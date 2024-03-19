#include <iostream>
#include <vector>
using namespace std;

class Position {
private:
    string name;
    int salary;
public:
    virtual void showOutput() = 0; // Make this a pure virtual function
    virtual ~Position() {} // Add a virtual destructor
    Position(string name, int salary) {
        this->name = name;
        this->salary = salary;
    }
    string getName() {
        return name;
    }
    int getSalary() {
        return salary;
    }
};

class Boss : public Position {
public:
    Boss(string name, int salary) : Position(name, salary) {} // Correct constructor
    void showOutput() override {
        cout << "Boss - " << getName() << ", Salary: " << getSalary() << endl;
    }
};

class Manager : public Position {
public:
    Manager(string name, int salary) : Position(name, salary) {} // Correct constructor
    void showOutput() override {
        cout << "Manager - " << getName() << ", Salary: " << getSalary() << endl;
    }
};

class TeamLeader : public Position {
public:
    TeamLeader(string name, int salary) : Position(name, salary) {} // Correct constructor
    void showOutput() override {
        cout << "Team Leader - " << getName() << ", Salary: " << getSalary() << endl; // Adjusted output
    }
};

class Employee : public Position {
public:
    Employee(string name, int salary) : Position(name, salary) {} // Correct constructor
    void showOutput() override {
        cout << "Employee - " << getName() << ", Salary: " << getSalary() << endl;
    }
};

double totalSalary(const vector<Position*>& positions) {
    double total = 0;
    for (auto position : positions) {
        total += position->getSalary();
    }
    return total;
}

int main() {
    vector<Position*> positions;
    string name;
    int salary;

    for(int i = 0; i < 4; i++){
        cin >> name >> salary;
        switch(i) {
            case 0: positions.push_back(new Boss(name, salary)); break;
            case 1: positions.push_back(new Manager(name, salary)); break;
            case 2: positions.push_back(new TeamLeader(name, salary)); break;
            case 3: positions.push_back(new Employee(name, salary)); break;
        }
    }

    for(auto* position : positions) {
        position->showOutput();
    }

    cout << "Total company salary: " << totalSalary(positions) << endl;

    // Cleanup
    for(auto* position : positions) {
        delete position;
    }

    return 0;
}
