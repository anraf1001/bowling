#include "Game.hpp"

#include <sstream>

#include "NotEnoughArgsExcept.hpp"
#include "TooManyArgsExcept.hpp"

Game::Game(int argc, [[maybe_unused]] char** argv) {
    if (argc < 2) {
        std::stringstream message{};
        message << "You've given " << argc - 1 << " arguments";
        throw NotEnoughArgsExcept{message.str()};
    } else if (argc > 3) {
        std::stringstream message{};
        message << "You've given " << argc - 1 << " arguments";
        throw TooManyArgsExcept{message.str()};
    }
}
