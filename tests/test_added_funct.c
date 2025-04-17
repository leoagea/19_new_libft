/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_added_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:00:00 by lagea             #+#    #+#             */
/*   Updated: 2025/04/17 16:30:46 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft.h"

// Helper function to print test result
void print_test_result(const char *test_name, int success) {
    if (success)
        printf("\033[0;32m[PASS]\033[0m %s\n", test_name);
    else
        printf("\033[0;31m[FAIL]\033[0m %s\n", test_name);
}

// For ft_bubble_sort_arr testing
typedef struct {
    int id;
    char *name;
    float score;
} t_person;

int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_person_by_id(const void *a, const void *b) {
    const t_person *pa = a;
    const t_person *pb = b;
    return pa->id - pb->id;
}

int compare_person_by_score(const void *a, const void *b) {
    const t_person *pa = a;
    const t_person *pb = b;
    if (pa->score < pb->score) return -1;
    if (pa->score > pb->score) return 1;
    return 0;
}

// Test functions
void test_ft_atol(void) {
    printf("Testing ft_atol...\n");
    
    int success = 
        ft_atol("123") == 123L && 
        ft_atol("-456") == -456L && 
        ft_atol("2147483647") == 2147483647L && 
        ft_atol("-2147483648") == -2147483648L;
    
    print_test_result("ft_atol basic cases", success);
    
    // Test overflow behavior (implementation-specific)
    long overflow_res = ft_atol("99999999999999999999");
    printf("ft_atol(\"99999999999999999999\") = %ld (check overflow behavior)\n", overflow_res);
}

void test_ft_atoi_base(void) {
    printf("\nTesting ft_atoi_base...\n");
    
    int success = 
        ft_atoi_base("10", "0123456789") == 10 && 
        ft_atoi_base("1010", "01") == 10 && 
        ft_atoi_base("a", "0123456789abcdef") == 10 && 
        ft_atoi_base("-1010", "01") == -10;
    
    print_test_result("ft_atoi_base different bases", success);
}

void test_ft_putunbr_fd(void) {
    printf("\nTesting ft_putunbr_fd...\n");
    
    int fd = open("test_putunbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        printf("\033[0;31m[ERROR]\033[0m Could not create test file\n");
        return;
    }
    
    ft_putunbr_fd(12345, fd);
    ft_putchar_fd('\n', fd);
    ft_putunbr_fd(0, fd);
    ft_putchar_fd('\n', fd);
    ft_putunbr_fd(UINT_MAX, fd);
    
    close(fd);
    
    fd = open("test_putunbr.txt", O_RDONLY);
    char buffer[32];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytes_read > 0 ? bytes_read : 0] = '\0';
    close(fd);
    
    printf("ft_putunbr_fd output:\n%s\n", buffer);
    unlink("test_putunbr.txt");
    
    // Verify by checking if the output contains expected values
    int success = 
        strstr(buffer, "12345") != NULL && 
        strstr(buffer, "0") != NULL &&
        strstr(buffer, "4294967295") != NULL;  // UINT_MAX
    
    print_test_result("ft_putunbr_fd", success);
}

void test_ft_realloc(void) {
    printf("\nTesting ft_realloc...\n");
    
    // Test Case 1: Realloc NULL pointer (should behave like malloc)
    char *str1 = ft_realloc(NULL, 10);
    if (str1) {
        strcpy(str1, "Test");
        printf("Case 1: ft_realloc(NULL, 10) allocated memory successfully\n");
        
        // Test Case 2: Expand existing memory
        char *str2 = ft_realloc(str1, 20);
        if (str2) {
            int preserved = strcmp(str2, "Test") == 0;
            strcat(str2, " expanded");
            printf("Case 2: Expanded memory, content %s\n", 
                   preserved ? "preserved" : "corrupted");
            
            // Test Case 3: Shrink memory
            char *str3 = ft_realloc(str2, 5);
            if (str3) {
                int truncated = strlen(str3) <= 5;
                printf("Case 3: Shrunk memory to 5 bytes, %s\n",
                       truncated ? "truncated correctly" : "not truncated");
                
                // Test Case 4: Free memory (realloc with size 0)
                char *str4 = ft_realloc(str3, 0);
                printf("Case 4: Freed memory with size 0, result pointer is %s\n",
                       str4 == NULL ? "NULL (correct)" : "not NULL (incorrect)");
            } else {
                printf("\033[0;31m[ERROR]\033[0m Case 3 failed: Could not shrink memory\n");
            }
        } else {
            printf("\033[0;31m[ERROR]\033[0m Case 2 failed: Could not expand memory\n");
            free(str1);
        }
    } else {
        printf("\033[0;31m[ERROR]\033[0m Case 1 failed: Could not allocate initial memory\n");
    }
}

void test_ft_bubble_sort_arr(void) {
    printf("\nTesting ft_bubble_sort_arr...\n");
    
    // Test with integers
    int int_array[] = {5, 2, 9, 1, 7, 3};
    int int_array_size = sizeof(int_array) / sizeof(int);
    
    printf("Original int array: ");
    for (int i = 0; i < int_array_size; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    
    ft_bubble_sort_arr(int_array, int_array_size, sizeof(int), compare_int);
    
    printf("Sorted int array: ");
    for (int i = 0; i < int_array_size; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    
    int int_sort_success = 1;
    for (int i = 1; i < int_array_size; i++) {
        if (int_array[i] < int_array[i-1]) {
            int_sort_success = 0;
            break;
        }
    }
    print_test_result("ft_bubble_sort_arr with integers", int_sort_success);
    
    // Test with structs
    t_person people[] = {
        {3, "Charlie", 85.5},
        {1, "Alice", 92.0},
        {5, "Eve", 78.0},
        {2, "Bob", 89.5},
        {4, "Dave", 95.5}
    };
    int people_size = sizeof(people) / sizeof(t_person);
    
    printf("\nOriginal people array:\n");
    for (int i = 0; i < people_size; i++) {
        printf("ID: %d, Name: %s, Score: %.1f\n", 
               people[i].id, people[i].name, people[i].score);
    }
    
    // Sort by ID
    ft_bubble_sort_arr(people, people_size, sizeof(t_person), compare_person_by_id);
    
    printf("\nSorted people array by ID:\n");
    for (int i = 0; i < people_size; i++) {
        printf("ID: %d, Name: %s, Score: %.1f\n", 
               people[i].id, people[i].name, people[i].score);
    }
    
    int id_sort_success = 1;
    for (int i = 1; i < people_size; i++) {
        if (people[i].id < people[i-1].id) {
            id_sort_success = 0;
            break;
        }
    }
    print_test_result("ft_bubble_sort_arr with structs by ID", id_sort_success);
    
    // Sort by score
    ft_bubble_sort_arr(people, people_size, sizeof(t_person), compare_person_by_score);
    
    printf("\nSorted people array by score:\n");
    for (int i = 0; i < people_size; i++) {
        printf("ID: %d, Name: %s, Score: %.1f\n", 
               people[i].id, people[i].name, people[i].score);
    }
    
    int score_sort_success = 1;
    for (int i = 1; i < people_size; i++) {
        if (people[i].score < people[i-1].score) {
            score_sort_success = 0;
            break;
        }
    }
    print_test_result("ft_bubble_sort_arr with structs by score", score_sort_success);
}

void test_ft_join_path(void) {
    printf("\nTesting ft_join_path...\n");
    
    int score_join_success = 1;
    char *path1 = "/usr/local/bin";
    char *path2 = "my_program";
    
    char *result = ft_join_path(path1, path2);
    if (result) {
        printf("Joined path: %s\n", result);
        free(result);
    } else {
        printf("\033[0;31m[ERROR]\033[0m Failed to join paths\n");
        score_join_success = 0;
    }

    // Test with NULL path
    char *result2 = ft_join_path(NULL, path2);
    if (result2) {
        printf("Joined path with NULL: %s\n", result2);
        free(result2);
    } else {
        score_join_success = 0;
        printf("\033[0;31m[ERROR]\033[0m Failed to join NULL path\n");
    }

    print_test_result("ft_join_path", score_join_success);
}

// Main function for testing added functions
void test_added_functions(void) {
    test_ft_atol();
    test_ft_atoi_base();
    test_ft_putunbr_fd();
    test_ft_realloc();
    test_ft_bubble_sort_arr();
    test_ft_join_path();
}
