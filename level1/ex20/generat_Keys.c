#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Options{Capital = 1, Small = 2, Digit = 3, Special = 4};

int Read_Number_Positive()
{
	int Number = 0;
	do
	{
		printf("Pleas enter the Number Positive ?\n");
		scanf("%d", &Number);
	
	}while(Number <= 0);

	return (Number);
}
int Random_Number(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return (RandNum);
}
char Option_Character(enum Options TypeChar)
{
	switch (TypeChar)
	{
		case Capital:
			return (char)Random_Number(65, 90);
		case Small:
			return (char)Random_Number(97, 122);
		case Digit:
			return (char)Random_Number(48, 57);
		case Special:
			return (char)Random_Number(33, 47);
		default:
			return ('\0');
	}
}
char *Generat_Key()
{
	char *Word = (char *)malloc(5);
	if(Word == NULL)
	{
		return (NULL);
	}

	for(int i = 0; i < 4; i++)
	{
		Word[i] = Option_Character(Capital);
	}
	Word[4] = '\0';

	return (Word);
}
int ft_strlen(char *src)
{
	int i = 0;
	while(src[i] != '\0')
	{
		i++;
	}
	return (i);
}
char *ft_strcpy(char *dest, char *src)
{
    int len = ft_strlen(dest);
        int i = 0;
        while(src[i] != '\0')
        {
                dest[len] = src[i];
                len++;
                i++;
        }
	dest[len] = '\0';
        return (dest);
}
char *Generat_Keys()
{
    char *Words = (char *)malloc(17);
    
    if (Words == NULL)
    {
        return NULL;
    }

    if (Words == NULL) {
        
        free(Words);
        return NULL;
    }

    ft_strcpy(Words, Generat_Key());
    ft_strcpy(Words, "-");
    ft_strcpy(Words, Generat_Key());
    ft_strcpy(Words, "-");
    ft_strcpy(Words, Generat_Key());
    ft_strcpy(Words, "-");
    ft_strcpy(Words, Generat_Key());

    return Words;
}
void Print_Result(int Number)
{
	for(int i = 1; i <= Number; i++)
	{
		char *Key = Generat_Keys();
		if(Key != NULL)
		{
			printf("Key[%d] : %s\n", i, Key);
			free(Key);
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	
	Print_Result(Read_Number_Positive());
	return (0);	
}
