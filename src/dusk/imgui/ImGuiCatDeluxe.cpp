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
#include "d/d_pane_class.h"
#include "d/d_meter2_draw.h"
#include "d/d_meter2.h"
#include "d/d_meter2_info.h"
#include "d/d_menu_window.h"
#include "d/d_menu_ring.h"
#include "d/d_meter_HIO.h"
#include "d/d_kantera_icon_meter.h"
#include "dusk/dusk.h"
#include "dusk/main.h"
#include "m_Do/m_Do_main.h"
#include "dusk/logging.h"

namespace dusk {
    ImGuiCatDeluxe::ImGuiCatDeluxe() {}

    void ImGuiCatDeluxe::draw() {
        if (ImGui::BeginMenu("Cat Deluxe")) {

            bool zButtonItems = getSettings().game.enableZButtonItems;
            if (ImGui::Checkbox("Z button Items", &zButtonItems)) {
                if (!zButtonItems) getSettings().game.enableZButtonItems.setValue(false);
                else getSettings().game.enableZButtonItems.setValue(true);
                if (!getSettings().game.enableZButtonItems) {
                    g_drawHIO.mButtonZItemBaseAlpha[0] = 0.0f;
                    /*g_drawHIO.mMidnaIconScale = 1.1f;
                    g_drawHIO.mMidnaIconAlpha = 1.0f;
                    g_drawHIO.mMidnaIconPosX = 0.0f;
                    g_drawHIO.mMidnaIconPosY = 0.0f;*/
                    if (g_meter2_info.getMeterClass() != nullptr) {
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpScreen->search(MULTI_CHAR('item_r_n'))->hide();
                        const J2DPane* parent = g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonMidona->getPanePtr()->getParentPane();
                        bool result = g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent->getPanePtr()->mPaneTree.removeChild(&g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonMidona->getPanePtr()->mPaneTree);

                        if (result && parent == NULL) {
                            g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonMidona->getPanePtr()->mTranslateX = g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent->getPanePtr()->mBounds.i.x;
                            g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonMidona->getPanePtr()->mTranslateY = g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent->getPanePtr()->mBounds.i.y;
                            g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonMidona->getPanePtr()->calcMtx();
                            g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonMidona->getPanePtr()->calcMtx();
                        }
                        //JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent);
                        //g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent = NULL;
                        JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR = NULL;
                        if (dMeter2Info_getMenuWindowClass()->mpMenuRing != nullptr) dMeter2Info_getMenuWindowClass()->mpMenuRing->mpScreen->search(MULTI_CHAR('r_btn_n'))->hide();
                        JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpKanteraMeter[2]);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpKanteraMeter[2] = NULL;
                        for (int j = 0; j < 3; j++) {
                            if (g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemNumTex[2][j] != NULL) {
                                JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemNumTex[2][j]);
                                g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemNumTex[2][j] = NULL;
                            }
                        }
                        for (int j = 0; j < 2; j++) {
                            for (int k = 0; k < 3; k++) {
                                g_meter2_info.getMeterClass()->getMeterDrawPtr()->heap->free(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYTex[2][j][k]);
                                g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYTex[2][j][k] = NULL;
                            }
                        }
                        if (g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2] != NULL) {
                            JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2]);
                            g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2] = NULL;
                        }
                        JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2]);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2] = NULL;
                        /*g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent = JKR_NEW CPaneMgr(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpScreen, MULTI_CHAR('midona_n'), 2, NULL);
                        JUT_ASSERT(0, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonMidona != NULL);*/
                        //g_meter2_info.getMeterClass()->getMeterDrawPtr()->initButtonCross();
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR = JKR_NEW CPaneMgr(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpScreen, MULTI_CHAR('r_itm_p'), 0, NULL);
                        dMeter2Info_setMeterItemPanePtr(2, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2] = JKR_NEW J2DPicture(
                            MULTI_CHAR('r_itm_pp'),
                            JGeometry::TBox2<f32>(0.0f, 0.0f, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR->getInitSizeX(), g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR->getInitSizeY()),
                            static_cast<J2DPicture*>(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR->getPanePtr())->getTexture(0)->getTexInfo(), NULL);
                        JUT_ASSERT(0, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2] != NULL);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2]->setBasePosition(J2DBasePosition_4);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR->getPanePtr()->appendChild(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2]);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->field_0x810 = g_drawHIO.mButtonZAlpha;
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mButtonZItemBaseAlpha[1] = g_drawHIO.mButtonZItemBaseAlpha[1];
                    }
                    getSettings().game.xMidonaPos.setValue(0.0f); getSettings().game.yMidonaPos.setValue(0.0f); Save();
                    DuskLog.info("Z Items Off");
                } else {
                    g_drawHIO.mButtonZItemBaseAlpha[0] = 0.5f;
                    /*g_drawHIO.mMidnaIconScale = 0.8f;
                    g_drawHIO.mMidnaIconAlpha = 1.0f;
                    g_drawHIO.mMidnaIconPosX = -160.0f;
                    g_drawHIO.mMidnaIconPosY = 25.0f;*/
                    if (g_meter2_info.getMeterClass() != nullptr) {
                        if (g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2] != NULL && dComIfGs_getSaveData()->getPlayer().getPlayerStatusA().mSelectItem[2] != 0xFF) {
                            JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2]);
                            g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2] = NULL;
                        }
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpScreen->search(MULTI_CHAR('item_r_n'))->show();
                        //JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent);
                        //g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent = NULL;
                        JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR = NULL;
                        if (dMeter2Info_getMenuWindowClass()->mpMenuRing != nullptr) dMeter2Info_getMenuWindowClass()->mpMenuRing->mpScreen->search(MULTI_CHAR('r_btn_n'))->show();
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpKanteraMeter[2] = JKR_NEW dKantera_icon_c();
                        JUT_ASSERT(0, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpKanteraMeter[2] != NULL);
                        ResTIMG* timg = (ResTIMG*)dComIfGp_getMain2DArchive()->getResource('TIMG', dMeter2Info_getNumberTextureName(0));
                        for (int j = 0; j < 3; j++) {
                            g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemNumTex[2][j] = JKR_NEW J2DPicture(timg);
                            JUT_ASSERT(0, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemNumTex[2][j] != NULL);
                        }
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->field_0x773[2] = dMeter2Info_isDirectUseItem(2);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->field_0x76c[2] = 0;

                        for (int j = 0; j < 2; j++) {
                            for (int k = 0; k < 3; k++) {
                                g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYTex[2][j][k] = (ResTIMG*)g_meter2_info.getMeterClass()->getMeterDrawPtr()->heap->alloc(0xC00, 0x20);
                                JUT_ASSERT(0, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYTex[2][j][k] != NULL);
                            }
                        }
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2] = JKR_NEW CPaneMgr(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpScreen, MULTI_CHAR('r_itm_p'), 0, NULL);
                        JUT_ASSERT(0, mpItemXY[2] != NULL);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2]->getPanePtr()->setBasePosition(J2DBasePosition_4);
                        dMeter2Info_setMeterItemPanePtr(2, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2]);
                        //g_meter2_info.getMeterClass()->getMeterDrawPtr()->initButtonCross();
                         g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonCrossParent->getPanePtr()->appendChild(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpButtonMidona->getPanePtr());
                         //g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemR = JKR_NEW CPaneMgr(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpScreen, MULTI_CHAR('midona'), 0, NULL);

                        JKR_DELETE(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2]);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2] = NULL;
                        
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2] = JKR_NEW J2DPicture(
                            MULTI_CHAR('r_itm_pp'),
                            JGeometry::TBox2<f32>(0.0f, 0.0f, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[1]->getInitSizeX(), g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2]->getInitSizeY()),
                            static_cast<J2DPicture*>(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2]->getPanePtr())->getTexture(0)->getTexInfo(), NULL);
                        JUT_ASSERT(0, g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2] != NULL);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2]->setBasePosition(J2DBasePosition_4);
                        g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXY[2]->getPanePtr()->appendChild(g_meter2_info.getMeterClass()->getMeterDrawPtr()->mpItemXYPane[2]);
                        dComIfGp_setSelectItem(2);
                        g_meter2_info.getMeterClass()->field_0x1d6[2] = dMeter2Info_isDirectUseItem(2);
                        g_meter2_info.getMeterClass()->field_0x1d8[2] = dComIfGp_getSelectItemNum(2);
                        //g_meter2_info.getMeterClass()->getMeterDrawPtr()->drawButtonXY(2, dComIfGp_getSelectItem(2), dComIfGp_getZStatus(), true, false);
                        //g_meter2_info.getMeterClass()->getMeterDrawPtr()->setButtonIconMidonaAlpha(g_meter2_info.getMeterClass()->mStatus);
                    }
                    getSettings().game.xMidonaPos.setValue(-162.6f); getSettings().game.yMidonaPos.setValue(26.1f); Save();
                    DuskLog.info("Z Items On");
                }
            }
            ImGui::SameLine();
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.72f, 0.2f, 1.0f));
            ImGui::TextUnformatted("[EXPERIMENTAL]");
            ImGui::PopStyleColor();

            if (!dusk::IsGameLaunched) {
                ImGui::BeginDisabled();
            }

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
            config::ImGuiCheckbox("Shield Durability", getSettings().game.enableShieldDurability);
            config::ImGuiCheckbox("Object Storing", getSettings().game.enableObjectStoring);
            if (ImGui::IsItemHovered()) {
                ImGui::SetTooltip("Press R while grabbing an object to store it.\nPress R + D-Pad Down to equip the stored object");
            }
            ImGui::MenuItem("Custom Meters Color", nullptr, &m_showColorMeter);
            ImGui::MenuItem("UI Editor", nullptr, &m_showUIPosition);
            ImGui::SeparatorText("Mod by Captain Kitty Cat");
            /*ImColor reeed = IM_COL32(0xFF, 0xC8, 0, 0xFF);
            ImGui::TextColored(reeed, "youtube.com/@captainkittyca2");*/
            ImGui::TextLinkOpenURL("youtube.com/@captainkittyca2", "https://www.youtube.com/@captainkittyca2");
            //ImGui::MenuItem("Stub Log", nullptr, &m_showStubLog);

            if (!dusk::IsGameLaunched) {
                ImGui::EndDisabled();
            }
            ImGui::EndMenu();
        }
    }
}
