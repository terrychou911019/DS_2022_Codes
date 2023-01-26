// tle: 2/6

#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const int max_n = 200005;

int arr[max_n], ans[max_n], par[max_n];
vector<int> edge[max_n];
set<int> s;

void find_par(int node, int parent)
{   
    par[node] = parent;
    for (auto it : edge[node])
    {   
        if (it == parent)    
            continue;
        find_par(it, node);
    }
}

void dfs(int node, int parent)
{   
    s.insert(arr[node]);
    for (auto it : edge[node])
    {
        if (it == parent)
            continue;
        dfs(it, node);
    }
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    find_par(1, 0);
    for (int i = 1; i <= n; i++)
    {
        s.clear();
        dfs(i, par[i]);
        cout << s.size() << " ";   
    }
    cout << "\n";
    return 0;
}