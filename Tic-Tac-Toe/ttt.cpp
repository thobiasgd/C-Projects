#include <iostream>
#include <vector>
#include "functions.hpp"

std::vector<std::vector<char>> game_matrix(3, std::vector<char>(3, '#'));
bool playerX = true;
bool victory = false;

int main(){
  greetings();
  while (!victory){
    manager(player_turn(playerX), game_matrix, playerX);
    victory = victory_check(game_matrix, playerX);
    playerX = !playerX;
  }

  std::cout << "\n-- End game! Hope had fun! --\n";

}
