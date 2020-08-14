#include <stdio.h> 		//HEADER FILE USED FOR THE PROGRAM
#include <stdlib.h>		//HEADER FILE USED FOR THE PROGRAM
#include <string.h>		//HEADER FILE USED FOR THE PROGRAM
#include <windows.h>	//HEADER FILE USED FOR THE PROGRAM
#define Max_Airports 100	//DEFINE CONSTANT FOR THE MAXIMUM NUMBER OF AIRPORTS
#define Max_Planes 150		//DEFINE CONSTANT FOR THE MAXIMUM NUMBER OF PLANES
#define Max_Flights 1000	//DEFINE CONSTANT FOR THE MAXIMUM NUMBER OF FLIGHTS
#define Max_Flightpaths 100		//DEFINE CONSTANT FOR THE MAXIMUM NUMBER OF FLIGHT PATHS
#define Max_Passengers 1000		//DEFINE CONSTANT FOR THE MAXIMUM NUMBER OF PASSENGERS
#define AIRPORTS_FILE "Airport.txt"		//DEFINE FILE NAME FOR AIRPORTS
#define PLANES_FILE "Airplane.txt"		//DEFINE FILE NAME FOR AIRPLANES
#define Flights_FILE "Flights.txt"		//DEFINE FILE NAME FOR FLIGHTS
#define Flightpath_FILE "FlightPaths.txt"	//DEFINE FILE NAME FOR FLIGHT PATHS
#define PASSENGERS_FILE "Passengers.txt"	//DEFINE FILE NAME FOR PASSENGERS

void create_file();		//DEFINE FUNCTION FOR CREATING FILES.
void print_file();		//DEFINE FUNCTION FOR PRINTING FILES.
void read_file();		//DEFINE FUNCTION FOR READING FILES.
void Admin();			//DEFINE FUNCTION FOR ADMIN.
void Ticketagent();		//DEFINE FUNCTION FOR TICKET AGENT.
void Manager();			//DEFINE FUNCTION FOR MANAGER.
void flightpaths();		//DEFINE FUNCTION FOR FLIGHT PATHS.
void planes();			//DEFINE FUNCTION FOR PLANES.
void airports();		//DEFINE FUNCTION FOR AIRPORTS.
void passengers();		//DEFINE FUNCTION FOR PASSENGERS.
void flights();			//DEFINE FUNCTION FOR FLIGHTS.
void ViewSeating();		//DEFINE FUNCTION FOR DISPLAYING PLANE SEATING.
char seat_type();		//DEFINE FUNCTION FOR SEAT TYPE.
char *TimeDisplay();	//DEFINE FUNCTION FOR DISPLAYING TIME.
char *DateDisplay();	//DEFINE FUNCTION FOR DISPLAYING DATE.
char* Plane_Type(); 	//DEFINE FUNCTION FOR PLANE TYPE.
FILE *fp;				//DEFINE FILE.

struct seating			//DEFINE STRUCTURE FOR SEATING.
{
	int IDpassenger;	//INTEGER FOR PASSENGER ID.
	int checkseat; 		//INTEGER FOR CHECKING THE SEAT, WHEREBY 0=EMPTY, 1=BOOKED, 2=RESERVED.
	char *reserve_expire_date; 	//CHARACTER FOR RESERVING EXPIRY DATE.
};

struct flight			//DEFINE STRUCTURE FOR FLIGHT.
{
	int flightpathID;	//INTEGER FOR FLIGHTPATH ID.
	int planeID;		//INTEGER FOR PLANE ID.
	char *time;			//CHARACTER FOR TIME.
	char *date;			//CHARACTER FOR DATE.
	float price;		//FLOAT FOR PRICE.
	struct seating **seats;	//POINTS TO SEATS AND ASSIGNS IT TO SEATS.
};

struct flightpath		//DEFINE STRUCTURE FOR FLIGHTPATH.
{
	char flightpath_name[100];	//STRING FOR FLIGHTPATH NAME.
	int depart_airportID;		//INTEGER FOR DEPARTING AIRPORT ID.
	int arrive_airportID;		//INTEGER FOR ARRIVING AIRPORT ID.
};

struct airport			//DEFINE STRUCTURE FOR AIRPORT.
{
	char name[60];		//STRING FOR NAME WITH MAXIMUM OF 61 CHARACTERS.
};

struct passengers		//STRUCTURE FOR PASSENGERS.
{
	char firstname[50];	//STRING FOR PASSENGER FORENAME.
	char lastname[50];	//STRING FOR PASSENGER SURNAME.
	char DOB [5];		//STRING FOR PASSENGER DATE OF BIRTH.
};

int main()				//DECLARE FUNCTION FOR MAIN.
{
	struct airport *Airport[Max_Airports];	//STRUCTURE FOR AIRPORT DEFINED WITH A POINTER TO IT.
	struct flight *Flights[Max_Flights];	//STRUCTURE FOR FLIGHT DEFINED WITH A POINTER TO IT.
	struct flightpath *Path[Max_Flightpaths];	//STRUCTURE FOR FLIGHTPATH DEFINED WITH A POINTER TO IT.
	struct passengers *Passengers[Max_Passengers];		//STRUCTURE FOR PASSENGERS DEFINED WITH A POINTER TO IT.
	int *Planes[Max_Planes];				//INTEGER FOR PLANES, WITH 0=P62, 1=P124.
	int Airport_number, Plane_number,Flightpathnum, Passengernum,Flightsnum = 0;		//INTEGERS INITIALISED TO THE VALUE 0.	
	char fileopen;		//DECLARE VARIABLE FOR FILE OPEN.
	
	printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAY MESSAGE TO THE USER.
	printf("Database files:\n\nDo thefiles you wish to store the data in already exist?\n");		//ASKS THE USER FOR A RESPONSE.
	printf("Select 'Y' for yes or 'N' for no, if you wish to create a new file:\n");		//GIVES THE USER 2 OPTIONS TO CHOOSE TO INPUT.
	scanf("%c", &fileopen);		//THE INPUT IS SCANNED BY THE PROGRAM.
	fileopen = toupper(fileopen);	//UPPERCASE AND LOWERCASE CHARACTERS ARE ACCEPTED.		
	fflush(stdin);		//CLEARS THE BUFFER.
	
	if(fileopen == 'N')		//CONDITIONAL EXECUTION DEPENDING ON THE INPUT.
	{
		create_file();		//CALL THE CREATE FILE FUNCTION.
	}

	
	read_file(Airport, &Airport_number,Planes,&Plane_number, Flights,&Flightsnum,Path, &Flightpathnum,Passengers, &Passengernum);	//CALL THE READ FILE FUNCTION.
	system("cls");		//CLEARS THE COMMAND WINDOW.
	int role;	//DECLARING THE INTEGER ROLE.
	
	
	do	//ITERATIVE EXECUTION.
	{
		printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAYS MESSAGE TO THE USER.
		printf("Select your Job Title:\n1 Data Admin\n2 Ticket Agent\n3 Manager\n4 Exit\n");	//DISPLAYS THE OPTIONS TO THE USER.
		scanf("%d", &role);		//THE INPUT IS SCANNED BY THE PROGRAM.
		fflush(stdin);		//CLEARS THE BUFFER.		
 		system("cls");		//CLEARS THE COMMAND WINDOW.
 		printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAYS MESSAGE TO THE USER.
	
		if (role == 1)	//CONDITIONAL EXECUTION.
		{
			Admin();	//CALL THE ADMIN FUNCTION.
		}
	
		else if (role == 2)		//CONDITIONAL EXECUTION.
		{
			Ticketagent();		//CALL THE TICKET AGENT FUNCTION.
		}
	
		else if (role == 3)		//CONDITIONAL EXECUTION.
		{
			Manager();			//CALL THE MANAGER FUNCTION.
		}
		else if(role == 4)
		{
			return 0;
		}
	}
	while (role != '1' && role != '2' && role != '3' && role != '4');	//CONTINUES TO RUN UNTIL A VALID OPTION IS SELECTED.
}

void Admin()	//DEFINE THE FUNCTION FOR ADMIN.
{
	system("cls");		//CLEARS THE COMMAND WINDOW.
	int option;			//DECLARES THE INTEGER OPTION.
	int role;
	do		//ITERATIVE EXECUTION.
	{
		printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAY MESSAGE TO THE USER.
		printf("\n  Database Admin\n\n");	//DISPLAY MESSAGE TO THE USER.
		printf("Select an option:\n1 - Flights\n2 - Flightpaths\n3 - Planes\n4 - Airports\n5 - Passengers\n6 - Exit\n");	//DISPLAYS THE OPTIONS TO THE USER.
		scanf("%d", &option);		//THE OPTION IS SCANNED BY THE PROGRAM.
		fflush(stdin);		//CLEARS THE BUFFER.
		
		if(option == 1)		//CONDITIONAL EXECUTION.
		{
			flights();	
		}
		
		else if (option == 2)
		{
			flightpaths();
		}
	
		else if (option == 3)	//CONDITIONAL EXECUTION.
		{
			planes();			//CALLS THE PLANES FUNCTION.
		}
		
		else if (option == 4)	//CONDITIONAL EXECUTION.
		{
			airports();			//CALLS THE AIRPORTS FUNCTION.
		}
		
		else if (option == 5)	//CONDITIONAL EXECUTION.
		{
			passengers();		//CALLS THE PASSENGERS FUNCTION.
		}
			else if (option == 6)	//CONDITIONAL EXECUTION.
		{
			system ("cls");
				do	//ITERATIVE EXECUTION.
	{
		
		printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAYS MESSAGE TO THE USER.
		printf("Select your Job Title:\n1 Data Admin\n2 Ticket Agent\n3 Manager\n4 Exit\n");	//DISPLAYS THE OPTIONS TO THE USER.
		scanf("%d", &role);		//THE INPUT IS SCANNED BY THE PROGRAM.
		fflush(stdin);		//CLEARS THE BUFFER.		
 		system("cls");		//CLEARS THE COMMAND WINDOW.
 		printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAYS MESSAGE TO THE USER.
	
		if (role == 1)	//CONDITIONAL EXECUTION.
		{
			Admin();	//CALL THE ADMIN FUNCTION.
		}
	
		else if (role == 2)		//CONDITIONAL EXECUTION.
		{
			Ticketagent();		//CALL THE TICKET AGENT FUNCTION.
		}
	
		else if (role == 3)		//CONDITIONAL EXECUTION.
		{
			Manager();			//CALL THE MANAGER FUNCTION.
		}
		else if(role == 4)
		{
			
		}
	}
	while (role != '1' && role != '2' && role != '3' && role != '4');	//CONTINUES TO RUN UNTIL A VALID OPTION IS SELECTED.
}
	//CALLS THE PASSENGERS FUNCTION.
		}
	
	while(option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6');	//CONTINUES TO RUN UNTIL A VALID OPTION IS SELECTED.
}

void flightpaths(struct airport **Airports, int *Airport_number, struct flight *Flights[], struct flightpath **Path, int *Flightpathnum, int input)		//DEFINE THE FLIGHTPATHS FUNCTION.
{
	char flightpath_name2[100];		//STRING FOR FLIGHTPATH NAME DECLARED.
	int depart_airportID2;			//INTEGER FOR DEPARTING AIRPORT ID.
	int arrive_airportID2;			//INTEGER FOR ARRIVING AIRPORT ID.
	system("cls");					//CLEARS THE COMMAND WINDOW.
	int o;							//INTEGER O DECLARED.
	printf("Which option would you like?\n1 - View Flightpath\n2 - View Flightpaths\n3 - Add Flightpath\n4 - Exit");	//DISPLAYS THE OPTIONS TO THE USER.
	scanf("%d", &o);				//THE OPTION IS SCANNED BY THE PROGRAM.
	fflush(stdin);					//CLEARS THE BUFFER.
	
	if(o == 1)						//CONDITIONAL EXECUTION.
	{
		printf("%i: %s - %s to %s\n", input+1, Path[input]->flightpath_name, Airports[Path[input]->depart_airportID]->name, Airports[Path[input]->arrive_airportID]->name); 	//SELECTED FLIGHTPATH IS DISPLAYED TO THE USER.
	}

	else if (o == 2)				//CONDITIONAL EXECUTION.
	{
		printf("\n"); 				//PRINT ON NEW LINE.
  		int i;						//INTEGER I IS DECLARED.
    
		for (i=0; i<*Flightpathnum; i++)	//ITERATIVE EXECUTION.
    	{ 
    	    printf("%i: %s - %s to %s\n", input+1, Path[input]->flightpath_name, Airports[Path[input]->depart_airportID]->name, Airports[Path[input]->arrive_airportID]->name); 	//SELECTED FLIGHTPATH IS DISPLAYED TO THE USER.
    	} 
	}
		
	else if (o == 3)				//CONDITIONAL EXECUTION.
	{
		system("cls");				//CLEARS THE COMMAND WINDOW.
	    printf("\n\t\t\t~~ Triple E Airlines ~~\n"); 	//DISPLAYS MESSAGE TO THE USER.
        printf("\nAvailable flight paths are:\n");		//DISPLAYS OPTIONS TO THE USER.
  		printf("\n"); 				//PRINT ON NEW LINE.
  		int i;						//INTEGER I IS DECLARED.
    
		for (i=0; i<*Flightpathnum; i++)	//ITERATIVE EXECUTION.
    	{ 
    	    printf("%i: %s - %s to %s\n", input+1, Path[input]->flightpath_name, Airports[Path[input]->depart_airportID]->name, Airports[Path[input]->arrive_airportID]->name); 	//SELECTED FLIGHTPATH IS DISPLAYED TO THE USER.
    	} 
    
		printf("\nEnter name of new flight path:\n");	//ASKS THE USER TO ENTER THE NAME OF A NEW FLIGHT PATH.
    	scanf("%100s", &flightpath_name2);				//THE NAME IS SCANNED BY THE PROGRAM.
    	fflush(stdin);									//CLEARS THE BUFFER.	
   		printf("\nAvailable airports are:\n");			//DISPLAYS MESSAGE TO THE USER.
    	printf("\n"); 
 	
		for (i=0; i<*Airport_number; i++)//iterative execution displaying the airports 
    	{ 
    	    printf("%i: %s\n", input+1, Airports[input]->name);//displays the airport 
    	}
    
		printf("Choose departure airport:\n");			//ASKS THE USER TO ENTER THE DEPARTURE AIRPORT ID.
    	scanf("%i", &depart_airportID2);				//THE INPUT IS SCANNED BY THE PROGRAM.
    	fflush(stdin);									//CLEARS THE BUFFER.
    	depart_airportID2 -=1;							//INITIALISES THE VARIABLE.
    	printf("Choose arrival airport\n");				//DISPLAYS THE MESSAGE TO THE USER.
    	scanf("%i", &arrive_airportID2);				//THE INPUT IS SCANNED BY THE PROGRAM.
 		fflush(stdin);									//CLEARS THE BUFFER.
 		arrive_airportID2 -=1;							//INITIALISES THE VARIABLE.
    
    	Path[*Flightpathnum] = malloc(sizeof(struct flightpath));//saved this information into structure//memory size saved and pointed to the address
    	strcpy(Path[*Flightpathnum]->flightpath_name,flightpath_name2);//string copy the assigning value
    	Path[*Flightpathnum]->depart_airportID = depart_airportID2;//string copy the assigning value
    	Path[*Flightpathnum]->arrive_airportID = arrive_airportID2;//string copy the assigning value
    
		printf("\n"); 				//PRINT ON NEW LINE.
    
		for (i=0; i<*Flightpathnum; i++)	//ITERATIVE EXECUTION.
    	{ 
    	    printf("%i: %s - %s to %s\n", input+1, Path[input]->flightpath_name, Airports[Path[input]->depart_airportID]->name, Airports[Path[input]->arrive_airportID]->name); 	//SELECTED FLIGHTPATH IS DISPLAYED TO THE USER.
    	} 
    	
		(*Flightpathnum)++;//increments flightpathnum
	}
	else if (o==4)//if statement 
	{
	system ("cls");//clears screen
		Admin();//returns to admin function
	}
}

void planes(int **Planes, int *Plane_number, int input)	//DEFINES THE FUNCTION PLANES.
{
	system("cls");										//CLEARS THE COMMAND WINDOW.
	int o;												//INTEGER O IS DECLARED.
	printf("Which option would you like?\n1 - View  Plane\n2 - View Planes\n3 - Add Plane\n4 - Exit");		//THE OPTIONS ARE DISPLAYED TO THE USER.
	scanf("%d", &o);									//THE INPUT IS SCANNED BY THE PROGRAM.
	fflush(stdin);										//CLEARS THE BUFFER.
	
	if(o == 1)											//CONDITIONAL EXECUTION.
	{
		printf("%i: type %s\n", input+1, Plane_Type(Planes[input]));			//DISPLAYS TO THE USER THE PLANE TYPE AND NUMBER.	
	}

	else if (o == 2)									//CONDITIONAL EXECUTION.
	{
 	   int i; 											//INTEGER I IS DECLARED. 
 	   printf("\n"); 									//PRINTS NEW LINE TO THE USER.

   		for (i=0; i<*Plane_number; i++)//itterative execution, if the following conditions apply i increases by one and the planes are displayed
    	{ 
    	    printf("%i: type %s\n", input+1, Plane_Type(Planes[input]));	
    	} 
	}
		
	else if (o == 3)									//CONDITIONAL EXECUTION.
	{
 		int PTI;//declares the integer PTI (stands for plane type input)
 
		system("cls");//clears comand window
	    printf("\n\t\t\t~~ Triple E Airlines ~~\n"); 
 	
    	printf("\nNumber of available planes:\n"); 
    	
 		int i; 											//INTEGER I IS DECLARED. 
 		printf("\n"); 									//PRINTS NEW LINE TO THE USER.

   		for (i=0; i<*Plane_number; i++)//itterative execution, if the following conditions apply i increases by one and the planes are displayed
    	{ 
    	    printf("%i: type %s\n", input+1, Plane_Type(Planes[input]));	
    	} 
 
  	  	printf("\nWhich plane would you like to add?:\n1- P62\n2- P124\n"); //prints to the user
  	  	scanf("%i", &PTI);//inputs the ID 
  		fflush(stdin);//clears buffer 
	    PTI -= 1; 
	    Planes[*Plane_number] = malloc(sizeof(int));//// memory size of the array planes points to the memory address for the first byte of the block being returned
	    Planes[*Plane_number] = &PTI;//assigns the value to PTI 
	   
	    printf("%i: type %s\n", input+1, Plane_Type(Planes[input]));//prints to the user	
	    (*Plane_number) ++; // adds one to the plane number
	}	
	else if (o==4)//if statement 
	{
	system ("cls");//clears screen
		Admin();//returns to admin function
	}
}

void airports(struct airport **Airports, int input, int *Airport_number)
{
	system("cls");//clears screen
	int o;//declares integer 
	printf("Which option would you like?\n1 - View Airport\n2 - View Airports\n3 - Add Airport\n4 - Exit");//prints to the user
	scanf("%d", &o);//asks for user input
	fflush(stdin);//clears buffer
	
	if(o == 1)//if statement 
	{
		printf("%i: %s\n", input+1, Airports[input]->name);//displays the airport 
	}

	else if (o == 2)//if statement 
	{
    
		int i;//declares the integer i 
    	printf("\n"); //prints new line
 	
		for (i=0; i<*Airport_number; i++)//iterative execution displaying the airports 
    	{ 
    	    printf("%i: %s\n", input+1, Airports[input]->name);//displays the airport 
    	}
	}
		
	else if (o == 3)//if statement
	{
	    char AirportName_Input[50];		//DECLARE A STRING FOR THE INPUT OF AIRPORT NAMES WITH A MAX OF 51 CHARACTERS.
	    system("cls");		//CLEARS THE COMMAND WINDOW.
	    printf("\n\t\t\t~~ Triple E Airlines ~~\nThe following airports exist:\n"); 	
	    
		int i;//declares the integer i 
    	printf("\n"); //prints a new line
 	
		for (i=0; i<*Airport_number; i++)//iterative execution displaying the airports 
    	{ 
    	    printf("%i: %s\n", input+1, Airports[input]->name);//displays the airport 
    	}
	
	    printf("\nInsert a new airport name: "); 
	    gets(AirportName_Input);//inputs Airport Name 
	    fflush(stdin);//clears buffer 
	    Airports[*Airport_number] = malloc(sizeof(struct airport));//memory size is reserved and is pointed to the address of the first byte of the block that is returned 
	    strcpy(Airports[*Airport_number]->name, AirportName_Input);//string copy assigning value 
	    
		printf("%i: %s\n", input+1, Airports[input]->name);//displays the airport 
	    (*Airport_number) ++;//increments pointer 
	}
	else if (o==4)//if statement 
	{
	system ("cls");//clears screen
		Admin();//returns function
	}
	
}

void passengers(struct passengers **Passengers, int *Passengernum, int input)
{
	system("cls");
	int o;
	printf("Which option would you like?\n1 - View Passenger\n2 - Add Passenger\n3 - Exit");
	scanf("%d", &o);
	fflush(stdin);
	
	if(o == 1)
	{
		printf("%i: %s %s - DOB: %s\n", input+1, Passengers[input]->firstname, Passengers[input]->lastname, DateDisplay(Passengers[input]->DOB));//displays the passenger
	}

	else if (o == 2)
	{
	char DOB_input[5];//declares a string with max of 6 characters 
    char secondname_input[40];//declares a string with max of 41 characters 
    char firstname_input[40];//declares a string with max of 41 characters 
 
    system("cls"); 
    printf("\n\t\t\t~~ Triple E Airlines ~~\n"); 
    printf("\nEnter the forename of the passenger to be added:\n"); //Input First name of passenger 
    scanf("%50s", &firstname_input);//inputs first name 
    fflush(stdin);//clears buffer 
    printf("\nEnter the surname of the passenger to be added:\n");//Input Surname of passenger 
    scanf("%50s", &secondname_input);//inputs second name 
    fflush(stdin);//clears buffer 
    printf("\nNow please enter the date of birth of your passenger to be added, written as (ddmmyy): ");// Input DOB of passenger  
    scanf("%6s", &DOB_input);//inputs date of birth 
    fflush(stdin);//clears buffer 
    Passengers[*Passengernum] = malloc(sizeof(struct passengers));// Saves this information into the passenger structure////memory size is reserved and is pointed to the address of the first byte of the block that is returned 
    strcpy(Passengers[*Passengernum]->firstname, firstname_input);//string copy assigning value 
    strcpy(Passengers[*Passengernum]->lastname, secondname_input);//string copy assigning value 
    strcpy(Passengers[*Passengernum]->DOB, DOB_input);//string copy assigning value 
   
    printf("%i: %s %s - DOB: %s\n", input+1, Passengers[input]->firstname, Passengers[input]->lastname, DateDisplay(Passengers[input]->DOB));//displays the passenger
    (*Passengernum) ++;//increments 
	}	
	else if (o==3)
	{
	system ("cls");
	Admin();
	}
	
}

void Ticketagent(struct airport **Airports, int *Airport_number, int **Planes, int *Plane_number, struct flight *Flights[], int *Flightsnum, struct flightpath **Path, int *flightpathsNum, struct passengers **Passengers, int *Passengernum, int searchType, int input)
{
	system("cls");
    int a, b, i, book_or_reserve, choice, flightID, option;	//declares integer variables a, b, i, book_or_reserve, choice and flightID. 
    char reservationExpiry[10], first, second;	//declares a string which has a max of 11 characters, and two further variables for first and last name. 
 
	do 
	{ 
        printf("Please select an option:\n1 - Departing airport \n2 - Arrival airport \n3 - Date \n4 - Exit\n"); 
        scanf("%i", &choice);//user inputs the relevant number 
        fflush(stdin);//clears buffer 
        
		if (choice != 4)//if its 4 it exits the programme 
        { 
            int y, option;		//DECLARING THE INTEGER Y AND OPTION.
		   	char date[10];		//DECLARING A STRING TO CONTAIN A MAXIMUM OF 11 VALUES. 
		    system("cls");		//CLEARS THE COMMAND WINDOW.
			printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAYS THE MESSAGE TO THE USER.
 
		    switch(searchType)		//CONDITIONAL EXECUTION FOR SWITCH STATEMENT FROM THE TICKET AGENT FUNCTION.
		    { 
    		    case 1: 			//CASE 1 GIVES THE SAME INSTRUCTIONS AS CASE 2.
    		    case 2: 
        		    printf("\nHere are the available airports:\n"); 	//MESSAGE IS DISPLAYED TO THE USER.
        		    
					int i;//declares the integer i 
    				printf("\n"); 
 	
					for (i=0; i<*Airport_number; i++)//iterative execution displaying the airports 
    				{ 
    	    			printf("%i: %s\n", input+1, Airports[input]->name);//displays the airport 
    				}
    				
            		printf("\nChoose an airport:\n"); 			//MESSAGE IS DISPLAYED TO THE USER.
            		scanf("%i", &choice);		//THE AIRPORT NUMBER IS READ FROM THE INPUT OF THE USER.
            		fflush(stdin);		//THE BUFFER IS CLEARED. 		
            		choice -= 1; 	
            		break; 			//THE LOOP IS STOPPED.
 
        		case 3:				//
            		printf("\nType in the date to be looked up written as (ddmmyy):\n"); 
            		scanf("%6s", &date);	//THE PROGRAM READS THE INPUT FROM THE USER.
            		fflush(stdin);	//THE BUFFER IS CLEARED. 
            		break; 			//THE LOOP IS STOPPED.
            
        		default: 			//DEFAULT OPTION.
        		    break; 			//THE LOOP IS STOPPED.
    		}		 
 
    		system("cls"); 		//CLEARS THE COMMAND WINDOW.
 			printf("\n\t\t\t~~ Triple E Airlines ~~\n"); 		//DISPLAYS THE MESSAGE TO THE USER.
 			printf("\nHere are the flights matching your search:\n"); 		//MESSAGE IS DISPLAYED TO THE USER.
 	
 		   switch(searchType) 		//CONDITIONAL EXECUTION FOR SWITCH STATEMENT FROM THE TICKET AGENT FUNCTION.
 		   { 
    		    case 1: 
        		    for (y=0; y<*flightpathsNum; y++)		//ITERATIVE EXECUTION FOR DISPLAYING DEPARTURE AIRPORTS. 
            		{ 
                		if (Path[Flights[y]->flightpathID]->depart_airportID == choice)	//CONDITIONAL EXECUTION.
                		{ 
                    		printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price); 
                		} 	
            		} 
            	break; 		//THE LOOP IS STOPPED.
 
       			case 2: 
        		    for (y=0; y<*flightpathsNum; y++)		//ITERATIVE EXECUTION FOR DISPLAYING ARRIVAL AIRPORTS. 
        		    { 
        		        if (Path[Flights[y]->flightpathID]->arrive_airportID == choice)	//CONDITIONAL EXECUTION.
        		        { 
        		            printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price); 
        		        } 
        		    } 
        	    break; 		//THE LOOP IS STOPPED.
 
	        	case 3: 
	        	    for (y=0; y<*flightpathsNum; y++)		//ITERATIVE EXECUTION.
	        	    { 
	        	        if (strcmp(Flights[y]->date, date) == 0)	//CONDITIONAL EXECUTION COMPARING THE STRING.
	                	{ 
	                    	printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price); 
	                	}	 
	            	} 
            	break; 		//THE LOOP IS STOPPED.
 
    		    default : 		//DEFAULT CASE IF INVALID OPTION IS ENTERED BY THE USER.
        		    system("cls");		//CLEARS THE COMMAND WINDOW. 
            		printf("\nInvalid option selected. Try again.\n");		//DISPLAYS AN ERROR MESSAGE TO THE USER. 
    		} 
 
            printf("\nChoose which flight you want\n"); // Asks ticket agent to choose from displayed flights. 
            scanf("%i", &flightID);//user inputs the relevant number 
            fflush(stdin);//clears buffer 
            flightID -= 1; 
            ViewSeating(Flights, Planes, flightID);// Passes data to view seating function, and displays availble seats. 
            printf("\nWhich seat do you want to book?");// Asks ticket agent to choose from displayed seats. 
            printf("\nEnter in the x co-ordinate:\n"); 
            scanf("%i", &a);// Inputs x and y coordinates of desired seats. 
            fflush(stdin);//clears buffer 
            a--;//decrements 
 
            printf("\nEnter in the y co-ordinate:\n"); 
            scanf("%i", &b); 
            fflush(stdin);//clears buffer 
            b--;//decrements 
            printf("Please select an option:\n1 - Reserving a seat\n2 - Booking a ticket\n"); 
            scanf("%i", &book_or_reserve); // Asks ticket agents whether they want to reserve or book the saet. 
            fflush(stdin);//clears buffer 
 
            if (book_or_reserve == 1)// If they have chosen reservation they have to input a date. 
            { 
                printf("\nInsert the date requiring to be reserved 3 days in advance (ddmmyy):\n");
                scanf("%6s", &reservationExpiry);//inputs the date 
                fflush(stdin);//clears buffer 
            } 
 
            printf("\nPlease type the first initials of the customer's first and last name to search. For new passengers, enter 0 for both initials.");// Program asks the ticket to input the intials of the passenger. 
            printf("\nEnter the first initial of the forename: "); 
            scanf("%c", &first);//inputs first name 
            first = toupper(first);//changes every single letter that is inputted to a capital 
            fflush(stdin);//clears buffer 
            printf("\nEnter the first initial of the surname: "); 
            scanf("%c", &second);//inputs second name 
            second = toupper(second);//changes every single letter that is inputted to a capital 
            fflush(stdin);//clears buffer 
 
            printf("\n");//prints a line 
            for (i=0; i<*Passengernum; i++)// Searches passengers and displays all the passengers with those initails. 
            { 
                if (Passengers[i]->firstname[0] == first && Passengers[i]->lastname[0] == second)//if the initials are found then displays the passsengers 
                { 
                    printf("%i: %s %s - DOB: %s\n", input+1, Passengers[input]->firstname, Passengers[input]->lastname, DateDisplay(Passengers[input]->DOB));//displays the passenger
                } 
            } 
            printf("Viewing passenger;\nTo enter a new passenger, please enter 0\n"); // Asks the ticket agent to choose the correct passenger 
            scanf("%i", &i);                                         // or to add a passenger 
            fflush(stdin);//clears buffer 
            i--; 
 
            if (i == -1)//when C becomes less than 0 
            { 
        		char DOB_input[5];//declares a string with max of 6 characters 
   				char secondname_input[40];//declares a string with max of 41 characters 
   				char firstname_input[40];//declares a string with max of 41 characters 
 
 			  	system("cls"); 
			    printf("\n\t\t\t~~ Triple E Airlines ~~\n"); 
			    printf("\nEnter the forename of the passenger to be added:\n"); //Input First name of passenger 
	    		scanf("%50s", &firstname_input);//inputs first name 
	    		fflush(stdin);//clears buffer 
	    		printf("\nEnter the surname of the passenger to be added:\n");//Input Surname of passenger 
	    		scanf("%50s", &secondname_input);//inputs second name 
	    		fflush(stdin);//clears buffer 
	    		printf("\nNow please enter the date of birth of your passenger to be added, written as (ddmmyy): ");// Input DOB of passenger  
	    		scanf("%6s", &DOB_input);//inputs date of birth 
	    		fflush(stdin);//clears buffer 
	    		
	    		Passengers[*Passengernum] = malloc(sizeof(struct passengers));// Saves this information into the passenger structure////memory size is reserved and is pointed to the address of the first byte of the block that is returned 
	    		strcpy(Passengers[*Passengernum]->firstname, firstname_input);//string copy assigning value 
	    		strcpy(Passengers[*Passengernum]->lastname, secondname_input);//string copy assigning value 
	    		strcpy(Passengers[*Passengernum]->DOB, DOB_input);//string copy assigning value 
	   
	    		printf("%i: %s %s - DOB: %s\n", input+1, Passengers[input]->firstname, Passengers[input]->lastname, DateDisplay(Passengers[input]->DOB));//displays the passenger
	    		(*Passengernum) ++;//increments 
			}	
            
			i = (*Passengernum)-1; 
         
 
            if (book_or_reserve == 1)// Saves reservation date. 
            { 
                strcpy(Flights[flightID]->seats[b][a].reserve_expire_date, reservationExpiry);//adds the relevant letter to the grid 
            } 
            Flights[flightID]->seats[b][a].checkseat = book_or_reserve; 
            Flights[flightID]->seats[b][a].IDpassenger = i; 
            ViewSeating(Flights, Planes, flightID); 
    } 
}while(choice != 4); 
	
	printf("To seach flight press '1'.\nTo exit press '2':\n");
	scanf("%d", &option);
	fflush(stdin);
	
	if (option == 1)
	{
	int y, option;		//DECLARING THE INTEGER Y AND OPTION.
    char date[10];		//DECLARING A STRING TO CONTAIN A MAXIMUM OF 11 VALUES. 
    system("cls");		//CLEARS THE COMMAND WINDOW.
	printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAYS THE MESSAGE TO THE USER.
 
    switch(searchType)		//CONDITIONAL EXECUTION FOR SWITCH STATEMENT FROM THE TICKET AGENT FUNCTION.
    { 
        case 1: 			//CASE 1 GIVES THE SAME INSTRUCTIONS AS CASE 2.
        case 2: 
            
			printf("\nHere are the available airports:\n"); 	//MESSAGE IS DISPLAYED TO THE USER.
            int i;//declares the integer i 
    		printf("\n"); 
 	
			for (i=0; i<*Airport_number; i++)//iterative execution displaying the airports 
	    	{ 
	    	    printf("%i: %s\n", input+1, Airports[input]->name);//displays the airport 
	    	}
    
	        printf("\nChoose an airport:\n"); 			//MESSAGE IS DISPLAYED TO THE USER.
            scanf("%i", &choice);		//THE AIRPORT NUMBER IS READ FROM THE INPUT OF THE USER.
            fflush(stdin);		//THE BUFFER IS CLEARED. 		
            choice -= 1; 	
            break; 			//THE LOOP IS STOPPED.
 
        case 3:				
            printf("\nType in the date to be looked up written as (ddmmyy):\n"); 
            scanf("%6s", &date);	//THE PROGRAM READS THE INPUT FROM THE USER.
            fflush(stdin);	//THE BUFFER IS CLEARED. 
            break; 			//THE LOOP IS STOPPED.
            
        default: 			//DEFAULT OPTION.
            break; 			//THE LOOP IS STOPPED.
    } 
    system("cls"); 		//CLEARS THE COMMAND WINDOW.
 	printf("\n\t\t\t~~ Triple E Airlines ~~\n"); 		//DISPLAYS THE MESSAGE TO THE USER.
 	printf("\nHere are the flights matching your search:\n"); 		//MESSAGE IS DISPLAYED TO THE USER.
 
    switch(searchType) 		//CONDITIONAL EXECUTION FOR SWITCH STATEMENT FROM THE TICKET AGENT FUNCTION.
    { 
        case 1: 
            for (y=0; y<*Flightsnum; y++)		//ITERATIVE EXECUTION FOR DISPLAYING DEPARTURE AIRPORTS. 
            { 
                if (Path[Flights[y]->flightpathID]->depart_airportID == choice)	//CONDITIONAL EXECUTION.
                { 
                    printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price);
                } 
            } 
            break; 		//THE LOOP IS STOPPED.
 
        case 2: 
            for (y=0; y<*Flightsnum; y++)		//ITERATIVE EXECUTION FOR DISPLAYING ARRIVAL AIRPORTS. 
            { 
                if (Path[Flights[y]->flightpathID]->arrive_airportID == choice)	//CONDITIONAL EXECUTION.
                { 
                   printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price);
                } 
            } 
            break; 		//THE LOOP IS STOPPED.
 
        case 3: 
            for (y=0; y<*Flightsnum; y++)		//ITERATIVE EXECUTION.
            { 
                if (strcmp(Flights[y]->date, date) == 0)	//CONDITIONAL EXECUTION COMPARING THE STRING.
                { 
                   printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price);
                } 
            } 
            break; 		//THE LOOP IS STOPPED.
 
        default : 		//DEFAULT CASE IF INVALID OPTION IS ENTERED BY THE USER.
            system("cls");		//CLEARS THE COMMAND WINDOW. 
            printf("\nInvalid option selected. Try again.\n");		//DISPLAYS AN ERROR MESSAGE TO THE USER. 
    } 	
	}
	
	else if (option == 2)
	{
		exit(0);
	}
}

void Manager(int **Planes, int *Plane_number, struct flight *Flights[], int *Flightsnum, struct flightpath **Patg, struct airport **Airports)	//DEFINE THE FUNCTION FOR THE MANAGER.
{
	int a, b, c, taken_seats;	//DECLARING THE INTEGERS A, B, C, AND SEATS TAKEN.
	int P62, P124 =0;		//INITIALISES THE VARIABLES FOR THE P62 AND P124 PLANE TO BE 0.
    float sum_revenue =0;	//INITIALISES THE VARIABLE FOR THE SUM REVENUE TO BE 0. 
    system("cls");	//CLEARS THE COMMAND WINDOW SCREEN.
 	printf("\n\t\t\t~~ Triple E Airlines ~~\n");	//DISPLAYS TO THE USER THE MESSAGE ON THE COMMAND WINDOW.
	  
 	for (a=0; a<*Plane_number; a++)	//ITERATIVE EXECUTION FOR THE NUMBER OF PLANES.
    { 
        if (Planes[a]==0)	//CONDITIONAL EXECUTION.
        { 
            P62++;	//P62 CONTINUES TO INCREASE BY ONE.
        } 
        else	//CONDITIONAL EXECUTION.
        { 
            P124++;		//P124 CONTINUES TO INCREASE BY ONE.
        } 
    } 

    printf("\nThe total number of P62 planes in the company is %i.\n", P62); 	//DISPLAYS BACK TO THE USER HOW MANY P62 PLANES EXIST.
    printf("The total number of P124 planes in the company is %i.\n", P124); 	//DISPLAYS BACK TO THE USER HOW MANY P124 PLANES EXIST.

    for (a=0; a<*Flightsnum; a++)	//ITERATIVE EXECUTION FOR THE FLIGHT NUMBER.
    { 
        taken_seats = 0;	//SET THE NUMBER OF SEATS TAKEN TO BE 0.
        
		for (a =0; a<12; a++)	//ITERATIVE EXECUTION FOR THE NUMBER OF COLUMNS.
        { 
            for (b =0; b<4; b++) 	//ITERATIVE EXECUTION FOR THE NUMBER OF ROWS.
            {
                if (Flights[a]->seats[b][c].checkseat == 2) 	//CONDITIONAL EXECUTION.
                { 
                    taken_seats++;		//INCREASE THE NUMBER OF TAKEN SEATS BY 1 UNTIL THE ITERATIVE FORMULA HAS BEEN SATISFIED.
                } 
            } 
        } 
    //    printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nCost: %.2f\nSeats occupied: %i\nRevenue Generated: %.2f\n", a+1, date(Flights[a]->date), time(Flights[a]->time), Airports[Flightpaths[Flights[a]->flightpathID]->depart_airportID]->name, Airports[Flightpaths[Flights[a]->flightpathID]->arrive_airportID]->name, Flights[a]->price, taken_seats, Flights[a]->price * taken_seats); 
        sum_revenue += Flights[a]->price * taken_seats;		//THIS WILL ADD THE SUM REVENUE ON ITSELF UNTIL THE FINAL REVENUE HAS BEEN REACHED. 
	} 
    printf("\nThe total revenue total of every flight is %.2f\n", sum_revenue);		//		DISPLAYS TO THE USER TO SUM REVENUE TO 2 DECIMAL PLACES.
}

void read_file(struct airport **Airport, int *Airport_number,int **Planes,int *Plane_number, struct flight *Flights[],int *Flightsnum,struct flightpath **Path, int *Flightpathnum,struct passengers **Passengers, int *Passengernum)
{
	int i;//stores array by declaring a integer called i
//reading airports file
	int x;//stores values of x in integer
	int y;//stores values of y in integer
	
	if((fp=fopen(AIRPORTS_FILE, "rb")))//reads airport file allows the info on the file to be read and transfered to airport structure
	{
		fscanf(fp, "%i", Airport_number);//reads numbers in fles allows the program to find how many airports they are
		i=0;//sets x to 0
		
	while ((!feof(fp))&&(i<*Airport_number))//this loop uses feof which allows to read until end of file or if c value is less han the number at the top of file
	{
		Airport[i] = malloc(sizeof(struct airport));//reserves memory size and its pointed to the address of the first byte of block that is returned
	fscanf(fp, "%i\n", &Airport[i]->name);//reads whats in the file
	x++;//increments i until it reaches top number on file
	}
	fclose(fp);//closes the file
	}
	
	else
	{
		fprintf(stderr, "%s File unable to open.Exiting..\n",AIRPORTS_FILE);//program exits if the file doesnt open
		exit(-1);
	}
//reading planes file
	if((fp=fopen(PLANES_FILE, "rb")))//reads planes file allows the info on the file to be read and transfered to airport structure
	{
		fscanf(fp, "%i\n", Plane_number);//reads numbers in fles allows the program to find how many airports they are
		i=0;//sets i to 0
	
	while ((!feof(fp))&&(i<*Plane_number))//this loop uses feof which allows to read until end of file or if c value is less han the number at the top of file
	{
		Planes[i] = malloc(sizeof(int));//reserves memory size and its pointed to the address of the first byte of block that is returned
		fscanf(fp, "%i\n", &Planes[i]);//reads whats in the file
		x++;//increments x until it reaches top number on file
	}
	fclose(fp);//closes the file
	}
	
	else
	{
		fprintf(stderr, "%s File unable to open.Exiting..\n",PLANES_FILE);//program exits if the file doesnt open
		exit(-1);
	}
}

void print_files(struct airport **Airport, int *Airport_number,int **Planes,int *Plane_number, struct flight *Flights[],int *Flightsnum,struct flightpath **path, int *Flightpathnum,struct passengers **Passengers, int *Passengernum)
{
	
	int i;
	//WRITE TO AIRPORT FILE
	if((fp=fopen(AIRPORTS_FILE, "w")))
	{
		fprintf(fp, "%i\n", *Airport_number);
		for(i=0; i<*Airport_number; i++)
		{
			fprintf(fp, "%s/n", Airport[i]->name);
		}
	fclose(fp);
	}
	
	else
	{
		fprintf(stderr, "%s Sorry open file error. Exitting program..\n",AIRPORTS_FILE);
		exit(-1);
	}
	//WRITE TO PLANE FILE
	if((fp=fopen(PLANES_FILE, "w")))
	{
		fprintf(fp, "%i\n", *Plane_number);
		for(i=0; i<*Plane_number; i++)
		{
			fprintf(fp, "%i/n",Planes[i]);
		}
	fclose(fp);
	}
	else
	{
		fprintf(stderr, "%s Sorry open file error. Exitting program..\n",PLANES_FILE);
		exit(-1);
	}
	//write to flight file
	if((fp=fopen(Flights_FILE, "w")))
	{
		int x;
		int y;
		fprintf(fp, "%i\n", *Flightsnum);
	
		for(i=0; i<*Flightsnum; i++)
		{
			fprintf(fp, "%i\t%i\t%s\t%s\t%f", Flights[i]->flightpathID, Flights[i]->planeID, Flights[i]->date, Flights[i]->time, Flights[i]->price); 
            
			for (x=0; x<12; x++) 
            { 
                for (y=0; y<4; y++) 
                { 
                    //printf("\t%i\t%i\t%s", Flights[c]->Seats[x][y].passengerID, Flights[c]>Seats[x][y].seat_status, Flights[c]->Seats[x][y].reservation_expiry_date);//debugging 
                    fprintf(fp, "\t%i\t%i\t%s", Flights[i]->seats[x][y].IDpassenger, Flights[i]->seats[x][y].checkseat, Flights[i]->seats[x][y].reserve_expire_date); 
                } 
            } 
            fprintf(fp, "\n"); 
        } 
        fclose(fp);
    } 
    
	else 
    { 
    	fprintf(stderr,"%s Sorry open file error. Exitting program..\n",Flights_FILE);// Exit program if file doesn't open. 
    	exit(-1); 
    } 
    
	if((fp=fopen(PLANES_FILE, "w")))
	{
		fprintf(fp, "%i\n", *Plane_number);
	
		for(i=0; i<*Plane_number; i++)
		{
			fprintf(fp, "%i/n", Planes[i]);
		}
	fclose(fp);
	}

	else
	{
		fprintf(stderr, "%s Sorry open file error. Exitting program..\n",PLANES_FILE);
		exit(-1);
	}	
//flight path file 
	if((fp=fopen(Flightpath_FILE, "w")))
	{
		fprintf(fp, "%i\n", *Flightpathnum);
		
		for(i=0; i<*Flightpathnum; i++)
		{
			fprintf(fp, "%s\t%i\t%i\n", path[i]->flightpath_name, path[i]->depart_airportID, path[i]->arrive_airportID); 
		}
	
	fclose(fp);
	}
	
	else
	{
		fprintf(stderr, "%s Sorry open file error. Exitting program..\n",Flightpath_FILE);
		exit(-1);
	}	
//Passengers file
	if((fp=fopen(PASSENGERS_FILE, "w")))
	{
		fprintf(fp, "%i\n", *Passengernum);
	
		for(i=0; i<*Passengernum; i++)
		{
			fprintf(fp, "%s\t%i\t%i\n", Passengers[i]->firstname, Passengers[i]->lastname, Passengers[i]->DOB); 
		}
		fclose(fp);
	}
	
	else
	{
		fprintf(stderr, "%s Sorry open file error. Exitting program..\n",PASSENGERS_FILE);
		exit(-1);
	}	
}
//creates files for user
void create_file()
{
	{
	fp = fopen(AIRPORTS_FILE, "w");//opens file and writes 
	fprintf(fp, "%i\n",0);//prints to file
	fclose(fp);//closes file
	fp=fopen(PLANES_FILE, "w");//opens file and writes 
	fprintf(fp, "%i\n", 0);//prints to file
	fclose(fp);//closes file
	fp=fopen(Flights_FILE, "w");//opens file and writes 
	fprintf(fp, "%i\n", 0);//prints to file
	fclose(fp);//closes file
	fp=fopen(Flightpath_FILE, "w");//opens file and writes 
	fprintf(fp, "%i\n", 0);//prints to file
	fclose(fp);//closes file
	fp=fopen(PASSENGERS_FILE, "w");//opens file and writes 
	fprintf(fp, "%i\n", 0);//prints to file
	fclose(fp);//closes file
}
}

// this function displays the date of flight when the user vies the flight details
char* DateDisplay(char* input)
{
	 char *out; //character pointer variable for output
    out = malloc(9 * sizeof(char));  
    out[0] = input[0];
    out[1] = input[1]; 
    strcpy(&out[2], "/");
    out[3] = input[2]; 
    out[4] = input[3]; 
    strcpy(&out[5], "/");
    out[6] = input[4]; 
    out[7] = input[5]; 
    out[8] = '\0';
    return out;//returns the answers
}
//this function will allows the program to display the time of flight
char* TimeDisplay(char* input)
{
	char *out;//character pointer variable for output
    out = malloc(6 * sizeof(char));  
    out[0] = input[0];
    out[1] = input[1]; 
    strcpy(&out[2], ":"); 
    out[3] = input[2]; 
    out[4] = input[3]; 
    out[5] = '\0'; 
    return out; //returns the answers
}

void flights(struct airport **Airports, int **Planes, struct flight *Flights[], struct flightpath **Path, int input, int *Flightsnum, int *Flightpathnum, int *Airport_number,int *Plane_number)
{
	system("cls");		//clears screen								
	int o;			//declares int									
	printf("Which option would you like?\n1 - View  Flight\n2 - View Flights\n3 - Add Flight\n4 - Exit");	 // prints to the user
	scanf("%d", &o);	//asks for user input								
	fflush(stdin);	//clears buffer									
	
	if(o == 1)		// if statement									
	{
		
    printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price); 
	
	}

	else if (o == 2) // else if statement				
	{
 	system("cls");//clears screen 
	printf("\n\t\t\t****Triple E Airlines****\n"); // prints to the user 
	printf("\nAll flights in the database:\n");  // prints to the user
	int v; //declared int v
 
 	for (v=0; v<*Flightsnum; v++)//for loop for flights num
    { 
     printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price); 
    } 
	}
		
	else if (o == 3)									
	{
		int FlightpathID_Input,PlaneID_Input,x,y;//integer for flight , plane inputs
		float Price_Input;//float to store price of flight
		char time_input[10];//character varible to store time
		char date_input[10];//char variable to store date
	
		system("cls");//clears the screen
		printf("\n\t\t\t****Triple E Airlines****\n"); //prints statement to user
		printf("\nAvailable flight paths are:\n");//prints statement to user
		printf("%i: %s - %s to %s\n", input+1, Path[input]->flightpath_name, Airports[Path[input]->depart_airportID]->name, Airports[Path[input]->arrive_airportID]->name); 	//SELECTED FLIGHTPATH IS DISPLAYED TO THE USER.
		printf("Choose a flight path\n");//Asks user to choose a flight path
		scanf("%i", &FlightpathID_Input);//scans for user input 
		fflush(stdin);//clears the buffer 
		FlightpathID_Input -= 1;
	
		printf("\nAvalible planes are:\n");//avalible planes will be shown
		printf("%i: type %s\n", input+1, Plane_Type(Planes[input]));			//DISPLAYS TO THE USER THE PLANE TYPE AND NUMBER.	
		printf("\nChoose a plane\n");//Asks admin to choose a plan
		scanf("%i",&PlaneID_Input);//scans user input , until user inputs plane name
		fflush(stdin);//clears the buffer
		PlaneID_Input -=1;

		printf("Input price of flight:\n");//Asks user to input price of flight
		scanf("%f", &Price_Input);//allows user to add price for flight
		fflush(stdin);//clears the buffer 
	
		//Asking user for date and time
		printf("\nInput the date of the flight as shown, ddmmyy:\n"); //displays data to the user 
		printf("dd = day - e.g. 01, 02, 03, 04...,31.\n"); //displays data to the user 
		printf("mm = month - e.g. 01, 02, 03, 04....,12\n"); //displays data to the user 
		printf("yy = year - e.g. 01, 02, 03, 04....\n"); //displays data to the user 
		scanf("%6s", &date_input);//asks for user to input date
		fflush(stdin);//clears buffer 
		printf("\nInput the time of the flight as shown, hhmm:\n");//displays data to the user 
		printf("hh stands for the hours - e.g 01, 02, 03, 04..,24.\n"); //displays data to the user 
		printf("mm stands for the minutes - e.g 01, 02, 03, 04...,59.\n"); //displays data to the user 
		scanf("%4s", &time_input); //asks for user to input time
		fflush(stdin);//clears buffer 
	
		//Save everything in structure 
		Flights[*Flightsnum] = malloc(sizeof(struct flight));//memory size is reserved and is pointed to the address of the first byte 
    	Flights[*Flightsnum]->date = malloc(sizeof(char)*6);//memory size is reserved and is pointed to the address of the first byte 
    	Flights[*Flightsnum]->time = malloc(sizeof(char)*4);//memory size is reserved and is pointed to the address of the first byte 
    	
		strcpy(Flights[*Flightsnum]->time, time_input);//strcpy copies the text in address and gives a value from user input
    	strcpy(Flights[*Flightsnum]->date, date_input); //strcpy copies the text in address and gives a value from user input
    
    	Flights[*Flightsnum]->price = Price_Input;
		Flights[*Flightsnum]->flightpathID = FlightpathID_Input;//memory size is reserved and is pointed to the address of the first byte 
    	Flights[*Flightsnum]->planeID = PlaneID_Input;//memory size is reserved and is pointed to the address of the first byte 
    	Flights[*Flightsnum]->seats = (struct seating **)malloc(sizeof(struct seating *) * 12);//memory size is reserved and is pointed to the address of the first byte 
 		
		for (x=0; x<12; x++)// seat information being saved into the seat structure 
    	{ 
        	Flights[*Flightsnum]->seats[x] = (struct seating *)malloc(sizeof(struct seating) * 4);//memory size is reserved and is pointed to the address of the first byte
        	
			for (y=0; y<4; y++) 
        	{ 
            	Flights[*Flightsnum]->seats[x][y].reserve_expire_date = malloc(sizeof(char)*6);//memory size is reserved and is pointed to the address of the first byte
            	Flights[*Flightsnum]->seats[x][y].IDpassenger = 0;//initialises to 0 
            	Flights[*Flightsnum]->seats[x][y].checkseat = 0;//initialises to 0 
            	strcpy(Flights[*Flightsnum]->seats[x][y].reserve_expire_date, "000000");//gives the value of 000000 
        	} 
    	} 
    	
		system("cls");//clears screen
    	printf("\nFlight ID: %i\nDate: %s\nTime: %s\nFlight path: %s to %s\nPlane ID: %i(%s)\nCost: %.2f\n", input+1, DateDisplay(Flights[input]->date), TimeDisplay(Flights[input]->time), Airports[Path[Flights[input]->flightpathID]->depart_airportID]->name, Airports[Path[Flights[input]->flightpathID]->arrive_airportID]->name, Flights[input]->planeID+1, Plane_Type(Planes[Flights[input]->planeID]), Flights[input]->price);
		(*Flightsnum)++;//increments the pointer
	}	
	else if (o==4)//else if statement
	{
	system ("cls");//clears screen
		Admin();//returns to funtion
	}
	
}

// This function displays the plane type of the flight in the view flights function 
char* Plane_Type(int* input) 
{ 
    char *out;// Passes the selected plane inputted from another function. 
    if (input == 0)// This takes the choice and properly sets it out as the it 
    {      // should be. 
        out = malloc(4 * sizeof(char));//memory size is reserved and is pointed to the address of the first byte of the block that is returned 
        strcpy(&out[0], "P"); 
        strcpy(&out[1], "6");// This sets it out for the p62 plane 
        strcpy(&out[2], "2"); 
        out[3] = '\0';//End of string 
    } 
    else 
    { 
        out = malloc(5 * sizeof(char));//memory size is reserved and is pointed to the address of the first byte of the block that is returned 
        strcpy(&out[0], "P"); 
        strcpy(&out[1], "1");// This sets it out for the p124 plane 
        strcpy(&out[2], "2"); 
        strcpy(&out[3], "4"); 
        out[4] = '\0';//End of string 
    } 
    return out;//returns answers 
} 

void ViewSeating(struct flight *Flights[], int **Planes, int input) 	//DEFINE THE FUNCTION FOR DISPLAYING THE SEATING ARRANGEMENT OF EACH PLANE.	
{ 
    if (Planes[Flights[input]->planeID] == 0) 	//CONDITIONAL EXECUTION FOR THE P62 PLANE OPTION.
    { 
        printf("\n"); 	//SEATING PLAN FOR THE P62 PLANE, DISPLAYING WHICH SEATS ARE OCCUPIED.
        printf("     1   2   \n"); 
        printf("   |---|---|\n"); 
        printf("  1| %c | %c |\n", seat_type(Flights[input]->seats[0][0].checkseat), seat_type(Flights[input]->seats[0][1].checkseat)); 
        printf("   |---|---|\n"); 
        printf("  2| %c | %c |\n", seat_type(Flights[input]->seats[1][0].checkseat), seat_type(Flights[input]->seats[1][1].checkseat)); 
        printf("   |---|---|\n"); 
        printf("  3| %c | %c |\n", seat_type(Flights[input]->seats[2][0].checkseat), seat_type(Flights[input]->seats[2][1].checkseat)); 
        printf("   |---|---|\n"); 
        printf("  4| %c | %c |\n", seat_type(Flights[input]->seats[3][0].checkseat), seat_type(Flights[input]->seats[3][1].checkseat)); 
        printf("   |---|---|\n"); 
        printf("  5| %c | %c |\n", seat_type(Flights[input]->seats[4][0].checkseat), seat_type(Flights[input]->seats[4][1].checkseat)); 
        printf("   |---|---|\n"); 
        printf("  6| %c | %c |\n", seat_type(Flights[input]->seats[5][0].checkseat), seat_type(Flights[input]->seats[5][1].checkseat)); 
        printf("   |---|---|\n\n"); 
    } 
    
    else 	//CONDITIONAL EXECUTION FOR THE OTHER OPTION BEING THE P124 PLANE.
    { 
        printf("\n");	//SEATING PLAN FOR THE P124 PLANE, DISPLAYING WHICH SEATS ARE OCCUPIED.
        printf("     1   2   3   4 \n");
        printf("   |---|---|---|---|\n"); 
        printf("  1| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[0][0].checkseat), seat_type(Flights[input]->seats[0][1].checkseat), seat_type(Flights[input]->seats[0][2].checkseat), seat_type(Flights[input]->seats[0][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf("  2| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[1][0].checkseat), seat_type(Flights[input]->seats[1][1].checkseat), seat_type(Flights[input]->seats[1][2].checkseat), seat_type(Flights[input]->seats[1][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf("  3| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[2][0].checkseat), seat_type(Flights[input]->seats[2][1].checkseat), seat_type(Flights[input]->seats[2][2].checkseat), seat_type(Flights[input]->seats[2][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf("  4| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[3][0].checkseat), seat_type(Flights[input]->seats[3][1].checkseat), seat_type(Flights[input]->seats[3][2].checkseat), seat_type(Flights[input]->seats[3][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf("  5| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[4][0].checkseat), seat_type(Flights[input]->seats[4][1].checkseat), seat_type(Flights[input]->seats[4][2].checkseat), seat_type(Flights[input]->seats[4][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf("  6| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[5][0].checkseat), seat_type(Flights[input]->seats[5][1].checkseat), seat_type(Flights[input]->seats[5][2].checkseat), seat_type(Flights[input]->seats[5][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf("  7| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[6][0].checkseat), seat_type(Flights[input]->seats[6][1].checkseat), seat_type(Flights[input]->seats[6][2].checkseat), seat_type(Flights[input]->seats[6][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf("  8| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[7][0].checkseat), seat_type(Flights[input]->seats[7][1].checkseat), seat_type(Flights[input]->seats[7][2].checkseat), seat_type(Flights[input]->seats[7][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf("  9| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[8][0].checkseat), seat_type(Flights[input]->seats[8][1].checkseat), seat_type(Flights[input]->seats[8][2].checkseat), seat_type(Flights[input]->seats[8][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf(" 10| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[9][0].checkseat), seat_type(Flights[input]->seats[9][1].checkseat), seat_type(Flights[input]->seats[9][2].checkseat), seat_type(Flights[input]->seats[9][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf(" 11| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[10][0].checkseat), seat_type(Flights[input]->seats[10][1].checkseat), seat_type(Flights[input]->seats[10][2].checkseat), seat_type(Flights[input]->seats[10][3].checkseat)); 
        printf("   |---|---|---|---|\n"); 
        printf(" 12| %c | %c | %c | %c |\n", seat_type(Flights[input]->seats[11][0].checkseat), seat_type(Flights[input]->seats[11][1].checkseat), seat_type(Flights[input]->seats[11][2].checkseat), seat_type(Flights[input]->seats[11][3].checkseat)); 
        printf("   |---|---|---|---|\n\n"); 
    } 
} 

char seat_type(int input)//Character seat type function , to reserve and book seats
{
	switch(input)//switches between different inputs
	{
		case 0 :
			return ' ';//space means nothing booked
			
			break;//breaks
		case 1 :
			return 'R';// r means that the seat is reserved 
			break;//breaks
		case 2 :
			return 'B';//B means its booked
			break;//breaks
		default:
			return ' ';//space if not
			break;//breaks
	}
}
