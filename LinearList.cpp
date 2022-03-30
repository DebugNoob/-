struct linearList
{
    ElementType *data;
    int MaxSize; //能存储的最大元素个数
    int Last;    //线性表当前元素个数
};
typedef struct linearList LinearList;
ElementType GetElem(LinearList *L, int i)
{
    return (i < 0 || i >= L->Last) ? NULL : L->data[i];
    /*此处取值不成功时返回NULL不妥*/
}
void FreeList(LinearList *L)
{
    delete L->data;
}
Bool ListEmpty(LinearList *L)
{
    return (L->Last <= 0);
}
Bool ListFull(LinearList *L)
{
    return (L->Last >= L->MaxSize);
}
int ListLength(LinearList *L)
{
    return L->Last;
}
int LocateElem(LinearList *L, ElementType x)
/*查找表中值为x的结点。若查找成功，则返回第一个值为x的结点的序号；否则返回-1。 */
{
    int i;
    for (i = 0; i < L->Last; i++)
        if (L->data[i] == x)
            return i; /*查找成功*/
    return -1;        /*查找失败*/
}
Bool InsertElem(LinearList *L, ElementType x, int i)
/*在第i个位置插入值为x的结点。
   插入成功则返回TRUE，否则返回FALSE*/
{
    if (i < 0 || i > L->Last || L->Last == L->MaxSize)
        return FALSE; /*插入位置不合理，插入失败*/

    for (int j = L->Last - 1; j >= i; j--)
        L->data[j + 1] = L->data[j]; /*后移*/
    L->data[i] = x;                  /*插入*/
    L->Last++;                       /*表长增1*/
    return TRUE;
}
Bool DeleteElem(LinearList *L, int i)
/*删除表中第i个结点。若删除成功，则返回TRUE；否则返回FALSE*/
{
    if (i < 0 || i >= L->Last || L->Last == 0)
        return FALSE; /*第i个结点不存在，删除失败*/

    for (int j = i; j < L->Last - 1; j++)
        L->data[j] = L->data[j + 1]; /*前移*/
    L->Last--;                       /*表长减1*/
    return TRUE;
}
