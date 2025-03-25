/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:20:55 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 00:16:22 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void ft_bubble_sort_arr(void *array, int n, size_t size, int (*cmp)(const void *, const void *))
{
    char *arr = (char *)array;
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            
            void *a = arr + j * size;
            void *b = arr + (j + 1) * size;
            
            if (cmp(a, b) > 0) {
                char tmp[size];
                ft_memcpy(tmp, a, size);
                ft_memcpy(a, b, size);
                ft_memcpy(b, tmp, size);
            }
        }
    }
}

/*/////////////////////////////////////////////////////////////////////////////
//          						TEST
                                
int cmp_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int cmp_char(const void *a, const void *b) {
    return (*(unsigned char *)a - *(unsigned char *)b);
}

typedef struct {
    int id;
    float score;
} Student;

int cmp_student_by_score(const void *a, const void *b) {
    const Student *sa = a;
    const Student *sb = b;
    if (sa->score < sb->score) return -1;
    if (sa->score > sb->score) return 1;
    return 0;
}

void print_int_array(int *arr, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void print_char_array(char *arr, int n) {
    for (int i = 0; i < n; ++i)
        printf("'%c' ", arr[i]);
    printf("\n");
}

void print_student_array(Student *arr, int n) {
    for (int i = 0; i < n; ++i)
        printf("ID: %d, Score: %.2f\n", arr[i].id, arr[i].score);
    printf("\n");
}


int main() {
    // === INT ===
    int int_arr[] = {5, 3, 8, 1, 4};
    int int_n = sizeof(int_arr) / sizeof(int);

    printf("Original int array:\n");
    print_int_array(int_arr, int_n);

    bubble_sort_arr(int_arr, int_n, sizeof(int), cmp_int);

    printf("Sorted int array:\n");
    print_int_array(int_arr, int_n);
    printf("\n");

    // === CHAR ===
    char char_arr[] = {'z', 'b', 'k', 'a', 'm'};
    int char_n = sizeof(char_arr) / sizeof(char);

    printf("Original char array:\n");
    print_char_array(char_arr, char_n);

    bubble_sort_arr(char_arr, char_n, sizeof(char), cmp_char);

    printf("Sorted char array:\n");
    print_char_array(char_arr, char_n);
    printf("\n");

    // === STRUCT (Student) ===
    Student students[] = {
        {1, 92.5},
        {2, 85.0},
        {3, 99.9},
        {4, 70.5},
        {5, 88.8}
    };
    int student_n = sizeof(students) / sizeof(Student);

    printf("Original student array:\n");
    print_student_array(students, student_n);

    bubble_sort_arr(students, student_n, sizeof(Student), cmp_student_by_score);

    printf("Sorted student array (by score):\n");
    print_student_array(students, student_n);

    return 0;
}
*/