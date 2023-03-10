/********************Clinic Management System********************/
/*	Author		:	Eslam_Hosny_Fahmy							*/									
/*	Version		:	1.0											*/					
/*	Date		:	September  25, 2022							*/
/*	Last_Edit	:	N/A											*/			
/***************************Thank You****************************/
#ifndef  _CLINIC_
#define _CLINIC_

#define SIZE		100
#define SizeGen 	10 
typedef struct listnode			//Initialization Of Structure For Storing Information.
{		
	
	u8 	name[SIZE];		
	u8		age;
	u8		gender[SizeGen];
	s32	ID;
	u8		Res;	
	struct listnode *next;
}ListNode;

typedef struct list			//Initialization Of List TO Access The Structure.
{
	ListNode *head;
}List;

/*Prototypes of Functions For The Features */
void Create_List(List *pl);
void Add_Patient(List *pl);
void	Edit_Patient(List *pl);
void Reserv_Slot(List *pl);
void Cancel_Reservation(List *pl);
void Display_Patient(List *pl);
void	View_Reservations(List *pl);
s32 get_num_only();				//Function That Takes Only Numbers

#endif
