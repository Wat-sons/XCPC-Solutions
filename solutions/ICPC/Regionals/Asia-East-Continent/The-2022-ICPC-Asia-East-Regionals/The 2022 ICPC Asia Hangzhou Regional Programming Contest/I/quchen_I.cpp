#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int B = 3333;
const int LIM = 1000000000;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll total_walk = 0;
int mx = 0;

int walk(ll x) {
    cout << "walk " << x << endl;
    cout.flush();

    int pos;
    cin >> pos;

    total_walk += x;
    mx = max(mx, pos);

    return pos;
}

ll recover_answer(ll diff, int lower_bound_n) {
    ll ans = (ll)4e18;

    for (ll d = 1; d * d <= diff; d++) {
        if (diff % d == 0) {
            ll d1 = d;
            ll d2 = diff / d;

            if (d1 >= lower_bound_n) ans = min(ans, d1);
            if (d2 >= lower_bound_n) ans = min(ans, d2);
        }
    }

    return ans;
}

void guess(ll n) {
    cout << "guess " << n << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. 随机走 3333 步，估计 mx
    for (int i = 1; i <= B; i++) {
        int x = uniform_int_distribution<int>(1, LIM)(rng);
        walk(x);
    }

    unordered_map<int, ll> mp;
    mp.reserve(B * 3);

    // 2. baby step: 连续 walk 1
    for (int i = 1; i <= B; i++) {
        int pos = walk(1);

        if (mp.count(pos)) {
            ll diff = total_walk - mp[pos];
            ll ans = recover_answer(diff, mx);
            guess(ans);
            return 0;
        }

        mp[pos] = total_walk;
    }

    // 3. walk mx
    int pos = walk(mx);

    if (mp.count(pos)) {
        ll diff = total_walk - mp[pos];
        ll ans = recover_answer(diff, mx);
        guess(ans);
        return 0;
    }

    // 4. giant step: 每次 walk 3333
    for (int i = 1; i <= B; i++) {
        int pos = walk(B);

        if (mp.count(pos)) {
            ll diff = total_walk - mp[pos];

            ll ans = recover_answer(diff, mx);

            guess(ans);
            return 0;
        }
    }

    return 0;
}
