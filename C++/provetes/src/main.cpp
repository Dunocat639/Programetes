#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main() {
    // 1. Inicialització
    InitWindow(800, 450, "El meu primer panell");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Exemple de control: GuiButton(Rectangle, Text)
            if (GuiButton((Rectangle){ 300, 160, 200, 30 }, "SOC UN BOTÓ")) {
                // El que vulguis que passi en clicar
            }

            if (GuiButton((Rectangle){500, 200, 240, 50}, "Bon dia")) {
                ClearBackground(RED);
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}