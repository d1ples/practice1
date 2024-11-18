#include <array>
#include <numeric>
#include <iostream>

enum ItemType {
    item_health_potion,
    item_torch,
    item_arrow,
    max_items
};

using inventory_type = std::array<int,ItemType::max_items>;

int countTotalItems(const inventory_type& items) {
    return std::accumulate(items.begin(),items.end(),0);
}

int main() {
    inventory_type items = {2, 5, 10};

    std::cout << "The player has " << countTotalItems(items) << " item(s) in total\n";

    std::cout << "The player has " << items[ItemType::item_torch] << " torches\n";

    return 0;
}
