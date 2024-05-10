#ifndef rpn_generator_h
#define rpn_generator_h

#define NUMBER_OF_MATH_OPERATORS 5

#include "raylib.h"

/** \brief prototyp funkcji losujacej liczbe w postaci znakow i zapisujacej ja w tablicy znakowej podawanej do niej przez parametr */
void generate_number(char *number, int size_of_expression);
/** \brief prototyp funkcji losujacej operator matematyczny */
char generate_math_operator();
/** \brief prototyp funckja generujacej wyrazenie ONP i zapisujacej je w tablicy znakowej podawanej przez parametr */
void generate_rpn(char *onp_expression, int size_of_expression, int *time);

void draw_rpn_generator(int *size_of_generated_rpn, char *generated_rpn);


#endif // rpn_generator_h
