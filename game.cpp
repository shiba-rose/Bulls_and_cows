#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <vector>

#include "game.h"
#include "phrases.h"



void start_game_1() {
    // Здесь логика игры_1
    std::string computer_output_number {generate_number()};
    
    for(;;){ 
        int bulls, cows;
        std::string user_input_number {input_player_number()};
        std::tie(bulls, cows) = check_bulls_and_cows(computer_output_number, user_input_number);

        if (check_user_win(bulls, cows)){
            break;
        }
    }
}


void start_game_2(){
    // Здесь логика игры_2
    std::vector<std::string> combinations {generate_all_combinations()};
    has_player_guessed_number();
     for(;;){
        std::string computer_input_number = combinations[rand() % combinations.size()];
        auto [bulls, cows] = check_computer_win(computer_input_number);

        if (bulls == 4){
            break;
        }
        combinations = filter_combinations(combinations, computer_input_number, bulls,cows);
        if (check_empty_combinations){
            break;
        } 
     }
}

// Здесь логика игры_3
void start_game_duel()
{
    std::string computer_output_number {generate_number()};
    std::string user_input_number;
    std::vector<std::string> combinations {generate_all_combinations()};
    std::string user_output_number;
   
    print_slow(get_random_phrase(duel_start_phrases), 2);
    has_player_guessed_number();
    print_slow(get_random_phrase(duel_first_move_phrases), 2);
    for (;;) {
        int bulls, cows;
        std::string user_input_number {input_player_number()};
        std::tie(bulls, cows) = check_bulls_and_cows(computer_output_number, user_input_number);

        if (check_user_win(bulls, cows)){
            break;
        }
        std::string computer_input_number = combinations[rand() % combinations.size()];
        std::tie(bulls, cows) = check_computer_win(computer_input_number);

        if (bulls == 4){
            break;
        }
        combinations = filter_combinations(combinations, computer_input_number, bulls,cows);
        if (check_empty_combinations){
            break;
        } 

    }

}