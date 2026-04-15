/*******************************************************************************************
*
*   LayoutName v1.0.0 - Tool Descriptionkk
*
*   MODULE USAGE:
*       #define GUI_LAYOUT_NAME_IMPLEMENTATION
*       #include "gui_layout_name.h"
*
*       INIT: GuiLayoutNameState state = InitGuiLayoutName();
*       DRAW: GuiLayoutName(&state);
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 raylib technologies. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <string.h>     // Required for: strcpy()

#ifndef GUI_LAYOUT_NAME_H
#define GUI_LAYOUT_NAME_H

typedef struct {
    bool ValueBOx000EditMode;
    int ValueBOx000Value;
    bool DropdownBox001EditMode;
    int DropdownBox001Active;
    bool TextOpcioEditMode;
    char TextOpcioText[128];

    Rectangle layoutRecs[6];

    // Custom state variables (depend on development software)
    // NOTE: This variables should be added manually if required

} GuiLayoutNameState;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// ...

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
GuiLayoutNameState InitGuiLayoutName(void);
void GuiLayoutName(GuiLayoutNameState *state);
static void BotoConvertir();

#ifdef __cplusplus
}
#endif

#endif // GUI_LAYOUT_NAME_H

/***********************************************************************************
*
*   GUI_LAYOUT_NAME IMPLEMENTATION
*
************************************************************************************/
#if defined(GUI_LAYOUT_NAME_IMPLEMENTATION)

#include "raygui.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Internal Module Functions Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiLayoutNameState InitGuiLayoutName(void)
{
    GuiLayoutNameState state = { 0 };

    state.ValueBOx000EditMode = false;
    state.ValueBOx000Value = 0;
    state.DropdownBox001EditMode = false;
    state.DropdownBox001Active = 0;
    state.TextOpcioEditMode = false;
    strcpy(state.TextOpcioText, "CONVERTIR A:");

    state.layoutRecs[0] = (Rectangle){ 144, 232, 120, 24 };
    state.layoutRecs[1] = (Rectangle){ 288, 232, 72, 24 };
    state.layoutRecs[2] = (Rectangle){ 384, 232, 120, 24 };
    state.layoutRecs[3] = (Rectangle){ 280, 208, 104, 16 };
    state.layoutRecs[4] = (Rectangle){ 64, 288, 120, 24 };
    state.layoutRecs[5] = (Rectangle){ 136, 288, 120, 24 };

    // Custom variables initialization

    return state;
}
static void BotoConvertir()
{
    // TODO: Implement control logic
}


void GuiLayoutName(GuiLayoutNameState *state)
{
    const char *DropdownBox001Text = "CELSIUS;FAHRENHEIT";
    const char *BotoConvertirText = "CONVERTIR";
    const char *TextResultatText = "RESULTAT:";
    const char *ResultatText = "";
    
    if (state->DropdownBox001EditMode) GuiLock();

    if (GuiValueBox(state->layoutRecs[0], ValueBOx000Text, &state->ValueBOx000Value, 0, 100, state->ValueBOx000EditMode)) state->ValueBOx000EditMode = !state->ValueBOx000EditMode;
    if (GuiButton(state->layoutRecs[2], BotoConvertirText)) BotoConvertir(); 
    if (GuiTextBox(state->layoutRecs[3], state->TextOpcioText, 128, state->TextOpcioEditMode)) state->TextOpcioEditMode = !state->TextOpcioEditMode;
    GuiLabel(state->layoutRecs[4], TextResultatText);
    GuiLabel(state->layoutRecs[5], ResultatText);
    if (GuiDropdownBox(state->layoutRecs[1], DropdownBox001Text, &state->DropdownBox001Active, state->DropdownBox001EditMode)) state->DropdownBox001EditMode = !state->DropdownBox001EditMode;
    
    GuiUnlock();
}

#endif // GUI_LAYOUT_NAME_IMPLEMENTATION
