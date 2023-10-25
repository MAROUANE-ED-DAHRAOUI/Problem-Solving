#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define CLEAR_SCREEN "\x1b[H\x1b[2J"

int Read_Number_For_Round_Player()
{
    int Number = 0;
    do
    {
        printf("How Many Rounds (1 to 10)? ");
        scanf("%d", &Number);
    } while (Number <= 0 || Number > 10);

    return Number;
}

int Random_Number(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

int Player_Choice()
{
    int Choice = 0;
    do
    {
        printf("Your Choice: [1]: Stone, [2]: Paper, [3]: Scissors? ");
        scanf("%d", &Choice);

    } while (Choice <= 0 || Choice > 3);

    return Choice;
}

int Computer_Choice()
{
    return Random_Number(1, 3);
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
void ChangeBackgroundColor(const char *color)
{
    printf("%s", color);
}
void PrintWinner(const char *winnerColor, const char *winner)
{
    ChangeBackgroundColor(winnerColor);
    printf("Round Winner: %s\n", winner);
    printf(ANSI_COLOR_RESET);
}
void Play_Game(int Number)
{
    int CountRound = 0;
    int CountPlayer = 0;
    int CountComputer = 0;
    int DrawTime = 0;

    for (int i = 0; i < Number; i++)
    {
        CountRound++;

        printf("\nRound [%d] Begins:\n\n", CountRound);

        int PlayerChoice = Player_Choice();

        printf("\n-------------ROUND [%d]-----------------\n\n", CountRound);
        
	int ComputerChoice = Computer_Choice();

        printf("\nPlayer 1 Choice: ");
        if (PlayerChoice == 1)
            printf("Stone\n");
        else if (PlayerChoice == 2)
            printf("Paper\n");
        else if (PlayerChoice == 3)
            printf("Scissors\n");

        printf("Computer Choice: ");
        if (ComputerChoice == 1)
            printf("Stone\n");
        else if (ComputerChoice == 2)
            printf("Paper\n");
        else if (ComputerChoice == 3)
            printf("Scissors\n");

        if (ComputerChoice == PlayerChoice)
        {
            DrawTime++;
            PrintWinner(ANSI_COLOR_YELLOW, "No Winner");
        }
        else if ((ComputerChoice == 1 && PlayerChoice == 3) || (ComputerChoice == 2 && PlayerChoice == 1) || (ComputerChoice == 3 && PlayerChoice == 2))
        {
            CountComputer++;
            PrintWinner(ANSI_COLOR_RED, "Computer");
        }
        else
        {
            CountPlayer++;
            PrintWinner(ANSI_COLOR_GREEN, "Player1");
        }
    }

    printf(CLEAR_SCREEN);
    printf("\n---------------------------------------------------------------------\n\n");
    printf("                           +++  GAME OVER  +++                           \n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n---------------------------[Game Result]-----------------------------\n\n");

    printf("Game Round: %d\nPlayer1 Won Times: %d\nComputer Won Times: %d\nDraw Times: %d\n", CountRound, CountPlayer, CountComputer, DrawTime);

    if (CountPlayer > CountComputer)
    {
        PrintWinner(ANSI_COLOR_GREEN, "Final Winner: Player1");
    }
    else if (CountPlayer < CountComputer)
    {
        PrintWinner(ANSI_COLOR_RED, "Final Winner: Computer");
    }
    else
    {
        PrintWinner(ANSI_COLOR_YELLOW, "Final Winner: No Winner");
    }

    printf("---------------------------------------------------------------------------\n\n");
}

int main()
{
    srand((unsigned)time(NULL));

    int Number = Read_Number_For_Round_Player();
    Play_Game(Number);

    while (Play_Again())
    {
	 printf(CLEAR_SCREEN);
        Number = Read_Number_For_Round_Player();
        Play_Game(Number);
    }

    return 0;
}
