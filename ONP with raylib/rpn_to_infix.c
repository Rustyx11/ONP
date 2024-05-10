
#include "rpn_to_infix.h"
/** \brief Funkcja zarzadzajaca postacia infixowa na postac odwrotnej notacji polskiej
* @param mouseOnText
* @param letterCountRpnToInfix
* @param rpn_expression
* @param rpn_to_infix_result
* @return Funkcja nie zwraca wartosci
*/
void manage_rpn_to_infix(bool *mouseOnText,int *letterCountRpnToInfix, char *rpn_expression, char *rpn_to_infix_result)
{
    DrawText("ENTER RPN EXPRESSION...", 250, 70, 20, DARKGRAY);
    Rectangle rpn_expression_box = {125, 120, 700, 50};
    Rectangle result_expression_box = {125, 300, 700, 50};

    DrawRectangleRec(rpn_expression_box, LIGHTGRAY);
    DrawRectangleRec(result_expression_box, LIGHTGRAY);
    DrawRectangleLines(result_expression_box.x, result_expression_box.y, result_expression_box.width, result_expression_box.height, DARKGRAY);
    DrawText("INFIX RESULT...", 250, 250, 20, DARKGRAY);
    DrawText(TextFormat("INPUT CHARS: %i/%i", *letterCountRpnToInfix, SIZE - 3), 600, 200, 20, DARKGRAY);

    if (CheckCollisionPointRec(GetMousePosition(), rpn_expression_box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *mouseOnText = true;
        else if (!CheckCollisionPointRec(GetMousePosition(), rpn_expression_box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *mouseOnText = false;

        if (*mouseOnText)
        {
            DrawRectangleLines(rpn_expression_box.x, rpn_expression_box.y, rpn_expression_box.width, rpn_expression_box.height, MAROON);
            int key = GetCharPressed();
            while (key > 0)
            {
                if ((( key >= 40 && key <= 57) || key == 32) && (*letterCountRpnToInfix < SIZE - 3))
                {
                    rpn_expression[*letterCountRpnToInfix] = (char)key;
                    *letterCountRpnToInfix += 1;
                   // rpn_expression[*letterCountRpnToInfix] = '\n';
                    strncpy(rpn_to_infix_result, rpn_expression, SIZE - 1);
                    convert_rpn_to_infix(rpn_to_infix_result);
                }

                key = GetCharPressed();
            }

            if(IsKeyReleased(KEY_BACKSPACE))
            {
                *letterCountRpnToInfix -= 1;
                if (*letterCountRpnToInfix < 0) *letterCountRpnToInfix = 0;
                    rpn_expression[*letterCountRpnToInfix] = '\0';
                 strncpy(rpn_to_infix_result, rpn_expression, SIZE - 1);
                    convert_rpn_to_infix(rpn_to_infix_result);
            }
        }
        else
            DrawRectangleLines(rpn_expression_box.x, rpn_expression_box.y, rpn_expression_box.width, rpn_expression_box.height, DARKGRAY);

        DrawText(rpn_expression, rpn_expression_box.x + 5, rpn_expression_box.y + 8, 40, MAROON);
        DrawText(rpn_to_infix_result, result_expression_box.x + 5, result_expression_box.y + 8, 40, MAROON);

}
