/*
Файл называется "polish_notation_solver.h".
Программа решает арифметическое выражение в форме обратной польсокой записи.
Заголовочный файл для "polish_notation_solver.c".

Программу написал: Власов Евгений Максиович, группа ИВТ-13БО.
*/

//Защита от множественного включения.
#pragma once
//Функция подсчёта выражения в обратной польской записи.
float calculate_value(char* expression_in_rpn);
