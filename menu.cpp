

#include "game.h"



// функция main меню игры 
MenuResult menu() { 


    // начальное меню 
    std::string choice;
    print_slow("1. Начать игру");
    print_slow("2. Инструкция" );
    print_slow("3. Выход",2);

    print_slow("Выберите действие: "); 
    std::cin >> choice;
 

    // действия которые возможны 
    if (choice == "1") { 
        std::cout << std::endl; 
        print_slow("Начинаем игру...", 2);

        return MenuResult::Play; // начинаем игру 
    } 
    else if (choice == "2") { 
        std::cout << std::endl; 
        print_slow("ИНСТРУКЦИЯ:");
        print_slow("В этой игре вам нужно угадать загаданное число."); 
        print_slow("Вы должны вводить 4-значные числа с уникальными цифрами."); 
        print_slow("После каждой попытки вы получите подсказку в виде количества быков и коров."); 
        print_slow("Бык — правильная цифра стоит на правильном месте."); 
        print_slow("Корова — правильная цифра есть, но стоит не на своём месте."); 
        print_slow("Но также компьютер будет угадывать ваше число, и вы должны будете давать ему подсказки."); 
        print_slow("Удачи!", 2); 

        return MenuResult::Again; // возвращаемся в меню
    } 
    else if (choice == "3") {
        std::cout << std::endl ;
            print_slow("Выход из игры...", 1, 30);
            print_slow("До свидания!", 2, 30);

        return MenuResult::Exit; // конец игры, завершение 

    } 

    // если в cin пошло не что-то 
    else { 
        std::cout << std::endl;
        print_slow("Неверный выбор.");
        print_slow("Пожалуйста, выберите 1, 2 или 3.", 2);
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return MenuResult::Again; // возвращаемся в меню
    } 
}

MenuResult menu2() { 


    // начальное меню 
    std::string choice;
    print_slow("1. Player Guess");
    print_slow("2. Computer Guess" );
    print_slow("3. Duel");
    print_slow("4. Exit", 2);
 
    print_slow("Выберите действие: "); 
    std::cin >> choice;
 

    // действия которые возможны 
    if (choice == "1") { 
        std::cout << std::endl; 
        print_slow("Начинаем игру против компьютера...", 2);

        return MenuResult::Game1; // начинаем игру 
    } 
    else if (choice == "2") { 
        std::cout << std::endl; 
        print_slow("Начинаем игру против компьютера...", 2);

        return MenuResult::Game2; // начинаем игру 
    }
    else if (choice == "3") {
        std::cout << std::endl ;
            print_slow("Начинаем дуэль...", 2);

        return MenuResult::Game3; // начинаем игру 

    } 
    
        else if (choice == "4") {
        std::cout << std::endl ;
            print_slow("Выход в главное меню...", 2);

        return MenuResult::Exit; // конец игры, завершение 

    } 
    // если в cin пошло не то 
    else { 
        std::cout << std::endl;
        print_slow("Неверный выбор.");
        print_slow("Пожалуйста, выберите 1 или 2", 2);
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return MenuResult::Again; // возвращаемся в меню
    } 
}
