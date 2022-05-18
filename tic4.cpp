//---------------------------------------------------
// Purpose:     Implementation of the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              Andrew MObley - Completed implementation.
//---------------------------------------------------

#include "tic4.h"

//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Tic4::Tic4()
{
   ClearBoard();
}

//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Tic4::~Tic4()
{
   // Intentionally empty
}

//---------------------------------------------------
// Clear the Tic4 board
//---------------------------------------------------
void Tic4::ClearBoard()
{
   // Initialize Tic4 board
   for (int c = 0; c < SIZE; c++)
   for (int r = 0; r < SIZE; r++)
      board[r][c] = ' ';
   board_count = 0;
}

//---------------------------------------------------
// Set value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::SetBoard(const int row, const int col, const char player)
{
   // Error checking
   if ((row < 0) || (row >= SIZE) || 
       (col < 0) || (col >= SIZE) ||
       (board[row][col] != ' '))
      return false;

   // Set value of board
   board[row][col] = player;
   board_count++;
   return true;
}

//---------------------------------------------------
// Get value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::GetBoard(const int row, const int col, char & player)
{
   // Error checking
   if ((row < 0) || (row >= SIZE) || 
       (col < 0) || (col >= SIZE))
      return false;

   // Get value of board
   player = board[row][col];
   return true;
}

//---------------------------------------------------
// Check to see if player has won the game
//---------------------------------------------------
bool Tic4::CheckWin(const char player)
{
   // Check all the rows
   for (int r = 0; r < SIZE; r++)
   {
      // Count player pieces
      int count = 0;
      for (int c = 0; c < SIZE; c++)
         if (board[r][c] == player)
            count++;
      if (count == SIZE)
         return true;
   }

   // Check all the cols
   for (int c = 0; c < SIZE; c++)
   {
      // Count player pieces
      int count = 0;
      for (int r = 0; r < SIZE; r++)
         if (board[r][c] == player)
            count++;
      if (count == SIZE)
         return true;
   }

   // Check first diagonal
   int count = 0;
   for (int r = 0; r < SIZE; r++)
   {
      int c = r;
      if (board[r][c] == player)
         count++;
   }
   if (count == SIZE) 
      return true;
    
   // Check second diagonal
   count = 0;
   for (int r = 0; r < SIZE; r++)
   {
      int c = SIZE-1-r;
      if (board[r][c] == player)
         count++;
   }
   if (count == SIZE) 
      return true;
    
   // The player did not win
   return false;
}

//---------------------------------------------------
// Print the Tic4 board
//---------------------------------------------------
void Tic4::PrintBoard()
{
   // Draw column numbers
   cout << "\n     ";
   for (int c = 0; c < SIZE; c++)
      cout << c << "   ";
   cout << "\n";

   // Print the Tic4 board
   for (int r = 0; r < SIZE; r++)
   {
      // Draw dashed line
      cout << "   +";
      for (int c = 0; c < SIZE; c++)
         cout << "---+";
      cout << "\n";

      // Draw board contents
      cout << " " << r << " | ";
      for (int c = 0; c < SIZE; c++)
         cout << board[r][c] << " | ";
      cout << "\n";
   }

   // Draw dashed line
   cout << "   +";
   for (int c = 0; c < SIZE; c++)
      cout << "---+";
   cout << "\n\n";
}

//---------------------------------------------------
// Check if board is full
//---------------------------------------------------
bool Tic4::IsFull()
{
   return (board_count == SIZE * SIZE);
}

//---------------------------------------------------
// SimpleAI plays an 'O' at the first spot it can find 
// goes top to bottom left to right 
//---------------------------------------------------
bool Tic4::SimpleAI(const char player)
{
  //Goes through the rows then the colums 
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (board[r][c] == ' ')
            {
            board[r][c] = player;
            cout << "Simple AI plays at " << r << " "<< c << endl;
            board_count++;
            return true;
            }
        }
    }
    return false;
}
//---------------------------------------------------
// RandomAI finds a random location and checks if empty 
// then places an O there if empty
//---------------------------------------------------
bool Tic4::RandomAI(const char player)
{
    while(!IsFull())
    {
    int r = rand() % SIZE;
    int c = rand() % SIZE;
    if (board[r][c] == ' ')
            {
            board[r][c] = player;
            cout << "RandomAI AI plays at " << r << " "<< c << endl;
            board_count++;
            return true;
            }
    }
        return false;
} 
//---------------------------------------------------
// CleverAI checks the diagonal locations on the board 
// first and if empty plays there. If no diagonal spots 
// open it plays in the next free spot it can find
// searchs row then colums
//---------------------------------------------------
bool Tic4::CleverAI(const char player)
{
       // Check first diagonal
   for (int r = 0; r < SIZE; r++)
   {
      int c = r;
      if (board[r][c] == ' ')
      {
            board[r][c] = player;
            cout << "Clever AI plays at " << r << " "<< c << endl;
            board_count++;;
            return true;
      }
   }
   // Check second diagonal
   for (int r = 0; r < SIZE; r++)
   {
      int c = SIZE-1-r;
      if (board[r][c] == ' ')
      {
            board[r][c] = player;
            cout << "Clever AI plays at " << r << " "<< c << endl;
            board_count++;
            return true; 
      }
   }
   // checks the other rows and colums
   for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (board[r][c] == ' ')
                {
                board[r][c] = player;
                cout << "Clever AI plays at " << r << " "<< c << endl;
                board_count++;
                return true;
                }
        }
    }
   return false;
}
//---------------------------------------------------
// CleverAI checks the diagonal locations on the board 
// first and if empty plays there. If no diagonal spots 
// open it plays in the next free spot it can find
// searchs row then colums
//---------------------------------------------------
bool Tic4::FancyAI(const char player)
{
    int AI = rand() % 3;
    
    if  (AI == 0)
        {
        CleverAI(player);
        return true;
        }
    else if (AI == 1)
        {
        SimpleAI(player);
        return true;
        }
    else if (AI == 2)
        {
        RandomAI(player);
        return true;
        }
    else
        {
        return false;
        }
}