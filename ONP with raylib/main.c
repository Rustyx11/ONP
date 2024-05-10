#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "stacks.h"
#include "rpn_generator.h"
#include "conversions.h"
#include "calculate_expression.h"
#include "infix_to_rpn.h"
#include "rpn_to_infix.h"
#include "compare_times.h"

enum mode
{
    CALCULATE_EXPRESSION,
    GENERATE_RPN,
    COMPARE_TIMES,
    INFIX_TO_RPN,
    RPN_TO_INFIX,
};

int program_mode = CALCULATE_EXPRESSION; // okreslanie aktualnego stanu programu
int step_by_step = 1;


struct buttons_textures
{
    Texture2D calculate_expression_button_on;
    Texture2D calculate_expression_button_off;

    Texture2D generate_rpn_expression_button_on;
    Texture2D generate_rpn_expression_button_off;

    Texture2D compare_times_button_on;
    Texture2D compare_times_button_off;

    Texture2D infix_to_rpn_button_on;
    Texture2D infix_to_rpn_button_off;

    Texture2D rpn_to_infix_button_on;
    Texture2D rpn_to_infix_button_off;

    Texture2D generate_button_on;
    Texture2D generate_button_off;

    Texture2D step_by_step_button_on;
    Texture2D step_by_step_button_off;
};

/** \brief Wejscie do wyrazenia
* @param exp
* @return Funkcja nie zwraca wartosci
*/
void enter_the_expression(char* exp);
//double calculate_rpn_expression(char* exp, int step_by_step);
/** \brief Wyswietlanie wyniku
* @param number_node* top
* @param exp
* @return Funkcja nie zwraca wartosci
*/
void print_result(number_node* top, char* exp);
bool is_rpn(char* exp);
void stars();
/** \brief Wczytanie tekstur przyciskow
* @param buttons_textures *buttons
* @return Funkcja nie zwraca wartosci
*/
void load_buttons_textures(struct buttons_textures *buttons)
{
    buttons ->calculate_expression_button_on = LoadTexture("img/calculate_expression_on.png");
    buttons ->calculate_expression_button_off = LoadTexture("img/calculate_expression_off.png");

    buttons ->generate_rpn_expression_button_on = LoadTexture("img/generate_rpn_on.png");
    buttons ->generate_rpn_expression_button_off = LoadTexture("img/generate_rpn_off.png");

    buttons ->compare_times_button_on = LoadTexture("img/compare_times_on.png");
    buttons ->compare_times_button_off = LoadTexture("img/compare_times_off.png");

    buttons ->infix_to_rpn_button_on = LoadTexture("img/infix_to_rpn_on.png");
    buttons ->infix_to_rpn_button_off = LoadTexture("img/infix_to_rpn_off.png");

    buttons ->rpn_to_infix_button_on = LoadTexture("img/rpn_to_infix_on.png");
    buttons ->rpn_to_infix_button_off = LoadTexture("img/rpn_to_infix_off.png");

    buttons ->generate_button_on = LoadTexture("img/generate_on.png");
    buttons ->generate_button_off = LoadTexture("img/generate_off.png");

    buttons ->step_by_step_button_on = LoadTexture("img/step_by_step_on.png");
    buttons ->step_by_step_button_off = LoadTexture("img/step_by_step_off.png");

}
/** \brief funkcja ktora nie laduje tekstur przyciskow
* @param buttons_textures *buttons
* @return Funkcja nie zwraca wartosci
*/
void unload_button_textures(struct buttons_textures *buttons)
{
    UnloadTexture(buttons ->calculate_expression_button_off);
    UnloadTexture(buttons ->calculate_expression_button_on);
    UnloadTexture(buttons ->compare_times_button_off);
    UnloadTexture(buttons ->compare_times_button_on);
    UnloadTexture(buttons ->generate_rpn_expression_button_off);
    UnloadTexture(buttons ->generate_rpn_expression_button_on);
    UnloadTexture(buttons ->infix_to_rpn_button_off);
    UnloadTexture(buttons ->infix_to_rpn_button_on);
    UnloadTexture(buttons ->rpn_to_infix_button_off);
    UnloadTexture(buttons ->rpn_to_infix_button_on);
    UnloadTexture(buttons ->generate_button_off);
    UnloadTexture(buttons ->generate_button_on);
    UnloadTexture(buttons ->step_by_step_button_off);
    UnloadTexture(buttons ->step_by_step_button_on);
}
/** \brief Funkcja rysujaca przyciski
* @param buttons_textures *buttons
* @return Funkcja nie zwraca wartosci
*/
void draw_buttons(struct buttons_textures *buttons)
{
    if(GetMouseX() >= 0 && GetMouseX() <= 200 && GetMouseY() >= 0 && GetMouseY() <= 50)
    {
        DrawTexture(buttons ->calculate_expression_button_on , 0, 0, RAYWHITE);
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            program_mode = CALCULATE_EXPRESSION;
    }
    else if (program_mode == CALCULATE_EXPRESSION)
        DrawTexture(buttons ->calculate_expression_button_on , 0, 0, RAYWHITE);
    else
        DrawTexture(buttons ->calculate_expression_button_off , 0, 0, RAYWHITE);
    //---------------------------------------------------------------------------------------------------

    if(GetMouseX() >= 200 && GetMouseX() <= 400 && GetMouseY() >= 0 && GetMouseY() <= 50)
    {
        DrawTexture(buttons ->generate_rpn_expression_button_on , 200, 0, RAYWHITE);
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            program_mode = GENERATE_RPN;
    }
    else if(program_mode == GENERATE_RPN)
        DrawTexture(buttons ->generate_rpn_expression_button_on , 200, 0, RAYWHITE);
    else
        DrawTexture(buttons ->generate_rpn_expression_button_off , 200, 0, RAYWHITE);
    //---------------------------------------------------------------------------------------------------

    if(GetMouseX() >= 400 && GetMouseX() <= 600 && GetMouseY() >= 0 && GetMouseY() <= 50)
    {
        DrawTexture(buttons ->compare_times_button_on , 400, 0, RAYWHITE);
         if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            program_mode = COMPARE_TIMES;
    }
    else if(program_mode == COMPARE_TIMES)
        DrawTexture(buttons ->compare_times_button_on , 400, 0, RAYWHITE);
    else
        DrawTexture(buttons ->compare_times_button_off , 400, 0, RAYWHITE);
    //---------------------------------------------------------------------------------------------------

    if(GetMouseX() >= 600 && GetMouseX() <= 800 && GetMouseY() >= 0 && GetMouseY() <= 50)
    {
        DrawTexture(buttons ->infix_to_rpn_button_on , 600, 0, RAYWHITE);
         if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            program_mode = INFIX_TO_RPN;
    }
    else if(program_mode == INFIX_TO_RPN)
        DrawTexture(buttons ->infix_to_rpn_button_on , 600, 0, RAYWHITE);
    else
        DrawTexture(buttons ->infix_to_rpn_button_off , 600, 0, RAYWHITE);
    //---------------------------------------------------------------------------------------------------

    if(GetMouseX() >= 800 && GetMouseX() <= 1000 && GetMouseY() >= 0 && GetMouseY() <= 50)
    {
        DrawTexture(buttons ->rpn_to_infix_button_on , 800, 0, RAYWHITE);
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            program_mode = RPN_TO_INFIX;
    }
    else if(program_mode == RPN_TO_INFIX)
        DrawTexture(buttons ->rpn_to_infix_button_on , 800, 0, RAYWHITE);
    else
        DrawTexture(buttons ->rpn_to_infix_button_off , 800, 0, RAYWHITE);

    if(program_mode == GENERATE_RPN || program_mode == COMPARE_TIMES)
    {
        if(GetMouseX() >= 400 && GetMouseX() <= 600 && GetMouseY() >= 150 && GetMouseY() <= 200)
            DrawTexture(buttons ->generate_button_on , 400, 150, RAYWHITE);
        else if(program_mode == GENERATE_RPN)
            DrawTexture(buttons ->generate_button_off , 400, 150, RAYWHITE);
        else
            DrawTexture(buttons ->generate_button_off , 400, 150, RAYWHITE);
    }
    //---------------------------------------------------------------------------------------------------

    if(program_mode == CALCULATE_EXPRESSION)
    {
        if(GetMouseX() >= 700 && GetMouseX() <= 900 && GetMouseY() >= 100 && GetMouseY() <= 200)
            DrawTexture(buttons ->step_by_step_button_on , 700, 100, RAYWHITE);
        else if(step_by_step == 1)
            DrawTexture(buttons ->step_by_step_button_on , 700, 100, RAYWHITE);
        else
            DrawTexture(buttons ->step_by_step_button_off , 700, 100, RAYWHITE);
    }

}
/** \brief Funkcja dzieki ktorej wybieramy operacje
* @param decision
* @return Funkcja zwraca wartosc true lub false
*/
bool what_to_do(int *decision)
{
    printf("Select your choice:\n\n");
    printf("1. Calculate the expression.\n");
    printf("2. Generate RPN expression.\n");
    printf("3. Compare times to generate RPN expressions.\n");
    printf("4. Convert Infix expression to RPN.\n");
    printf("5. Convert RPN expression to Infix.\n");
    printf("6. Exit.\n");
    printf("Your Choice: ");
    scanf("%d", decision);


    if(*decision >= 1 && *decision <= 5)
    {
        stars();
        return true;
    }

    return false;

}



//----------------------------------------------------------------------------------------------------
int main()
{

    srand(time(NULL));

    const int screenHeight = 800;
    const int screenWidth = 1000;
    InitWindow(screenWidth,screenHeight,"ONP calculator");

    char exp[SIZE + 2];
    char conversion_result[SIZE + 2];
    memset(exp, 0, sizeof(exp));
    memset(conversion_result, 0, sizeof(conversion_result));

    int letterCounterInInfixToRpn = 0;
    char infix_expression[SIZE + 2];
    char infix_to_rpn_result[SIZE + 2];
    memset(infix_expression, 0, sizeof(infix_expression));
    memset(infix_to_rpn_result, 0, sizeof(infix_to_rpn_result));

    int letterCounterRpnToInfix = 0;
    char rpn_expression[SIZE + 2];
    char rpn_to_infix_result[SIZE + 2];
    memset(rpn_expression, 0, sizeof(rpn_expression));
    memset(rpn_to_infix_result, 0, sizeof(rpn_to_infix_result));

    int time_to_generate_expression[5] = {0,0,0,0,0};
    int size_of_generated_expression[5] = {0,0,0,0,0};


    int letterCount = 0;


    int size_of_generated_rpn = 10 + rand() % 24;
    char generated_rpn[100];
    memset(generated_rpn, 0, sizeof(generated_rpn));

    Rectangle rpnTextBox = { screenWidth / 8, 120, 500, 50 };
    Rectangle resultTextBox = { screenWidth / 8, 320, 500, 50 };
    Rectangle resultExpressionTextBox = { screenWidth/8, 600, 500, 50 };

    bool mouseOnText = false;
    struct buttons_textures buttons;
    load_buttons_textures(&buttons);

    int framesCounter = 0;

    SetTargetFPS(30);
    while(!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(WHITE);

        switch(program_mode)
        {
        case CALCULATE_EXPRESSION:
            manage_calculate_expression(&mouseOnText, rpnTextBox, &framesCounter, &letterCount, &step_by_step, exp, conversion_result);
            draw_calculate_expression_window(mouseOnText, &framesCounter, &letterCount, step_by_step,
                                          rpnTextBox, resultTextBox, resultExpressionTextBox, exp, conversion_result);
            break;
        case GENERATE_RPN:
            draw_rpn_generator(&size_of_generated_rpn, generated_rpn);
            break;
        case COMPARE_TIMES:
            draw_compare_times(time_to_generate_expression, size_of_generated_expression);
            break;
        case INFIX_TO_RPN:
            manage_infix_to_rpn(&mouseOnText, &letterCounterInInfixToRpn, infix_expression, infix_to_rpn_result);
            break;
        case RPN_TO_INFIX:
            manage_rpn_to_infix(&mouseOnText, &letterCounterRpnToInfix, rpn_expression, rpn_to_infix_result);
            break;
        default:
            manage_calculate_expression(&mouseOnText, rpnTextBox, &framesCounter, &letterCount, &step_by_step, exp, conversion_result);
            draw_calculate_expression_window(mouseOnText, &framesCounter, &letterCount, step_by_step,
                                          rpnTextBox, resultTextBox, resultExpressionTextBox, exp, conversion_result);
            break;

        }
            draw_buttons(&buttons);
            EndDrawing();
    }
    unload_button_textures(&buttons);
    CloseWindow();
    return 0;
}
/** \brief Funkcja ktora wchodzi do wyrazenia
* @param exp
* @return Funkcja nie zwraca wartosci
*/
void enter_the_expression(char* exp)
{
    printf("Enter the expression:  ");
    fflush(stdin);
    fgets(exp, SIZE - 1, stdin);
}
/** \brief Funkcja wyswietlajaca wynik
* @param number_node* top
* @param exp
* @return Funkcja nie zwraca wartosci
*/
void print_result(number_node* top, char* exp)
{
    int i = 0;
    printf("(RPN): ");
    while (exp[i] != '\0')
    {
        if(exp[i] != '\n')
            printf("%c", exp[i]);
        i++;
    }
    printf(" = %lf\n\n", pop_value(&top));
}

/** \brief Funkcja sprawdzajaca czy dzialanie jest w odwrotnej notacji polskiej
* @param number_node* top
* @param exp
* @return Funkcja nie zwraca wartosci
*/
bool is_rpn(char* exp)
{
    int i = 0;
    for (i = 0; i < (int)strlen(exp) - 1; i++)
    {
        if (exp[i] == '(')
            return false;
        else if (!isdigit(exp[i]))
        {
            switch (exp[i])
            {
            case ' ':
                if (exp[i + 1] == ' ')
                    break;
                else if (!isdigit(exp[i + 1]))
                    return false;
                else
                    return true;
                break;
            case '.': break;
            default:
                return false;
                break;
            }
        }

    }
    return false;
}

void stars()
{
    int i;
    for(i = 0; i < 75; i++)
        printf("*");
    puts("");
}
