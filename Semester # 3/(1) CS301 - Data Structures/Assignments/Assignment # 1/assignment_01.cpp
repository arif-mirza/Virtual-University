#include <iostream>
#include <string>
using namespace std;

// Product class
class Product {
private:
    int data;
    int productId;
    Product* next;

public:
    Product(int d = 0, int pid = 0) {
        data = d;
        productId = pid;
        next = nullptr;
    }

    int getData() { return data; }
    void setData(int d) { data = d; }

    Product* getNext() { return next; }
    void setNext(Product* n) { next = n; }

    int getProductId() { return productId; }
    void setProductId(int pid) { productId = pid; }
};

// Queue class
class Queue {
private:
    Product* front;
    Product* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int data, int pid) {
        Product* newNode = new Product(data, pid);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->setNext(newNode);
            rear = newNode;
        }
        cout << "Added -> Serial: " << data << ", Product ID: " << pid << endl;
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return -1;
        }

        Product* temp = front;
        int pid = temp->getProductId();
        int serial = temp->getData();
        front = front->getNext();
        if (front == nullptr)
            rear = nullptr;

        cout << "Sold product with serial: " << serial << " and ID: " << pid << endl;
        delete temp;
        return pid;
    }

    void displayFront() {
        if (front)
            cout << "First product in queue -> Serial: " << front->getData()
                 << ", Product ID: " << front->getProductId() << endl;
        else
            cout << "Queue is empty.\n";
    }

    void displayRear() {
        if (rear)
            cout << "Last product in queue -> Serial: " << rear->getData()
                 << ", Product ID: " << rear->getProductId() << endl;
        else
            cout << "Queue is empty.\n";
    }
};

int main() {
    string studentId = "BC240205517";
    cout << "Student ID: " << studentId << endl;
    cout << "==============================\n";

    int smartphoneCount = 5; 
    int tabletCount = 1;     
    int watchCount = 7;      

    Queue inventory;
    int serial = 1;
    int pid = 6789;    // starting product ID mention in assignment

    cout << smartphoneCount << " smartphones being added to inventory:\n";
    for (int i = 0; i < smartphoneCount; ++i)
        inventory.enqueue(serial++, pid++);

    cout << "\n" << tabletCount << " tablets being added to inventory:\n";
    for (int i = 0; i < tabletCount; ++i)
        inventory.enqueue(serial++, pid++);

    cout << "\n" << watchCount << " smart watches being added to inventory:\n";
    for (int i = 0; i < watchCount; ++i)
        inventory.enqueue(serial++, pid++);

    cout << "\n";
    inventory.displayFront();
    inventory.displayRear();

    cout << "\nSelling 2 products...\n";
    inventory.dequeue();
    inventory.dequeue();

    cout << "\n";
    inventory.displayFront();

    cout << "==============================\n";
    return 0;
}
