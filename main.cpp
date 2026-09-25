#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


#include "game.h"
#include "phrases.h"


int main() {
    //Вход в игру и приветствие
    welcome_to_game();
    // вызов функции меню и вызов самой игры 
    
    while (true) {
        switch(main_menu()) {

            case MenuResult::play: {
                bool go_main_menu = false;
                while (!go_main_menu) {
                    switch (play_menu()) {

                        case MenuResult::game_player_guess: 
                            start_game_1();
                            break; 
                        case MenuResult::game_computer_guess:
                            start_game_2();
                            break;
                        case MenuResult::game_duel:
                            start_game_duel();
                            break;
                        case MenuResult::again: 
                            continue;
                        case MenuResult::exit: break;
                        default: break; 
                    }
                    go_main_menu = true; 
                }
                continue;
            }
                // после игры отправляет в меню снова чтобы начать новую или выйти из игры
            case MenuResult::exit: return 0; // завершение программы полностью 
            case MenuResult::again: continue; // повторение при вызове меню снова, например при ошибке 
            default: return 0; 
        }
    }
}