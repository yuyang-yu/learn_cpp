#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <iostream>
#include <string>
#include <string_view>

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
int getRandomNumber(int min, int max)
{
    static constexpr double fraction{1.0 / (RAND_MAX + 1.0)}; // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

class Creature
{
protected:
    std::string m_name;
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:
    Creature(std::string_view name, char symbol, int health, int damage, int gold)
        : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold}
    {
    }

    char getSymbol() const { return m_symbol; }
    const std::string &getName() const { return m_name; }
    bool isDead() const { return m_health <= 0; }
    int getGold() const { return m_gold; }
    void addGold(int gold) { m_gold += gold; }
    void reduceHealth(int health) { m_health -= health; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
};

class Player : public Creature
{
    int m_level{1};

public:
    Player(const std::string &name)
        : Creature{name, '@', 10, 1, 0}
    {
    }

    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    int getLevel() const { return m_level; }
    bool hasWon() const { return m_level >= 20; }
};

class Monster : public Creature
{
public:
    enum class Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

private:
    static const Creature &getDefaultCreature(Type type)
    {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            {{"dragon", 'D', 20, 4, 100},
             {"orc", 'o', 4, 2, 25},
             {"slime", 's', 1, 1, 10}}};

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(Type type)
        : Creature{getDefaultCreature(type)}
    {
    }

    static Monster getRandomMonster()
    {
        int num{getRandomNumber(0, static_cast<int>(Type::max_types) - 1)};
        return Monster{static_cast<Type>(num)};
    }
};

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand();                                               // get rid of first result

    for (int i{0}; i < 10; ++i)
    {
        Monster m{Monster::getRandomMonster()};
        std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
    }

    return 0;
}