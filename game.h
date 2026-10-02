#pragma once

#include <string>
#include <tuple>
#include <vector>  
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <utility>

#include "phrases.h"
extern int number_length;
// ===== Утилиты (function.cpp) =====

//функции вывода
void cin_clear();
void print_slow(std::string text, int enter = 1, int delay = 3);
void print_separator(char separator_symbol = '=', int separator_length = 40);
std::string get_random_phrase(const std::vector<std::string>& phrases);
void print_greeting();
std::string output_main_menu();
std::string output_play_menu();
void print_instructions();

// Функции алгоритмы для игр
std::string generate_number();
bool check_number(std::string number);
std::vector<std::string> generate_all_combinations();
std::tuple<int, int> check_bulls_and_cows(std::string secret, std::string player);
std::vector<std::string> filter_combinations(
    std::vector<std::string> combinations,
    std::string computer_input_number,
    int bulls,
    int cows
);
std::string get_valid_number();
void print_user_result(std::string user_input_number, int bulls, int cows);
void is_number_guessed();
bool is_valid_bulls_and_cows(int bulls, int cows);
std::pair<int, int> print_computer_result(std::string computer_input_number);
bool is_combinations_empty(std::vector<std::string> combinations);
// ===== Общий enum =====
enum class MenuResult {
    exit  = 0,
    again = 1,
    play  = 2,
    player_guess = 3,
    computer_guess = 4,
    game_duel = 5,
    settings = 6
};

// ===== Меню (menu.cpp) =====
MenuResult main_menu();
MenuResult play_menu();

// ===== Игры (game.cpp) =====
void start_player_guess();
void start_computer_guess();
void start_game_duel();