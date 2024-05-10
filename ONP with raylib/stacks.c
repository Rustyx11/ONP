#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** \brief funkcja dodaje liczbe podana przez parametr do stosu liczbowego i przez parametr zwraca wskaznik do nowego wierzcholka stosu
*@param number_node** top
*@param number
*@return jezeli nie udalo sie poprawnie przydzielic miejsca na nowy wezel funkcja konczy swoje dzialanie i zwraca wartosc false
*/
bool push_value(number_node** top, double number)
{
    number_node* new_node = (number_node*)malloc(sizeof(number_node));  // przydzielanie miejsca dla nowego wezla
    if (new_node != NULL)                                               // sprawdzenie, czy przydzial miejsca dla nowego wezla sie powiodl
    {
        new_node->value = number;       // przypisanie do pola z wartoscia nowego wezla liczby podanej przez parametr
        new_node->next = *top;          // przepisanie do wskaznika nastpenego elementu nowego wezla wskaznika na aktualny wierzcholek stosu
        *top = new_node;                // nowym wierzcholkiem stosu staje sie nowy wezel
        return true;                    // funkcja konczy swoje dzialanie i zwraca wartosc true
    }
    return false;       // jezeli nie udalo sie poprawnie przydzielic miejsca na nowy wezel funkcja konczy swoje dzialanie i zwraca wartosc false
}
/** \brief  funkcja zwraca wartosc w wierzcholku stosu, usuwa go i przez parametr zwraca wskaznik do nowego wierzcholka stosu
*@param number_node** top
*@return zwrocenie wartosci przechowywanej w usunietym wierzcholku
*/
double pop_value(number_node** top)
{
    double result = 0.0;            // inicjacja zmiennej przechowujacej aktualna wartosc wierzcholka stosu
    if (*top)                       // jezeli stos nie jest pusty
    {
        result = (*top) -> value;           // przypisanie aktualnej wartosci wierzcholka stosu do zmiennej
        number_node* tmp = (*top)->next;    // utworzenie tymczasowego wezla stosu i przypisanie do niego adresu kolejnego elementu stosu
        free(*top);                         // zwolnienie pamieci, usuniecie aktualnego wierzcholka stosu
        (*top) = tmp;                       // nowym wierzcholkiem stosu staje sie adres kolejnego elementu poprzedniego wierzcholka
    }
    return result;                          // zwrocenie wartosci przechowywanej w usunietym wierzcholku
}

void read_value_stack(number_node* top, int *lines, bool show_step_by_step)
{
    if(show_step_by_step)
    {
        DrawText(TextFormat("Stack:"), 650, 200 + *lines * 20, 18, DARKGRAY);
        for(; top != NULL; top = top -> next)
        {
            DrawText(TextFormat(" %.4lf", top -> value), 720, 200 + (*lines) * 20, 18, DARKGRAY);
            (*lines)++;
        }
    }
}
/** funkcja zapisuje tablice znakowa podana przez parametr do stosu znakowego
*@param char_array_node** top
*@param array
*@return jezeli nie udalo sie poprawnie przydzielic miejsca na nowy wezel funkcja konczy swoje dzialanie i zwraca wartosc false
*/
bool push_char_array(char_array_node** top, char* array)
{                                                         // przez parametr zwraca wskaznik do nowego wierzcholka stosu
    char_array_node* new_char_array_node = (char_array_node*)malloc(sizeof(char_array_node));   // przydzielanie miejsca dla nowego wezla
    if (new_char_array_node)                                                                    // sprawdzenie, czy przydzial miejsca dla nowego wezla sie powiodl
    {
        strncpy_s(new_char_array_node->data, SIZE - 1, array, SIZE - 1);    // przypisanie do pola z tablica znakowa nowego wezla liczby tablicy znakowej podanej przez parametr
        new_char_array_node->next = *top;                                   // przepisanie do wskaznika nastpenego elementu nowego wezla wskaznika na aktualny wierzcholek stosu
        *top = new_char_array_node;                                         // nowym wierzcholkiem stosu staje sie nowy wezel
        return true;                                                        // funkcja konczy swoje dzialanie i zwraca wartosc true
    }
    return false;   // jezeli nie udalo sie poprawnie przydzielic miejsca na nowy wezel funkcja konczy swoje dzialanie i zwraca wartosc false
}
/** funkcja zwraca wartosc w wierzcholku stosu, usuwa go
* przez parametr zwraca wskaznik do nowego wierzcholka stosu oraz zawartosc tablicy znakowej przechowywanej w wezle
*@param char_array_node** top
*@param data
*@return jezeli stos jest pusty funkcja konczy swoje dzialanie i zwraca wartosc false
*/
bool pop_char_array(char_array_node** top, char* data)
{
    if (*top)               // jezeli stos nie jest pusty
    {
        strncpy_s(data, SIZE - 1, (*top)->data, SIZE - 1);      // przpisanie zawartosci tablicy znakowej wierzcholka stosu do tablicy znakowej przekazanej przez parametr
        char_array_node* tmp = (*top)->next;                    // utworzenie tymczasowego wezla stosu i przypisanie do niego adresu kolejnego elementu stosu
        free(*top);                                             // zwolnienie pamieci, usuniecie aktualnego wierzcholka stosu
        (*top) = tmp;                                           // nowym wierzcholkiem stosu staje sie adres kolejnego elementu poprzedniego wierzcholka
        //printf("pop_char_array: %s\n", data);
        return true;     // funkcja konczy swoje dzialanie i zwraca wartosc true
    }
    return false;   // jezeli stos jest pusty funkcja konczy swoje dzialanie i zwraca wartosc false
}
