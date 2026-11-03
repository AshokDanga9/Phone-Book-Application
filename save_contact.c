#include "phonebook.h"

void save_contacts(sll *head)
{
    FILE *fp;
    sll *temp;
    int i;

    fp=fopen("phonebook.txt","w");

    if(fp==NULL)
    {
        printf("File opening failed\n");
        return;
    }

    temp=head;

    while(temp!=NULL)
    {
        fprintf(fp,"%s\n",temp->name);

        fprintf(fp,"%d\n",temp->mob_count);

        for(i=0;i<temp->mob_count;i++)
        {
            fprintf(fp,"%lld\n",temp->mobno[i]);
        }

        fprintf(fp,"%s\n",temp->email);
        fprintf(fp,"%s\n",temp->address);

        temp=temp->next;
    }

    fclose(fp);

    printf("Contacts saved successfully\n");
}
