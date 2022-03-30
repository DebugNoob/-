#include <iostream>
#include <cstring>
using namespace std;
class Stack
{
private:
    int *data;
    int max_size;
    int m_top;
    void init()
    {
        data = new int[max_size];
        m_top = -1;
    }

public:
    Stack()
    {
        max_size = 1000;
        init();
    }
    Stack(int size)
    {
        max_size = size;
        init();
    }
    ~Stack()
    {
        delete data;
    }
    void push(int x)
    {
        data[++m_top] = x;
    }
    int pop()
    {
        return data[m_top--];
    }
    int top()
    {
        return data[m_top];
    }
    bool empty()
    {
        if (m_top == -1)
            return true;
        else
            return false;
    }
    Stack &operator=(Stack &obj)
    {
        m_top = obj.m_top;
        max_size = obj.max_size;
        data = new int[max_size];
        for (int i = 0; i <= m_top; i++)
        {
            data[i] = obj.data[i];
        }
        return *this;
    }
};
int main()
{
    Stack t1;
    t1.push(13);
    t1.push(-24);
    t1.push(76);
    cout << t1.top() << endl;
    if (t1.empty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;
    Stack t2 = t1;
    for (int i = 1; i <= 4; i++)
    {
        if (!t2.empty())
            cout << t2.pop() << endl;
        else
            cout << "empty" << endl;
    }
}