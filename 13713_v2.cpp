#include <iostream>

using namespace std;

const int INF = 1e9;
int n, e, s, f, k;
int length[1010][1010];
int dist[1010];

int main()
{   
    cin >> n >> e;
    cin >> s >> f >> k;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            length[i][j] = -1;
        }
    }

    for (int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        length[u][v] = w;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dist[i] = INF;
    }
    dist[s] = 0;
    
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            for (int l = 0; l < n + 1; l++)
            {
                if (length[j][l] != -1)
                {   
                    cout << j << " to " << l << ": " << length[j][l] << "\n";
                    dist[l] = min(dist[l], dist[j] + length[j][l]);
                }
            }
        }
        cout << "k = " << i << ": " << "for dist\n";
        for (int z = 0; z < n + 1 ; z++)
        {
            cout << "dist " << z << ": " << dist[z] << "\n";
        }  
    }
    
/*
    if (dist[f] == INF)
        cout << "-1\n";
    else
        cout << dist[f] << "\n";
*/
    return 0;
}