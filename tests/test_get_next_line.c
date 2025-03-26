/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:00:00 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 23:08:09 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft.h"

// Test get_next_line function
void test_get_next_line(void) {
    printf("Testing get_next_line...\n");
    
    // Create test file
    int fd = open("test_gnl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        printf("\033[0;31m[ERROR]\033[0m Could not create test file\n");
        return;
    }
    
    // Write test content
    const char *test_content = 
        "First line\n"
        "Second line\n"
        "Third line with no newline at end";
    
    write(fd, test_content, strlen(test_content));
    close(fd);
    
    // Open for reading
    fd = open("test_gnl.txt", O_RDONLY);
    if (fd < 0) {
        printf("\033[0;31m[ERROR]\033[0m Could not open test file for reading\n");
        return;
    }
    
    // Test reading line by line
    printf("\nReading file line by line:\n");
    printf("----------------------------------------\n");
    
    char *line;
    int line_count = 0;
    
    while ((line = get_next_line(fd)) != NULL) {
        line_count++;
        printf("Line %d: %s", line_count, line);
        // If there's no newline at the end, add one for display
        if (line[strlen(line) - 1] != '\n')
            printf("\n");
        free(line);
    }
    
    close(fd);
    printf("----------------------------------------\n");
    
    // Verify expected behavior
    printf("\nTest Results:\n");
    
    if (line_count == 3)
        printf("\033[0;32m[PASS]\033[0m get_next_line read the expected number of lines (3)\n");
    else
        printf("\033[0;31m[FAIL]\033[0m get_next_line read %d lines, expected 3\n", line_count);
    
    // Test with invalid fd
    printf("\nTesting with invalid file descriptor:\n");
    line = get_next_line(-1);
    if (line == NULL)
        printf("\033[0;32m[PASS]\033[0m get_next_line returned NULL for invalid fd\n");
    else {
        printf("\033[0;31m[FAIL]\033[0m get_next_line didn't return NULL for invalid fd\n");
        free(line);
    }
    
    // Clean up
    unlink("test_gnl.txt");
}
