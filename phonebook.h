#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Phonebook
{
    char name[10];
    long long mobno[10];
    int mob_count;
    char address[1000];
    char email[1000];

    struct Phonebook *next;

} sll;


// Function declarations

sll *create_new_contact(sll *head);

void print_contacts(sll *head);

sll *delete_by_search(sll *head);

void find_contact(sll *head);

sll *edit_contact(sll *head);

void save_contacts(sll *head);

sll *syncfile(sll *head);

#endif
