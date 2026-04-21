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

    private:
        bool m_showColorMeter = false;
    };
}

#endif  // DUSK_IMGUI_CATDELUXE_HPP
