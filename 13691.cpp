#include <iostream>

using namespace std;

int leafNodes[270005], tmp[270005];
int cnt;

int myabs(int num) {
    if (num >= 0)
        return num;
    else   
        return -num;
}

int mypow(int x, int y)
{
    int t;
    if (y == 0)
        return 1;

    t = mypow(x, y / 2);
    if ((y % 2) == 0)
        return t * t;
    else
        return x * t * t;
}

void swapNodes(int lhs, int rhs, int dg)
{
    if (lhs != rhs)
    {
        int mid = (lhs + rhs) / 2;
        swapNodes(lhs, mid, dg - 1);
        swapNodes(mid + 1, rhs, dg - 1);
        
        int p = mypow(2, dg - 1);

        if (leafNodes[lhs] > leafNodes[lhs + p])
        {
            cnt += 1;
            for (int i = 0 ; i < p ; i++)
            {
                tmp[i] = leafNodes[lhs + i];
                leafNodes[lhs + i] = leafNodes[lhs + p + i];
                leafNodes[lhs + p + i] = tmp[i];
            }
        }
    }
}

int findDegree(int num)
{
    int d = 0;
    while (num != 1)
    {
        num = num / 2;
        d += 1;
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {   
        int n;
        cin >> n;
        int degree = findDegree(n);
        bool possible = 1;
        cnt = 0;
        for (int i = 0 ; i < n ; i++)
        {
            cin >> leafNodes[i];
        }
        for (int i = 0 ; i < n ; i++)
        {
            if (i % 2 == 0)
            {
                if (myabs(leafNodes[i] - leafNodes[i + 1]) != 1)
                {
                    cnt = -1;
                    possible = false;
                    break;
                }
            }
        }

        if (possible)
            swapNodes(0, n - 1, degree);

        cout << cnt << "\n";
    }
    return 0;
}