#include<iostream>

using namespace std;
#define nl "\n";

struct node {
    int data;
    node *next;

    node() {
        data = 0, next = NULL;
    }
};

struct linkedlist {
    node *head;

    linkedlist() {
        head = NULL;
    }

    void Insert(int ele) {
        node *temp = new node();
        temp->data = ele;
        temp->next = head;
        head = temp;
        cout << "The Element Is Inserted" << nl;
    }

    void remove() {
        if (head == NULL) {
            cout << "The Stack Is Empty" << nl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
        cout << "The Element Removed" << nl;
    }

    void display() {
        if (head == NULL) {
            cout << "The List Is Empty" << nl;
            return;
        }
        cout << "The Element Is ";
        node *cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << nl;
    }
};

int main() {
    linkedlist lst;
    int ch, x;
    while (true) {
        cout << "1 Insert" << nl;
        cout << "2 Remove" << nl;
        cout << "3 Display" << nl;
        cout << "0 Exit" << nl;
        cout << "Enter the choose" << nl;
        cin >> ch;
        if (ch == 1) {
            cout << "Enter The Number To Insert" << nl;
            cin >> x;
            lst.Insert(x);
        } else if (ch == 2) {
            lst.remove();
        } else if (ch == 3) {
            lst.display();
        } else if (ch == 0) {
            cout << "See You Soon :)" << nl;
            break;
        }
    }
}

