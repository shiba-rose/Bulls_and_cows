#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "game.h"




    void print_slow(std::string text, int enter= 1, int delay=3, int total_time_to_print_limit = 5000) { // функция для медленного вывода текста
        if (!text.empty() && text.length() * delay > total_time_to_print_limit){
            delay = total_time_to_print_limit / text.length();    
        }
        for (char c : text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
        for (int i = 0; i < enter; ++i) {
            std::cout << std::endl;
        }
    }

std::vector<std::string> generate_all_combinations() {
    std::vector<std::string> combinations;

    for (int i = 1023; i <= 9876; ++i) {
        std::string number = std::to_string(i);

        if (number.length() == 4 &&
            number[0] != number[1] &&
            number[0] != number[2] &&
            number[0] != number[3] &&
            number[1] != number[2] &&
            number[1] != number[3] &&
            number[2] != number[3]) {

            combinations.push_back(number);
        }
    }

    return combinations;
}

std::vector<std::string> filter_combinations(
        std::vector<std::string> combinations,
        std::string computer_input_number,
        int bulls,
        int cows) {

    std::vector<std::string> result;

    for (std::string number : combinations) {
        std::tuple<int, int> current_result =
            check_bulls_and_cows(computer_input_number, number);

        int current_bulls = std::get<0>(current_result);
        int current_cows  = std::get<1>(current_result);

        if (current_bulls == bulls && current_cows == cows) {
            result.push_back(number);
        }
    }

    return result;
}

//Функция вывода ограничителя
void print_demarcation(){
    char element {'='};
    int quantity {45};
    print_slow(std::string(quantity ,element));
    std::cout <<std::endl;
}

//Функция начала игры и приветствия
void welcome_to_game(){
    print_slow("Загрузка игры...");
    print_demarcation();
    print_slow("          Игра 'Быки и Коровы'          ");
    print_demarcation();
    std::cout << std::endl;
    print_slow("Добро пожаловать в игру!", 2, 30);
}

//Функция вывода инструкции
void print_instructions(){
    print_slow("ИНСТРУКЦИЯ:");
    print_slow("В этой игре вам нужно угадать загаданное число."); 
    print_slow("Вы должны вводить 4-значные числа с уникальными цифрами."); 
    print_slow("После каждой попытки вы получите подсказку в виде количества быков и коров."); 
    print_slow("Бык — правильная цифра стоит на правильном месте."); 
    print_slow("Корова — правильная цифра есть, но стоит не на своём месте."); 
    print_slow("Но также компьютер будет угадывать ваше число, и вы должны будете давать ему подсказки."); 
    print_slow("Удачи!",2);
}

//Функция очистки ввода
void  clearing_input(){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}