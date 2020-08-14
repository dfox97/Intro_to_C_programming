#include <stdio.h> /*Type of library for the program, holds the information for the code */
#include <ctype.h>/*Type of library for the program, hold information */
double telephone();/*variable which holds bery large or small numbers */
double internet();/*variable which holds bery large or small numbers */
double television();/*variable which holds bery large or small numbers */
char service_code();/*character variable stores characters*/

int main()/* int main function holds the main infomation for the program*/
{
	char pound=156;/* character variable holds car type and gbp=156 displays pound sign(found in the ASCII Codes table)*/
 	unsigned int account_number;/*Unsigned can hold a larger positive value, and no negative value*/
	
{
	printf("Please enter Account Number\n");/*prints the statement inside the brackets*/
	scanf("%u",&account_number);/*asks user for input*/
	while(account_number==1)/*while account number ==1 it will print out invalid character , stopping the user inputting chracters*/
	{
		printf("Invalid characters, please enter a valid account number\n");/*prints the statement inside the brackets*/
		fflush(stdin);/*clears the buffer*/
		scanf("%u", &account_number);/*asks user for input*/
	}
	printf("Account number is %u\n",account_number);/*prints the statement inside the brackets*/	
 	fflush(stdin);/*allows you to flush the input buffer*/
 	
 	char code;/* character variable holds car type and gbp=156 displays pound sign(found in the ASCII Codes table)*/
 	code = service_code();/* sets the value of code to service code*/
 	code=toupper(code);/*allows the use of lower and upper case characters*/

	while (code != 'P' && code!= 'I'&& code!='T')/*while loop which is like a if statement but repeating.so while the user has entered p,i,t he code below will run*/
{
			
			printf("\nEnter valid service code\n");/*prints the statement inside the brackets*/
			code = service_code();/* sets the value of code to service code*/

}
		if (code == 'P')/* if statement inside while statement , if character P is entered then it will display the telephone function*/
		{
			telephone();/*The function is recalled and run*/

		}
		else /* else if the character entered is I */
			if (code == 'I')
		{
			internet();/*the function is recalled and ran*/

		}
		else 
			if (code == 'T')/* else if the character entered is t */
		{
			television();/*the function is recalled and ran*/

		}
}
}
char service_code()/*local function name char as the return type*/
{
	char service_code;/*stores the character in service code*/
	printf("\nWhich service would you like\n");/*prints the statement inside the brackets*/
	scanf("%c",&service_code);/*asks user for input*/
	fflush(stdin);/*allows you to flush the input buffer*/
	return(service_code);/*returns to service_code*/
	
}
double telephone()/*local function double telephone - can store large values*/
{
	unsigned int minutes;/*unsigned int used to store minutes, Unsigned can hold a larger positive value, and no negative value*/ 
	float totalcost;/* float variable to store totalcost*/
	char pound=156;/* character variable holds car type and gbp=156 displays pound sign(found in the ASCII Codes table)*/
	printf("Input service minutes\n");/*prints the statement inside the brackets*/
	scanf("%u",&minutes);/*asks user for input*/
	totalcost=0.05*minutes+15.00;/* calculation for total cost*/
	printf("Telephone cost for %d minutes used: %c%.2f\n",minutes,pound,totalcost);/*prints the statement inside the brackets*/

}
double internet()/*local function double internet - can store large values*/
{
	unsigned int minutes;/*unsigned int used to store minutes, Unsigned can hold a larger positive value, and no negative value*/ 
	float totalcost;/* float variable to store totalcost*/
	char pound=156;/* character variable holds car type and gbp=156 displays pound sign(found in the ASCII Codes table)*/
	printf("Input service minutes\n");/*prints the statement inside the brackets*/
	scanf("%u",&minutes);/*asks user for input*/	
	fflush(stdin);/*allows you to flush the input buffer*/
		if (minutes<=1000){/* if statement inside while statement , if character P is entered then it will display the telephone function*/

		totalcost=20;
		printf("The internet cost is %c%.2f\n",pound,totalcost);/*prints the statement inside the brackets*/
		}
			else
                if (minutes>1000)/* if statement inside while statement , if character P is entered then it will display the telephone function*/
            {
				totalcost=0.02*(20.00+minutes-1000);/* calculation for total cost*/
			printf("The internet cost is %c%.2f\n",pound,totalcost);/*prints the statement inside the brackets*/
		}
}


double television()/*local function double television - can store large values*/
{
	unsigned int minutes;/*unsigned int used to store minutes, Unsigned can hold a larger positive value, and no negative value*/ 
	unsigned int pack;/*unsigned int used to store pack, Unsigned can hold a larger positive value, and no negative value*/ 
	float totalcost;/* float variable to store totalcost*/
	char pound=156;/* character variable holds car type and gbp=156 displays pound sign(found in the ASCII Codes table)*/
	printf("Please enter 1 for basic package or 2 for the premium pack\n");/*prints the statement inside the brackets*/
	scanf("%u",&pack);/*asks user for input*/
	fflush(stdin);/*allows you to flush the input buffer*/

	fflush(stdin);/*allows you to flush the input buffer*/
while(pack != 1 && pack !=2)
{
	printf("\nThis is an invalid pack number , please enter 1 for the basic package or 2 for the premium package");
	fflush(stdin);/*allows you to flush the input buffer*/
	scanf("%u",&pack);/*asks user for input*/
}
	printf("Input service minutes\n");/*prints the statement inside the brackets*/
	scanf("%u",&minutes);/*asks user for input*/
	while(pack == 1)/*while loop which is like a if statement but repeating.so while the user has entered p,i,t he code below will run*/
{
		if (minutes<=60)/* if statement inside while statement , if character P is entered then it will display the telephone function*/
	{
		totalcost=5;/* declares totalcost value*/
		printf("\nbasic packselected\nThe television cost is %c%.2f\n",pound,totalcost);/*prints the statement inside the brackets*/
		break;/*breaks the loop */
	}
	else
        if (minutes>60)/* if statement inside while statement , if character P is entered then it will display the telephone function*/
    {
		totalcost=0.01*(20.00+minutes-60);/* declares totalcost value and calculation*/
		printf("\nbasic pack selected\nThe television cost is %c%.2f\n",pound,totalcost);/*prints the statement inside the brackets*/
		break;/*breaks the loop */	
	}
}
	while(pack == 2)/*while loop which is like a if statement but repeating.so while the user has entered p,i,t he code below will run*/
{
		if (minutes<=60)/* if statement inside while statement , if character P is entered then it will display the telephone function*/
	{
		totalcost=10;/* declares totalcost value*/
		printf("\npremium pack selected\nThe television cost is %c%.2f\n",pound,totalcost);/*prints the statement inside the brackets*/
		break;/*breaks the loop */
	}
	else
        if (minutes>60)/* if statement inside while statement , if character P is entered then it will display the telephone function*/
    {
		totalcost=0.02*(20.00+minutes-60);/* declares totalcost value and calculation*/
		printf("\npremium pack selected\nThe television cost is %c%.2f\n",pound,totalcost);/*prints the statement inside the brackets*/
		break;	/*breaks the loop */
	}
	
}
}
