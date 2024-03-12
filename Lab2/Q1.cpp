#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    Person();
    Person(std::string name){
        this->name = name;
    };

    void setName(std::string name) { this->name = name; };
    std::string getName(){ return this->name; };

private:
    std::string name;
};

class Staff : public Person {
public:
    // TODO
    Staff();
    Staff(std::string name) : Person(name), supervisor(nullptr) {}  // Initialize supervisor to nullptr
    Staff* getStaff() { return this; };
    Staff* getSup() { return this->supervisor; };
    void setSup(Staff* sup){
        this->supervisor = sup;
    };
private:
    Staff* supervisor;
};

class Doctor : public Staff {
public:
    // TODO
    Doctor(std::string docName): Staff(docName) {};

    void setSupervisor(Doctor *docSupervisor) {
        setSup(docSupervisor->getStaff());
        if(docSupervisor->getStaff() != NULL) {
        }
    };
};

class Nurse : public Staff {
public:
    // TODO
    Nurse(std::string nurName): Staff(nurName) {};

    void setSupervisor(Doctor *docSupervisor) {
        setSup(docSupervisor->getStaff());
    };
};

class Task {
public:
    // TODO
    Task();
    Task(std::string name): name(name) {};

    void setNurse(Nurse *thisNurse) {
        nurse = thisNurse;
    };

    void getTask() {
        if (nurse) {
            std::cout << std::endl << name << " " << nurse->getName();
        }
    }
private:
    std::string name;
    Nurse* nurse;
};

class Patient : public Person {
public:
    // TODO
    Patient();
    Patient(std::string name): Person(name) {};

    void setTask(Task* taskItem) {
        tasks.push_back(taskItem);
    };

    void setDoctor(Doctor *resDoc){
        doctor = resDoc;
    }

    std::string getDoctorName() {
        if (doctor) {  // Ensure doctor is not nullptr
            return doctor->getName();
        }
        return "";
    }

    void getAllTasks() {
        for (auto task : tasks) {
            task->getTask();
        }
    }

private:
    Doctor* doctor;
    std::vector<Task*> tasks;
};


int main(void) {
    // TODO
    int numDoc, numNur, numPat, numTask;
    int resAss, taskAss;
    std::vector<Doctor*> Doclist ;
    std::vector<Nurse*> Nurlist ;
    std::vector<Patient*> Patlist ;
    std::vector<Task*> Tasklist ;

    std::cin >> numDoc >> numNur >> numPat;
    for (int i = 0; i < numDoc; i++) {
        std::string name;
        std::cin >> name;
        Doclist.push_back(new Doctor(name));
        //std::cout << Doclist.size() << std::endl;

    }
    for (int i = 0; i < numNur; i++) {
        std::string name;
        std::cin >> name;
        Nurlist.push_back(new Nurse(name));
        //std::cout << Nurlist.size() << std::endl;
    }
    for (int i = 0; i < numPat; i++) {
        std::string name;
        std::cin >> name;
        Patlist.push_back(new Patient(name));
        //std::cout << Patlist.size() << std::endl;
    }

    std::cin >> numTask;
    for (int i = 0; i < numTask; i++) {
        int patId;
        std::string taskName;
        std::cin >> patId;
        getline(std::cin, taskName);
        taskName.erase(0,1);
        Tasklist.push_back(new Task(taskName));
        Patlist[patId]->setTask(Tasklist[i]);
    }

    Patlist[0]->getAllTasks();


    for (int i = 0; i < numNur; i++) {
        int Nur, DocSup;
        std::cin >> Nur >> DocSup;
        Nurlist[Nur]->setSupervisor(Doclist[DocSup]);
    }


    for (int i = 0; i < numDoc; i++) {
        int Doc, DocSup;
        std::cin >> Doc >> DocSup;
        if (DocSup != -1){
            Doclist[Doc]->setSupervisor(Doclist[DocSup]);
        }
    }

    std::cin >> resAss >> taskAss;
    for (int i = 0; i < resAss; i++) {
        int assDoc, resDoc, Pat;
        std::cin >> assDoc >> resDoc >> Pat;
        //TODO
        if(Doclist[assDoc]->getStaff() == Doclist[resDoc]->getSup())
        {
            Patlist[Pat]->setDoctor(Doclist[resDoc]);
        }
    }
    for (int i = 0; i < taskAss; i++) {
        int taskId, assDoc, Nur;
        std::cin >> taskId >> assDoc >> Nur;
        //TODO
        if(Doclist[assDoc]->getStaff() == Nurlist[Nur]->getSup()){
            Tasklist[taskId]->setNurse(Nurlist[Nur]);
        }
    }

    //OUTPUT
    for (int i = 0; i < numPat; i++) {
        std::cout << "name: " << Patlist[i]->getName() << std::endl;
        std::cout << "doctor: " << Patlist[i]->getDoctorName() << std::endl;
        std::cout << "tasks: "; //TODO
        Patlist[i]->getAllTasks();

        if(i != numPat - 1) {
            std::cout << std::endl;
        }
    }
}


