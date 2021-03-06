/*
Файл называется "stack.h".
Программа решает арифметическое выражение в форме обратной польсокой записи.
Заголовочный файл для "stack.c".

Программу написал: Власов Евгений Максиович, группа ИВТ-13БО.
*/

//Защита от множественного включения.
#pragma once
//Функция проверки, пуст стек или нет.
int is_empty();
//Функция проверки, полон стек или нет.
int is_full();
//Функция добавления элемента в стек.
int push(float item) ;
//Функция, которая возвращает содержимое вершины стека.
int peek(float* buffer);
//Функция удаления элемента из стека.
int pop(float* buffer);
//Функция, которая перемещает указатель стека на его начало.
void clear_stack();
