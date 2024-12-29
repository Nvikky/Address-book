/*
NAME : N VENKATA PRASAD
DATE : 28/09/24
DESCRIPTION : CONTACT.H - It consists of all function prototypes
*/
#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
    Contact temp;
    Contact temp1;
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

int val(char *s);
int valnum(char *s);
int valmail(char *email);


#endif
