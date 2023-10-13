#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char *ft_strcpy(char *dest, char *src)
{
	int i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
char *Read_string()
{
	char Buffer[20];
	char *Name = NULL;
	
	printf("Pleas enter the Name encrypt?\n");
	scanf("%19s", Buffer);

	Name = (char *)malloc(ft_strlen(Buffer) + 1);
	
	if(Name == NULL)
	{
		return (NULL);
	}

	ft_strcpy(Name, Buffer);

	return (Name);
}
char *Encrypt_Name(char *Name)
{
	int len = ft_strlen(Name);

	for(int i = 0; i < len; i++)
	{
		Name[i] = Name[i] + 2;		
	}

	return (Name);
}
char *Decrypt_Name(char *str)
{
	int len = ft_strlen(str);

	for(int i = 0; i < len; i++)
	{
		str[i] = str[i] - 2;
	}

	return (str);
}
void Print_Result(char *Name)
{
	printf("\nText Befor Incryption : %s\n", Name);
	
	Name = Encrypt_Name(Name);
	printf("Text after Encryption : %s\n", Name);

	Name = Decrypt_Name(Name);
	printf("Text after Decryption : %s\n", Name);
	
}
int main()
{
	Print_Result(Read_string());
	return (0);
}
