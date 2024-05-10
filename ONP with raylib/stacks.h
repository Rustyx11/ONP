#ifndef stacks_h
#define stacks_h

#include <stdbool.h>
#include "raylib.h"

#define SIZE 19

/** \brief  struktura wezla stosu liczbowego */
struct number_stack_node
{
    double value;                    // zmienna przechowujaca wartosc wezla
    struct number_stack_node *next;  // wskaxnik na nastepny wezel
};
/** \brief struktura wezla stosu z tablica znakow */
struct char_array_stack_node
{
    char data[SIZE];                     // zmienna przechowujaca tablica znakow
    struct char_array_stack_node* next;  // wskaxnik na nastepny wezel
};


typedef struct number_stack_node number_node;             // przypisanie nazwy alternatywnej dla wezla stosu liczbowego
typedef struct char_array_stack_node char_array_node;     // przypisanie nazwy alternatywnej dla wezla z tablica znakow

bool push_value(number_node** top, double number);      // prototyp funkcji dodajacej liczbe podana przez parametr do stosu liczbowego
double pop_value(number_node** top);                    // prototyp funkcji zwracajacej wartosc w wierzcholku stosu liczbowego i usuwajacej go
void read_value_stack(number_node* top, int *lines, bool show_step_by_step);

bool push_char_array(char_array_node** top, char* array);  // prototyp funkcji zapisujacej tablice znakowa podana przez parametr do stosu liczbowego
bool pop_char_array(char_array_node** top, char* data);    // funkcja zwraca wartosc w wierzcholku stosu, usuwa go

#endif // stacks
