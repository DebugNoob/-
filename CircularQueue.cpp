#include <iostream>
using namespace std;
struct cQueue
{
    int *a;
    int maxSize;
    int front, rear; //rear指向队尾下一个元素
};
void cQueue::init(int sz)
{
    head = rear = 0;
    maxSize = sz;
    a = new int[sz];
}
bool cQueue::empty()
{
    return head == rear;
}
bool cQueue::full()
{
    return head == (rear + 1) % maxSize;
}
int cQueue::size()
{
    return (rear - head + maxSize) % maxSize;
}
void cQueue::push(int x)
{
    a[rear++] = x;
    rear %= maxSize;
}
int cQueue::front() { return a[head]; }
void cQueue::pop()
{
    head++;
    head %= maxSize;
}
