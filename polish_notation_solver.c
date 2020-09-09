/*

Файл называется "polish_notation_solver.c".
Программа решает арифметическое выражение в форме обратной польсокой записи.
Этот файл выполняет решение выражения в обратной польской записи.

Программу написал: Власов Евгений Максиович, группа ИВТ-13БО.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
//Стек
float stack[STACK_SIZE];
//Указатель на вершину стека. Изначально он = -1.
int top = -1;

//Функция проверки, пуст стек или нет.
static int is_empty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Функция проверки, полон стек или нет.
static int is_full() {
    if (top == STACK_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Функция добавления элемента в стек.
static void push(float item) {
    if (is_full()) {
        printf("Incorrect expression: stack overflow.\n");
		system("pause");
        exit(1);
    }
    else {
        top++;
        stack[top] = item;
    }
}

//Функция удаления элемента из стека.
static float pop() {
    if (is_empty()) {
        printf("Incorrect expression: stack underflow.\n");
		system("pause");
        exit(1);
    }
    else {
        float item = stack[top];
        top--;
        return item;
    }
}

//Функция подсчёта выражения в обратной польской записи.
float calculate_value(char* expression_in_rpn) {
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
            first_arg = pop();
            second_arg = pop();
            push(second_arg + first_arg);
        }
		//Иначе если это "-", то вычесть из второго числа первое и добавить результат в стек.
        else if (!strcmp(token, "-")) {
            first_arg = pop();
            second_arg = pop();
            push(second_arg - first_arg);
        }
		//Иначе если это "*", то умножить второе число с первым и добавить результат в стек.
        else if (!strcmp(token, "*")) {
            first_arg = pop();
            second_arg = pop();
            push(second_arg * first_arg);
        }
		//Иначе если это "/", то поделить второе число с первым и добавить результат в стек.
        else if (!strcmp(token, "/")) {
            first_arg = pop();
            second_arg = pop();
			//Если получается деление на ноль, то выдать ошибку.
            if (first_arg == 0) {
                printf("Can't evaluate expression: zero division occurs.\n");
				system("pause");
                exit(0);
            }
            push(second_arg / first_arg);
        }
		//Иначе считать число number и добавить его в стек.
        else {
            float number;
			//Если считалось не число, то выдать ошибку.
            if (!sscanf_s(token, "%f", &number)) {
                printf("Incorrect expression: unknown token: %s.\n", token);
				system("pause");
                exit(1);
            }
            push(number);
        }
		//Считать следующий символ или число.
        token = strtok_s(NULL, " ", &context);
    }
	//Результат
    float result = pop();
	//Если стек всё ещё не пустой, то вырежение записано неверно и выдать ошибку.
    if (!is_empty()) {
        printf("Incorrect expression: stack must be empty.\n");
		system("pause");
        exit(1);
    }
    return result;
}
