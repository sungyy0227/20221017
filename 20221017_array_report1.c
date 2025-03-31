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
    printf("학급 평균 점수: %.2f\n", average);

    printf("학생 번호를 입력하세요 (1 ~ 30): ");
    scanf_s("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d번 학생의 점수: %d\n", studentNumber, score);
    }
    else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }
    printf("0 : 모든 학생의 점수 출력\n");
    printf("1 : 평균 점수 이상 학생의 점수 출력\n");
    printf("2 : 평균 점수 미만 학생의 점수 출력\n");
    printf("옵션을 입력하시오 (0,1,2) : ");
    scanf_s("%d", &option);
    if (option == 0 || option == 1 || option == 2) {
        printScore(scores, 30, average, option);
    }
    else {
        printf("올바른 옵션이 아닙니다");
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
            printf("학생번호 : %2d , 점수 : %3d\n", i + 1, score[i]);
            return;
        }
    }

    if (option == 1) {
        for (int i = 0; i < 30; i++) {
            if (score[i] >= average) {
                printf("학생번호 : %2d , 점수 : %3d\n", i + 1, score[i]);
                return;
            }
        }
    }

    if (option == 2) {
        for (int i = 0; i < 30; i++) {
            if (score[i] < average) {
                printf("학생번호 : %2d , 점수 : %3d\n", i + 1, score[i]);
                return;
            }
        }
    }
    printf("올바른 번호가 아닙니다");
}
