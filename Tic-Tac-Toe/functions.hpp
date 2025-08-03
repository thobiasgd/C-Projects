void display_game(std::vector<std::vector<char>>& matrix);

void greetings();

void manager(std::vector<int> playerChoices, std::vector<std::vector<char>>& matrix, bool playerX);std::vector<int> player_turn(bool playerX);

bool victory_check(std::vector<std::vector<char>> matrix, bool playerX);
