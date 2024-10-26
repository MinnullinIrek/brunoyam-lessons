
#include <iostream>
#include <string>


bool is_exist(const string& str, char ch) {
    // Линейный поиск
    bool found = false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ch) 
            found = true;
            break;
        }
    }
    return found;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string str;
    char ch;

    // Ввод строки и символа от пользователя
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    std::cout << "Введите символ для поиска: ";
    std::cin >> ch;

    if (is_exist(str, ch))
    {
        cout << "есть";
    }


    // Линейный поиск
    bool found = false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ch) {
            std::cout << "Символ '" << ch << "' найден на позиции " << i + 1 << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Символ '" << ch << "' не найден в строке.\n";
    }

    return 0;
}
