#include <stdio.h>/*Type of library for the program, holds the information for the code*/ 
/* stores user input in a,b,c void info hold the code , pointers used to help lower the memory usage*/

	void info(char *a,char *b,char *c);/*functions declared info*/
	void pyramid(char *a,char *b,char *c);/*pyramid function declared in brackets*/
/* the info and pyramid store and print what the two void function hold*/
 void main()/*main function */
{
	char a,b,c;/*character value names - this is where the user input will be stored*/
	info(&a, &b, &c);/*runs the void info */
	pyramid(&a,&b,&c);/*prints the pyramid */

}
void info(char *a,char *b,char *c)/*info function produces the information to the user*/
{
	printf("Input three characters from the keyboard\n");/*prints to the user */
	scanf("%c",a);/*looks for a character the user has input*/
	scanf("%c",b);/*looks for a character the user has input*/
	scanf("%c",c);/*looks for a character the user has input*/
}
void pyramid(char *a,char *b,char *c){/*pyramid function a,b,c will be printed below a being the first character b being the second and then c being the third*/
	printf("     %c\n",*a);/*prints characters in the pyramid */
	printf("    %c%c%c\n",*a,*b,*a);/*prints characters in the pyramid*/ 
	printf("   %c%c%c%c%c\n",*a,*b,*c,*b,*a);/*prints characters in the pyramid */
	printf("  %c%c%c%c%c%c%c\n",*a,*b,*c,*c,*c,*b,*a);/*prints characters in the pyramid */
	printf(" %c%c%c%c%c%c%c%c%c\n",*a,*b,*c,*c,*c,*c,*c,*b,*a);/*prints characters in pyramid*/
	printf("%c%c%c%c%c%c%c%c%c%c%c\n",*a,*b,*c,*c,*c,*c,*c,*c,*c,*b,*a);/*prints characters in the pyramid */

}
