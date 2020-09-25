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


void push(float item) {
    if (is_full()) {
        printf("stack overflow");
        exit(1);
    }
    else {
        top++;
        stack[top] = item;
    }
}

float peek() {
    if (is_empty()) {
        printf("stack underflow");
        exit(1);
    }
    else {
        return stack[top];
    }
}

float pop() {
    if (is_empty()) {
        printf("stack underflow");
        exit(1);
    }
    else {
        float item = stack[top];
        top--;
        return item;
    }
}

void clear_stack() {
    top = -1;
}
