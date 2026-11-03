#include "phonebook.h"

void print_contacts(sll *head)
{
    sll *temp;

    if(head==NULL)
    {
        printf("Contact list is empty\n");
        return;
    }

    temp=head;

    while(temp!=NULL)
    {
        printf("\nName: %s\n",temp->name);

        for(int i=0;i<temp->mob_count;i++)
        {
            printf("Mobile Number %d: %lld\n",i+1,temp->mobno[i]);
        }

        printf("Email: %s\n",temp->email);
        printf("Address: %s\n",temp->address);

        temp=temp->next;
    }
}
