#include <iostream>
using namespace std;
template <class T>
void BinaryInsertionScort(T a[], int n)
{
    for (int i = 1; i < n; i++) //采用折半法在a[0]-a[i-1]之间找插入a[i]的位置
    {
        T temp = a[i];
        int l = 0, r = i - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (temp < a[m])
            {
                r = m - 1;
            }
            else
                l = m + 1;
        } //l为插入点
        for (int k = i - 1; k >= l; k--)
        {
            a[k + 1] = a[k];
        }
        a[l] = temp;
    }
}
int main()
{
    int a[] = {3, 5, 1, 3, 1, 2, 5, 7, 1, 2};
    BinaryInsertionScort<int>(a, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}