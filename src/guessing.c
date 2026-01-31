#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int test_guess(int x, int guess){

	if(guess > x){
		return -1;
	}
	else if(guess < x){
		return +1;
	}
	return 0;
}


int main(){

	srand(time(NULL));

	bool in_game = true;

	while(in_game){

		int x = rand() % 101;
		int attempts = 1;

		printf("Im thinking of a number between 0 and 100, can you guess it?\n");

		bool is_guessing = true;

		while(is_guessing){

			int guess;
			printf("#%02d attempt ... ", attempts);
			if(scanf("%d", &guess) != 1){
				while(getchar() != '\n');
				printf("Please enter an integer\n");
				continue;
			}
			int test = test_guess(x, guess);
			if (test == 1){
				attempts ++;
				printf("Guess higher\n");
			}
			else if (test == -1){
				attempts ++;
				printf("Guess lower\n");
			}
			else{
				printf("Right guess! I was thinking of %d.", x);
				printf("\nAttempts necessary: %d", attempts);
				is_guessing = false;
			}

		}

		printf("\nDo you wish to play again? (y/n): ");
		char ans;
		scanf(" %c", &ans);
		if(ans != 'y'){
			printf("Bye!\n");
			in_game = false;
		}
	}

	return 0;
}

