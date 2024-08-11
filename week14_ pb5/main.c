#include <stdio.h>
#include <ctype.h>
#include "stack.h"
int Priority(char c);
void infixToPostfix(char* infix, char* postfix);

int main()
{
	char infix[100], postfix[100];

    printf(" Infix: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf(" Postfix: %s\n", postfix);
}

int Priority(char c)
{
	if (c == '-' || c == '+')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '^')
		return 3;
	else
		return 0;
}

void infixToPostfix(char* infix, char* postfix)
{
	stack stack;
    initialize_stack(&stack);
    int i = 0, j = 0;
	//---------------------------
	 while (infix[i] != '\0'){
		if (infix[i] == ' ') continue;

		if (isdigit(infix[i]) || isalpha(infix[i]))
        {
            postfix[j++] = infix[i];
        }
		else if (infix[i] == '(')
        {
            push_stack(&stack, infix[i]);
        }
		else if (infix[i] == ')')
        {
			while (top_stack(&stack) != '(')
            {
				postfix[j++] =  pop_stack(&stack);
			}
			 pop_stack(&stack);
		}
		else
		{
			while (!is_empty(&stack) && (Priority(top_stack(&stack)) >= Priority(infix[i])))
			{
				postfix[j++] = pop_stack(&stack);
			}
			push_stack(&stack, infix[i]);
		}
		i++;
	}

	while (!is_empty(&stack)){
		postfix[j++] = pop_stack(&stack);
	}
    postfix[j] = '\0';
}


