#include <iostream>
template <class T>
void ShellSort(T a[], int n, int s) //s=n/2
{
    for (int k = s; k > 0; k >>= 1)
    {
        for (int i = k, j; i < n; i++) //将第i号元素插进属于他的分组前面的正确排序中
        {
            T temp = a[i];
            j = i - k; //j为分组里检验是否为插入点
            while (j >= 0 && temp < a[j])
            {
                a[j + k] = a[j]; //a[i]更小，分组里前面元素后移
                j -= k;
            }
            a[j + k] = temp; //不满足循环的j的情况有两种，下标小于0，或想要插入的值temp >= a[j]，所以j+k才为插入点
        }
    }
}
int main()
{
    int a[] = {3, 5, 1, 3, 1, 2, 5, 7, 1, 2};
    ShellSort<int>(a, 10, 5);
    for (int i = 0; i < 10; i++)
    {
        std::cout << a[i] << " ";
    }
}