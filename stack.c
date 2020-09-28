/*
Файл называется "stack.c".
Программа решает арифметическое выражение в форме обратной польсокой записи.
Это файл стека.

Программу написал: Власов Евгений Максиович, группа ИВТ-13БО.
*/

#define STACK_SIZE 100
//Стек
float stack[STACK_SIZE];
//Указатель на вершину стека. Изначально он = -1.
int top = -1;

//Функция проверки, пуст стек или нет.
int is_empty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Функция проверки, полон стек или нет.
int is_full() {
    if (top == STACK_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Функция добавления элемента в стек.
int push(float item) {
    if (is_full()) {
        printf("Stack overflow.");
        return 1;
    }
    else {
        top++;
        stack[top] = item;
        return 0;
    }
}

//Функция, которая возвращает содержимое вершины стека.
int peek(float* buffer) {
    if (is_empty()) {
        printf("Stack underflow.");
        return 1;
    }
    else {
        *buffer = stack[top];
        return 0;
    }
}

//Функция удаления элемента из стека.
int pop(float* buffer) {
    if (is_empty()) {
        printf("Stack underflow.");
        return 1;
    }
    else {
        float item = stack[top];
        top--;
        *buffer = item;
        return 0;
    }
}

//Функция, которая перемещает указатель стека на его начало.
void clear_stack() {
    top = -1;
}

