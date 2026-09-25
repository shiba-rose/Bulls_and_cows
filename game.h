#pragma once

#include <string>
#include <tuple>
#include <vector>            

// ===== Утилиты (function.cpp) =====
void print_slow(std::string text, int enter= 1, int delay=3, int total_time_to_print_limit = 5000);
std::string generate_number();
bool check_number(std::string number);
void print_demarcation();
void welcome_to_game();
void print_instructions();
void  clearing_input();
std::tuple<int, int> check_bulls_and_cows(std::string secret, std::string player);
std::vector<std::string> generate_all_combinations();
std::vector<std::string> filter_combinations(
    std::vector<std::string> combinations,
    std::string computer_input_number,
    int bulls,
    int cows
);

// ===== Общий enum =====
enum class MenuResult {
    exit  = 0,
    again = 1,
    play  = 2,
    game_player_guess = 3,
    game_computer_guess = 4,
    game_duel = 5
};

// ===== Меню (menu.cpp) =====
MenuResult main_menu();
MenuResult play_menu();

// ===== Игры (game.cpp) =====
void start_game_1();
void start_game_2();
void start_game_duel();