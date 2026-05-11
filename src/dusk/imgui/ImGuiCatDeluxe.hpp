#ifndef DUSK_IMGUI_CATDELUXE_HPP
#define DUSK_IMGUI_CATDELUXE_HPP

#include <aurora/aurora.h>
#include <string>

#include "imgui.h"

namespace dusk {
    class ImGuiCatDeluxe {
    public:
        ImGuiCatDeluxe();
        void draw();
        void ShowMetersColor();
        void ShowUIPositionsWindow();

    private:
        bool m_showColorMeter = false;
        bool m_showUIPosition = false;
    };
}

#endif  // DUSK_IMGUI_CATDELUXE_HPP
