#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char x)
{
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;

    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        // Operand
        if(isalnum(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        // Opening bracket
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        // Closing bracket
        else if(infix[i] == ')')
        {
            while(peek() != '(')
            {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else
        {
            while(top != -1 && precedence(peek()) >= precedence(infix[i]))
            {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop remaining
    while(top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}