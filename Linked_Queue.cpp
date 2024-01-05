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
    node *last;

    linkedlist() {
        head = NULL;
        last = NULL;
    }

    void Enqueue(int ele) {
        node *temp = new node();
        temp->data = ele;
        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
        cout << "The Element Is Enqueued" << nl;
    }

    void DeQueue() {
        if (head == NULL) {
            cout << "The List Is Empty" << nl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            last = NULL;
        } else {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "The Element Is Dequeued" << nl;
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
        cout << "1 Enqueue" << nl;
        cout << "2 Dequeue" << nl;
        cout << "3 Display" << nl;
        cout << "0 exit" << nl;
        cout << "Enter the choose" << nl;
        cin >> ch;
        if (ch == 1) {
            cout << "Enter The Number To Enqueue" << nl;
            cin >> x;
            lst.Enqueue(x);
        } else if (ch == 2) {
            lst.DeQueue();
        } else if (ch == 3) {
            lst.display();
        } else if (ch == 0) {
            cout << "See You Soon :)" << nl;
            break;
        }
    }
}

