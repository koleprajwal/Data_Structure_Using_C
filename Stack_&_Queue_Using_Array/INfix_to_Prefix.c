#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return -1;
}


void reverseExpression(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {

        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

int main() {
    char exp[20], result[20];
    char *e, x;
    int k = 0;

    printf("Enter the expression: ");
    scanf("%s", exp);


    reverseExpression(exp);


    e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) {
            result[k++] = *e; 
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {

            while ((x = pop()) != '(')
                result[k++] = x;
        } else {

            while (top != -1 && priority(stack[top]) >= priority(*e))
                result[k++] = pop();
            push(*e);
        }
        e++;
    }


    while (top != -1)
        result[k++] = pop();

    result[k] = '\0';


    reverseExpression(result);

    printf("Prefix Expression: %s\n", result);

    return 0;
}

