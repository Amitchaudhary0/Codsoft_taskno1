#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Random
{
protected:
  int randomPoint;
  int randomNo;

public:
  Random()
  {
    srand(time(0));
    randomPoint = (rand() % (50 - 10 + 1)) + 10;
  }
  int randomNum()
  {
    srand(time(0));
    randomNo = rand() % 10;
    return randomNo;
  }
};

class Game : protected Random
{
  int guessedNo, point = randomPoint, maxPoint = 100, bet, Random;

public:
  Game()
  {
    cout << "\n\n*** WELCOME TO THE NUMBER GUESSING GAME ***\n\n"
         << endl;
  jump:
    Random = randomNum();
    cout << "\nYou have " << point << " points out of " << maxPoint << endl;
    cout << "___Guess A Number Between 0 To 10__" << endl<< endl;
    cout << "Enter Your Guessed Number: ";
    cin >> guessedNo;

    while (point < maxPoint)
    {

    bet:
      cout << "Enter your bet: ";
      cin >> bet;
      if (bet > point)
      {
        cout << "You can't bet more than your points" << endl;
        goto bet;
      }
      else if (bet < 1)
      {
        cout << "you can't bet 0 or below" << endl;
        goto bet;
      }

      if (guessedNo < Random)
      {
        cout << "OPPS!! You Guessed too low" << endl;
        point -= bet;
        if (point <= 0)
        {
          cout << "\n\nYOU LOOSE!! You have no points to play with" << endl;
          exit(0);
        }
        cout << "\n You have now " << point << " points" << endl;
        cout << "\n\nGuess Again: ";
        cin >> guessedNo;
      }
      else if (guessedNo > Random)
      {
        cout << "OPPS!! You Guessed too high" << endl;
        point -= bet;
        if (point <= 0)
        {
          cout << "\n\nYOU LOOSE!! You have no points to play with" << endl;
          exit(0);
        }
        cout << "\n You have now " << point << " points" << endl;
        cout << "\n\nGuess Again: ";
        cin >> guessedNo;
      }
      else
      {
        cout << "Wow!! you won " << bet << " points\n"<< endl;
        point += bet;
        if (point < maxPoint)
        {
          goto jump;
        }
      }
    }
    cout << "\n\n\aCONGRATULATIONS!!!\n You have earned " << point << "points and you **WON**" << endl;
  }
};

int main()
{
  Game G1;
  return 0;
}