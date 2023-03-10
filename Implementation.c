/********************Clinic Management System********************/
/*	Author		:	Eslam_Hosny_Fahmy							*/									
/*	Version		:	1.0											*/					
/*	Date		:	September  25, 2022							*/	
/*	Last_Edit	:	N/A											*/		
/***************************Thank You****************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "STD_types.h"
#include "Final_Project.h"

//Definition of  Available Slots for Patients.
u8 Av_S[6][30]={"2    Pm to 2:30 Pm" ,"2:30 Pm to 3    Pm" , "3    Pm to 3:30 Pm", "4    Pm to 4:30 Pm" , "4:30 Pm to 5    Pm" , "Not Reserved"};
u8 Ch_S[6]={0,0,0,0,0,0};

/*Initialization of  The List */
void Create_List(List *pl)
{
	pl->head=NULL;
}

/*Add New Node In The List*/
void Add_Patient(List *pl)
{
	s8 flag=0; 			  
	s32 id;
	ListNode *new=(ListNode*)malloc(sizeof(ListNode));
	ListNode *tmp=pl->head;
	
	printf("ID     :  ");
	id=get_num_only();
	if(NULL == tmp)							// Check if it is the first node in the list "List is Empty".
	{
		printf("Name   :  ");
		scanf("%s",new->name);
		printf("Age    :  ");
		new->age=get_num_only();
		printf("Gender :  ");
		scanf("%s",new->gender);
		new->ID=id;
		new->Res=5;
		printf("\nThe Patient's Information Is Recorded Successfully ^_^ \n");
	}
	else 											//Not Empty.
	{
		while(NULL != tmp)
		{
			if(id == tmp->ID)	 		 //Check if The Entered ID IS used Before.
			{
				flag++;
				break;
				}
			tmp=tmp->next;			//Move To Next Node.
		}
		if(flag>0)			
		{
			printf("Id Already Exists\n");
		}
		else									//Inserting The Information Of  The Patient.
		{
			printf("Name   :  ");
			scanf("%s",new->name);
			printf("Age    :  ");
			new->age=get_num_only();
			printf("Gender :  ");
			scanf("%s",new->gender);
			new->ID=id;
			new->Res = 5 ;			 //The Patient Not Reserve Any Slots Yet.
			printf("\nThe Patient's Information Is Recorded Successfully ^_^ \n");
    	}	
	}
		new->next= pl->head;	//Connect The New Node With The List && The Head  Will Still The Last Node Added.
		pl->head = new;	
}

/* Edit Information Of Patient*/
void	Edit_Patient(List *pl)
{
	s8 flag=0; 			  
	s32 id;
	ListNode *tmp = pl->head;
	
	if(NULL == tmp) 										//Check If The List Is Empty.
		printf("No Clients in Systems Yet !\n");	
	else
	{
		printf("Enter The Id To Edit : ");
		id=get_num_only(); 
		while (NULL != tmp)						//Loop To Find The Wanted ID "Node".
		{
			if (id == tmp->ID)
			{
				flag++;
				break;
			}
			tmp=tmp->next;						//Move To Next Node.
		}
		if(flag>0)										//Apply The New Information.
		{
			printf("Name   :  ");
			scanf("%s",tmp->name); 
			printf("Age    :  ");
			tmp->age=get_num_only();
			printf("Gender :  ");
			scanf("%s",tmp->gender);
		}
		else
			printf("Incorrect ID !\n");
	}
	
}

/*Reserve A Slot With The Doctor*/
void Reserv_Slot(List *pl)
{	
	s32 id;
	s8 flag=0; 
	u8 test=0 , resv=0;
	ListNode * tmp = pl->head;
	
	if(pl->head==NULL)
		printf("No Clients in Systems Yet !\n");	
	else
	{
		printf("Enter The Id To Reserve :  ");
		id=get_num_only();
		while ( tmp != NULL)
		{	
			if ( id==tmp->ID)						//Check If The Entered ID is Exist or Not.
			{
				flag++;
				break;
			}
			tmp=tmp->next;							//Move To Next Node.
		}
		
		if( flag > 0)
		{
			if (tmp->Res!=5)						//Check If The Patient Reserve any Slot Befor.
			{
				printf("This Patient is Already Reserved A Slot [ Cancel It First ] !\n");
				return;
			}
			else
			{
				for (u8 i=0 ; i < 5 ; i++ )		//Checking And Printing The Available Slots For The Patient In Current Day.
				{
					if( 0==Ch_S[i] )
						printf("%d- %s\n",i+1,Av_S[i]);
					else
					{
						test++;
					}
				}
				if(test>=5)							//The All Slots Are Reserved Before.
				{
					printf("\nSorry No Availble Reservetions -_- !\n");
					return;
				}
				else
				{
					printf("\nYour Choice :  ");
					resv=get_num_only();			//Take The Wanted Slot To Reserve.
				}
				if( (resv > 0 && resv <= 5) && (Ch_S[resv-1]!=1))
				{
					tmp->Res = resv-1;			//Store The Last Index Of Reserved Slot.
					Ch_S[resv-1]=1;
				}
				else
					printf("Wrong Choice ( Not Available )!\n");
			}
		}
		else
			printf("Incorrect ID !\n");

	}
	
}

/* Cancel Reservetions */
/*The Admin Cancel A Reservation By Entering The Patient ID*/
void Cancel_Reservation(List *pl)
{
	s32 id;
	ListNode* tmp = pl->head;
	s8 flag=0; 

	if(NULL == tmp)
		printf("No Clients in Systems Yet !\n");	
	else
	{
		printf("Enter The Id To Cancel Reserve :  ");
		id=get_num_only();
		while ( tmp != NULL)				//Check If The Entered ID is Exist or Not.
		{
			if ( id==tmp->ID )
			{
				flag++;
				break;
			}
			tmp=tmp->next;						//Move To next Node.
		}
	
		if( flag > 0)
		{
			if( 1==Ch_S[tmp->Res] )		//Check The Reservation Of The Selected Node "Is Reserved Or Not".
			{
				printf("Your Reservetion: ( %s ) Is Cancelled \n",Av_S[tmp->Res]);
				Ch_S[tmp->Res]=0;
				tmp->Res = 5;
			}	
			else
			{
				printf("This ID Didn't Reseverd Yet !\n");		//The Patient Already Not Reserved.
			}
		
		}
		else
			printf("Incorrect ID !\n");
	}	
}

/*Show The Basic Information for The Patient*/
void   Display_Patient(List *pl)
{
	s8 flag=0;
	s32 id;
	ListNode* tmp = pl->head;
	
	if(NULL == tmp) 
		printf("No Clients in Systems Yet !\n");	
	else
	{
		printf("Enter The Id : ");
		id=get_num_only();
		while(NULL != tmp)					//Check If The Entered ID is Exist or Not.
		{
			if(id == tmp->ID )  				//Printing The Patient Information.
			{
				printf("Name   : %s \n",tmp->name);
				printf("Age    : %d \n",tmp->age);
				printf("Gender : %s \n",tmp->gender);
				flag=1;
			} 
			tmp = tmp->next; 			//Move To Next Node.
		}
		if( flag != 1) 
			printf("Id Not In The System !\n");
		}
}

/*Print All Reservations With The Patient ID Attached To Each Reservation Slot*/
void	View_Reservations(List *pl)
{	
	u8 i = 0 ; 
	ListNode *tmp = pl->head;
	
	if( NULL==tmp) 
		printf("No Clients In Systems !\n");
	else
	{
		while(tmp != NULL)
		{
			if( 1==Ch_S[tmp->Res] )			//Just Print The Patients Who Reserve A Slot.  
			{
				i++;
				printf("%d- ID: %d  %s ( %s ) \n", i , tmp->ID , tmp->name , Av_S[tmp->Res]);
			}
			tmp = tmp->next; 
		}
	}

}

s32 get_num_only()								//Function To get only Numbers For Password.
{
	s32 num=0;
	u8 ch , Enter =13 , Tab =9 ,BckSpace=8;
	do
	{
		ch=getch();
		if((ch==Enter || ch ==Tab) && num!=0)		//If User Press Enter Key or Tab Key.
			break;
		if(ch>=48 && ch <=57)
		{
			printf("%c",ch);
			num=num*10+(ch-48);
		}
		else if(ch==BckSpace)				//If User Press BackSpace.
		{
			printf("\b \b");
			num=num/10;			//Remove Last Entered Number.
		}
	}
	while(1);
	printf("\n");
	return num;
}

