#include <stdio.h>
#include <stdbool.h>
#define SIZE 30
#pragma warning(disable:4996)

typedef struct {
	int data[SIZE];
	int front;
	int rear;
}LinearQueue;

void initQueue(LinearQueue* q) {
	q->front = 0;
	q->rear = -1;
}

bool isEmpty(LinearQueue* q) {
	return q->rear < q->front;
}

bool isFull(LinearQueue* q) {
	return q->rear == SIZE - 1;
}

bool enqueue(LinearQueue* q, int value) {
	if (isFull(q)) {
		printf("큐가 가득 찼습니다.\n");
		return false;
	}
	q->rear++;
	q->data[q->rear] = value;
	return true;
}

int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어 있습니다, 큐를 초기화 합니다.\n");
		initQueue(q);
		return -1;
	}
	int value = q->data[q->front];
	q->front++;
	return value;
}

void queuedataprint(LinearQueue* q) {
	printf("queue data : ");
	for (int i = q->front; i <= q->rear; i++) {
		printf("%d ", q->data[i]);
	}
	printf("\n");


}

int main() {
	LinearQueue q;
	initQueue(&q);
	int menu=0;
	printf("선택할 메뉴를 입력하시오\n");
	while (1) {
		if (menu == 4) break;
		printf("(1 : 삽입, 2 : 삭제, 3 : 데이터 출력, 4 : 종료) : ");
		scanf("%d", &menu);
		int value = 0;
		switch (menu) {
		case 1:
			printf("삽입할 값을 입력하시오 : ");
			scanf("%d", &value);
			enqueue(&q, value);
			break;
		case 2:
			printf("Dequeue: %d\n", dequeue(&q));
			break;
		case 3:
			queuedataprint(&q);
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 메뉴 입니다 다시 입력하시오.\n");
		}
	}
	
}