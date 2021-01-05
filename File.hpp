#pragma once

#include <filesystem>

class File {
public:
    File(const std::string& filename)
        : filePath_{filename} {}

private:
    std::filesystem::path filePath_;
};
