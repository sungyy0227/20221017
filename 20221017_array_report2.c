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
        printf("---학생 성적 관리 프로그램---\n");
        printf("1. 학생 정보 추가\n");
        printf("2. 학생 정보 삭제\n");
        printf("3. 학생 정보 검색\n");
        printf("4. 학생 정보 출력(옵션 : 0,1,2)\n");
        printf("5. 프로그램 종료\n");
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
            printf("새로운 학생 추가 - 번호 : %d, 점수 :  %d\n", size, newScore);

            break;

        case 2:
            printf("삭제할 학생 번호를 입력(1~ %d) : ", size);
            scanf_s("%d", &studentNumber);
            deleteStudent(scores, size, studentNumber);
            break;

        case 3:
            printf("검색할 학생 번호를 입력(1~ %d) : ", size);
            scanf_s("%d", &studentNumber);
            int score = getStudentScore(scores, size, studentNumber);
            if (score != -1) printf("%d번 학생 점수 : %d\n", studentNumber - 1, score);
            else printf("해당 학생은 없는 학생 입니다.\n");
            break;

        case 4:
            int option;
            scanf_s("%d", &option);
            double average = calculateAverage(scores, size);
            printScore(scores, size, average, option);
            break;

        case 5:
            free(scores);
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 입력\n");
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
            if (score[i] != -1) printf("학생번호 : %2d , 점수 : %3d\n", i + 1, score[i]);
        }
    }

    if (option == 1) {
        for (int i = 0; i < 30; i++) {
            if (score[i] >= average) {
                if (score[i] != -1) printf("학생번호 : %2d , 점수 : %3d\n", i + 1, score[i]);

            }
        }
    }

    if (option == 2) {
        for (int i = 0; i < 30; i++) {
            if (score[i] < average) {
                if (score[i] != -1) printf("학생번호 : %2d , 점수 : %3d\n", i + 1, score[i]);
            }
        }
    }


}

void deleteStudent(int* scores, int size, int studentNumber) {
    if (studentNumber < 1 || studentNumber>size) {
        printf("학생 번호 오류\n");
    }
    if (scores[studentNumber - 1] == -1)printf("없는 학생입니다\n");
    else {
        scores[studentNumber - 1] = -1;
        printf("%d 학생 삭제 완료\n", studentNumber);
    }
}
