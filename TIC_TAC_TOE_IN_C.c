// Program of TIC - TAC - TOE game
//  Author : Hello Coder! I'm Joy and I made this simple game using C language.
//           I hope this game will help you for better understanding the logic.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, rule, player_move, computer_move, first_move, position, terminator;
char player_name[30], winner;
char board[9];
void show_board();
int generate_Random_Number(int);
void clear_board();
int check_freespace();
void check_winner(char);
char existance_of_winner();
int restarter();

int main()
{

    char ex_position = '1';
    for (i = 0; i < 9; i++)
    {
        board[i] = ex_position;
        ex_position++;
    }

    printf("\n=== Welcome to TIC - TAC - TOE Game! ===\n");
    printf("\n<-- Programmed by Joycodz -->\n");
    printf("\nDo you know the rules?\n");
    printf("If you don't know the rules then enter 1 to skip this press any key.\n");
    fflush(stdin);
    scanf("%d", &rule);
    if (rule == 1) // Rules of the game
    {
        printf("The rules are very simple.\n");
        printf("Who ever match three moves row wise or column wise or diagonally he/she wins.\nOtherwise it's a Draw.\n");
        printf("\n<-> Please look carefully at the following board and choose your move position according to the given numbers <->\n");
        show_board();
    }
    printf("\n< Let's start the game. >\n"); // Game started
    fflush(stdin);
    printf("\nPlease enter your name : "); // Taking the name of the player
    scanf("%s", &player_name);             // You can also use gets(player_name); and fgets(player_name, 30, stdin);;
    printf("\nX --> %s\nO--> Computer\n", player_name);

start: // for restarting the game
    terminator = 0;
    clear_board();
    first_move = generate_Random_Number(2); // To randomize first move between player and computer

    while (existance_of_winner() == ' ' && check_freespace() != 0)
    {
        if (first_move != 1)
        {
        make_move:
            printf("\nHi %s make your move!\n", player_name);
            scanf("%d", &player_move);
            if (board[player_move - 1] == ' ')
            {
                board[player_move - 1] = 'X';
                first_move = -1;
                show_board();
            }
            else
            {
                printf("INVALID MOVE!\n");
                goto make_move;
                fflush(stdin);
            }

            winner = existance_of_winner();
            check_winner(winner);
            if (terminator == 1)
            {
                if (restarter() == 1)
                {
                    goto start;
                }
                else
                {
                    break;
                }
            }
        }

        printf("\nComputer is making move ... \n");
    gen_move:
        computer_move = generate_Random_Number(8);
        if (check_freespace() > 0)
        {
            if (board[computer_move] == ' ')
            {
                board[computer_move] = 'O';
                show_board();
            }
            else if (check_freespace() == 1)
            {

                board[position] = 'O';
                show_board();
            }

            else
            {
                goto gen_move;
            }
            first_move = -1;
        }

        winner = existance_of_winner();
        check_winner(winner);

        if (terminator == 1)
        {
            if (restarter() == 1)
            {
                goto start;
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}

void show_board()
{
    if (check_freespace != 0)
    {
        printf("\n");
        printf(" %c | %c | %c ", board[0], board[1], board[2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[3], board[4], board[5]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[6], board[7], board[8]);
        printf("\n");
    }
}

void clear_board()
{
    for (i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}

int generate_Random_Number(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int check_freespace()
{
    int space = 9;
    for (i = 0; i < 9; i++)
    {
        if (board[i] != ' ')
        {
            space--;
        }
        else
        {
            position = i;
        }
    }
    return space;
}
char existance_of_winner()
{
    for (i = 0; i < 9; i += 3) // checking rows
    {
        if (board[i] == board[i + 1] && board[i] == board[i + 2])
        {
            return board[i];
        }
    }
    for (i = 0; i < 3; i++) // checking cols
    {
        if (board[i] == board[i + 3] && board[i] == board[i + 6]) // 1st b[0]==b[3] && b[0]==b[6]
        {                                                         // 2nd b[1]==b[4] && b[1]==b[7]
            return board[i];                                      // 3rd b[2]==b[5] && b[2]==b[8]
        }
    }
    for (i = 0; i < 3; i += 2)
    {
        if (i == 0)
        {
            if (board[i] == board[i + 4] && board[i] == board[i + 8])
            {
                return board[i];
            }
        }
        else if (i == 2)
        {
            if (board[i] == board[i + 2] && board[i] == board[i + 4])
            {
                return board[i];
            }
        }
    }

    return ' ';
}
void check_winner(char n)
{
    if (n == 'X')
    {
        printf("\nAwsome %s you have won!\n", player_name);
        terminator = 1;
    }
    else if (n == 'O')
    {
        printf("\nOops!\nComputer has won.\nBetter luck next time.\n");
        terminator = 1;
    }
    else if (check_freespace() == 0)
    {
        printf("\nMatch is ended with draw!\nBetter luck next time.\n");
        terminator = 1;
    }
}

int restarter()
{
    int restart;
    printf("\nDo you want to play again?\nEnter 1 to restart otherwise enter anything.\n");
    scanf("%d", &restart);
    if (restart == 1) // To play again
    {
        printf("Hey %s good luck!\n", player_name); // Send the control to the main function
        clear_board();
        return restart;
    }
    else
    {
        printf("Thanks for playing!");
    }

    return restart;
}
