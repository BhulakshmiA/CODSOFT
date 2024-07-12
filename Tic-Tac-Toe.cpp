
#include <iostream>
using namespace std;
const int SIZE = 3;
char board[SIZE][SIZE];
char currentMarker;
int currentPlayer;

void initializeBoard() {
    char counter = '1';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = counter++;
        }
    }
}

void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "| ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / SIZE;
    int col = (slot - 1) % SIZE;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }
    return 0;
}

void switchPlayer() {
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void startGame() {
    initializeBoard();
    cout << "Player 1, choose your marker (X or O): ";
    char markerPlayer1;
    cin >> markerPlayer1;
    currentPlayer = 1;
    currentMarker = markerPlayer1;
    drawBoard();
    int winner;
    for (int turn = 0; turn < SIZE * SIZE; turn++) {
        cout << "Player " << currentPlayer << ", enter your slot (1-9): ";
        int slot;
        cin >> slot;
        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again!" << endl;
            turn--;
            continue;
        }
        if (!placeMarker(slot)) {
            cout << "Slot occupied! Try again!" << endl;
            turn--;
            continue;
        }
        drawBoard();
        winner = checkWinner();
        if (winner != 0) {
            cout << "Player " << winner << " wins! Congratulations!" << endl;
            return;
        }
        switchPlayer();
    }
    cout << "It's a tie!" << endl;
}

int main() {
    char playAgain;
    do {
        startGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}

