#include "phonebook.h"

sll *delete_by_search(sll *head)
{
    char name[10];
    sll *temp,*prev=NULL;

    if(head==NULL)
    {
        printf("Contact list is empty\n");
        return head;
    }

    printf("Enter name to delete:\n");
    scanf("%9s",name);

    temp=head;

    while(temp!=NULL && strcmp(temp->name,name)!=0)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Contact not found\n");
    }
    else if(temp==head)
    {
        head=head->next;
        free(temp);
        temp=NULL;
        printf("Contact deleted successfully\n");
    }
    else
    {
        prev->next=temp->next;
        free(temp);
        temp=NULL;
        printf("Contact deleted successfully\n");
    }

    return head;
}
