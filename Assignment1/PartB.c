#include <stdio.h> /*Type of library for the program, holds the information for the code */

int main(void) /*Main body for the program */
{
	char car_type, GBP=156;/* character variable holds car type and gbp=156 displays pound sign(found in the ASCII Codes table)*/
	float litresrate,fuelprice;/*float stores number values with decimals- kept common/relatable floats together on one line*/
	float builtuparea,singlecarriageway,dualcarriageway;/*float stores the three distances the user inputs*/
	float mpg1, mpg2, mpg3;/*stores miles per gallon for each car type*/
	float litres, gallons;/*litres and gallons on the same line as they relatable*/
	float cost1, cost2, cost3,totalfuelcost,totalcost;/* all these are the costs of the 3 calculations, with the total fuel and total cost together as well*/
	int remuneration;/* remuneration is an integer as it only need to stores the whole number and not the decimals, reduces memory as integer is less memory*/	
	litresrate=4.54609;/*litresrate is the global rate of how many litres are in 1 gallon*/
	printf("Please input Car type\n");/*prints text*/
	scanf("%c", &car_type);/*asks for users input*/
	car_type=tolower(car_type);/*allows upper and lower case in the if statement*/

if (car_type=='a')/*if meaning if the car type is this value it will follow the steps in the if statement*/
	{	
		fuelprice=1.50;/*stores values for calculations for case a*/
		mpg1=40;/*stores values for calculations for case a*/
		mpg2=50;/*stores values for calculations for case a*/
		mpg3=60;/*stores values for calculations for case a*/

	}
	else if(car_type=='b')/*if meaning if the car type is this value it will follow the steps in the if statement*/
	{

		fuelprice=1.30;/*stores values for calculations for case b*/
		mpg1=45;/*stores values for calculations for case b*/
		mpg2=55;/*stores values for calculations for case b*/
		mpg3=65;/*stores values for calculations for case b*/
}
	
	else /* else shows that if the value of car type is anything else it will print out invalid*/
	{
		printf("invalid case number");/*invalid case number*/
	}
	
		printf("The car type is %c\n",car_type);/*prints what the user has inputted for the car type*/
		printf("Please input distance travelled in built up area\n");/*asks user for distance in built up area*/
		scanf("%f",&builtuparea);/*asks user what they want for distance in area*/
		printf("Please input distance travelled in single carrigeway\n");/*asks user for distance in single carriageway*/
		scanf("%f",&singlecarriageway);/*asks user what they want for distance in area*/
		printf("Please input distance travelled in dual carrigeway\n");/*asks user for distance in dual carriageway*/
		scanf("%f",&dualcarriageway);/*asks user what they want for distance in area*/
		
		gallons=builtuparea/mpg1;/*calculations for program working out gallons consumed */
		litres=litresrate*gallons;/*calculations for program working out litres consumed*/
		cost1=fuelprice*litres;/*calculations for program working out the cost of litres*/
		
		gallons=singlecarriageway/mpg2;/*calculations for program working out gallons consumed */
		litres=litresrate*gallons;/*calculations for program working out litres consumed*/
		cost2=fuelprice*litres;/*calculations for program working out the cost of litres*/
		
		gallons=dualcarriageway/mpg3;/*calculations for program working out gallons consumed*/
		litres=litresrate*gallons;/*calculations for program working out litres consumed*/
		cost3=fuelprice*litres;/*calculations for program working out the cost of litres*/
		
		totalfuelcost=cost1+cost2+cost3;/*adds up the overall fuel cost*/
		
		printf("\n%.2f gallons consumed in built up area driving for %.2f miles at %.2f mpg\n",gallons,builtuparea,mpg1);/*prints gallons consumed value to the user also displaying miles and mpg*/
		printf("%.2f litres consumed in built up area driving for %.2f miles at %..2f mpg \n",litres,builtuparea,mpg1);/*prints litres consumed value to the user also displaying miles and mpg*/
		printf("%c%.2f fuel cost for %.2f miles in the built up area\n",GBP,cost1,builtuparea);/*prints the total fuel cost in the built up area also using character input to display the pound sign*/
	
		printf("\n%.2f gallons consumed in single carriageway driving for %.2f miles at %.02f mpg\n",gallons,singlecarriageway,mpg2);/*prints gallons consumed value to the user also displaying miles and mpg*/
		printf("%.2f litres consumed in single carriageway for %.2f miles at %.2f mpg \n",litres,singlecarriageway,mpg2);/*prints litres consumed value to the user also displaying miles and mpg*/
		printf("%c%.2f fuel cost for %.2f miles in the single carriageway\n",GBP,cost2,singlecarriageway);/*prints the total fuel cost in the single carriageway area also using character input to display the pound sign*/
		
		printf("\n%.2f gallons consumed in dual carrigeway driving for %.0f miles at %.0f mpg\n",gallons,dualcarriageway,mpg3);/*prints gallons consumed value to the user also displaying miles and mpg*/
		printf("%.2f litres consumed in dual carriageway driving for %.0f miles at %.0f mpg \n",litres,dualcarriageway,mpg3);/*prints litres consumed value to the user also displaying miles and mpg*/
		printf("%c%.2f fuel used for %.0f miles in dual carriageway\n",GBP,cost3,dualcarriageway);/*prints the total fuel cost in the single carriageway area also using character input to display the pound sign*/	
		
		printf("Total fuel cost %c%.2f\n",GBP,totalfuelcost);/*prints the total fuel cost for all three areas*/
		
		if (totalfuelcost<=10){/*if statement to work out the remuneration(drivers salary costs) for different circumstances i less than or equal to 10 then it will print the normal pounds value*/
		remuneration=totalfuelcost;/*remuneration given the value of totalfuelcost*/
		printf("The drivers salary is %c%d\n",GBP,remuneration);/*prints salary to the user*/
		}
		else if(totalfuelcost<=30){/*if totalfuelcost is less than 30 or equal too then do the calculations below */
			remuneration = 10 + ((totalfuelcost-10)*2);/*calculation to work out the drivers money back */
			printf("The drivers salary is %c%d\n",GBP,remuneration);/*prints drivers salary*/
		}

		else if(totalfuelcost<=60){/*if totalfuelcost is less than 60 or equal too then do the calculations below */
			remuneration = 10 + 40 + ((totalfuelcost-30)*3);/*works out remuneration */
			printf("The drivers salary is %c%d\n",GBP,remuneration);/*prints salary*/
		}
			else
                if (totalfuelcost>60)/*else if more than 60 */
            {
				remuneration=10+40+90+((totalfuelcost-60)*5);/*calculation*/
			printf("The drivers salary is %c%.2d\n",GBP,remuneration);/*prints value*/
		}
  totalcost=totalfuelcost+remuneration;/*calculation for the overall total cost */
		printf("The overall cost is %c%.2f\n",GBP,totalcost);/*prints to the user the total cost of the fuel and  remuneration*/
} 
