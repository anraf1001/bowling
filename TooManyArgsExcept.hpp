#pragma once

#include <stdexcept>

class TooManyArgsExcept : public std::invalid_argument {
public:
    TooManyArgsExcept(const std::string& what_arg)
        : std::invalid_argument{what_arg} {}
};
