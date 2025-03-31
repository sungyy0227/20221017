#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int score[], int size, double average, int option);


int main() {
    int scores[30]; 
    int studentNumber;
    double average;
    int option = 0;
    srand(time(0));

    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101; 
    }

    average = calculateAverage(scores, 30);
    printf("�б� ��� ����: %.2f\n", average);

    printf("�л� ��ȣ�� �Է��ϼ��� (1 ~ 30): ");
    scanf_s("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d�� �л��� ����: %d\n", studentNumber, score);
    }
    else {
        printf("��ȿ���� ���� �л� ��ȣ�Դϴ�.\n");
    }
    printf("0 : ��� �л��� ���� ���\n");
    printf("1 : ��� ���� �̻� �л��� ���� ���\n");
    printf("2 : ��� ���� �̸� �л��� ���� ���\n");
    printf("�ɼ��� �Է��Ͻÿ� (0,1,2) : ");
    scanf_s("%d", &option);
    if (option == 0 || option == 1 || option == 2) {
        printScore(scores, 30, average, option);
    }
    else {
        printf("�ùٸ� �ɼ��� �ƴմϴ�");
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
            printf("�л���ȣ : %2d , ���� : %3d\n", i + 1, score[i]);
        }
    }

    if (option == 1) {
        for (int i = 0; i < 30; i++) {
            if (score[i] >= average) {
                printf("�л���ȣ : %2d , ���� : %3d\n", i + 1, score[i]);
            }
        }
    }

    if (option == 2) {
        for (int i = 0; i < 30; i++) {
            if (score[i] < average) {
                printf("�л���ȣ : %2d , ���� : %3d\n", i + 1, score[i]);
            }
        }
    }


}