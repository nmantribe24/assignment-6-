#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Size of Doubly Linked List: " << list.getSize() << endl;
    return 0;
}
