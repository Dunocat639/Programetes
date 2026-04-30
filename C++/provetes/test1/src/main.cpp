#include <iostream>
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define GUI_LAYOUT_NAME_IMPLEMENTATION
#include "style_genesis.h"

class GUI {
public:

    // Input value box variables
    bool ValueBoxEditMode1 = false;
    int degrees = 0;

    // Output value box variables
    bool ValueBoxEditMode2 = false;
    int degreesOutput = 0;

    // Degress format dropdown box variables
    bool DropDownBoxEditMode = false;
    int DropDownBoxActive = 0;


    void calculate(int degrees, int &degreesOutput, int DropDownBoxActive) {

        if (DropDownBoxActive == 0) { // If celsius selected
            degreesOutput = (degrees - 32) / (9/5); // Then convert fahrenheit to celsius
            std::cout << &degreesOutput;
        }

        if (DropDownBoxActive == 1) { // If fahrenheit selected
            degreesOutput = (degrees * (9/5)) + 32; // Then convert celsius to fahrenheit
            std::cout << degreesOutput;
        }
    }


    void Update() {

        // Degrees input
        if (GuiValueBox({100, 200, 100, 25}, "Insert value: ", &degrees, -999999, 999999, ValueBoxEditMode1)) {
            ValueBoxEditMode1 = !ValueBoxEditMode1;
        }

        // Degree type dropdown
        if (GuiDropdownBox({225, 200, 125, 25}, "Celsius;Fahrenheit", &DropDownBoxActive, DropDownBoxEditMode)) {
            DropDownBoxEditMode = !DropDownBoxEditMode;
        }
        
        // Calculate button
        if (GuiButton({375, 200, 100, 25}, "Calculate")) {
            calculate(degrees, degreesOutput, DropDownBoxActive);
        }

        // Degrees output
        GuiValueBox({550, 200, 100, 25}, "Result: ", &degreesOutput, -999999, 999999, false);

    }
};



int main() {

    InitWindow(800, 450, "Raygui test");
    SetTargetFPS(60);

    GuiLoadStyleGenesis();

    GUI gui = GUI();

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        gui.Update();
        
            

        EndDrawing();
    }
    CloseWindow();
    return 0;
}