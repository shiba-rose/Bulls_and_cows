#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <ctime>
#include <thread>

#include "game.h"
#include "phrases.h"


void print_slow(std::string text, int enter, int delay, int total_time_to_print_limit) { // функция для медленного вывода текста
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
//
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


//Функция очистки ввода
void  clearing_input(){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

std::string generate_number() { // функция для генерации случайного числа
    std::string number;
    while (number.length() < 4){
        char digit = rand() % 10;

        if (number.empty() && digit == 0){
            continue; // пропускаем ведущий ноль
        }
        if (number.find('0' +digit) == std::string::npos){
            number += '0' + digit;
        }
    }
    return number;
}


bool check_bulls_and_cows_input(int bulls, int cows) {
    if (bulls < 0 || bulls > 4) {
        return false;
    }
    if (cows < 0 || cows > 4) {
        return false;
    }
    if (bulls + cows > 4) {
        return false;
    }
    return true;
}



bool check_number(std::string number) {// функция для проверки числа удовлетворяет ли оно условию игры
    if (number.length() != 4) {
        return false;
    }

    if (number[0] == '0'){
        return false;
    }

    for (char c : number){
        if (!isdigit(c)){
            return false;
        }

    }
    if (number[0] == number[1] || number[0] == number[2] || number[0] == number[3] ||
        number[1] == number[2] || number[1] == number[3] ||
        number[2] == number[3]) {
        return false;
    }
    return true;
}

std::tuple<int,int> check_bulls_and_cows(std::string secret_number, std::string player_number){
    int bulls {0};
    int cows {0};
    
    // Проверка быков
    for (int i {0}; i<4; ++i){
        if(secret_number[i] == player_number[i]){
            ++bulls;
            player_number[i] ='B';
        }
    }

    // Проверяем коров
    for(int i {0}; i<4; ++i){
        if (player_number[i] == 'B'){
            continue;
        }
        if (secret_number.find(player_number[i]) != std::string::npos){
            ++cows;
        }
    }
    return {bulls, cows};


}

std::string input_player_number(){
    std::string user_input_number;
    print_demarcation();
    print_slow("Введите число:");
    std::cout << std::endl;
    std::cin >> user_input_number;

    while (check_number(user_input_number)){
        print_demarcation();
        print_slow("Неверный ввод. Пожалуйста, введите 4-значное число с уникальными цифрами:");
        std::cout << std::endl;
        clearing_input();
        std::cin >> user_input_number;
    }
    if (user_input_number == "1234"){
        print_demarcation();
            print_slow("А что-то поумнее выдумать можешь чем 1234..........................ладно сойдёт", 2, 30);
            print_demarcation();
     }

    return user_input_number; 
}

bool check_user_win(int bulls, int cows){
    print_demarcation();
    print_slow("          ТВОЙ ХОД");
    print_demarcation();
    print_slow("Быков: ", 0);
    std::cout << bulls << std::endl;;
    print_slow("Коров: ", 0);
    std::cout << cows << std::endl;
    print_demarcation();

    if (bulls == 4){
        print_slow(get_random_phrase(duel_player_win_phrases), 1);
        return true;
    } 
        
    return false;
}


void has_player_guessed_number(){
print_slow("Загадай 4-значное число с уникальными цифрами: ");
    for(;;){
        print_slow("Загадал число?(yes/no)     ",0);
        std::string answer;
        std::cin >> answer;

        if (answer == "yes"){
            break;
        }
        else{
            clearing_input();
            print_slow("Жду..........", 1, 30);   
        }   
    }
}

std::tuple<int,int> check_computer_win(std::string computer_input_number){
    print_demarcation();
    print_slow("      ХОД КОМПЬЮТЕРА");
    print_demarcation();
    print_slow("Число компьютера: ", 0);
    std::cout << computer_input_number << std::endl;
    int bulls, cows;
    print_slow("Быков: ", 0);
    std::cin >> bulls;
    std::cout <<  std::endl;
    print_slow("Коров: ", 0);
    std::cin >> cows;
    std::cout <<  std::endl;
    while (!check_bulls_and_cows_input(bulls, cows)) {
        print_slow("Ошибка! Такое количество быков и коров невозможно.");
        print_slow("Введите заново:");
        print_demarcation();
        print_slow("Быков: ", 0);
        std::cin >> bulls;
        std::cout <<  std::endl;
        print_slow("Коров: ", 0);
        std::cin >> cows;
        std::cout <<  std::endl;
    print_demarcation();
        }

    if (bulls == 4){
        print_slow("Твое число: ", 0);
        std::cout << computer_input_number << std::endl;
        print_slow(get_random_phrase(duel_computer_win_phrases));
    }
    return {bulls,cows};
}


bool check_empty_combinations(std::vector<std::string> combinations){
    if (combinations.empty()){
        print_slow("Ты где то ошибся!!!");
        print_slow("Начни игру заново...");
        return true;
    }
    return false;        
}