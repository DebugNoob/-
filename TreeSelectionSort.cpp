#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
template <class T>
void TreeSelectionSort(T a[], int n)
{
#define Left(i) (2 * (i)-2 * n)
#define Right(i) (2 * (i)-2 * n + 1)
#define father(i) (n + (i) / 2)
//#define bother(i) ((i)&1 ? (i)-1 : (i) + 1)
#define Root (2 * n - 2)
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define inf 0x3f3f3f3f
    T *t = (T *)malloc(sizeof(T) * (2 * n - 1));
    memcpy(t, a, sizeof(T) * n);
    for (int k = n; k <= Root; k++) //第一轮选择
    {
        t[k] = Min(t[Left(k)], t[Right(k)]);
    }
    a[0] = t[Root];
    for (int k = 1; k <= n - 1; k++) //第二轮至第n轮选择
    {
        int sel = Root;
        int left = Left(sel);
        while (left >= 0)
        {
            sel = (t[sel] == t[left]) ? left : left + 1;
            left = Left(sel);
        }
        t[sel] = inf;
        sel = father(sel);
        while (sel <= Root)
        {
            t[sel] = Min(t[Left(sel)], t[Right(sel)]);
            sel = father(sel);
        }
        a[k] = t[Root];
    }
    free(t);
}
int main()
{
    int a[] = {3, 5, 1, 3, 1, 2, 5, 7, 1, 2};
    TreeSelectionSort<int>(a, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}