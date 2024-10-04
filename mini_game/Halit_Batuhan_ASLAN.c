#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initialize_game();
void print_board();
void move_player(char);
char game_board[272];/*for keeping characters on the board*/
int ECTS_1 = 0;/*ECTS for first grade courses*/
int ECTS_2 = 0;/*ECTS for second grade courses*/
int position_p;/*to keep position of 'P'*/
int main()
{
	initialize_game();
	print_board();
	char move;/*to take move direction from user*/
	int previous_pos,new_pos;/*to keep positions of 'P'*/
	int movement = 0;/*to keep only movement which changes direction*/
	int try = 0;/*to keep total movement */
	int total_ECTS;/*total ECTS of first and second grades*/
	while(game_board[270] == 'X')
	{
		previous_pos= 0,new_pos=0;
		printf("Please enter your move (a,s,d,w): ");
		scanf(" %c",&move);/*taking move direction of 'P'*/
		/*controling user enter a valid value or not*/
		if(move == 'a'|| move == 'A'|| move == 's'|| move == 'S'|| move == 'd'|| move == 'D'|| move == 'w'|| move == 'W')
		{
			for(;game_board[previous_pos] != 'P';previous_pos++);/*keeping position before movement*/
			move_player(move);/*change position of 'P' and others if necessary*/
			for(;game_board[new_pos] != 'P';new_pos++);/*keeping position after movement*/
			try++;
			if(previous_pos != new_pos)/*if position has been changed increment movement*/
				movement++;
			print_board();/*printing new board*/
			total_ECTS = ECTS_1 + ECTS_2;
			printf("Total ECTS is %d\n",total_ECTS);/*printing total ECTS*/
			printf("Total try is %d\n",try);/*printing total try of movement*/
			printf("Total movement is %d\n",movement);/*printing movement*/
		}
		else/*if value is not acceptable printing warning message*/
			printf("!!Please enter a valid character\n");
	}
	printf("You have completed your game\n");
	return 0;
}
void print_board()
{
	int i = 0;/*index of char game_board*/
	for(;i<272;i++)
		printf("%c",game_board[i]);/*printing all characters of game_board*/
}
void move_player(char direction)
{
	int i = 0;
	int line_P = 1;/*to use line of P at the board*/
	int column_P = 1;/*to use column of P at the board*/
	/*finding the index of P*/
	while(game_board[i] != 'P')
	{
		if(game_board[i] == '\n')/*calculating line number of P*/
			line_P ++;
		i++;
	}
	column_P = i - ((line_P-1)*17) +1;/*finding column of P*/
	position_p = (line_P-1) * 17 + column_P -1 ;/*finding position of P*/
	if(direction == 'a' || direction == 'A')
	{
		if(column_P == 1)/*to check if user want to go lefter than the board size*/
			printf("!!You are on the left hand side of the board. You can not go left\n");
		/*if P is on the inner walls normal position, puts wall again*/
		if(((line_P) == 7 || (line_P) == 11) && (column_P>=7 && column_P<=11) && ECTS_1 == 32)
		{
			if(game_board[position_p-1] == '2')
				ECTS_2 += 8;
			game_board[position_p - 1] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the inner walls normal position, puts wall again*/
		else if(((line_P)<11 && (line_P)>7) && (column_P == 7 || column_P == 11) && ECTS_1 == 32)
		{
			if(game_board[position_p-1] == '2')
				ECTS_2 += 8;
			game_board[position_p - 1] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the outer walls normal position, puts wall again*/
		else if(((line_P) == 5 || (line_P) == 13) && (column_P>=5 && column_P<=13) && ECTS_2 == 24)
		{
			game_board[position_p - 1] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the outer walls normal position, puts wall again*/
		else if(((line_P)<13 && (line_P)>5) && (column_P == 5 || column_P == 13) && ECTS_2 == 24)
		{
			game_board[position_p - 1] = 'P';
			game_board[position_p] = '#';
		}
		/*taking '1' courses and increments ECTS_1*/
		else if(game_board[position_p-1] == '1')
		{
			ECTS_1 += 8;
			game_board[position_p - 1] = 'P';
			game_board[position_p] = '.';
		}
		/*taking '2' courses and increments ECTS_2*/
		else if(game_board[position_p-1] == '2')
		{
			ECTS_2 += 8;
			game_board[position_p - 1] = 'P';
			game_board[position_p] = '.';
		}
		/*change position of P*/
		else if(game_board[position_p-1] == '.')
		{
			game_board[position_p - 1] = 'P';
			game_board[position_p] = '.';
		}
		/*not allow user to pass through inner walls*/
		else if(game_board[position_p-1] == '#' && ECTS_1 != 32)
			printf("You have not get enough ECTS. Try to reach 32 ECTS\n");
		/*allow user to pass through inner walls*/
		else if(game_board[position_p-1] == '#' && ECTS_1 == 32 && (column_P == 8 || column_P == 12))
		{
			game_board[position_p-1] = 'P';
			game_board[position_p] = '.';
		}
		/*not allow user to pass through outer walls*/
		else if(game_board[position_p-1] == '#' && ECTS_1 == 32 && ECTS_2 != 24)
			printf("You have not get enough ECTS. Try to reach 56 ECTS\n");
		/*allow user to pass through outer walls*/
		else if(game_board[position_p-1] == '#' && ECTS_2 == 24)
		{
			game_board[position_p - 1] = 'P';
			game_board[position_p] = '.';
		}
	}
	else if(direction == 's' || direction == 'S')
	{
		if(line_P == 16)/*to check if user want to go lower than the board size*/
			printf("!!You are on the bottom of the board. You can not go downwards\n");
		/*if P is on the inner walls normal position, puts wall again*/
		if(((line_P) == 7 || (line_P) == 11) && (column_P>=7 && column_P<=11) && ECTS_1 == 32)
		{
			if(game_board[position_p+17] == '2')
				ECTS_2 += 8;
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the inner walls normal position, puts wall again*/
		else if(((line_P)<11 && (line_P)>7) && (column_P == 7 || column_P == 11) && ECTS_1 == 32)
		{
			if(game_board[position_p+17] == '2')
				ECTS_2 += 8;
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the outer walls normal position, puts wall again*/
		else if(((line_P) == 5 || (line_P) == 13) && (column_P>=5 && column_P<=13) && ECTS_2 == 24)
		{
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the outer walls normal position, puts wall again*/
		else if(((line_P)<13 && (line_P)>5) && (column_P == 5 || column_P == 13) && ECTS_2 == 24)
		{
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '#';
		}
		/*taking '1' courses and increments ECTS_1*/
		else if(game_board[position_p + 17] == '1')
		{
			ECTS_1 += 8;
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '.';
		}
		/*taking '2' courses and increments ECTS_2*/
		else if(game_board[position_p+17] == '2')
		{
			ECTS_2 += 8;
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '.';
		}
		/*change position of P*/
		else if(game_board[position_p+17] == '.')
		{
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '.';
		}
		/*not allow user to pass through inner walls*/
		else if(game_board[position_p+17] == '#' && ECTS_1 != 32)
			printf("You have not get enough ECTS. Try to reach 32 ECTS\n");
		/*allow user to pass through inner walls*/
		else if(game_board[position_p+17] == '#' && ECTS_1 == 32 && (line_P == 6 || line_P == 10))
		{
			game_board[position_p+17] = 'P';
			game_board[position_p] = '.';
		}
		/*not allow user to pass through outer walls*/
		else if(game_board[position_p+17] == '#' && ECTS_2 != 24)
			printf("You have not get enough ECTS. Try to reach 56 ECTS\n");
		/*allow user to pass through outer walls*/
		else if(game_board[position_p+17] == '#' && ECTS_2 == 24)
		{
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '.';
		}
		/*if P reaches X position*/
		else if(game_board[position_p+17] == 'X')
		{
			game_board[position_p + 17] = 'P';
			game_board[position_p] = '.';
		}
	}
	else if(direction == 'd' || direction == 'D')
	{
		if(column_P == 16)/*to check if user want to go righter than the board size*/
			printf("!!You are on the right hand side of the board. You can not go right\n");
		/*if P is on the inner walls normal position, puts wall again*/
		if(((line_P) == 7 || (line_P) == 11) && (column_P>=7 && column_P<=11) && ECTS_1 == 32)
		{
			if(game_board[position_p+1] == '2')
				ECTS_2 += 8;
			game_board[position_p + 1] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the inner walls normal position, puts wall again*/
		else if(((line_P)<11 && (line_P)>7) && (column_P == 7 || column_P == 11) && ECTS_1 == 32)
		{
			if(game_board[position_p+1] == '2')
				ECTS_2+=8;
			game_board[position_p + 1] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the outer walls normal position, puts wall again*/
		else if(((line_P) == 5 || (line_P) == 13) && (column_P>=5 && column_P<=13) && ECTS_2 == 24)
		{
			game_board[position_p + 1] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the outer walls normal position, puts wall again*/
		else if(((line_P)<13 && (line_P)>5) && (column_P == 5 || column_P == 13) && ECTS_2 == 24)
		{
			game_board[position_p + 1] = 'P';
			game_board[position_p] = '#';
		}
		/*taking '1' courses and increments ECTS_1*/
		else if(game_board[position_p+1] == '1')
		{
			ECTS_1 += 8;
			game_board[position_p + 1] = 'P';
			game_board[position_p ] = '.';
		}
		/*taking '2' courses and increments ECTS_2*/
		else if(game_board[position_p+1] == '2')
		{
			ECTS_2 += 8;
			game_board[position_p + 1] = 'P';
			game_board[position_p] = '.';
		}
		/*change position of P*/
		else if(game_board[position_p+1] == '.')
		{
			game_board[position_p + 1] = 'P';
			game_board[position_p] = '.';
		}
		/*not allow user to pass through inner walls*/
		else if(game_board[position_p+1] == '#' && ECTS_1 != 32)
			printf("You have not get enough ECTS. Try to reach 32 ECTS\n");
		/*allow user to pass through inner walls*/
		else if(game_board[position_p+1] == '#' && ECTS_1 == 32 && (column_P == 6 || column_P == 10))
		{
			game_board[position_p+1] = 'P';
			game_board[position_p] = '.';
		}
		/*not allow user to pass through outer walls*/
		else if(game_board[position_p+1] == '#' && ECTS_2 != 24)
			printf("You have not get enough ECTS. Try to reach 56 ECTS\n");
		/*allow user to pass through outer walls*/
		else if(game_board[position_p+1] == '#' && ECTS_2 == 24)
		{
			game_board[position_p + 1] = 'P';
			game_board[position_p] = '.';
		}
		/*if P reaches X position*/
		else if(game_board[position_p+1] == 'X')
		{
			game_board[position_p + 1] = 'P';
			game_board[position_p] = '.'; 
		}
	}
	else if(direction == 'w' || direction == 'W')
	{
		if(line_P == 1)/*to check if user want to go upper than the board size*/
			printf("!!You are on the top of the board. You can not go upwards\n");
		/*if P is on the inner walls normal position, puts wall again*/
		if(((line_P) == 7 || (line_P) == 11) && (column_P>=7 && column_P<=11) && ECTS_1 == 32)
		{
			if(game_board[position_p-17] == '2')
				ECTS_2 += 8;
			game_board[position_p - 17] = 'P';
			game_board[position_p] = '#';	
		}
		/*if P is on the inner walls normal position, puts wall again*/
		else if(((line_P)<11 && (line_P)>7) && (column_P == 7 || column_P == 11) && ECTS_1 == 32)
		{
			if(game_board[position_p-17] == '2')
				ECTS_2 += 8;
			game_board[position_p - 17] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the outer walls normal position, puts wall again*/
		else if(((line_P) == 5 || (line_P) == 13) && (column_P>=5 && column_P<=13) && ECTS_2 == 24)
		{
			game_board[position_p - 17] = 'P';
			game_board[position_p] = '#';
		}
		/*if P is on the outer walls normal position, puts wall again*/
		else if(((line_P)<13 && (line_P)>5) && (column_P == 5 || column_P == 13) && ECTS_2 == 24)
		{
			game_board[position_p - 17] = 'P';
			game_board[position_p] = '#';
		}
		/*taking '1' courses and increments ECTS_1*/
		else if(game_board[position_p-17] == '1')
		{
			ECTS_1 += 8;
			game_board[position_p-17] = 'P';
			game_board[position_p] = '.';
		}
		/*taking '2' courses and increments ECTS_2*/
		else if(game_board[position_p-17] == '2')
		{
			ECTS_2 += 8;
			game_board[position_p-17] = 'P';
			game_board[position_p] = '.';
		}
		/*change position of P*/
		else if(game_board[position_p-17] == '.')
		{
			game_board[position_p-17] = 'P';
			game_board[position_p] = '.';
		}
		/*not allow user to pass through inner walls*/
		else if(game_board[position_p-17] == '#' && ECTS_1 != 32)
			printf("You have not get enough ECTS. Try to reach 32 ECTS\n");
		/*allow user to pass through inner walls*/
		else if(game_board[position_p-17] == '#' && ECTS_1 == 32 && (line_P ==  8 || line_P == 12))
		{
			game_board[position_p-17] = 'P';
			game_board[position_p] = '.';
		}
		/*not allow user to pass through outer walls*/
		else if(game_board[position_p-17] == '#' && ECTS_2 != 24)
			printf("You have not get enough ECTS. Try to reach 56 ECTS\n");
		/*allow user to pass through outer walls*/
		else if(game_board[position_p-17] == '#' && ECTS_2 == 24)
		{
			game_board[position_p-17] = 'P';
			game_board[position_p] = '.';
		}
	}
}
void initialize_game()
{
	int point_2;/*to initialize positions of '2'*/
	int point_1;/*to initialize positions of '1'*/
	int line_2;/*generate random line value to put '2'*/
	int line_1;/*generate random line value to put '1'*/
	int column_2;/*generate random column value to put '2'*/
	int column_1;/*generate random column value to put '1'*/
	int count_2 = 0;/*number of randomly generated '2'*/
	int count_1 = 0;/*number of randomly generated '1'*/
	int pos_2[4];/*keeping positions of '2' in an game_board*/
	int pos_1[5];/*keeping positions of '1' in an game_board*/
	int index_pos_2 = 0;/*index for pos_2 array*/
	int index_pos_1 = 0;/*index for pos_1 array*/
	int line = 1;/*line number of board*/
	int column = 1;/*column number of board*/
	srand(time(NULL));/*every execution it updates time to generate new number*/
	/*generate numbr to position for '2'*/
	while(count_2<3)
	{
		line_2 = rand()%7 + 6;/*it generates between 6-12 for line*/
		if(line_2 == 6 || line_2 == 12)
		{
			index_pos_2 = 0;
			column_2 = rand()%7 +6;/*it generates between 6-12 for column*/
			point_2 = (line_2-1)*17+column_2-1;/*according to line-column it finds position for '2'*/
			while(index_pos_2 <= count_2)
			{
				if(pos_2[index_pos_2] == point_2)
				{
					count_2 = count_2;
					break;
				}
				else
					index_pos_2++;
			}
			if(index_pos_2 >= count_2)
			{
				pos_2[count_2] = point_2;
				count_2++;
			}
		}
		else
		{
			index_pos_2 = 0;
			column_2 = rand()%2 + 1;	
			if(column_2 == 1)
				point_2 = (line_2-1)*17+(5*column_2);
			else
				point_2 = (line_2-1)*17+(5*column_2)+1;
			while(index_pos_2<=count_2)
			{
				if(pos_2[index_pos_2] == point_2)
				{
					count_2 = count_2;
					break;
				}
				else
					index_pos_2++;
			}
			if(index_pos_2 >= count_2)
			{
				pos_2[count_2] = point_2;
				count_2++;
			}
		}
	}
	pos_2[count_2] = '\0';/*remark for end of array*/
	/*generate numbr to position for '1'*/
	while(count_1<4)
	{
		line_1 = rand()%3 + 8;/*it generates between 8-10 for line*/
		if(line_1 == 8 || line_1 == 10)
		{
			index_pos_1 = 0;
			column_1 = rand()%3 +8;/*it generates between 8-10 for column*/
			point_1 = (line_1-1)*17 + column_1-1;/*according to line-column it finds position for '1'*/
			while(index_pos_1 <= count_1)
			{
				if(pos_1[index_pos_1] == point_1)
				{
					count_1 = count_1;
					break;
				}
				else
					index_pos_1++;
			}
			if(index_pos_1>= count_1)
			{
				pos_1[count_1] = point_1;
				count_1++;
			}
		}
		else
		{
			index_pos_1= 0;
			column_1 = rand()%2 + 1;
			if(column_1 == 1)
				point_1 = (line_1-1)*17+(8*column_1)-1;
			else
				point_1 = (line_1-1)*17+(4*column_1)+1;
			while(index_pos_1<= count_1)
			{
				if(pos_1[index_pos_1] == point_1)
				{
					count_1 = count_1;
					break;
				}
				else
					index_pos_1++;
			}
			if(index_pos_1>= count_1)
			{
				pos_1[count_1] = point_1;
				count_1++;
			}
		}
	}
	pos_1[count_1] = '\0';/*remark for end of array*/
	/*according to line-column combinations it initialize board for some special characters*/
	for(;line <= 16;line++)
	{
		column = 0;
		for(;column<=16;)
		{
			column++;
			/*arrange for walls,'P' and other '.'*/
			if(line>4 && line <14 && column> 4 && column<14)
			{
				if(line == 5 || line == 13 || column == 5 || column == 13)
					game_board[(line-1)*17 + column-1] = '#';
				else if(line > 6 && line <12 && column> 6 && column<12)
				{
					if(line ==7  || line == 11 || column == 7 || column == 11)
						game_board[(line-1)*17 + column-1] = '#';
					else if(line == 9 && column == 9)
					{
						position_p = (line-1)*17 + column-1;
						game_board[position_p] = 'P';
					}
					else
						game_board[(line-1)*17 + column-1] = '.';
				}
				else
					game_board[(line-1)*17 + column-1] = '.';
			}
			else if(line == 16 && column == 16)
				game_board[(line*17)-2] = 'X';
			else
				game_board[(line-1)*17 + column-1] = '.';
		}
		/*putting new line character end of the lines*/
		game_board[(line-1)*17 + column-1] = '\n';
	}
	int j = 0;/*index for pos_2 game_board*/
	for(;j<count_2;j++)
		game_board[pos_2[j]] = '2';
	int k = 0;/*index for pos_1 game_board*/
	for(;k<count_1;k++)
		game_board[pos_1[k]] = '1';
}