/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_double_linked_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:00:00 by lagea             #+#    #+#             */
/*   Updated: 2025/06/02 18:39:07 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

// Test structure
typedef struct s_student {
    int     id;
    char    *name;
    float   grade;
} t_student;

// Helper functions for student data
t_student *create_student(int id, const char *name, float grade) {
    t_student *student = malloc(sizeof(t_student));
    if (!student)
        return NULL;
    student->id = id;
    student->name = ft_strdup(name);
    student->grade = grade;
    return student;
}

void free_student(void *data) {
    t_student *student = (t_student*)data;
    if (student) {
        free(student->name);
        free(student);
    }
}

void print_student(void *data) {
    t_student *student = (t_student*)data;
    if (student) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", 
               student->id, student->name, student->grade);
    }
}

int compare_students_by_id(void *a, void *b) {
    t_student *student_a = (t_student*)a;
    t_student *student_b = (t_student*)b;
    return student_a->id - student_b->id;
}

int compare_students_by_grade(void *a, void *b) {
    t_student *student_a = (t_student*)a;
    t_student *student_b = (t_student*)b;
    if (student_a->grade < student_b->grade) return -1;
    if (student_a->grade > student_b->grade) return 1;
    return 0;
}

// Tests declaration
void test_dll_init_and_basics(void);
void test_dll_insertions(void);
void test_dll_deletions(void);
void test_dll_revert(void);
void test_dll_print(void);
void test_dll_bubble_sort(void);
void test_dll_free(void);
void test_dll_quick_sort(void);

// Main test function
void test_double_linked_list(void) {
    test_dll_init_and_basics();
    test_dll_insertions();
    test_dll_deletions();
    test_dll_revert();
    test_dll_print();
    test_dll_bubble_sort();
    test_dll_free();
    test_dll_quick_sort();
}

// Test implementation
void test_dll_init_and_basics(void) {
    printf("Testing dll_init and basic operations...\n");
    
    t_dll list;
    dll_init(&list);
    
    if (list.head == NULL && list.tail == NULL)
        printf("\033[0;32m[PASS]\033[0m dll_init correctly initializes empty list\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_init did not initialize list as expected\n");
    
    // Test dll_size on empty list
    if (dll_size(&list) == 0)
        printf("\033[0;32m[PASS]\033[0m dll_size returns 0 for empty list\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_size did not return 0 for empty list\n");
    
    // Test node creation
    t_student *student = create_student(1, "Alice", 95.5);
    t_node *node = dll_new_node(student);
    
    if (node && node->content == student && node->next == NULL && node->prev == NULL)
        printf("\033[0;32m[PASS]\033[0m dll_new_node correctly creates a new node\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_new_node did not create node as expected\n");
    
    free_student(student);
    free(node);
}

void test_dll_insertions(void) {
    printf("\nTesting dll insertion operations...\n");
    
    t_dll list;
    dll_init(&list);
    
    // Test insert head
    t_student *alice = create_student(1, "Alice", 95.5);
    dll_insert_head(alice, &list);
    
    if (list.head && list.head == list.tail && list.head->content == alice)
        printf("\033[0;32m[PASS]\033[0m dll_insert_head works on empty list\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_insert_head failed on empty list\n");
    
    // Test insert tail
    t_student *bob = create_student(2, "Bob", 87.0);
    dll_insert_tail(bob, &list);
    
    if (list.head && list.tail && list.head != list.tail && 
        list.head->next == list.tail && list.tail->prev == list.head &&
        list.tail->content == bob)
        printf("\033[0;32m[PASS]\033[0m dll_insert_tail works on non-empty list\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_insert_tail failed on non-empty list\n");
    
    // Test another insert head
    t_student *carol = create_student(3, "Carol", 92.3);
    dll_insert_head(carol, &list);
    
    if (list.head && list.head->content == carol && 
        list.head->next->content == alice)
        printf("\033[0;32m[PASS]\033[0m dll_insert_head works on non-empty list\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_insert_head failed on non-empty list\n");
    
    // Test size after insertions
    if (dll_size(&list) == 3)
        printf("\033[0;32m[PASS]\033[0m dll_size correctly reports 3 nodes\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_size did not report 3 nodes\n");
    
    // Clean up
    t_node *current = list.head;
    while (current) {
        t_node *temp = current;
        current = current->next;
        free_student(temp->content);
        free(temp);
    }
}

void test_dll_deletions(void) {
    printf("\nTesting dll deletion operations...\n");
    
    t_dll list;
    dll_init(&list);
    
    // Add some nodes
    dll_insert_tail(create_student(1, "Alice", 95.5), &list);
    dll_insert_tail(create_student(2, "Bob", 87.0), &list);
    dll_insert_tail(create_student(3, "Carol", 92.3), &list);
    
    // Test delete head
    void *first_content = list.head->content;
    dll_delete_head(&list);
    
    if (dll_size(&list) == 2 && list.head->content != first_content)
        printf("\033[0;32m[PASS]\033[0m dll_delete_head correctly removes first node\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_delete_head did not work as expected\n");
    
    // Test delete tail
    void *last_content = list.tail->content;
    dll_delete_tail(&list);
    
    if (dll_size(&list) == 1 && list.tail->content != last_content)
        printf("\033[0;32m[PASS]\033[0m dll_delete_tail correctly removes last node\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_delete_tail did not work as expected\n");
    
    // Test delete when single node
    dll_delete_head(&list);
    
    if (dll_size(&list) == 0 && list.head == NULL && list.tail == NULL)
        printf("\033[0;32m[PASS]\033[0m dll_delete_head correctly removes last remaining node\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_delete_head did not handle single node case correctly\n");
    
    // Free any remaining memory (first_content and last_content were already freed by delete operations)
    free_student(first_content);
    free_student(last_content);
}

void test_dll_revert(void) {
    printf("\nTesting dll_revert operation...\n");
    
    t_dll list;
    dll_init(&list);
    
    // Add some nodes
    t_student *alice = create_student(1, "Alice", 95.5);
    t_student *bob = create_student(2, "Bob", 87.0);
    t_student *carol = create_student(3, "Carol", 92.3);
    
    dll_insert_tail(alice, &list);
    dll_insert_tail(bob, &list);
    dll_insert_tail(carol, &list);
    
    // Save pointers for checking later
    void *original_head = list.head->content;
    void *original_tail = list.tail->content;
    
    // Revert the list
    dll_revert(&list);
    
    // Check if head and tail are swapped and links are correct
    if (list.head->content == original_tail && list.tail->content == original_head)
        printf("\033[0;32m[PASS]\033[0m dll_revert correctly reversed head and tail\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_revert did not reverse head and tail correctly\n");
    
    // Check if links are correctly reversed
    t_node *current = list.head;
    void *expected_content[] = {carol, bob, alice};
    int all_correct = 1;
    
    for (int i = 0; i < 3; i++) {
        if (current->content != expected_content[i]) {
            all_correct = 0;
            break;
        }
        current = current->next;
    }
    
    if (all_correct)
        printf("\033[0;32m[PASS]\033[0m dll_revert correctly reversed node order\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_revert did not reverse node order correctly\n");
    
    // Clean up
    current = list.head;
    while (current) {
        t_node *temp = current;
        current = current->next;
        free_student(temp->content);
        free(temp);
    }
}

void test_dll_print(void) {
    printf("\nTesting dll print operations...\n");
    
    t_dll list;
    dll_init(&list);
    
    // Add some nodes
    dll_insert_tail(create_student(1, "Alice", 95.5), &list);
    dll_insert_tail(create_student(2, "Bob", 87.0), &list);
    dll_insert_tail(create_student(3, "Carol", 92.3), &list);
    
    printf("Forward print output:\n");
    dll_print_forward(&list, print_student);
    printf("\nBackward print output:\n");
    dll_print_backward(&list, print_student);
    
    printf("\n\033[0;32m[INFO]\033[0m Visually verify that the print functions work as expected\n");
    
    // Clean up
    t_node *current = list.head;
    while (current) {
        t_node *temp = current;
        current = current->next;
        free_student(temp->content);
        free(temp);
    }
}

void test_dll_bubble_sort(void) {
    printf("\nTesting dll_bubble_sort operation...\n");
    
    t_dll list;
    dll_init(&list);
    
    // Add some nodes in unsorted order
    dll_insert_tail(create_student(5, "Eve", 78.5), &list);
    dll_insert_tail(create_student(3, "Carol", 92.3), &list);
    dll_insert_tail(create_student(1, "Alice", 95.5), &list);
    dll_insert_tail(create_student(4, "Dave", 85.0), &list);
    dll_insert_tail(create_student(2, "Bob", 87.0), &list);
    
    printf("Original list (unsorted):\n");
    dll_print_forward(&list, print_student);
    
    // Sort by student ID
    dll_bubble_sort(list.head, list.tail, compare_students_by_id);
    
    printf("\nList sorted by ID:\n");
    dll_print_forward(&list, print_student);
    
    // Check if sorted correctly by ID
    t_node *current = list.head;
    int prev_id = 0;
    int sorted_by_id = 1;
    
    while (current) {
        t_student *student = (t_student*)current->content;
        if (student->id < prev_id) {
            sorted_by_id = 0;
            break;
        }
        prev_id = student->id;
        current = current->next;
    }
    
    if (sorted_by_id)
        printf("\033[0;32m[PASS]\033[0m dll_bubble_sort correctly sorted by ID\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_bubble_sort did not sort correctly by ID\n");
    
    // Sort by grade
    dll_bubble_sort(list.head, list.tail, compare_students_by_grade);
    
    printf("\nList sorted by grade:\n");
    dll_print_forward(&list, print_student);
    
    // Check if sorted correctly by grade
    current = list.head;
    float prev_grade = 0;
    int sorted_by_grade = 1;
    
    while (current) {
        t_student *student = (t_student*)current->content;
        if (student->grade < prev_grade) {
            sorted_by_grade = 0;
            break;
        }
        prev_grade = student->grade;
        current = current->next;
    }
    
    if (sorted_by_grade)
        printf("\033[0;32m[PASS]\033[0m dll_bubble_sort correctly sorted by grade\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_bubble_sort did not sort correctly by grade\n");
    
    // Clean up
    current = list.head;
    while (current) {
        t_node *temp = current;
        current = current->next;
        free_student(temp->content);
        free(temp);
    }
}

void test_dll_free(void) {
    printf("\nTesting dll_free operation...\n");
    
    t_dll list;
    dll_init(&list);
    
    // Add some nodes
    dll_insert_tail(create_student(1, "Alice", 95.5), &list);
    dll_insert_tail(create_student(2, "Bob", 87.0), &list);
    dll_insert_tail(create_student(3, "Carol", 92.3), &list);
    
    // Free the list with our custom free function
    dll_free(&list, free_student);
    
    if (list.head == NULL && list.tail == NULL)
        printf("\033[0;32m[PASS]\033[0m dll_free correctly freed all nodes and reset list\n");
    else
        printf("\033[0;31m[FAIL]\033[0m dll_free did not reset list pointers\n");
    
    printf("\033[0;33m[NOTE]\033[0m If the program doesn't crash, dll_free likely worked correctly\n");
}

//////////////////////////////////////////////////////////////////
// Test: Quick sort on double linked list
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper comparison function for integers
int int_cmp(void *a, void *b) {
	int ia = *(int *)a;
	int ib = *(int *)b;
	return (ia > ib) - (ia < ib);
}

void debug_print_dll(t_dll *list, const char *test_name) {
    printf("\n=== %s ===\n", test_name);
    printf("List content: ");
    
    t_node *current = list->head;
    // Forward traversal
    printf("Forward:  ");
    while (current) {
        printf("%d -> ", *(int*)current->content);
        current = current->next;
    }
    printf("Size: %zu\n", list->size);
}

// Helper to free the list
void free_list(t_dll *list) {
	t_node *cur = list->head;
	while (cur) {
		t_node *next = cur->next;
		free(cur->content);
		free(cur);
		cur = next;
	}
	list->head = list->tail = NULL;
}

// Helper to insert integer into list
void insert_int_tail(t_dll *list, int value) {
	int *p = malloc(sizeof(int));
	*p = value;
	dll_insert_tail(p, list);
}

// Test: sorting an empty list
int test_empty_list() {
	t_dll list;
	dll_init(&list);
	dll_quick_sort(&list, int_cmp);
	if (list.head == NULL && list.tail == NULL){
	    free_list(&list);
        return 0;
    }
	else{
	    free_list(&list);
        return 1;
    }
}

// Test: sorting a single element list
int test_single_element() {
	t_dll list;
	dll_init(&list);
	insert_int_tail(&list, 42);
	dll_quick_sort(&list, int_cmp);
	if (list.head && list.tail && list.head == list.tail && *(int *)list.head->content == 42){
	    free_list(&list);
        return 0;
    }
	else{
	    free_list(&list);
        return 1;
    }
	free_list(&list);
}

// Test: sorting a list with multiple elements
int test_multiple_elements() {
	t_dll list;
	dll_init(&list);
	int vals[] = {5, 3, 8, 1, 7};
	for (int i = 0; i < 5; i++)
		insert_int_tail(&list, vals[i]);
	// debug_print_dll(&list, "Before sorting multiple elements");
	dll_quick_sort(&list, int_cmp);

	int expected[] = {1, 3, 5, 7, 8};
	t_node *cur = list.head;
	int pass = 1;
	for (int i = 0; i < 5; i++) {
		if (!cur || *(int *)cur->content != expected[i]) {
			pass = 0;
			break;
		}
		cur = cur->next;
	}
	if (pass && cur == NULL)
	{
		// debug_print_dll(&list, "test_multiple_elements");
		// printf("test_multiple_elements: PASS\n");
		// printf("=============\n");
	    free_list(&list);
        return 0;
    }
	else{
	    free_list(&list);
        return 1;
    }
	free_list(&list);
}

// Test: sorting a list with duplicate elements
int test_duplicates() {
	t_dll list;
	dll_init(&list);
	int vals[] = {4, 2, 4, 2, 4};
	for (int i = 0; i < 5; i++)
		insert_int_tail(&list, vals[i]);
	// debug_print_dll(&list, "Before sorting duplicates");
	dll_quick_sort(&list, int_cmp);

	int expected[] = {2, 2, 4, 4, 4};
	t_node *cur = list.head;
	int pass = 1;
	for (int i = 0; i < 5; i++) {
		if (!cur || *(int *)cur->content != expected[i]) {
			pass = 0;
			break;
		}
		cur = cur->next;
	}
	if (pass && cur == NULL)
	{
		// debug_print_dll(&list, "test_duplicates");
		// printf("test_duplicates: PASS\n");
		// printf("=============\n");
	    free_list(&list);
        return 0;
	}
	else{
	    free_list(&list);
        return 1;
    }
	free_list(&list);
}

// Test: already sorted list
int test_sorted() {
	t_dll list;
	dll_init(&list);
	int vals[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		insert_int_tail(&list, vals[i]);
	dll_quick_sort(&list, int_cmp);

	int expected[] = {1, 2, 3, 4, 5};
	t_node *cur = list.head;
	int pass = 1;
	for (int i = 0; i < 5; i++) {
		if (!cur || *(int *)cur->content != expected[i]) {
			pass = 0;
			break;
		}
		cur = cur->next;
	}
	if (pass && cur == NULL){
        free_list(&list);
		return 0;
    }
	else{
        
        free_list(&list);
        return 1;
    }
}

// Test: reverse sorted list
int test_reverse_sorted() {
	t_dll list;
	dll_init(&list);
	int vals[] = {5, 4, 3, 2, 1};
	for (int i = 0; i < 5; i++)
		insert_int_tail(&list, vals[i]);
	// debug_print_dll(&list, "Before sorting reverse sorted");
	dll_quick_sort(&list, int_cmp);

	int expected[] = {1, 2, 3, 4, 5};
	t_node *cur = list.head;
	int pass = 1;
	for (int i = 0; i < 5; i++) {
		if (!cur || *(int *)cur->content != expected[i]) {
			pass = 0;
			break;
		}
		cur = cur->next;
	}
	if (pass && cur == NULL){
		// debug_print_dll(&list, "test_reverse_sorted");
		// printf("=============\n");
	    free_list(&list);
		return 0;
	}
	else{
	    free_list(&list);
		return 1;
    }
}

void test_dll_quick_sort(void) {
    printf("\nTesting dll_quick_sort operation...\n");
    const int expected_results[] = {
        test_empty_list(),
        test_single_element(),
        test_multiple_elements(),
        test_duplicates(),
        test_sorted(),
        test_reverse_sorted()
    };
    int all_passed = 1;
    for (size_t i = 0; i < sizeof(expected_results) / sizeof(expected_results[0]); i++) {
        if (expected_results[i] != 0) {
            all_passed = 0;
            printf("\033[0;31m[FAIL]\033[0m Test %ld failed\n", i + 1);
        } else {
            printf("\033[0;32m[PASS]\033[0m Test %ld passed\n", i + 1);
        }
    }
    if (all_passed) {
        printf("\033[0;32mAll tests passed!\033[0m\n");
    } else {
        printf("\033[0;31mSome tests failed.\033[0m\n");
    }
}