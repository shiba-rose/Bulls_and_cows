#include "game.h"

// функция main меню игры 
MenuResult main_menu() { 
    // начальное меню 
    std::string choice {output_main_menu()};
 
    // действия которые возможны 
    if (choice == "1") { 
        print_slow("Начинаем игру...", 2);
        return MenuResult::play; // начинаем игру 
    } 

    else if (choice == "2") {        
        print_instructions();
        return MenuResult::again; // возвращаемся в меню
    } 

    else if (choice == "3") {
        return MenuResult::settings;
    }
    else if (choice == "4") {
        print_slow("До свидания!", 1, 30);
        print_slow("Выход из игры...", 2, 30);
        return MenuResult::exit; // конец игры, завершение 
    } 

    // если в cin пошло не что-то 
    else { 
        cin_clear();
        print_slow("Пожалуйста, выберите 1, 2 или 3.", 2);
        return MenuResult::again; // возвращаемся в меню
    } 
}

MenuResult play_menu() { 
    // игровое меню 
    std::string choice {output_play_menu()};

    // действия которые возможны 
    if (choice == "1") { 
        print_slow("Начинаем игру против компьютера...", 2);
        return MenuResult::player_guess;  
    } 

    else if (choice == "2") { 
        print_slow("Начинаем игру против компьютера...", 2);
        return MenuResult::computer_guess; 
    }

    else if (choice == "3") {
        print_slow("Начинаем дуэль...", 2);
        return MenuResult::game_duel; 
    } 
    
    else if (choice == "4") {
        print_slow("Выход в главное меню...", 2);
        return MenuResult::exit; // конец игры, завершение 
    } 
    // если в cin пошло не то 
    else { 
        cin_clear();
        print_slow("Пожалуйста, выберите 1, 2, 3 или 4", 2);
        return MenuResult::again; // возвращаемся в меню
    } 
}
