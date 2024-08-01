#include <stdio.h>

typedef struct stack {
    char array[10];
    int top;
    char min_array[10];
} stack;

void initialize_stack(stack *sp);
void push_stack(stack *sp, char item);
char first_element_stack(stack *sp);
void destroy_stack(stack *sp);
int size_stack(stack sp);
int is_empty(stack sp);
int is_full(stack sp);
void copy(stack *sp, stack *sp2);
char FindMin(stack *sp);
char pop_stack(stack *sp);
int is_matching_char(char open, char close);
int check_parentheses(const char *expression, stack *s);

int main() {
    stack s, s2, empty_stack;
    char expression[100];

    initialize_stack(&s);
    initialize_stack(&s2);
    initialize_stack(&empty_stack);

    printf("Enter the expression: ");
    scanf("%s", expression);

    if (check_parentheses(expression, &empty_stack) == 1) {
        printf("The expression is valid\n\n");
    } else {
        printf("The expression is not valid\n\n");
    }

    push_stack(&s, '4');
    push_stack(&s, '5');
    push_stack(&s, '0');
    push_stack(&s, '6');

    printf("The size of the stack: %d\n", size_stack(s));
    printf("The first element in the stack: %c\n", first_element_stack(&s));
    printf("The minimum element in the stack: %c\n\n", FindMin(&s));

    copy(&s, &s2);
    printf("The size of the copied stack: %d\n", size_stack(s2));
    printf("The first element in the copied stack: %c\n", first_element_stack(&s2));
    printf("The minimum element in the copied stack: %c\n\n", FindMin(&s2));

    destroy_stack(&s);
    destroy_stack(&s2);

    printf("The size of the original stack after destroying: %d\n", size_stack(s));
    printf("The size of the copied stack after destroying: %d\n", size_stack(s2));

}

void initialize_stack(stack *sp) {
    sp->top = 0;
}

int is_empty(stack sp) {
    return sp.top == 0;
}

int is_full(stack sp) {
    return sp.top == 10;
}

char first_element_stack(stack *sp) {
    if (!is_empty(*sp)) {
        return sp->array[sp->top - 1];
    }
}

void push_stack(stack *sp, char item) {
    if (!is_full(*sp)) {
        sp->array[sp->top] = item;
        if (sp->top == 0) {
            sp->min_array[sp->top] = item;
        } else {
            sp->min_array[sp->top] = (item < sp->min_array[sp->top - 1]) ? item : sp->min_array[sp->top - 1];
        }
        sp->top++;
    }
}

void destroy_stack(stack *sp) {
    sp->top = 0;
}

int size_stack(stack sp) {
    return sp.top;
}

void copy(stack *sp, stack *sp2) {
    for (int i = 0; i < sp->top; i++) {
        push_stack(sp2, sp->array[i]);
    }
}

char FindMin(stack *sp) {
    if (!is_empty(*sp)) {
        return sp->min_array[sp->top - 1];
    }
}

char pop_stack(stack *sp) {
    if (!is_empty(*sp)) {
        sp->top--;
        return sp->array[sp->top];
    }
}

int is_matching_char(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int check_parentheses(const char *expression, stack *s) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push_stack(s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (is_empty(*s)) {
                return 0;
            }

            char last_open = pop_stack(s);
            if (!is_matching_char(last_open, ch)) {
                return 0;
            }
        }
    }

    return is_empty(*s);
}
