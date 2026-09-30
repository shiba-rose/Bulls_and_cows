

#include "game.h"


void print_slow(std::string text, int enter, int delay) { // функция для медленного вывода текста
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