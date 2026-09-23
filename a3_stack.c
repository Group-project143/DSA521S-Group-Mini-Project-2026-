#include <stdio.h>

#define SIZE 100 

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE -1) 
    {
        printf("Stack is Overflow\n");

    }   
    else {
        top++;
        stack[top] = value;
    
    }
}   

int pop()
{
    int poppedValue;

    if (top == -1)
    {
        printf("Stack is Underflow\n");
        return 0;
    }
    else
    {
        poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top value is: %d\n", stack[top]);
    }
}

void displayStack()
{
    printf("Stack: [");

    for (int i = 0; i <= top; i++)
    {
        printf("%d", stack[i]);

        if (i < top)
        {
            printf(", ");
        }
    }

    printf("]\n");
}

void postfixEvaluation()
{
    char expression[100];
    int operand1, operand2, result;

    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    for (int i = 0; expression[i] != '\0'; i++)
{
    char item = expression[i];

    if (item == ' ')
    {
        continue;
    }

    if (item >= '0' && item <= '9')
    {
       int number = item - '0';
       push(number);

       printf("Push %d: ", number);
       displayStack();
    }   
     else if (item == '+' || item == '-' || item == '*' || item == '/')
    { 
    operand2 = pop();
    operand1 = pop();

    if (item == '+')
    {
        result = operand1 + operand2;
    }
    else if (item == '-')
    {
        result = operand1 - operand2;
    }
    else if (item == '*')
    {
        result = operand1 * operand2;
    }
    else if (item == '/')
    {
        if (operand2 == 0)
        {
            printf("Error: Cannot divide by zero\n");
            return;
        }
        result = operand1 / operand2;
    }

    push(result);
    printf("Apply %c: ", item);
    displayStack();
  } 
}

result = pop();

printf("Final Result is: %d\n", result);
}

int main()
{
    postfixEvaluation();

    return 0;
}