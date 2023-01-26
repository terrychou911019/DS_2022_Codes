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

set<int> dfs(int node, int parent)
{
    if (edge[node].size() == 1 && edge[node][0] == parent) // leaf node
    {
        s[node].insert(arr[node]); 
        ans[node] = s[node].size();
        return s[node]; 
    }
    else
    {
        for (auto it : edge[node])
        {
            if (it == parent)
                continue;
            auto tmp = dfs(it, node);
            if (tmp.size() >= s[node].size()) // to prevent tle
                swap(s[node], tmp);
            for (auto item : tmp)
                s[node].insert(item);
        }
        s[node].insert(arr[node]);
        ans[node] = s[node].size();
        return s[node];
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
    auto start = dfs(1, 0);
    //start.insert(s[1].begin(), s[1].end());
    s[1].swap(start);
    for (auto item : start)
        s[1].insert(item);
    //s[1].insert(start.begin(), start.end());
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}