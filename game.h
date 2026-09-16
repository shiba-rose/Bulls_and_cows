#pragma once

#include <string>
#include <tuple>
#include <vector>            

// ===== Утилиты (function.cpp) =====
void print_slow(std::string text, int enter, int delay);
std::string generate_number();
bool check_number(std::string number);
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
    Exit  = 0,
    Again = 1,
    Play  = 2,
    Game1 = 3,
    Game2 = 4,
    Game3 = 5
};

// ===== Меню (menu.cpp) =====
MenuResult menu();
MenuResult menu2();

// ===== Игры (game.cpp) =====
void start_game_1();
void start_game_2();
void start_game_duel();