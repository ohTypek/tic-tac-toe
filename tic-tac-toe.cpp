#include <iostream>
#include <string>
#include "game.h"

// Class constructor
Game::Game(int x, int o) : x_win(x), o_win(o) {
  showMap();
}

// Method to display the game board
void Game::showMap() {
  std::cout << "_" << square[0] << "_|_" << square[1] << "_|_" << square[2] << "_\n"
            << "_" << square[3] << "_|_" << square[4] << "_|_" << square[5] << "_\n"
            << " " << square[6] << " | " << square[7] << " | " << square[8] << " \n";
}

// Method to place a symbol on the board
void Game::placeSymbol(int place, int turn) {
  this->square[place - 1] = signs[turn%2];
}

// Method to check if a given place is available
bool Game::checkPlace(int i) {
  if(square[i-1] == ' ' || square[i-1] == '_')
    return true;

  return false;
}

// Method to check if any player has won
bool Game::checkWin() {
  for (char sign: signs) {
    if((square[0]==sign && square[1] == sign && square[2] == sign)
    || (square[3]==sign && square[4] == sign && square[5] == sign)
    || (square[6]==sign && square[7] == sign && square[8] == sign)
    || (square[0]==sign && square[3] == sign && square[6] == sign)
    || (square[1]==sign && square[4] == sign && square[7] == sign)
    || (square[2]==sign && square[5] == sign && square[8] == sign)
    || (square[0]==sign && square[4] == sign && square[8] == sign)
    || (square[2]==sign && square[4] == sign && square[6] == sign))
      return true;
    }
    return false;
}

// Method to get current player's symbol based on the turn number
char Game::currentSign(int turn) {
  return square[turn%2];
}

// Class destructor
Game::~Game() {

  std::cout << "\nThe round has ended!" << std::endl;
  std::cout << "X has won " << x_win << " games." << std::endl;
  std::cout << "O has won " << o_win << " games." << std::endl << std::endl;

}

// Welcome function
void welcome() {
  std::cout << "The game is won by the player who wins 5 rounds." << std::endl
            << "Each number corresponds to a position on the board." << std::endl;

  std::cout << "_1_|_2_|_3_\n"
            << "_4_|_5_|_6_\n"
            << " 7 | 8 | 9 \n"
            << std::endl;
}

int main() {
  welcome();

  int place, x_win = 0, o_win = 0;

  while (x_win<5 && o_win<5) {
    // Creating a new game object for each round
    Game *tic = new Game(x_win, o_win);

    for (int i = 1; i <= 9; i++) {
      std::cout << "Where do you want to place your sign?: ";
      std::cin >> place;

      if(tic->checkPlace(place)) {
        tic->placeSymbol(place, i);
        tic->showMap();
      } else {
        std::cerr << "The spot is already occupied. Try again!" << std::endl;
        i--;
      }

      if(tic->checkWin()) {
        std::cout << tic->currentSign(i-1) << " wins!" << std::endl;

        // Updating win counters
        if (tic->currentSign(i-1) == 'X') {
          x_win++;
          tic->x_win++;
        }
        else {
          o_win++;
          tic->o_win++;
        }

        break;
      }

      if (i == 9 && !tic->checkWin())
      {
        std::cout << "It's a draw" << std::endl;
      }
      
    }

    // Deleting the game object after the round
    delete tic;

    if(x_win == 5 || o_win == 5) {
      std::cout << std::endl << "The game ended!" << std::endl;
      
      if(x_win > o_win)
        std::cout << "X has won the game!" << std::endl;
      else
        std::cout << "O has won the game!" << std::endl;
    }
  }

  std::cin.get();

  return 0;
}