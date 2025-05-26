/*
 * Title : Tic tac toe
 * Name : Ajay P S
 * Date : November 2024
 * Working : 1. Select playing character for player 1 (O/X)
 * 2. Select the index value for the 2D box for player 1 and player 2
 */
#include <stdio.h>
#include <stdlib.h>

#define RED "\033[31m"
#define BLUE "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int reference_array[9];
void print_box(char box[3][3]);
void data_enter(char box[3][3], char player_key, char index);
int playing(char player_1, char player_2);
int winner(char box[3][3], char player_1, char player_2);
int check_index(char index, int *reference_array);

int main() 
{
    printf("TIC TAC TOE\n");
    printf("INSTRUCTIONS:\n");
    printf("1. Drawn a 3x3 grid\n");
    printf("2. Each player chooses a symbol X or O\n");
    printf("3. Players take turns marking spaces on the grid\n");
    printf("4. First to get 3 in a row horizontally, vertically or diagonally wins\n");
    printf("5. Else it's a tie\n");
    printf(GREEN "PRESS ENTER TO START THE GAME\n" RESET);
label:
    printf("*****************************\n");
    while ((getchar()) != '\n');
    for (int i = 0; i < 9; i++)
    {
    	reference_array[i] = i + 1;
    }
    printf("+---+---+---+\n");
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("| %d | %d | %d |\n", reference_array[k], reference_array[k+1], reference_array[k+2]);
        printf("+---+---+---+\n");
        k += 3;
    }
    printf("Player 1, select your choice (O/X): ");
    char Player_1, Player_2;
    while(scanf(" %c", &Player_1))
    {
	    if(Player_1 == 'X' || Player_1 == 'x' || Player_1 == 'O' || Player_1 == 'o')
	    	break;
	    else
		    printf("You have to enter only O or X: ");
    }
    Player_1 = (Player_1 == 'x'|| Player_1 == 'X') ? 'X' : (Player_1 == 'o' || Player_1 == 'O') ? 'O' : Player_1;
    Player_2 = (Player_1 == 'O') ? 'X' : 'O';

    if (playing(Player_1, Player_2) == 1)
        goto label;
    else
        return 0;
}

int playing(char player_1, char player_2) 
{
    int move_count = 0, flag = 0;
    char box[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    while (1) 
    {
        system("clear");
        print_box(box);

        char index;
        printf("Player 1 [%c]: ", player_1);
        while(scanf(" %c", &index) && (check_index(index, reference_array) == 0))
	{
		printf("Index is already taken, Enter another data:");
	}
        data_enter(box, player_1, index);
        move_count++;
        if (winner(box, player_1, player_2) == 1) 
	{
            system("clear");
            print_box(box);
            printf(GREEN "PLAYER 1 WINS\n" RESET);
            flag = 1;
            break;
        }

        if (move_count == 9) 
	{
            system("clear");
            print_box(box);
            printf(YELLOW "TIE\n" RESET);
            flag = 3;
            break;
        }

        system("clear");
        print_box(box);

        printf("Player 2 [%c]: ", player_2);
        while(scanf(" %c", &index) && (check_index(index, reference_array) == 0))
	{
		printf("Index is already taken, Enter another data:");
	}
        data_enter(box, player_2, index);
        move_count++;
        if (winner(box, player_1, player_2) == 2) 
	{
            system("clear");
            print_box(box);
            printf(GREEN "PLAYER 2 WINS\n" RESET);
            flag = 2;
            break;
        }
    }

    printf(RED "GAME OVER\n" RESET "1. Play Again\n2. Exit\nEnter your choice: ");
    int again;
    scanf("%d", &again);
    return (again == 1) ? 1 : 0;
}

int winner(char box[3][3], char player_1, char player_2) 
{
    for (int i = 0; i < 3; i++) 
    {
        if (box[i][0] == player_1 && box[i][1] == player_1 && box[i][2] == player_1) 
		return 1;
        if (box[0][i] == player_1 && box[1][i] == player_1 && box[2][i] == player_1) 
		return 1;
        if (box[i][0] == player_2 && box[i][1] == player_2 && box[i][2] == player_2) 
		return 2;
        if (box[0][i] == player_2 && box[1][i] == player_2 && box[2][i] == player_2) 
		return 2;
    }
    if (box[0][0] == player_1 && box[1][1] == player_1 && box[2][2] == player_1) 
	    return 1;
    if (box[0][2] == player_1 && box[1][1] == player_1 && box[2][0] == player_1) 
	    return 1;
    if (box[0][0] == player_2 && box[1][1] == player_2 && box[2][2] == player_2) 
	    return 2;
    if (box[0][2] == player_2 && box[1][1] == player_2 && box[2][0] == player_2)
	    return 2;
    return 0;
}

void data_enter(char box[3][3], char player_key, char index) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
	{
            if (box[i][j] == index) 
	    {
                box[i][j] = player_key;
                return;
            }
        }
    }
}

void print_box(char box[3][3]) 
{
    printf("\n+---+---+---+\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("| ");
        for (int j = 0; j < 3; j++) 
	{
            if (box[i][j] == 'X')
                printf(RED "%c" RESET, box[i][j]);
            else if (box[i][j] == 'O')
                printf(BLUE "%c" RESET, box[i][j]);
            else
                printf("%c", box[i][j]);

            printf(" | ");
        }
        printf("\n+---+---+---+\n");
    }
}
int check_index(char ref_ind, int *reference_array)
{
    if (ref_ind >= '1' && ref_ind <= '9')
    {
        int index = ref_ind - '1';
        if (reference_array[index] != -1)
        {
            reference_array[index] = -1;
            return 1;
        }
    }
    return 0;
}
