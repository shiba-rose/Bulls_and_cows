#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


#include "game.h"



int main() {
    srand(time(0));
    print_slow("Загрузка игры...", 2, 30);

    std::cout << "========================================" << std::endl;
    print_slow("          Игра 'Быки и Коровы'          ", 1, 30);
    std::cout << "========================================" << std::endl
        << std::endl;

    print_slow("Добро пожаловать в игру!", 2, 30);

    // вызов функции меню и вызов самой игры 
    
    while (true) {
        switch(menu()) {

            case MenuResult::Play: {
                bool go_main_menu = false;
                while (!go_main_menu) {
                    switch (menu2()) {

                        case MenuResult::Game1: 
                            start_game_1();
                            break; 
                        case MenuResult::Game2:
                            start_game_2();
                            break;
                        case MenuResult::Game3:
                            start_game_duel();
                            break;
                        case MenuResult::Again: 
                            continue;
                        case MenuResult::Exit: break;
                        default: break; 
                    }
                    go_main_menu = true; 
                }
                continue;
            }
                // после игры отправляет в меню снова чтобы начать новую или выйти из игры
            case MenuResult::Exit: return 0; // завершение программы полностью 
            case MenuResult::Again: continue; // повторение при вызове меню снова, например при ошибке 
            default: return 0; 
        }
    }
}