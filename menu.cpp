#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


#include "game.h"



// функция main меню игры 
MenuResult menu() { 


    // начальное меню 
    std::string choice;
    std::cout << "1. Начать игру" << std::endl 
        << "2. Инструкция" << std::endl 
        << "3. Выход" << std::endl 
        << std::endl; 
 
    std::cout << "Выберите действие: "; 
    std::cin >> choice;
 

    // действия которые возможны 
    if (choice == "1") { 
        std::cout << std::endl; 
        print_slow("Начинаем игру...", 2, 30);

        return MenuResult::Play; // начинаем игру 
    } 
    else if (choice == "2") { 
        std::cout << std::endl; 
        print_slow("ИНСТРУКЦИЯ:", 1, 5);
        print_slow("В этой игре вам нужно угадать загаданное число.", 1, 5); 
        print_slow("Вы должны вводить 4-значные числа с уникальными цифрами.", 1, 5); 
        print_slow("После каждой попытки вы получите подсказку в виде количества быков и коров.", 1, 5); 
        print_slow("Бык — правильная цифра стоит на правильном месте.", 1, 5); 
        print_slow("Корова — правильная цифра есть, но стоит не на своём месте.", 1, 5); 
        print_slow("Но также компьютер будет угадывать ваше число, и вы должны будете давать ему подсказки.", 1, 5); 
        print_slow("Удачи!", 2, 30); 

        return MenuResult::Again; // возвращаемся в меню
    } 
    else if (choice == "3") {
        std::cout << std::endl ;
            print_slow("Выход из игры...", 2, 30);
            print_slow("До свидания!", 2, 30);

        return MenuResult::Exit; // конец игры, завершение 

    } 

    // если в cin пошло не что-то 
    else { 
        std::cout << std::endl;
        print_slow("Неверный выбор.", 1, 30);
        print_slow("Пожалуйста, выберите 1, 2 или 3.", 2, 30);
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return MenuResult::Again; // возвращаемся в меню
    } 
}

MenuResult menu2() { 


    // начальное меню 
    std::string choice;
    std::cout << "1. Player Guess" << std::endl 
        << "2. Computer Guess" << std::endl 
        << "3. Duel" << std::endl
        << "4. Exit" << std::endl
        << std::endl; 
 
    std::cout << "Выберите действие: "; 
    std::cin >> choice;
 

    // действия которые возможны 
    if (choice == "1") { 
        std::cout << std::endl; 
        print_slow("Начинаем игру против компьютера...", 2, 30);

        return MenuResult::Game1; // начинаем игру 
    } 
    else if (choice == "2") { 
        std::cout << std::endl; 
        print_slow("Начинаем игру против компьютера...", 2, 30);

        return MenuResult::Game2; // начинаем игру 
    }
    else if (choice == "3") {
        std::cout << std::endl ;
            print_slow("Начинаем дуэль...", 2, 30);

        return MenuResult::Game3; // начинаем игру 

    } 
    
        else if (choice == "4") {
        std::cout << std::endl ;
            print_slow("Выход в главное меню...", 2, 30);

        return MenuResult::Exit; // конец игры, завершение 

    } 
    // если в cin пошло не то 
    else { 
        std::cout << std::endl;
        print_slow("Неверный выбор.", 1, 30);
        print_slow("Пожалуйста, выберите 1 или 2", 2, 30);
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return MenuResult::Again; // возвращаемся в меню
    } 
}
