
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    Node* prev, *next;
    Node (char x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};


bool isPalindrome(Node* head) {
    if (head == nullptr) return true;
    

    Node *left=head, *right=head;
    while (right->next != nullptr) {
        right = right->next;
    }
    
 
    while (left!=right && left->prev!=right) {
   
        if (left->data != right->data)
            return false;
            

        left = left->next;
        right = right->prev;
    }
    
    return true;
}

int main() {
    

    Node *head = new Node('L');
    head->next = new Node('E');
    head->next->prev = head;
    head->next->next = new Node('V');
    head->next->next->prev = head->next;
    head->next->next->next = new Node('E');
    head->next->next->next->prev = head->next->next;
  	head->next->next->next->next = new Node('L');
  	head->next->next->next->next->prev = head->next->next->next;

    if (isPalindrome(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}