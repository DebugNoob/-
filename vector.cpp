Vector *Union(Vector *Va, Vector *Vb)
{
    int m, n, i, k, j;
    ElementType x;
    Vector *Vc = (Vector *)malloc(sizeof(Vector));
    n = Va->VectorLength;
    m = Vb->VectorLength;
    InitVector(Vc, m + n);
    j = 0;
    for (i = 0; i < n; i++)
    {
        x = GetNode(Va, i);
        Insert(Vc, x, j);
        j++;
    }
    for (i = 0; i < m; i++)
    {
        x = GetNode(Vb, i);
        k = Find(Va, x);
        if (k == -1)
        {
            insert(Vc, x, j);
            j++;
        }
    }
    return Vc;
}
Vector *Intersection(Vector *Va, Vector *Vb)
{
    int m, n, i, k, j;
    ElementType x;
    Vector *Vc = (Vector *)malloc(sizeof(Vector));
    n = Va->VectorLength;
    m = Vb->VectorLength;
    InitVector(Vc, (m > n) ? n : m);
    i = 0;
    j = 0;
    while (i < m)
    {
        x = GetNode(Vb, i);
        k = Find(Va, x);
        if (k != -1)
        {
            Insert(Vc, x, j);
            j++;
        }
        i++;
    }
    return Vc;
}
