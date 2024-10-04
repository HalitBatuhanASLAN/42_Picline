#include<stdio.h>
#define line 5 /*total line of board*/
#define column 35 /*total column of board*/
/*defining special numbers for some characters*/
#define plus -1 
#define vertcal_line -2
#define minus -3
#define space -4
#define user_turn 1 /*1 is for user turn*/
#define computer_turn 2 /*2 is for user turn*/
#define number_cups 14 /*total cup number*/
/*defininig first and last indixes for computers cups
includinfg large cup in array which keeps quantity of stones*/
#define computer_cup_1 7
#define computer_cup_6 12
#define computer_large_cup 13
/*defininig first and last indixes for user cups
includinfg large cup in array which keeps quantity of stones*/
#define user_cup_1 0 
#define user_cup_6 5
#define user_large_cup 6
/*prototypes of functions*/
int game_play();
void print_board();
void initialize_stone_quantity();
void initialize_game();
int updating_cups();
int move();
int empty_or_not();
int is_one_of_empty();
int main()
{
    int number_of_stones,flag = 1,winner = 0;
    int board[line][column];
    int stone_quantity[number_cups];/*keep stone number for each cup*/
    printf("\nWelcome to game\n");
    printf("\nIn board the bottom row is yours and the top one is computers\n");
    /*taking total stone number for each player till accepted numbers are entered*/
    while(flag)
    {
        printf("\nEnter number of stones for each player(Multiple of 6) : ");
        scanf("%d",&number_of_stones);
        if(number_of_stones<=0 || number_of_stones % 6 != 0)
            printf("\n!!Enter number which is positive multiple of 6\n");
        else if(number_of_stones>0)
            flag = 0;
    }
    initialize_game(board,number_of_stones);
    initialize_stone_quantity(board,stone_quantity);
    printf("\n");
    print_board(board,stone_quantity);
    winner = game_play(board,stone_quantity);
    /*according to winner value prints winner*/
    if(winner < 0)
        printf("You win the game with %d stones. Congratulations:).\n",winner*-1);
    else if(winner > 0)
        printf("Computer win the game with %d stones.Next time maybe:).\n",winner);
    else if(winner == 0)
        printf("Game is tied with %d stones in each player:)\n",stone_quantity[user_large_cup]);
    return 0;
}
/*playing game, checking turns, cups are empty or not ...*/
int game_play(int board[line][column],int stone_quantity[number_cups])
{
    /*start with user*/
    int turn = user_turn,number_of_cup = 0,flag = 1,winner = 0,max_index;
    do
    {
        if(turn == user_turn)
            printf("\nIt is your turn\n\n");
        else if(turn == computer_turn)
            printf("\nIt is computers turn\n\n");
        if(turn == user_turn)
        {
            /*taking cup number and checks if it is valid or not*/
            printf("Enter the number of cup between 1-6 (cups are numbered from left to right) : ");
            scanf("%d",&number_of_cup);
            if(number_of_cup > 6 || number_of_cup < 1)
                printf("\n!!It is not number of cup\n");
            else
            {
                /*checking if cup has no stones in it*/
                number_of_cup = empty_or_not(stone_quantity,number_of_cup);
                if(number_of_cup == -1)
                {
                    printf("\n!!There is no any stones in that cup\n");
                    turn = user_turn;
                }
                else
                {
                    do
                    {
                        /*for index value decrement return value of move function*/
                        number_of_cup = move(board,stone_quantity,number_of_cup,turn)-1;                    
                        winner = is_one_of_empty(stone_quantity);
                    }
                    while(stone_quantity[number_of_cup] != 1 && number_of_cup != user_large_cup && winner == 0);
                    /*countinue in case game is not over and last cups after distribution has more than 1 stones
                    and number of cup is not equal to user large cup*/
                }
                /*check for some cases to updating turn*/
                if(number_of_cup == user_large_cup)
                    turn = user_turn;
                else if(stone_quantity[number_of_cup] == 1)
                    turn = computer_turn;
            }
        }
        else if(turn == computer_turn)
        {
            int i = computer_cup_6;
            int max = stone_quantity[i];
            max_index = i;
            /*for user find cup wihch has the most stones and first comes*/
            for(;i>=computer_cup_1;i--)
            {
                if(stone_quantity[i] >= max)
                {
                    max = stone_quantity[i];
                    max_index = i;
                }
            }
            number_of_cup = max_index;
            do
            {
                number_of_cup = move(board,stone_quantity,number_of_cup,turn)-1;
                winner = is_one_of_empty(stone_quantity);
            }
            while(number_of_cup != -1 && (stone_quantity[number_of_cup] != 1 && winner == 0));
            /*countinue in case stone number which is last one after distribution is not equal to 1 
            and game is not over and number of cup is not equal to -1(move returns 0 when last 
            cup is computer large cup and for indexis we decrement it so it becomes -1) */
            /*check for some special cases and if necessary change turn*/
            if(number_of_cup == computer_large_cup)
                turn = computer_turn;
            else if(stone_quantity[number_of_cup] == 1)
                turn = user_turn;
        }
        winner = is_one_of_empty(stone_quantity);/*check if one of sides cups are empty*/
    }
    while(flag && winner == 0);/*countinue in case winner is equal to 0 and flag is equal to 1*/
    /*find the winner with score if winner is user multiply score with -1*/
    if(stone_quantity[user_large_cup] > stone_quantity[computer_large_cup])
        winner = stone_quantity[user_large_cup] * -1;
    else if(stone_quantity[user_large_cup] < stone_quantity[computer_large_cup])
        winner = stone_quantity[computer_large_cup];
    else
        winner = 0 ;
    return(winner);
    /*return winner score and if game is tied return 0*/
}
/*prints the board*/
void print_board(int board[line][column],int stone_quantity[number_cups])
{
    int current_line = 0;
    int current_column = 0;
    int index_of_quantity = 0;
    for(current_line = 0;current_line < line;current_line++)
    {
        /*according to line updating index*/
        if(current_line == 1)
            index_of_quantity = computer_cup_6;
        if(current_line == 2)
            index_of_quantity = computer_large_cup;
        if(current_line == 3)
            index_of_quantity = user_cup_1;
        for(current_column = 0;current_column < column;current_column++)
        {
            /*prints special characters*/
            if(board[current_line][current_column] == plus)
                printf("+");
            else if(board[current_line][current_column] == vertcal_line)
                printf("|");
            else if(board[current_line][current_column] == minus)
                printf("-");
            else if(board[current_line][current_column] == space)
                printf(" ");
            else
            {
                /*if stone numbers is greater than or equal 10*/
                if(stone_quantity[index_of_quantity] >=10)
                {
                    printf("%d",stone_quantity[index_of_quantity] / 10);
                    printf("%d",stone_quantity[index_of_quantity] % 10);
                    current_column++;
                }
                else
                    printf("%d",stone_quantity[index_of_quantity] % 10);
                /*according to line updating index*/
                if(current_line == 1)
                    index_of_quantity --;
                if(current_line == 2)
                    index_of_quantity -= 7;
                if(current_line == 3)
                    index_of_quantity++;
            }
        }       
        printf("\n");
    }
}
/*initializing stone_quantity array*/
void initialize_stone_quantity(int board[line][column],int stone_quantity[number_cups])
{
    int current_line,current_column,index_of_quantity = 0;
    for(current_line = 0;current_line<line;current_line++)
    {
        /*updating index for line of numbers*/
        if(current_line == 1)
            index_of_quantity = computer_cup_6;
        if(current_line == 2)
            index_of_quantity = computer_large_cup;
        if(current_line == 3)
            index_of_quantity = user_cup_1;
        for(current_column = 0;current_column<column;current_column++)
        {
            /*if in board array it is in line of computer row*/
            if((current_line == 1 )&& (current_column >= 7 && current_column <= 27 && current_column % 4 == 3))
            {
                if(board[current_line][current_column + 1] != space)
                    stone_quantity[index_of_quantity] = board[current_line][current_column]*10 + board[current_line][current_column + 1];
                else
                    stone_quantity[index_of_quantity] = board[current_line][current_column];
                index_of_quantity--;/*because next number must be in previous index in stone_quantity array*/
            }
            /*if in board array it is in line of user row*/
            if((current_line == 3) && (current_column >= 7 && current_column <= 27 && current_column % 4 == 3))
            {
                if(board[current_line][current_column + 1] != space)
                    stone_quantity[index_of_quantity] = board[current_line][current_column]*10 + board[current_line][current_column + 1];
                else
                    stone_quantity[index_of_quantity] = board[current_line][current_column];
                index_of_quantity++;/*because next number must be in next index in stone_quantity array*/
            }
            /*if in board it is in line of large cups row*/
            if(current_line == 2 && (current_column == 2 || current_column == 31))
            {
                if(board[current_line][current_column + 1] != space)
                    stone_quantity[index_of_quantity] = board[current_line][current_column]*10 + board[current_line][current_column + 1];
                else
                    stone_quantity[index_of_quantity] = board[current_line][current_column];
                index_of_quantity -= 7;/*next number is for user large cup so update index for that*/
            }            
        }
    }
}
/*initializing board*/
void initialize_game(int board[line][column],int number_of_stones)
{
    int current_line = 0;
    int current_column = 0;
    int stone_for_cups = number_of_stones / 6;/*number of stones for each cup*/
    /*using of % operator is to make code shorter because some characters goes with a loop*/
    for(;current_line < line;current_line++)
    {
        for(current_column = 0;current_column < column;current_column++)
        {
            /*for special line-column combinations puts relevant number into the board array*/
            if((current_line == 0 || current_line == 4) && (current_column == 0 || current_column == 34 || (current_column>=5 && current_column <= 29 && current_column % 4 == 1)))
                board[current_line][current_column] = plus;
            else if((current_line == 2) && (current_column >= 9 && current_column <=25 && current_column % 4 == 1))
                board[current_line][current_column] = plus;
            else if((current_line <= 3 && current_line >= 1) &&(current_column == 0 || current_column == 34 || (current_column>=5 && current_column <= 29 && current_column % 4 == 1)))
                board[current_line][current_column] = vertcal_line;
            else if(current_line == 0 || current_line == 4)
                board[current_line][current_column] = minus;
            else if((current_line == 2) && (current_column>= 6 && current_column<= 28))
                board[current_line][current_column] = minus;
            else
                board[current_line][current_column] = space;
            /*puts number of stones into the array*/
            if(stone_for_cups>=10)
            {
                if((current_line == 1 || current_line == 3) && (current_column >= 7 && current_column <= 27 && current_column % 4 == 3))
                    board[current_line][current_column] = stone_for_cups/10;
                else if((current_line == 1 || current_line == 3) && (current_column >= 8 && current_column <= 28 && current_column % 4 == 0))
                    board[current_line][current_column] = stone_for_cups % 10;
            }
            else
            {    
                if((current_line == 1 || current_line == 3) && (current_column >= 7 && current_column <= 27 && current_column % 4 == 3))
                    board[current_line][current_column] = stone_for_cups;
            }
            /*for large cups*/
            if(current_line == 2 && (current_column == 2 || current_column == 31))
                board[current_line][current_column] = 0;
        }
    }
}
/*updating the stones for each cup*/
int updating_cups(int stone_quantity[number_cups],int number_of_cup,int turn)
{
    /*keeping number of stones which will be distributed */
    int total_stones = stone_quantity[number_of_cup];
    if(number_of_cup >= user_cup_1 && number_of_cup <= computer_cup_6)
    {
        /*updating the current cups as having 0 stones*/
        stone_quantity[number_of_cup] = 0;
        number_of_cup++;
        /*distributes stones till stones are run out*/
        while(total_stones != 0)
        {
            for(;number_of_cup<=computer_large_cup,total_stones>0;total_stones--)
            {
                if(turn == user_turn && number_of_cup == computer_large_cup)
                    number_of_cup = user_cup_1;
                else if(turn == computer_turn && number_of_cup == user_large_cup)
                    number_of_cup = computer_cup_1;
                stone_quantity[number_of_cup]++;/*increment stone in cup*/
                number_of_cup++;/*increment stone number*/
                /*if it is in end of array updating index*/
                if(number_of_cup == 14 && total_stones != 0)
                    number_of_cup = user_cup_1;
                if(number_of_cup == 14 && total_stones == 0)
                    number_of_cup = computer_cup_6;
            }
        }
    }
    /*returns last cup number*/
    return(number_of_cup);
}
/*distributing of stones with other functions*/
int move(int board[line][column],int stone_quantity[number_cups],int number_of_cup,int turn)
{
    /*updating stones for each cup and returns last cup after dsitributing*/
    number_of_cup = updating_cups(stone_quantity,number_of_cup,turn);
    printf("\n");
    /*prints board*/
    print_board(board,stone_quantity);
    return(number_of_cup);
}
/*for user choise checking if cup is empty or not*/
int empty_or_not(int stone_quantity[number_cups],int cup)
{
    cup--;/*for indexis in stone_quantity array*/
    if(stone_quantity[cup] == 0)
        cup = -1;
    return(cup);
    /*if empty returns -1 else returns indexis of cup*/
}
/*to check game is over or countinue*/
int is_one_of_empty(int stone_quantity[number_cups])
{
    int i,empty = 0,sum_user = 0,sum_computer = 0;
    for(i = user_cup_1;i<=user_cup_6;i++)
        sum_user += stone_quantity[i];
    for(i = computer_cup_1;i<=computer_cup_6;i++)
        sum_computer += stone_quantity[i];
    if(sum_user == 0 || sum_computer == 0)
        empty = 1;
    return(empty);
    /*if one of side's cups are empty returns 1 else 0*/
}