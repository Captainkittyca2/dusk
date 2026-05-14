#include "dusk/settings.h"
#include "dusk/config.hpp"

namespace dusk {
saveInfoShieldDurability* saveInfoDurabilityPtr = reinterpret_cast<saveInfoShieldDurability*>(&g_dComIfG_gameInfo.info.mSavedata.reserve);
UserSettings g_userSettings = {
    .video = {
        .enableFullscreen {"video.enableFullscreen", false},
        .enableVsync {"video.enableVsync", true},
        .lockAspectRatio {"video.lockAspectRatio", false},
        .enableFpsOverlay {"game.enableFpsOverlay", false},
        .fpsOverlayCorner {"game.fpsOverlayCorner", 0},
    },

    .audio = {
        .masterVolume {"audio.masterVolume", 60},
        .mainMusicVolume {"audio.mainMusicVolume", 100},
        .subMusicVolume {"audio.subMusicVolume", 100},
        .soundEffectsVolume {"audio.soundEffectsVolume", 100},
        .fanfareVolume {"audio.fanfareVolume", 100},
        .enableReverb {"audio.enableReverb", true},
        .enableHrtf {"audio.enableHrtf", false},
        .menuSounds {"audio.menuSounds", true},
    },

    .game = {
        .language { "game.language", GameLanguage::English },

        // Quality of Life
        .enableZButtonItems {"game.enableZButtonItems", false},
        .enableObjectStoring {"game.enableObjectStoring", false},
        .enableArmorsQuickToggle {"game.enableArmorsQuickToggle", false},
        .enableQuickTransform {"game.enableQuickTransform", false},
        .hideTvSettingsScreen {"game.hideTvSettingsScreen", true},
        .biggerWallets {"game.biggerWallets", false},
        .noReturnRupees {"game.noReturnRupees", false},
        .disableRupeeCutscenes {"game.disableRupeeCutscenes", false},
        .noSwordRecoil {"game.noSwordRecoil", false},
        .damageMultiplier {"game.damageMultiplier", 1},
        .noHeartDrops {"game.noHeartDrops", false},
        .instantDeath {"game.instantDeath", false},
        .fastClimbing {"game.fastClimbing", false},
        .noMissClimbing {"game.noMissClimbing", false},
        .fastTears {"game.fastTears", false},
        .no2ndFishForCat {"game.no2ndFishForCat", false},
        .instantSaves {"game.instantSaves", false},
        .instantText {"game.instantText", false},
        .sunsSong {"game.sunsSong", false},
        .autoSave {"game.autoSave", false},

        // Preferences
        .xLanternPos {"game.xLanternPos", 0.0f},
        .yLanternPos {"game.yLanternPos", 0.0f},
        .xOxygenPos {"game.xOxygenPos", 0.0f},
        .yOxygenPos {"game.yOxygenPos", 0.0f},
        .xSyncMeterPos {"game.xSyncMeterPos", 0.0f},
        .ySyncMeterPos {"game.ySyncMeterPos", 0.0f},
        .xAllButtonsPos {"game.xAllButtonsPos", 0.0f},
        .yAllButtonsPos {"game.yAllButtonsPos", 0.0f},
        .xBtnAPos {"game.xBtnAPos", 0.0f},
        .yBtnAPos {"game.yBtnAPos", 0.0f},
        .xTextAPos {"game.xTextAPos", 0.0f},
        .yTextAPos {"game.yTextAPos", 0.0f},
        .xSyncAPos {"game.xSyncAPos", 0.0f},
        .ySyncAPos {"game.ySyncAPos", 0.0f},
        .xBtnBPos {"game.xBtnBPos", 0.0f},
        .yBtnBPos {"game.yBtnBPos", 0.0f},
        .xItemBPos {"game.xItemBPos", 0.0f},
        .yItemBPos {"game.yItemBPos", 0.0f},
        .xTextBPos {"game.xTextBPos", 0.0f},
        .yTextBPos {"game.yTextBPos", 0.0f},
        .xSyncBPos {"game.xSyncBPos", 0.0f},
        .ySyncBPos {"game.ySyncBPos", 0.0f},
        .xBtnXPos {"game.xBtnXPos", 0.0f},
        .yBtnXPos {"game.yBtnXPos", 0.0f},
        .xItemXPos {"game.xItemXPos", 0.0f},
        .yItemXPos {"game.yItemXPos", 0.0f},
        .xTextXPos {"game.xTextXPos", 0.0f},
        .yTextXPos {"game.yTextXPos", 0.0f},
        .xSyncXPos {"game.xSyncXPos", 0.0f},
        .ySyncXPos {"game.ySyncXPos", 0.0f},
        .xBtnYPos {"game.xBtnYPos", 0.0f},
        .yBtnYPos {"game.yBtnYPos", 0.0f},
        .xItemYPos {"game.xItemYPos", 0.0f},
        .yItemYPos {"game.yItemYPos", 0.0f},
        .xTextYPos {"game.xTextYPos", 0.0f},
        .yTextYPos {"game.yTextYPos", 0.0f},
        .xSyncYPos {"game.xSyncYPos", 0.0f},
        .ySyncYPos {"game.ySyncYPos", 0.0f},
        .xBtnZPos {"game.xBtnZPos", 0.0f},
        .yBtnZPos {"game.yBtnZPos", 0.0f},
        .xItemZPos {"game.xItemZPos", 0.0f},
        .yItemZPos {"game.yItemZPos", 0.0f},
        .xTextZPos {"game.xTextZPos", 0.0f},
        .yTextZPos {"game.yTextZPos", 0.0f},
        .xSyncZPos {"game.xSyncZPos", 0.0f},
        .ySyncZPos {"game.ySyncZPos", 0.0f},
        .xMidonaPos {"game.xMidonaPos", 0.0f},
        .yMidonaPos {"game.yMidonaPos", 0.0f},
        .xDPadPos {"game.xDPadPos", 0.0f},
        .yDPadPos {"game.yDPadPos", 0.0f},
        .xDPadPos2 {"game.xDPadPos2", 0.0f},
        .yDPadPos2 {"game.yDPadPos2", 0.0f},
        .xHeartPos {"game.xHeartPos", 0.0f},
        .yHeartPos {"game.yHeartPos", 0.0f},
        .xRupeePos {"game.xRupeePos", 0.0f},
        .yRupeePos {"game.yRupeePos", 0.0f},
        .xRupeeTextPos {"game.xRupeeTextPos", 0.0f},
        .yRupeeTextPos {"game.yRupeeTextPos", 0.0f},
        .xMinMap {"game.xMinMap", 0.0f},
        .yMinMap {"game.yMinMap", 0.0f},
        .enableShieldDurability {"game.enableShieldDurability", false},
        .enableTWWHDArmor {"game.enableTWWHDArmor", false},
        .HDArmorMultiplier {"game.HDArmorMultiplier", 1},
        .imGuiToggleOnOff {"game.imGuiToggleOnOff", true},
        .enableManualShielding {"game.enableManualShielding", false},
        .enableMirrorMode {"game.enableMirrorMode", false},
        .minimalHUD {"game.minimalHUD", false},
        .pauseOnFocusLost {"game.pauseOnFocusLost", false},
        .enableLinkDollRotation {"game.enableLinkDollRotation", false},
        .enableAchievementToasts {"game.enableAchievementToasts", true},
        .enableControllerToasts {"game.enableControllerToasts", true},
        .enableDiscordPresence {"game.enableDiscordPresence", true},

        // Graphics
        .bloomMode {"game.bloomMode", BloomMode::Dusk},
        .bloomMultiplier {"game.bloomMultiplier", 1.0f},
        .disableWaterRefraction {"game.disableWaterRefraction", false},
        .enableFrameInterpolation {"game.enableFrameInterpolation", false},
        .internalResolutionScale {"game.internalResolutionScale", 0},
        .shadowResolutionMultiplier {"game.shadowResolutionMultiplier", 1},
        .enableDepthOfField {"game.enableDepthOfField", true},
        .enableMapBackground {"game.enableMapBackground", true},
        .disableCutscenePillarboxing {"game.disableCutscenePillarboxing", false},

        // Audio
        .noLowHpSound {"game.noLowHpSound", false},
        .midnasLamentNonStop {"game.midnasLamentNonStop", false},

        // Input
        .gyroMode {"game.gyroMode", GyroMode::Sensor},
        .enableGyroAim {"game.enableGyroAim", false},
        .enableGyroRollgoal {"game.enableGyroRollgoal", false},
        .gyroSensitivityX {"game.gyroSensitivityX", 1.0f},
        .gyroSensitivityY {"game.gyroSensitivityY", 1.0f},
        .gyroSensitivityRollgoal {"game.gyroSensitivityRollgoal", 1.0f},
        .gyroSmoothing {"game.gyroSmoothing", 0.65f},
        .gyroDeadband {"game.gyroDeadband", 0.04f},
        .gyroInvertPitch {"game.gyroInvertPitch", false},
        .gyroInvertYaw {"game.gyroInvertYaw", false},
        .freeCamera {"game.freeCamera", false},
        .invertCameraXAxis {"game.invertCameraXAxis", false},
        .invertCameraYAxis {"game.invertCameraYAxis", false},
        .invertFirstPersonXAxis {"game.invertFirstPersonXAxis", false},
        .invertFirstPersonYAxis {"game.invertFirstPersonYAxis", false},
        .freeCameraSensitivity {"game.freeCameraSensitivity", 1.0f},
        .debugFlyCam {"game.debugFlyCam", false},
        .debugFlyCamLockEvents {"game.debugFlyCamLockEvents", true},
        .allowBackgroundInput {"game.allowBackgroundInput", true},

        // Cheats
        .infiniteHearts {"game.infiniteHearts", false},
        .infiniteArrows {"game.infiniteArrows", false},
        .infiniteSeeds {"game.infiniteSeeds", false},
        .infiniteBombs {"game.infiniteBombs", false},
        .infiniteOil {"game.infiniteOil", false},
        .infiniteOxygen {"game.infiniteOxygen", false},
        .infiniteRupees {"game.infiniteRupees", false},
        .enableIndefiniteItemDrops {"game.enableIndefiniteItemDrops", false},
        .moonJump {"game.moonJump", false},
        .superClawshot {"game.superClawshot", false},
        .alwaysGreatspin {"game.alwaysGreatspin", false},
        .enableFastIronBoots {"game.enableFastIronBoots", false},
        .canTransformAnywhere {"game.canTransformAnywhere", false},
        .fastRoll {"game.fastRoll", false},
        .fastSpinner {"game.fastSpinner", false},
        .freeMagicArmor {"game.freeMagicArmor", false},
        .invincibleEnemies {"game.invincibleEnemies", false},

        // Technical
        .restoreWiiGlitches {"game.restoreWiiGlitches", false},

        // Controls
        .enableTurboKeybind {"game.enableTurboKeybind", false},
        .enableResetKeybind {"game.enableResetKeybind", false},

        // Tools
        .speedrunMode {"game.speedrunMode", false},
        .liveSplitEnabled {"game.liveSplitEnabled", false},
        .showSpeedrunRTATimer {"game.showSpeedrunRTATimer", true},
        .recordingMode {"game.recordingMode", false},
        .showInputViewer {"game.showInputViewer", false},
        .showInputViewerGyro {"game.showInputViewerGyro", false}
    },

    .backend = {
        .isoPath {"backend.isoPath", ""},
        .isoVerification {"backend.isoVerification", DiscVerificationState::Unknown},
        .graphicsBackend {"backend.graphicsBackend", "auto"},
        .skipPreLaunchUI {"backend.skipPreLaunchUI", false},
        .showPipelineCompilation {"backend.showPipelineCompilation", false},
        .wasPresetChosen {"backend.wasPresetChosen", false},
        .checkForUpdates {"backend.checkForUpdates", true},
        .cardFileType {"backend.cardFileType", static_cast<int>(CARD_GCIFOLDER)},
        .enableAdvancedSettings {"backend.enableAdvancedSettings", false},
    },

    // Not sure if there's a better way to declare this
    .actionBindings = {
        .firstPersonCamera {
            ActionBindConfigVar{"actionBindings.firstPersonCamera_port0", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.firstPersonCamera_port1", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.firstPersonCamera_port2", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.firstPersonCamera_port3", PAD_NATIVE_BUTTON_INVALID},
        },
        .callMidna {
            ActionBindConfigVar{"actionBindings.callMidna_port0", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.callMidna_port1", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.callMidna_port2", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.callMidna_port3", PAD_NATIVE_BUTTON_INVALID},
        },
        .openDusklightMenu {
            ActionBindConfigVar{"actionBindings.openDusklightMenu_port0", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.openDusklightMenu_port1", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.openDusklightMenu_port2", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.openDusklightMenu_port3", PAD_NATIVE_BUTTON_INVALID},
        },
        .turboSpeedButton {
            ActionBindConfigVar{"actionBindings.turboButton_port0", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.turboButton_port1", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.turboButton_port2", PAD_NATIVE_BUTTON_INVALID},
            ActionBindConfigVar{"actionBindings.turboButton_port3", PAD_NATIVE_BUTTON_INVALID},
        },
    }
};

UserSettings& getSettings() {
    return g_userSettings;
}

void registerSettings() {
    // Video
    Register(g_userSettings.video.enableFullscreen);
    Register(g_userSettings.video.enableVsync);
    Register(g_userSettings.video.lockAspectRatio);
    Register(g_userSettings.video.enableFpsOverlay);
    Register(g_userSettings.video.fpsOverlayCorner);

    // Audio
    Register(g_userSettings.audio.masterVolume);
    Register(g_userSettings.audio.mainMusicVolume);
    Register(g_userSettings.audio.subMusicVolume);
    Register(g_userSettings.audio.soundEffectsVolume);
    Register(g_userSettings.audio.fanfareVolume);
    Register(g_userSettings.audio.enableReverb);
    Register(g_userSettings.audio.enableHrtf);
    Register(g_userSettings.audio.menuSounds);

    // Game
    Register(g_userSettings.game.language);
    Register(g_userSettings.game.enableZButtonItems);
    Register(g_userSettings.game.enableObjectStoring);
    Register(g_userSettings.game.enableQuickTransform);
    Register(g_userSettings.game.hideTvSettingsScreen);
    Register(g_userSettings.game.biggerWallets);
    Register(g_userSettings.game.noReturnRupees);
    Register(g_userSettings.game.disableRupeeCutscenes);
    Register(g_userSettings.game.noSwordRecoil);
    Register(g_userSettings.game.damageMultiplier);
    Register(g_userSettings.game.noHeartDrops);
    Register(g_userSettings.game.instantDeath);
    Register(g_userSettings.game.fastClimbing);
    Register(g_userSettings.game.fastTears);
    Register(g_userSettings.game.no2ndFishForCat);
    Register(g_userSettings.game.instantSaves);
    Register(g_userSettings.game.instantText);
    Register(g_userSettings.game.sunsSong);
    Register(g_userSettings.game.xLanternPos);
    Register(g_userSettings.game.yLanternPos);
    Register(g_userSettings.game.xOxygenPos);
    Register(g_userSettings.game.yOxygenPos);
    Register(g_userSettings.game.xSyncMeterPos);
    Register(g_userSettings.game.ySyncMeterPos);
    Register(g_userSettings.game.xAllButtonsPos);
    Register(g_userSettings.game.yAllButtonsPos);
    Register(g_userSettings.game.xBtnAPos);
    Register(g_userSettings.game.yBtnAPos);
    Register(g_userSettings.game.xTextAPos);
    Register(g_userSettings.game.yTextAPos);
    Register(g_userSettings.game.xSyncAPos);
    Register(g_userSettings.game.ySyncAPos);
    Register(g_userSettings.game.xBtnBPos);
    Register(g_userSettings.game.yBtnBPos);
    Register(g_userSettings.game.xItemBPos);
    Register(g_userSettings.game.yItemBPos);
    Register(g_userSettings.game.xTextBPos);
    Register(g_userSettings.game.yTextBPos);
    Register(g_userSettings.game.xSyncBPos);
    Register(g_userSettings.game.ySyncBPos);
    Register(g_userSettings.game.xBtnXPos);
    Register(g_userSettings.game.yBtnXPos);
    Register(g_userSettings.game.xItemXPos);
    Register(g_userSettings.game.yItemXPos);
    Register(g_userSettings.game.xTextXPos);
    Register(g_userSettings.game.yTextXPos);
    Register(g_userSettings.game.xSyncXPos);
    Register(g_userSettings.game.ySyncXPos);
    Register(g_userSettings.game.xBtnYPos);
    Register(g_userSettings.game.yBtnYPos);
    Register(g_userSettings.game.xItemYPos);
    Register(g_userSettings.game.yItemYPos);
    Register(g_userSettings.game.xTextYPos);
    Register(g_userSettings.game.yTextYPos);
    Register(g_userSettings.game.xSyncYPos);
    Register(g_userSettings.game.ySyncYPos);
    Register(g_userSettings.game.xBtnZPos);
    Register(g_userSettings.game.yBtnZPos);
    Register(g_userSettings.game.xItemZPos);
    Register(g_userSettings.game.yItemZPos);
    Register(g_userSettings.game.xTextZPos);
    Register(g_userSettings.game.yTextZPos);
    Register(g_userSettings.game.xSyncZPos);
    Register(g_userSettings.game.ySyncZPos);
    Register(g_userSettings.game.xMidonaPos);
    Register(g_userSettings.game.yMidonaPos);
    Register(g_userSettings.game.xDPadPos);
    Register(g_userSettings.game.yDPadPos);
    Register(g_userSettings.game.xDPadPos2);
    Register(g_userSettings.game.yDPadPos2);
    Register(g_userSettings.game.xHeartPos);
    Register(g_userSettings.game.yHeartPos);
    Register(g_userSettings.game.xRupeePos);
    Register(g_userSettings.game.yRupeePos);
    Register(g_userSettings.game.xRupeeTextPos);
    Register(g_userSettings.game.yRupeeTextPos);
    Register(g_userSettings.game.xMinMap);
    Register(g_userSettings.game.yMinMap);
    Register(g_userSettings.game.enableShieldDurability);
    Register(g_userSettings.game.enableTWWHDArmor);
    Register(g_userSettings.game.HDArmorMultiplier);
    Register(g_userSettings.game.imGuiToggleOnOff);
    Register(g_userSettings.game.enableManualShielding);
    Register(g_userSettings.game.enableArmorsQuickToggle);
    Register(g_userSettings.game.autoSave);
    Register(g_userSettings.game.enableMirrorMode);
    Register(g_userSettings.game.invertCameraXAxis);
    Register(g_userSettings.game.invertCameraYAxis);
    Register(g_userSettings.game.invertFirstPersonXAxis);
    Register(g_userSettings.game.invertFirstPersonYAxis);
    Register(g_userSettings.game.freeCameraSensitivity);
    Register(g_userSettings.game.minimalHUD);
    Register(g_userSettings.game.pauseOnFocusLost);
    Register(g_userSettings.game.enableDiscordPresence);
    Register(g_userSettings.game.bloomMode);
    Register(g_userSettings.game.bloomMultiplier);
    Register(g_userSettings.game.disableWaterRefraction);
    Register(g_userSettings.game.internalResolutionScale);
    Register(g_userSettings.game.shadowResolutionMultiplier);
    Register(g_userSettings.game.enableDepthOfField);
    Register(g_userSettings.game.enableMapBackground);
    Register(g_userSettings.game.disableCutscenePillarboxing);
    Register(g_userSettings.game.enableFastIronBoots);
    Register(g_userSettings.game.canTransformAnywhere);
    Register(g_userSettings.game.fastRoll);
    Register(g_userSettings.game.freeMagicArmor);
    Register(g_userSettings.game.restoreWiiGlitches);
    Register(g_userSettings.game.enableLinkDollRotation);
    Register(g_userSettings.game.enableAchievementToasts);
    Register(g_userSettings.game.enableControllerToasts);
    Register(g_userSettings.game.noMissClimbing);
    Register(g_userSettings.game.noLowHpSound);
    Register(g_userSettings.game.midnasLamentNonStop);
    Register(g_userSettings.game.enableTurboKeybind);
    Register(g_userSettings.game.enableResetKeybind);
    Register(g_userSettings.game.speedrunMode);
    Register(g_userSettings.game.liveSplitEnabled);
    Register(g_userSettings.game.showSpeedrunRTATimer);
    Register(g_userSettings.game.recordingMode);
    Register(g_userSettings.game.showInputViewer);
    Register(g_userSettings.game.showInputViewerGyro);
    Register(g_userSettings.game.fastSpinner);
    Register(g_userSettings.game.infiniteHearts);
    Register(g_userSettings.game.infiniteArrows);
    Register(g_userSettings.game.infiniteSeeds);
    Register(g_userSettings.game.infiniteBombs);
    Register(g_userSettings.game.infiniteOil);
    Register(g_userSettings.game.infiniteOxygen);
    Register(g_userSettings.game.infiniteRupees);
    Register(g_userSettings.game.enableIndefiniteItemDrops);
    Register(g_userSettings.game.moonJump);
    Register(g_userSettings.game.superClawshot);
    Register(g_userSettings.game.alwaysGreatspin);
    Register(g_userSettings.game.invincibleEnemies);
    Register(g_userSettings.game.enableFrameInterpolation);
    Register(g_userSettings.game.gyroMode);
    Register(g_userSettings.game.enableGyroAim);
    Register(g_userSettings.game.enableGyroRollgoal);
    Register(g_userSettings.game.gyroSensitivityX);
    Register(g_userSettings.game.gyroSensitivityY);
    Register(g_userSettings.game.gyroSensitivityRollgoal);
    Register(g_userSettings.game.gyroDeadband);
    Register(g_userSettings.game.gyroSmoothing);
    Register(g_userSettings.game.gyroInvertPitch);
    Register(g_userSettings.game.gyroInvertYaw);
    Register(g_userSettings.game.freeCamera);
    Register(g_userSettings.game.debugFlyCam);
    Register(g_userSettings.game.debugFlyCamLockEvents);
    Register(g_userSettings.game.allowBackgroundInput);

    Register(g_userSettings.backend.isoPath);
    Register(g_userSettings.backend.isoVerification);
    Register(g_userSettings.backend.graphicsBackend);
    Register(g_userSettings.backend.skipPreLaunchUI);
    Register(g_userSettings.backend.showPipelineCompilation);
    Register(g_userSettings.backend.wasPresetChosen);
    Register(g_userSettings.backend.checkForUpdates);
    Register(g_userSettings.backend.cardFileType);
    Register(g_userSettings.backend.enableAdvancedSettings);

    Register(g_userSettings.actionBindings.firstPersonCamera[0]);
    Register(g_userSettings.actionBindings.firstPersonCamera[1]);
    Register(g_userSettings.actionBindings.firstPersonCamera[2]);
    Register(g_userSettings.actionBindings.firstPersonCamera[3]);
    Register(g_userSettings.actionBindings.callMidna[0]);
    Register(g_userSettings.actionBindings.callMidna[1]);
    Register(g_userSettings.actionBindings.callMidna[2]);
    Register(g_userSettings.actionBindings.callMidna[3]);
    Register(g_userSettings.actionBindings.openDusklightMenu[0]);
    Register(g_userSettings.actionBindings.openDusklightMenu[1]);
    Register(g_userSettings.actionBindings.openDusklightMenu[2]);
    Register(g_userSettings.actionBindings.openDusklightMenu[3]);
    Register(g_userSettings.actionBindings.turboSpeedButton[0]);
    Register(g_userSettings.actionBindings.turboSpeedButton[1]);
    Register(g_userSettings.actionBindings.turboSpeedButton[2]);
    Register(g_userSettings.actionBindings.turboSpeedButton[3]);
}

// Transient settings

static TransientSettings g_transientSettings = {
    .collisionView = {
        .enableTerrainView = false,
        .enableWireframe = false,
        .enableAtView = false,
        .enableTgView = false,
        .enableCoView = false,
        .terrainViewOpacity = 50.0f,
        .colliderViewOpacity = 50.0f,
        .drawRange = 100.0f,
    },
    .skipFrameRateLimit = false,
};

TransientSettings& getTransientSettings() {
    return g_transientSettings;
}

}
