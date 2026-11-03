#include "phonebook.h"

sll *edit_contact(sll *head)
{
    char name[10];
    char new_name[10];
    int choice,num;
    sll *temp,*ptr;

    if(head==NULL)
    {
        printf("Contact list is empty\n");
        return head;
    }

    printf("Enter name to edit:\n");
    scanf("%9s",name);

    temp=head;

    while(temp!=NULL && strcmp(temp->name,name)!=0)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Contact not found\n");
        return head;
    }

    printf("\n1. Edit Name\n");
    printf("2. Edit Mobile Number\n");
    printf("3. Edit Email\n");
    printf("4. Edit Address\n");
    printf("5. Add New Mobile Number\n");

    printf("Enter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter new name:\n");
            scanf("%9s",new_name);

            ptr=head;

            while(ptr!=NULL)
            {
                if(ptr!=temp && strcmp(ptr->name,new_name)==0)
                {
                    printf("Duplicate contact name\n");
                    return head;
                }

                ptr=ptr->next;
            }

            strcpy(temp->name,new_name);
            printf("Name updated successfully\n");
            break;

        case 2:
            printf("Enter mobile number position:\n");
            scanf("%d",&num);

            if(num<1 || num>temp->mob_count)
            {
                printf("Invalid number position\n");
                break;
            }

            printf("Enter new mobile number:\n");
            scanf("%lld",&temp->mobno[num-1]);

            printf("Mobile number updated successfully\n");
            break;

        case 3:
            printf("Enter new email:\n");
            scanf("%999s",temp->email);

            printf("Email updated successfully\n");
            break;

        case 4:
            printf("Enter new address:\n");
            scanf(" %999[^\n]",temp->address);

            printf("Address updated successfully\n");
            break;
       
        case 5:
            if(temp->mob_count < 10)
           {
            printf("Enter new mobile number:\n");
            scanf("%lld",&temp->mobno[temp->mob_count]);

            temp->mob_count++;

            printf("New mobile number added successfully\n");
           }
            else
           {
            printf("Maximum 10 mobile numbers allowed\n");
           }
            break;

        default:
            printf("Invalid choice\n");
           }

           return head;
}
