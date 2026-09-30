

#include "game.h"


std::string get_random_phrase(const std::vector<std::string>& phrases) {
    return phrases[rand() % phrases.size()];
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



void start_game_1() {
    // Здесь логика игры_1
    std::string computer_output_number {generate_number()};
    std::string user_input_number;

    while (computer_output_number != user_input_number) {
        print_slow("Введите число:", 2);
        std::cin >> user_input_number;

        while (check_number(user_input_number) == false){
            print_slow("Неверный ввод. Пожалуйста, введите 4-значное число с уникальными цифрами:", 2);
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> user_input_number;
        }

        int bulls;
        int cows;
        std::tie(bulls, cows) = check_bulls_and_cows(computer_output_number, user_input_number);

        std::cout << std::endl;
        print_slow("Быков: ", 0);
        std::cout << bulls << std::endl;;
        print_slow("Коров: ", 0);
        std::cout << cows << std::endl;
        
        if (bulls == 4){
            print_slow("Поздравляю!");
            print_slow("Ты победил!");
            print_slow("Отличная работа! Ты угадал загаданное число!", 3);
        }


    }

}


void start_game_2(){
    // Здесь логика игры_2
    std::vector<std::string> combinations {generate_all_combinations()};
    std::string computer_input_number = combinations[rand() % combinations.size()];
    std::string user_output_number;
    print_slow("Загадай 4-значное число с уникальными цифрами: ");
    bool flag {true};
    while (flag) {

        print_slow("Загадал число?(да/нет)     ",0);
        std::string answer;
        std::cin >> answer;

        if (answer == "да"){
            flag = false;
        }

        else{
            print_slow("Жду..........");   
        }   
    }
     while (true){
        print_slow("Твое число: ", 0);
        std::cout << computer_input_number << std::endl;
        int bulls;
        int cows;
        print_slow("Быков: ", 0);
        std::cin >> bulls;
        print_slow("Коров: ", 0);
        std::cin >> cows;

        if (bulls == 4){
            print_slow("Твое число: ", 0);
            std::cout << computer_input_number << std::endl;
            print_slow("Спасибо за игру!",2);
            break;
        }

        else{
            combinations = filter_combinations(combinations, computer_input_number, bulls,cows);
            if (combinations.empty()){
                print_slow("Ты где то ошибся!!!",2);
                print_slow("Начни игру заново...",2);
                break;
            }

            else{
                computer_input_number = combinations[rand() % combinations.size()];    
            }
        }
     }

}

void start_game_duel()
{
    // Здесь логика игры_3
    std::string computer_output_number {generate_number()};
    std::string user_input_number;
    std::vector<std::string> combinations {generate_all_combinations()};
    std::string computer_input_number = combinations[rand() % combinations.size()];
    std::string user_output_number;

    print_slow(get_random_phrase(duel_start_phrases), 2);
    print_slow("Загадай 4-значное число с уникальными цифрами: ");
    bool flag {true};
    while (flag) {

        print_slow("Загадал число?(да/нет)     ",0);
        std::string answer;
        std::cin >> answer;

        if (answer == "да"){
            flag = false;
        }

        else{
            print_slow("Жду..........", 1, 30);   
        }   
    }
    print_slow(get_random_phrase(duel_first_move_phrases), 2);
    while (computer_output_number != user_input_number) {
        print_slow("Введите число:", 2);
        std::cin >> user_input_number;

        while (check_number(user_input_number) == false){
            print_slow("Неверный ввод. Пожалуйста, введите 4-значное число с уникальными цифрами:", 2, 3);
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> user_input_number;
        }

        if (user_input_number == "1234"){
            print_slow("А что-то поумнее выдумать можешь чем 1234..........................ладно сойдёт", 2, 30);
        }

        int bulls_1;
        int cows_1;
        std::tie(bulls_1, cows_1) = check_bulls_and_cows(computer_output_number, user_input_number);
        std::cout << std::endl;
        print_slow("============================");
        print_slow("          ТВОЙ ХОД");
        print_slow("============================");
        print_slow("Твоё число: ", 0);
        std::cout << user_input_number << std::endl;
        std::cout << std::endl;
        print_slow("Быков: ", 0);
        std::cout << bulls_1 << std::endl;;
        print_slow("Коров: ", 0);
        std::cout << cows_1 << std::endl;
        print_slow("============================",2);

        if (bulls_1 == 4){
            print_slow(get_random_phrase(duel_player_win_phrases));
            print_slow("Отличная работа! Ты угадал загаданное число!", 3);
        }
        else{
            print_slow(get_random_phrase(duel_turn_phrases),2);
            print_slow("============================");
            print_slow("      ХОД КОМПЬЮТЕРА");
            print_slow("============================");
            print_slow("Компьютер назвал: ", 0);
            std::cout << computer_input_number << std::endl;
            int bulls_2;
            int cows_2;
            print_slow("Быков: ", 0);
            std::cin >> bulls_2;
            print_slow("Коров: ", 0);
            std::cin >> cows_2;
            print_slow("============================",2);
            if (bulls_2 == 4){
                print_slow("Твое число: ", 0);
                std::cout << computer_input_number << std::endl;
                print_slow(get_random_phrase(duel_computer_win_phrases));
                print_slow("Спасибо за игру!",2);
                break;
            }

            else{
                print_slow(get_random_phrase(duel_after_player_phrases), 2);
                combinations = filter_combinations(combinations, computer_input_number, bulls_2,cows_2);
                if (combinations.empty()){
                    print_slow("Ты где то ошибся!!!",2);
                    print_slow("Начни игру заново...",2);
                    break;
                }

                else{
                    computer_input_number = combinations[rand() % combinations.size()];    
                }
            }    
        }

    }

}