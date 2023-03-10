/********************Clinic Management System********************/
/*	Author		:	Eslam_Hosny_Fahmy							*/
/*	Layer		:	APP											*/									
/*	Version		:	1.0											*/					
/*	Date		:	September  25, 2022							*/
/*	Last_Edit	:	N/A											*/			
/***************************Thank You****************************/
#include <stdio.h>
#include "STD_types.h"
#include "Final_Project.h"

#define Password 1234 

int main()
{
	s32 mode,pass,choice,num,try=0;
	List L;
	Create_List(&L);
	
	printf("=====================================================================\n\t\t");
	printf("   Welcome In Clinc Managment System\n");
	while(1)
	{
		printf("=====================================================================\n");
		printf("[1]- Admin Mode\n[2]- User Mode\n\nChoice :  ");
		mode=get_num_only();								//Choose The Wanted Mode Of USER_MODE or ADMIN_MODE.
		switch(mode)
		{
			case 1:
			do
			{
				printf("Enter Password :  ");				//Take The Password From The User (only 3-Times avilable if Password is Wrong).
				pass=get_num_only();
				if(pass==Password)
					break;
				printf("Wrong Password , You Have %d Tries Left !\n",3-try);
				try++;
			}while( try <= 3 );
			
			if(try <= 3 )							//When User Entered The Correct Password.
			{
				printf("\t\t======================================\n");
				printf(" \t\t  <<<<< Login Successfully ^_^ >>>>>\n");
				try=0;
				while(1)
				{
					printf("\t\t======================================\n");
					printf("\t\t\t[ Choose The Feature ]\n");
					printf("[1]- Add New Patient Record.\n[2]- Edit Patient Record.\n[3]- Reserve A Slot With The Doctor.\n[4]- Cancel Reservation.\n\nYour Choice :  ");
					choice=get_num_only();			//Choose The Wanted Feature In Admin Mode.
					switch(choice)
					{
						/*If The Entered Choice Not One Of The Features 
						If The User Enter Wrong Choice It Will Exit Of Feature Table*/
						default: printf("\t\t      <<<<< Wrong Choice ! >>>>>\n");	
						break;
						case 1:
							printf("\t\t======================================\n");
							printf(" \t\t  <<<<< ADD New Patient Record >>>>>\n");
							Add_Patient(&L);			//ADD New Patient In The List.
							break;
						case 2:
							printf("\t\t=======================================\n");
							printf(" \t\t    <<<<< Edit Patient Record >>>>>\n");
							Edit_Patient(&L);			//Modify Patient's Information.
							break;
						case 3:
							printf("\t\t======================================\n");
							printf(" \t\t     <<<<<  Reserve A Slot >>>>>\n");
							Reserv_Slot(&L);		//Reserve A Slot for A Patient.
							break;
						case 4:
							printf("\t\t======================================\n");
							printf(" \t\t    <<<<< Cancel reservation >>>>>\n");
							Cancel_Reservation(&L);	//Cancellation Of A Reservation.
							break;
						
					}									
					printf("\t\t======================================\n");
					printf("More Operations In Admin Mode\n1- Yes \n2- No\nYour Choice :  "); //Chech If There is Any Wanted Operations.
					num=get_num_only();
					if( 1==num)
						continue;
					else
						break;			
				}										// End of Admin Mode. 
			} 		
			else									//Access Denied Duo To Wrong Password After 3 Tryies .
			{
				 printf("\t\t      <<<<< Access Denied ! >>>>>");
				try=0; 
			} 
			break; 						// Break Of Admin Mode.
					
			case 2:							//In The Case Of User Mode.
				printf("\t\t======================================\n");
				printf(" \t\t <<<<< Welcome To User Mode ^_^ >>>>>\n");
				while(1)
				{
					printf("\t\t======================================\n");
					printf("\t\t\t[ Choose The Feature ]\n");
					printf("[1]-View Patient Record.\n[2]-View Today Reservations.\n\nYour Choice :  ");
					choice=get_num_only();			// Choosing The Wantede feature.
					switch(choice)
					{
						default:
						printf("\t\t      <<<<< Wrong Choice ! >>>>>\n");	//If The User Enter Wrong Choice It Will Exit Of Feature Table.
						break;
						case 1:
							printf("\t\t======================================\n");
							printf(" \t\t<<<<< View Patient Information >>>>>\n");
							Display_Patient(&L);		//Printing The Information Of The Patient.
							break;
						case 2:
							printf("\t\t======================================\n");
							printf(" \t\t  <<<<< View Reservations >>>>>\n");
							View_Reservations(&L);		//Printing Who Made A Reservation Before.
							break;
					} 
					printf("\t\t======================================\n");
					printf("More Operations In User Mode\n1- Yes \n2- No\nYour Choice :  ");	//Chech If There is Any Wanted Operations.			
					num=get_num_only();
					if( 1==num)
						continue;
					else
						break;
				}											//End Of User Mode.
				break; 
				default:
					printf("\n\t\t\t<<<<< Wrong Choice ! >>>>>\n");				//When User Enter Wrong Choice OF Admin Mode & User Mode.
					break;
		}										// End Case Of Admin And User.
		printf("\n=====================================================================\n");
		printf("Shut Down System \n1- Yes \n2- No\nYour Choice :  ");		//Ask For Exit Programm.
		num=get_num_only();
		if( 1==num )
			break;
		else if( 2==num )
			continue;
		
	}						//End Of Program.
	
	return 0;
}