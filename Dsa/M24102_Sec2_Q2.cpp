#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int val;
    struct Node *next;
};

class Stack
{
private:
    struct Node *top = NULL;
    int stackSize = 0;

public:
    void Push(int x)
    {
        struct Node *newNode = new Node;
        newNode->val = x;
        newNode->next = top;
        top = newNode;
        stackSize++;
        cout << "Pushed: " << top->val << endl;
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "Pop not allowed on empty stack" << endl;
            return;
        }

        struct Node *temp = top;
        top = top->next;
        cout << "Pop: " << temp->val << endl;
        free(temp);
        stackSize--;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        cout << "Top: " << top->val << endl;
        return top->val;
    }

    void Size()
    {
        cout << "Size: " << stackSize << endl;
    }
};

class Queue
{
private:
    struct Node *front = NULL;
    struct Node *rear = NULL;
    int queueSize = 0;

public:
    void Enqueue(int x)
    {
        struct Node *newNode = new Node;
        newNode->val = x;
        newNode->next = NULL;
        queueSize++;
        if (front == NULL && rear == NULL)
        {
            front = rear = newNode;
            cout << "Enqueue: " << rear->val << endl;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        cout << "Enqueue: " << rear->val << endl;
    }

    void Dequeue()
    {
        struct Node *temp = front;

        if (isEmpty())
        {
            cout << "Dequeue not allowed on empty Queue" << endl;
            front = rear = NULL;
            return;
        }
        else
        {
            front = front->next;
            queueSize--;
        }
        cout << "Dequeue: " << temp->val << endl;
        free(temp);
    }

    void Front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front: " << front->val << endl;
    }

    void Back()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Back: " << rear->val << endl;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void Size()
    {
        cout << "Size: " << queueSize << endl;
    }
};

vector<int> getNextGreater(vector<int> &a)
{
    int n = a.size();
    vector<int> v(n, -1);

    Stack st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.isEmpty() && (a[i % n] >= st.Top()))
        {
            st.Pop();
        }

        if (!st.isEmpty() && (i < n))
        {
            v[i] = st.Top();
        }

        st.Push(a[i % n]);
    }

    return v;
}

int main()
{
    Stack s1;
    s1.Pop();
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Pop();
    s1.Push(1);
    s1.Push(4);
    s1.Size();
    int top = s1.Top();
    cout << top << endl;

    Queue q1;
    q1.Dequeue();
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Enqueue(4);
    q1.Size();
    q1.Front();
    q1.Back();
    q1.Dequeue();
    q1.Size();

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> ans = getNextGreater(v);
    cout << "ans ";
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}