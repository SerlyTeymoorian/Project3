#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

#include "address_book.h"



Status load_file(AddressBook *address_book)
{
	int ret;
	
	ret = access(DEFAULT_FILE, F_OK);

	//Check for file existance
	if (ret == 0)
	{	
		
        char buff[255];
        int numLines =0; 
        char ch;
        address_book->fp = fopen(DEFAULT_FILE, "r");
        newAddress = (AddressBook*) malloc(1 * sizeof(AddressBook));
        contactInfo = (ContactInfo*) malloc(1 * sizeof(ContactInfo));
        newAddress->list = contactInfo;
        newAddress->count = 0;
        while(!feof(address_book->fp)) 
        {
            ++numLines; 
            fgets(buff, 255, (FILE*)address_book->fp);
            char *individualData;
            individualData = strtok (buff,",");
            int counter = 0;
            while (individualData != NULL) 
            {
                ++counter;
                if (counter == 1) 
                {
                    ((newAddress->count)+contactInfo)->si_no= atoi(individualData);
                }
                else if (counter == 2) 
                {
                    strcpy(*((newAddress->count)+contactInfo)->name, individualData);
                }
                else if (counter == 3) 
                {
                    strcpy( ((newAddress->count)+contactInfo)->phone_numbers[0], individualData);
                }
                else if (counter == 4) 
                {
                    strcpy(((newAddress->count)+contactInfo)->phone_numbers[1], individualData);
                }
                else if (counter == 5)
                {
                    strcpy(((newAddress->count)+contactInfo)->phone_numbers[2], individualData);
                }
                else if (counter == 6) 
                {
                    strcpy(((newAddress->count)+contactInfo)->phone_numbers[3], individualData);
                }
                else if (counter == 7) 
                {
                    strcpy(((newAddress->count)+contactInfo)->phone_numbers[4], individualData);
                }
                else if (counter == 8) 
                {
                    strcpy(((newAddress->count)+contactInfo)->email_addresses[0], individualData);
                }
                else if (counter == 9) 
                {
                    strcpy(((newAddress->count)+contactInfo)->email_addresses[1], individualData);
                }
                else if (counter == 10) 
                {
                    strcpy(((newAddress->count)+contactInfo)->email_addresses[2], individualData);
                }
                else if (counter == 11) 
                {
                    strcpy(((newAddress->count)+contactInfo)->email_addresses[3], individualData);
                }
                else if (counter == 12) 
                {
                    strcpy(((newAddress->count)+contactInfo)->email_addresses[4], individualData);
                    newAddress->count++;
                } 
                individualData = strtok (NULL, ",");
                contactInfo = (ContactInfo*) realloc(contactInfo, ((numLines + 1) * sizeof(ContactInfo)));
                newAddress->list = contactInfo;
            }
        
        }
   
	    fclose(address_book->fp);
	}
	else
	{
		address_book->fp = fopen(DEFAULT_FILE, "w");
        fclose(address_book->fp);
	}

	return e_success;
}


Status save_file(AddressBook *address_book)
{
	/*
	 * Write contacts back to file.
	 * Re write the complete file currently
	 */ 
	address_book->fp = fopen(DEFAULT_FILE, "w");

	if (address_book->fp == NULL)
	{
		return e_fail;
	}

	/* 
	 * Add the logic to save the file
	 * Make sure to do error handling
	 */ 

	fclose(address_book->fp);

	return e_success;
}
