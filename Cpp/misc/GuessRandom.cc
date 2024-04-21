#include <iostream>
#include <random>
using namespace std;

#define MAXATTEMPTS 7
#define MAX 200
#define MIN 0

int main()
{
    int Guess;   // Guess number
    int Attempt; // Guess attempts
    int RndNum;  // The random "magic number"

    random_device rd;                           // obtain a random number from hardware
    mt19937 gen(rd());                          // seed the generator
    uniform_int_distribution<> distr(MIN, MAX); // define the range

    RndNum = distr(gen); // assign the rand value to magic number

    // Start Guess game
    cout << "Greetings! I have a number between " << MIN << " and " << MAX << " in mind." << endl
         << "You have a maximum of " << MAXATTEMPTS << " times to guess it right, can you do it?" << endl;

    for (Attempt = 0; Attempt < MAXATTEMPTS; Attempt++)
    {
        // Ask for input
        cout << Attempt << ". "
             << "What's your guess? ";
        cin >> Guess;
        // Validate input as intergers only
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bad entry. Enter a NUMBER: ";
            cin >> Guess;
        }
        // Validate input rang
        if (Guess < MIN || Guess > MAX)
        {
            cout << "Our of range" << endl;
            break;
        }

        if (Guess < RndNum) // input is lower
        {
            cout << "😜 Too low, yee scurry dog!" << endl;
        }
        else if (Guess > RndNum) // input is greater
        {
            cout << "😆 Too high, yee land lubber!" << endl;
        }
        else // input is equal to magic number
        {
            cout << "Avast! Yee guessed my secret number, yee did! 😊 --> " << RndNum << endl;
            break; // end loop when correct
        }
    }

    if (Attempt >= MAXATTEMPTS)
    {
        cout << "Yee out of guesses! Better luck next time, yee matey!" << endl
             << "My secret number was " << RndNum << endl;
    }

    return 0;
}
