#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "style_genesis.h" 

int main() {
    InitWindow(800, 450, "Raygui test");
    SetTargetFPS(60);

    GuiLoadStyleGenesis(); 

    while (!WindowShouldClose()) {
        BeginDrawing();
        
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            
            if (GuiButton((Rectangle){ 300, 200, 200, 30 }, "ARA SÍ QUE FUNCIONA")) {
                
            }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}