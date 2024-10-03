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
    int sum = 0; /*Variable to find result*/
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
	int decryption_length,i;
	char character;
	while(scanf("%c",&character) != EOF)/*taking input till the end of the file*/
	{
		i = finding_in_alphabet(character);
		/*first condition for checking if its for comment line length*/
		if(character == '@' && scanf("%c",&character) == 1 && character == ' ')
		{
			printf("/* There is ");
			while(scanf("%c",&character) == 1 && character != '\n')
			{
				int j = 0;
				while(alphabet[j] != character)
					j++;
				decryption_length = (j - key);
				if(decryption_length >= 0)
					printf("%c",alphabet[decryption_length]);
				else
					printf("%c",alphabet[(decryption_length + 61)]);
			}
			printf(" characters as comment.*/");
		}
		if(character == '\n')/*condition for checking end of lines and prints new line*/
			printf("\n");
		else if(character == ' ')/*condition for checking spaces, if character is space then prints space*/
			printf(" ");
		else/*for other conditions it decrypt the characters and prints the normal form*/
		{
			decryption_length = i - key;
			if(decryption_length >=0)
				printf("%c",alphabet[decryption_length]);
			else
				printf("%c",alphabet[decryption_length + 61]);
		}
	}
	return 0;
}
