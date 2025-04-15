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
		printf("ť�� ���� á���ϴ�.\n");
		return false;
	}
	q->rear++;
	q->data[q->rear] = value;
	return true;
}

int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("ť�� ��� �ֽ��ϴ�, ť�� �ʱ�ȭ �մϴ�.\n");
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
	printf("������ �޴��� �Է��Ͻÿ�\n");
	while (1) {
		if (menu == 4) break;
		printf("(1 : ����, 2 : ����, 3 : ������ ���, 4 : ����) : ");
		scanf("%d", &menu);
		int value = 0;
		switch (menu) {
		case 1:
			printf("������ ���� �Է��Ͻÿ� : ");
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
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�߸��� �޴� �Դϴ� �ٽ� �Է��Ͻÿ�.\n");
		}
	}
	
}