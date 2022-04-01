#include <iostream>
template <class T>
void RadixSort(T *pdata, int Clow, int Chigh, int d) //基数的上下界，d为最大位数
{                                                    //T类型单链表(pdata)附加头节点
    struct TempLink
    {
        T *pHead;
        T *pTail;
    };
    int r = Chigh - Clow + 1; //每一位有r种可能
    TempLink *tlink;
    T *p;
    tlink = new TempLink[r];
    for (int i = 0; i < d; i++) //执行d次分配
    {
        for (int j = 0; j < r; j++)
        {
            tlink[j].pHead = tlink[j].pTail = nullptr;
        }
        //将记录分配到r个队列里
        for (p = pdata->next; p != nullptr; p = p->next)
        {
            int j = p->data - Clow;
            if (tlink[j].pHead == nullptr)
            {
                tlink[j].pHead = tlink[j].pTail = p;
            }
            else
            {
                tlink[j].pTail->next = p;
                tlink[j].pTail = p;
            }
        }
        //收集分配到r个队列中的记录
        p = pdata;
        for (int j = 0; j < r; j++)
        {
            if (tlink[j].pHead != nullptr)
            {
                p->next = tlink[j].pHead;
                p = tlink[j].pTail;
            }
        }
        p->next = nullptr;
    }
    delete[] tlink;
}
struct node
{
    int data;
    node *next;
};

int main()
{
    int a[] = {3, 5, 1, 3, 1, 2, 5, 7, 1, 2};
    node *start = new node{0, 0};
    node *p = start;
    for (int i = 0; i < 10; i++)
    {
        node *temp = new node;
        temp->data = a[i];
        temp->next = nullptr;
        p->next = temp;
        p = temp;
    }
    RadixSort(start, 0, 10, 1);
    for (p = start->next; p != nullptr; p = p->next)
    {
        std::cout << p->data << " ";
    }
}