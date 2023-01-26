#include <iostream>

using namespace std;

const int INF = 1e9;
int n, e, s, f, k;
int length[1000010][3];
int dist[1010];

int main()
{   
    cin >> n >> e;
    cin >> s >> f >> k;

    for (int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        length[i][0] = u;
        length[i][1] = v;
        length[i][2] = w;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dist[i] = INF;
    }
    dist[s] = 0;
    
    for (int i = 0; i <= k; i++)
    {   
        int tmp[1010];
        for (int j = 0; j < n; j++)
        {
            tmp[j] = dist[j];
        }

        /*
        cout << "k = " << i << ": ";
        for (int j = 0 ; j < n ; j++)
            cout << tmp[j] << " ";
        cout << "\n";
        */

        for (int j = 0; j < e; j++)
        {   
            //cout << "k = " << i << ": " << length[j][0] << " to " << length[j][1] << ": " << length[j][2] << "\n";
            tmp[length[j][1]] = min(tmp[length[j][1]], dist[length[j][0]] + length[j][2]);
        }

        for (int j = 0; j < 1010; j++)
        {   
            int t = dist[j];
            dist[j] = tmp[j];
            tmp[j] = t;
        }
    }
    
    if (dist[f] == INF)
        cout << "-1\n";
    else
        cout << dist[f] << "\n";

    return 0;
}