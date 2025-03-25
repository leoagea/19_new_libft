/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_dll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:48:34 by lagea             #+#    #+#             */
/*   Updated: 2025/03/26 00:07:06 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void dll_bubble_sort(t_node *start, t_node *end, int (*cmp)(void *, void *)) 
{
	if (!start || !end)
	return;
	
    int swapped = 1;
    t_node *ptr;
	
    while (swapped){
		swapped = 0;
        ptr = start;
		
        while (ptr && ptr->next && ptr != end) {
			if (cmp(ptr->content, ptr->next->content) > 0) {
				void *tmp = ptr->content;
                ptr->content = ptr->next->content;
                ptr->next->content = tmp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
		
        end = end->prev;
    }
}

/*/////////////////////////////////////////////////////////////////////////////
								TEST
typedef struct {
	int id;
	float score;
} Student;
// Fonctions de comparaison
int compare_by_id(void *a, void *b) {
	Student *sa = a;
    Student *sb = b;
    return sa->id - sb->id;
}

int compare_by_score(void *a, void *b) {
    Student *sa = a;
    Student *sb = b;
    if (sa->score < sb->score) return -1;
    if (sa->score > sb->score) return 1;
    return 0;
}

// Fonctions utilitaires
void append_node(t_node **head, Student *content) {
    t_node *new = malloc(sizeof(t_node));
    new->content = content;
    new->next = NULL;
    new->prev = NULL;

    if (!*head) {
        *head = new;
        return;
    }

    t_node *last = *head;
    while (last->next)
        last = last->next;

    last->next = new;
    new->prev = last;
}

void print_student_list(t_node *head) {
    while (head) {
        Student *s = head->content;
        printf("ID: %d, Score: %.2f\n", s->id, s->score);
        head = head->next;
    }
    printf("\n");
}

void free_list(t_node *head) {
    while (head) {
        t_node *next = head->next;
        free(head->content);
        free(head);
        head = next;
    }
}

t_node *get_last_node(t_node *head) {
    while (head && head->next)
        head = head->next;
    return head;
}

// Main pour démonstration
int main() {
    t_node *list = NULL;

    Student *s1 = malloc(sizeof(Student)); *s1 = (Student){3, 89.5};
    Student *s2 = malloc(sizeof(Student)); *s2 = (Student){1, 95.0};
    Student *s3 = malloc(sizeof(Student)); *s3 = (Student){4, 72.3};
    Student *s4 = malloc(sizeof(Student)); *s4 = (Student){2, 88.0};

    append_node(&list, s1);
    append_node(&list, s2);
    append_node(&list, s3);
    append_node(&list, s4);

    printf("Original list:\n");
    print_student_list(list);

    t_node *last = get_last_node(list);

    printf("Sorted by ID:\n");
    dll_bubble_sort(list, last, compare_by_id);
    print_student_list(list);

    printf("Sorted by Score:\n");
    dll_bubble_sort(list, last, compare_by_score);
    print_student_list(list);

    free_list(list);

	// === TEST TRI PARTIEL SUR NOEUDS 3 À 9 ===
	printf("Partial sort from node 3 to node 9 (by ID):\n");

	// Création d'une nouvelle liste de 10 étudiants dans le désordre
	t_node *big_list = NULL;
	for (int i = 0; i < 10; ++i) {
		Student *s = malloc(sizeof(Student));
		*s = (Student){.id = rand() % 100, .score = (float)(rand() % 1000) / 10};
		append_node(&big_list, s);
	}

	// Affichage avant
	printf("Before partial sort:\n");
	print_student_list(big_list);

	// Récupération des pointeurs vers les nœuds 3 et 9
	t_node *start = big_list;
	for (int i = 0; i < 2 && start; ++i)
		start = start->next;

	t_node *end = start;
	for (int i = 0; i < 6 && end; ++i)
		end = end->next;

	// Tri partiel
	dll_bubble_sort(start, end, compare_by_id);

	// Affichage après
	printf("After partial sort (nodes 3 to 9 by ID):\n");
	print_student_list(big_list);

	// Libération mémoire
	free_list(big_list);
}
*/
