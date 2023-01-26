#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const int max_n = 200005;

//int arr[max_n], ans[max_n], par[max_n];
vector<int> edge[max_n];
set<int> s;
pair<int, set<int>> arr[max_n];
int ans[max_n];

set<int> dfs(int node, int parent)
{   
    if (edge[node].size() == 1 && edge[node][0] == parent) // leaf node
    {
        arr[node].second.insert(arr[node].first);
        return arr[node].second;
    }
    else
    {
        arr[node].second.insert(arr[node].first);
        for (auto it : edge[node])
        {
            if (it == parent)
                continue; 
            //auto tmp = dfs(it, node);
            //arr[node].second.insert(tmp.begin(), tmp.end());  
            auto tmp1 = dfs(it, node);
            auto tmp2 = arr[node].second;
            if (tmp1.size() >= tmp2.size())
            {
                tmp1.insert(tmp2.begin(), tmp2.end());
                arr[node].second = tmp1;
            }
            else
            {
                tmp2.insert(tmp1.begin(), tmp1.end());
                arr[node].second = tmp2;
            }
        }
        return arr[node].second;
    }
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    auto start = dfs(1, 0);
    //arr[1].second.insert(start.begin(), start.end());
    start.insert(arr[1].second.begin(), arr[1].second.end());
    arr[1].second = start;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i].second.size() << " ";
        //for (auto it : arr[i].second)
        //    cout << it << " ";
        //cout << "\n";
    }
    cout << "\n";
    return 0;
}