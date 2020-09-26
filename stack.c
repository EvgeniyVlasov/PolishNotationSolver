#define STACK_SIZE 100
float stack[STACK_SIZE];
int top = -1;

int is_empty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_full() {
    if (top == STACK_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}


int push(float item) {
    if (is_full()) {
        printf("stack overflow");
        return 1;
    }
    else {
        top++;
        stack[top] = item;
        return 0;
    }
}

int peek(float* buffer) {
    if (is_empty()) {
        printf("stack underflow");
        return 1;
    }
    else {
        *buffer = stack[top];
        return 0;
    }
}

int pop(float* buffer) {
    if (is_empty()) {
        printf("stack underflow");
        return 1;
    }
    else {
        float item = stack[top];
        top--;
        *buffer = item;
        return 0;
    }
}

void clear_stack() {
    top = -1;
}

