#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#pragma warning(disable:4996)

typedef struct {
	int data[MAX];
	int top;
} Stack;

void initStack(Stack* s) {
	s->top = -1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

int isFull(Stack* s) {
	return s->top == MAX - 1;
}

void push(Stack* s, int value) {
	if (isFull(s)) {
		printf("overflow");
		return;
	}
	s->data[++(s->top)] = value;
}

int peek(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is Empty");
		return -1;
	}
	return s->data[(s->top)];
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("underflow");
		return -1;
	}
	return s->data[(s->top)--];
}

void display(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is Empty");
		return;
	}
	printf("Stack contents: ");
	for (int i = 0; i <= s->top; i++) {
		printf("%c", s->data[i]);
	}
	printf("\n");
}

void reversedisplay(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is Empty");
		return;
	}
	printf("reverse Stack contents: ");

	while (!isEmpty(s)) {
		printf("%c", pop(s));
	}
}

int isMatching(char open, char close) {
	if (open == '(' && close == ')') return 1;
	if (open == '[' && close == ']') return 1;
	if (open == '{' && close == '}') return 1;
	return 0;
}

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return -1;
}

int infixToPostfix(char* infix, char* postfix) {
	Stack s;
	initStack(&s);
	int j = 0;

	for (int i = 0; infix[i] != '\0'; i++) {
		char ch = infix[i];

		if (isalpha(ch) || isdigit(ch)) {
			postfix[j++] = ch;
		}
		else if (ch == '(') {
			push(&s, ch);
		}
		else if (ch == ')') {
			while (!isEmpty(&s) && peek(&s) != '(') {
				postfix[j++] = pop(&s);
			}
			pop(&s);
		}
		else {
			while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
				postfix[j++] = pop(&s);
			}
			push(&s, ch); 
		}
	}
	while (!isEmpty(&s)) {
		postfix[j++] = pop(&s);
	}
	postfix[j] = '\0';
	return evaluatePostfix(postfix);
}

int evaluatePostfix(char* postfix) {
	Stack s;
	initStack(&s);

	for (int i = 0; postfix[i] != '\0'; i++) {
		char ch = postfix[i];

		if (isdigit(ch)) {
			push(&s, ch - '0');
		}
		else {
			int b = pop(&s);
			int a = pop(&s);
			int result;

			switch (ch) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/': result = a / b; break;
			default:
				printf("Invalid operator encountered.\n");
				exit(1);
			}
			push(&s, result);
		}
	}
	return pop(&s);
}

void isparentheses(Stack* s,char *string) { //fgets함수로 전달
	string[strcspn(string, "\n")] = '\0';
	int isValid=1;
	for (int i = 0; string[i] != '\0'; i++) {
		char ch = string[i];
		if (ch == '(' || ch == '[' || ch == '{') {
			push(s, ch);
		}
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (isEmpty(s) || !isMatching(pop(s), ch)) {
				isValid = 0;
				break;
			}
		}
	}
	if (!isEmpty(s)) isValid = 0;

	if (isValid) printf("유효한 괄호\n");
	else printf("유효하지 않은 괄호\n");

}

int main() {
	char infix[MAX];
	char postfix[MAX];
	int result;
	printf("계산할 식을 중위 표기법으로 입력하시오 : ");
	scanf("%s", infix);
	result=infixToPostfix(infix, postfix);
	printf("후위표기식 결과 : %s\n", postfix);
	printf("후위표기식 계산 결과: %d\n", result);
	return 0;
}
