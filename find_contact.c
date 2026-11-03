#include "phonebook.h"

void find_contact(sll *head)
{
    char name[10];
    sll *temp;

    if(head==NULL)
    {
        printf("Contact list is empty\n");
        return;
    }

    printf("Enter name to search:\n");
    scanf("%9s",name);

    temp=head;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            printf("\nContact Found\n");

            printf("Name: %s\n",temp->name);

            for(int i=0;i<temp->mob_count;i++)
            {
                printf("Mobile Number %d: %lld\n",i+1,temp->mobno[i]);
            }

            printf("Email: %s\n",temp->email);
            printf("Address: %s\n",temp->address);

            return;
        }

        temp=temp->next;
    }

    printf("Contact Not Found\n");
}
