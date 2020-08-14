#include<stdio.h>/*Type of library for the program, holds the information for the code */
#include<conio.h>/*Type of library for the program, holds the information for the code */
#include <stdlib.h>/*Type of library for the program, holds the information for the code */
#define row 5 // assigns value of 5 for the keyword (row) 
#define col 5 // assigns value of 5 for the keyword (col) 

void board (char grid [row] [col]); //declares function for board
void compostion (char grid[row][col], char playertoken, char comtoken);//declares function for computer position
int checkwin(char grid [row] [col],char token);//checks winner function which is declared
int boardposition (char grid [row] [col], int playerturn,char token);//declares function board postion

int main ()// main part of program which holds all the infomation together 
{
	char grid[row][col]={	// makes the game board clear , as without this the game board has random characters inside the boxes
	{' ',' ',' ',' ',' '},// declares whats in char grid
	{' ',' ',' ',' ',' '},// declares whats in char grid
	{' ',' ',' ',' ',' '},// declares whats in char grid
	{' ',' ',' ',' ',' '},// declares whats in char grid
	{' ',' ',' ',' ',' '}// declares whats in char grid
};
	char gamemode;	// character function for gamemode type - singleplayer or multiplayer 
	int win = 0; // int function holds value for win
	int playerturn; // int function stores value for playersturn
	char token;// character function helps display noughts and crosses 
	int winner;// integer function for winner 
	
 printf("\t------------------------------------\n");// printf statement 
 printf("\t   |Tic-Tac-Toe Game|\n");// printf statement  intro to the game , states what the game is to the user
 printf("\t------------------------------------\n");// printf statement 
 printf("Do you want to play single player or multiplayer?\n"); // printf statement asking the user what to input
 printf("Please enter 's' for single player or 'm' for multiplayer:\n");// printf statement  asking the user for singleplayer or multiplayer option

 scanf("%c",&gamemode);// scanf looking for a user input for the game mode
 fflush(stdin);// clears buffer
 gamemode = tolower(gamemode);// allows the user to input capitals
 
 while (gamemode != 's'&& gamemode != 'm')//while statement which helps if user inputs a incorrect statement
 {
 	printf("Invalid character\nSingleplayer = S OR Multiplayer = M \nPlease input 's'or 'm' for game mode\n");// prints statement to user addressing that they input an invalid character
 	scanf("%c",&gamemode);//scans for user input again
 	fflush(stdin);//clears buffer
}
 if (gamemode == 's')// if statement for gamemode once the user has inptut their gamemode option 
 {
 	printf("\t Singleplayer Mode");// prints the title of what gamemode the user wanted
	char comtoken,playertoken;// character function computer and player sign
	int turn;// int function for player turn first or second
	
	printf("\nChoose First (1) or Second(2)");// printf statement for players choice of turn
	scanf("%d",&playerturn);// scans for player input
	fflush(stdin);//clears buffer
	int winner=0;//integer for winner equalling 0 
 
	if(playerturn== 1)// if statement for the condition when user inputs f then the if loop happens
	{
		playertoken='X';//assigns the player to 'X' 
		comtoken='O';//assigns the computer to 'O'
		turn=1;//turn is assigned to 1 , since the user has chosen first turn
	}
	else 
	if(playerturn == 2)//if statement for the condition when the user inputs S
	{
		comtoken='X';//assigns the computer to 'X'
		playertoken='O';//assigns the player to 'O'
		turn=2; //turn is assigned to 2 , since the user has chosen second turn
	}
	do // do statement once the user has selected their turn
 	{
 		if (turn==1)// if statment for player 1
		 {
 		board(grid);// board function to print baord to user 
 		boardposition(grid,turn,playertoken);//board position allows the user to input the charcter token
 		winner = checkwin(grid,playertoken);//checkwin function equal to winner
 		board(grid);//prints board again once the user has input their loction
 		
		if (winner==1)//if statemenet for winner which was declared as the checkwin function
 		{
 			board(grid);//prints board again (board wasnt printing without this inside the if statement)
			printf("Winner is Player %d",playerturn);//prints to the user the winner 
		 }
		else if (winner==-1)//else statement if the game is a draw (board is full)
		{
			board(grid);//prints board again (board wasnt printing without this inside the if statement)
			printf("Draw");//prints out to the user that the game is a draw
		}
		else // else statement
		{
			winner = 0;//winner equals 0 allows the checkwin to run
			board(grid);//prints board again (board wasnt printing without this inside the if statement)
			turn++;// increments turn 
		}
		 }	 
		else if (turn==2)// if statment for turn 2 this is the computers turn
	{
		// token is given a character value (O) this will be assigned to player one
 		board(grid);// board function to print baord to user 
 		compostion (grid,playertoken,comtoken);//function for computer position in turn 2
 		winner = checkwin(grid,comtoken);//checks to see the win condition
 		board(grid);//prints board again once the user has input their loction

		 if (winner==1)//if statement for winner
 		{
 		board(grid);//prints board again (board wasnt printing without this inside the if statement)
		 	printf("Winner is Player %d",playerturn);//prints out to the user that the game has been won
		 }
		else if (winner==-1)//else if statement for winner -1 = draw
		{
			board(grid);//prints board again (board wasnt printing without this inside the if statement)
			printf("The game has reached a Draw");//prints out to the user that the game is a draw
		}
		else //function for else 
		{
			winner = 0;//winner equals 0 allows the checkwin to run
			board(grid);//prints board again (board wasnt printing without this inside the if statement)
			turn--;// decrement playerturn
		}
 		
	}
}
	while (winner==0);//while do statement while winner == 0 the game is in progress and until the do loop
}

 if (gamemode == 'm')//if statement for the second gamemode 
 {
 	printf("\t Multiplayer Mode");// prints title of gamemode
 	printf("\nSelect who wants to go first\n'X' Player 1 \n'O' Player 2\nType 1 for First or 2 for Second\n");//asks user if they want to play first or second
	scanf("%d",&playerturn);//scans for user input 

	int winner = 0;//integer winner initialised =0
	if(playerturn != '1'&& playerturn != '2')
	{
	
	printf("\nYou entered an invalid co-ordinate\n");//happens when an invalid co-ordinate is added
	printf("\nSelect who wants to go first\n'X' Player 1 \n'O' Player 2\nType 1 for First or 2 for Second\n");//asks user if they want to play first or second
	scanf("%d",&playerturn);//scans for user input 
	fflush(stdin);
}
 	do // do statement once the user has selected their turn
 	{
 		
	 	if (playerturn==1)// if statment for player 1
		 {
		token='X';// token is given a character value (X) this will be assigned to player one 
 		board(grid);// board function to print baord to user 
 		boardposition(grid,playerturn,token);//board position allows the user to input the charcter token
 		winner=checkwin(grid,token);//winner initialised to checkwin function / clears the brackets 
 		board(grid);//prints board again once the user has input their loction
 		
		if (winner==1)//if statement for the checkwin function which is winner once its equal to 1 then the game stops and the winner is announced
 		{
 			printf("Winner is Player %d",playerturn);//prints to the user the winner 
		 }
		else if (winner==-1)//else if statment to show that once the value is -1 then the game is a draw
		{
			printf("The game has reached a Draw");//prints to the user the game is a draw
		}
		else//else if the game is in progress and winner = 0
		{
			winner = 0;//winner equals 0 game in progress
			playerturn++;//player increments 
		}
	}
		 
		if (playerturn==2)// if statment for player 2
		 {
		token='O';// token is given a character value (O) this will be assigned to player one
 		board(grid);// board function to print baord to user 
 		boardposition(grid,playerturn,token);//board position allows the user to input the charcter token
 		winner=checkwin(grid,token);//winner function is made to equal the checkwin
 		board(grid);//prints board again once the user has input their loction
 		
		 if (winner==1)//if statment for winner condition if 1 then the game is won
 		{
 			printf("Winner is Player %d",playerturn);//prints to user the winner 
		 }
		else if (winner==-1)//else if winner is -1 then the game is a draw
		{
			printf("Draw");// prints statment as draw
		}
		else //else if for game in progress
		{
			winner = 0;//winner is equal to 0 if the statments are not met
			playerturn--;// decrement playerturn
		}
 
	}

}
	while (winner==0);//while do statement while winner == 0 the game is in progress and until the do loop
}

}

void board (char grid [row] [col])// board function to print out the game board
{
system("cls");//system to clear the board so the game doesnt spam with gameboards

	printf("\n");//print the grid
 	printf("   1   2   3   4   5 \n");//print the grid
 	printf(" |---|---|---|---|---|\n");//print the grid
 	printf("1| %c | %c | %c | %c | %c |\n", grid[0][0], grid[0][1], grid[0][2], grid[0][3],grid[0][4]);//print the grid
 	printf(" |---|---|---|---|---|\n");//print the grid
 	printf("2| %c | %c | %c | %c | %c |\n", grid[1][0], grid[1][1], grid[1][2], grid[1][3],grid[1][4]);//print the grid
 	printf(" |---|---|---|---|---|\n");//print the grid
 	printf("3| %c | %c | %c | %c | %c |\n", grid[2][0], grid[2][1], grid[2][2], grid[2][3],grid[2][4]);//print the grid
 	printf(" |---|---|---|---|---|\n");//print the grid
 	printf("4| %c | %c | %c | %c | %c |\n", grid[3][0], grid[3][1], grid[3][2], grid[3][3],grid[3][4]);//print the grid
 	printf(" |---|---|---|---|---|\n");//print the grid
 	printf("5| %c | %c | %c | %c | %c |\n", grid[4][0], grid[4][1], grid[4][2], grid[4][3],grid[4][4]);//print the grid
 	printf(" |---|---|---|---|---|\n");//print the grid
 	printf("\n");//print the grid
 }

int boardposition (char grid [row] [col], int playerturn,char token)//board position function allows the user to input co-ordiantes 
{
int rowposition , colposition;// stores the values for row and col 
printf("\n Player %d turn:",playerturn);//prints to user the players turn
printf("\nEnter Row:\n");//asks the user to input row
scanf("%d", &rowposition);//scans for user input for the row and stores the value
fflush(stdin);//clears buffers
printf("\nEnter Column:\n");//asks the user to input column
scanf("%d", &colposition);//scans for user input for the column and stores the value
fflush(stdin);//clears buffers	

if(grid[rowposition-1][colposition-1]== ' ' && rowposition>=1 && rowposition<=5 && colposition>=1 && colposition<=5)//if statments for the grid position
		{
			grid[rowposition-1][colposition-1] = token;// makes sure the position is inside the grid and makes sure the grid is empty 
		}
		else //else if the grid has an x or o then invalid co ordiante is printed to the user
		{
		printf("\nInvalid co-ordinate\n");// invalid co-ordinate 
		boardposition (grid, playerturn,token);//restarts the board position asking the user to input row and column again
		}
}

int checkwin(char grid [row] [col],char token)//checkwin function which will check and stop the program
{
	int x, y, i = 0;//initialises the variables and makes i = 0
	for (x=0; x<row; x++)//runs the following for rows
	{
		for (y=0; y<col; y++)//runs the following for columns
		{
			if (grid[x][y] == token)//runs if statement for grid and making it equalequal token	//checks rows
			{
				i = i+1;// the value is now i+1 which was the privious value.
			}
		}
		if (i==5)//if statment for i == 5 basically if the value of i reaches 5 then the game ends 
		{
			return 1;//function returns 1
		}
		else // else if 
			i=0;//i =0 the game constantly runs
	}
	for (y=0; y<col; y++)//for loop for the number for columns 
	{//i =0 the game constantly runs
		for (x=0; x<row; x++)//runs for the rows
		{
			if (grid[x][y] == token) //runs if statement for grid and making it equalequal token			//checks columns
			{
				i = i+1;// the value is now i+1 which was the privious value
			}
		}
		if (i == 5)//if statment for i == 5 basically if the value of i reaches 5 then the game ends
		{
			return 1;//function returns 1
		}
		else // else if 
			i=0;//i =0 the game constantly runs
	}
	for (x=0; x<row; x++)//runs the following for number of rows
	{
		if (grid[x][x] == token)//runs if statement for grid and making it equalequal token
		{
			i = i + 1; 	// the value is now i+1 which was the privious value	//check diagonal - left to right
		}
		if (i==5)//if statment for i == 5 basically if the value of i reaches 5 then the game ends
		{
			return 1;//function returns 1
		}
	}
		i=0;//i =0 the game constantly runs
	
	for (x=0; x<row; x++)//runs the following for number of rows
	{
		if (grid[x][4-x] == token)//runs if statement for grid and making it equalequal token	//check diagonal - right to left
		{
			i = i + 1;// the value is now i+1 which was the privious value
		}
		if (i == 5)//if statment for i == 5 basically if the value of i reaches 5 then the game ends
		{
			return 1; //function returns 1
		}
	}
	i = 0;//i =0 the game constantly runs

	for (x=0; x<row; x++)//runs the following for number of rows
	{
		for (y=0; y<col; y++)//for loops for columns 
		{
			if (grid [x][y] != ' ') //runs the following statement 	//checks if all full - draw
			{
				i = i+1;// the value is now i+1 which was the privious value
			}
		}
	}
	if (i==25)//if the value reaches exactly 25 then function returns -1
	{
		return -1;//reutrns -1
	}
	else//else if 
		return 0;// game im progress return 0.

 }
//return 1 = win 
//return -1 = draw
//return 0 = game still in progress
			
void compostion (char grid[row][col], char playertoken, char comtoken)// singleplayer function this makes computer function
{
int x,y;//initializes integer x, y
char turn;//char variable for turn which will store the value 

while (x<=4 && turn==0 )//while loop for when x<=4 and turn == 0
{
	y=0;//making y equal 0			
	
	while (y<=4 && turn==0)//While loop for when y<-4 and turn ==0
	{
		if (grid[x][y] = ' ')//if loop for checking if the board is blank
		{
			grid[x][y] = comtoken;//making grid equal computer token
		if(checkwin(grid,comtoken)==1)//if statment for checkwin function when it equals 1
		{
			turn =1;// turn equalling 1
			
		}
		else//else if 
		{
			grid[x][y] = ' ';//makes grid =' ' 
		}
		}
		y++;//increments y++
	}
x++;//increments x++
}
x=0;//makes x = 0 after the top loop as ran

y=0;//makes y = 0 after the top loop as ran
while (x<=4 && turn==0)//While loop for when y<-4 and turn ==0// blocks user from winning the game
{
	y=0;//makes y=0
	
while(y<=4 && turn==0)//while loop
	{
		if(grid[x][y]==' ')//if loop to check grid is blank
		{
			grid[x][y]=playertoken;//grid = platertoken
		if(checkwin(grid,playertoken)==1)//if loop to checkwin playertooken
			{
			
turn=1;//when turn equal 1 
			grid[x][y]=comtoken;//place computer token to stop player winning
			}
		else//else if 
		{
		grid[x][y]=' ';//grid=blank 
		}
	}
	y++;//increment of y++
	}
	x++;//increments x++
}	
while(turn==0)//while loop for while game is running and the above functions arnt met then this loop runs placing random tokens in board.
{
srand(time(NULL));//makes the computer completly random	
x=rand() % 5;//rand function which makes the computer randomly place token inside grid

y=rand() % 5;//rand function which makes the computer randomly place token inside grid

if (grid[x][y] == ' ')//if the grid is empty
{
	grid[x][y] = comtoken;//place token inside board
	turn=1;//turn is equal to 1
}
}
}

