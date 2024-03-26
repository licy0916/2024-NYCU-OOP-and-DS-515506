#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Item
{
private:
    string name;

public:
    // TODO: Add constructors or functions
    Item(){};
    string getName() const { return name; }

    friend istream& operator>>(istream& is, Item& item);

};

istream& operator>>(istream& is, Item& item) {
    is >> item.name;
    return is;
}

class Magic
{
private:
    string name;
    int manaCost;

public:
    // TODO: Add constructors or functions
    Magic(): manaCost(){};
    string getName() const { return name; }
    int getManaCost() const { return manaCost; }

    void setName(string name) { this->name = name; }
    void setManaCost(int manaCost) { this->manaCost = manaCost; }

    friend istream& operator>>(istream& is, Magic& magic);
};

istream& operator>>(istream& is, Magic& magic) {
    is >> magic.name >> magic.manaCost;
    return is;
}

class Player
{

private:
    string name;
    int strength;
    int mana;
    vector<Item> items;
    Magic magic;

public:
    // TODO: Add constructors or functions
    Player(){};


    void addStrength() { this->strength ++; }
    void addMana() { this->mana ++; }

    friend istream& operator>>(istream& is, Player &player);
    friend ostream& operator<<(ostream& os, Player &player);

    Player &operator++() {
        strength++;
        return *this;
    }

    Player &operator++(int) {
        mana++;
        return *this;
    }

    Player operator+(Item &item) {
        addItem(item);
        return *this;
    }

    Player operator+(Magic &newMagic) {
        if(this->mana >= newMagic.getManaCost()) {
            if(magic.getManaCost() <= newMagic.getManaCost()) {
                addMagic(newMagic);
            }

        }
        return *this;
    }

    void addItem(const Item& item) {
        if (int(items.size()) < strength) {
            items.push_back(item);
        } else if (int(items.size()) == strength) {
            if(items.size()!=0){
                for (int i = 0; i < items.size()-1; i++) {
                    items[i] = items[i+1];
                }
                items[items.size()-1] = item;
            }
        }
    }

    void addMagic(const Magic& magic) {
        this->magic = magic;
    }
};

istream& operator>>(istream& is, Player &player) {
    is >> player.name >> player.strength >> player.mana;
    return is;
}

ostream& operator<<(ostream& os, Player &player) {
    os << player.name << endl << "Strength: " << player.strength << endl << "Mana: " << player.mana << endl
       << "Items(" << player.items.size() << "):" << endl;
    if(player.items.size() > 0) {
        for (int i = 0; i < player.items.size(); i++) {
            os << player.items[i].getName() << endl;
        }
    }else{
        os << "No item" << endl;
    }


    if(player.magic.getName() != "") {
        os << "Magic: " << endl << player.magic.getName() << " " << player.magic.getManaCost() << endl;
    }else{
        os << "Magic:" << endl <<"No Magic" << endl;
    }
    return os;

}



// TODO: Add constructors or functions


int main()
{
    Player player;
    cin >> player;

    int strengthTrainingCount, manaTrainingCount;
    cin >> strengthTrainingCount >> manaTrainingCount;
    for (int i = 0; i < strengthTrainingCount; i++)
    {
        ++player;
    }
    for (int i = 0; i < manaTrainingCount; i++)
    {
        player++;
    }

    int getItemTimes, getMagicTimes;
    cin >> getItemTimes >> getMagicTimes;
    for (int i = 0; i < getItemTimes; i++)
    {
        Item item;
        cin >> item;
        player = player + item;
    }
    for (int i = 0; i < getMagicTimes; i++)
    {
        Magic magic;
        cin >> magic;
        player = player + magic;
    }

    cout << player;

    return 0;
}