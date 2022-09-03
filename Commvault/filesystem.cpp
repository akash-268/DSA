#include <iostream>

int main(int argc, char *argv[])
{
    // const path pathToShow{argc > 1 ? argv[1] : fs::current_path()};

    // for (const auto &entry : fs::directory_iterator(pathToShow))
    {
        const auto fileName = entry.path().filename().string();
        if (entry.is_directory())
        {
            std::cout << "dir: " << fileName << "\n";
        }
        else if (entry.is_regular_file())
        {
            std::cout << "file: " << fileName << "\n";
        }
        else
        {
            std::cout << "??: " << fileName << "\n";
        }
    }
    return 0;
}
