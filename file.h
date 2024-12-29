/*
NAME : N VENKATA PRASAD
DATE : 28/09/24
DESCRIPTION : FILE.C - It consists of all file related functions and function calls and prototypes.
*/
#ifndef FILE_H
#define FILE_H

#include "contact.h"

void saveContactsToFile(AddressBook *addressBook);
int loadContactsFromFile(AddressBook *addressBook);

#endif

