/*
Файл называется "polish_notation_solver.c".
Программа решает арифметическое выражение в форме обратной польсокой записи.
Этот файл выполняет решение выражения в обратной польской записи.

Программу написал: Власов Евгений Максиович, группа ИВТ-13БО.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//Взятие первого и второго аргумента из стека.
void read_operands(float* first_arg, float* second_arg) {
	pop(first_arg);
	pop(second_arg);
}

//Функция подсчёта выражения в обратной польской записи.
float calculate_value(char* expression_in_rpn) {
	//Поставить указатель вершины стека в его начало.
    clear_stack();
	//Оставшаяся часть выражения.
    char* context = NULL;
	//Символ или число выражения.
    char* token = strtok_s(expression_in_rpn, " ", &context);
	//Первый аргумент.
    float first_arg;
	//Второй аргумент.
    float second_arg;
	//Пока выражение не закончилось...
    while (token != NULL) {
		//Если это "+", то сложить второе число с первым и добавить результат в стек.
        if (!strcmp(token,"+")) {
			read_operands(&first_arg, &second_arg);
            push(second_arg + first_arg);
        }
		//Иначе если это "-", то вычесть из второго числа первое и добавить результат в стек.
        else if (!strcmp(token, "-")) {
			read_operands(&first_arg, &second_arg);
            push(second_arg - first_arg);
        }
		//Иначе если это "*", то умножить второе число с первым и добавить результат в стек.
        else if (!strcmp(token, "*")) {
			read_operands(&first_arg, &second_arg);
            push(second_arg * first_arg);
        }
		//Иначе если это "/", то поделить второе число с первым и добавить результат в стек.
        else if (!strcmp(token, "/")) {
			read_operands(&first_arg, &second_arg);
			//Если получается деление на ноль, то выдать ошибку.
            if (first_arg == 0) {
                printf("Can't evaluate expression: zero division occurs.");
                exit(0);
            }
            push(second_arg / first_arg);
        }
		//Иначе считать число number и добавить его в стек.
        else {
            float number;
			//Если считалось не число, то выдать ошибку.
            if (!sscanf_s(token, "%f", &number)) {
                printf("\nIncorrect expression: unknown token =%s.", token);
                exit(1);
            }
            push(number);
        }
		//Считать следующий символ или число.
        token = strtok_s(NULL, " ", &context);
    }
	//Результат
    float result = 0;
    pop(&result);
	//Если стек всё ещё не пустой, то вырежение записано неверно и выдать ошибку.
    if (!is_empty()) {
        printf("\nIncorrect expression: stack must be empty.");
        exit(1);
    }
    return result;
}
