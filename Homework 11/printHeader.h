#ifndef PRINT_HEADER_H
#define PRINT_HEADER_H
#include <iostream>
#include <string>

void printHeader(const std::string& text) {
    const int totalLength = 44; // Total length of the line
    const int textLength = text.length();
    const int paddingLength = (totalLength - textLength) / 2;

    std::string padding(paddingLength, '-');

    std::cout << "\n--------------------------------------------\n"
              << padding << text << padding;
    
    if (textLength % 2 != 0) {
        std::cout << "-";
    }

    std::cout << "\n--------------------------------------------\n";
}
#endif // PRINT_HEADER_H
