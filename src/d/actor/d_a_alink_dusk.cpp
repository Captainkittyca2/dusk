#include "d/actor/d_a_alink.h"
#include "d/actor/d_a_midna.h"
#include "d/d_meter2.h"
#include "d/d_meter2_draw.h"
#include "d/d_meter2_info.h"

bool armorQuickToggleCooldown = false;
bool armorQuickToggleInitiated = false;
u32 armorQuickToggleCounter = 0;
u32 armorQuickToggleInitiatedTimer = 0;
u32 armorQuickToggleCooldownTimer = 0;

void daAlink_c::handleArmorsQuickToggle() {
    if (!dusk::getSettings().game.enableArmorsQuickToggle) return;

    // temporary if statement code for automatically having magic and zora armors unlocked to test the mod
    if (!dComIfGs_isItemFirstBit(dItemNo_WEAR_ZORA_e)) {
        dComIfGs_onItemFirstBit(dItemNo_WEAR_ZORA_e); dComIfGs_onItemFirstBit(dItemNo_ARMOR_e);
    }

    // Have magic and zora armors
    if (!dComIfGs_isItemFirstBit(dItemNo_WEAR_ZORA_e) && !dComIfGs_isItemFirstBit(dItemNo_ARMOR_e)) return;

    // Be Human
    if (dComIfGs_getTransformStatus()) return;

    if (!armorQuickToggleCooldown && mDoCPd_c::getTrigDown(PAD_1) && armorQuickToggleCounter < 2)
    {
        armorQuickToggleInitiated = true;
        armorQuickToggleCounter++;
    }

    if (armorQuickToggleInitiated) {
        armorQuickToggleInitiatedTimer++;
        if (armorQuickToggleInitiatedTimer >= 15) {
            armorQuickToggleInitiated = false;
            armorQuickToggleCooldown = true;
            armorQuickToggleInitiatedTimer = 0;
            armorQuickToggleCooldownTimer = 0;
            setClothesChange(0);
            mDoAud_seStart(0x4F, 0, 0, 0);
            if (armorQuickToggleCounter == 1) {
                if (dComIfGs_getSelectEquipClothes() != dItemNo_WEAR_ZORA_e) dComIfGs_setSelectEquipClothes(dItemNo_WEAR_ZORA_e);
                else dComIfGs_setSelectEquipClothes(dItemNo_WEAR_KOKIRI_e);
            } else if (armorQuickToggleCounter == 2 && dComIfGs_isItemFirstBit(dItemNo_ARMOR_e)) {
                if (dComIfGs_getSelectEquipClothes() != dItemNo_ARMOR_e) dComIfGs_setSelectEquipClothes(dItemNo_ARMOR_e);
                else dComIfGs_setSelectEquipClothes(dItemNo_WEAR_KOKIRI_e);
            }
            armorQuickToggleCounter = 0;
        }
    }
    if (armorQuickToggleCooldown) {
        armorQuickToggleCooldownTimer++;
        if (armorQuickToggleCooldownTimer >= 20) {
            armorQuickToggleCooldown = false;
            armorQuickToggleCooldownTimer = 0;
        }
    }
}
void daAlink_c::armorRupeeLossHD(s16 rupeeLostParam, cXyz LinkPosition, csXyz angle_positioned, cXyz theScale,
                      s8 theRoomCurrent) {
    u8 minussOrPlussWhichOneWillItBe;
    u8 HDHit = 0;
    if (rupeeLostParam > dComIfGs_getRupee())
        rupeeLostParam = dComIfGs_getRupee();
    while (rupeeLostParam > 0) {
        minussOrPlussWhichOneWillItBe = (u8)(cM_rndF(2.0f));
        angle_positioned.y = (s16)(cM_rndF(32767.0f));
        if (!minussOrPlussWhichOneWillItBe)
            angle_positioned.y = -angle_positioned.y;
        // armorDamageTimeOrNo = true;
        armorTimerFast = true;
        if (rupeeLostParam > 100) {
            rupeeLostParam -= 100;
            HDHit = 6;
        } else if (rupeeLostParam > 50) {
            rupeeLostParam -= 50;
            HDHit = 5;
        } else if (rupeeLostParam > 20) {
            rupeeLostParam -= 20;
            HDHit = 4;
        } else if (rupeeLostParam > 10) {
            rupeeLostParam -= 10;
            HDHit = 3;
        } else if (rupeeLostParam > 5) {
            rupeeLostParam -= 5;
            HDHit = 2;
        } else {
            rupeeLostParam -= 1;
            HDHit = 1;
        }
        fopAcM_fastCreateItem2(&LinkPosition, HDHit, -1, theRoomCurrent, -1, &angle_positioned,
                               &theScale);
        HDHit = 0;
    }
}

void daAlink_c::handleWolfHowl() {
    if (checkWolf()) {
        if (!dusk::getSettings().game.sunsSong) {
            return;
        }

        // Check to see if Link has the ability to transform.
        if (!dComIfGs_isEventBit(dSv_event_flag_c::M_077)) {
            return;
        }

        // Ensure there is a proper pointer to the mMeterClass and mpMeterDraw structs in
        // g_meter2_info.
        const auto meterClassPtr = g_meter2_info.getMeterClass();
        if (!meterClassPtr) {
            return;
        }

        const auto meterDrawPtr = meterClassPtr->getMeterDrawPtr();
        if (!meterDrawPtr) {
            return;
        }

        // Ensure that link is not in a cutscene.
        if (checkEventRun()) {
            Z2GetAudioMgr()->seStart(Z2SE_SYS_ERROR, NULL, 0, 0, 1.0f, 1.0f, -1.0f, -1.0f, 0);
            return;
        }

        mDoCPd_c::getCpadInfo(PAD_1).mPressedButtonFlags = 0;

        // Ensure that the Z Button is not dimmed
        if (meterDrawPtr->getButtonZAlpha() != 1.f) {
            Z2GetAudioMgr()->seStart(Z2SE_SYS_ERROR, NULL, 0, 0, 1.0f, 1.0f, -1.0f, -1.0f, 0);
            return;
        }

        bool canTransform = false;

        if (mLinkAcch.ChkGroundHit() && !checkModeFlg(MODE_PLAYER_FLY) && !checkMagneBootsOn()) {
            if (!checkForestOldCentury()) {
                if (checkMidnaRide()) {
                    if ((checkWolf() &&
                         (checkModeFlg(MODE_UNK_1000) || dComIfGp_checkPlayerStatus0(0, 0x10))) ||
                        (!checkWolf() &&
                         (checkEventRun() || getMidnaActor()->checkMetamorphoseEnable()) &&
                         (checkModeFlg(4) || dComIfGp_checkPlayerStatus0(0, 0x10))))
                    {
                        canTransform = true;
                    }
                }
            }
        }

        getWolfHowlMgrP()->setCorrectCurve(9);
        procWolfHowlDemoInit();
    }
}

void daAlink_c::handleQuickTransform() {
    if (!dusk::getSettings().game.enableQuickTransform) {
        return;
    }

    // Check to see if Link has the ability to transform.
    if (!dComIfGs_isEventBit(dSv_event_flag_c::M_077)) {
        return;
    }

    // Ensure there is a proper pointer to the mMeterClass and mpMeterDraw structs in g_meter2_info.
    const auto meterClassPtr = g_meter2_info.getMeterClass();
    if (!meterClassPtr) {
        return;
    }

    const auto meterDrawPtr = meterClassPtr->getMeterDrawPtr();
    if (!meterDrawPtr) {
        return;
    }

    // Ensure that link is not in a cutscene.
    if (checkEventRun()) {
        Z2GetAudioMgr()->seStart(Z2SE_SYS_ERROR, NULL, 0, 0, 1.0f, 1.0f, -1.0f, -1.0f, 0);
        return;
    }

    mDoCPd_c::getCpadInfo(PAD_1).mPressedButtonFlags = 0;

    // Don't allow quick transform while in the STAR tent.
    if (checkStageName("R_SP161")) {
        Z2GetAudioMgr()->seStart(Z2SE_SYS_ERROR, NULL, 0, 0, 1.0f, 1.0f, -1.0f, -1.0f, 0);
        return;
    }

    // Ensure that the Z Button is not dimmed
    if (meterDrawPtr->getButtonZAlpha() != 1.f) {
        Z2GetAudioMgr()->seStart(Z2SE_SYS_ERROR, NULL, 0, 0, 1.0f, 1.0f, -1.0f, -1.0f, 0);
        return;
    }

    // The game will crash if trying to quick transform while holding the Ball and Chain
    if (mEquipItem == dItemNo_IRONBALL_e) {
        Z2GetAudioMgr()->seStart(Z2SE_SYS_ERROR, NULL, 0, 0, 1.0f, 1.0f, -1.0f, -1.0f, 0);
        return;
    }

    // Use the game's default checks for if the player can currently transform
    if (!m_midnaActor->checkMetamorphoseEnableBase()) {
        Z2GetAudioMgr()->seStart(Z2SE_SYS_ERROR, NULL, 0, 0, 1.0f, 1.0f, -1.0f, -1.0f, 0);
        return;
    }

    bool canTransform = false;

    if (mLinkAcch.ChkGroundHit() && !checkModeFlg(MODE_PLAYER_FLY) && !checkMagneBootsOn()) {
        if (!checkForestOldCentury()) {
            if (checkMidnaRide()) {
                if ((checkWolf() &&
                     (checkModeFlg(MODE_UNK_1000) || dComIfGp_checkPlayerStatus0(0, 0x10))) ||
                    (!checkWolf() &&
                     (checkEventRun() || getMidnaActor()->checkMetamorphoseEnable()) &&
                     (checkModeFlg(4) || dComIfGp_checkPlayerStatus0(0, 0x10))))
                {
                    canTransform = true;
                }
            }
        }
    }

    if (!canTransform)
    {
        Z2GetAudioMgr()->seStart(Z2SE_SYS_ERROR, NULL, 0, 0, 1.0f, 1.0f, -1.0f, -1.0f, 0);
        return;
    }

    OSReport("Running quick transform!");
    procCoMetamorphoseInit();
}

bool daAlink_c::checkGyroAimContext() {
    switch (mProcID) {
    case PROC_SUBJECTIVITY:
    case PROC_SWIM_SUBJECTIVITY:
    case PROC_HORSE_SUBJECTIVITY:
    case PROC_CANOE_SUBJECTIVITY:
    case PROC_BOARD_SUBJECTIVITY:
    case PROC_WOLF_ROPE_SUBJECTIVITY:
    case PROC_BOW_SUBJECT:
    case PROC_BOOMERANG_SUBJECT:
    case PROC_COPY_ROD_SUBJECT:
    case PROC_HOOKSHOT_SUBJECT:
    case PROC_SWIM_HOOKSHOT_SUBJECT:
    case PROC_HORSE_BOW_SUBJECT:
    case PROC_HORSE_BOOMERANG_SUBJECT:
    case PROC_HORSE_HOOKSHOT_SUBJECT:
    case PROC_CANOE_BOW_SUBJECT:
    case PROC_CANOE_BOOMERANG_SUBJECT:
    case PROC_CANOE_HOOKSHOT_SUBJECT:
    case PROC_HOOKSHOT_ROOF_WAIT:
    case PROC_HOOKSHOT_ROOF_SHOOT:
    case PROC_HOOKSHOT_WALL_WAIT:
    case PROC_HOOKSHOT_WALL_SHOOT:
        return true;
    case PROC_IRON_BALL_SUBJECT:
        return itemButton() && mItemVar0.field_0x3018 == 2;
    default:
        return false;
    }
}
