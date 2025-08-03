#include<stdio.h>
#include <stdlib.h>
#include <time.h>

char board[74], playerToken[4][4]; 
int players;
int ActiveTokens[4][4], step[4][4]; 


void initialize_board(){
    for(int i=0; i<73; i++){
        board[i] = '-';
    }
    
    char tokens[4][4] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'P', 'Q', 'R', 'S'},
        {'W', 'X', 'Y', 'Z'}
    };

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            playerToken[i][j] = tokens[i][j];
    for (int i = 0; i < players; i++) {
        for (int j = 0; j < 4; j++) {
            ActiveTokens[i][j] = 0; // Initialize all tokens as inactive
            step[i][j] = 0; // Initialize steps for each token  
        }
    }

}
void print_start(){
    printf(" Loked Tokens:\n");
    for (int i=0; i<players;i++){
        printf("Player %d's home: ", i + 1);
        for (int j = 0; j < 4; j++) {
            if (ActiveTokens[i][j] == 0) {
                printf("%c |", playerToken[i][j]); 
            } else {
                printf(" - |"); 
            }
        }
        printf("\n");       
    }
}
void print_end(){    
    printf(" Home Tokens:\n");
    for (int i=0; i<players;i++){
        printf("Player %d's home: ", i + 1);
        for (int j = 0; j < 4; j++) {
            if (ActiveTokens[i][j] == 2) {
                printf("%c |", playerToken[i][j]); 
            } else {
                printf(" - |"); 
            }
        }
        printf("\n");       
    }
}
void print_board(){
    print_start();
    for(int i=0; i<73; i++){
        printf("%c |", board[i]);
    }
    printf("\n");
    print_end();
}

void available_tokens(int p, int r) {
    p--; // Adjust for 0-based index
    for(int i=0; i<4; i++){
        if (ActiveTokens[p][i] == 0 && r == 6) printf("%d (%c) \n", i + 1, playerToken[p][i]);
        else if (ActiveTokens[p][i] == 1 && step[p][i] + r < 57) printf("%d (%c) \n", i + 1, playerToken[p][i]);
    }
}

void handle(int x) {
    char token = board[x];
    for (int i = 0; i < players; i++) {
        for (int j = 0; j < 4; j++) {
            if (ActiveTokens[i][j] == 1 && playerToken[i][j] == token) {
                ActiveTokens[i][j] = 0; // Deactivate the token
                step[i][j] = 0; // Reset steps for the token
                board[x] = '-'; // Remove token from the board
                printf("Player %d's token %c has been sent back to home.\n", i + 1, playerToken[i][j]);
            }
        }
    }
}
void move(int p, int c, int r) {
    c--;
    p--; // Adjust for 0-based index
    int x;
    if (ActiveTokens[p][c] == 0 && r == 6) {
        ActiveTokens[p][c] = 1; // Activate the token
        step[p][c] = 1; // Reset steps for the new token
        board[step[p][c] + (p * 13)] = playerToken[p][c]; // Place token on the board
    }
    else if (ActiveTokens[p][c] == 1 && step[p][c] + r <= 57) {
        board[(step[p][c] + (p * 13))%52] = '-';
        step[p][c] += r; // Move the token forward
        if (step[p][c] >= 52) {
            x= step[p][c] + (p * 5) +1;
            if (board[x] != '-') printf("Invalid move, token cannot land on occupied space.\n");
            else {
                board[x] = playerToken[p][c]; // Place token in home
                if (step[p][c] == 57) ActiveTokens[p][c] = 2; // Mark token as in home
            }
        }
        else {
            x=(step[p][c] + (p * 13))%52;
            if (board[x] != '-') handle(x); // Handle collision
            else
                board[x] = playerToken[p][c]; // Place token on the board
        }
    } 
}
void chance(int i){
    int c;
    printf("dice rolled:");
    int r=(rand() % 6) + 1;
    printf(" %d \nselect the peice no. to move:\n",r);
    available_tokens(i,r);
    printf("Enter the token number to move (1-4) \n or 5 to skip: ");

    scanf("%d", &c);
    if (c < 1 || c > 4) {
        printf("Player %d skipped their turn.\n", i + 1);
        return;
    } 
    move(i, c, r);
}

int won() {
    for (int i = 0; i < players; i++) {
        int count = 0;  
        for (int j = 0; j < 4; j++) {
            if (ActiveTokens[i][j] == 2) {
                count++;
            }
        }
        if (count == 4) {
            printf("Player %d has won the game!\n", i + 1);
            return 1; // Game is won
        }
    }
    return 0; // Game is not won yet      
}
int main() {
    printf("Enter number of players (2-4): ");
    scanf("%d", &players);
    if (players < 2 || players > 4) {
        printf("Invalid number of players. Please enter a number between 2 and 4.\n");
        return 1;
    }
    initialize_board();
    print_board();
    srand(time(NULL));
    while (!won()) {
        for (int i = 0; i < players; i++) {
            printf("Player %d's turn:\n", i + 1);
            chance(i);
            // Additional game logic would go here
            print_board();
        }
    }
    printf("Game Over! \n");
    return 0;
}

