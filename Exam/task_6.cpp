#include <iostream>
#include <vector>
#include <string>

class Item {
public:
    std::string name;
    int buyPrice;
    int sellPrice;

    Item(std::string name, int buyPrice, int sellPrice)
        : name(name), buyPrice(buyPrice), sellPrice(sellPrice) {}

    void display() {
        std::cout << name << " (Buy: " << buyPrice << ", Sell: " << sellPrice << ")\n";
    }
};

class Shop {
private:
    std::vector<Item> itemsForSale;

public:
    void addItem(Item item) {
        itemsForSale.push_back(item);
    }

    void removeItem( std::string itemName) {
        for (auto it = itemsForSale.begin(); it != itemsForSale.end(); ++it) {
            if (it->name == itemName) {
                itemsForSale.erase(it);
                break;
            }
        }
    }

    bool hasItem( std::string itemName) {
        for ( auto item : itemsForSale) {
            if (item.name == itemName) {
                return true;
            }
        }
        return false;
    }

    void displayShopItems() {
        std::cout << "Items available for sale:\n";
        for (auto item : itemsForSale) {
            item.display();
        }
    }

    std::vector<Item>& getItemsForSale() {
        return itemsForSale;
    }
};

class Character {
public:
    std::string name;
    int gold;
    std::vector<Item> inventory;

    Character(std::string name, int gold) : name(name), gold(gold) {}

    void buyItem(std::string itemName, Shop& shop) {
        if (shop.hasItem(itemName)) {
            for (auto item : shop.getItemsForSale()) {
                if (item.name == itemName) {
                    if (gold >= item.buyPrice) {
                        gold -= item.buyPrice;
                        inventory.push_back(item);
                        shop.removeItem(itemName);
                        std::cout << name << " купил " << item.name << " за " << item.buyPrice << " золота.\n";
                    } else {
                        std::cout << name << " не имеет достаточно золота для покупки " << item.name << ".\n";
                    }
                    return;
                }
            }
        } else {
            std::cout << itemName << " не найден в магазине.\n";
        }
    }

    void sellItem( std::string itemName, Shop& shop) {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->name == itemName) {
                gold += it->sellPrice;
                shop.addItem(*it);
                inventory.erase(it);
                std::cout << name << " продал " << itemName << " за " << it->sellPrice << " золота.\n";
                return;
            }
        }
        std::cout << name << " не имеет " << itemName << " для продажи.\n";
    }
};

int main() {
    Item sword("Sword", 100, 50);
    Item shield("Shield", 150, 75);
    Item potion("Potion", 50, 25);

    Shop shop;
    shop.addItem(sword);
    shop.addItem(shield);
    shop.addItem(potion);

    Character hero("Hero", 200);

    shop.displayShopItems();

    hero.buyItem("Sword", shop);
    hero.buyItem("Potion", shop);

    std::cout << "\nInventory of " << hero.name << ":\n";
    for (auto item : hero.inventory) {
        item.display();
    }

    hero.sellItem("Sword", shop);

    std::cout << "\nInventory of " << hero.name << " after selling:\n";
    for (auto item : hero.inventory) {
        item.display();
    }

    std::cout << "\nUpdated Shop Items:\n";
    shop.displayShopItems();

    return 0;
}
