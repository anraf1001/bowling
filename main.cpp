#include <iostream>

#include "Game.hpp"
#include "NotEnoughArgsExcept.hpp"
#include "TooManyArgsExcept.hpp"

int main(int argc, char** argv) {
    try {
        Game game{argc, argv};
    } catch (NotEnoughArgsExcept& exc) {
        std::cout << "Not enough arguments were passed: " << exc.what() << '\n';
        std::cout << "Arguments' count should be 1 - 2";
    } catch (TooManyArgsExcept& exc) {
        std::cout << "Too many arguments were passed: " << exc.what() << '\n';
        std::cout << "Arguments' count should be 1 - 2";
    }
    return 0;
}
