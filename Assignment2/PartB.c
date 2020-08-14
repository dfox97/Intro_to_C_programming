#include <stdio.h>/*Type of library for the program, holds the information for the code */

float x_to_the_4(float x)/*local function to help calculate the kurtosis this calculates x to the power of 4*/
{
	x=x*x*x*x;/*calculation for x to the power of 4*/
	return(x);/*returns the value of x to the local function*/
}

float x_squared(float x)/*local function to help calculate the kurtosis this calculates x squared*/
{
	x=x*x;/*calculation for x squared helps with the kurtosis calculation*/
	return(x);/*return statement which returns the value of x to the local function*/
}
float kurtosis(float value[10],float mean, int n)/*local function to work out the calculation using different variables, floats inside brackets declares function */
{
	int i;/* integer which stores a value which is named i*/
	float x,answer1, answer2 , sumnum, sumdenom,numerator,denominator,kurtosis;/*floats which will store values with decimals*/

	for(i=0;i<n;i++)/* for statement , will execute the next statement inside brackets a number of time depending on i and n*/
{
	 x=value[i];/*makes the array with i equal x , this helps work out the equation*/
	 answer1 = x_to_the_4(x-mean);/*answer 1 will work out the value of x to the power of 4 also x minus the mean(top line of the kurtosis)*/
	 answer2 = x_squared(x-mean);/*works out bottom line of kurtosis , x squared also x minus the mean */
	 sumnum=sumnum+answer1;/*sums up answer 1 and the sumnumerator to work out the numerator*/
	 sumdenom=sumdenom+answer2;/*works out the denominator */
}
	numerator=sumnum/n;/*sumnumerator divided by n gives the kurtosis numerator*/
	denominator=x_squared(sumdenom/n);/*sumdenominator divided by n gives the kurtosis numerator also timesing the sumdem/n by x squared this gives the denominator total*/
	kurtosis=numerator/denominator;/*finally works out the kurtosis by dividing the numerator and denominator */

for (i=0; i<n; i++)/* another for statement , excutes the statement in the brackets */
{/* Couldnt place the printf statement inside the main function as it displayed the kurtosis as 0*/
	printf("\nValue %.2d=%.3f\n",i+1, value[i]);/*printf statement displys to the user*/ 
}
	printf("-----------------\n");/*printf statement displys to the user*/ 
	printf("Kurtosis =%f",kurtosis);/*printf statement displys to the user*/ 

}
int main()/* int main holds the main info for the program while also calculating the mean*/
{
	int i,n;/* integer which stores values named i and n*/
	float value[10],sum=0;/*floats which will store values with decimals*/

	
	printf("Please input number of terms(Maximum terms is 10 )\n");/*printf statement displys to the user*/ 
	scanf("%d",&n);/*scanf asks the user to input the value of terms*/
	printf("Characters and Negative values WILL be ignored and finish the kurtosis\n");/*printf statement displys to the user*/
	
	for(i=0;i<n;i++)/* another for statement , excutes the statement in the brackets the purpose of this statement is stop stop negative 
	numbers being entered or the user inputting too many terms*/
	{
		if (i<=8)/* if statement , 8 is the loop count so its the 9th value it includes*/
	{
		
		printf("Enter values %d ",i+1);/*printf statement displys to the user*/ 
		scanf("%f",&value[i]);/*scanf asks the user to input the value of terms*/
		
		if (value[i]<0)/*if negative then a print f statement will be shown to the user stating that the value is negative and it wont be accepted*/
		{
			n=i+1;/* increases value of n by changing it do i+1 to stop the loop*/
			printf("Negative number entered, n is now %d\n No more values will be accepted.",n);/*printf statement displys to the user*/
			 
		}
	
		}
	if (i>8)/* if statement , 8 is the loop count so its the 9th value it includes*/
		{
			n=10;/* giving n a value of 10*/
			printf("Enter the value %d: ",i+1);/*printf statement displys to the user*/ 
			scanf("%f",&value[i]);/*scanf asks the user to input the value of terms*/
			printf("Maximum capacity reached, no more values will be accepted\n");/*printf statement displys to the user*/ 
		}
		
/*errors when outside main function(if placed in kurtosis calculation ,gives wrong values, if palced in mean */
		sum=value[i]+sum;/*calculation */
		
}
	float mean;/* calculated the mean for kutrosis (wont allow function, errors) have to include inside the main function*/
	mean=sum/n;/*mean calculation*/
	kurtosis(value,mean,n);/*returns the values to the calculation function*/

}