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

class DoublyCircularList {
    Node* head;
public:
    DoublyCircularList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head->prev = head;
            return;
        }
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head->prev = head;
            return;
        }
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }

    void insertAfter(int key, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                if (temp == head)
                    head = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                if (temp->next == temp) {
                    head = NULL;
                    delete temp;
                    return;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void searchNode(int key) {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found\n";
    }

    void display() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyCircularList list;
    int choice, val, key;
    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Insert Before\n";
        cout << "5. Delete Node\n6. Search Node\n7. Display\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertBefore(key, val);
            break;
        case 5:
            cout << "Enter key to delete: ";
            cin >> key;
            list.deleteNode(key);
            break;
        case 6:
            cout << "Enter key to search: ";
            cin >> key;
            list.searchNode(key);
            break;
        case 7:
            list.display();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
