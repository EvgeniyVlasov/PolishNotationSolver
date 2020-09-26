/*

Файл называется "polish_notation_solver.c".
Программа решает арифметическое выражение в форме обратной польсокой записи.
Этот файл выполняет решение выражения в обратной польской записи.

Программу написал: Власов Евгений Максиович, группа ИВТ-13БО.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Функция подсчёта выражения в обратной польской записи.
float calculate_value(char* expression_in_rpn) {
    clear_stack();
    char* context = NULL;
    char* token = strtok_s(expression_in_rpn, " ", &context);

    float first_arg;
    float second_arg;
    while (token != NULL) {
        if (!strcmp(token,"+")) {
            pop(&first_arg);
            pop(&second_arg);
            push(second_arg + first_arg);
        }
        else if (!strcmp(token, "-")) {
            pop(&first_arg);
            pop(&second_arg);
            push(second_arg - first_arg);
        }
        else if (!strcmp(token, "*")) {
            pop(&first_arg);
            pop(&second_arg);
            push(second_arg * first_arg);
        }
        else if (!strcmp(token, "/")) {
            pop(&first_arg);
            pop(&second_arg);
            if (first_arg == 0) {
                printf("can't evaluate expression: zero division occurs");
                exit(0);
            }
            push(second_arg / first_arg);
        }
        else {
            float number;
            if (!sscanf_s(token, "%f", &number)) {
                printf("\nincorrect expression: unknown token =%s", token);
                exit(1);
            }
            push(number);
        }

        token = strtok_s(NULL, " ", &context);
    }

    float result = 0;
    pop(&result);
    if (!is_empty()) {
        printf("\nincorrect expression: stack must be empty.");
        exit(1);
    }
    return result;
}
