#include <array>
#include <cstdlib>
#include <iostream>
#include <string>


class Monster {
public:
  enum class Type {
    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,

    max_monster_types
  };

  Monster(Type type, std::string name, std::string roar, int health):
    type(type), name(name), roar(roar), health(health) {}

  static std::string to_string(const Type &type) {
    switch (type) {
      case Type::Dragon: return "Dragon";
      case Type::Goblin: return "Goblin";
      case Type::Ogre: return "Ogre";
      case Type::Orc: return "Orc";
      case Type::Skeleton: return "Skeleton";
      case Type::Troll: return "Troll";
      case Type::Vampire: return "Vampire";
      case Type::Zombie: return "Zombie";
      default: return "unknown";
    }
  }

  void print() {
    std::cout << name << " the " << to_string(type) << " has " << health << " and says " << roar << "\n";
  };

private:
  Type type;
  std::string name;
  std::string roar;
  int health;
};

class MonsterGenerator {
  
  static int getRandomNumber(int min, int max) {
    static constexpr double fraction = 1. / (static_cast<double>(RAND_MAX) + 1.);
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
  };

  Monster generateMonster() {
    constexpr std::array names = [ "Boba", "Chpoka", "Murunbu", "Ponch", "Zhozho", "Katamaran" ];
    
  }

}

int main()
{
    Monster skeleton{ Monster::Type::Skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();
 
    return 0;
}
