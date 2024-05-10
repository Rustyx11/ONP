# Odwrotna notacja polska

Odwrotna notacja polska to sposób zapisu wyrażeń arytmetycznych, w którym znak wykonywanej operacji umieszczony jest po operandach (zapis postfiksowy), a nie pomiędzy nimi jak w konwencjonalnym zapisie algebraicznym (zapis infiksowy). Taki zapis pozwala na całkowitą rezygnację z użycia nawiasów w wyrażeniach, ponieważ w jednoznaczny sposób określa kolejność wykonywanych działań.

![tabelka](http://2.bp.blogspot.com/-6z9Xc0FvrPk/U5RBgXLulbI/AAAAAAAABck/bN61vs8-vqU/s1600/Przechwytywanie2.PNG)

Została opracowana przez australijskiego naukowca Charlesa Hamblina w oparciu o tak zwaną „Notacje polską” Jana Łukasiewicza na potrzeby zastosowań informatycznych. Taka notacja znacznie upraszcza wykonywanie na komputerze obliczeń z nawiasami i zachowaniem kolejności działań. Jest używana w niektórych językach programowania oraz w niektórych kalkulatorach naukowych. Programy komputerowe kompilujące program dokonują analizy wyrażenia arytmetycznego, przekształcając je na ciąg instrukcji odpowiadający odwrotnej notacji polskiej a wyrażenie to jest obliczane podczas wykonywania programu.

Do obliczenia wartości wyrażenia zapisanego w ONP potrzebujemy stosu. Zasada postępowania jest następująca:
 
Wyrażenie ONP przeglądamy od strony lewej do prawej. Jeśli napotkamy liczbę, to umieszczamy ją na stosie. Jeśli napotkamy operator, to ze stosu pobieramy dwie ostatnie liczby, wykonujemy na nich działanie zgodne z napotkanym operatorem i wynik umieszczamy z powrotem na stosie. Gdy wyrażenie zostanie przeglądnięte do końca, na szczycie stosu będzie znajdował się jego wynik.

![Jan Łukasiewicz](https://upload.wikimedia.org/wikipedia/commons/d/d2/Jan_%C5%81ukasiewicz.jpg)
Jan Łukasiewicz 1935r


## Budowa aplikacji

![menu](..\images\menu.png)

Użytkownik ma do wyboru 5 różnych zakładek, każda z nich odpowiada za inny sposób obliczenia.

### Moduł prezentacji algorytmu
![calculate_expression](..\images\calculate_expression.png)

Użytkownik na samym początku wpisuje wyrażenie w postaci infiksowej, następnie program oblicza działanie i przekształca  je na postać odwrotnej notacji polskiej. Po prawej stronie widnieje opcja step by step dzięki której możemy zobaczyć całe działanie krok po kroku.

![generate_rpn](..\images\generate_rpn.png)

Generowanie wyrażeń w notacji ONP

![compare_times](..\images\compare_times.png)

Porównywanie czasów wygenerowanych wyrażeń w zależności od ich długości.

![infix_to_rpn](..\images\infix_to_rpn.png)

Konwersja wyrażenia podanego w notacji infixowej na postać ONP

![rpn_to_infix](..\images\rpn_to_infix.png)

Konwersja wyrażenia podanego w notacji ONP na postać infixową


