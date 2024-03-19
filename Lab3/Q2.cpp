#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
private:
    string color;
public:
    //TODO hint : you can define virtual functions here
    Shape(string color): color(color) {};
    virtual void draw() = 0;
    virtual double getarea() = 0;
    void setColor(string color) {
        this->color = color;
    }
    string getColor() {
        return color;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    //TODO
    Rectangle(double width, double height, string color) : Shape(color) {
        this->width = width;
        this->height = height;
    }
    void draw() override{
        cout << "Name: Rectangle, Color: " << this->getColor() << ", Area: " << this->width * this->height << endl;

    };
    double getarea() override {
        return this->width * this->height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    //TODO
    Circle(double radius, string color) : Shape(color) {
        this->radius = radius;
    }
    void draw() override{
        cout << "Name: Circle, Color: " << this->getColor() << ", Area: " << this->radius*this->radius*M_PI << endl;

    };
    double getarea() override {
        return this->radius*this->radius*M_PI;
    }
};


class Triangle : public Shape {
private:
    double base;
    double height;
public:
    //TODO
    Triangle(double base, double height, string color) : Shape(color) {
        this->base = base;
        this->height = height;
    }
    void draw() override{
        //Name: Rectangle, Color: red, Area: 12
        cout << "Name: Triangle, Color: " << this->getColor() << ", Area: " << this->base * this->height / 2 << endl;
    };
    double getarea() override {
        return this->base * this->height / 2;
    }
};

class ShapeManager {
private:
    vector<Shape*> shapes;
public:
    //TODO hint : you can define functions here to know the information of each shape and calculate the total area

    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }
    void listShapes() {
        cout << "All shapes:" <<endl;
        for (int i = 0; i < 3; i++) {
            shapes[i]->draw();
        }
    }
    double calculateTotalArea() {
        double totalArea = 0;
        for (int i = 0; i <3; i++) {
            totalArea += shapes[i]->getarea();
        }
        return totalArea;
    }
};

int main() {

    ShapeManager manager;

    string color;

    double width, height;
    //TODO
    cin >> color >> width >> height;
    Shape* r = new Rectangle(width, height, color);
    manager.addShape(r);


    double radius;
    //TODO
    cin >> color >> radius;
    Shape* c = new Circle(radius, color);
    manager.addShape(c);

    double base, triHeight;
    //TODO
    cin >> color >> base >> triHeight;
    Shape* t = new Triangle(base, triHeight, color);
    manager.addShape(t);

    manager.listShapes();
    cout << "Total area: " << manager.calculateTotalArea() << endl;

    return 0;
}
