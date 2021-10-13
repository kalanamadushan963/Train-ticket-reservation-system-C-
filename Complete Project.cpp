/**********************************************PREPROCESSORS**********************************************************/
//Train Reservation System - BROUGHT TO YOU BY : code-projects.org
//Working on basic structure
//including all libraries for now
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/*******************************************GLOBAL VARIABLES**********************************************************/
//ALl the globle variables and the composite data types will be declared here
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;




/*******************************************FUNCTION PROTOTYPE**********************************************************/
//function prototypes to be used
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);
void printticket(char name[],int,int,float);	//print ticket
void specifictrain(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login();


/******************************************FUNCTION DECLARATION**********************************************************/

/*********************************************MAIN()*************************************************/

int main()

{
		system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t|           |  code-projects.org  |             |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");

	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();		//Fucntion still not added
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			//function not added. code has been removed due to some errors
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/
void viewdetails(void)
{
	system("cls");
	printf("-----------------------------------------------------------------------------");	
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1001\tRed Lines Express\tBoston to Manhattan\tRs.5000\t\t9am");
	printf("\n1002\tRed Lines Express\tManhattan To Boston\tRs.5000\t\t12pm");
	printf("\n1003\tLA City Express\t\tBoston To L.A\t\tRs.4500\t\t8am");
	printf("\n1004\tLA City Express\t\tL.A To Boston\t\tRs.4500\t\t11am");
	printf("\n1005\tIron City Express\tBoston To Chicago\tRs.4000\t\t7am");
	printf("\n1006\tIron City Express\tChicago To Boston\tRs.4000\t\t9.30am");
    printf("\n1007\tKeystone Express\tBoston To Washington\tRs.3500\t\t1pm");	
    printf("\n1008\tKeystone Express\tWashington To Boston\tRs.3500\t\t4pm");
    printf("\n1009\tMeteor Express\t\tBoston To Miami\t\tRs.6000\t\t3.35pm");
    printf("\n1009\tMeteor Express\t\tMiami To Boston\t\tRs.6000\t\t4.15pm");
    
}


/*********************************************RESERVATION()*************************************************/
void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name 
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(6000.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/
#include<stdio.h>
#include<conio.h>
static int n=0;
struct STUDENT
{
	int age,roll_no,maths,physics,chemistry,total;
	char name[10];
	float avg;
};
int main()
{
	void add();
	void password();
	void displayAll();
	void record();
	void del();
	void marksheet();
	void modify();
	void changePassword();
	int i,count=0,a,n=0,r,m,ms;
	printf("\n\t\t\t\t========================================================\n");
	printf("\n\t\t\t\t\t\t   STUDENT RECORDS\n");
	printf("\n\t\t\t\t========================================================\n");

		while(1)
		{
		printf("\n----------------------");
		printf("\nchoose an option below");
		printf("\n----------------------");
		printf("\n1.add a record");
		printf("\n2.delete a record");
		printf("\n3.modify a record");
		printf("\n4.generate marksheet");
		printf("\n5.search a record");
		printf("\n6.display all records");
		printf("\n7.change password");
		printf("\n8.exit");
		printf("\n----------------------\n");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
			{
				password();
				add();	
				break;
			}
			case 2:
			{	
				password();
				del();
				break;
			}
			case 3:
			{
				password();
				modify();
				break;
			}
			case 4:
			{
				marksheet();
				break;	
			}
			case 5:
			{
				record();
				break;
			}
			case 6:
			{
				displayAll();
				break;
			}
			case 7:
			{
				password();
				changePassword();
				break;
			}
			case 8:
			{
				exit(0);
			}
				
		}
	}	
}
void add()
{
		int i;
		struct STUDENT s;
		int size;
		FILE *fp;
		size=sizeof(s);
		fp=fopen("MINI_PROJECT_IN_C.DAT","ab");
 		printf("\nenter roll no for record\n");
		scanf("%d",&s.roll_no);
		printf("enter name\n");
		scanf("%s",s.name);
		printf("enter age\n");
		scanf("%d",&s.age);
		printf("enter maths marks\n");
		scanf("%d",&s.maths);
		printf("enter physics marks\n");
		scanf("%d",&s.physics);
		printf("enter chemistry marks\n");
		scanf("%d",&s.chemistry);
		s.total=s.maths+s.physics+s.chemistry;
		s.avg=s.total/3;
		fwrite(&s,size,1,fp);
		fclose(fp);	
		printf("\nrecord successfully added");
}

void password()
{
	FILE *fp;
	int i=0,count=0;
	printf("\nenter password");
	char ch[6],c[6],a,b;
	fp=fopen("password.txt","r");
	while((b=getc(fp))!=EOF)
		{
		c[i]=b;
		i++;
		}
	for(i=0;i<6;i++)
	{
	a=getch();
	ch[i]=a;
	printf("*");
	if(ch[i]==c[i])
	{
		count++;
	}
	}
	if(count==6)
	{
		printf("\nlogin success");
	}
	else
	{
		printf("\nlogin failed re ");
		password();
	}
	fclose(fp);
}
void displayAll()
{
FILE *fp;
struct STUDENT s;

fp=fopen("MINI_PROJECT_IN_C.DAT","rb");

printf("\n========================================================\n\n");
printf("\t\t All Student Details\n\n");
printf("========================================================\n\n");


while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
		printf("\nrollno:%d\t",s.roll_no);
		printf("name:%s\t",s.name);
		printf("age:%d\t",s.age);
		printf("total:%d\n",s.total);
}
printf("========================================================\n\n");

fclose(fp);
}
void record()
{
FILE *fp;
struct STUDENT s;
int id,found=0;
fp=fopen("MINI_PROJECT_IN_C.DAT","rb");
printf("\nEnter the student roll no:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);
if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
printf("\n========================================================\n\n");
printf("\t\t Student Record of %d\n\n",s.roll_no);
printf("========================================================\n\n");

		printf("rollno:%d\t",s.roll_no);
		printf("name:%s\t",s.name);
		printf("age:%d\t",s.age);
		printf("total:%d\n",s.total);

printf("========================================================\n\n");
}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}
void del()
{
FILE *fp,*fp1;
struct STUDENT s,s1;
int id,found=0;

fp=fopen("MINI_PROJECT_IN_C.DAT","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter student roll no you want to Delete:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
}
else
{
fwrite(&s,sizeof(s),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen("MINI_PROJECT_IN_C.DAT","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&s,sizeof(s),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&s,sizeof(s),1,fp);
}
}
fclose(fp);
fclose(fp1);
}
void marksheet()
{
FILE *fp;
struct STUDENT s;
int id,found=0;
fp=fopen("MINI_PROJECT_IN_C.DAT","rb");
printf("\nEnter the student roll no:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);
if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
printf("\n========================================================\n\n");
printf("\t\t Student Marksheet of %d\n\n",s.roll_no);
printf("========================================================\n\n");

		printf("rollno:%d\t",s.roll_no);
		printf("name:%s\t",s.name);
		printf("maths:%d\t",s.maths);
		printf("physics:%d\t",s.physics);
		printf("chemistry:%d\t",s.chemistry);
		printf("total:%d\t",s.total);
		printf("average:%2f\n",s.avg);

printf("========================================================\n\n");
}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}
void modify()
{
FILE *fp,*fp1;
struct STUDENT s;
int id,found=0;

fp=fopen("MINI_PROJECT_IN_C.DAT","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter student roll no you want to Modify:");
scanf("%d",&id);

while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
if(s.roll_no==id)
{
found=1;
		printf("enter roll no for record\n");
		scanf("%d",&s.roll_no);	
		//fflush(stdin);
		printf("enter name\n");
		scanf("%s",s.name);
		printf("enter age\n");
		scanf("%d",&s.age);
		printf("enter maths marks\n");
		scanf("%d",&s.maths);
		printf("enter physics marks\n");
		scanf("%d",&s.physics);
		printf("enter chemistry marks\n");
		scanf("%d",&s.chemistry);
		s.total=s.maths+s.physics+s.chemistry;
		s.avg=s.total/3;
fwrite(&s,sizeof(s),1,fp1);
}
else
{
fwrite(&s,sizeof(s),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen("MINI_PROJECT_IN_C.DAT","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&s,sizeof(s),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&s,sizeof(s),1,fp);
}

}
fclose(fp);
fclose(fp1);
}
void changePassword()
{
	FILE *fp;
	int i;
	char ch[6],c[6],count=0;
	fp=fopen("password.txt","w");
	printf("\nenter new passowrd with 6 character");
	scanf("%s",ch);
	printf("\nre-enter password");
	scanf("%s",c);
	for(i=0;i<6;i++)
	{
		if(ch[i]==c[i])
		count++;
	}
	if(count==6)
	{
	fprintf(fp,"%s",ch);
	printf("\npassword successfully changed");
	}
	else
	{
		printf("\nnot matching");
		changePassword();
	}	
	fclose(fp);
}


 




/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain(int train_num)
{

	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tBoston to Manhattan");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tManhattan to Boston");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tLA City Express");
		printf("\nDestination:\t\tBoston to L.A");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tLA City Express");
		printf("\nDestination:\t\tL.A to Boston");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tIron City Express");
		printf("\nDestination:\t\tBoston to Chicago");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tIron City Express");
		printf("\nDestination:\t\tChicago to Boston");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\nDestination:\t\tBoston to Washington");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\n Destination:\t\tWashington to Boston");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tBoston to Miami");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tMiami to Boston");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

void cancel(void)
	system("cls");
	int trainnum;
	printf("-----------------------\n");
		printf("Enter the train number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&trainnum);
		printf("\n\nCancelled");
		getch();
}





