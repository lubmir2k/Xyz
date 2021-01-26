#include <iostream>
#include <ctime>

void Intro()
{
    std::cout << "You are a secret agent breaking into a secure server room.\n";
    std::cout << "You need to enter the correct codes to continue...\n\n";
    std::cout << "________________________________________________\n";
    std::cout << "|      _____________________________           |\n";
    std::cout << "| [][] _____________________________ [_][_][_] |\n";
    std::cout << "| [][] [_][_][_] [_][_][_][_] [_][_] [_][_][_] |\n";
    std::cout << "| [][] [_][_][_] [_][_][_][_] [_][_] [_][_][_] |\n";
    std::cout << "|                                              |\n";
    std::cout << "| [][] [][][][][][][][][][][][][][_] [][][][]  |\n";
    std::cout << "| [][] [_][][][][][][][][][][][][][] [][][][]  |\n";
    std::cout << "| [][] [__][][][][][][][][][][][][_] [][][][]  |\n";
    std::cout << "| [][] [___][][][][][][][][][][][__] [__][][]  |\n";
    std::cout << "|          [_][______________][_]              |\n";
    std::cout << "|______________________________________________|\n";
}

bool Game(int Difficulty)
{
    const int CodeX = rand() % Difficulty + Difficulty;
    const int CodeY = rand() % Difficulty + Difficulty;
    const int CodeZ = rand() % Difficulty + Difficulty;

    const int Sum = CodeX + CodeY + CodeZ;
    const int Product = CodeX * CodeY * CodeZ;

    std::cout << "\n\n+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << Sum;
    std::cout << "\n+ The codes multiply to give: " << Product;
    std::cout << "\n\n> ";

    int GuessX, GuessY, GuessZ;
    std::cin >> GuessX >> GuessY >> GuessZ;

    int GuessSum = GuessX + GuessY + GuessZ;
    int GuessProduct = GuessX * GuessY * GuessZ;

    if (GuessSum == Sum && GuessProduct == Product)
    {
        std::cout << "\n*** Great work agent! You have extracted a file! ***\n";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! ***\n";
        return false;
    }
}

void Outro()
{
    std::cout << "\n\n/   /                                     /   /\n";
    std::cout << "| O |                                       | O |\n";
    std::cout << "|   |- - - - - - - - - - - - - - - - - - - -|   |\n";
    std::cout << "| O |                                       | O |\n";
    std::cout << "|   |      W E L L  D O N E  A G E N T      |   |\n";
    std::cout << "| O |                                       | O |\n";
    std::cout << "|   |    Y O U  G O T  A L L  F I L E S     |   |\n";
    std::cout << "| O |                                       | O |\n";
    std::cout << "|   | N O W  G E T  O U T  O F  T H E R E ! |   |\n";
    std::cout << "| O |                                       | O |\n";
    std::cout << "|   |                                       |   |\n";
    std::cout << "| O |- - - - - - - - - - - - - - - - - - - -| O |\n";
    std::cout << "|   |                                       |   |\n\n";
}


int main()
{
    srand(time(NULL)); // Creates new random sequence based on time of day

    Intro();

    int Difficulty = 1;
    const int MaxDifficulty = 5;

    while (Difficulty <= MaxDifficulty)
    {
        bool bLevelComplete = Game(Difficulty);
        std::cin.clear(); // Clear any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++Difficulty;
        }
    }

    Outro();

    return 0;
}