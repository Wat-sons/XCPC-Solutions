#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long double PI = acosl(-1.0L);

ll n, m;

void solve()
{
    cin >> n >> m;

    long double d = 0;

    for(int i = 1; i < m; i++)
    {
        d += min((long double)2.0, PI * i / m);
    }
    d *= 2;
    d += 2;
    long double k = 2.0L * m;
    long double ans = 0;
    ans += k * k * n*(n - 1) * (n + 1) / 6.0L;
    ans += k * d * n * (n + 1) * (2 * n + 1) / 12.0L;
    if(m>1)ans+=2*m*(n+1)*n/2;

    cout << fixed << setprecision(10) << (double)ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while(t--)
    {
        solve();
    }

    return 0;
}
