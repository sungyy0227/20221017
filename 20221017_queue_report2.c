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
		printf("50�������� �ʰ��ϴ� ������ �߰��� �� �����ϴ�.\n");
		return false;
	}
	if (isFull(q)) {
		printf("��⿭�� ���� á���ϴ�. �۾��� �߰��� �� �����ϴ�.\n");
		return false;
	}

	strcpy(q->queue[q->rear].documentName, documentName);
	q->queue[q->rear].numPages = numPages;
	q->rear = (q->rear + 1) % SIZE;
	printf("�۾� '%s' (%d ������)�� ��⿭�� �߰��Ǿ����ϴ�.\n", documentName, numPages);
	return true;
}

PrintJob dequeue(PrintQueue* q) {
	if (isEmpty(q)) {
		printf("��⿭�� ����ֽ��ϴ�. �۾��� �����ϴ�.\n");
		PrintJob emptyJob = { "", 0 };
		return emptyJob;
	}
	PrintJob job = q->queue[q->front];
	q->front = (q->front + 1) % SIZE;
	return job;
}

void printQueue(PrintQueue* q) {
	if (isEmpty(q)) {
		printf("��⿭�� ����ֽ��ϴ�.\n");
		return;
	}
	printf("---������� �۾�---\n");
	int i = q->front;
	while (i != q->rear) {
		printf("- %s (%d ������)\n", q->queue[i].documentName, q->queue[i].numPages);
		i = (i + 1) % SIZE;
	}
}

void clearQueue(PrintQueue* q) {
	initQueue(q);
	printf("��⿭�� �ʱ�ȭ �Ǿ����ϴ�.\n");
}

bool cancelJob(PrintQueue* q, char* documentName) {
	if (isEmpty(q)) {
		printf("��⿭�� ����ֽ��ϴ�.\n");
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
		printf("�ش� ���� ����.\n");
		return false;
	}
	for (int i = found; i != q->rear; i = (i + 1) % SIZE) {
		q->queue[i] = q->queue[(i + 1)%SIZE];
	}
	q->rear = (q->rear - 1 + SIZE) % SIZE;
	printf("���� \'%s\'�� ��ҵǾ����ϴ�.\n", documentName);
	return true;
}

int main() {
	PrintQueue q;
	initQueue(&q);
	int menu;
	char documentName[50];
	int numPages;

	printf("������ �޴��� �Է��Ͻÿ�\n");
	while (1) {
		printf("1)�۾��߰�\n2)�۾�ó��\n3)��⿭���\n4)�۾����\n5)��⿭�ʱ�ȭ\n6)����\n�Է� : ");
		scanf("%d", &menu);
		int value = 0;
		switch (menu) {
		case 1:
			printf("���� �̸�: ");
			scanf("%s", documentName);
			printf("������ ��: ");
			scanf("%d", &numPages);
			enqueue(&q, documentName, numPages);
			break;
		case 2:
			PrintJob job = dequeue(&q);
			if (strlen(job.documentName) > 0) {
				printf("�۾� '%s' (%d ������)�� ó�� ���Դϴ�...\n", job.documentName, job.numPages);
			}
			break;
		case 3:
			printQueue(&q);
			break;
		case 4:
			printf("����� ���� �̸� : ");
			scanf("%s", documentName);
			cancelJob(&q, documentName);
			break;
		case 5:
			clearQueue(&q);
			break;
		case 6:
			printf("���α׷��� �����մϴ�.\n");
			return;
		default:
			printf("�߸��� �޴� �Դϴ� �ٽ� �Է��Ͻÿ�.\n");
			break;
		}
	}

}