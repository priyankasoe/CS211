#include <iostream>
#include <string>

int main() {
    // Variable to store user input
    std::string name;

    std::string age;
    // Prompt the user for input
    std::cout << "Enter your name: ";
    std::cout << "enter age: ";

    // Read user input
    std::getline(std::cin, name); 
    std::getline(std::cin, age);
    // Output the user's input
    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;
}
