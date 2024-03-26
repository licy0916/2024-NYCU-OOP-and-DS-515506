#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Player;

class Object {
protected:
    string name;

public:
    Object(const string& name = "") : name(name) {}
    virtual ~Object() = default;
    virtual void interact(Player& player) = 0; // Pure virtual function for interaction
};

class Monster : public Object {
private:
    int attackValue;

public:
    Monster(const string& name, int attackValue) : Object(name), attackValue(attackValue) {}
    virtual void interact(Player& player) override;
};

class Food : public Object {
private:
    int healValue;

public:
    Food(const string& name, int healValue) : Object(name), healValue(healValue) {}
    virtual void interact(Player& player) override;
};

class Player {
private:
    string name;
    int health;

public:
    Player(const string& name, int health) : name(name), health(health) {
        cout << name << "'s health: " << health << endl; // Print initial health
    }

    void changeHealth(int amount) {
        health += amount;
        // Note: Now we're moving the health printing logic to the caller to ensure correct ordering
        if (health <= 0) {
            cout << name << "'s health: " << health << endl;
            cout << "Game Over" << endl;
            exit(0); // Ends the program if the player's health drops to 0 or below
        }
    }

    void printHealth() const {
        cout << name << "'s health: " << health << endl;
    }

    friend void Monster::interact(Player& player);
    friend void Food::interact(Player& player);
};

void Monster::interact(Player& player) {
    cout << "Fight against " << name << endl;
    player.changeHealth(-attackValue); // Player loses health
    player.printHealth(); // Explicitly print health after interaction
}

void Food::interact(Player& player) {
    cout << "Eat " << name << endl;
    player.changeHealth(healValue); // Player gains health
    player.printHealth(); // Explicitly print health after interaction
}

class Room {
private:
    unique_ptr<Object> object;

public:
    Room(Object* object = nullptr) : object(object) {}

    void encounter(Player& player) {
        if (object) {
            object->interact(player);
        } else {
            cout << "Walk" << endl;
            player.printHealth(); // Print health even if the room is empty
        }
    }
};

int main() {
    int roomCount;
    cin >> roomCount;
    vector<Room> rooms;
    for (int i = 0; i < roomCount; i++) {
        char roomTag;
        cin >> roomTag;
        if (roomTag == 'm') {
            string objectName;
            int objectValue;
            cin >> objectName >> objectValue;
            rooms.emplace_back(new Monster(objectName, objectValue));
        } else if (roomTag == 'f') {
            string objectName;
            int objectValue;
            cin >> objectName >> objectValue;
            rooms.emplace_back(new Food(objectName, objectValue));
        } else { // Correctly handle 'e' for empty rooms
            rooms.emplace_back(nullptr);
        }
    }
    string playerName;
    int playerHealth;
    cin >> playerName >> playerHealth;
    Player player(playerName, playerHealth);

    for (Room& room : rooms) {
        room.encounter(player);
    }

    if (playerHealth > 0) { // This check is now redundant but kept for clarity
        cout << "Win Win" << endl;
    }
    return 0;
}