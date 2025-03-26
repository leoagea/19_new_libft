/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:00:00 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 23:03:31 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

// Forward declarations for test functions
void test_original_functions(void);
void test_double_linked_list(void);
void test_printf_functions(void);
void test_added_functions(void);
void test_get_next_line(void);

// Print colorful section headers
void print_section_header(const char *section_name) {
    printf("\n\033[1;34m========== TESTING %s ==========\033[0m\n\n", section_name);
}

int main(void) {
    printf("\033[1;33m================================\033[0m\n");
    printf("\033[1;33m==    LIBFT TESTING SUITE     ==\033[0m\n");
    printf("\033[1;33m================================\033[0m\n\n");

    print_section_header("ORIGINAL FUNCTIONS");
    test_original_functions();

    print_section_header("DOUBLE LINKED LIST");
    test_double_linked_list();
    
    print_section_header("PRINTF FUNCTIONS");
    test_printf_functions();
    
    print_section_header("ADDED FUNCTIONS");
    test_added_functions();
    
    print_section_header("GET NEXT LINE");
    test_get_next_line();

    printf("\n\033[1;33m================================\033[0m\n");
    printf("\033[1;33m==     TESTING COMPLETED      ==\033[0m\n");
    printf("\033[1;33m================================\033[0m\n");

    return 0;
}
