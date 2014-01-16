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
            DeleteAll(phonebook);
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
}

void random()
{
}

void cls()
{
	system("cls");
}
