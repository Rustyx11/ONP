#ifndef compare_times_h
#define compare_times_h

#include "raylib.h"
#include "rpn_generator.h"

 extern int time_to_generate_expression;
 extern int size_of_generated_expression;

void draw_compare_times(int *time_to_generate_expression, int *size_of_generated_expression);
#endif // compare_times_h
