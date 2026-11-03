#include "phonebook.h"

int main()
{
    sll *head=NULL;
    char choice;

    head=syncfile(head);

    while(1)
    {
        printf("\n");
        printf("---------- PHONE BOOK MENU ----------\n");
        printf("C/c : Create New Contact\n");
        printf("P/p : Print All Contacts\n");
        printf("D/d : Delete Contact\n");
        printf("F/f : Find Contact\n");
        printf("E/e : Edit Contact\n");
        printf("S/s : Save Contacts\n");
        printf("Q/q : Quit\n");

        printf("Enter your choice:\n");
        scanf(" %c",&choice);

        switch(choice)
        {
            case 'C':
            case 'c':
                head=create_new_contact(head);
                break;

            case 'P':
            case 'p':
                print_contacts(head);
                break;

            case 'D':
            case 'd':
                head=delete_by_search(head);
                break;

            case 'F':
            case 'f':
                find_contact(head);
                break;

            case 'E':
            case 'e':
                head=edit_contact(head);
                break;

            case 'S':
            case 's':
                save_contacts(head);
                break;

            case 'Q':
            case 'q':
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
