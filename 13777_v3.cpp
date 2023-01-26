#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const int max_n = 200005;

//int arr[max_n], ans[max_n], par[max_n];
vector<int> edge[max_n];
//set<int> s;
//pair<int, set<int>> arr[max_n];
int arr[max_n], ans[max_n];
set<int> s[max_n];

void dfs(int node, int parent)
{   
    if (edge[node].size() == 1 && edge[node][0] == parent) // leaf node
    {
        ans[node] = s[node].size();
    }
    else
    {
        for (auto it : edge[node])
        {
            if (it == parent)
                continue;
            dfs(it, node);
            if (s[it].size() >= s[node].size()) // to prevent tle
                swap(s[node], s[it]);
            for (auto item : s[it])
                s[node].insert(item);
        }
        ans[node] = s[node].size();
    }
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i]; // lucky value
        s[i].insert(arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}