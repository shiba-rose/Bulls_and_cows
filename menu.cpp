#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "game.h"
#include "phrases.h"

// функция main меню игры 
MenuResult main_menu() { 

    // начальное меню 
    print_slow("1. Начать игру");
    print_slow("2. Инструкция");
    print_slow("3. Выход",2) ;
    print_slow("Выберите действие: ",0);
    std::string choice;
    std::cin >> choice;
    std::cout << std::endl;

    // действия которые возможны 
    //Начало игры
    if (choice == "1") { 
        print_slow("Начинаем игру...", 2);
        return MenuResult::play; // начинаем игру 
    } 
    //Инструкция
    else if (choice == "2") { 
        void print_instructions();
        return MenuResult::again; // возвращаемся в меню
    } 
    //Выход
    else if (choice == "3") {
        print_slow("Выход из игры...");
        print_slow("До свидания!", 2);
        return MenuResult::exit; // конец игры, завершение 
    } 
    // если в cin пошло не что-то 
    else { 
        print_slow("Неверный выбор.");
        print_slow("Пожалуйста, выберите 1, 2 или 3.", 2);
        clearing_input();
        return MenuResult::again; // возвращаемся в меню
    } 
}
// функция игрового меню игры 
MenuResult play_menu() { 

    // Игровое меню 
    print_slow("1. Player Guess");
    print_slow("2. Computer Guess");
    print_slow("3. Duel");
    print_slow("4. Exit", 2) ;
    std::cout << "Выберите действие: "; 
    std::string choice;
    std::cin >> choice;
    std::cout << std::endl;

    // действия которые возможны
    // выбор игры "Player Guess" 
    if (choice == "1") {      
        return MenuResult::game_player_guess; 
    } 
    // выбор игры "Computer Guess
    else if (choice == "2") { 
        return MenuResult::game_computer_guess;
    }
    // выбор игры "Duel"
    else if (choice == "3") {
        return MenuResult::game_duel;  
    } 
    // конец игры, завершение 
    else if (choice == "4") {
        print_slow("Выход в главное меню...", 2);
        return MenuResult::exit; 

    } 
    // если в cin пошло не то 
    else { 
        print_slow("Неверный выбор.");
        print_slow("Пожалуйста, выберите 1, 2, 3 или 4", 2);
        clearing_input();
        return MenuResult::again; // возвращаемся в меню
    } 
}
