#include <stdio.h>
#include "grade_funcs.h"

// ��� ���� ��� �Լ�
double calculate_average(int grades[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return (double)sum / size;
}

// �ְ� �� ���� ���� ã�� �Լ�
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

// �հ�/���հ� �л� ���� ����ϴ� �Լ�
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
    // �л� ���� �迭
    int grades[10] = { 85, 70, 55, 90, 45, 60, 78, 88, 92, 49 };
    int size = 10;

    // ��� ���� ���
    double average = calculate_average(grades, size);
    printf("Average grade: %.1f\n", average);

    // �ְ� ������ ���� ���� ã��
    int min_grade, max_grade;
    find_min_max(grades, size, &min_grade, &max_grade);
    printf("Highest grade: %d\n", max_grade);
    printf("Lowest grade: %d\n", min_grade);

    // ��պ��� ���� ������ ���� ���� ���
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

    // �հݰ� ���հ� �л� �� ��� �� ���
    int pass_count, fail_count;
    count_pass_fail(grades, size, &pass_count, &fail_count);
    printf("\nNumber of students passing: %d\n", pass_count);
    printf("Number of students failing: %d\n", fail_count);

    return 0;
}