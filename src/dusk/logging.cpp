#include "dusk/logging.h"
#include <cstdio>
#include <cstdlib>
#include <SDL3/SDL.h>
#include <ctime>
#include <filesystem>
#include <mutex>
#include <string>

bool StubLogEnabled = true;

using namespace std::literals::string_view_literals;

// MSVC is broken and seemingly miscompiles std::string_view::npos without this.
// I wish I was joking.
constexpr size_t npos = std::string_view::npos;

static constexpr std::string_view StubFragments[] = {
    "is a stub"sv,
    "Unimplemented: BP register"sv,
    "Unhandled BP register"sv,
    "Unhandled XF register"sv,
    "but selective updates are not implemented"sv,
};

namespace {
std::mutex gLogFileMutex;
SDL_IOStream* gLogFile = nullptr;

std::string MakeTimestampedLogPath() {
    char* prefPath = SDL_GetPrefPath(nullptr, "Dusk");
    if (!prefPath) {
        return {};
    }

    std::filesystem::path logDir(prefPath);
    SDL_free(prefPath);
    logDir /= "logs";

    std::error_code ec;
    std::filesystem::create_directories(logDir, ec);
    if (ec || !std::filesystem::is_directory(logDir)) {
        return {};
    }

    std::time_t now = std::time(nullptr);
    std::tm localTime{};
#if defined(_WIN32)
    localtime_s(&localTime, &now);
#else
    localtime_r(&now, &localTime);
#endif

    char timestamp[32];
    if (std::strftime(timestamp, sizeof(timestamp), "%Y%m%d-%H%M%S", &localTime) == 0) {
        return {};
    }

    return (logDir / ("dusk-" + std::string(timestamp) + ".log")).string();
}

void WriteToLogFile(const char* levelStr, const char* module, const char* message) {
    std::scoped_lock lock(gLogFileMutex);
    if (!gLogFile) {
        return;
    }

    std::string line = "[";
    line += levelStr;
    line += " | ";
    line += module;
    line += "] ";
    line += message;
    line += '\n';

    SDL_WriteIO(gLogFile, line.data(), line.size());
    SDL_FlushIO(gLogFile);
}
}  // namespace

bool dusk::InitializeLogFile() {
    std::scoped_lock lock(gLogFileMutex);
    if (gLogFile) {
        return true;
    }

    std::string logPath = MakeTimestampedLogPath();
    if (logPath.empty()) {
        return false;
    }

    gLogFile = SDL_IOFromFile(logPath.c_str(), "a");
    return gLogFile != nullptr;
}

void dusk::ShutdownLogFile() {
    std::scoped_lock lock(gLogFileMutex);
    if (!gLogFile) {
        return;
    }

    SDL_FlushIO(gLogFile);
    SDL_CloseIO(gLogFile);
    gLogFile = nullptr;
}

static bool IsForStubLog(const char* message) {
    std::string_view msg_view(message);

    for (auto& fragment : StubFragments) {
        if (msg_view.find(fragment) != ""sv.npos) {
            return true;
        }
    }

    return false;
}

void aurora_log_callback(AuroraLogLevel level, const char* module, const char* message,
                         unsigned int len) {
    if (StubLogEnabled && level != LOG_FATAL && IsForStubLog(message)) {
        dusk::SendToStubLog(level, module, message);
        return;
    }

    const char* levelStr = "??";
    FILE* out = stdout;
    switch (level) {
    case LOG_DEBUG:
        levelStr = "DEBUG";
        break;
    case LOG_INFO:
        levelStr = "INFO";
        break;
    case LOG_WARNING:
        levelStr = "WARNING";
        break;
    case LOG_ERROR:
        levelStr = "ERROR";
        out = stderr;
        break;
    case LOG_FATAL:
        levelStr = "FATAL";
        out = stderr;
        break;
    }
    fprintf(out, "[%s | %s] %s\n", levelStr, module, message);
    WriteToLogFile(levelStr, module, message);
    if (level == LOG_FATAL) {
        fflush(out);
        abort();
    }
}

aurora::Module DuskLog("dusk");
