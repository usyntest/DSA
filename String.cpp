#include <iostream>

int main() {
    char s[] = {'U', 'd', 'a', 'y', '\0'};
    for (int i = 0; s[i] != '\0'; i++) {
        std::cout << s[i];
    }
    std::cout << std::endl;
    return 0;
}