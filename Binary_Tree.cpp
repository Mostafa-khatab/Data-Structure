 #include<iostream>

using namespace std;
#define nl "\n";

struct node {
    int data;
    node *right;
    node *left;

    node() {
        data = 0, right = NULL, left = NULL;
    }
};

struct tree {
    node *root;

    tree() {
        root = NULL;
    }

    void insert(node *&temp, int ele) {
        if (temp == NULL) {
            node *newnode = new node();
            newnode->data = ele;
            temp = newnode;
        } else if (temp->data < ele) {
            insert(temp->right, ele);
        } else {
            insert(temp->left, ele);
        }
        return;
    }

    void Delete(node *&temp, int ele) {
        if (temp == NULL) {
            cout << "Not Found" << nl;
        } else if (temp->data == ele) {
            if (temp->left == NULL) {
                node *temp_right = temp->right;
                delete temp;
                temp = temp_right;
            } else if (temp->right == NULL) {
                node *temp_left = temp->left;
                delete temp;
                temp = temp_left;
            } else {
                node *save_sort = min_node(temp->right);
                temp->data = save_sort->data;
                Delete(temp->right, save_sort->data);
            }
        } else if (temp->data > ele) {
            Delete(temp->left, ele);
        } else {
            Delete(temp->right, ele);
        }
    }

    node *min_node(node *temp) {
        if (temp == NULL) {
            cout << "Tree Is Empty" << nl;
            return NULL;
        }
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    node *max_node(node *temp) {
        if (temp == NULL) {
            cout << "Tree Is Empty" << nl;
            return NULL;
        }
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    void InOrder(node *temp) {
        if (temp != NULL) {
            InOrder(temp->left);
            cout << temp->data << " ";
            InOrder(temp->right);
        }
    }

    void PreOrder(node *temp) {
        if (temp != NULL) {
            cout << temp->data << " ";
            PreOrder(temp->left);
            PreOrder(temp->right);
        }
    }

    void PostOrder(node *temp) {
        if (temp != NULL) {
            PostOrder(temp->left);
            PostOrder(temp->right);
            cout << temp->data << " ";
        }
    }
};

int main() {
    tree tr;
    int ch, x;
    while (true) {
        cout << "1 Insert " << nl;
        cout << "2 Delete" << nl;
        cout << "3 Get Min" << nl;
        cout << "4 Get Max" << nl;
        cout << "5 In Order" << nl;
        cout << "6 Pre Order" << nl;
        cout << "7 Post Order" << nl;
        cout << "0 Exit" << nl;
        cout << "Enter the choose" << nl;
        cin >> ch;
        if (ch == 1) {
            cout << "Enter The Number To Insert" << nl;
            cin >> x;
            tr.insert(tr.root, x);
        } else if (ch == 2) {
            cout << "Enter The Number To Delete" << nl;
            cin >> x;
            tr.Delete(tr.root, x);
        } else if (ch == 3) {
            cout << tr.min_node(tr.root)->data << nl;
        } else if (ch == 4) {
            cout << tr.max_node(tr.root)->data << nl;
        } else if (ch == 5) {
            tr.InOrder(tr.root);
            cout << nl;
        } else if (ch == 6) {
            tr.PreOrder(tr.root);
            cout << nl;
        } else if (ch == 7) {
            tr.PostOrder(tr.root);
            cout << nl;
        } else if (ch == 0) {
            cout << "See You Soon :)" << nl;
            break;
        }
    }
}

