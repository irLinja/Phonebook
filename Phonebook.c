#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Phonebook_Data
{
      char FirstName[20];
      char LastName[20];
      char PhoneNumber[20];
};
   
struct Phonebook_Data phonebook[100];
   
int counter = 0;
   
void cls();
void add();
void delete();
void deleteall();
void edit();
void list();
void search();
void random();

int main()
{
	int iSelection = 0;


for(;;)
{
    printf("\n\t\t\tPhonebook Options");
    printf("\n\n\t(1)\tAdd Contact");
    printf("\n\t(2)\tDelete Contact");
    printf("\n\t(3)\tDisplay Phonebook ");
    printf("\n\t(4)\tLook Up a Contacts Phone Number");
    printf("\n\t(5)\tPick a Random Contact to Call");
    printf("\n\t(6)\tDelete ALL Contacts");
    printf("\n\t(7)\tExit Phonebook");
    printf("\n\nSelect an option from the menu? ");
    scanf("%d", &iSelection);

    switch(iSelection)
    {
        case 1:
            add();
            break;
        case 2:
            delete();
            break;
        case 3:
            list();
            break;
        case 4:
            search();
            break;
        case 5:
            random();
            break;
        case 6:
            deleteall();
            break;
        case 7:
            fprintf(stdout, "\nYou have chosen to exit the Phonebook.\n");
            getchar( );
            break;
        default:
            fprintf(stdout, "\n\tI don't know the option : %d \a\n", iSelection);
            break;
    }


    if (iSelection == 7) break;
}


return 0;
}


void add()
{
	counter++;
 
	printf("\nFirst Name: ");
    scanf("%s", phonebook[counter-1].FirstName);
    printf("Last Name: ");
    scanf("%s", phonebook[counter-1].LastName);
    printf("Phone Number XXX-XXX-XXXX: ");
    scanf("%s", phonebook[counter-1].PhoneNumber);
    printf("\n\tContact successfully added to Phonebook\n");
    getchar( );
    system("cls");
}

void delete()
{
	int x = 0;
   int i = 0;
   char deleteFirstName[20];
   char deleteLastName[20];
 
 
   printf("\nFirst name: ");
   scanf("%s", deleteFirstName);
   printf("Last name: ");
   scanf("%s", deleteLastName);
 
 
   for (x = 0; x < counter; x++)
   {
       if (strcmp(deleteFirstName, phonebook[x].FirstName) == 0)
       {
           if (strcmp(deleteLastName, phonebook[x].LastName) == 0)
           {
               for ( i = x; i < counter - 1; i++ )
               {
                  strcpy(phonebook[i].FirstName, phonebook[i+1].FirstName);
                  strcpy(phonebook[i].LastName, phonebook[i+1].LastName);
                  strcpy(phonebook[i].PhoneNumber, phonebook[i+1].PhoneNumber);
               }
               printf("Record deleted from the phonebook.\n\n");
               --counter;
               return;
            }
        }
    }
  
   printf("That contact was not found, please try again.");
}

void deleteall()
{
   int x = 0;
   char nullStr[20] = {'\0'};
  
   for ( x = 0; x < counter; x++ )
   {
      strcpy(phonebook[x].FirstName, nullStr);
      strcpy(phonebook[x].LastName, nullStr);
      strcpy(phonebook[x].PhoneNumber, nullStr);
      --counter;
   }
   
   printf("All Contacts have been deleted.\n");
}

void edit()
{
}

void list()
{
	cls();
	int x;
	for( x = 0; x < counter; x++)
      {
         printf("\n(%d)\n", x+1);
         printf("Name: %s %s\n", phonebook[x].FirstName, phonebook[x].LastName);
         printf("Number: %s\n", phonebook[x].PhoneNumber);
      }
      getchar( );
}

void search()
{
	int x = 0;
	char TempFirstName[20];
	char TempLastName[20];
  
   	printf("\nWhat is the Name of the Contact that you want to find the Phone Number for?");
   	printf("\n\nFirst Name: ");
   	scanf("%s", TempFirstName);
   	printf("Last Name: ");
   	scanf("%s", TempLastName);
   	for (x = 0; x < counter; x++)
   	{
      	if (strcmp(TempFirstName, phonebook[x].FirstName) == 0)
         	if (strcmp(TempLastName, phonebook[x].LastName) == 0)
              	printf("\n%s %s's phone number is %s\n", phonebook[x].FirstName, phonebook[x].LastName, phonebook[x].PhoneNumber);
   	}
}

void random()
{
}

void cls()
{
	system("cls");
}
