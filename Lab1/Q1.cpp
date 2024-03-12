/*
 We want to make a fun system which simulates that the teacher can modify the score of their favorite student.

 Input Format:
     The first row will contains three numbers representing studentCount (the number of students), teacherCount (the number of teachers), and modificationCount (the number of modifications).
     Then there will be "studentCount" rows. Each of them contains three values representing a student's ID, name, and score.
     After that, there will be "teacherCount" rows. Each of them contains three values representing a teacher's ID, name, and the ID of their favorite student.
     In the end, there will be "modificationCount" rows. Each of them contains two values representing the teacher's ID, and the new score for their favorite student.
 
 Constraints:

     1 <= studentCount <= 100
     1 <= teacherCount <= 100
     1 <= modificationCount <= 100
     1 <= the length of IDs and names <= 20
     1 <= all of the scores <= 100
     There won't be two identical student IDs or teacher IDs.

     You can only write codes in blocks containing "// TODO".

     Do not modify other parts of the codes.
 
 Output Format:
     Every group of sentences containing the teacher's ID and name, their favorite student's ID and name in the same line, and the score of their favorite student in the next line.
     It is necessary to iterate over and output all teachers, maintaining the same order as they were initially entered.
 
 Sample Input:
     2 1 1
     111122222 Albert 30
     333344444 Bob 100
     12345 Jenny 111122222
     12345 50

 Sample Output:
     [12345]Jenny's favorite student is [111122222]Albert.
     The student's score is 50.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Student {
	private:
		std::string id;
		std::string name;
		int score;
	public:
		Student() {}
		void setId(std::string newId) {
            // TODO
			id = newId;
		}
		void setName(std::string newName) {
            // TODO
            name = newName;
		}
		void setScore(int newScore) {
            // TODO
			score = newScore;
		}
		std::string getId() {
            // TODO
            return id;
		}
		std::string getName() {
            // TODO
            return name;
		}
		int getScore() {
			// TODO
            return score;
		}
};

class Teacher {
	private:
		std::string id;
		std::string name;
		Student* favoriteStudent;
	public:
		Teacher() {}
		void setId(std::string newId) {
			id = newId;
		}
		void setName(std::string newName) {
			name = newName;
		}
		void setFavoriteStudent(Student* newFavoriteStudent) {
            favoriteStudent = newFavoriteStudent;
		}
		std::string getId() {
			// TODO
            return id;
		}
		std::string getName() {
			// TODO
            return name;
		}
		std::string getFavoriteStudentId() {
			// TODO
            return favoriteStudent->getId();
		}
		std::string getFavoriteStudentName() {
			// TODO
            return favoriteStudent->getName();
		}
		int getFavoriteStudentScore() {
			// TODO
            return favoriteStudent->getScore();
		}
		void setFavoriteStudentScore(int newScore) {
			// TODO
            favoriteStudent->setScore(newScore);
		}
};

int main(void) {
    // TODO
    int stuCount, teaCount, modCount;
    std::cin >> stuCount >> teaCount >> modCount;
    std::unordered_map<std::string, Student> students;
    std::vector<Teacher> teachers;

    for(int i=0; i<stuCount; i++){
        std::string stuId, stuName;
        int stuScore;
        std::cin >> stuId >> stuName >> stuScore;
        Student student ;
        student.setId(stuId);
        student.setName(stuName);
        student.setScore(stuScore);
        students[stuId] = student;
    }

    for(int i=0; i<teaCount; i++){
        std::string teaId, teaName, favStuId;
        std::cin >> teaId >> teaName >> favStuId;
        Teacher teacher;
        teacher.setId(teaId);
        teacher.setName(teaName);
        teacher.setFavoriteStudent(&students[favStuId]);
        teachers.push_back(teacher);
    }

    // Modifications
    for (int i = 0; i < modCount; i++) {
        std::string teaId;
        int newScore;
        std::cin >> teaId >> newScore;
        for (auto& teacher : teachers) {
            if (teacher.getId() == teaId) {
                teacher.setFavoriteStudentScore(newScore);
                break;
            }
        }
    }

    // Output
    for (int i =0; i<teachers.size(); i++) {
        std::cout << "[" << teachers[i].getId() << "]" << teachers[i].getName()
                  << "'s favorite student is [" << teachers[i].getFavoriteStudentId() << "]" << teachers[i].getFavoriteStudentName() << ".\n";
        std::cout << "The student's score is " << teachers[i].getFavoriteStudentScore() << ".\n";
    }

    return 0;
}
