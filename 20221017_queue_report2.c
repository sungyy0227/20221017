#include <stdio.h>
#include <stdbool.h>
#define SIZE 10
#pragma warning(disable:4996)

typedef struct {
	char documentName[50];
	int numPages;
}PrintJob;

typedef struct {
	PrintJob queue[SIZE];
	int front;
	int rear;
}PrintQueue;

void initQueue(PrintQueue* q) {
	q->front = 0;
	q->rear = 0;
}

bool isEmpty(PrintQueue* q) {
	return q->front == q->rear;
}

bool isFull(PrintQueue* q) {
	return (q->rear + 1) % SIZE == q->front;
}

bool enqueue(PrintQueue* q, char* documentName, int numPages) {
	if (numPages > 50) {
		printf("50페이지를 초과하는 문서는 추가할 수 없습니다.\n");
		return false;
	}
	if (isFull(q)) {
		printf("대기열이 가득 찼습니다. 작업을 추가할 수 없습니다.\n");
		return false;
	}

	strcpy(q->queue[q->rear].documentName, documentName);
	q->queue[q->rear].numPages = numPages;
	q->rear = (q->rear + 1) % SIZE;
	printf("작업 '%s' (%d 페이지)가 대기열에 추가되었습니다.\n", documentName, numPages);
	return true;
}

PrintJob dequeue(PrintQueue* q) {
	if (isEmpty(q)) {
		printf("대기열이 비어있습니다. 작업이 없습니다.\n");
		PrintJob emptyJob = { "", 0 };
		return emptyJob;
	}
	PrintJob job = q->queue[q->front];
	q->front = (q->front + 1) % SIZE;
	return job;
}

void printQueue(PrintQueue* q) {
	if (isEmpty(q)) {
		printf("대기열이 비어있습니다.\n");
		return;
	}
	printf("---대기중인 작업---\n");
	int i = q->front;
	while (i != q->rear) {
		printf("- %s (%d 페이지)\n", q->queue[i].documentName, q->queue[i].numPages);
		i = (i + 1) % SIZE;
	}
}

void clearQueue(PrintQueue* q) {
	initQueue(q);
	printf("대기열이 초기화 되었습니다.\n");
}

bool cancelJob(PrintQueue* q, char* documentName) {
	if (isEmpty(q)) {
		printf("대기열이 비어있습니다.\n");
		return false;
	}
	int found = -1;
	for (int i = q->front; i != q->rear; i = (i + 1) % SIZE) {
		if (strcmp(q->queue[i].documentName, documentName) == 0) {
			found = i;
			break;
		}
	}
	if (found == -1) {
		printf("해당 문서 없음.\n");
		return false;
	}
	for (int i = found; i != q->rear; i = (i + 1) % SIZE) {
		q->queue[i] = q->queue[(i + 1)%SIZE];
	}
	q->rear = (q->rear - 1 + SIZE) % SIZE;
	printf("문서 \'%s\'가 취소되었습니다.\n", documentName);
	return true;
}

int main() {
	PrintQueue q;
	initQueue(&q);
	int menu;
	char documentName[50];
	int numPages;

	printf("선택할 메뉴를 입력하시오\n");
	while (1) {
		printf("1)작업추가\n2)작업처리\n3)대기열출력\n4)작업취소\n5)대기열초기화\n6)종료\n입력 : ");
		scanf("%d", &menu);
		int value = 0;
		switch (menu) {
		case 1:
			printf("문서 이름: ");
			scanf("%s", documentName);
			printf("페이지 수: ");
			scanf("%d", &numPages);
			enqueue(&q, documentName, numPages);
			break;
		case 2:
			PrintJob job = dequeue(&q);
			if (strlen(job.documentName) > 0) {
				printf("작업 '%s' (%d 페이지)를 처리 중입니다...\n", job.documentName, job.numPages);
			}
			break;
		case 3:
			printQueue(&q);
			break;
		case 4:
			printf("취소할 문서 이름 : ");
			scanf("%s", documentName);
			cancelJob(&q, documentName);
			break;
		case 5:
			clearQueue(&q);
			break;
		case 6:
			printf("프로그램을 종료합니다.\n");
			return;
		default:
			printf("잘못된 메뉴 입니다 다시 입력하시오.\n");
			break;
		}
	}

}