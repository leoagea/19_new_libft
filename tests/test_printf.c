/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:00:00 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 22:54:11 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft.h"

// Test printf functions
void test_printf_functions(void) {
    printf("Testing printf functions...\n");
    
    // Create a temporary file for testing
    int fd = open("test_printf_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        printf("\033[0;31m[ERROR]\033[0m Could not create test file\n");
        return;
    }
    
    // Test different format specifiers
    int ret1 = ft_printf(fd, "Test string: %s\n", "hello world");
    int ret2 = ft_printf(fd, "Test char: %c\n", 'A');
    int ret3 = ft_printf(fd, "Test integer: %d\n", 12345);
    int ret4 = ft_printf(fd, "Test unsigned: %u\n", 67890);
    int ret5 = ft_printf(fd, "Test hex lowercase: %x\n", 0xabcdef);
    int ret6 = ft_printf(fd, "Test hex uppercase: %X\n", 0xabcdef);
    int ret7 = ft_printf(fd, "Test pointer: %p\n", &ret1);
    int ret8 = ft_printf(fd, "Test boolean: %b\n", 1);
    int ret9 = ft_printf(fd, "Test percent: %%\n");
    
    // Combined test
    int ret10 = ft_printf(fd, "Combined test: %s %c %d %u %x %X %p %b %%\n", 
                        "string", 'C', -123, 456u, 0xabc, 0xDEF, &ret2, 0);
    
    // Close file and reopen for reading
    close(fd);
    fd = open("test_printf_output.txt", O_RDONLY);
    if (fd < 0) {
        printf("\033[0;31m[ERROR]\033[0m Could not open test file for reading\n");
        return;
    }
    
    // Read and display the contents of the file
    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytes_read > 0 ? bytes_read : 0] = '\0';
    close(fd);
    
    printf("\nft_printf output:\n");
    printf("---------------------------------------\n");
    printf("%s", buffer);
    printf("---------------------------------------\n");
    
    // Check return values
    printf("\nReturn values verification:\n");
    printf("ft_printf(\"Test string: %%s\\n\", \"hello world\") returned %d\n", ret1);
    printf("ft_printf(\"Test char: %%c\\n\", 'A') returned %d\n", ret2);
    printf("ft_printf(\"Test integer: %%d\\n\", 12345) returned %d\n", ret3);
    printf("ft_printf(\"Test unsigned: %%u\\n\", 67890) returned %d\n", ret4);
    printf("ft_printf(\"Test hex lowercase: %%x\\n\", 0xabcdef) returned %d\n", ret5);
    printf("ft_printf(\"Test hex uppercase: %%X\\n\", 0xabcdef) returned %d\n", ret6);
    printf("ft_printf(\"Test pointer: %%p\\n\", &ret1) returned %d\n", ret7);
    printf("ft_printf(\"Test boolean: %%b\\n\", 1) returned %d\n", ret8);
    printf("ft_printf(\"Test percent: %%%%\\n\") returned %d\n", ret9);
    printf("Combined test returned %d\n", ret10);
    
    // Clean up
    unlink("test_printf_output.txt");
    
    printf("\n\033[0;33m[NOTE]\033[0m Visually inspect the output to verify correct formatting\n");
}
