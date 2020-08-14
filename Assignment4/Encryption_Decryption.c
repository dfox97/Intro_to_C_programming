#include<stdio.h>/*Type of library for the program, holds the information for the code */
#include<conio.h>/*Type of library for the program, holds the information for the code */
#include <stdlib.h>/*Type of library for the program, holds the information for the code */

int main()//main function hol the option choice for the user
 {
	int opt;//integer for the option for the user
	printf("Do you want to encrypt or decrypt a file?\nEncrypt:1\nDecrypt:2\n ");//prints to the user what the user should input
	scanf("%d",&opt);//scans for the users input for the option
	fflush(stdin);// clears buffer
	opt = tolower(opt);// allows the user to input capitals
	
switch (opt)// switch used for the option , if the user inputs case 1 then the encryption function will be used
	{
		case 1:// case 1 is met when the user inputs 1
		encryption();//function will run
		break;// breaks the switch
	
		case 2:// case 2 is met when the user inputs 2
		decryption();//decryption function which runs at 2
		break;// breaks the switch
		
		default:
			printf("\nInvalid option try again\n\n\n");//informs the user that the input is incorrect
			main();//function will return back to main if the option is invalid
			break;
	}
}
int encryption ()//integer function for the encryption format
{
	FILE *Fileinput; //file pointer for the input file in text format for encryption
	FILE *KeyFile; //file pointer for the key file in text format
	FILE *encryptedfile;//file pointer for the output file in text format
	
	char filename[100], encryptfile[100], keyname[100];//arrays created to store the characters for the file types
	int lengthinput = 0, passkeylength = 0, x =0,currentint = 0,i = 0;//integers for the length for input setting each variable to 0
	char message[lengthinput],ch;//char message array to find the length of the input, also char ch for the for loop to read single characters
	int key[passkeylength], encrypt; //integer key array for the passkey length and also the integer encption
	
printf(" ---------------------------------\n"); //prints to the user what they have chosen as an option
printf(" ----------|Encryption|-----------\n"); //prints to the user what they have chosen as an option
printf(" ---------------------------------\n"); //prints to the user what they have chosen as an option

printf("Input name of text file for encryption including .txt:\n");//prints to the user asking for txt file
scanf("%s",filename);//scans for the users input for the text file 
fflush(stdin);// clears buffer

printf("Input name of Key file including .txt:\n");//prints to the user asking for txt file
scanf("%s",keyname);//scans for the users input for the text file 
fflush(stdin);// clears buffer

printf("Input name of encrypted file including .txt:\n");//prints to the user asking for txt file
scanf("%s",encryptfile);//scans for the users input for the text file 
fflush(stdin);// clears buffer

Fileinput=fopen(filename, "r+");//makes the pointer file equal to file open filename in a readable and then writable format
KeyFile=fopen(keyname, "r+");//makes the pointer file equal to file open keyname in a readable and then writable format

	while(Fileinput== NULL || KeyFile== NULL)//while loop too stop errors if the file or key file is not there then it asks the user to try again
	{
		printf(" File does not exists or error in opening\n");//prints to the user an error in the program
		printf("please try again\n");//prints to the user to please try again
		encryption();// goes back to encryption function, from the beginning
	}

while ((ch = fgetc(Fileinput)) !=EOF)//fgetc reads single character at a time
{
	lengthinput++;//increment for lengthinput which increases by 1
	message[x]= ch;//assigns message to a char 
	x++;//increment for x which increases by 1
}
x= 0 ;//makes the value of x equal to 0 so it can work with the keyfile while loop below
while (fscanf(KeyFile, "%1d", &currentint)>0)//reads keyfile data 1d is width limit max number of characters it will scan
{
	passkeylength++;//increment for passkeylength which increases by 1
	key[x] = currentint;//assigns key to currentint
	x++;//increment for x which increases by 1
}
	fclose(Fileinput);//closes the message file
	fclose(KeyFile);//closes the key file

for (x = 0; x < lengthinput; x ++)//for loop which is set to run the same number of times as the length of the message setting x to 0 and increasing it by 1
{
	encrypt = message[x] + key[i];//algorithm given in the assignment question working out the value for the encryption 
	message[x] = encrypt;//setting message[x] to the encrypt value
	if (i == passkeylength - 1)//gets rid off extra keys if the value, if the value of i is equal key length then minus -1
	{
		i=0;//sets i=0
	}
	else//otherwise
	{
		i++;//increment i by 1 
	}
}
encryptedfile=fopen(encryptfile, "w");//sets the encrypted file to the encryptfile which makes it writeable (w)
fprintf(encryptedfile, "%s", message);//pointer file infront of fprintf because its a file, this prints the encryption to the file
fclose(encryptedfile);//closes the file set to encryptedfile

printf("\nFile Successfully Encrypted!\n\n");//displays to user that the file has successfully encrypted
printf("The file name is called %s\n",encryptfile);//prints to the user the filename so they know what the name of the file name is(incase of incorrect output name)
printf("Encrypted to: %s\n",message);//prints to the user showing the encryption
}

int decryption() //integer function for the decryption selection
{
	
	FILE *Fileinput; //file pointer for the input file in text format for decryption it will be the output file from the encryption file
	FILE *KeyFile; //file pointer for the key file in text format
	FILE *decryptedfile;//file pointer for the output file in text format
	
	char filename[100], decryptfile[100], keyname[100];//arrays created to store the characters for the file types
	int lengthinput = 0, passkeylength = 0, x =0, currentint = 0, i = 0;//integers for the length for input setting each variable to 0
	char message[lengthinput],ch;//char message array to find the length of the input, also char ch for the for loop to read single characters
	int key[passkeylength], decrypt;//integer key array for the passkey length and also the integer encption
	

printf(" ---------------------------------\n"); //prints to the user what they have chosen as an option
printf(" ----------|Decryption|-----------\n"); //prints to the user what they have chosen as an option
printf(" ---------------------------------\n"); //prints to the user what they have chosen as an option

printf("Input name of file to be decrypted including .txt:\n");//prints to the user asking for txt file
scanf("%s",filename);//scans for the users input for the text file 
fflush(stdin);// clears buffer

printf("Input name of Key file including .txt:\n");//prints to the user asking for txt file
scanf("%s",keyname);//scans for the users input for the text file 
fflush(stdin);// clears buffer

printf("Input the file you want including .txt:\n");//prints to the user asking for txt file
scanf("%s",decryptfile);//scans for the users input for the text file 
fflush(stdin);// clears buffer

Fileinput=fopen(filename, "r+");//makes the pointer file equal to file open filename in a readable and then writable format
KeyFile=fopen(keyname, "r+");//makes the file pointer for the key open and convert it to a readable and writable format


	while (Fileinput== NULL || KeyFile== NULL)//while loop too stop errors if the file or key file is not there then it asks the user to try again
	{
		printf(" File does not exists or error in opening");//prints to the user an error in the program
		printf("Please try again!\n");//asks the user to try again
		decryption();//function which links back to the start of decryption
	}

while ((ch = fgetc(Fileinput)) !=EOF)//fgetc reads single character at a time
{
	lengthinput++;//increment for lengthkey which increases by 1
	message[x]= ch;//assigns message to ch allows x to change
	x++;// increments value of x by 1
}
x= 0 ;// making x equal 0 again so the keyfile can start back at 0 
while (fscanf(KeyFile, "%1d", &currentint)>0)//reads keyfile data 1d is width limit max number of characters it will scan
{
	passkeylength++;//increment for passkeylength which increases by 1
	key[x] = currentint;//assigns key to currentint
	x++; // increments value of x by 1
}
	fclose(Fileinput);//closes the message file
	fclose(KeyFile);//closes the key file

for (x=0; x<lengthinput; x++)//for loop which is set to run the same number of times as the length of the message setting x to 0 and increasing it by 1
{
	decrypt = message[x] - key[i];//algorithm given in the assignment question working out the value for the encryption 
	message[x] = decrypt;//setting message[x] to the encrypt value
	
	if (i == passkeylength -1)//gets rid off extra keys if the value, if the value of i is equal key length then minus -1
	{
		i=0;//sets i equal to 0
}
	else//otherwise
	{
		i++;//increment i by 1 
	}
}
decryptedfile=fopen(decryptfile, "w");//sets the encrypted file to the decryptfile which makes it writeable (w)
fprintf(decryptedfile, "%s", message);//pointer file infront of fprintf because its a file, this prints the decryption to the file
fclose(decryptedfile);//closes the file called decrypted file

printf("\nFile Successfully Decrypted!\n\n");//prints to the user that the file has successfully decrypted 
printf("The file name is called %s\n",decryptfile);//prints to the user the filename so they know what the name of the file name is(incase of incorrect output name)
printf("Decryption back to: %s\n",message);// displays what the file will say.

}
