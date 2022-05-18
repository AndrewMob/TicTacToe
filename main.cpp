//---------------------------------------------------
// Purpose:     Main program for the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              YOUR NAME - Andrew Mobley
//---------------------------------------------------

#include "tic4.h"
#include "tic4.cpp"

//---------------------------------------------------
// Main program to play Tic4 game
//---------------------------------------------------
int main()
{
   // Declare variables
   Tic4 game;
   int row, col;

   // Play game
   cout << "\nWelcome to 4x4 tic-tac-toe\n";
   game.PrintBoard();
   while (!game.IsFull())
   {
      // Get X move
      cout << "Enter X move: ";
      cin >> row >> col;

      while (game.SetBoard(row, col,'X') == false)
      {
         cout << "Enter X move: ";
         cin >> row >> col;
      }
      game.PrintBoard();

      // Check if X wins
      if (game.CheckWin('X'))
      {
         cout << "X wins!\n\n";
         return 0;
      }

    // Get O move by using FancyAI that randomly chooses a method
    game.FancyAI('O');

    game.PrintBoard();

      // Check if O wins
      if (game.CheckWin('O'))
      {
         cout << "O wins!\n\n";
         return 0;
      }
   }
   cout << "Sorry, nobody wins.\n\n";
   return 0;
}
