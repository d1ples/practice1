#include <string>
#include <iostream>

enum MonsterType {
    ogre,
    orc,
    dragon,
    giant_spider,
    slime
};

struct Monster {
    MonsterType type;
    std::string name;
    int health;
};

std::string to_string(MonsterType type) {
    switch (type) {
        case ogre:
            return "Ogre";
        case orc:
            return "Orc";
        case dragon:
            return "Dragon";
        case giant_spider:
            return "Giant spider";
        case slime:
            return "Slime";
    }
}

void printMonster(Monster monster) {
    std::cout << to_string(monster.type) << " named " << monster.name << " has " << monster.health << " hp\n";
}

int main() {
    Monster ogre{ MonsterType::ogre, "Torg", 145 };
    Monster slime{ MonsterType::slime, "Blurp", 23 };

    printMonster(ogre);
    printMonster(slime);

    return 0;
}
