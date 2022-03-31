#include <iostream>
template <class T>
void QucikSort(T a[], int low, int high) //使该组数左侧数<=中心值，右侧数>中心值
{
    int l, r;
    T temp;
    l = low, r = high, temp = a[l];
    if (low >= high)
        return;
    while (l < r) //中心值需要满足左侧数小于等于它，右侧数大于它。
    {
        while (l < r && temp < a[r]) //中心值小于排序码时，右标左移
            r--;
        if (l < r) //l<r时，r的排序码>=中心值
        {
            a[l++] = a[r];
        }
        while (l < r && temp >= a[l])
            l++;
        if (l < r)
            a[r--] = a[l];
    }
    a[l] = temp;
    QucikSort(a, low, --r);
    QucikSort(a, ++l, high);
}
int main()
{
    int a[] = {3, 5, 1, 3, 1, 2, 5, 7, 1, 2};
    QucikSort<int>(a, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        std::cout << a[i] << " ";
    }
}