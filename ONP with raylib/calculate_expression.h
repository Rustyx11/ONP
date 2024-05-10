#ifndef calculate_expression_h
#define calculate_expression_h

#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "conversions.h"
#include "stacks.h"

extern Rectangle rpnTextBox;
extern Rectangle resultTextBox;
extern Rectangle resultExpressionTextBox;
extern bool mouseOnText;
extern int step_by_step;

double calculate_rpn_expression(char* exp, int step_by_step);
void manage_calculate_expression(bool *mouseOnText, Rectangle rpnTextBox,
                          int *framesCounter,int *letterCount, int *step_by_step,  char *exp, char *conversion_result);

void draw_calculate_expression_window(bool mouseOnText, int *framesCounter, int *letterCount, int step_by_step, Rectangle rpnTextBox,
                                      Rectangle resultTextBox, Rectangle resultExpressionTextBox,char *exp, char *conversion_result);
extern double calculate_rpn_expression(char* exp, int step_by_step);
extern bool is_rpn(char* exp);



#endif // calculate_expression_h
