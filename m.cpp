#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int s[500005], e[500005];

void Merge(int *init, int *merged, const int l, const int m, const int n)
{   
    int i1, i2, iresult;
    for (i1 = l, iresult = l, i2 = m + 1; i1 <= m && i2 <= n; iresult++)
    {
        if (init[i1] <= init[i2])
        {
            merged[iresult] = init[i1];
            i1++;
        }
        else
        {
            merged[iresult] = init[i2];
            i2++;
        }
    }
    copy (init + i1, init + m + 1, merged + iresult);
    copy (init + i2, init + n + 1, merged + iresult);
}

void MergePass(int *init, int *result, const int n, const int s)
{   
    int i;
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
        Merge(init, result, i, i + s - 1, i + 2 * s - 1);
    if ((i + s - 1) < n)
        Merge(init, result, i, i + s - 1, n);
    else    
        copy(init + i, init + n + i, result + i);
}

void MergeSort(int *a, const int n)
{   
    int *tmplist = new int[n + 1];
    for (int i = 1; i < n; i *= 2)
    {
        MergePass(a, tmplist, n, i);
        i *= 2;
        MergePass(tmplist, a, n, i);
    }
}

int my_abs(int x)
{
    return x >= 0 ? x : -x;
}

int main()
{   
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    s[0] = 0;
    e[0] = 0;
    s[1] = m;
    e[1] = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        int from, to;
        cin >> from >> to;
        ans += my_abs(from - to);
        s[i] = from;
        e[i] = to;
    }
    
    // merge sort for s, e
    MergeSort(s, n + 1);
    MergeSort(e, n + 1);
    //sort(s, s + n + 2);
    //sort(e, e + n + 2);

    for (int i = 1; i <= n + 1; i++)
    {
        ans += my_abs(s[i] - e[i]);
    }
    cout << ans << "\n";
    return 0;
}