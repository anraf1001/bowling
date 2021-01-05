#pragma once

#include <stdexcept>

class NotEnoughArgsExcept : public std::invalid_argument {
public:
    NotEnoughArgsExcept(const std::string& what_arg)
        : std::invalid_argument{what_arg} {}
};
