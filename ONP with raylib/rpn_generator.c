#include "rpn_generator.h"
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/** \brief funkcja losuje liczbe
* w postaci znakow i zapisuje ja w tablicy znakowej podawanej do niej przez parametr
* @param number - przechowanie liczby
* @param size_of_expression - wielkosc wyrazenia
* @return Funkcja nie zwraca wartosci
*/
void generate_number(char *number, int size_of_expression)
{
    int i;                                  // iterator i
    memset(number, 0, size_of_expression - 1);            // zerowanie tablicy znakow w ktorej bedzie przechowywana wylosowana liczba
    number[0] = (1 + rand() % 9) + '0';     // losowanie pierwszej cyfry liczby z przedzialu <1;9> (unikniecie 0 jako pierwszej cyfry liczby)
    for(i = 1; i < 1 + rand() % 5; i++)     // petla losujaca dlugosc liczby
        number[i] = (rand() % 10) + '0';    // losowanie cyfr z przedzialu <0;9>
}
/** \brief  funkcja losujaca operator matematyczny
* @return Funkcja nie zwraca wartosci
*/
char generate_math_operator()
{
    switch(rand() % NUMBER_OF_MATH_OPERATORS)            // wybor opcji w zaleznosci od wylosowania operatora z puli operatorow matematycznych
    {                                                    //(kazdy operator ma przyporzadkowana liczbe)
    case 0:
        return '+';
        break;
    case 1:
        return '-';
        break;
    case 2:
        return '*';
        break;
    case 3:
        return '/';
        break;
    case 4:
        return '^';
        break;
    default:
        return 'X';
        break;
    }

}
/** \brief funckja generuje wyrazenie ONP
*
* dlugosci podanej jako parametr i zapisuje je w tablicy znakowej podawanej przez parametr
* @param rpn_expression - Wyrazenie w ONP
* @param size_of_expression - wielkosc wyrazenia
* @param time - czas trwania
* @return Funkcja nie zwraca wartosci
*/

void generate_rpn(char *rpn_expression, int size_of_expression, int *time)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
	int i = 0, j, k;                        // iteratory
	int number_counter = 0;                 // zmienna zliczajaca ilosc pojawiajacych liczb w wyrazeniu
	int rpn_expression_length;
	char number[size_of_expression];

	memset(rpn_expression,0,size_of_expression - 1);      // zerowanie tablicy znakow w ktorej bedzie przechowywana wylosowane wyrazenie ONP
	memset(number, 0, size_of_expression - 1);            // zerowanie tablicy znakow w ktorej bedzie przechowywana wylosowana liczba

	while(i < size_of_expression - 1)                     // dopoki i miesci sie w wymiarze tablicy
	{
	    if(number_counter < 2)              // jezeli ilosc liczb jest mniejsza niz 2
	    {
	        rpn_expression_length = strlen(rpn_expression);                     // zapisanie dotychczasowej dlugosci wyrazenia
	        generate_number(number, size_of_expression);                        // wygenerowanie liczby
	        if(i + strlen(number) + 1 < size_of_expression - 1)                 // jezeli i + dlugosc wygenerowanej liczby + 1 miesci sie w wymiarze tablicy
            {
                for(j = 0, k = 0; j < strlen(number); j++, k++)                 // pêtla przepisujaca wygenerowan¹ liczbe do rownania
                {
                    rpn_expression[j + rpn_expression_length] = number[k];      // przepisywanie wygenerowanej liczby do rownania
                    i++;                                                        // inkrementacja iteratora i
                }
                    rpn_expression[i++] = ' ';                                  // utworzenie odstepu po przepisaniu liczby
                number_counter++;                                               // inkremencacja iteratora liczacego ilosc liczb
            }
            else
                break;                                                          // przerwanie petli while jezeli wygenerowana liczba nie zmiesci nie zmiesci sie w wymiarze tablicy
	    }
	    else                                                    // jezeli ilosc liczb >= 2
        {
            rpn_expression[i++] = generate_math_operator();     // wygenerowanie operatora matematycznego oraz inkrementacja iteratora i
            if(i  + 1 < size_of_expression - 1)                               // jezeli iterator i zwiekszony o 1 miesci sie w zakresie tablicy
                rpn_expression[i++] = ' ';                      // utworzenie odstepu po przepisaniu liczby
            number_counter = 1;                                 // ustawienie licznika liczb na 1, aby generowanie liczb i operatorow w nastepnych
        }                                                       // krokach programu odbywalo sie naprzemiennie
	}
	gettimeofday(&end, NULL);
	*time = (int)abs(end.tv_usec - start.tv_usec);
    return;
}
/** \brief Funkcja wyswietlajaca wynik w generatorze
* @param size_of_generated_rpn
* @param generated_rpn
* @return Funkcja nie zwraca wartosci
*/
void draw_rpn_generator(int *size_of_generated_rpn, char *generated_rpn)
{
    long int tmp = 0;
    DrawText("GENERATE EXPRESSION...", 250, 90, 20, DARKGRAY);

    Rectangle generate_button_box = {400, 150, 200, 50};
    Rectangle generated_expression_box = {125, 300, 700, 50};

    DrawText("GENERATED EXPRESSION...", 300, 280, 20, DARKGRAY);
    DrawRectangleRec(generated_expression_box, LIGHTGRAY);
    DrawRectangleLines(generated_expression_box.x, generated_expression_box.y, generated_expression_box.width, generated_expression_box.height, DARKGRAY);
    DrawText(generated_rpn, generated_expression_box.x + 5, generated_expression_box.y + 8, 40, MAROON);

    if(CheckCollisionPointRec(GetMousePosition(), generate_button_box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        generate_rpn(generated_rpn, *size_of_generated_rpn, &tmp);
    DrawText(generated_rpn, generated_expression_box.x + 5, generated_expression_box.y + 8, 40, MAROON);

}
