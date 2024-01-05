#include<iostream>

using namespace std;
#define nl "\n";

struct node {
    int data;
    node *next;
    node *prev;

    node() {
        data = 0, next = NULL, prev = NULL;
    }
};

struct linkedlist {
    node *head;

    linkedlist() {
        head = NULL;
    }

    void InsertBeginning(int ele) {
        node *temp = new node();
        temp->data = ele;
        if (head == NULL) {
            head = temp;
            temp->next = NULL;
            temp->prev = NULL;
        } else {
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head = temp;
        }
        cout << "The Element Is Inserted" << nl;
    }

    void InsertEnd(int ele) {
        node *temp = new node();
        temp->data = ele;
        if (head == NULL) {
            InsertBeginning(ele);
            return;
        }
        node *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->prev = cur;
        cout << "The Element Is Inserted" << nl;
    }

    void InsertedSorted(int ele) {
        node *temp = new node();
        temp->data = ele;
        if (head == NULL || head->data >= ele) {
            InsertBeginning(ele);
            return;
        } else {
            node *cur = head;
            while (cur != NULL && cur->next->data < ele) {
                cur = cur->next;
            }
            if (cur == NULL) {
                InsertEnd(ele);
            } else {
                temp->next = cur->next;
                cur->next = temp;
                temp->prev = cur;
                temp->next->prev = temp;
            }
        }
        cout << "The Element Is Inserted" << nl;
    }

    void DeleteFromBeginning() {
        if (head == NULL) {
            cout << "The List Is Empty" << nl;
            return;
        }
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        cout << "The Element Is Deleted" << nl;
    }

    void DeleteFromEnd() {
        if (head == NULL) {
            cout << "The List Is Empty" << nl;
            return;
        }
        node *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        node *temp = cur;
        cur = cur->prev;
        cur->next = NULL;
        delete temp;
        cout << "The Element Is Deleted" << nl;
    }

    bool found(int ele) {
        node *cur = head;
        while (cur != NULL) {
            if (cur->data == ele) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void DeleteItem(int ele) {
        if (head == NULL) {
            cout << "The List Is Empty" << nl;
            return;
        }
        if (found(ele)) {
            node *cur = head;
            node *temp2 = NULL;
            if (head->data == ele) {
                if (head->next == NULL) {
                    head = NULL;
                    delete cur;
                } else {
                    head = head->next;
                    head->prev = NULL;
                }
            } else {
                while (cur->data != ele && cur != NULL) {
                    temp2 = cur;
                    cur = cur->next;
                }
                if (cur->next == NULL) {
                    temp2->next == NULL;
                    delete cur;
                } else {
                    temp2->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                }
                cout << "The Element Is Deleted" << nl;
            }
        } else {
            cout << "Not Found :(" << nl;
        }
    }

    void display() {
        node *cur = head;
        cout << "The Element Is ";
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
        cout << "1 Insert At Beginning" << nl;
        cout << "2 Insert At End" << nl;
        cout << "3 Insert Sorted" << nl;
        cout << "4 Delete From Begin" << nl;
        cout << "5 Delete From End" << nl;
        cout << "6 Delete Item" << nl;
        cout << "7 Display" << nl;
        cout << "0 Exit" << nl;
        cout << "Enter the choose" << nl;
        cin >> ch;
        if (ch == 1) {
            cout << "Enter The Number To Insert" << nl;
            cin >> x;
            lst.InsertBeginning(x);
        } else if (ch == 2) {
            cout << "Enter The Number To Insert" << nl;
            cin >> x;
            lst.InsertEnd(x);
        } else if (ch == 3) {
            cout << "Enter The Number To Insert" << nl;
            cin >> x;
            lst.InsertedSorted(x);
        } else if (ch == 4) {
            lst.DeleteFromBeginning();
        } else if (ch == 5) {
            lst.DeleteFromEnd();
        } else if (ch == 6) {
            cout << "Enter The Number To Delete" << nl;
            cin >> x;
            lst.DeleteItem(x);
        } else if (ch == 7) {
            lst.display();
        } else if (ch == 0) {
            cout << "See You Soon :)" << nl;
            break;
        }
    }
}


