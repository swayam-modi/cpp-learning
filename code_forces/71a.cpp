#include <iostream>
#include <string>

int main()
{
    int n = 0;
    std::cin >> n;

    while (n > 0)
    {
        std::string word;
        std::cin >> word;

        if (word.length() > 10)
        {
            std::cout << word[0] << word.length() - 2 << word[word.length() - 1] << std::endl;
        }
        else
        {
            std::cout << word << std::endl;
        }
        n--;
    }

    return 0;
}