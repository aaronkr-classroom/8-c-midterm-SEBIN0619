#ifndef GRADE_FUNCS_H
#define GRADE_FUNCS_H

// 함수 선언
double calculate_average(int grades[], int size);
void find_min_max(int grades[], int size, int* min, int* max);
void count_pass_fail(int grades[], int size, int* pass_count, int* fail_count);

#endif // GRADE_FUNCS_H