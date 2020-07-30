#include <stdio.h>
#include<graphics.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include<string.h>
void insert();
void DisplayAll();
void Delete();
void  favour();
void update();
int serach();
int ask();
int findrec (int);
typedef struct data {
    int SLNO;
    char name[20];
    char phone[15];
    char gmail[30];
    char pin[15];
    char fav[4];
    struct data *next;
    } data;
data *firstrec,*currentrec,*newrec;
int recno = 0;
void main()
{
    char username[15],ch,ch1;
    char password[10];
    int i,j,inc=0;
    textbackground(WHITE);
    textcolor(RED);
    clrscr();
    firstrec = NULL;
    while(inc<3)
    {
		printf("\t\t\t============================================\n");
		printf("\t\t\t\t*****USER LOGIN********\n");
		printf("\t\t\tYou have only three chance to LOG IN \n");
		printf("\t\t\t============================================\n");
		printf("\t\t\t\tEnter your username:");
		gets(username);
		printf("\t\t\t============================================\n");
		printf("\t\t\tEnter your 8 digits password:");
		for(i = 0;i <8;i++)
		{
			ch1 = getch();
			if(ch1 == 8)
			break;
			password[i] = ch1;
			ch1 = '*';
			printf("%c ", ch1);
		}
		printf("\n\t\t\t============================================\n");
		password[i] = '\0';
		if(strcmp(username,"shivaraj")==0)
		{
			if(strcmp(password,"98451594")==0)
			{
			printf("\n\t\t\t\t________________________\n");
			printf("\n\t\t\t\tWelcome.Login Success!");
			printf("\n\t\t\t\t_________________________\n");
			}
			else
			{
			printf("\n\t\t\t\t\t________________\n");
			printf("\n\t\t\t\t\tWrong password");
			printf("\n\t\t\t\t\t_________________\n");
			}
		}
		else
		{
			printf("\n\t\t\tUser doesn't exist\n");
		}
		if((strcmp(password,"98451594")==0) && (strcmp(username,"shivaraj"))==0)
		{
			break;
		}
		inc++;

    }
	if(inc<3)
	{
		do
		{
		fflush(stdin);
		printf("\n\t\t\tWelcome To Contact Book Application\n");
		printf("\t\t\t------------------------------------\n");
		printf("\t\t\t1 - Add a new contact\n");
		printf("\t\t\t2 - Delete a contact\n");
		printf("\t\t\t3 - Display all contacts\n");
		printf("\t\t\t4 - Update the contact\n");
		printf("\t\t\t5 - Find the contact\n");
		printf("\t\t\t6 - Star your favourite contact\n");
		printf("\t\t\tQ - Exit\n");
		printf("\n\t\t\tEnter Your choice:");
		ch=getchar();
		ch=toupper(ch);
		clrscr();
		switch(ch)
		{
			case '1': clrscr();
			printf("\t\t\tAdd a new contact\n");
			fflush(stdin);
			insert();
			break;
			case '2': clrscr();
			printf("\t\t\tDelete a contact\n");
			Delete();
			break;
			case '3': clrscr();
			printf("\t\t\tDisplay all contacts\n");
			DisplayAll();
			break;
			case '4': clrscr();
			printf("\t\t\tUpdate a contact\n");
			update();
			break;
			case '5':   clrscr();
			printf("\t\t\tSearch a contact by name\n");
			serach();
			break;
			case '6' : clrscr();
			fflush(stdin);
			printf("\t\t\tFavourite  contact\n");
			favour();
			break;
			case 'Q':
			break;
			default: printf("\t\t\tInvalid choice\n");
			break;
		}
		}while(ch != 'Q');
	}
	else
	{
		exit(0);
	}
	getch();
}
void DisplayAll()
{
    if(firstrec==NULL)
	printf("\t\t\tSorry,your contact book is empty!\n");
    else
    {
	    printf("%6s %-20s %-15s %-20s %-20s\n","SL.NO","Name","Phone NO","PIN code","gmailID");
		puts("------ -------------------- ------------- -----------------  ------------");
	currentrec=firstrec;
	do
	{
		printf("%5d: %-20s %-15s %-15s %-20s\n",\
		currentrec->SLNO,\
		currentrec->name,\
		currentrec->phone,\
		currentrec->pin,\
		currentrec->gmail);
	}while((currentrec=currentrec->next) != NULL);
    }
}
void insert()
{
    newrec = (struct data *)malloc(sizeof(struct data));
    if(firstrec==NULL)
	firstrec = currentrec = newrec;
    else
    {
		currentrec = firstrec;
		while(currentrec->next != NULL)
		currentrec = currentrec->next;
		currentrec->next = newrec;
		currentrec = newrec;
    }
    recno++;
    printf("%27s: %5i\n","contact SLNO",recno);
    currentrec->SLNO = recno;
    printf("%25s: ","Enter contact name");
    gets(currentrec->name);
    printf("%25s: ","Enter contact Number");
    gets(currentrec->phone);
    printf("%25s: ","Enter the pin code");
    gets(currentrec->pin);
    printf("%25s: ","Enter contact gmail");
    gets(currentrec->gmail);
    printf("%25s:","Make your contact as faourite(YES/NO)");
    gets(currentrec->fav);
    printf("contact added! Successfuly");
    currentrec->next = NULL;
}
void Delete()
{
    int record;
    struct data *previous;
    if(firstrec==NULL)
    {
		printf("There are no such record found!\n");
		return;
    }

    DisplayAll();
    printf("Enter contact  SLNO to Delete: ");
    scanf("%d",&record);
    currentrec = firstrec;

    while(currentrec != NULL)
    {
	if(currentrec->SLNO == record)
	{
	    if(currentrec == firstrec)
		firstrec=currentrec->next;
	    else
		previous->next = currentrec->next;

		free(currentrec);
	    printf("contact %d Deleted!\n",record);
	    recno=recno-1;
	    return;
	}

	else
	{
		previous = currentrec;
	    currentrec = currentrec->next;
	}

    }
    printf("Sorry, unable to find your contact\n");
 }
void update()
{
    int record, occure;
    if(firstrec==NULL)
    {
	printf("No such record found!\n");
	return;
    }

    DisplayAll();
    printf("Enter contact  SLNO to Update: ");
    scanf("%d",&record);
    occure = findrec(record);

    if( occure >0 ){
	    printf("Contact %d:\n",currentrec->SLNO);
	    printf("Name: %s\n",currentrec->name);
	    if(ask())
		    gets(currentrec->name);
	    printf("Phone: %s\n",currentrec->phone);
	    if(ask())
		    gets(currentrec->phone);
		printf("PIN code : %s\n",currentrec->pin);
		if(ask())
			gets(currentrec->pin);
	    printf("gmail: %s\n",currentrec->gmail);
	    if(ask())
		    gets(currentrec->gmail);
		printf("Favourite: %s\n",currentrec->fav);
	    if(ask())
		    gets(currentrec->fav);
	    return;
	}
    printf("Sorry, unable to find your contact\n");
}
int findrec (int sn)
{
    int x;
    x = sn;
    currentrec = firstrec;
    while(currentrec != NULL)
    {

		if(currentrec->SLNO == x)
			{
		return 1;
		}

		else
		{
			currentrec = currentrec->next;
		}
    }
    return -1;
}
int serach()
{
     char buff[20];
     if(firstrec==NULL)
	{
	printf("Record Not Found!\n");
	    return 1;
    }
    printf("Enter contact name: ");
    fflush(stdin);
    gets(buff);

    currentrec = firstrec;
    while(currentrec != NULL)
    {

	if( strcmp(currentrec->name, buff) == 0 )
	    {
		printf("%6s %-20s %-15s %-15s %-20s\n","SLNO#","Name","Phone","PIN Code","gmail");
	    printf("%6d: %-20s %-15s %-15s %-20s\n",\
	    currentrec->SLNO,\
	    currentrec->name,\
	    currentrec->phone,\
		currentrec->pin,\
	    currentrec->gmail);
			return 0;
	    }
		else
		{
			currentrec = currentrec->next;
		}
    }
    printf("Contact  not found! in the database\n");
	  return 1;
}
void favour()
{
	char fav[5];
	int i;
	printf("Would you like to see favorite account\n");
	gets(fav);
	//currentrec=firstrec;
	if(currentrec==NULL)
	printf("There are no contacts to display!\n");
    else
    {
	    printf("%-10s %-11s %-10s %-20s %-15s\n","Name","Phone NO","PIN code","gmailID","favorite");
		puts("---------- ----------- ---------- ------------------  ---------");
		currentrec=firstrec;
		do
		{
			if(strcmp(currentrec->fav,fav)==0)
			{
			printf("%-10s %-11s %-10s %-20s %-15s\n",\
			currentrec->name,\
			currentrec->phone,\
			currentrec->pin,\
			currentrec->gmail,\
			currentrec->fav);
			}
		}while((currentrec=currentrec->next) != NULL);
    }
}
int ask()
{
	char read;
    fflush(stdin);
	printf("Want to Update? (Y-yes/N-Not)");
	read = getchar();
	read = toupper(read);
	fflush(stdin);
	if(read == 'Y')
	{
		printf("Enter new value: ");
		return(1);
	}
	else
		return(0);
}