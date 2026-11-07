phonebook : main.o create_contact.o print_contact.o delete_contact.o find_contact.o edit_contact.o save_contact.o syncfile.o
	cc main.o create_contact.o print_contact.o delete_contact.o find_contact.o edit_contact.o save_contact.o syncfile.o -o phonebook

main.o : main.c
	cc -c main.c

create_contact.o : create_contact.c
	cc -c create_contact.c

print_contact.o : print_contact.c
	cc -c print_contact.c

delete_contact.o : delete_contact.c
	cc -c delete_contact.c

find_contact.o : find_contact.c
	cc -c find_contact.c

edit_contact.o : edit_contact.c
	cc -c edit_contact.c

save_contact.o : save_contact.c
	cc -c save_contact.c

syncfile.o : syncfile.c
	cc -c syncfile.c
