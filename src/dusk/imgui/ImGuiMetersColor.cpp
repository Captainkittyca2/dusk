#include <algorithm>

#include "imgui.h"

#include "ImGuiMetersColor.hpp"
#include "ImGuiConsole.hpp"
#include "m_Do/m_Do_graphic.h"
#include "dusk/settings.h"

namespace dusk {
    MeterColorsOverride s_meterColorsOverride;
void ResetToDefaultMeterColors() {
    s_meterColorsOverride.lanternCustomTop = {230, 170, 0, 255};
    s_meterColorsOverride.lanternCustomBottom = {255, 255, 140, 255};
    s_meterColorsOverride.oxygen1CustomBottom = {200, 200, 255, 255};
    s_meterColorsOverride.oxygen1CustomTop = {80, 180, 255, 255};
    s_meterColorsOverride.oxygen2CustomBottom = {255, 100, 100, 255};
    s_meterColorsOverride.oxygen2CustomTop = {255, 10, 10, 255};
}

void DrawMetersColorWindow(bool& open) {
    if (!open) {
        return;
    }

    if (!ImGui::Begin("Custom Meters Color", &open)) {
        ImGui::End();
        return;
    }

    ImGui::SeparatorText("Lantern Meter");
    DrawColorEdit("Top##Lantern1", s_meterColorsOverride.lanternCustomTop);
    DrawColorEdit("Bottom##Lantern2", s_meterColorsOverride.lanternCustomBottom);
    ImGui::SeparatorText("Oxygen Meter (Full)");
    DrawColorEdit("Top##Oxygen11", s_meterColorsOverride.oxygen1CustomTop);
    DrawColorEdit("Bottom##Oxygen12", s_meterColorsOverride.oxygen1CustomBottom);
    ImGui::SeparatorText("Oxygen Meter (Low)");
    DrawColorEdit("Top##Oxygen21", s_meterColorsOverride.oxygen2CustomTop);
    DrawColorEdit("Bottom##Oxygen22", s_meterColorsOverride.oxygen2CustomBottom);
    if (ImGui::MenuItem("Reset meter colors to default")) {
        ResetToDefaultMeterColors();
    }
    ImGui::End();
}

void ImGuiCatDeluxe::ShowMetersColor() {
    DrawMetersColorWindow(m_showColorMeter);
}
}  // namespace dusk
