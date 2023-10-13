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

void *Read_Password()
{
	char *Pass = NULL;
	char Buffer[3];
	
	printf("Pleas enter 3 letter in the Password ?\n");
	scanf("%3s", Buffer);

	Pass = (char *)malloc(ft_strlen(Buffer) + 1);

	if(Pass == NULL)
	{
		printf("Memory allocation failde!!\n");
		return (NULL);
	}
	
	ft_strcpy(Pass, Buffer);

	return (Pass);
}
void Search_Password(char *Pass)
{
	int Count = 0;
	char Words[4];
	Words[3] = '\0';

	for(char i = 65; i <= 90; i++)
	{
		for(char j = 65; j <= 90; j++)
		{
			for(char k = 65; k <= 90; k++)
			{
				Count++;

				Words[0] = i;
				Words[1] = j;
				Words[2] = k;
				
				printf("Trial[%d] : %s\n", Count, Words);
				int l = 0;
				while(Pass[l] != '\0' && Pass[l] == Words[l])
				{
					if(Pass[l + 1] == '\0')
					{
						printf("Password is %s\n", Words);
						printf("Found After %d Trial(s)\n", Count);
						return;
					}
					l++;
				}						
			}
		}
	}
}
int main()
{
	Search_Password(Read_Password());
	return (0);
}
