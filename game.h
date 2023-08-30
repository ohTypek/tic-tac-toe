#ifndef GAME_H
#define GAME_H

class Game {
  public:
    Game(int,int);
    void showMap();
    void placeSymbol(int, int);
    bool checkPlace(int);
    bool checkWin();
    char currentSign(int);
    ~Game();
    int x_win, o_win;

  private:
    char square[9] = {
      '_', '_', '_',
      '_', '_', '_',
      ' ', ' ', ' '
    };
    char signs[2] = {'X', 'O'};
};

#endif // GAME_H