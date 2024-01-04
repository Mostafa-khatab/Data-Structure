#include<iostream>

using namespace std;
#define nl "\n";

struct node {
    int data;
    node *next;

    node() {
        data = 0;
        next = NULL;
    }
};

struct linkedlist {
    node *head;

    linkedlist() {
        head = NULL;
    }

    void InsertBegin(int ele) {
        node *temp = new node();
        temp->data = ele;
        temp->next = head;
        head = temp;
    }

    void InsertEnd(int ele) {
        node *temp = new node();
        temp->data = ele;
        if (head == NULL) {
            InsertBegin(ele);
            return;
        }
        node *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }

    void InsertByPosition(int ele, int pos) {
        node *temp = new node();
        temp->data = ele;
        if (pos == 1) {
            InsertBegin(ele);
            return;
        }
        node *cur = head;
        int cnt = 1;
        while (cur != NULL && cnt < pos - 1) {
            cnt++;
            cur = cur->next;
        }
        if (cur == NULL) {
            InsertEnd(ele);
        } else {
            temp->next = cur->next;
            cur->next = temp;
        }
    }

    void InsertInOrder(int ele) {
        node *temp = new node();
        temp->data = ele;
        if (head == NULL || head->data >= ele) {
            InsertBegin(ele);
            return;
        }
        node *cur = head;
        while (cur->next != NULL && ele > cur->next->data) {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
    }

    void DeleteFromBegin() {
        if (head == NULL) {
            cout << "the list is empty" << nl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteFromEnd() {
        if (head == NULL) {
            cout << "the list is empty" << nl;
            return;
        }
        if (head->next == NULL) {
            DeleteFromBegin();
            return;
        }
        node *cur = head;
        while (cur->next->next != NULL) {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = NULL;
    }

    void DeleteByPosition(int pos) {
        if (head == NULL) {
            cout << "the list is empty" << nl;
            return;
        }
        if (pos <= 0) {
            cout << "invalid input" << nl;
            return;
        }
        if (pos == 1) {
            DeleteFromBegin();
            return;
        }
        node *cur = head;
        int cnt = 1;
        while (cnt < pos - 1 && cur != NULL) {
            cur = cur->next;
            cnt++;
        }
        if (cur == NULL || cur->next == NULL) {
            DeleteFromEnd();
            return;
        }
        node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    void DeleteByValue(int ele) {
        if (head == NULL) {
            cout << "the list is empty" << nl;
            return;
        }
        if (head->data == ele) {
            DeleteFromBegin();
            return;
        }
        node *cur = head;
        while (cur->next != NULL && cur->next->data != ele) {
            cur = cur->next;
        }
        if (cur->next == NULL) {
            cout << "value not found" << nl;
            return;
        }
        node *temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    void UpdateElement(int old_ele, int new_ele) {
        if (head == NULL) {
            cout << "the list is empty" << nl;
            return;
        }
        node *cur = head;
        while (cur->next != NULL) {
            if (cur->data == old_ele) {
                cur->data = new_ele;
                return;
            }
            cur = cur->next;
        }
        cout << "invalid input" << nl;
    }
    void GetSize(){
        int c=0;
        node *cur=head;
        while(cur!=NULL){
            c++;
            cur=cur->next;
        }
        cout<<"the size of list " << c << nl;
    }

    void Display() {
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
    int choose, x;
    while (true) {
        cout << "choose" << nl;
        cout << "1 insert at beginning" << nl;
        cout << "2 insert at end" << nl;
        cout << "3 insert at position" << nl;
        cout << "4 insert in order" << nl;
        cout << "5 delete from beginning" << nl;
        cout << "6 delete from end" << nl;
        cout << "7 delete by position" << nl;
        cout << "8 delete by value" << nl;
        cout << "9 UpdateElement element" << nl;
        cout << "10 get size of list" << nl;
        cout << "99 Display" << nl;
        cin >> choose;
        if (choose == 1) {
            cout<<"Enter The Element To Insert At Beginning"<<nl;
            cin >> x;
            lst.InsertBegin(x);
        } else if (choose == 2) {
            cout<<"Enter The Element To Insert At End"<<nl;
            cin >> x;
            lst.InsertEnd(x);
        } else if (choose == 3) {
            cout<<"Enter The Element To Insert At Position"<<nl;
            cin >> x;
            int z;
            cout<<"Enter The Position To Insert"<<nl;
            cin >> z;
            lst.InsertByPosition(x, z);
        } else if (choose == 4) {
            cout<<"Enter The Element To Insert In Order"<<nl;
            cin >> x;
            lst.InsertInOrder(x);
        } else if (choose == 5) {
            lst.DeleteFromBegin();
        } else if (choose == 6) {
            lst.DeleteFromEnd();
        } else if (choose == 7) {
            cout<<"Enter The Position You Want Delete"<<nl;
            cin >> x;
            lst.DeleteByPosition(x);
        } else if (choose == 8) {
            cin >> x;
            lst.DeleteByValue(x);
        } else if (choose == 9) {
            cout<<"Enter The Element You Want To Update"<<nl;
            cin >> x;
            int new_ele;
            cout<<"Enter The Element The New Value"<<nl;
            cin >> new_ele;
            lst.UpdateElement(x, new_ele);
        }else if (choose == 10) {
            lst.GetSize();
        } else if (choose == 99) {
            lst.Display();
        } else break;
    }
}

