CC = gcc

CFLAGS = -Wall -Wextra

TARGET = phonebook

SRC = main.c create_contact.c print_contact.c delete_contact.c find_contact.c edit_contact.c save_contact.c syncfile.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
