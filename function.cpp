//Описание
//1 функции вывода
//2 Функции алгоритмы для игр

#include "game.h"
//1 функции вывода

//  Функция посимвольного ввода
void print_slow(std::string text, int enter, int delay) { // функция для медленного вывода текста
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    for (int i = 0; i < enter; ++i) {
        std::cout << std::endl;
    }
}

// Функция выбора случайной фразы
std::string get_random_phrase(const std::vector<std::string>& phrases) {
    return phrases[rand() % phrases.size()];
}

//2 Функции алгоритмы для игр

// Функция для генерации случайного числа
std::string generate_number() { 
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

// Функция для проверки числа, удовлетворяет ли оно условию игры
bool check_number(std::string number) {
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

// Функция создания массива со всеми возможными комбинациями
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

// Функция определения быков и коров
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

// Функция фильтрации массива по введенным данным
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