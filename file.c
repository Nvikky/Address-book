/*
NAME : N VENKATA PRASAD
DATE : 28/09/24
DESCRIPTION : FILE.C - It consists of all file related functions and function calls.
*/
#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
        FILE *temp= fopen("temp.csv","w");
        for(int i=0;i<addressBook->contactCount;i++)
        {
                fprintf(temp,"%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        fclose(temp);
        remove("text.csv");
        rename("temp.csv","text.csv");
}

int loadContactsFromFile(AddressBook *addressBook)
{
        FILE *file=fopen("text.csv","a+");
         if (file == NULL) 
	 {
        	perror("Error opening file");
        	return -1; // Return -1 
   	 
	 }

	 int i = 0;
	 char line[100];

    	while (i < 100 && fgets(line, sizeof(line), file) != NULL)
       	{
 if(sscanf(line,"%[^,],%[^,],%s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email) == 3)
       	{
            i++;
        }
    }

    addressBook->contactCount = i; // Update contact count
    fclose(file); // Close the file
    return i; // Return the number of contacts loaded
}











