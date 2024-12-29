/*
NAME : N VENKATA PRASAD
DATE : 28/09/24
DESCRIPTION : Main.C - It consists of all Main functions and function calls
*/
#include <stdio.h>
#include<stdlib.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\033[0;36mAddress Book Menu:\033[0m\n");
        printf("\033[1;35m1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\033[0m\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
		int sortChoice;
                printf("List the contacts\n1.Sorted\n2.Unsorted\n");
                scanf("%d",&sortChoice);
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("\033[0;32m\t\t----------::: Saving and Exiting :::----------\033[0m\n");
                saveContactsToFile(&addressBook);
		printf("\033[0;32m\t\t----------::\U0001F4AF:: Sucessfully saved ::\U0001F4AF::----------\033[0m\n");
                break;
	case 7:
                printf("\033[1;33m\t\t----------::\U0001F600::Thankyou::\U0001F600::----------\033[0m\n");
                exit(0);
            default:
                printf("\t\t----------::\U0001F605:: Invalid choice. Please try again ::\U0001F605::----------\n");
        }
    } while (choice >= 1 && choice < 7);
    
       return 0;
}

