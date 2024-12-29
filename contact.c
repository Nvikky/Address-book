/*
NAME : N VENKATA PRASAD
DATE : 28/09/24
DESCRIPTION : CONTACT.C - It consists of all functions definitions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    // Sort contacts based on the chosen criteria
   int n = addressBook->contactCount;
    if(sortCriteria==1)
    {
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0)
            {
                Contact temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }
    }
    if(n)
    {	printf("\033[1;33m\t\t------------------------- :: List Of Contatcs :: --------------------------\033[0m\n");
        printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
        printf("\033[0;34m| %-40s | %-15s | %-45s |\033[0m\n", "Name", "Phone number", "E-Mail Id");
        printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
        for(int i=0;i<n;i++)
        {
            printf("| %-40s | %-15s | %-45s |\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
        }
    }
    else
    {
        printf("\033[0;31m \t\t---------------- ::\U0001F613:: N0 Contacts are available ::\U0001F613:: ----------------\033[0m\n");
    }

}

int val(char *s)//function defination to validite name
{
    int i=0;
    while(s[i]!='\0')//Run the loop un till null character
    {
        if(!((isalpha(s[i]))||s[i]==' '))//logic for is alphabat and sapce
        {
            return 0;
        }
        i++;
    }
    return 1;//return 1
}
int valnum(char *s)//function defination to validite phone number
{
   int i=0;
   while(s[i]!='\0')////Run the loop un till null character
    {
        if(!(isdigit(s[i]))||strlen(s)!=10)//logic for is digit and sapce
        {
            return 0;
        }
        i++;
    }
    return 1; //return 1
}
int valmail(char *email)
{
    int at_count = 0;
    int length = strlen(email);
    // Email must be at least 5 characters (a@b.c)
    if (length < 5)
        return 0;
    // Traverse the email string
    for (int i = 0; i < length; i++)
    {
        char c = email[i];
        // Check for valid characters
        if (!isalnum(c) && c != '@' && c != '.' && c != '-' && c != '_')
        {
            return 0;  // Invalid character found
        }
        // Count '@' characters
        if (c == '@')
        {
            at_count++;
            if (at_count > 1)
                return 0;  // More than one '@'
        }
        // Check for a period after '@'
        if (c == '.' && (i > 0 && email[i - 1] == '@'))
        {
            return 0;  // No valid domain if '.' immediately follows '@'
        }
    }
    char *at_ptr = strchr(email, '@'); // Check for exactly one '@' and at least one '.' after '@'
    char *dot_ptr = strrchr(email, '.');
    if (at_ptr == NULL || dot_ptr == NULL || dot_ptr < at_ptr)
    {
        return 0;  // Missing '@' or '.' before '@'
    }
    // Check domain is not empty
    if (strlen(dot_ptr + 1) == 0)
        return 0;
    return 1;  // Passed all checks
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
//    populateAddressBook(addressBook);

    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);

}


void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}



void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
     int i=addressBook->contactCount;
    printf("\033[0;36mEnter your name : \033[0m");
    getchar();
    scanf("%[^\n]",addressBook->contacts[i].name);//read the input from user
    if(!val(addressBook->contacts[i].name))//call the function
    {
       printf("\033[0;31m\t\t----------------::\U0001F613:: Error :: Name ::\U0001F613::---------------\033[0m\n");
       return;
    }
    printf("\033[0;36mEnter your number : \033[0m");
    getchar();
    scanf("%[^\n]",addressBook->contacts[i].phone);//read the input from the user
			
    if(!valnum(addressBook->contacts[i].phone))//calling the function
    {
       printf("\033[0;31m\t\t---------------::\U0001F613:: Error :: Phone number ::\U0001F613::---------------\033[0m\n");
       return;
    }
    for(int j=0;j<addressBook->contactCount;j++)                                                                                         {                                                                                                                                            if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[i].phone)==0)                                                         {                                                                                                                                                                                                                                                                         printf("\033[0;31m\t\t----------------- ::\U0001F613:: Number already existed ::\U0001F613:: ---------------\033[0m\n");
                return;
                }
        }
    printf("\033[0;36mEnter your email-address : \033[0m");
    getchar();
    scanf("%[^\n]",addressBook->contacts[i].email);//read the input from user
    
    if(!valmail(addressBook->contacts[i].email))//calling the function
    {
       printf("\033[0;31m\t\t---------------::\U0001F613:: Error :: E-mail::\U0001F613::---------------\033[0m\n");
       return;
    }
    for(int j=0;j<addressBook->contactCount;j++)
        {
                if(strcmp(addressBook->contacts[j].email,addressBook->contacts[i].email)==0)
                {

                printf("\033[0;31m\t\t----------------- ::\U0001F613:: E-Mail already existed ::\U0001F613:: ---------------\033[0m\n");
                return;
                }
	}
    addressBook->contactCount++;
    printf("\033[0;32m\t\t---------------::\U0001F973::Sucessfully Added::\U0001F973::---------------\033[0m\n");
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
	printf("1.search by name\n2.search by phone number\n3.search by e-mail id\n");
    int opt;
    scanf("%d",&opt);
    getchar();
    switch(opt)
    {
        case 1:
        {
            printf("Enter the name : ");
            scanf("%[^\n]",addressBook->temp.name);
	    for (int j = 0; addressBook->temp.name[j] != '\0'; j++) addressBook->temp.name[j] = toupper((unsigned char)addressBook->temp.name[j]);
            getchar();
            if(!val(addressBook->temp.name))
            {
                printf("\033[0;31m\t\t---------------::\U0001F613:: Error :: Name must contain only alphabet::\U0001F613::---------------\033[0m\n");
                return -1;
            }
            int c=0;
            int position;
            for(int i = 0;i<addressBook->contactCount;i++)
            {
            strcpy(addressBook->temp1.name,addressBook->contacts[i].name);
                for (int j = 0; addressBook->temp1.name[j] != '\0'; j++) addressBook->temp1.name[j] = toupper((unsigned char)addressBook->temp1.name[j]);
		    if(strstr(addressBook->temp1.name,addressBook->temp.name)!=NULL)
            {
                position=i;
                if(c==0)
                {
		printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
                printf("|\033[0;34m %-40s | %-15s | %-45s |\033[0m\n", "Name", "Phone number", "E-Mail Id");
                printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
                }
                c++;
                printf("| %-40s | %-15s | %-45s |\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
            }
            }
            if(c==0)
            {
                printf("\033[0;31m\t\t---------------::\U0001F613:: Error::No contacts Found ::\U0001F613::---------------\033[0m\n");
                return -1;
            }
            if(c==1)
            {
                return position;
            }
            if(c>1)
            {
                printf("Multiple results are found in this name\nDo you want to search by:\n2.search by phone number\n3.search by e-mail id\n");
                scanf("%d",&opt);
                getchar();
                if(opt == 2)
                goto case_2;
                else if(opt == 3)
                goto case_3;
                else
                goto default_case;
            }
            break;
        }
        case 2:
        case_2:
        {
            printf("Enter the phone number : ");
            scanf("%[^\n]",addressBook->temp.phone);
            getchar();
            if(!valnum(addressBook->temp.phone))
            {
                printf("\033[0;31m\t\t---------------::\U0001F613:: Error :: phone number must be 10 digits ::\U0001F613::---------------\033[0m");
                return -1;
            }
            int c=0;
            for(int i = 0;i<addressBook->contactCount;i++)
            {
            if(strcmp(addressBook->temp.phone,addressBook->contacts[i].phone)==0)
            {
                c++;
		printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
                printf("\033[0;34m| %-40s | %-15s | %-45s |\033[0m\n", "Name", "Phone number", "E-Mail Id");
		printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
                printf("| %-40s | %-15s | %-45s |\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
                return i;
            }
            }
            if(c==0)
            {
                printf("\033[0;31m\t\t---------------::\U0001F613::Error :: Details Not Found Please try again::\U0001F613::---------------\033[0m\n");
                return -1;
            }
            break;
        }
        case 3:
        case_3:
        {
            printf("Enter the E-Mail Id : ");
            scanf("%[^\n]",addressBook->temp.email);
            getchar();
            if(!valmail(addressBook->temp.email))
            {
                printf("\033[0;31m\t\t---------------::\U0001F613::Error :: Email is not in correct format::\U0001F613::---------------\033[0m");
                return -1;
            }
            int c=0;
            for(int i = 0;i<addressBook->contactCount;i++)
            {
            if(strcmp(addressBook->temp.email,addressBook->contacts[i].email)==0)
            {
                c++;
		printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
                printf("\033[0;34m| %-40s | %-15s | %-45s |\033[0m\n", "Name", "Phone number", "E-Mail Id");
                printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
                printf("| %-40s | %-15s | %-45s |\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
                return i;
            }
            }
            if(c==0)
            {
                printf("\033[0;31m\t\t---------------::\U0001F613::Error :: Details Not Found Please try again::\U0001F613::---------------\033[0m\n");
                return -1;
            }
            break;
        }
        default :
        default_case:
        {
            printf("\033[0;31m\t\t---------------::\U0001F613::Error :: Invalid choice::\U0001F613::---------------\033[0m\n");
            return -1;
        }
	    break;
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
	int position = searchContact(addressBook);
	if(position==-1)
	{
	    printf("\033[0;31m\t\t---------------::\U0001F613:: Error :: Editing is not possible ::\U0001F613::---------------\033[0m\n");
	    return;
	}
	int ch;
	printf("Do you want to Edit Name\n1.Yes\n0.No\n");
	scanf("%d",&ch);
	getchar();
	if(ch==1)
	{
	    printf("Enter New Name : ");
	    scanf("%[^\n]",addressBook->temp.name);
	    getchar();
	    if(!val(addressBook->temp.name))
	    {
	        printf("\033[0;31m\t\t---------------::\U0001F613::Error :: Name::\U0001F613::---------------\033[0m\n");
	        return;
	    }
	    strcpy(addressBook->contacts[position].name,addressBook->temp.name);
	    printf("\033[0;32m\t\t---------------::\U0001F973::Name Successfully Updated::\U0001F973::---------------\033[0m\n");
	}
	else if(ch!=0)
	{
		printf("\033[0;31m\t\t----------------::\U0001F613:: Invalid option ::\U0001F613::----------------\033[0m\n");
	}
    do{
	    printf("Do you want to Edit Phone Number\n1.Yes\n0.No\n");
	    scanf("%d",&ch);
        int c=0;
	    getchar();
    	if(ch==1)
	    {
	        printf("Enter New Phone Number: ");
	        scanf("%[^\n]",addressBook->temp.phone);
	        getchar();
	        if(!valnum(addressBook->temp.phone))
	        {
	             printf("\033[0;31m\t\t---------------::\U0001F613::Error ::: Incorrect Phone number Formate ::\U0001F613::---------------\033[0m\n");
	             return;
	        }
            for(int j=0;j<addressBook->contactCount;j++)                                                                                         
            {                                                                                                                                        
            if(strcmp(addressBook->contacts[j].phone,addressBook->temp.phone)==0)     
		    {        
		        c=1; 
                printf("\033[0;31m\t\t----------------- ::\U0001F613:: Phone number already existed ::\U0001F613:: ---------------\033[0m\n");
		    }
            }
        
        if(c==0)
        {
	            strcpy(addressBook->contacts[position].phone,addressBook->temp.phone);
                ch=0;
	            printf("\033[0;32m\t\t---------------::\U0001F973:: Phone Number Successfully Updated ::\U0001F973::---------------\033[0m\n");
	    }
        else if(ch!=1 && ch!=0) 
        {
                printf("\033[0;31m\t\t----------------::\U0001F613:: Invalid option ::\U0001F613::----------------\033[0m\n");
        }
        }
    }while(ch);
    do{
	    	printf("Do you want to Edit E-Mail\n1.Yes\n0.No\n");
	        scanf("%d",&ch);
            int c=0;
        	getchar();
        	if(ch==1)
	        {
	             printf("Enter New E-Mail : ");
	             scanf("%[^\n]",addressBook->temp.email);
	             getchar();
	            if(!valmail(addressBook->temp.email))
	            {
	                printf("\033[0;31m\t\t---------------::\U0001F613:: Error:::Incorrect E-mail Formate ::\U0001F613::---------------\033[0m\n");
	                return;
	            }
                for(int j=0;j<addressBook->contactCount;j++)
            {
            if(strcmp(addressBook->contacts[j].email,addressBook->temp.email)==0)
            {
               c=1;
                printf("\033[0;31m\t\t----------------- ::\U0001F613:: E-Mail already existed ::\U0001F613:: ---------------\033[0m\n");
               break;
            }
            }
                if(c==0)
            {
	                strcpy(addressBook->contacts[position].email,addressBook->temp.email);
                    ch=0;
	                printf("\033[0;32m\t\t---------------::\U0001F973:: E-Mail Successfully Updated::\U0001F973::---------------\033[0m\n");
            }
            }
        else if(ch!=0 && ch!=1)
        {
                printf("\033[0;31m\t\t----------------::\U0001F613:: Invalid option ::\U0001F613::----------------\033[0m\n");
        }    

    }while(ch);
		printf("\033[1;32m\t\t---------------::\U0001F973:: Contact Successfully Updated::\U0001F973::---------------\033[0m\n");
		printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
 		printf("\033[0;34m| %-40s | %-15s | %-45s |\033[0m\n", "Name", "Phone number", "E-Mail Id");        
		printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");
		printf("| %-40s | %-15s | %-45s |\n", addressBook->contacts[position].name, addressBook->contacts[position].phone, addressBook->contacts[position].email);
        printf("\033[0;31m+------------------------------------------+-----------------+-----------------------------------------------+\033[0m\n");


}
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
	int position = searchContact(addressBook);
	if(position<0)
	{
	    printf("\033[0;31m\t\t---------------::\U0001F613:: Deleting is not possible ::\U0001F613::---------------\033[0m\n");
	    return;
	}
	for(int i=position;i<addressBook->contactCount-1;i++)
	{
	    addressBook->contacts[i]=addressBook->contacts[i+1];
	}
	addressBook->contactCount--;
	printf("\033[0;32m\t\t---------------::\U0001F973:: Deleted Successfully ::\U0001F973::---------------\033[0m\n");
}
