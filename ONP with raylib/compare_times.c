#include "compare_times.h"
/** \brief funkcja porownan czasow
* @param time_to_generate_expression
* @param size_of_generated_expression
* @return Funkcja nie zwraca wartosci
*/
void draw_compare_times(int *time_to_generate_expression, int *size_of_generated_expression)
{
    int i;
    char generated_expression[20000];

    DrawText("COMPARISION OF THE TIMES OF THE GENERATED EXPRESSIONS", 125, 90, 20, DARKGRAY);
    DrawText("DEPENDING ON THEIR LENGTH...", 125, 110, 20, DARKGRAY);

    Rectangle compare_time_1 = {125, 300, 700, 50};
    Rectangle compare_time_2 = {125, 400, 700, 50};
    Rectangle compare_time_3 = {125, 500, 700, 50};
    Rectangle compare_time_4 = {125, 600, 700, 50};
    Rectangle compare_time_5 = {125, 700, 700, 50};
    Rectangle generate_button_box = {400, 150, 200, 50};

    DrawRectangleRec(compare_time_1, LIGHTGRAY);        DrawRectangleLines(compare_time_1.x, compare_time_1.y, compare_time_1.width, compare_time_1.height, DARKGRAY);
    DrawRectangleRec(compare_time_2, LIGHTGRAY);        DrawRectangleLines(compare_time_2.x, compare_time_2.y, compare_time_2.width, compare_time_2.height, DARKGRAY);
    DrawRectangleRec(compare_time_3, LIGHTGRAY);        DrawRectangleLines(compare_time_3.x, compare_time_3.y, compare_time_3.width, compare_time_3.height, DARKGRAY);
    DrawRectangleRec(compare_time_4, LIGHTGRAY);        DrawRectangleLines(compare_time_4.x, compare_time_4.y, compare_time_4.width, compare_time_4.height, DARKGRAY);
    DrawRectangleRec(compare_time_5, LIGHTGRAY);        DrawRectangleLines(compare_time_5.x, compare_time_5.y, compare_time_5.width, compare_time_5.height, DARKGRAY);

    DrawText(TextFormat("GENERATED EXPRESION OF SIZE %d took:", size_of_generated_expression[0]), compare_time_1.x + 10, compare_time_1.y - 20, 20, DARKGRAY);
    DrawText(TextFormat("GENERATED EXPRESION OF SIZE %d took:", size_of_generated_expression[1]), compare_time_2.x + 10, compare_time_2.y - 20, 20, DARKGRAY);
    DrawText(TextFormat("GENERATED EXPRESION OF SIZE %d took:", size_of_generated_expression[2]), compare_time_3.x + 10, compare_time_3.y - 20, 20, DARKGRAY);
    DrawText(TextFormat("GENERATED EXPRESION OF SIZE %d took:", size_of_generated_expression[3]), compare_time_4.x + 10, compare_time_4.y - 20, 20, DARKGRAY);
    DrawText(TextFormat("GENERATED EXPRESION OF SIZE %d took:", size_of_generated_expression[4]), compare_time_5.x + 10, compare_time_5.y - 20, 20, DARKGRAY);

    if(CheckCollisionPointRec(GetMousePosition(), generate_button_box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        for(i = 0; i < 5; i++)
        {
            size_of_generated_expression[i] = 2000 * (i + 1);
            generate_rpn(generated_expression, size_of_generated_expression[i], &time_to_generate_expression[i]);
        }
    }

    DrawText(TextFormat("%d ms", time_to_generate_expression[0]), compare_time_1.x + 10, compare_time_1.y + 8, 40, MAROON);
    DrawText(TextFormat("%d ms", time_to_generate_expression[1]), compare_time_2.x + 10, compare_time_2.y + 8, 40, MAROON);
    DrawText(TextFormat("%d ms", time_to_generate_expression[2]), compare_time_3.x + 10, compare_time_3.y + 8, 40, MAROON);
    DrawText(TextFormat("%d ms", time_to_generate_expression[3]), compare_time_4.x + 10, compare_time_4.y + 8, 40, MAROON);
    DrawText(TextFormat("%d ms", time_to_generate_expression[4]), compare_time_5.x + 10, compare_time_5.y + 8, 40, MAROON);


}
