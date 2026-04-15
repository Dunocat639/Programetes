#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "style_genesis.h" 

#define GUI_LAYOUT_NAME_IMPLEMENTATION
#include "gui_layout_name.h"

int main() {
    InitWindow(800, 450, "Raygui test");
    SetTargetFPS(60);

    GuiLayoutNameState state = InitGuiLayoutName();

    GuiLoadStyleGenesis();

    while (!WindowShouldClose()) {
        BeginDrawing();

            GuiLayoutName(&state);

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            
            

        EndDrawing();
    }
    CloseWindow();
    return 0;
}