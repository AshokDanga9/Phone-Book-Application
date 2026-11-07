#include "phonebook.h"
#include <strings.h>


sll *create_new_contact(sll *head)
{
    sll *new_node, *temp;
    char choice;
    int i;

    new_node = malloc(sizeof(sll));

    if(new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    // Enter name

    while(getchar() != '\n');

    printf("Enter Name:\n");
    fgets(new_node->name, sizeof(new_node->name), stdin);

    i = strlen(new_node->name);

    if(i > 0 && new_node->name[i - 1] == '\n')
        new_node->name[i - 1] = '\0';

    // Check duplicate contact

    temp = head;

    while(temp != NULL)
    {
        if(strcasecmp(temp->name, new_node->name) == 0)
        {
            printf("Contact already exists\n");
            free(new_node);
            return head;
        }

        temp = temp->next;
    }

    // Enter mobile number

    new_node->mob_count = 0;

    printf("Enter Mobile Number:\n");
    scanf("%lld", &new_node->mobno[new_node->mob_count]);

    new_node->mob_count++;

    // Add another mobile number

    while(1)
    {
        printf("Do you want to add another number to the same name (Y/N)?\n");
        scanf(" %c", &choice);

        if(choice == 'Y' || choice == 'y')
        {
            if(new_node->mob_count < 10)
            {
                printf("Enter Mobile Number:\n");
                scanf("%lld", &new_node->mobno[new_node->mob_count]);

                new_node->mob_count++;
            }
            else
            {
                printf("Maximum numbers reached\n");
                break;
            }
        }
        else
        {
            break;
        }
    }

    // Add email

    printf("Do you want to add email (Y/N)?\n");
    scanf(" %c", &choice);

    if(choice == 'Y' || choice == 'y')
    {
        getchar();

        printf("Enter Email:\n");
        fgets(new_node->email, sizeof(new_node->email), stdin);

        i = strlen(new_node->email);

        if(i > 0 && new_node->email[i - 1] == '\n')
            new_node->email[i - 1] = '\0';
    }
    else
    {
        new_node->email[0] = '\0';
    }

    // Add address

    printf("Do you want to add address (Y/N)?\n");
    scanf(" %c", &choice);

    if(choice == 'Y' || choice == 'y')
    {
        getchar();

        printf("Enter Address:\n");
        fgets(new_node->address, sizeof(new_node->address), stdin);

        i = strlen(new_node->address);

        if(i > 0 && new_node->address[i - 1] == '\n')
            new_node->address[i - 1] = '\0';
    }
    else
    {
        new_node->address[0] = '\0';
    }

    new_node->next = NULL;

    // Insert at last

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }

    printf("Contact created successfully\n");

    return head;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         1,1           All
