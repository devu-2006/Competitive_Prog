#include <bits/stdc++.h>

using namespace std;

class BIT
{
    vector<int> bit;
public:
    BIT(int n){
        bit.assign(n+1,0);
    }
    void update(int id, int val)
    {
        int n = bit.size() - 1;
        while (id <= n)
        {
            bit[id] += val;
            id += (id & -id);
        }
    }
    int query(int id)
    {
        int ans = 0;
        while (id > 0)
        {
            ans += bit[id];
            id -= (id & -id);
        }
        return ans;
    }
};
// vector<int> bit;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    // bit.assign(n + 1, 0);
    BIT bt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        bt.update(i, a[i]);
    }
}
