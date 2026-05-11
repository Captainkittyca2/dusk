#include <algorithm>

#include "imgui.h"

#include "imgui/ImGuiConsole.hpp"
#include "m_Do/m_Do_graphic.h"
#include "dusk/settings.h"
#include "d/d_meter2_info.h"
#include "m_Do/m_Do_audio.h"

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
            if (saveInfoDurabilityPtr->hylianShieldDurability == 0) {
                saveInfoDurabilityPtr->hylianShieldDurability = 255;
            }
            else {
                saveInfoDurabilityPtr->woodShieldDurability = 255;
            }
            dMeter2Info_setShield(0xff, true);
            //lastShield = 0xfe;
            shieldBroke = true;
            dMeter2Info_setFloatingMessage(2047, 90, true);
            mDoAud_seStart(Z2SE_OBJ_WOODSHIELD_BREAK, 0, 0, 0);
            return false;
        }
        return true;
    }
}  // namespace dusk
