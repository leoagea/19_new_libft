/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_original.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:00:00 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 23:09:15 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../libft.h"

// Helper function to print test result
void print_result(const char *test_name, int success) {
    if (success)
        printf("\033[0;32m[PASS]\033[0m %s\n", test_name);
    else
        printf("\033[0;31m[FAIL]\033[0m %s\n", test_name);
}

// Test functions
void test_character_functions(void) {
    printf("Testing character functions...\n");
    
    // Test ft_isalpha
    int is_alpha_result = 
        ft_isalpha('a') && ft_isalpha('Z') && 
        !ft_isalpha('1') && !ft_isalpha('!');
    print_result("ft_isalpha", is_alpha_result);
    
    // Test ft_isdigit
    int is_digit_result = 
        ft_isdigit('0') && ft_isdigit('9') && 
        !ft_isdigit('a') && !ft_isdigit('!');
    print_result("ft_isdigit", is_digit_result);
    
    // Test ft_isalnum
    int is_alnum_result = 
        ft_isalnum('a') && ft_isalnum('Z') && 
        ft_isalnum('0') && !ft_isalnum('!');
    print_result("ft_isalnum", is_alnum_result);
    
    // Test ft_isascii
    int is_ascii_result = 
        ft_isascii(0) && ft_isascii(127) && 
        !ft_isascii(128) && !ft_isascii(-1);
    print_result("ft_isascii", is_ascii_result);
    
    // Test ft_isprint
    int is_print_result = 
        ft_isprint(' ') && ft_isprint('~') && 
        !ft_isprint(0) && !ft_isprint(127);
    print_result("ft_isprint", is_print_result);
    
    // Test ft_toupper and ft_tolower
    int toupper_result = 
        ft_toupper('a') == 'A' && ft_toupper('z') == 'Z' && 
        ft_toupper('A') == 'A' && ft_toupper('!') == '!';
    print_result("ft_toupper", toupper_result);
    
    int tolower_result = 
        ft_tolower('A') == 'a' && ft_tolower('Z') == 'z' && 
        ft_tolower('a') == 'a' && ft_tolower('!') == '!';
    print_result("ft_tolower", tolower_result);
}

void test_string_functions(void) {
    printf("\nTesting string functions...\n");
    
    // Test ft_strlen
    int strlen_result = 
        ft_strlen("hello") == 5 && ft_strlen("") == 0 && 
        ft_strlen("hello world") == 11;
    print_result("ft_strlen", strlen_result);
    
    // Test ft_strchr and ft_strrchr
    char test_str[] = "hello world";
    int strchr_result = 
        ft_strchr(test_str, 'l') == &test_str[2] && 
        ft_strchr(test_str, 'z') == NULL;
    print_result("ft_strchr", strchr_result);
    
    int strrchr_result = 
        ft_strrchr(test_str, 'l') == &test_str[9] && 
        ft_strrchr(test_str, 'z') == NULL;
    print_result("ft_strrchr", strrchr_result);
    
    // Test ft_strncmp
    int strncmp_result = 
        ft_strncmp("hello", "hello", 5) == 0 && 
        ft_strncmp("hello", "hellx", 5) < 0 && 
        ft_strncmp("hellx", "hello", 5) > 0 &&
        ft_strncmp("hello", "hellx", 4) == 0;
    print_result("ft_strncmp", strncmp_result);
    
    // Test ft_strlcpy and ft_strlcat
    char dst1[10] = "";
    int strlcpy_result = ft_strlcpy(dst1, "hello", sizeof(dst1)) == 5 && strcmp(dst1, "hello") == 0;
    print_result("ft_strlcpy", strlcpy_result);
    
    char dst2[10] = "hello";
    int strlcat_result = ft_strlcat(dst2, " world", sizeof(dst2)) == 11 && strcmp(dst2, "hello wor") == 0;
    print_result("ft_strlcat", strlcat_result);
}

void test_memory_functions(void) {
    printf("\nTesting memory functions...\n");
    
    // Test ft_memset
    char mem1[10];
    ft_memset(mem1, 'A', 10);
    int memset_result = memcmp(mem1, "AAAAAAAAAA", 10) == 0;
    print_result("ft_memset", memset_result);
    
    // Test ft_bzero
    char mem2[10];
    ft_memset(mem2, 'A', 10);
    ft_bzero(mem2, 5);
    int bzero_result = 
        memcmp(mem2, "\0\0\0\0\0AAAAA", 10) == 0;
    print_result("ft_bzero", bzero_result);
    
    // Test ft_memcpy
    char mem3[10] = {0};
    ft_memcpy(mem3, "hello", 5);
    int memcpy_result = 
        memcmp(mem3, "hello\0\0\0\0\0", 10) == 0;
    print_result("ft_memcpy", memcpy_result);
    
    // Test ft_memmove
    char mem4[10] = "abcdefghi";
    ft_memmove(mem4, mem4 + 2, 5);
    int memmove_result = 
        memcmp(mem4, "cdefgfghi", 10) == 0;
    print_result("ft_memmove", memmove_result);
}

void test_conversion_functions(void) {
    printf("\nTesting conversion functions...\n");
    
    // Test ft_atoi
    int atoi_result = 
        ft_atoi("123") == 123 && 
        ft_atoi("-456") == -456 && 
        ft_atoi(" \t\n\r\f\v+789") == 789 &&
        ft_atoi("  -12a3") == -12;
    print_result("ft_atoi", atoi_result);
    
    // Test ft_itoa
    char *itoa1 = ft_itoa(123);
    char *itoa2 = ft_itoa(-456);
    char *itoa3 = ft_itoa(0);
    int itoa_result = 
        strcmp(itoa1, "123") == 0 && 
        strcmp(itoa2, "-456") == 0 && 
        strcmp(itoa3, "0") == 0;
    print_result("ft_itoa", itoa_result);
    free(itoa1);
    free(itoa2);
    free(itoa3);
}

void test_allocation_functions(void) {
    printf("\nTesting allocation functions...\n");
    
    // Test ft_strdup
    char *dup = ft_strdup("hello");
    int strdup_result = 
        strcmp(dup, "hello") == 0;
    print_result("ft_strdup", strdup_result);
    free(dup);
    
    // Test ft_calloc
    void *calloc_ptr = ft_calloc(5, sizeof(int));
    int calloc_result = calloc_ptr != NULL && memcmp(calloc_ptr, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 5 * sizeof(int)) == 0;
    print_result("ft_calloc", calloc_result);
    free(calloc_ptr);
    
    // Test ft_substr
    char *substr = ft_substr("hello world", 6, 5);
    int substr_result = 
        strcmp(substr, "world") == 0;
    print_result("ft_substr", substr_result);
    free(substr);
    
    // Test ft_strjoin
    char *joined = ft_strjoin("hello", " world");
    int strjoin_result = 
        strcmp(joined, "hello world") == 0;
    print_result("ft_strjoin", strjoin_result);
    free(joined);
    
    // Test ft_strtrim
    char *trimmed = ft_strtrim("  hello world  ", " ");
    int strtrim_result = 
        strcmp(trimmed, "hello world") == 0;
    print_result("ft_strtrim", strtrim_result);
    free(trimmed);
    
    // Test ft_split
    char **split = ft_split("hello,world,test", ',');
    int split_result = 
        split != NULL && 
        strcmp(split[0], "hello") == 0 && 
        strcmp(split[1], "world") == 0 && 
        strcmp(split[2], "test") == 0 && 
        split[3] == NULL;
    print_result("ft_split", split_result);
    for (int i = 0; split[i]; i++) {
        free(split[i]);
    }
    free(split);
}

// Main function for testing original functions
void test_original_functions(void) {
    test_character_functions();
    test_string_functions();
    test_memory_functions();
    test_conversion_functions();
    test_allocation_functions();
}
