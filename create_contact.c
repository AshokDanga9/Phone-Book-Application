#include "phonebook.h"

sll *create_new_contact(sll *head)
{
    sll *new_node,*temp;
    char choice;

    new_node=malloc(sizeof(sll));

    if(new_node==NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Enter Name:\n");
    scanf("%9s",new_node->name);

    // Check duplicate contact

    temp=head;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,new_node->name)==0)
        {
            printf("Contact already exists\n");
            free(new_node);
            new_node=NULL;
            return head;
        }

        temp=temp->next;
    }

    // First mobile number

    new_node->mob_count=0;

    printf("Enter Mobile Number 1:\n");
    scanf("%lld",&new_node->mobno[new_node->mob_count]);

    new_node->mob_count++;

    // Add another mobile number

    while(1)
    {
        printf("Do you want to add another number to the same name (Y/N)?\n");
        scanf(" %c",&choice);

        if(choice=='Y' || choice=='y')
        {
            if(new_node->mob_count<10)
            {
                printf("Enter Mobile Number %d:\n",new_node->mob_count+1);

                scanf("%lld",&new_node->mobno[new_node->mob_count]);

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
    scanf(" %c",&choice);

    if(choice=='Y' || choice=='y')
    {
        printf("Enter Email:\n");
        scanf("%999s",new_node->email);
    }
    else
    {
        new_node->email[0]='\0';
    }

    // Add address

    printf("Do you want to add address (Y/N)?\n");
    scanf(" %c",&choice);

    if(choice=='Y' || choice=='y')
    {
        printf("Enter Address:\n");
        scanf(" %999[^\n]",new_node->address);
    }
    else
    {
        new_node->address[0]='\0';
    }

    new_node->next=NULL;

    // Insert at last

    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=new_node;
    }

    printf("Contact created successfully\n");

    return head;
}
