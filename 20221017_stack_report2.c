#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

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

int main() {
	Stack s;
	initStack(&s);
	char string[MAX];
	int isValid = 1;
	printf("문자열을 입력하시오 : ");
	fgets(string,MAX,stdin);
	string[strcspn(string, "\n")] = '\0';

	for (int i = 0; string[i] != '\0'; i++) {
		char ch = string[i];
		if (ch == '(' || ch == '[' || ch == '{') {
			push(&s, ch);
		}
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (isEmpty(&s) || !isMatching(pop(&s), ch)) {
				isValid = 0;
				break;
			}
		}
	}
	if (!isEmpty(&s)) isValid = 0;

	if (isValid) printf("유효한 괄호\n");
	else printf("유효하지 않은 괄호\n");
}