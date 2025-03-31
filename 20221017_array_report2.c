#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int score[], int size, double average, int option);
void deleteStudent(int* scores, int size, int studentNumber);

int main() {
    int* scores;
    int size = 30;
    int capacity = 30;
    int choice, studentNumber;

    scores = (int*)malloc(capacity * sizeof(int));
    if (!scores) {
        printf("error\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < size; i++) {
        scores[i] = rand() % 101;
    }

    while (1) {
        printf("---�л� ���� ���� ���α׷�---\n");
        printf("1. �л� ���� �߰�\n");
        printf("2. �л� ���� ����\n");
        printf("3. �л� ���� �˻�\n");
        printf("4. �л� ���� ���(�ɼ� : 0,1,2)\n");
        printf("5. ���α׷� ����\n");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            if (capacity - size < 5) {
                capacity += 10;
                int* newScores = realloc(scores, capacity * sizeof(int));
                if (!scores) {
                    printf("error\n");
                    return 1;
                }
                scores = newScores;
            }
            int newScore = rand() % 101;
            scores[size] = newScore;
            size++;
            printf("���ο� �л� �߰� - ��ȣ : %d, ���� :  %d\n", size, newScore);

            break;

        case 2:
            printf("������ �л� ��ȣ�� �Է�(1~ %d) : ", size);
            scanf_s("%d", &studentNumber);
            deleteStudent(scores, size, studentNumber);
            break;

        case 3:
            printf("�˻��� �л� ��ȣ�� �Է�(1~ %d) : ", size);
            scanf_s("%d", &studentNumber);
            int score = getStudentScore(scores, size, studentNumber);
            if (score != -1) printf("%d�� �л� ���� : %d\n", studentNumber - 1, score);
            else printf("�ش� �л��� ���� �л� �Դϴ�.\n");
            break;

        case 4:
            int option;
            scanf_s("%d", &option);
            double average = calculateAverage(scores, size);
            printScore(scores, size, average, option);
            break;

        case 5:
            free(scores);
            printf("���α׷� ����\n");
            return 0;
        default:
            printf("�߸��� �Է�\n");
            break;
        }
    }
    return 0;
}

double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }

    else {
        return -1;
    }
}

void printScore(int score[], int size, double average, int option) {
    if (option == 0) {
        for (int i = 0; i < size; i++) {
            if (score[i] != -1) printf("�л���ȣ : %2d , ���� : %3d\n", i + 1, score[i]);
        }
        return;
    }

    if (option == 1) {
        for (int i = 0; i < 30; i++) {
            if (score[i] >= average) {
                if (score[i] != -1) printf("�л���ȣ : %2d , ���� : %3d\n", i + 1, score[i]);

            }
        }
        return;
    }

    if (option == 2) {
        for (int i = 0; i < 30; i++) {
            if (score[i] < average) {
                if (score[i] != -1) printf("�л���ȣ : %2d , ���� : %3d\n", i + 1, score[i]);
            }
        }
        return;
    }
    printf("�ùٸ� �ɼ��� �ƴմϴ�\n");

}

void deleteStudent(int* scores, int size, int studentNumber) {
    if (studentNumber < 1 || studentNumber>size) {
        printf("�л� ��ȣ ����\n");
    }
    if (scores[studentNumber - 1] == -1)printf("���� �л��Դϴ�\n");
    else {
        scores[studentNumber - 1] = -1;
        printf("%d �л� ���� �Ϸ�\n", studentNumber);
    }
}