#include <iostream>
#include <string>
#include "game.h"

Game::Game(int x, int o) : x_win(x), o_win(o) {
  showMap();
}

void Game::showMap() {
  std::cout << "_" << square[0] << "_|_" << square[1] << "_|_" << square[2] << "_\n"
            << "_" << square[3] << "_|_" << square[4] << "_|_" << square[5] << "_\n"
            << " " << square[6] << " | " << square[7] << " | " << square[8] << " \n";
}

void Game::placeSymbol(int place, int turn) {
  this->square[place - 1] = signs[turn%2];
}

bool Game::checkPlace(int i) {
  if(square[i-1] == ' ' || square[i-1] == '_')
    return true;

  return false;
}

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

char Game::currentSign(int turn) {
  return square[turn%2];
}

Game::~Game() {

  std::cout << "\nThe round has ended!" << std::endl;
  std::cout << "X has won " << x_win << " games." << std::endl;
  std::cout << "O has won " << o_win << " games." << std::endl << std::endl;

}

int main() {
  int place, x_win = 0, o_win = 0;

  while (x_win<5 && o_win<5)
  {
    Game *tic = new Game(x_win, o_win);

    for (int i = 1; i <= 9; i++) {
      std::cout << "Where do you want to place your sign?: ";
      std::cin >> place;

      if(tic->checkPlace(place)) {
        tic->placeSymbol(place, i);
        tic->showMap();
      } else {
        std::cerr << "Square already has a symbol. Try again!" << std::endl;
        i--;
      }

      if(tic->checkWin()) {
        std::cout << tic->currentSign(i-1) << " wins!" << std::endl;

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
        std::cout << "No one won" << std::endl;
      }
      
    }

    delete tic;

    if(x_win == 5 || o_win == 5) {
      std::cout << std::endl << "The game ended!" << std::endl;
      
      if(x_win > o_win)
        std::cout << "X has won the game!" << std::endl;
      else
        std::cout << "O has won the game!" << std::endl;
    }
  }
  

  system("PAUSE");
  return 0;
}