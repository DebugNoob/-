#include <iostream>
using namespace std;
struct cQueue
{
    int *a;
    int maxSize;
    int front, rear; //rear指向队尾下一个元素
};
void init(cQueue *q, int sz)
{
    q->maxSize = sz;
    q->a = new int[sz];
    q->front = q->rear = 0;
}
void flush(cQueue *q)
{
    delete q->a;
}
bool empty(cQueue *q)
{
    return q->front == q->rear;
}
bool full(cQueue *q)
{
    return q->rear == q->maxSize;
}
void clear(cQueue *q)
{
    q->front = q->rear = 0;
}
int size(cQueue *q)
{
    return q->rear - q->front;
}
bool push(cQueue *q, int x)
{
    if (full(q))
        return 0;
    q->a[q->rear++] = x;
}
void pop(cQueue *q)
{
    q->front++;
}
int front(cQueue *q)
{
    return q->a[q->front];
}
int main()
{
    cQueue q1, q2;
    int a, b, c, v1, v2;
    cin >> a >> b >> c;
    init(&q1, 100);
    init(&q2, 100);
    for (int i = 1; i <= a; i++)
    {
        push(&q1, i);
    }
    for (int i = 1; i <= b; i++)
    {
        push(&q2, i);
    }
    while (c--)
    {
        v1 = front(&q1);
        v2 = front(&q2);
        cout << v1 << " " << v2 << endl;
        pop(&q1);
        pop(&q2);
        push(&q1, v1);
        push(&q2, v2);
    }
}