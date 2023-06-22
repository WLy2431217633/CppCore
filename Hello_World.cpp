#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> words {"Hello", "_", "World", "!"};
    for (const auto& word : words)
    {
        std::cout << word;
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}
