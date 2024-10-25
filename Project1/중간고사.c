#include <stdio.h>
#include "grade_funcs.h"

// 평균 성적 계산 함수
double calculate_average(int grades[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return (double)sum / size;
}

// 최고 및 최저 성적 찾는 함수
void find_min_max(int grades[], int size, int* min, int* max) {
    *min = grades[0];
    *max = grades[0];

    for (int i = 1; i < size; i++) {
        if (grades[i] < *min) {
            *min = grades[i];
        }
        if (grades[i] > *max) {
            *max = grades[i];
        }
    }
}

// 합격/불합격 학생 수를 계산하는 함수
void count_pass_fail(int grades[], int size, int* pass_count, int* fail_count) {
    *pass_count = 0;
    *fail_count = 0;

    for (int i = 0; i < size; i++) {
        if (grades[i] >= 60) {
            (*pass_count)++;
        }
        else {
            (*fail_count)++;
        }
    }
}

int main() {
    // 학생 성적 배열
    int grades[10] = { 85, 70, 55, 90, 45, 60, 78, 88, 92, 49 };
    int size = 10;

    // 평균 성적 계산
    double average = calculate_average(grades, size);
    printf("Average grade: %.1f\n", average);

    // 최고 성적과 최저 성적 찾기
    int min_grade, max_grade;
    find_min_max(grades, size, &min_grade, &max_grade);
    printf("Highest grade: %d\n", max_grade);
    printf("Lowest grade: %d\n", min_grade);

    // 평균보다 높은 성적과 낮은 성적 출력
    printf("\nGrades above average: ");
    for (int i = 0; i < size; i++) {
        if (grades[i] > average) {
            printf("%d ", grades[i]);
        }
    }

    printf("\nGrades below average: ");
    for (int i = 0; i < size; i++) {
        if (grades[i] < average) {
            printf("%d ", grades[i]);
        }
    }
    printf("\n");

    // 합격과 불합격 학생 수 계산 및 출력
    int pass_count, fail_count;
    count_pass_fail(grades, size, &pass_count, &fail_count);
    printf("\nNumber of students passing: %d\n", pass_count);
    printf("Number of students failing: %d\n", fail_count);

    return 0;
}