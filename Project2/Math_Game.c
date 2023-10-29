#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define CLEAR_SCREEN "\x1b[H\x1b[2J"

enum enTypelevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperator { Add = 1, Sub = 2, Mul = 3, Div = 4, Mixe = 5 };

struct Count
{
	int RightAnswer;
	int WorngAnswer;
};

int Read_How_Many_Question() {
    int Number = 0;

    printf("How Many Questions do You Want To answer? ");
    scanf("%d", &Number);

    return Number;
}

enum enTypelevel Read_Question_level() 
{
    int Number = 0;
     
       do
       {
        	printf("Enter Question level [1: Easy, 2: Med, 3: Hard, 4: Mix]: ");
        	scanf("%d", &Number);

       }while (Number < 0 || Number > 4);

    return (enum enTypelevel)Number;
}

int Read_Operation_Type()
{
    int Number = 0;
   	
	do 
	{
        	printf("Enter Operation Type [1: Add, 2: Sub, 3: Mul, 4: Div, 5: Mix]: ");
        	scanf("%d", &Number);
	
    	}while (Number <= 0 || Number > 5);

    return Number;
}

int Random_Number(int from, int to) 
{
    int RandNum = rand() % (to - from + 1) + from;
    return RandNum;
}
void ChangeBackgroundColor(const char *color)
{
    printf("%s", color);
}
void IsResult_Add(int Nb1, int Nb2, char Type, struct Count *Cnt)
{
	int Result = 0;

    		printf("   %d\n %c\n   %d\n------------\n= ", Nb1, Type, Nb2);
    		scanf("%d", &Result);

        if(Result == (Nb1 + Nb2))
         {
		ChangeBackgroundColor(ANSI_COLOR_GREEN);
		Cnt->RightAnswer++;
                printf("\nRight Answer :-)\n\n");
		ChangeBackgroundColor(ANSI_COLOR_RESET);
         }
         else
         {
		ChangeBackgroundColor(ANSI_COLOR_RED);
		Cnt->WorngAnswer++;
                printf("\nWrong Answer :-(\n");
                printf("The Right Answer Is: %d\n\n", Nb1 + Nb2);
		ChangeBackgroundColor(ANSI_COLOR_RESET);
         }
}
void IsResult_Sub(int Nb1, int Nb2, char Type, struct Count *Cnt)
{
	 int Result = 0;
   	 printf("   %d\n %c\n   %d\n------------\n= ", Nb1, Type, Nb2);
   	 scanf("%d", &Result);

        if(Result == (Nb1 - Nb2))
         {
		ChangeBackgroundColor(ANSI_COLOR_GREEN);
		Cnt->RightAnswer++;
                printf("\nRight Answer :-)\n\n");
		ChangeBackgroundColor(ANSI_COLOR_RESET);
         }
         else
         {
		ChangeBackgroundColor(ANSI_COLOR_RED);
		Cnt->WorngAnswer++;
                printf("\nWrong Answer :-(\n");
                printf("The Right Answer Is: %d\n\n", Nb1 - Nb2);
		ChangeBackgroundColor(ANSI_COLOR_RESET);
         }
}
void IsResult_Mul(int Nb1, int Nb2, char Type, struct Count *Cnt)
{	
	 int Result = 0;
         printf("   %d\n %c\n   %d\n-----------\n= ", Nb1, Type, Nb2);
         scanf("%d", &Result);

        if(Result == (Nb1 * Nb2))
         {
		ChangeBackgroundColor(ANSI_COLOR_GREEN);
	        Cnt->RightAnswer++;
                printf("\nRight Answer :-)\n\n");
		ChangeBackgroundColor(ANSI_COLOR_RESET);
         }
         else
         {
		ChangeBackgroundColor(ANSI_COLOR_RED);
		Cnt->WorngAnswer++;
                printf("\nWrong Answer :-(\n");
                printf("The Right Answer Is: %d\n\n", Nb1 * Nb2);
		ChangeBackgroundColor(ANSI_COLOR_RESET);
         }
}
void IsResult_Div(int Nb1, int Nb2, char Type, struct Count *Cnt)
{
	 int Result = 0;

         printf("   %d\n %c\n   %d\n-----------\n= ", Nb1, Type, Nb2);
         scanf("%d", &Result);

        if(Result == (Nb1 / Nb2))
         {
		ChangeBackgroundColor(ANSI_COLOR_GREEN);
	        Cnt->RightAnswer++;
                printf("\nRight Answer :-)\n\n");
		ChangeBackgroundColor(ANSI_COLOR_RESET);
         }
         else
         {
		ChangeBackgroundColor(ANSI_COLOR_RED);
	        Cnt->WorngAnswer++;
                printf("\nWrong Answer :-(\n");
                printf("The Right Answer Is: %d\n\n", Nb1 / Nb2);
		ChangeBackgroundColor(ANSI_COLOR_RESET);
         }
}
void Check_OpType(int Nb1, int Nb2, enum enOperator Type, struct Count *Cnt)
{
	switch(Type)
	{
		case 1:
   	 		IsResult_Add(Nb1, Nb2, '+', Cnt);
			break;
		case 2:
			IsResult_Sub(Nb1, Nb2, '-', Cnt);
			break;
		case 3:
			IsResult_Mul(Nb1, Nb2, '*', Cnt);
			break;
		case 4:
			 IsResult_Div(Nb1, Nb2, '/', Cnt);
			 break;
		case 5:
			Check_OpType(Nb1, Nb2, Random_Number(1, 4), Cnt);
		default:
			printf("Invaled!!");
			break;
	}
}
void Mix_Level(int Numb, int *Nb1, int *Nb2)
{
	int Choice = 0;
	do
	{
		Numb--;
		Choice = Random_Number(1, 3);
		if(Choice == 1)
		{
			*Nb1 = Random_Number(1, 12);
            		*Nb2 = Random_Number(1, 12);
		}
		else if(Choice == 2)
		{
			*Nb1 = Random_Number(1, 35);
            		*Nb2 = Random_Number(1, 35);
		}
		else 
		{
			*Nb1 = Random_Number(1, 100);
            		*Nb2 = Random_Number(1, 100);
		}
		
	
	}while(Numb > 0);	
}
void Type_Question(int Type, int *Nb1, int *Nb2, int Num) 
{

    switch (Type)
 	{
        case 1:
            *Nb1 = Random_Number(1, 10);
            *Nb2 = Random_Number(1, 10);
            break;
        case 2:
            *Nb1 = Random_Number(10, 40);
            *Nb2 = Random_Number(10, 40);
            break;
        case 3:
            *Nb1 = Random_Number(30, 100);
            *Nb2 = Random_Number(30, 100);
            break;
        case 4:
            // Mix Type
             Mix_Level(Num, Nb1, Nb2);
            break;
        default:
            printf("Invalid Question Type\n");
	 }
}
void Header_Result(struct Count *Cnt)
{
	if(Cnt->RightAnswer > Cnt->WorngAnswer)
	{
		printf(CLEAR_SCREEN);
		ChangeBackgroundColor(ANSI_COLOR_GREEN);
		printf("\n\n\t\t\t------------------------------------------------\n");
                printf("                                   Final Results is PASS          \n");
                printf("\t\t\t------------------------------------------------\n");
	}
	else if(Cnt->RightAnswer < Cnt->WorngAnswer)
	{
		printf(CLEAR_SCREEN);
		ChangeBackgroundColor(ANSI_COLOR_RED);
		printf("\n\n\t\t\t------------------------------------------------\n");
                printf("                                    Final Results is FAIL          \n");
                printf("\t\t\t------------------------------------------------\n");
	}
	else
	{
		printf(CLEAR_SCREEN);
		ChangeBackgroundColor(ANSI_COLOR_YELLOW);
		printf("\n\n\t\t\t------------------------------------------------\n");
                printf("                                     Final Results is DRAW          \n");
                printf("\t\t\t------------------------------------------------\n\n");
	}
}
void Print_level(int level)
{
	if(level == 1)
	{
		printf("\t\t\tQuestion level     : Easy\n");
	}
	else if(level == 2)
	{
		printf("\t\t\tQuestion level     : Med\n");
	}
	else if(level == 3)
	{
		printf("\t\t\tQuestion level     : Hard\n");
	}
	else
	{
		printf("\t\t\tQuestion level     : MIX\n");
	}
	
}
void Print_Operation_Type(int Type)
{
	if(Type == 1)
	{
		printf("\t\t\tOpType              : +\n");
	}
	else if(Type == 2)
	{
		printf("\t\t\tOpType              : -\n");
	}
	else if(Type == 3)
	{
		printf("\t\t\tOpType              : *\n");
	}
	else if(Type == 4)
	{
		printf("\t\t\tOpType              : /\n");
	}
	else
	{
		printf("\t\t\tOpType              : MIX\n");
	}
}
void Final_Result(int level, int Type, int NumQue)
{
		struct Count *Cnt;

		Header_Result(Cnt);
		printf("\t\t\tNumber Of Question : %d\n", NumQue);
		Print_level(level);
		Print_Operation_Type(Type);
		printf("\t\t\tNumber Of Right Answer : %d\n", Cnt->RightAnswer);
		printf("\t\t\tNumber Of Worng Answer : %d\n", Cnt->WorngAnswer);
		printf("\n\t\t\t------------------------------------------------\n\n");
}
bool Play_Again()
{
    char response;
    while (1)
    {
        printf("Do you want to play again? (Y/N) ");
        scanf("%c", &response);

        if (response == 'Y' || response == 'y')
        {
            return true;
        }
        else if (response == 'N' || response == 'n')
        {
            return false;
        }
    }
}
void Print_Result(struct Count *Cnt)
{
    int Number = Read_How_Many_Question();
    int Count = 0;
    int level = Read_Question_level();
    int Type = Read_Operation_Type();

     do {

        	Count++;
        	printf("Question [%d/%d]\n\n", Count, Number);

        	int Nb1 = 0, Nb2 = 0;
        	Type_Question(level, &Nb1, &Nb2, Number);
        	Check_OpType(Nb1, Nb2, Type, Cnt);

    	} while (Count < Number);
	
	Final_Result(level, Type, Number);

	if(Play_Again())
	{
		printf(CLEAR_SCREEN);
		ChangeBackgroundColor(ANSI_COLOR_RESET);
		Print_Result(Cnt);
	}
	else
	{
		printf(CLEAR_SCREEN);
	}
}
int main()
{
	srand((unsigned)time(NULL));

	struct Count *Cnt = (struct Count *)malloc(sizeof(struct Count));
   	 
	if(Cnt == NULL)
	{
       		 exit(1);
    	}
	
	Cnt->RightAnswer = 0;
	Cnt->WorngAnswer = 0;	
	
    	Print_Result(Cnt);
	free(Cnt);
    	
	return (0);
}
