#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void update_string(char *str, int(*pf)(int));
void ToUpper(char *str);
void ToLower(char *str);
void Transpose(char *str);

int main()
{
	char option[] = { 'u', 'l', 't' };
	int n = sizeof(option) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");

	while (1)
	{
		printf("Choose an option:\n");
		printf("u) to upper\nl) to lower\nT) to Transpose\n");
	
		char c;
		while (scanf("%c%*[^\n]%*c", &c) != 1)
			printf("Please try again.\n>> ");
	
		int i = 0;
		bool check = false;
		while (i < n)
		{
			if (option[i] == c)
			{
				(*(operations[i]))(input);
				check = true;
				break;
			}
			i++;
		}
		if (check)
			break;
		else
			printf("Wrong input, try again\n");
	}
	printf("%s\n", input);
	return (0);
}

void update_string(char *str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}

void ToUpper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

void ToLower(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

void Transpose(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		else if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}
