#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int total_attempts = 0;
    int userguess;
    srand(time(0)); 
    int number = rand() % 100 + 1; 
    cout << "Welcome to the Number Guessing Game" << endl;
    cout << "Guess a number between 1 and 100: " << endl;
    
    while (true) {
        cout << "Enter the number you have guessed: ";
        cin >> userguess;
        total_attempts++;
        
        if (userguess == number) {
            cout << "You have guessed the correct number in " << total_attempts << " total attempts" << endl;
            break;
        } else if (userguess < number - 10) {
            cout << "Too low! Try again: " << endl;
        } else if (userguess < number) {
            cout << "Little low! Try again: " << endl;
        } else if (userguess > number + 10) {    
            cout << "Too high! Try again: " << endl;    
        } else {
            cout << "Little high! Try again: " << endl;
        }
    }

    return 0;
}

