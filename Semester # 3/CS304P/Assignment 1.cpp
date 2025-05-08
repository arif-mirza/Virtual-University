#include <iostream>
#include <string>
#include <cstddef> // For NULL
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node() : data(0), next(NULL) {}
    void setData(int val) { data = val; }
    void setNext(Node *ptr) { next = ptr; }
    int getData() const { return data; }
    Node *getNext() const { return next; }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(NULL) {}

    // TODO 1: Implement the insertFirstDigit function
    void insertFirstDigit(int val)
    {
        // Write your code here

        Node *newNode = new Node();
        newNode->setData(val);
        newNode->setNext(head);
        head = newNode;
    }

    // TODO 2: Implement the insertLastDigit function
    void insertLastDigit(int val)
    {
        // Write your code here
        Node *newNode = new Node();
        newNode->setData(val);
        newNode->setNext(NULL);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->getNext() != NULL)
            {
                curr = curr->getNext();
            }
            curr->setNext(newNode);
        }
    }

    // TODO 3: Implement the removeFirstDigit function
    void removeFirstDigit()
    {
        // Write your code here
        if (head != NULL)
        {
            Node *temp = head;
            head = head->getNext();
            delete temp;
        }
    }

    // TODO 4: Implement the removeLastDigit function
    void removeLastDigit()
    {
        // Write your code here
        if (head == NULL)
            return;
        if (head->getNext() == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *curr = head;
        while (curr->getNext()->getNext() != NULL)
        {
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(NULL);
    }

    void display() const
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->getData();
            if (curr->getNext() != NULL)
                cout << " -> ";
            curr = curr->getNext();
        }
        cout << " -> NULL" << endl;
    }
};

int main()
{
    // TODO 5: Write your VUID
    string studentID = "BC240205517";

    // Extract digits and combine
    int firstDigit = studentID[2] - '0';
    int lastDigit = studentID[studentID.size() - 1] - '0';
    int combined = firstDigit * 10 + lastDigit;

    // Initialize list with three book IDs
    int books[] = {101, 102, 103};
    LinkedList inventory;
    for (int id : books)
        inventory.insertLastDigit(id);

    // Display header & extraction
    cout << "---------------- Book Inventory Management ("
         << studentID << ")---------------" << endl;
    cout << "Extracted First and Last Digits are:\n"
         << combined << "\n\n";

    // Add first digit and display
    cout << "Added First digit at start of List:\n";
    inventory.insertFirstDigit(firstDigit);
    inventory.display();
    cout << endl;

    // Add second digit and display
    cout << "Added Last digit at Last of List:\n";
    inventory.insertLastDigit(lastDigit);
    inventory.display();
    cout << endl;

    // Remove first digit and display
    cout << "Removed First digit from List:\n";
    inventory.removeFirstDigit();
    inventory.display();
    cout << endl;

    // Remove last digit and display
    cout << "Removed Last digit from List:\n";
    inventory.removeLastDigit();
    inventory.display();

    return 0;
}
