#include<stdio.h>
/*Alphabet to find order of characters*/
char alphabet[61] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
'(', '<', '=', '+', ')', '[', '*', '/', ']', '{', '>', '!', '-', '}', '?',
'\\', '&', '|', '%', '_', ';', '"', '#', '.', '\'', '0', '1', '2', '3', '4',
'5', '6', '7', '8', '9'};
/*Function to calculate  key*/
int finding_key(long long int student_number)
{
    int sum = 0;/*Variable to find result*/
    while(student_number > 0)
    {
        sum += student_number % 10; 
        student_number /= 10;
    }
    if(sum >= 10)
        return(finding_key(sum));
    else
        return(sum);
}
/*Function to find index of character in alphabet array*/
int finding_in_alphabet(char character)
{
    int i = 0;/*counter to find index of the character*/
    while(alphabet[i] != '\0')
    {
        if(alphabet[i] == character)
            return(i);
        i ++;
    }
}
int main()
{
	long long int student_num = 220104004003;/*student id variable as long long int*/
	int key = finding_key(student_num); /*key is 7*/
	int i,comment,encryption_length;
	char character;
	while(scanf("%c",&character) != EOF)/*taking input till the end of the file*/
	{
		comment = 0;
		i = finding_in_alphabet(character);
		if(character == '/' && scanf("%c",&character) == 1 && character == '*')
		{
			while(scanf("%c",&character) == 1)
			{
				if(character == '\n')
					break;
				if(character != ' ')
					comment++;/*increment comment to find total length*/
			}
			character = '@';
			printf("%c ",character);
			comment -= 2;/*to decrement last two characters star-slash*/
			if(comment<10)
			{
				int j = 0;
				while(alphabet[j] != comment+'0')/*its for casting from integer to char and finds index in alphabet*/
					j++;
				encryption_length = (j + key) % 61;
				printf("%c",alphabet[encryption_length]);
			}
			else/*to encrypt comment if it is bigger than one digit number*/
			{
				float com = comment;
				int count = 0;
				while(com>0.9999)/*to find total digit*/
				{	
					com /= 10;
					count++;
				}
				while(count>0)
				{
					comment = com * 10;
					int k = 0;
					int num = comment % 10;
					while(alphabet[k] != num + '0')
						k++;
				    encryption_length = (k + key) % 61;
					printf("%c", alphabet[encryption_length]);
					count--;
					com *= 10;
				}
			}
			character = '\n';
		}
		if(character == '\n')/*condition for checking end of lines and prints new line*/
			printf("\n");
		else if(character == ' ')/*condition for checking spaces, if character is space then prints space*/
			printf(" ");
		else/*for other conditions it encrypt the characters and prints the encrypted form*/
		{
			encryption_length = (i + key) % 61;
			printf("%c",alphabet[encryption_length]);
		}
	}
	return 0;
}

