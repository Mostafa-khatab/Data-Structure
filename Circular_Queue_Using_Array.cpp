 
#include<iostream>

using namespace std;
#define nl "\n";
int n;
int *queue;
int rear = -1, front = -1;

bool IsEmpty() {
    return (rear == -1);
}

bool IsFull() {
    return (front == (rear + 1) % n);
}

void push(int ele) {
    if (IsFull()) {
        cout << "The Queue Is Full :(" << nl;
        return;
    }
    if (rear == -1)front++;
    rear = (rear + 1) % n;
    queue[rear] = ele;
    cout << "The Element Push :)" << nl;
}

void pop() {
    if (IsEmpty()) {
        cout << "The Queue Is Empty :(" << nl;
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
    cout << "The Queue Pop :)" << nl;
}

void Search(int ele) {
    if (IsEmpty()) {
        cout << "The Queue Is Empty :(" << nl;
        return;
    }
    int i;
    for (i = front; i != rear; i = (i + 1) % n) {
        if (queue[i] == ele) {
            cout << "The Element In Position " << i + 1 << " :)" << nl;
            return;
        }
    }
    if (queue[i] == ele) {
        cout << "The Element In Position " << i + 1 << " :)" << nl;
        return;
    }
    cout << "The Element Not Found :(" << nl;
}

int Count() {
    if (IsEmpty()) {
        cout << "The Queue Is Empty :(" << nl;
        return 0;
    }
    int cnt = 1;
    int i;
    for (i = front; i != rear; i = (i + 1) % n) {
        cnt++;
    }
    return cnt;
}

void display() {
    if (IsEmpty()) {
        cout << "The Queue Is Empty :(" << nl;
        return;
    }
    cout << "The Queue Element Is :)" << nl;
    int i;
    for (i = front; i != rear; i = (i + 1) % n) {
        cout << queue[i] << " ";
    }
    cout << queue[i];
    cout << nl;
}

int main() {
    cout << "Enter the size of the Queue" << nl;
    cin >> n;
    queue = new int[n];
    int x, ch;
    while (true) {
        cout << "1 push" << nl;
        cout << "2 pop" << nl;
        cout << "3 Search" << nl;
        cout << "4 display" << nl;
        cout << "5 Is_Empty" << nl;
        cin >> ch;
        if (ch == 1) {
            cout << "Enter The Element To Push" << nl;
            cin >> x;
            push(x);
        } else if (ch == 2) {
            pop();
        } else if (ch == 3) {
            cout << "Enter The Element To Search" << nl;
            cin >> x;
            Search(x);
        } else if (ch == 4) {
            display();
        } else if (ch == 5) {
            if (IsEmpty()) {
                cout << "The Queue Is Empty :(" << nl;
                continue;
            }
            cout << "The Queue Is Contain " << Count() << " Element :)" << nl;
        } else if (ch == 0) {
            break;
        } else {
            cout << "Invalid Input :(" << nl;
        }
    }
}

