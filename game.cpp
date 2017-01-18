#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int trn = 1;
char board[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
int help[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int c[2] = { 0, 0 };
int q = 0;
int ch;

void print_board(){
	//printing the board
	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			printf(" %c |", board[i][j]);
		}
		printf("\n");
	}

}

void check(){

	if ((board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') || (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') || (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x') || (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x') || (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') || (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x') || (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') || (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x')){

		print_board();
		printf("Player1 'x' wins\n");
		trn = 3;

	}
	else if ((board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') || (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') || (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o') || (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') || (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') || (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') || (board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') || (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o')){

		print_board();
		printf("Conmputer 'o' wins\n");
		trn = 3;
	}

}


void pc_turn(){
	if (trn != 3){

		int rnd1, rnd2;

		do{
			rnd1 = rand() % 3;
			rnd2 = rand() % 3;

		} while (board[rnd1][rnd2] != ' ');

		board[rnd1][rnd2] = 'o';
		trn = 1;
		check();

	}


}

void turn(){
	int counter = 0;

	if (trn == 1){
		if (board[c[0]][c[1]] == ' '){
			board[c[0]][c[1]] = 'x';
			trn = 2;
			check();
			pc_turn();
		}
		else{
			printf("Please choose another place!\n");
		}
	}

	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			if (board[i][j] != ' ')
				counter++;
		}
	}

	if (counter == 9 && trn != 3){
		print_board();
		printf("Draw!\n");
		trn = 3;

	}

}

int main(){

	srand(time(NULL));

	//welcome msg
	printf("Welcome to XO game ! player one(x),Computer(o)\nPlayer 1 turn, please choose a location(ie.5):\n");

	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			printf(" %d |", help[i][j]);
		}
		printf("\n");
	}

	do{
		if (q == 1){
			print_board();
		}
		q = 1;

		do{
			printf("\nPlease choose a place(ie.1):");
			scanf_s("%d", &ch);
			switch (ch){
			case 1:
				c[0] = 0;
				c[1] = 0;
				break;
			case 2:
				c[0] = 0;
				c[1] = 1;
				break;
			case 3:
				c[0] = 0;
				c[1] = 2;
				break;
			case 4:
				c[0] = 1;
				c[1] = 0;
				break;
			case 5:
				c[0] = 1;
				c[1] = 1;
				break;
			case 6:
				c[0] = 1;
				c[1] = 2;
				break;
			case 7:
				c[0] = 2;
				c[1] = 0;
				break;
			case 8:
				c[0] = 2;
				c[1] = 1;
				break;
			case 9:
				c[0] = 2;
				c[1] = 2;
				break;
			}
		} while (ch > 9 || ch < 1);

		turn();

	} while (trn != 3);

	system("pause");
	return 0;

}