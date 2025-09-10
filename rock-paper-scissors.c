#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement the game
int game(char you, char computer) {
    if (you == computer) return -1;

    if (you == 's' && computer == 'p') return 0;
    else if (you == 'p' && computer == 's') return 1;

    if (you == 's' && computer == 'z') return 1;
    else if (you == 'z' && computer == 's') return 0;

    if (you == 'p' && computer == 'z') return 0;
    else if (you == 'z' && computer == 'p') return 1;

    return -2; // invalid case
}

// Driver Code
int main() {
    int n;
    char you, computer;
    int result;

    srand(time(NULL));

    do {
        n = rand() % 100;
        if (n < 33)
            computer = 's';
        else if (n < 66)
            computer = 'p';
        else
            computer = 'z';

        printf("\nEnter s for STONE, p for PAPER and z for SCISSOR: ");
        scanf(" %c", &you); // space before %c to ignore leftover newline

        result = game(you, computer);

        if (result == -1) {
            printf("\nGame Draw!\n");
        }
        else if (result == 1) {
            printf("\nWow! You have won the game!\n");
        }
        else if (result == 0) {
            printf("\nOh! You have lost the game!\n");
        }
        else {
            printf("\nInvalid input! Please enter s, p or z.\n");
        }

        printf("You chose: %c | Computer chose: %c\n", you, computer);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &you); // reuse `you` for yes/no
    } while (you == 'y' || you == 'Y');

    printf("\nThanks for playing!\n");

    printf("\nPress Enter to exit...");
    getchar(); getchar(); // pause before exit
    return 0;
}
