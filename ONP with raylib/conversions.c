#include "conversions.h"
#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


int priority(char c)
{
    switch (c)
    {
    case '+':;
    case '-': return 1;
    case '*':;
    case '/': return 2;
    case '^': return 3;
    }
    return 0;
}
/** \brief Funkcja konwertuje postac infixowa na odwrotna notacje polska
* @param expression
* @param conversion_result
* @return Funkcja nie zwraca wartosci
*/
void convert_infix_to_rpn(char* expression, char *conversion_result)
{


    char stack[SIZE], exit[SIZE];
    memset(stack, 0, SIZE - 1);
    memset(exit, 0, SIZE  - 1);
    memset(conversion_result, 0, SIZE - 1);
    int counter = 0, counter_2 = 0, i = 0;
    bool is_number = true;

    for(i = 0; i < (int)strlen(expression); i++)
    {
        if (expression[i] == '\n')
        {
             while (counter)
             {
                 exit[counter_2++] = stack[--counter];
                 exit[counter_2++] = ' ';
             }
            break;
        }

        if (isdigit(expression[i]) && i + 1 < SIZE - 1 && isdigit(expression[i + 1]))
            is_number = true;
        else
            is_number = false;


        switch (expression[i])
        {
        case ' ':
            break;
        case '(':
            stack[counter++] = '(';
            break;
        case ')':
            if(counter > 0)
            {
                while (stack[counter - 1] != '(')
                {
                    exit[counter_2++] = stack[--counter];
                    exit[counter_2++] = ' ';
                }
                counter--;
            }
            break;
        case '+':;
        case '-':;
        case '*':;
        case '/':;
        case '^':
            while (counter)
            {
                if (priority(expression[i]) == 3 || (priority(expression[i]) > priority(stack[counter - 1]))) break;
                {
                    exit[counter_2++] = stack[--counter];
                    exit[counter_2++] = ' ';
                }
            }
            stack[counter++] = expression[i];
            break;
        default:
            exit[counter_2++] = expression[i];
            if(is_number == false)
                 exit[counter_2++] = ' ';
            break;
        }
   }

    strncpy_s(conversion_result, SIZE - 1, exit, SIZE - 1);
}
/** \brief Konwertuje postac odwrotnej notacji polskiej na infixowa
* @param rpn
* @return Funkcja nie zwraca wartosci
*/
void convert_rpn_to_infix(char* rpn)
{
    char temp[SIZE], array_1[SIZE], array_2[SIZE], storage[SIZE];
    char_array_node* top = NULL;
    memset(temp, 0, SIZE - 1);
    memset(array_1, 0, SIZE - 1);
    memset(array_2, 0, SIZE - 1);
    memset(storage, 0, SIZE - 1);
    int i = 0, j, k, position = 0;


    for (i = 0; i < strlen(rpn); i++)
    {
        if (isdigit(rpn[i]))
        {
            storage[position++] = rpn[i];

            if (strlen(storage) > 0 && i + 1 < SIZE - 1 && !isdigit(rpn[i + 1]))
            {
                push_char_array(&top, storage);
                position = 0;
                memset(storage, 0, SIZE - 1);
            }
        }
        else if(rpn[i] != ' ' && rpn[i] != '\n' && rpn[i] != '\0')
        {
                pop_char_array(&top, temp);
                strncpy_s(array_1, SIZE - 1, temp, SIZE - 1);
                pop_char_array(&top, temp);
                strncpy_s(array_2, SIZE - 1, temp, SIZE - 1);
                memset(temp, 0, SIZE - 1);
                temp[0] = '(';
                for (j = 1; j < strlen(array_2) + 1; j++)
                    temp[j] = array_2[j - 1];
                temp[j] = rpn[i];

                for (j = strlen(temp), k = 0; j < strlen(array_1) + strlen(array_2) + 2; j++, k++)
                    temp[j] = array_1[k];
                temp[j] = ')';

                push_char_array(&top, temp);
                memset(temp, 0, SIZE - 1);
        }
    }
    pop_char_array(&top, temp);
    strncpy_s(rpn, SIZE-1, temp, SIZE-1);


}
