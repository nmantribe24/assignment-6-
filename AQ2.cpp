#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void displayWithHeadRepeat() {
        if (!head) {
            cout << "List empty";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insertEnd(20);
    list.insertEnd(100);
    list.insertEnd(40);
    list.insertEnd(80);
    list.insertEnd(60);

    cout << "Output: ";
    list.displayWithHeadRepeat();
    return 0;
}
