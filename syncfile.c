#include "phonebook.h"

sll *syncfile(sll *head)
{
    FILE *fp;
    sll *new_node,*temp;
    char buffer[1000];
    int i;

    fp=fopen("phonebook.txt","r");

    if(fp==NULL)
    {
        printf("File not found\n");
        return head;
    }

    while(fgets(buffer,sizeof(buffer),fp)!=NULL)
    {
        new_node=malloc(sizeof(sll));

        if(new_node==NULL)
        {
            printf("Memory allocation failed\n");
            break;
        }

        buffer[strcspn(buffer,"\n")]='\0';
        strcpy(new_node->name,buffer);

        if(fgets(buffer,sizeof(buffer),fp)==NULL)
        {
            free(new_node);
            new_node=NULL;
            break;
        }

        new_node->mob_count=atoi(buffer);

        if(new_node->mob_count<0 || new_node->mob_count>10)
        {
            free(new_node);
            new_node=NULL;
            break;
        }

        for(i=0;i<new_node->mob_count;i++)
        {
            if(fgets(buffer,sizeof(buffer),fp)==NULL)
                break;

            new_node->mobno[i]=atoll(buffer);
        }

        if(i!=new_node->mob_count)
        {
            free(new_node);
            new_node=NULL;
            break;
        }

        if(fgets(buffer,sizeof(buffer),fp)==NULL)
        {
            free(new_node);
            new_node=NULL;
            break;
        }

        buffer[strcspn(buffer,"\n")]='\0';
        strcpy(new_node->email,buffer);

        if(fgets(buffer,sizeof(buffer),fp)==NULL)
        {
            free(new_node);
            new_node=NULL;
            break;
        }

        buffer[strcspn(buffer,"\n")]='\0';
        strcpy(new_node->address,buffer);

        new_node->next=NULL;

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
    }

    fclose(fp);

    return head;
}
