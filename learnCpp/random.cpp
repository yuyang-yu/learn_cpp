#include <random>
#include <iostream>

int getGuess(int count)
{
    while (true)
    {
        std::cout << "Guess #" << count << ": ";

        int guess{};
        std::cin >> guess;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return guess;
    }
}

bool playGame(int guesses, int number)
{
    for (int i{1}; i <= guesses; ++i)
    {
        int guess{getGuess(i)};

        if (guess > number)
        {
            std::cout << "Your guess is too high.\n";
        }
        else if (guess < number)
        {
            std::cout << "Your guess is too low.\n";
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool playAgain()
{
    while (true)
    {
        char ch{};
        std::cout << "Would you like to play again(y/n)?";
        std::cin >> ch;

        switch (ch)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            std::cout << "The input is invaild. Please enter y/n.\n";
        }
    }
}

int main()
{
    std::random_device rd;
    std::seed_seq seq{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{seq};
    std::uniform_int_distribution die{1, 100};

    constexpr int guesses{7};

    do
    {
        int number{die(mt)};

        std::cout << "Let's play a game. I'm thinking of number. You have " << guesses << " tries to guess what it is.\n";

        bool win{playGame(guesses, number)};
        if (win)
        {
            std::cout << "Corret! You win!\n";
        }
        else
        {
            std::cout << "Sorry, you lose. The corret number was " << number << "\n";
        }

    } while (playAgain());

    std::cout << "Thank you for playing.\n";

    return 0;
}