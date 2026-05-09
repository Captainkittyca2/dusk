#ifndef DUSK_CONFIG_H
#define DUSK_CONFIG_H

#include "dusk/config_var.hpp"

namespace dusk {

bool shieldDurability(u8 shieldType, bool strongAttack);

struct MeterColorsOverride {
    GXColor lanternCustomTop = {230, 170, 0, 255};
    GXColor lanternCustomBottom = {255, 255, 140, 255};
    GXColor oxygen1CustomBottom = {200, 200, 255, 255};
    GXColor oxygen1CustomTop = {80, 180, 255, 255};
    GXColor oxygen2CustomBottom = {255, 100, 100, 255};
    GXColor oxygen2CustomTop = {255, 10, 10, 255};
};

extern MeterColorsOverride s_meterColorsOverride;

struct saveInfoShieldDurability
{
    /* 0x00 */ uint8_t zoraArmorAcquired;
    uint8_t unk[63];
    /* 0x40 */ uint8_t woodShieldDurability;
    /* 0x41 */ uint8_t hylianShieldDurability;
    /* 0x42 */ uint16_t objectStored;
    /* 0x44 */ uint32_t objectParams;
    /* 0x48 */ uint16_t objCarryParams;
    /* 0x4A */ uint16_t objCarryItems;
    /* 0x4C */ uint8_t padding1;
    /* 0x4D */ uint16_t padding2;
    /* 0x4F */ uint8_t SkywardID;
};

extern saveInfoShieldDurability* saveInfoDurabilityPtr;

using namespace config;

enum class BloomMode : int {
    Off = 0,
    Classic = 1,
    Dusk = 2,
};

namespace config {
template <>
struct ConfigEnumRange<BloomMode> {
    static constexpr auto min = BloomMode::Off;
    static constexpr auto max = BloomMode::Dusk;
};
}

// Persistent user settings

struct UserSettings {
    // Program settings

    struct {
        // Video
        ConfigVar<bool> enableFullscreen;
        ConfigVar<bool> enableVsync;
        ConfigVar<bool> lockAspectRatio;
    } video;

    struct {
        // Audio
        ConfigVar<int> masterVolume;
        ConfigVar<int> mainMusicVolume;
        ConfigVar<int> subMusicVolume;
        ConfigVar<int> soundEffectsVolume;
        ConfigVar<int> fanfareVolume;
        ConfigVar<bool> enableReverb;
    } audio;

    // Game settings

    struct {
        // QoL
        ConfigVar<bool> enableZButtonItems;
        ConfigVar<bool> enableObjectStoring;
        ConfigVar<bool> enableArmorsQuickToggle;
        ConfigVar<bool> enableQuickTransform;
        ConfigVar<bool> hideTvSettingsScreen;
        ConfigVar<bool> skipWarningScreen;
        ConfigVar<bool> biggerWallets;
        ConfigVar<bool> noReturnRupees;
        ConfigVar<bool> disableRupeeCutscenes;
        ConfigVar<bool> noSwordRecoil;
        ConfigVar<int> damageMultiplier;
        ConfigVar<bool> noHeartDrops;
        ConfigVar<bool> instantDeath;
        ConfigVar<bool> fastClimbing;
        ConfigVar<bool> noMissClimbing;
        ConfigVar<bool> fastTears;
        ConfigVar<bool> instantSaves;
        ConfigVar<bool> instantText;
        ConfigVar<bool> sunsSong;

        // Preferences
        ConfigVar<float> xLanternPos;
        ConfigVar<float> yLanternPos;
        ConfigVar<float> xOxygenPos;
        ConfigVar<float> yOxygenPos;
        ConfigVar<float> xSyncMeterPos;
        ConfigVar<float> ySyncMeterPos;
        ConfigVar<float> xAllButtonsPos;
        ConfigVar<float> yAllButtonsPos;
        ConfigVar<float> xBtnAPos;
        ConfigVar<float> yBtnAPos;
        ConfigVar<float> xTextAPos;
        ConfigVar<float> yTextAPos;
        ConfigVar<float> xSyncAPos;
        ConfigVar<float> ySyncAPos;
        ConfigVar<float> xBtnBPos;
        ConfigVar<float> yBtnBPos;
        ConfigVar<float> xItemBPos;
        ConfigVar<float> yItemBPos;
        ConfigVar<float> xTextBPos;
        ConfigVar<float> yTextBPos;
        ConfigVar<float> xSyncBPos;
        ConfigVar<float> ySyncBPos;
        ConfigVar<float> xBtnXPos;
        ConfigVar<float> yBtnXPos;
        ConfigVar<float> xItemXPos;
        ConfigVar<float> yItemXPos;
        ConfigVar<float> xTextXPos;
        ConfigVar<float> yTextXPos;
        ConfigVar<float> xSyncXPos;
        ConfigVar<float> ySyncXPos;
        ConfigVar<float> xBtnYPos;
        ConfigVar<float> yBtnYPos;
        ConfigVar<float> xItemYPos;
        ConfigVar<float> yItemYPos;
        ConfigVar<float> xTextYPos;
        ConfigVar<float> yTextYPos;
        ConfigVar<float> xSyncYPos;
        ConfigVar<float> ySyncYPos;
        ConfigVar<float> xBtnZPos;
        ConfigVar<float> yBtnZPos;
        ConfigVar<float> xItemZPos;
        ConfigVar<float> yItemZPos;
        ConfigVar<float> xTextZPos;
        ConfigVar<float> yTextZPos;
        ConfigVar<float> xSyncZPos;
        ConfigVar<float> ySyncZPos;
        ConfigVar<float> xMidonaPos;
        ConfigVar<float> yMidonaPos;
        ConfigVar<float> xDPadPos;
        ConfigVar<float> yDPadPos;
        ConfigVar<float> xDPadPos2;
        ConfigVar<float> yDPadPos2;
        ConfigVar<float> xHeartPos;
        ConfigVar<float> yHeartPos;
        ConfigVar<float> xRupeePos;
        ConfigVar<float> yRupeePos;
        ConfigVar<float> xRupeeTextPos;
        ConfigVar<float> yRupeeTextPos;
        ConfigVar<float> xMinMap;
        ConfigVar<float> yMinMap;
        ConfigVar<bool> enableShieldDurability;
        ConfigVar<bool> enableTWWHDArmor;
        ConfigVar<bool> enableManualShielding;
        ConfigVar<bool> enableMirrorMode;
        ConfigVar<bool> invertCameraXAxis;
        ConfigVar<bool> disableMainHUD;
        ConfigVar<bool> pauseOnFocusLost;

        // Graphics
        ConfigVar<BloomMode> bloomMode;
        ConfigVar<float> bloomMultiplier;
        ConfigVar<bool> disableWaterRefraction;
        ConfigVar<bool> enableFrameInterpolation;
        ConfigVar<int> internalResolutionScale;
        ConfigVar<int> shadowResolutionMultiplier;

        // Audio
        ConfigVar<bool> noLowHpSound;
        ConfigVar<bool> midnasLamentNonStop;

        // Input
        ConfigVar<bool> enableGyroAim;
        ConfigVar<bool> enableGyroRollgoal;
        ConfigVar<float> gyroSensitivityX;
        ConfigVar<float> gyroSensitivityY;
        ConfigVar<float> gyroSensitivityRollgoal;
        ConfigVar<float> gyroSmoothing;
        ConfigVar<float> gyroDeadband;
        ConfigVar<bool> gyroInvertPitch;
        ConfigVar<bool> gyroInvertYaw;

        // Cheats
        ConfigVar<bool> infiniteHearts;
        ConfigVar<bool> infiniteArrows;
        ConfigVar<bool> infiniteBombs;
        ConfigVar<bool> infiniteOil;
        ConfigVar<bool> infiniteOxygen;
        ConfigVar<bool> infiniteRupees;
        ConfigVar<bool> moonJump;
        ConfigVar<bool> superClawshot;
        ConfigVar<bool> alwaysGreatspin;
        ConfigVar<bool> enableFastIronBoots;
        ConfigVar<bool> canTransformAnywhere;
        ConfigVar<bool> fastSpinner;
        ConfigVar<bool> freeMagicArmor;

        // Technical
        ConfigVar<bool> restoreWiiGlitches;

        // Controls
        ConfigVar<bool> enableTurboKeybind;
    } game;

    struct {
        ConfigVar<std::string> isoPath;
        ConfigVar<std::string> graphicsBackend;
        ConfigVar<bool> skipPreLaunchUI;
        ConfigVar<bool> showPipelineCompilation;
        ConfigVar<bool> wasPresetChosen;
        ConfigVar<bool> enableCrashReporting;
        ConfigVar<bool> duskMenuOpen;
    } backend;
};

UserSettings& getSettings();

void registerSettings();

// Transient settings

struct CollisionViewSettings {
    bool enableTerrainView;
    bool enableWireframe;
    bool enableAtView;
    bool enableTgView;
    bool enableCoView;
    float terrainViewOpacity;
    float colliderViewOpacity;
    float drawRange;
};

struct TransientSettings {
    CollisionViewSettings collisionView;
    bool skipFrameRateLimit;
    bool moveLinkActive;
};

TransientSettings& getTransientSettings();

}

#endif // DUSK_CONFIG_H
