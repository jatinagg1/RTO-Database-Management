#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

 class rto
{
 char name[20];
 char state[20];
 char mno[20];
	public: char regno[20];
		 rto()
		{
			strcpy(name,"\0");
			strcpy(state,"\0");
			strcpy(mno,"\0");
			strcpy(regno,"\0");
		}
		 void input();
		 void output();
		 void display();
		 void genregno();
		 char* regnum()
		{
		 return regno;
		}
}r[100];

 void rto::genregno()
{
 int i,j;
 int t=0;
 regno[0]=state[0];

	 for(i=0;state[i]!='\0';i++)
	{
		 if(state[i]==' ')
		{
			regno[1]=state[i+1];
			t=1;
		}
		 if(t==0)
			regno[1]=state[1];
	}

 regno[2]=' ';

	 for(j=0,i=3;i<7;i++,j++)
		regno[i]=mno[j];

	 if((int)regno[0]>=98 || regno[0]<=120 || regno[1]>=98 || regno[1]<=120)
	{
		regno[0]=regno[0]-32;
		regno[1]=regno[1]-32;
	}

 regno[i]='\0';
}

 void rto::input()
{
 cout<<"\n\n Full name : ";
	gets(name);
 cout<<"\n State(at present) : ";
	gets(state);
 cout<<"\n Mobile number : ";
	gets(mno);
 genregno();
 cout<<"\n\t\t**************************************************\n\n";
}

 void rto::output()
{
 cout<<"\n Applicant name: "<<name;
 cout<<"\n Applicant's state: "<<state;
 cout<<"\n Applicant's mobile number: "<<mno;
 cout<<endl<<" Registration Number: "<<regno<<endl;
 cout<<"\n\t\t**************************************************\n\n";
}

 void rto::display()
{
 cout<<"\n Applicant name: "<<name;
 cout<<"\n Applicant's state: "<<state;
 cout<<"\n Applicant's mobile number: "<<mno<<endl;
}

 void main()
{
 clrscr();
 cout<<"\n\t\t\t\tRTO DATABASE\n\n";
 int i,n,option;
 char ch;
 do
{
 cout<<" Enter number of applicants to be registered=";
	cin>>n;

	 if(n==0)
	{
	 cout<<"\n Enter valid number atleast greater than 0\n\n"<<" Press any key to continue\n\n";
	 getch();
	}
} while(n<1);

 do
{
 clrscr();
 cout<<"\n\t\t\t\tMain Menu for User\n\n\t1. Enter your details\t\t2. Display your details\n\t3. Search your vehicle\t\t4. Sorted list of vehicles\n\t5. Exit\n";
 cout<<"\n Enter your option number : ";
	cin>>option;
 switch(option)
{
	case 1: clrscr();
		cout<<"\n\t\t\t\tEnter your details";
		 for(i=0;i<n;i++)
		{
		 cout<<"\n\tApplicant "<<i+1;
		 r[i].input();
		}
		break;

	case 2:	clrscr();
		cout<<"\n\t\t\t\tDetails entered"<<endl;
		 for(i=0;i<n;i++)
		{
		 cout<<"\tApplicant "<<i+1;
		 r[i].output();
		}
		break;

	case 3: clrscr();
	       char temp[20],a[20];
	       cout<<"\n\t\t\tRegistration Number Checking\n"<<"\n Enter registration number to be searched\n\n ";
	       cout<<"IN THE FORMAT: [(state's first 2 letters)  (first 4 digits of mobile number)]\n\n";
	       gets(a);
	       int flag=0;
		for(i=0;i<n;i++)
	       {
		strcpy(temp,r[i].regnum());
		 if(strcmpi(temp,a)==0)
		{
		 r[i].display();
		 flag=1;
		}
	       }
		if(flag==0)
		cout<<"\n Not a registered number\n";
		cout<<"\n\t\t***************************************\n\n";
	       break;

	case 4: int j;
	       rto t;
		for(i=0;i<n;i++)
	       {
		 for(j=0;j<2;j++)
		{
		  if(strcmpi(r[j].regno,r[j+1].regno)>0)
		 {
		  t=r[j];
		  r[j]=r[j+1];
		  r[j+1]=t;
		 }
		}
	       }
	       clrscr();
	       cout<<"\n\t\tRegistrant Details\n";
		for(i=0;i<n;i++)
			r[i].output();
	       break;
	case 5:return;
}
	cout<<"\nDo u wish to go back to main menu(Y/N)? : ";
		cin>>ch;
} while(ch=='y' || ch=='Y');
 getch();
}
