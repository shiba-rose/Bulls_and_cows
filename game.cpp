#include "game.h"
int bulls;
int cows;

void start_player_guess() {
    std::string computer_output_number {generate_number()};

    for(;;) {   
        std::string user_input_number{get_valid_number()};
        std::tie(bulls, cows) = check_bulls_and_cows(computer_output_number, user_input_number);
        print_user_result(user_input_number, bulls, cows);
        
        if (bulls == number_length){
            print_slow(get_random_phrase(duel_player_win_phrases));
        }
    }
}


void start_computer_guess(){
    std::vector<std::string> combinations {generate_all_combinations()};
    std::string user_output_number;
    is_number_guessed();

    for(;;){
        std::string computer_input_number = combinations[rand() % combinations.size()];
        auto [bulls, cows] = print_computer_result(computer_input_number);

        if (bulls == number_length){
            print_slow(get_random_phrase(duel_computer_win_phrases));
            break;
        }
        else{
            combinations = filter_combinations(combinations, computer_input_number, bulls,cows);
            if (is_combinations_empty(combinations)){
                break;
            } 
        }
     }

}

void start_game_duel()
{
    std::string computer_output_number {generate_number()};
    std::vector<std::string> combinations {generate_all_combinations()};
    std::string user_output_number;
    print_slow(get_random_phrase(duel_start_phrases));
    is_number_guessed();
    print_slow(get_random_phrase(duel_first_move_phrases));

    for(;;){
        std::string user_input_number{get_valid_number()};
        std::tie(bulls, cows) = check_bulls_and_cows(computer_output_number, user_input_number);
        print_user_result(user_input_number, bulls, cows);
        
        if (bulls == number_length){
            print_slow(get_random_phrase(duel_player_win_phrases));
            std::cout << std::endl;
            break;
        }
        
        print_slow(get_random_phrase(duel_turn_phrases));

        std::string computer_input_number = combinations[rand() % combinations.size()];
        auto [bulls, cows] = print_computer_result(computer_input_number);

        if (bulls == number_length){
            print_slow(get_random_phrase(duel_computer_win_phrases));
            std::cout << std::endl;
            break;
        }
        else{
            combinations = filter_combinations(combinations, computer_input_number, bulls,cows);
            if (is_combinations_empty(combinations)){
                break;
            } 
        print_slow(get_random_phrase(duel_after_player_phrases));
        }
    }
}