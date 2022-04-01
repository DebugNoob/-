#include <string.h>
#include <iostream>
template <class T>
void TwoWayMerge(T[], T[], int, int, int);
template <class T>
void OnePassMerge(T[], T[], int, int);
template <class T>
void MergeSort(T a[], int n)
{
    int k;
    T *b = new T[n];
    k = 1; //初始子文件长度为1
    while (k < n)
    {
        OnePassMerge(b, a, k, n); //将a数组的子文件经过一趟归并存到b数组中
        k <<= 1;
        if (k >= n)
            memcpy(a, b, n * sizeof(T));
        else
        {
            OnePassMerge(a, b, k, n);
            k <<= 1;
        }
    }
    delete[] b;
}
template <class T>
void OnePassMerge(T dst[], T src[], int len, int n) //一趟两组归并
{
    int i;
    for (i = 0; i < n - 2 * len; i += 2 * len) //执行两两归并  将长度为n的子文件归并成长度为2*n的子文件
        TwoWayMerge(dst, src, i, i + len - 1, i + 2 * len - 1);
    if (i < n - len) //尾部至多有两个子文件
        TwoWayMerge(dst, src, i, i + len - 1, n - 1);
    else                                               //尾部至多有一个文件
        memcpy(&dst[i], &src[i], (n - i) * sizeof(T)); //？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
}
template <class T>
void TwoWayMerge(T dst[], T src[], int l, int mid, int r) //将l到mid的子文件和mid+1到r的子文件归并保存在dst l开始的位置
{
    int s1, s2;
    for (s1 = l, s2 = mid + 1; s1 <= mid && s2 <= r;)
    {
        if (src[s1] <= src[s2])
            dst[l++] = src[s1++];
        else
            dst[l++] = src[s2++];
    }
    if (s1 <= mid)
        memcpy(&dst[l], &src[s1], (mid - s1 + 1) * sizeof(T));
    else
        memcpy(&dst[l], &src[s2], (r - s2 + 1) * sizeof(T));
}
int main()
{
    int a[] = {3, 5, 1, 3, 1, 2, 5, 7, 1};
    MergeSort<int>(a, 9);
    for (int i = 0; i < 9; i++)
    {
        std::cout << a[i] << " ";
    }
}