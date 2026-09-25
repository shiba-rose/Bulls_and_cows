#pragma once

#include <string>
#include <vector>
#include <ctime>
extern std::vector<std::string> duel_start_phrases;
extern std::vector<std::string> duel_turn_phrases;
extern std::vector<std::string> duel_after_player_phrases;
extern std::vector<std::string> duel_player_win_phrases;
extern std::vector<std::string> duel_computer_win_phrases;
extern std::vector<std::string> duel_first_move_phrases;

std::string get_random_phrase(const std::vector<std::string>& phrases);
void print_instructions();
void print_demarcation();
void welcome_to_game();
