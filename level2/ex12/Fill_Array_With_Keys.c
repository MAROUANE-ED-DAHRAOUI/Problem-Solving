#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum OptionChar {CapitalChar = 1, SmallChar = 2, Digit = 3, SpecialChar = 4};

int Read_Number()
{
    int Number = 0;

    do
    {
        printf("Please enter the number of keys to generate: ");
        scanf("%d", &Number);
    } while (Number <= 0);

    return Number;
}

int Random_Number(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char Option_Character(enum OptionChar CharType)
{
    switch (CharType)
    {
        case CapitalChar:
            return (char)Random_Number(65, 90);
        case SmallChar:
            return (char)Random_Number(97, 122);
        case Digit:
            return (char)Random_Number(48, 57);
        case SpecialChar:
            return (char)Random_Number(33, 47);
        default:
            return ('\0');
    }
}

char *Generate_Word(int length)
{
    char *Word = (char *)malloc(sizeof(char) * length + 1);
    if (Word == NULL)
    {
        return (NULL);
    }

    for (int i = 0; i < length; i++)
    {
        Word[i] = Option_Character(CapitalChar);
    }
    Word[length] = '\0';
    return (Word);
}

char *Generate_Keys()
{
    char *Words = (char *)malloc(sizeof(char) * 21);
    if (Words == NULL)
    {
        return (NULL);
    }

    char *buffer = Generate_Word(4);
    for (int i = 0; i < 4; i++)
    {
        Words[i] = buffer[i];
    }
    Words[4] = '-';

    buffer = Generate_Word(4);
    for (int i = 0; i < 4; i++)
    {
        Words[i + 5] = buffer[i];
    }
    Words[9] = '-';

    buffer = Generate_Word(4);
    for (int i = 0; i < 4; i++)
    {
        Words[i + 10] = buffer[i];
    }
    Words[14] = '-';

    buffer = Generate_Word(4);
    for (int i = 0; i < 4; i++)
    {
        Words[i + 15] = buffer[i];
    }
    Words[19] = '\0';

    return (Words);
}

char *Fill_Array_With_Keys(int length)
{
    char *Arr = (char *)malloc(sizeof(char) * 21 * length);
    if (Arr == NULL)
    {
        return (NULL);
    }

    for (int i = 0; i < length; i++)
    {
        char *key = Generate_Keys();
        for (int j = 0; j < 20; j++)
        {
            Arr[i * 21 + j] = key[j];
        }
        free(key);
    }

    return (Arr);
}

int main()
{
    srand((unsigned)time(NULL));

    int length = Read_Number();
    char *Arr = Fill_Array_With_Keys(length);

    for (int i = 0; i < length; i++)
    {
        printf("Array[%d] : ", i + 1);
        for (int j = 0; j < 20; j++)
        {
            printf("%c", Arr[i * 21 + j]);
        }
        putchar('\n');
    }

    free(Arr);
    return (0);
}
