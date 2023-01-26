#include <iostream>
#include <stack>

using namespace std;

stack<int> sk_price;
stack<int> sk_days;
int ans[10000005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int price;
    int i = 0;
    while (cin >> price)
    {   
        ans[i] = 1;
        while (!sk_price.empty() && !sk_days.empty() && price <= sk_price.top())
        {
            ans[i] += sk_days.top();
            sk_price.pop();
            sk_days.pop();
        }
        sk_price.push(price);
        sk_days.push(ans[i]);
        i = i + 1;
    }
    for (int k = 0 ; k < i ; k++)
    {
        cout << ans[k] << " ";
    }
    cout << "\n";
    return 0;
}