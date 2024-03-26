#include <iostream>
#include <cstring>
#include <map>

class word
{
    char str[20];
public:
    word() { std::strcpy(str, ""); }
    word(char *s) { std::strcpy(str, s); }
    char *get() { return str; }
};

bool operator<(word a, word b)
{
    return std::strcmp(a.get(), b.get()) < 0;
}

class meaning
{
    char str[80];
public:
    meaning() { std::strcpy(str, ""); }
    meaning(char *s) { std::strcpy(str, s); }
    char *get() { return str; }
};

int main() 
{
    std::map<word, meaning> dictionary;

    dictionary.insert(std::pair<word, meaning>(word("дом"), meaning("Место проживания.")));
    dictionary.insert(std::pair<word, meaning>(word("клавиатура"), meaning("Устройство ввода данных.")));
    dictionary.insert(std::pair<word, meaning>(word("программирование"), meaning("Процесс создания программ.")));
    dictionary.insert(std::pair<word, meaning>(word("STL"), meaning("Standart Template Library.")));

    char str[80];
    std::cout << "Введите слово: ";
    std::cin >> str;

    std::map<word, meaning>::iterator p;

    p = dictionary.find(word(str));
    if(p != dictionary.end())
        std::cout << "Определение: " << p->second.get();
    else 
        std::cout << "Такого слова в словаре нет.\n";

    std::cout << std::endl;
    return 0;
}