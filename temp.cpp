#include <iostream>

void print_separator() 
{
    std::cout << "=====================\n";
}


void print_invitation() 
{
    std::cout << "Введите ваше число\n";
}


enum class GameState { Running, PlayerWin, ComputerWin };
enum class WhoseTurn { Player, Computer };
int game() 
{

    WhoseTurn turn = WhoseTurn::Player;
    
    GameState game_state;
    while(game_state == GameState::Running) 
    {
        int cows{};
        int bulls{};
        if (turn == WhoseTurn::Player) 
        {
            [cows, bulls] = PlayerMove();
        }
        else 
        {
            [cows, bulls] = ComputerMove();
        }

        if (bulls == get_field_size()) 
        {
            if (turn == WhoseTurn::Player)
                game_state = GameState::PlayerWin;
            else
                game_state = GameState::ComputerWin;
        }
    }

    switch (game_state)
    {
    case GameState::PlayerWin:
        /* code */
        break;
    case GameState::ComputerWin:
        /* code */
        break;
    default:
        throw std::logic_error("Unreachable code");
        break;
    }
}