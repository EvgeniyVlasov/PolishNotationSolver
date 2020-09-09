/*

���� ���������� "polish_notation_solver.c".
��������� ������ �������������� ��������� � ����� �������� ��������� ������.
���� ���� ��������� ������� ��������� � �������� �������� ������.

��������� �������: ������ ������� ���������, ������ ���-13��.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
//����
float stack[STACK_SIZE];
//��������� �� ������� �����. ���������� �� = -1.
int top = -1;

//������� ��������, ���� ���� ��� ���.
static int is_empty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

//������� ��������, ����� ���� ��� ���.
static int is_full() {
    if (top == STACK_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

//������� ���������� �������� � ����.
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

//������� �������� �������� �� �����.
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

//������� �������� ��������� � �������� �������� ������.
float calculate_value(char* expression_in_rpn) {
	//���������� ����� ���������.
    char* context = NULL;
	//������ ��� ����� ���������.
    char* token = strtok_s(expression_in_rpn, " ", &context);

	//������ ��������.
	float first_arg;
	//������ ��������.
    float second_arg;
	//���� ��������� �� �����������...
    while (token != NULL) {
		//���� ��� "+", �� ������� ������ ����� � ������ � �������� ��������� � ����.
        if (!strcmp(token,"+")) {
            first_arg = pop();
            second_arg = pop();
            push(second_arg + first_arg);
        }
		//����� ���� ��� "-", �� ������� �� ������� ����� ������ � �������� ��������� � ����.
        else if (!strcmp(token, "-")) {
            first_arg = pop();
            second_arg = pop();
            push(second_arg - first_arg);
        }
		//����� ���� ��� "*", �� �������� ������ ����� � ������ � �������� ��������� � ����.
        else if (!strcmp(token, "*")) {
            first_arg = pop();
            second_arg = pop();
            push(second_arg * first_arg);
        }
		//����� ���� ��� "/", �� �������� ������ ����� � ������ � �������� ��������� � ����.
        else if (!strcmp(token, "/")) {
            first_arg = pop();
            second_arg = pop();
			//���� ���������� ������� �� ����, �� ������ ������.
            if (first_arg == 0) {
                printf("Can't evaluate expression: zero division occurs.\n");
				system("pause");
                exit(0);
            }
            push(second_arg / first_arg);
        }
		//����� ������� ����� number � �������� ��� � ����.
        else {
            float number;
			//���� ��������� �� �����, �� ������ ������.
            if (!sscanf_s(token, "%f", &number)) {
                printf("Incorrect expression: unknown token: %s.\n", token);
				system("pause");
                exit(1);
            }
            push(number);
        }
		//������� ��������� ������ ��� �����.
        token = strtok_s(NULL, " ", &context);
    }
	//���������
    float result = pop();
	//���� ���� �� ��� �� ������, �� ��������� �������� ������� � ������ ������.
    if (!is_empty()) {
        printf("Incorrect expression: stack must be empty.\n");
		system("pause");
        exit(1);
    }
    return result;
}
