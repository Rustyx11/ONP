#include "calculate_expression.h"

/** \brief Funkcja obliczajaca dzialanie odwrotniej notacji polskiej
* @param exp
* @param step_by_step
* @return Funkcja zwraca wartosc NULL
*/
double calculate_rpn_expression(char* exp, int step_by_step)
{
    number_node* top = NULL;
    char temp[SIZE];
    int lines = 0;
    bool show_step_by_step = true;

    memset(temp, 0, SIZE * sizeof(char));  //zerowanie tymczasowej tablicy przechowujacej liczbe
    unsigned int i = 0, counter = 0;
    double result = 0, temp_value = 0, first_argument = 0, second_argument = 0;
    for (i = 0; i < strlen(exp); i++)
    {

        //if (lines > )
        if(lines > 22)
        {
            DrawText(TextFormat("TOO MUCH LINES TO DISPLAY!!!"), 650, 200 + lines * 20, 18, DARKGRAY);
            show_step_by_step = false;
        }
        else
            show_step_by_step = true;

        if(step_by_step == 1 && show_step_by_step)
        {
            if(exp[i] != ' ')
            {
                DrawText(TextFormat("Considered char: %c", exp[i]), 650, 200 + lines * 20, 18, DARKGRAY);
                lines++;
            }
        }
        if (isdigit(exp[i]) || exp[i] == '.')
        {
            temp[counter++] = exp[i];                       // przepisywanei cyfry do tablicy, ktora bedzie j¹ przechowywac
            if(step_by_step == 1 && show_step_by_step)
            {
                DrawText(TextFormat("Number array: %s", temp), 650, 200 + lines * 20, 18, DARKGRAY);
                lines++;
            }
        }
        else
        {
            temp_value = atof(temp);                        // zamiana liczby z ciagu znakow na liczbe
            if (temp_value != 0)                             // nie umieszczamy 0 na stosie
                push_value(&top, temp_value);                    // umieszczenie liczby na stosie
            memset(temp, 0, SIZE);                          //zerowanie tablicy zeby moc umiescic w niej nowa liczbe z ciagu
            counter = 0;                                    // zerowanie licznika

            if(step_by_step == 1 && show_step_by_step)
            {
                DrawText(TextFormat("Stack:"), 650, 200 + lines * 20, 18, DARKGRAY);
                read_value_stack(top, &lines, show_step_by_step);
                lines++;
            }
            switch (exp[i])
            {
            case '+':
                first_argument = pop_value(&top);
                second_argument = pop_value(&top);
                result = first_argument + second_argument;
                push_value(&top, result);
                if(step_by_step == 1 && show_step_by_step)
                {
                    DrawText(TextFormat("Operation: %.4lf + %.4lf = %.4lf\n", first_argument, second_argument, result), 650, 200 + lines * 20, 18, DARKGRAY);
                    lines++;
                    read_value_stack(top, &lines, show_step_by_step);
                    lines++;
                }
                break;
            case '-':
                first_argument = pop_value(&top);
                second_argument = pop_value(&top);
                result = second_argument - first_argument;
                push_value(&top, result);
                if(step_by_step == 1 && show_step_by_step)
                {
                    DrawText(TextFormat("Operation: %.4lf - %.4lf = %.4lf\n", second_argument, first_argument, result), 650, 200 + lines * 20, 18, DARKGRAY);
                    lines++;
                    read_value_stack(top, &lines, show_step_by_step);
                    lines++;
                }
                break;
            case 'x':
            case '*':
                first_argument = pop_value(&top);
                second_argument = pop_value(&top);
                result = first_argument * second_argument;
                push_value(&top, result);

                if(step_by_step == 1 && show_step_by_step)
                {
                    DrawText(TextFormat("Operation: %.4lf * %.4lf = %.4lf\n", first_argument, second_argument, result), 650, 200 + lines * 20, 18, DARKGRAY);
                    lines++;
                    read_value_stack(top, &lines, show_step_by_step);
                    lines++;
                }
                break;
            case '/':
                first_argument = pop_value(&top);
                second_argument = pop_value(&top);
                result = second_argument / first_argument;
                push_value(&top, result);
                if(step_by_step == 1 && show_step_by_step)
                {
                    DrawText(TextFormat("Operation: %.4lf / %.4lf = %.4lf\n", first_argument, second_argument, result), 650, 200 + lines * 20, 18, DARKGRAY);
                    lines++;
                    read_value_stack(top, &lines, show_step_by_step);
                    lines++;
                }
                break;
            case '^':
                first_argument = pop_value(&top);
                second_argument = pop_value(&top);
                result = pow(first_argument, second_argument);
                push_value(&top, result);

                if(step_by_step == 1 && show_step_by_step)
                {
                    DrawText(TextFormat("Operation: %.4lf ^ %.4lf = %.4lf\n", first_argument, second_argument, result), 650, 200 + lines * 20, 18, DARKGRAY);
                    lines++;
                    read_value_stack(top, &lines, show_step_by_step);
                    lines++;
                }
                break;
            default:
                continue;
            }

        }
    }
    if(top)
        return pop_value(&top);;
    return 0;
}
/** \brief Funkcja obliczajaca dzialanie odwrotniej notacji polskiej
* @param mouseOnText
* @param Rectangle rpnTextBox
* @param framesCounter
* @param letterCount
* @param step_by_step
* @param exp
* @param conversion_result
* @return Funkcja nie zwraca wartosci
*/
void manage_calculate_expression(bool *mouseOnText, Rectangle rpnTextBox, int *framesCounter,int *letterCount, int *step_by_step,  char *exp, char *conversion_result)
{
    char temp[SIZE + 2];
    memset(temp, 0, sizeof(temp));

    Rectangle step_by_step_box = {700, 100, 200, 50};

     if (CheckCollisionPointRec(GetMousePosition(), step_by_step_box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && *step_by_step != 1)
            *step_by_step = 1;
    else if (CheckCollisionPointRec(GetMousePosition(), step_by_step_box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && *step_by_step == 1)
            *step_by_step = 0;


    if (CheckCollisionPointRec(GetMousePosition(), rpnTextBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *mouseOnText = true;
        else if (!CheckCollisionPointRec(GetMousePosition(), rpnTextBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *mouseOnText = false;

        if (*mouseOnText)
        {
            int key = GetCharPressed();
            while (key > 0)
            {
                if ((( key >= 40 && key <= 57) || key == 32) && (*letterCount < SIZE - 3))
                {
                    exp[*letterCount] = (char)key;
                    *letterCount += 1;
                    exp[*letterCount] = '\n';
                }

                key = GetCharPressed();
            }

            if(IsKeyReleased(KEY_BACKSPACE))
            {
                *letterCount -= 1;
                if (*letterCount < 0) *letterCount = 0;
                    exp[*letterCount] = '\0';
            }



                if(is_rpn(exp))
                {
                    strncpy(temp, exp, SIZE-1);
                    strncpy(conversion_result, exp, SIZE-1);
                    convert_rpn_to_infix(conversion_result);
                }
                else
                {
                    strncpy(temp, exp, SIZE-1);
                    convert_infix_to_rpn(temp, conversion_result);
                }
        }

        if (*mouseOnText) *framesCounter += 1;
        else *framesCounter = 0;




}
/** \brief Funkcja ktora wyswietla obliczone dzialanie
* @param mouseOnText
* @param framesCounter
* @param letterCount
* @param step_by_step
* @param Rectangle rpnTextBox
* @param Rectangle resultTextBox
* @param Rectangle resultExpressionTextBox
* @param exp
* @param conversion_result
* @return Funkcja nie zwraca wartosci
*/
void draw_calculate_expression_window(bool mouseOnText, int *framesCounter, int *letterCount, int step_by_step, Rectangle rpnTextBox,
                                      Rectangle resultTextBox, Rectangle resultExpressionTextBox,char *exp, char *conversion_result)
{
    DrawRectangleRec(rpnTextBox, GRAY);

    DrawText("ENTER THE EXPRESSION", 250, 70, 20, DARKGRAY);

    DrawRectangleRec(rpnTextBox, LIGHTGRAY);
    if (mouseOnText) DrawRectangleLines(rpnTextBox.x, rpnTextBox.y, rpnTextBox.width, rpnTextBox.height, RED);
    else DrawRectangleLines(rpnTextBox.x, rpnTextBox.y, rpnTextBox.width, rpnTextBox.height, DARKGRAY);

    DrawText(exp, rpnTextBox.x + 5, rpnTextBox.y + 8, 40, MAROON);

    DrawText(TextFormat("INPUT CHARS: %i/%i", *letterCount, SIZE - 3), 400, 200, 20, DARKGRAY);

    if (mouseOnText)
    {
        if (*letterCount < SIZE)
        {
            // Draw blinking underscore char
            if (((*framesCounter/20)%2) == 0) DrawText("_", rpnTextBox.x + 8 + MeasureText(exp, 40), rpnTextBox.y + 12, 40, MAROON);
        }
        else DrawText("Press BACKSPACE to delete chars...", 350, 120, 20, DARKGRAY);
    }

    DrawText("RESULT", 350, 280, 20, DARKGRAY);
    DrawRectangleRec(resultTextBox, LIGHTGRAY);
    DrawRectangleLines(resultTextBox.x, resultTextBox.y, resultTextBox.width, resultTextBox.height, DARKGRAY);
    DrawRectangleRec(resultExpressionTextBox, LIGHTGRAY);
    DrawRectangleLines(resultExpressionTextBox.x, resultExpressionTextBox.y, resultExpressionTextBox.width, resultExpressionTextBox.height, DARKGRAY);

    if(strlen(exp) > 0)
    {

        if(is_rpn(exp))
        {
            DrawText("YOU HAVE ENTERED RPN EXPRESSION!", 200, 520, 20, BLACK);
            DrawText("THIS IS INFIX NOTATION", 240, 560, 20, BLACK);
            DrawText(TextFormat("%lf", calculate_rpn_expression(exp, step_by_step)),resultTextBox.x + 5, resultTextBox.y + 8, 40, MAROON);
            DrawText(conversion_result,resultExpressionTextBox.x + 5, resultExpressionTextBox.y + 8, 40, MAROON);
        }
        else
        {
            DrawText("YOU HAVE ENTERED INFIX EXPRESSION!", 180, 520, 20, BLACK);
            DrawText("THIS IS ONP NOTATION", 220, 560, 20, BLACK);
            DrawText(TextFormat("%.4lf", calculate_rpn_expression(conversion_result, step_by_step)),resultTextBox.x + 5, resultTextBox.y + 8, 40, MAROON);
            DrawText(conversion_result,resultExpressionTextBox.x + 5, resultExpressionTextBox.y + 8, 40, MAROON);
        }
    }
}
