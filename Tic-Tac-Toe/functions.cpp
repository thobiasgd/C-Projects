#include <iostream>
#include <vector>

void greetings(){
  std::cout << "\nWellcome to the Tic-Tac-Toe game, be sure to have a friend to play and have fun!\n\n";
  
}

void display_game(std::vector<std::vector<char>>& matrix){

std::cout << "\n";
std::cout << matrix[0][0] << " | " << matrix[0][1] << " | " << matrix[0][2] << " \n";
std::cout << matrix[1][0] << " | " << matrix[1][1] << " | " << matrix[1][2] << " \n";
std::cout << matrix[2][0] << " | " << matrix[2][1] << " | " << matrix[2][2] << " \n\n";

}

std::vector<int> player_turn(bool playerX){
  std::vector<int> playerChoices(2);
  if (playerX){
    std::cout << "Player [X] turn, choose your line: ";
    std::cin >> playerChoices[0];
    std::cout << "Now, choose your column: ";
    std::cin >> playerChoices[1];
  }
  else{
    std::cout << "Player [O] turn, choose your line: ";
    std::cin >> playerChoices[0];
    std::cout << "Now, choose your column: ";
    std::cin >> playerChoices[1];
  }

  playerChoices[0]--;
  playerChoices[1]--;
  return(playerChoices);
}

void manager(std::vector<int> playerChoices, std::vector<std::vector<char>>& matrix, bool playerX){
  if (playerX == true){
    if (matrix[playerChoices[0]][playerChoices[1]] != '#'){
      std::cout << "\nIt is already chosen!\nPlease choose another place.\n";
      manager(player_turn(playerX), matrix, playerX);
    }
    else{
      matrix[playerChoices[0]][playerChoices[1]] = 'X';
    }
  }
  else{
    if (matrix[playerChoices[0]][playerChoices[1]] != '#'){
      std::cout << "\nIt is already chosen!\nPlease choose another place.\n";
      manager(player_turn(playerX), matrix, playerX);
    }
    else{
      matrix[playerChoices[0]][playerChoices[1]] = 'O';
    }
  }
  display_game(matrix);
}

bool victory_check(std::vector<std::vector<char>> matrix, bool playerX){
  char player;
  bool victory;

  if (playerX){
    player = 'X';
  }
  else{
    player = 'O';
  }

  //Horizontal
  if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && matrix[0][2] == player){
    std::cout << "Congratulations! Player [" << player << "] won!!";
    victory = true;
    return victory;
  }
  else if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && matrix[1][2] == player){
    std::cout << "Congratulations! Player [" << player << "] won!!";
    victory = true;
    return victory;
  }
  else if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && matrix[2][2] == player){
    std::cout << "Congratulations! Player [" << player << "] won!!";
    victory = true;
    return victory;
  }
  //Vertical
  else if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0] && matrix[2][0] == player){
    std::cout << "Congratulations! Player [" << player << "] won!!";
    victory = true;
    return victory;
  }
  else if (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && matrix[2][1] == player){
    std::cout << "Congratulations! Player [" << player << "] won!!";
    victory = true;
    return victory;
  }
  else if (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2] && matrix[2][2] == player){
    std::cout << "Congratulations! Player [" << player << "] won!!";
    victory = true;
    return victory;
  }
  //Diagonal
  else if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[2][2] == player){
    std::cout << "Congratulations! Player [" << player << "] won!!";
    victory = true;
    return victory;
  }
  else if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[2][0] == player){
    std::cout << "Congratulations! Player [" << player << "] won!!";
    victory = true;
    return victory;
  }
  else{
    victory = false;
  }
  //Teste de Empate
  int aux = 9;
  for (int k = 0; k < matrix.size(); k++){
    for (int l = 0; l < matrix.size(); l++){
      if (matrix[k][l] != '#'){
        aux--;
        if (aux == 0){
          std::cout << "Game over!, game tied.";
          victory = true; 
          return victory;
        }
      }
    }
  }
  return victory;
}



