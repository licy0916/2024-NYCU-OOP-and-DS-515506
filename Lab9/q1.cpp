

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    MyQueue() {

    }

    void enQueue(int x) {
        // TODO
        stack1.push(x);
        cout << "Enqueued "<<x<<endl;

    }

    int deQueue() {
        // TODO
        if (stack1.empty()&&stack2.empty()){
            cout << "Queue is empty"<<endl;
            return -1;
        }
        if (stack2.empty()) {
            // Move all elements from inStack to outStack to reverse the order
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int x = stack2.top();
        cout << "Dequeued "<<x<<endl;
        stack2.pop();

        if (stack1.empty()) {
            // Move all elements from inStack to outStack to reverse the order
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        return -1;
    }

    int peek() {
        // TODO
        if (stack1.empty() && stack2.empty()){
            cout << "Queue is empty"<<endl;
            return -1;
        }

        if (stack2.empty()) {
            // Move all elements from inStack to outStack to reverse the order
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int x = stack2.top();
        cout << "Front element: "<<x<<endl;
        if (stack1.empty()) {
            // Move all elements from inStack to outStack to reverse the order
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        return -1;
    }

    bool isEmpty() {
        // TODO
        if(stack1.empty()){
            cout << "Queue is empty"<<endl;
            return true;
        }
        else{
            cout << "Queue is not empty"<<endl;
            return false;
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    MyQueue queue;
    string command;
    while(cin >> command){
        int value;
        if (command == "enqueue") {
            // TODO
            cin >> value;
            queue.enQueue(value);

        } else if (command == "dequeue") {
            // TODO
            queue.deQueue();

        } else if (command == "peek") {
            // TODO
            queue.peek();

        } else if (command == "empty") {
            // TODO
            queue.isEmpty();

        } else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}