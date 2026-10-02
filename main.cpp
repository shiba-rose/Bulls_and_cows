#include "game.h"
int number_length = 4;

int main() {
    srand(time(0));
    print_greeting();

    // вызов функции меню и вызов самой игры 
    for (;;){
        switch(main_menu()) {

            case MenuResult::play: {
                bool go_main_menu = false;
                while (!go_main_menu) {
                    switch (play_menu()) {

                        case MenuResult::player_guess: 
                            start_player_guess();
                            break; 
                        case MenuResult::computer_guess:
                            start_computer_guess();
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
            case MenuResult::settings:
                settings_menu();
                continue;
            case MenuResult::exit: return 0; // завершение программы полностью 
            case MenuResult::again: continue; // повторение при вызове меню снова, например при ошибке 
            default: return 0; 
        }
    }
}