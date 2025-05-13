#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Node {
	int data;
	struct Node* next;
	char name[15];
	char telnum[15];
}Node;

Node* insertFirst(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}
	newNode->next = head;
	return newNode;
}

Node* insertTelNum(Node* head, char *name,char *telnum) {
    Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	strcpy(newNode->telnum, telnum);
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;

	return head;
}

Node* insertLast(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;

	return head;
}

void insertAfterValue(Node* head, int targetValue, int newData) {
	Node* current = head;

	while (current != NULL) {
		if (current->data == targetValue) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = newData;
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		current = current->next;
	}
	printf("�� %d�� ���� ��带 ã�� �� �����ϴ�. �������� �ʽ��ϴ�.\n", targetValue);
}

Node* deleteHead(Node* head) {
	if (head == NULL) {
		printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
		return NULL;
	}

	Node* temp = head;
	head = head->next;
	free(temp);

	return head;
}

Node* deleteLast(Node* head) {
	if (head == NULL) {
		printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
		return NULL;
	}

	if (head->next == NULL) {
		free(head);
		return NULL;
	}

	Node* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	free(current->next);
	current->next = NULL;
	return head;
}

Node* deleteNode(Node* head, int targetValue) {
	if (head == NULL) {
		printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
		return NULL;
	}
	if (head->data == targetValue) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	Node* current = head;
	while (current->next != NULL && current->next->data != targetValue) {
		current = current->next;
	}
	if (current->next == NULL) {
		printf("�� %d�� ���� ��带 ã�� �� �����ϴ�.\n", targetValue);
		return head;
	}

	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);

	return head;
}

void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
	return;
}

void printTelList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("�̸� : %s,��ȭ��ȣ : %s -> \n", current->name,current->telnum);
		current = current->next;
	}
	printf("NULL\n");
	return;
}

int searchValue1(Node* head, int value) {
	int pos = 1;
	Node* current = head;
	while (current != NULL) {
		if (current->data == value) {
			return pos;
		}
		current = current->next;
		pos++;
	}
	return -1;
}

void searchValue2(Node* head, int value) {
	Node* current = head;
	while (current != NULL && current->next != NULL && current->next->next != NULL) {
		if (current->next->data == value) {
			printf("�� %d�� ��,�� ��尪�� : %d %d\n", value, current->data, current->next->next->data);
			return;
		}
		current = current->next;
	}
	printf("�� %d�� ��尡 �������� �ʰų� ��,�� ��忡 ���� �����ϴ�.\n", value);
}

void searchTelNum(Node* head, char* name) {
	Node* current = head;

	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			printf("�˻��� %s�� ����ó�� %s\n", name, current->telnum);
		}
		current = current->next;
	}
}

Node* deleteTelNum(Node* head, char* delname) {
	if (head == NULL) {
		printf("����Ʈ�� ��� �ֽ��ϴ�. ������ ��尡 �����ϴ�.\n");
		return NULL;
	}
	if (strcmp(head->name,delname)==0) {
		Node* temp = head;
		head = head->next;
		free(temp);
		printf("�̸� %s�� ��ȭ��ȣ�� �����߽��ϴ�.\n", delname);
		return head;
	}	
	Node* current = head;
	while (current->next != NULL && strcmp(current->next->name, delname) != 0) {
		current = current->next;
	}
	if (current->next == NULL) {
		printf("�̸� %s�� ���� ��ȭ��ȣ�� ã�� �� �����ϴ�.\n",delname);
		return head;
	}

	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);

	return head;
}

void freelist(Node* head) {
	Node* current = head;
	Node* temp;

	while (current != NULL) {
		temp = current;
		current = current->next;
		free(temp);
	}
}

//int main() {
//	Node* head = NULL;
//	int pos = -1;
//	int val = 30;
//
//	head = insertFirst(head, 30);
//	head = insertFirst(head, 20);
//	head = insertFirst(head, 10);
//	head = insertLast(head, 70);
//	head = insertLast(head, 80);
//	head = insertLast(head, 90);
//	insertAfterValue(head, 30, 40);
//	insertAfterValue(head, 40, 50);
//	insertAfterValue(head, 50, 60);
//
//	head = deleteHead(head);
//	head = deleteLast(head);
//	head = deleteNode(head, 40);
//	head = deleteNode(head, 70);
//	head = deleteNode(head, 100);
//
//	printList(head);
//	pos = searchValue1(head, val);
//	printf("�� %d�� ��ġ�� %d��°\n", val, pos);
//	searchValue2(head, 50);
//	searchValue2(head, 80);
//	freelist(head);
//
//}

int main() {
	Node* head = NULL;
	char name[15];
	char telnum[15];
	int menu;

	while (1) {
		printf("1)����ó�߰�\n2)����ó�˻�\n3)����ó����\n4)��ȭ��ȣ�����\n5)���α׷�����\n�Է� : ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("�߰��� ����ó�� �̸��� �Է��Ͻÿ� : ");
			scanf("%s", name);
			printf("��ȭ��ȣ�� �Է��Ͻÿ� : ( ex)ooo-oooo-oooo ) : ");
			scanf("%s", telnum);
			head = insertTelNum(head, name, telnum);
			break;
		case 2:
			printf("�˻��� ����ó�� �̸��� �Է��Ͻÿ� : ");
			scanf("%s", name);
			searchTelNum(head, name);
			break;
		case 3:
			printf("������ ����ó�� �̸��� �Է��Ͻÿ� : ");
			scanf("%s", name);
			head = deleteTelNum(head, name);
			break;
		case 4:
			printTelList(head);
			break;
		case 5:
			printf("���α׷��� �����մϴ�.\n");
			return;
		default:
			printf("�ٽ� �Է��Ͻÿ�.\n");
			break;
		}
	}

}