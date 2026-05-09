#include <algorithm>

#include "imgui.h"

#include "ImGuiUIPosition.hpp"
#include "ImGuiConsole.hpp"
#include "m_Do/m_Do_graphic.h"
#include "dusk/settings.h"
#include "ImGuiConfig.hpp"

namespace dusk {

void DrawUIPositionsWindow(bool& open) {
    if (!open) {
        return;
    }

    if (!ImGui::Begin("UI Editor", &open)) {
        ImGui::End();
        return;
    }

    if (ImGui::BeginMenu("Meters")) {
        ImGui::SeparatorText("Synced Meters");

        ImGui::Text("X Position");
        if (config::ImGuiSliderFloat("##xSyncMeterPos", getSettings().game.xSyncMeterPos, -140.0f, 700.0f, "%.1f")) {
            getSettings().game.xOxygenPos.setValue(getSettings().game.xSyncMeterPos);
            getSettings().game.xLanternPos.setValue(getSettings().game.xSyncMeterPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncMeterX")) {
            getSettings().game.xLanternPos.setValue(0.0f); getSettings().game.xOxygenPos.setValue(0.0f);
            getSettings().game.xSyncMeterPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        if (config::ImGuiSliderFloat("##ySyncMeterPos", getSettings().game.ySyncMeterPos, -80.0f, 500.0f, "%.1f")) {
            getSettings().game.yOxygenPos.setValue(getSettings().game.ySyncMeterPos);
            getSettings().game.yLanternPos.setValue(getSettings().game.ySyncMeterPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncMeterY")) {
            getSettings().game.yLanternPos.setValue(0.0f); getSettings().game.yOxygenPos.setValue(0.0f);
            getSettings().game.ySyncMeterPos.setValue(0.0f); Save();
        }
        
        ImGui::SeparatorText("Lantern Meter");

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xLanternPos", getSettings().game.xLanternPos, -140.0f, 700.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##LanternX")) {
            getSettings().game.xLanternPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yLanternPos", getSettings().game.yLanternPos, -80.0f, 500.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##LanternY")) {
            getSettings().game.yLanternPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("Oxygen Meter");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xOxygenPos", getSettings().game.xOxygenPos, -140.0f, 700.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##OxygenX")) {
            getSettings().game.xOxygenPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yOxygenPos", getSettings().game.yOxygenPos, -80.0f, 500.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##OxygenY")) {
            getSettings().game.yOxygenPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Hearts")) {
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xHeartPos", getSettings().game.xHeartPos, -540.0f, 1500.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xHeart")) {
            getSettings().game.xHeartPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yHeartPos", getSettings().game.yHeartPos, -200.0f, 550.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yHeart")) {
            getSettings().game.yHeartPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Rupees")) {

        ImGui::SeparatorText("Rupee Icon");

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xRupeePos", getSettings().game.xRupeePos, -1000.0f, 140.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xRupee")) {
            getSettings().game.xRupeePos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yRupeePos", getSettings().game.yRupeePos, -950.0f, 60.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yRupee")) {
            getSettings().game.yRupeePos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("Rupees Count");

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xRupeeTextPos", getSettings().game.xRupeeTextPos, -1000.0f, 140.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xRupeeText")) {
            getSettings().game.xRupeeTextPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yRupeeTextPos", getSettings().game.yRupeeTextPos, -950.0f, 60.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yRupeeText")) {
            getSettings().game.yRupeeTextPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("All Buttons")) {

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xAllButtonsPos", getSettings().game.xAllButtonsPos, -800.0f, 140.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##AllButtonsX")) {
            getSettings().game.xAllButtonsPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yAllButtonsPos", getSettings().game.yAllButtonsPos, -180.0f, 500.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##AllButtonsY")) {
            getSettings().game.yAllButtonsPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("A Button")) {
        ImGui::SeparatorText("Synced A Button");

        ImGui::Text("X Position");
        if (config::ImGuiSliderFloat("##xSyncAPos", getSettings().game.xSyncAPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f")) {
            getSettings().game.xBtnAPos.setValue(getSettings().game.xSyncAPos);
            getSettings().game.xTextAPos.setValue(getSettings().game.xSyncAPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncAX")) {
            getSettings().game.xBtnAPos.setValue(0.0f); getSettings().game.xTextAPos.setValue(0.0f);
            getSettings().game.xSyncAPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        if (config::ImGuiSliderFloat("##ySyncAPos", getSettings().game.ySyncAPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f")) {
            getSettings().game.yBtnAPos.setValue(getSettings().game.ySyncAPos);
            getSettings().game.yTextAPos.setValue(getSettings().game.ySyncAPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncAY")) {
            getSettings().game.yBtnAPos.setValue(0.0f); getSettings().game.yTextAPos.setValue(0.0f);
            getSettings().game.ySyncAPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("A Button");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xBtnAPos", getSettings().game.xBtnAPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xBtnA")) {
            getSettings().game.xBtnAPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yBtnAPos", getSettings().game.yBtnAPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yBtnA")) {
            getSettings().game.yBtnAPos.setValue(0.0f); Save();
        }
        
        ImGui::SeparatorText("A Text");

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xTextAPos", getSettings().game.xTextAPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xTextA")) {
            getSettings().game.xTextAPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yTextAPos", getSettings().game.yTextAPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yTextA")) {
            getSettings().game.yTextAPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("B Button")) {
        ImGui::SeparatorText("Synced B Button");

        ImGui::Text("X Position");
        if (config::ImGuiSliderFloat("##xSyncBPos", getSettings().game.xSyncBPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f")) {
            getSettings().game.xBtnBPos.setValue(getSettings().game.xSyncBPos);
            getSettings().game.xItemBPos.setValue(getSettings().game.xSyncBPos);
            getSettings().game.xTextBPos.setValue(getSettings().game.xSyncBPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncBX")) {
            getSettings().game.xBtnBPos.setValue(0.0f); getSettings().game.xTextBPos.setValue(0.0f);
            getSettings().game.xItemBPos.setValue(0.0f); getSettings().game.xSyncBPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        if (config::ImGuiSliderFloat("##ySyncBPos", getSettings().game.ySyncBPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f")) {
            getSettings().game.yBtnBPos.setValue(getSettings().game.ySyncBPos);
            getSettings().game.yItemBPos.setValue(getSettings().game.ySyncBPos);
            getSettings().game.yTextBPos.setValue(getSettings().game.ySyncBPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncBY")) {
            getSettings().game.yBtnBPos.setValue(0.0f); getSettings().game.yTextBPos.setValue(0.0f);
            getSettings().game.yItemBPos.setValue(0.0f); getSettings().game.ySyncBPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("B Button");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xBtnBPos", getSettings().game.xBtnBPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xBtnB")) {
            getSettings().game.xBtnBPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yBtnBPos", getSettings().game.yBtnBPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yBtnB")) {
            getSettings().game.yBtnBPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("B Items");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xItemBPos", getSettings().game.xItemBPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xItemB")) {
            getSettings().game.xItemBPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yItemBPos", getSettings().game.yItemBPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yItemB")) {
            getSettings().game.yItemBPos.setValue(0.0f); Save();
        }
        
        ImGui::SeparatorText("B Text");

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xTextBPos", getSettings().game.xTextBPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xTextB")) {
            getSettings().game.xTextBPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yTextBPos", getSettings().game.yTextBPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yTextB")) {
            getSettings().game.yTextBPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("X Button")) {
        ImGui::SeparatorText("Synced X Button");

        ImGui::Text("X Position");
        if (config::ImGuiSliderFloat("##xSyncXPos", getSettings().game.xSyncXPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f")) {
            getSettings().game.xBtnXPos.setValue(getSettings().game.xSyncXPos);
            getSettings().game.xItemXPos.setValue(getSettings().game.xSyncXPos);
            getSettings().game.xTextXPos.setValue(getSettings().game.xSyncXPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncXX")) {
            getSettings().game.xBtnXPos.setValue(0.0f); getSettings().game.xTextXPos.setValue(0.0f);
            getSettings().game.xItemXPos.setValue(0.0f); getSettings().game.xSyncXPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        if (config::ImGuiSliderFloat("##ySyncXPos", getSettings().game.ySyncXPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f")) {
            getSettings().game.yBtnXPos.setValue(getSettings().game.ySyncXPos);
            getSettings().game.yItemXPos.setValue(getSettings().game.ySyncXPos);
            getSettings().game.yTextXPos.setValue(getSettings().game.ySyncXPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncXY")) {
            getSettings().game.yBtnXPos.setValue(0.0f); getSettings().game.yTextXPos.setValue(0.0f);
            getSettings().game.yItemXPos.setValue(0.0f); getSettings().game.ySyncXPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("X Button");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xBtnXPos", getSettings().game.xBtnXPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xBtnX")) {
            getSettings().game.xBtnXPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yBtnXPos", getSettings().game.yBtnXPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yBtnX")) {
            getSettings().game.yBtnXPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("X Items");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xItemXPos", getSettings().game.xItemXPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xItemX")) {
            getSettings().game.xItemXPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yItemXPos", getSettings().game.yItemXPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yItemX")) {
            getSettings().game.yItemXPos.setValue(0.0f); Save();
        }
        
        ImGui::SeparatorText("X Text");

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xTextXPos", getSettings().game.xTextXPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xTextX")) {
            getSettings().game.xTextXPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yTextXPos", getSettings().game.yTextXPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yTextX")) {
            getSettings().game.yTextXPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Y Button")) {
        ImGui::SeparatorText("Synced Y Button");

        ImGui::Text("X Position");
        if (config::ImGuiSliderFloat("##xSyncYPos", getSettings().game.xSyncYPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f")) {
            getSettings().game.xBtnYPos.setValue(getSettings().game.xSyncYPos);
            getSettings().game.xItemYPos.setValue(getSettings().game.xSyncYPos);
            getSettings().game.xTextYPos.setValue(getSettings().game.xSyncYPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncYX")) {
            getSettings().game.xBtnYPos.setValue(0.0f); getSettings().game.xTextYPos.setValue(0.0f);
            getSettings().game.xItemYPos.setValue(0.0f); getSettings().game.xSyncYPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        if (config::ImGuiSliderFloat("##ySyncYPos", getSettings().game.ySyncYPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f")) {
            getSettings().game.yBtnYPos.setValue(getSettings().game.ySyncYPos);
            getSettings().game.yItemYPos.setValue(getSettings().game.ySyncYPos);
            getSettings().game.yTextYPos.setValue(getSettings().game.ySyncYPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncYY")) {
            getSettings().game.yBtnYPos.setValue(0.0f); getSettings().game.yTextYPos.setValue(0.0f);
            getSettings().game.yItemYPos.setValue(0.0f); getSettings().game.ySyncYPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("Y Button");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xBtnYPos", getSettings().game.xBtnYPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xBtnY")) {
            getSettings().game.xBtnYPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yBtnYPos", getSettings().game.yBtnYPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yBtnY")) {
            getSettings().game.yBtnYPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("Y Items");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xItemYPos", getSettings().game.xItemYPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xItemY")) {
            getSettings().game.xItemYPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yItemYPos", getSettings().game.yItemYPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yItemY")) {
            getSettings().game.yItemYPos.setValue(0.0f); Save();
        }
        
        ImGui::SeparatorText("Y Text");

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xTextYPos", getSettings().game.xTextYPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xTextY")) {
            getSettings().game.xTextYPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yTextYPos", getSettings().game.yTextYPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yTextY")) {
            getSettings().game.yTextYPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Z Button")) {
        ImGui::SeparatorText("Synced Z Button");

        ImGui::Text("X Position");
        if (config::ImGuiSliderFloat("##xSyncZPos", getSettings().game.xSyncZPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f")) {
            getSettings().game.xBtnZPos.setValue(getSettings().game.xSyncZPos);
            getSettings().game.xItemZPos.setValue(getSettings().game.xSyncZPos);
            getSettings().game.xTextZPos.setValue(getSettings().game.xSyncZPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncZX")) {
            getSettings().game.xBtnZPos.setValue(0.0f); getSettings().game.xTextZPos.setValue(0.0f);
            getSettings().game.xItemZPos.setValue(0.0f); getSettings().game.xSyncZPos.setValue(0.0f);
            Save();
        }

        ImGui::Text("Y Position");
        if (config::ImGuiSliderFloat("##ySyncZPos", getSettings().game.ySyncZPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f")) {
            getSettings().game.yBtnZPos.setValue(getSettings().game.ySyncZPos);
            getSettings().game.yItemZPos.setValue(getSettings().game.ySyncZPos);
            getSettings().game.yTextZPos.setValue(getSettings().game.ySyncZPos);
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset##SyncZY")) {
            getSettings().game.yBtnZPos.setValue(0.0f); getSettings().game.yTextZPos.setValue(0.0f);
            getSettings().game.yItemZPos.setValue(0.0f); getSettings().game.ySyncZPos.setValue(0.0f);
            Save();
        }

        ImGui::SeparatorText("Z Button");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xBtnZPos", getSettings().game.xBtnZPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xBtnZ")) {
            getSettings().game.xBtnZPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yBtnZPos", getSettings().game.yBtnZPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yBtnZ")) {
            getSettings().game.yBtnZPos.setValue(0.0f); Save();
        }

        ImGui::SeparatorText("Z Items");
        
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xItemZPos", getSettings().game.xItemZPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xItemZ")) {
            getSettings().game.xItemZPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yItemZPos", getSettings().game.yItemZPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yItemZ")) {
            getSettings().game.yItemZPos.setValue(0.0f); Save();
        }
        
        ImGui::SeparatorText("Z Text");

        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xTextZPos", getSettings().game.xTextZPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xTextZ")) {
            getSettings().game.xTextZPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yTextZPos", getSettings().game.yTextZPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yTextZ")) {
            getSettings().game.yTextZPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Midna")) {
        if (!dusk::getSettings().game.enableZButtonItems) {
            ImGui::Text("X Position");
            config::ImGuiSliderFloat("##xMidonaPos", getSettings().game.xMidonaPos, -800.0f - dusk::getSettings().game.xAllButtonsPos, 140.0f - dusk::getSettings().game.xAllButtonsPos, "%.1f");
            ImGui::SameLine();
            if (ImGui::Button("Reset##xMidona")) {
                getSettings().game.xMidonaPos.setValue(0.0f); Save();
            }

            ImGui::Text("Y Position");
            config::ImGuiSliderFloat("##yMidonaPos", getSettings().game.yMidonaPos, -180.0f - dusk::getSettings().game.yAllButtonsPos, 500.0f - dusk::getSettings().game.yAllButtonsPos, "%.1f");
            ImGui::SameLine();
            if (ImGui::Button("Reset##yMidona")) {
                getSettings().game.yMidonaPos.setValue(0.0f); Save();
            }
        } else {
            ImGui::Text("X Position");
            config::ImGuiSliderFloat("##xMidonaPos", getSettings().game.xMidonaPos, -800.0f, 1200.0f, "%.1f");
            ImGui::SameLine();
            if (ImGui::Button("Reset##xMidona")) {
                getSettings().game.xMidonaPos.setValue(-162.6f); Save();
            }

            ImGui::Text("Y Position");
            config::ImGuiSliderFloat("##yMidonaPos", getSettings().game.yMidonaPos, -820.0f, 150.0f, "%.1f");
            ImGui::SameLine();
            if (ImGui::Button("Reset##yMidona")) {
                getSettings().game.yMidonaPos.setValue(26.1f); Save();
            }
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("D-Pad")) {
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xDPadPos", getSettings().game.xDPadPos, -440.0f, 800.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xDPad")) {
            getSettings().game.xDPadPos.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yDPadPos", getSettings().game.yDPadPos, -420.0f, 350.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yDPad")) {
            getSettings().game.yDPadPos.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("D-Pad (MiniMap)")) {
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xDPadPos2", getSettings().game.xDPadPos2, -340.0f, 800.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xDPad2")) {
            getSettings().game.xDPadPos2.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yDPadPos2", getSettings().game.yDPadPos2, -320.0f, 500.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yDPad2")) {
            getSettings().game.yDPadPos2.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("MiniMap")) {
        ImGui::Text("X Position");
        config::ImGuiSliderFloat("##xMinMap", getSettings().game.xMinMap, -340.0f, 1200.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##xMinMap")) {
            getSettings().game.xMinMap.setValue(0.0f); Save();
        }

        ImGui::Text("Y Position");
        config::ImGuiSliderFloat("##yMinMap", getSettings().game.yMinMap, -820.0f, 550.0f, "%.1f");
        ImGui::SameLine();
        if (ImGui::Button("Reset##yMinMap")) {
            getSettings().game.yMinMap.setValue(0.0f); Save();
        }
        ImGui::EndMenu();
    }
    ImGui::End();
}



void ImGuiCatDeluxe::ShowUIPositionsWindow() {
    DrawUIPositionsWindow(m_showUIPosition);
}
}  // namespace dusk
