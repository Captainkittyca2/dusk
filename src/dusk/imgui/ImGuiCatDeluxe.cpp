#include "fmt/format.h"
#include "imgui.h"
#include "aurora/gfx.h"

#include "dusk/hotkeys.h"
#include "dusk/settings.h"
#include "ImGuiConsole.hpp"
#include "ImGuiCatDeluxe.hpp"
#include "ImGuiConfig.hpp"

#include "ImGuiEngine.hpp"
#include "d/actor/d_a_alink.h"
#include "d/actor/d_a_horse.h"
#include "d/d_com_inf_game.h"
#include "dusk/dusk.h"
#include "dusk/main.h"
#include "m_Do/m_Do_main.h"

namespace dusk {
    ImGuiCatDeluxe::ImGuiCatDeluxe() {}

    void ImGuiCatDeluxe::draw() {
        if (ImGui::BeginMenu("Cat Deluxe")) {
            /*bool developmentMode = mDoMain::developmentMode == 1;
            if (ImGui::Checkbox("Development Mode", &developmentMode)) {
                mDoMain::developmentMode = developmentMode ? 1 : -1;
            }*/

            ImGui::Separator();

            /*auto& collisionView = getTransientSettings().collisionView;
            if (ImGui::BeginMenu("Collision View")) {
                ImGui::Checkbox("Enable Terrain view", &collisionView.enableTerrainView);
                ImGui::Checkbox("Enable wireframe view", &collisionView.enableWireframe);
                ImGui::SliderFloat("Opacity##terrain", &collisionView.terrainViewOpacity, 0.0f, 100.0f);
                ImGui::SliderFloat("Draw Range", &collisionView.drawRange, 0.0f, 1000.0f);
                ImGui::Separator();
                ImGui::Checkbox("Enable Attack Collider view", &collisionView.enableAtView);
                ImGui::Checkbox("Enable Target Collider view", &collisionView.enableTgView);
                ImGui::Checkbox("Enable Push Collider view", &collisionView.enableCoView);
                ImGui::SliderFloat("Opacity##colliders", &collisionView.colliderViewOpacity, 0.0f, 100.0f);
                ImGui::EndMenu();
            }*/

            if (!dusk::IsGameLaunched) {
                ImGui::BeginDisabled();
            }

            /*ImGui::MenuItem("Process Management", hotkeys::SHOW_PROCESS_MANAGEMENT, &m_showProcessManagement);
            ImGui::MenuItem("Debug Overlay", hotkeys::SHOW_DEBUG_OVERLAY, &m_showDebugOverlay);
            ImGui::MenuItem("Heap Viewer", hotkeys::SHOW_HEAP_VIEWER, &m_showHeapOverlay);
            ImGui::MenuItem("Player Info", hotkeys::SHOW_PLAYER_INFO, &m_showPlayerInfo);
            ImGui::MenuItem("Save Editor", hotkeys::SHOW_SAVE_EDITOR, &m_showSaveEditor);     
            ImGui::MenuItem("Map Loader", hotkeys::SHOW_MAP_LOADER, &m_showMapLoader);
            ImGui::MenuItem("State Share", hotkeys::SHOW_STATE_SHARE, &m_showStateShare);
            ImGui::MenuItem("Debug Camera", hotkeys::SHOW_DEBUG_CAMERA, &m_showCameraOverlay);
            ImGui::MenuItem("Audio Debug", hotkeys::SHOW_AUDIO_DEBUG, &m_showAudioDebug);*/
            ImGui::MenuItem("Meters Color", nullptr, &m_showColorMeter);
            config::ImGuiCheckbox("TWW HD Magic Armor", getSettings().game.enableTWWHDArmor);
            if (ImGui::IsItemHovered()) {
                ImGui::SetTooltip("Magic Armor: Only lose rupees when hit\nand rupees are visibly knocked out");
            }
            config::ImGuiCheckbox("Manual Shielding", getSettings().game.enableManualShielding);
            if (ImGui::IsItemHovered()) {
                ImGui::SetTooltip("Hold R to guard with your shield while targeting.\nHold R and press B while targeting to perform\na shield attack");
            }
            config::ImGuiCheckbox("Armors Quick-Toggle (D-Pad Down)", getSettings().game.enableArmorsQuickToggle);
            if (ImGui::IsItemHovered()) {
                ImGui::SetTooltip("Green/Magic -> Zora OR Zora -> Green: Press once\nGreen/Zora -> Magic OR Magic -> Green: Press twice");
            }
            ImGui::SeparatorText("Mod by Captain Kitty Cat");
            ImColor reeed = IM_COL32(0xFF, 0xC8, 0, 0xFF);
            ImGui::TextColored(reeed, "youtube.com/@captainkittyca2");
            //ImGui::MenuItem("Stub Log", nullptr, &m_showStubLog);

            if (!dusk::IsGameLaunched) {
                ImGui::EndDisabled();
            }
            ImGui::EndMenu();
        }
    }
}
