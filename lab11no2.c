#include <stdio.h>
#include <stdlib.h>
#define NO_SCORE 5
#define NO_STD 10
typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;
void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);

int main() {
    Student std[NO_STD];
    float avg;
    FILE *fp;
    int i;
    fp = fopen(".\\lab11\\no2\\std10.dat", "wb");
    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }
    for(i = 0; i < NO_STD; i++) {
        printf("\nStudent %d\n", i+1);
        readStudentData(&std[i]);
        fwrite(&std[i], sizeof(Student), 1, fp);
    }
    fclose(fp);
    fp = fopen(".\\lab11\\no2\\std10.dat", "rb");
    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }
    printf("\n\n===== STUDENT REPORT =====\n");
    for(i = 0; i < NO_STD; i++) {
        fread(&std[i], sizeof(Student), 1, fp);
        findTotalScore(&std[i]);
        avg = findAverage(std[i]);
        printf("\nAverage score = %.2f", avg);
        findLessThanTen(std[i]);
        printf("\n-----------------------");
    }
    fclose(fp);
    return 0;
}

void readStudentData(Student *pStd) {
    int i;

    printf("\tName: ");
    scanf("%s", pStd->name);

    printf("\tSurname: ");
    scanf("%s", pStd->surname);

    for(i = 0; i < NO_SCORE; i++) {
        printf("\tScore %d: ", i+1);
        scanf("%d", &pStd->score[i]);
    }
}

void findTotalScore(Student *pStd) {
    int i;

    pStd->total = 0;

    printf("\n%s %s scores:", pStd->name, pStd->surname);

    for(i = 0; i < NO_SCORE; i++) {
        printf("%6d", pStd->score[i]);
        pStd->total += pStd->score[i];
    }
    printf("\nTotal score = %.2f", pStd->total);
}

float findAverage(Student s) {
    return s.total / NO_SCORE;
}

void findLessThanTen(Student s) {
    int i, count = 0;
    printf("\nScore less than 10:");
    for(i = 0; i < NO_SCORE; i++) {
        if(s.score[i] < 10) {
            printf("\n\tTest %d = %d", i+1, s.score[i]);
            count++;
        }
    }
    if(count == 0)
        printf(" None");
}
