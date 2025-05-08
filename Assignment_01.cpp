#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int bookCode;
    Node* next;

    Node(int code) {
        bookCode = code;
        next = nullptr;
    }
};

class BookInventory {
private:
    Node* head;

public:
    BookInventory() {
        head = nullptr;
    }

    void initializeInventory() {
        insertAtEnd(101);
        insertAtEnd(102);
        insertAtEnd(103);
    }

    void insertAtStart(int code) {
        Node* newNode = new Node(code);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int code) {
        Node* newNode = new Node(code);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void removeFromStart() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeFromEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->bookCode << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    string vuid = "BC240205517";

    // Extract first and last digits
    char firstDigitChar = vuid[2]; // '2'
    char lastDigitChar = vuid[vuid.length() - 1]; // '7'
    int firstDigit = firstDigitChar - '0';
    int lastDigit = lastDigitChar - '0';

    cout << "------------ Book Inventory Management (" << vuid << ") ------------" << endl;
    cout << "Extracted First and Last Digits are: " << firstDigit << lastDigit << endl << endl;

    BookInventory inventory;

    // Step 2: Initialize inventory
    inventory.initializeInventory();

    // Step 3: Insert first digit at start
    cout << "Added First digit at start of List:\n";
    inventory.insertAtStart(firstDigit);
    inventory.displayList();
    cout << endl;

    // Step 4: Insert last digit at end
    cout << "Added Last digit at Last of List:\n";
    inventory.insertAtEnd(lastDigit);
    inventory.displayList();
    cout << endl;

    // Step 5: Remove first digit from start
    cout << "Removed First digit from List:\n";
    inventory.removeFromStart();
    inventory.displayList();
    cout << endl;

    // Step 6: Remove last digit from end
    cout << "Removed Last digit from List:\n";
    inventory.removeFromEnd();
    inventory.displayList();
    cout << endl;

    cout << "------------------------------\n";

    return 0;
}
