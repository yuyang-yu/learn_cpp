#include <iostream>
#include <random> // for std::mt19937

// returns true if the user won, false if they lost
bool playGame(int guesses, int number)
{
    // Loop through all of the guesses
    for (int count{1}; count <= guesses; ++count)
    {
        std::cout << "Guess #" << count << ": ";

        int guess{};
        std::cin >> guess;

        if (guess > number)
            std::cout << "Your guess is too high.\n";
        else if (guess < number)
            std::cout << "Your guess is too low.\n";
        else // guess == number
            return true;
    }

    return false; // if the user lost
}

bool playAgain()
{
    // Keep asking the user if they want to play again until they pick y or n.
    while (true)
    {
        char ch{};
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;

        switch (ch)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        }
    }
}

int main()
{
    std::random_device rd;
    std::seed_seq seq{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{seq};                      // Create a mersenne twister, seeded using the seed sequence
    std::uniform_int_distribution die{1, 100}; // generate random numbers between 1 and 100

    constexpr int guesses{7}; // the user has this many guesses

    do
    {
        int number{die(mt)}; // this is the number the user needs to guess

        std::cout << "Let's play a game. I'm thinking of a number. You have " << guesses << " tries to guess what it is.\n";

        bool won{playGame(guesses, number)};
        if (won)
            std::cout << "Correct! You win!\n";
        else
            std::cout << "Sorry, you lose. The correct number was " << number << "\n";
    } while (playAgain());

    std::cout << "Thank you for playing.\n";

    return 0;
}