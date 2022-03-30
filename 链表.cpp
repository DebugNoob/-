#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#define inf 1e+9
using namespace std;
struct node
{
    int data;
    node *next = NULL;
};
node *Cratelist(int array[], int n) //将数组按顺序放入链表中
{
    node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        node *tmp = new node;
        tmp->data = array[i];
        if (tail == NULL) //首节点
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
    return head;
}
void Printlist(node *head)
{
    for (node *pi = head; pi != NULL; pi = pi->next)
    {
        if (pi->next == NULL)
            cout << pi->data << endl;
        else
            cout << pi->data << "->";
    }
}
node *Find(node *head, int a)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->data == a)
            return tmp;
    }
    return NULL;
}
void Insert(node *head, int a, int e) //在节点a后插入e
{
    node *tmp = Find(head, a);
    if (tmp != NULL)
    {
        node *nodeE = new node;
        nodeE->data = e;
        nodeE->next = tmp->next;
        tmp->next = nodeE;
    }
}
node *Delete(node *head, int a)
{
    node *pre = NULL, *tmp = head;
    while (tmp != NULL && tmp->data != a)
    {
        pre = tmp;
        tmp = tmp->next;
    }
    if (tmp->data == a)
    {
        if (pre == NULL)
        {
            head = tmp->next;
        }
        else
            pre->next = tmp->next;
        delete tmp;
    }
    return head;
}
void Sort(node *head)
{
    for (node *i = head; i != NULL; i = i->next)
    {
        node *min = i;
        for (node *u = i->next; u != NULL; u = u->next)
        {
            if (u->data < min->data)
            {
                min = u;
            }
        }
        swap(min->data, i->data);
    }
}
int main()
{
    int a[10] = {5, 8, 1, 3, 2, 4, 6}, n = 7;
    node *head = Cratelist(a, n);
    Printlist(head);
    Insert(head, 3, 5);
    Printlist(head);
    Printlist(head = Delete(head, 4));
    Printlist(head = Delete(head, 5));
    Sort(head);
    Printlist(head);
}