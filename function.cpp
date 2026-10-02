//Описание
//1 функции вывода
//2 Функции алгоритмы для игр

#include "game.h"
//1 функции вывода
//Функция очистки ввода
void cin_clear(){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    print_slow("Неверный ввод.");
}

//  Функция посимвольного вывода
void print_slow(std::string text, int enter, int delay) { // функция для медленного вывода текста
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    for (int i = 0; i < enter; ++i) {
        std::cout << std::endl;
    }
}

// Функция вывода разделителя
void print_separator(char separator_symbol, int separator_length){
    std::string separator(separator_length, separator_symbol);
    print_slow(separator);
}

// Функция выбора случайной фразы
std::string get_random_phrase(const std::vector<std::string>& phrases) {
    return phrases[rand() % phrases.size()];
}

// Функция вывода приветствия
void print_greeting(){
    print_slow("Загрузка игры...", 2, 30);
    print_separator();
    print_slow("          Игра 'Быки и Коровы'          ");
    print_separator();
    std::cout << std::endl;
    print_slow("Добро пожаловать в игру!", 2, 30);

}

// Вывод начального меню
std::string output_main_menu(){
    print_slow("1. Начать игру");
    print_slow("2. Инструкция" );
    print_slow("3. Выход",2);
    print_slow("Выберите действие: ",0); 
    
    std::string choice;
    std::cin >> choice;
    return choice;    
}

// Вывод игрового меню
std::string output_play_menu(){
    print_slow("1. Player Guess");
    print_slow("2. Computer Guess" );
    print_slow("3. Duel");
    print_slow("4. Exit", 2);
    print_slow("Выберите действие: ",0); 

    std::string choice;
    std::cin >> choice;
    return choice;
}

// Функция вывода инструкции
void print_instructions(){
    for (const std::string& phrase : instructions){
        print_slow(phrase);
    } 
    std::cout << std::endl;
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

std::string get_valid_number(){
    std::string user_input_number;
     print_slow("Введите число:", 0);
        std::cin >> user_input_number;

        while (!check_number(user_input_number)){
            cin_clear();
            print_slow("Пожалуйста, введите 4-значное число с уникальными цифрами:", 0);
            std::cin >> user_input_number;
        }
    return user_input_number;
}

void print_user_result(std::string user_input_number, int bulls, int cows){
    std::cout << std::endl;
    print_separator();
    print_slow("               ТВОЙ ХОД");
    print_separator();
    print_slow("Твоё число: ", 0);
    std::cout << user_input_number << std::endl;
    print_slow("Быков: ", 0);
    std::cout << bulls << std::endl;;
    print_slow("Коров: ", 0);
    std::cout << cows << std::endl;
    print_separator();
    std::cout << std::endl;
}


void is_number_guessed(){
    print_slow("Загадай 4-значное число с уникальными цифрами: ");
    for(;;) {
        print_slow("Загадал число?(yes/no)     ",0);
        std::string answer;
        std::cin >> answer;

        if (answer == "yes"){
            break;
        }

        else{
            print_slow("Жду..........");   
        }   
    }       
}


bool is_valid_bulls_and_cows(int bulls, int cows){
    if (bulls < 0 || bulls > 4 || cows < 0 || cows > 4 || (bulls + cows) > 4){
        return false;
    }
    return true;
}

std::pair<int, int> print_computer_result(std::string computer_input_number){
    std::cout << std::endl;
    int bulls{-1};
    int cows{-1};
    print_separator();
    print_slow("           ХОД КОМПЬЮТЕРА");
    print_separator();
    print_slow("Компьютер назвал: ", 0);
    std::cout << computer_input_number << std::endl;
    for (;;) {
        
        print_slow("Введите количество быков: ", 0);
         if (!(std::cin >> bulls)) {
            std::cout << std::endl;
            cin_clear();
            print_slow("Пожалуйста, введите число:", 0);
            continue;
        }   

        print_slow("Введите количество коров: ", 0);
        if (!(std::cin >> cows)) {
            std::cout << std::endl;
            cin_clear();
            print_slow("Пожалуйста, введите число.");
            continue;
        }

        if (!is_valid_bulls_and_cows(bulls, cows)){
            std::cout << std::endl;
            print_slow(" Пожалуйста, введите корректные значения быков и коров.", 2, 3);
            continue;
        }
        break;
    }
    print_separator();
    std::cout << std::endl;
    return {bulls, cows};
}


bool is_combinations_empty(std::vector<std::string> combinations){
    if (combinations.empty()){
        print_slow("Ты где то ошибся!!!");
        print_slow("Начни игру заново...",2);
        return true;
    }
    return false;
}