/*
 Sam Sytsma
 C++ Fall 2022
 Due: Oct. 14, 2022
 Lab 4 Temperature Output
 This Lab is a demo of my ability to write a number-guessing game in which the computer selects a random
 number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
 the end of each game, users should be told whether they won or lost, and then be asked
 whether they want to play again. When the user quits, the program should output the
 total number of wins and losses. To make the game more interesting, the program
 should vary the wording of the messages that it outputs for winning, for losing, and for
 asking for another game. Create 10 different messages for each of these cases, and use
 random numbers to choose among them. This application should use at least one Do-
 While loop and at least one Switch statement. Write your C++ code using good style and
 documenting comments. You should use functions in your code as well. Your source
 code file should be called Lab5.cpp.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Precondition:     Include library iostream
//Postcondition:    Outputs game rules to screen
void Heading();

//Precondition:     Include libraries iostream, ctime.
//Postcondition:    Outputs entire game.
void Game(int num, int guess, int tries, int again, int win, int loss);

//Precondition:     Include library iostream
//Postcondition:    Outputs wrong answer statment
void Wrong();

//Precondition:     Include library iostream
//Postcondition:    Outputs correct answer statment
void Correct();

//Precondition:     Include library iostream
//Postcondition:    Stores value in again. Outputs new game statments.
void NewGame(int& again);

int main() {
    int num = 0; int guess = 0; int tries = 0; int again = 0; int win = 0; int loss = 0;
    Heading();
    Game(num, guess, tries, again, win, loss);
    return 0;
}

void Heading(){
    cout << "Welcome to the Random Number guessing game!!\nYou will have 20 attempts to guess a random number between 1-100\nPlease enter one guess at a time\n";
}
void Game(int num, int guess, int tries, int again, int win, int loss){
    srand(time(0));             //seeds random number
    num = rand() % 100 + 1;     //sets value of number to guess
        do
        {
            cout << "Enter a guess between 1 and 100 : ";
            cin >> guess;
            tries++;           //adds on to the value in tries to make it reach 20 and end that attempt of the game
            
            if (guess != num)
                Wrong();
            else
                Correct();
            
            if (tries == 20 || guess == num){     //2 end statments to put the game in new game mode
                if (tries == 20){
                    cout << "Too many guesses\n";
                    NewGame(again);
                    loss++;
                }
                if (guess == num){
                    NewGame(again);
                    win++;
                }
                    if (again == 1){
                        num = rand() % 100 + 1;
                        tries = 0;
                        continue;
                    }
                    else
                        break;
            }
        } while (again != 2);
    cout << "Your final score was " << win << " win(s) and " << loss << " loss(es).\n";

}
void Wrong(){
    int incorrectc;
    incorrectc = 1 + (rand()%10);   //generates random number to decide which case to run
    switch (incorrectc){
        case 1:
            cout << "Wrong";
            break;
        case 2:
            cout << "Nope";
            break;
        case 3:
            cout << "Try again";
            break;
        case 4:
            cout << "Loser";
            break;
        case 5:
            cout << "L + Ratio";
            break;
        case 6:
            cout << "Incorrect";
            break;
        case 7:
            cout << "Naaaahhhhhh";
            break;
        case 8:
            cout << "Not Correct";
            break;
        case 9:
            cout << ":(";
            break;
        default:
            cout << "You are saddly incorrect";
            break;
    }
    cout << endl;
}
void Correct(){
    int correctc;
    correctc = 1 + (rand()%10);     //generates random number to decide which case to run
    switch (correctc){
        case 1:
            cout << "Right";
            break;
        case 2:
            cout << "Yuppers";
            break;
        case 3:
            cout << "You are right";
            break;
        case 4:
            cout << "Congrats";
            break;
        case 5:
            cout << "You got lucky";
            break;
        case 6:
            cout << "W";
            break;
        case 7:
            cout << "You done it";
            break;
        case 8:
            cout << "Correct";
            break;
        case 9:
            cout << ":)";
            break;
        default:
            cout << "You are saddly..... correct!";
            break;
    }
    cout << endl;
}
void NewGame(int& again){
    int newgamec;
    newgamec = 1 + (rand()%10);     //generates random number to decide which case to run
    switch (newgamec){
        case 1:
            cout << "If you would want to play again enter 1, if you want to give up enter 2: ";
            cin >> again;
            break;
        case 2:
            cout << "Play again? 1 yes | 2 no: ";
            cin >> again;
            break;
        case 3:
            cout << "Another go? 1 yes | 2 no: ";
            cin >> again;
            break;
        case 4:
            cout << "Run it back? 1 yes | 2 no: ";
            cin >> again;
            break;
        case 5:
            cout << "Give it another go? 1 yes | 2 no: ";
            cin >> again;
            break;
        case 6:
            cout << "Go again? 1 yes | 2 no: ";
            cin >> again;
            break;
        case 7:
            cout << "Be a man, play again. 1 retry | 2 end game: ";
            cin >> again;
            break;
        case 8:
            cout << "Again? 1 yes | 2 no: ";
            cin >> again;
            break;
        case 9:
            cout << "I know you want to go again. 1 retry | 2 end game: ";
            cin >> again;
            break;
        default:
            cout << "Just one more game. 1 retry | 2 end game: ";
            cin >> again;
            break;
    }
    cout << endl;
}

