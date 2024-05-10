#include "infix_to_rpn.h"
/** \brief Funkcja zarzadzajaca postacia infixowa na postac odwrotnej notacji polskiej
* @param mouseOnText
* @param letterCountInInfixToRpn
* @param infix_expression
* @param infix_to_rpn_result
* @return Funkcja nie zwraca wartosci
*/
void manage_infix_to_rpn(bool *mouseOnText,int *letterCountInInfixToRpn, char *infix_expression, char *infix_to_rpn_result)
{
    DrawText("ENTER INFIX EXPRESSION...", 250, 70, 20, DARKGRAY);
    Rectangle infix_expression_box = {125, 120, 700, 50};
    Rectangle result_expression_box = {125, 300, 700, 50};

    DrawRectangleRec(infix_expression_box, LIGHTGRAY);
    DrawRectangleRec(result_expression_box, LIGHTGRAY);
    DrawRectangleLines(result_expression_box.x, result_expression_box.y, result_expression_box.width, result_expression_box.height, DARKGRAY);
    DrawText("RPN RESULT...", 250, 250, 20, DARKGRAY);
    DrawText(TextFormat("INPUT CHARS: %i/%i", *letterCountInInfixToRpn, SIZE - 3), 600, 200, 20, DARKGRAY);

    if (CheckCollisionPointRec(GetMousePosition(), infix_expression_box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *mouseOnText = true;
        else if (!CheckCollisionPointRec(GetMousePosition(), infix_expression_box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *mouseOnText = false;

        if (*mouseOnText)
        {
            DrawRectangleLines(infix_expression_box.x, infix_expression_box.y, infix_expression_box.width, infix_expression_box.height, MAROON);
            int key = GetCharPressed();
            while (key > 0)
            {
                if ((( key >= 40 && key <= 57) || key == 32) && (*letterCountInInfixToRpn < SIZE - 3))
                {
                    infix_expression[*letterCountInInfixToRpn] = (char)key;
                    *letterCountInInfixToRpn += 1;
                    infix_expression[*letterCountInInfixToRpn] = '\n';
                    convert_infix_to_rpn(infix_expression, infix_to_rpn_result);
                }

                key = GetCharPressed();
            }

            if(IsKeyReleased(KEY_BACKSPACE))
            {
                *letterCountInInfixToRpn -= 1;
                if (*letterCountInInfixToRpn < 0) *letterCountInInfixToRpn = 0;
                    infix_expression[*letterCountInInfixToRpn] = '\0';
                 convert_infix_to_rpn(infix_expression, infix_to_rpn_result);
            }
        }
        else
            DrawRectangleLines(infix_expression_box.x, infix_expression_box.y, infix_expression_box.width, infix_expression_box.height, DARKGRAY);

         DrawText(infix_expression, infix_expression_box.x + 5, infix_expression_box.y + 8, 40, MAROON);
         DrawText(infix_to_rpn_result, result_expression_box.x + 5, result_expression_box.y + 8, 40, MAROON);

}
