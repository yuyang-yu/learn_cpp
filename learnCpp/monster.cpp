#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

struct Monster
{
    MonsterType type{};
    std::string_view name{};
    double health{};
};

constexpr std::string_view getMonsterType(MonsterType type)
{
    switch (type)
    {
    case MonsterType::ogre:
        return "Ogre";
    case MonsterType::dragon:
        return "Dragon";
    case MonsterType::orc:
        return "Orc";
    case MonsterType::giantSpider:
        return "GiantSpider";
    case MonsterType::slime:
        return "Slime";

    default:
        return "Unknown";
    }
}

// std::ostream operator<<(std::ostream &out, MonsterType type)
// {
//     switch (type)
//     {
//     case MonsterType::ogre:
//         out << "Ogre";
//         break;
//     case MonsterType::dragon:
//         out << "Dragon";
//         break;
//     case MonsterType::orc:
//         out << "Orc";
//         break;
//     case MonsterType::giantSpider:
//         out << "GiantSpider";
//         break;
//     case MonsterType::slime:
//         out << "Slime";
//         break;
//     default:
//         out << "Unknown";
//         break;
//     }

//     return out;
// }

void printMonster(const Monster &monster)
{
    std::cout << "This " << getMonsterType(monster.type) << " is named " << monster.name << " and has " << monster.health << " health." << '\n';
    // std::cout << "This " << monster.type << " is named " << monster.name << " and has " << monster.health << " health." << '\n';
}

int main()
{
    Monster mon1{MonsterType::ogre, "Torg", 145};
    Monster mon2{MonsterType::slime, "Blurp", 23};

    printMonster(mon1);
    printMonster(mon2);
}
