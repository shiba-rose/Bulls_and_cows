#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <vector>

#include "game.h"

std::vector<std::string> duel_start_phrases {
    "Ну что, готов к дуэли?",
    "Посмотрим, кто сегодня окажется умнее.",
    "Дуэль начинается!",
    "Я уже загадал своё число. А ты?",
    "Надеюсь, ты готов проиграть.",
    "Начнём. Покажи, на что способен.",
    "Так, посмотрим, насколько хорошо ты умеешь угадывать.",
    "Пусть победит лучший!"
};

std::vector<std::string> duel_turn_phrases {
    "Теперь мой ход.",
    "Так... моя очередь угадывать.",
    "Интересно... попробую вот это число.",
    "Сейчас я тебя раскусю.",
    "Хм, вариантов становится всё меньше.",
    "Я кое-что придумал.",
    "Проверим мою догадку.",
    "Думаю, это хороший вариант.",
    "Так, анализируем подсказку...",
    "Кажется, я становлюсь ближе."
};

std::vector<std::string> duel_after_player_phrases {
    "Хм, интересный результат.",
    "Так, это многое проясняет.",
    "Запомнил. Двигаемся дальше.",
    "Теперь вариантов стало меньше.",
    "Понял твою подсказку.",
    "Информация принята.",
    "Хорошо... продолжаем.",
    "Кажется, я начинаю понимать твоё число."
};

std::vector<std::string> duel_player_win_phrases {
    "Неплохо... ты меня победил.",
    "Вот это неожиданно.",
    "Ладно, в этот раз ты оказался быстрее.",
    "Поздравляю. Я проиграл.",
    "Хорошая игра. Ты победил."
};

std::vector<std::string> duel_computer_win_phrases {
    "Я знал, что смогу это сделать.",
    "Кажется, я разгадал твоё число.",
    "Победа за мной!",
    "Вот и всё. Я угадал.",
    "Неплохая дуэль. Но сегодня победил я."
};

std::vector<std::string> duel_first_move_phrases {
    "Ладно, первый ход за тобой.",
    "Давай, удиви меня. Первый ход твой.",
    "Хорошо, уступаю тебе первый ход.",
    "Начинай ты. Посмотрим, что ты придумал.",
    "Первый ход твой. Но не расслабляйся.",
    "Давай, загадывай и ходи первым.",
    "Сегодня я великодушен. Начинай.",
    "Уступаю первый ход. Не упусти свой шанс.",
    "Хорошо, начни первым. Потом будет моя очередь.",
    "Первый ход за тобой. А дальше посмотрим.",
    "Я позволю тебе сделать первый шаг.",
    "Давай посмотрим, что ты сделаешь первым ходом.",
    "Начинай. Мне интересно, насколько быстро ты ошибёшься.",
    "Первый ход твой. Я пока просто понаблюдаю.",
    "Ну хорошо... сегодня я начну с того, что уступлю тебе."
};

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
        print_slow("Введите число:", 2, 3);
        std::cin >> user_input_number;

        while (check_number(user_input_number) == false){
            print_slow("Неверный ввод. Пожалуйста, введите 4-значное число с уникальными цифрами:", 2, 3);
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> user_input_number;
        }

        int bulls;
        int cows;
        std::tie(bulls, cows) = check_bulls_and_cows(computer_output_number, user_input_number);

        std::cout << std::endl;
        print_slow("Быков: ", 0, 10);
        std::cout << bulls << std::endl;;
        print_slow("Коров: ", 0, 10);
        std::cout << cows << std::endl;
        
        if (bulls == 4){
            print_slow("Поздравляю!", 1, 5);
            print_slow("Ты победил!", 1, 5);
            print_slow("Отличная работа! Ты угадал загаданное число!", 3, 5);
        }


    }

}


void start_game_2(){
    // Здесь логика игры_2
    std::vector<std::string> combinations {generate_all_combinations()};
    std::string computer_input_number = combinations[rand() % combinations.size()];
    std::string user_output_number;
    print_slow("Загадай 4-значное число с уникальными цифрами: ", 1, 5);
    bool flag {true};
    while (flag) {

        print_slow("Загадал число?(да/нет)     ",0,5);
        std::string answer;
        std::cin >> answer;

        if (answer == "да"){
            flag = false;
        }

        else{
            print_slow("Жду..........", 1, 30);   
        }   
    }
     while (true){
        print_slow("Твое число: ", 0, 5);
        std::cout << computer_input_number << std::endl;
        int bulls;
        int cows;
        print_slow("Быков: ", 0, 5);
        std::cin >> bulls;
        print_slow("Коров: ", 0, 5);
        std::cin >> cows;

        if (bulls == 4){
            print_slow("Твое число: ", 0, 5);
            std::cout << computer_input_number << std::endl;
            print_slow("Спасибо за игру!",2,10);
            break;
        }

        else{
            combinations = filter_combinations(combinations, computer_input_number, bulls,cows);
            if (combinations.empty()){
                print_slow("Ты где то ошибся!!!",2,10);
                print_slow("Начни игру заново...",2,10);
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

    print_slow(get_random_phrase(duel_start_phrases), 2, 5);
    print_slow("Загадай 4-значное число с уникальными цифрами: ", 1, 5);
    bool flag {true};
    while (flag) {

        print_slow("Загадал число?(да/нет)     ",0,5);
        std::string answer;
        std::cin >> answer;

        if (answer == "да"){
            flag = false;
        }

        else{
            print_slow("Жду..........", 1, 30);   
        }   
    }
    print_slow(get_random_phrase(duel_first_move_phrases), 2, 5);
    while (computer_output_number != user_input_number) {
        print_slow("Введите число:", 2, 3);
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
        print_slow("============================", 1, 2);
        print_slow("          ТВОЙ ХОД", 1, 2);
        print_slow("============================", 1, 2);
        print_slow("Твоё число: ", 0, 5);
        std::cout << user_input_number << std::endl;
        std::cout << std::endl;
        print_slow("Быков: ", 0, 10);
        std::cout << bulls_1 << std::endl;;
        print_slow("Коров: ", 0, 10);
        std::cout << cows_1 << std::endl;
        print_slow("============================", 1, 2);

        if (bulls_1 == 4){
            print_slow(get_random_phrase(duel_player_win_phrases), 1, 5);
            print_slow("Отличная работа! Ты угадал загаданное число!", 3, 5);
        }
        else{
            print_slow(get_random_phrase(duel_turn_phrases),1,5);
            print_slow("============================", 1, 2);
            print_slow("      ХОД КОМПЬЮТЕРА", 1, 2);
            print_slow("============================", 1, 2);
            print_slow("Компьютер назвал: ", 0, 5);
            std::cout << computer_input_number << std::endl;
            int bulls_2;
            int cows_2;
            print_slow("Быков: ", 0, 5);
            std::cin >> bulls_2;
            print_slow("Коров: ", 0, 5);
            std::cin >> cows_2;
            print_slow("============================", 1, 2);
            if (bulls_2 == 4){
                print_slow("Твое число: ", 0, 5);
                std::cout << computer_input_number << std::endl;
                print_slow(get_random_phrase(duel_computer_win_phrases),1,5);
                print_slow("Спасибо за игру!",2,10);
                break;
            }

            else{
                print_slow(get_random_phrase(duel_after_player_phrases), 2, 5);
                combinations = filter_combinations(combinations, computer_input_number, bulls_2,cows_2);
                if (combinations.empty()){
                    print_slow("Ты где то ошибся!!!",2,10);
                    print_slow("Начни игру заново...",2,10);
                    break;
                }

                else{
                    computer_input_number = combinations[rand() % combinations.size()];    
                }
            }    
        }

    }

}