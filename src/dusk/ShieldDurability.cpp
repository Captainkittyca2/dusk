#include <algorithm>

#include "imgui.h"

#include "imgui/ImGuiConsole.hpp"
#include "m_Do/m_Do_graphic.h"
#include "dusk/settings.h"
#include "d/d_meter2_info.h"
#include "m_Do/m_Do_audio.h"
#include "d/d_com_inf_game.h"

namespace dusk {
    bool shieldDurability(uint8_t shieldType, bool strongAttack) {
        uint8_t attackPlus = 0;
        if (strongAttack) attackPlus = 30;
        if (shieldType == 2) {
            if (saveInfoDurabilityPtr->hylianShieldDurability - (50 + attackPlus) < 0) saveInfoDurabilityPtr->hylianShieldDurability = 0;
            else saveInfoDurabilityPtr->hylianShieldDurability -= (50 + attackPlus);
        } else if (shieldType == 0) {
            if (saveInfoDurabilityPtr->woodShieldDurability - (80 + attackPlus) < 0) saveInfoDurabilityPtr->woodShieldDurability = 0;
            else saveInfoDurabilityPtr->woodShieldDurability -= (80 + attackPlus);
        } else {
            if (saveInfoDurabilityPtr->woodShieldDurability - (100 + attackPlus) < 0) saveInfoDurabilityPtr->woodShieldDurability = 0;
            else saveInfoDurabilityPtr->woodShieldDurability -= (100 + attackPlus);
        }

        if (saveInfoDurabilityPtr->woodShieldDurability == 0 || saveInfoDurabilityPtr->hylianShieldDurability == 0) {
            dMeter2Info_setShield(0xff, true);
            if (saveInfoDurabilityPtr->hylianShieldDurability == 0) {
                dComIfGs_offEventBit(0x6102);
                dSv_memBit_c& membit = g_dComIfG_gameInfo.info.mMemory.mBit;
                auto* stageeData = dComIfGp_getStageStagInfo();
                if (stageeData != 0) {
                    uint8_t stageeIndex = dStage_stagInfo_GetSaveTbl(stageeData);
                    if (stageeIndex == 3) g_dComIfG_gameInfo.info.mMemory.mBit.mSwitch[1] &= ~(2 << 24);
                    else dComIfGs_getSaveData()->getSave(3).mBit.mSwitch[1] &= ~(2 << 24);
                }
                saveInfoDurabilityPtr->hylianShieldDurability = 255;
            }
            else {
                saveInfoDurabilityPtr->woodShieldDurability = 255;
            }
            //lastShield = 0xfe;
            shieldBroke = true;
            dMeter2Info_setFloatingMessage(2047, 90, true);
            mDoAud_seStart(Z2SE_OBJ_WOODSHIELD_BREAK, 0, 0, 0);
            return false;
        }
        return true;
    }
}  // namespace dusk
