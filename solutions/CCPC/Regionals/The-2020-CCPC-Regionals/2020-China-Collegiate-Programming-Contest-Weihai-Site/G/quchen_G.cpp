#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll LIM = 65535;
const ll MOD = 1000000007;
const ll BASE = 91138233;
const ll FULL = 65536;

ll norm(ll x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

struct Seg {
    int n;
    vector<ll> mx, tag, cov;
    vector<bool> has;

    Seg(int n = 0) {
        if (n) init(n);
    }

    void init(int n_) {
        n = n_;
        mx.assign(n * 4 + 5, 0);
        tag.assign(n * 4 + 5, 0);
        cov.assign(n * 4 + 5, 0);
        has.assign(n * 4 + 5, false);
    }

    void pull(int p) {
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    }

    void apply_set(int p, ll v) {
        mx[p] = v;
        cov[p] = v;
        tag[p] = 0;
        has[p] = true;
    }

    void apply_add(int p, ll v) {
        mx[p] += v;
        tag[p] += v;
    }

    void push(int p) {
        if (has[p]) {
            apply_set(p << 1, cov[p]);
            apply_set(p << 1 | 1, cov[p]);
            has[p] = false;
        }
        if (tag[p]) {
            apply_add(p << 1, tag[p]);
            apply_add(p << 1 | 1, tag[p]);
            tag[p] = 0;
        }
    }

    void build(int p, int l, int r, vector<int> &a) {
        tag[p] = cov[p] = 0;
        has[p] = false;

        if (l == r) {
            mx[p] = a[l];
            return;
        }

        int m = (l + r) >> 1;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        pull(p);
    }

    void build(vector<int> &a) {
        build(1, 1, n, a);
    }

    void add(int p, int l, int r, int L, int R, ll v) {
        if (L <= l && r <= R) {
            apply_add(p, v);
            return;
        }

        push(p);

        int m = (l + r) >> 1;
        if (L <= m) add(p << 1, l, m, L, R, v);
        if (R > m) add(p << 1 | 1, m + 1, r, L, R, v);

        pull(p);
    }

    void add(int l, int r, ll v) {
        add(1, 1, n, l, r, v);
    }

    void setv(int p, int l, int r, int pos, ll v) {
        if (l == r) {
            mx[p] = v;
            tag[p] = 0;
            cov[p] = v;
            has[p] = true;
            return;
        }

        push(p);

        int m = (l + r) >> 1;
        if (pos <= m) setv(p << 1, l, m, pos, v);
        else setv(p << 1 | 1, m + 1, r, pos, v);

        pull(p);
    }

    void setv(int pos, ll v) {
        setv(1, 1, n, pos, v);
    }

    int find_first(int p, int l, int r, int L, int R, ll v) {
        if (r < L || R < l || mx[p] < v) return -1;
        if (l == r) return l;

        push(p);

        int m = (l + r) >> 1;

        int res = find_first(p << 1, l, m, L, R, v);
        if (res != -1) return res;

        return find_first(p << 1 | 1, m + 1, r, L, R, v);
    }

    int find(int l, int r, ll v) {
        return find_first(1, 1, n, l, r, v);
    }
};



struct HashSeg {
    int n;
    vector<ll> h, tag, pw, sum;

    HashSeg(int n = 0) {
        if (n) init(n);
    }

    void init(int n_) {
        n = n_;

        h.assign(n * 4 + 5, 0);
        tag.assign(n * 4 + 5, 0);

        pw.assign(n + 5, 1);
        sum.assign(n + 5, 0);

        for (int i = 1; i <= n; i++) {
            pw[i] = pw[i - 1] * BASE % MOD;
            sum[i] = (sum[i - 1] + pw[i]) % MOD;
        }
    }

    ll get_sum(int l, int r) {
        return norm(sum[r] - sum[l - 1]);
    }

    void pull(int p) {
        h[p] = (h[p << 1] + h[p << 1 | 1]) % MOD;
    }

    void apply(int p, int l, int r, ll v) {
        v = norm(v);
        h[p] = (h[p] + v * get_sum(l, r)) % MOD;
        tag[p] = (tag[p] + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (!tag[p]) return;

        int m = (l + r) >> 1;

        apply(p << 1, l, m, tag[p]);
        apply(p << 1 | 1, m + 1, r, tag[p]);

        tag[p] = 0;
    }

    void build(int p, int l, int r, vector<int> &a) {
        tag[p] = 0;

        if (l == r) {
            h[p] = 1LL * a[l] * pw[l] % MOD;
            return;
        }

        int m = (l + r) >> 1;

        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);

        pull(p);
    }

    void build(vector<int> &a) {
        build(1, 1, n, a);
    }

    void add(int p, int l, int r, int L, int R, ll v) {
        if (L <= l && r <= R) {
            apply(p, l, r, v);
            return;
        }

        push(p, l, r);

        int m = (l + r) >> 1;

        if (L <= m) add(p << 1, l, m, L, R, v);
        if (R > m) add(p << 1 | 1, m + 1, r, L, R, v);

        pull(p);
    }

    void add(int l, int r, ll v) {
        add(1, 1, n, l, r, v);
    }

    ll ask(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) return h[p];

        push(p, l, r);

        int m = (l + r) >> 1;
        ll res = 0;

        if (L <= m) res = (res + ask(p << 1, l, m, L, R)) % MOD;
        if (R > m) res = (res + ask(p << 1 | 1, m + 1, r, L, R)) % MOD;

        return res;
    }

    ll ask(int l, int r) {
        return ask(1, 1, n, l, r);
    }

    ll shift(ll x, int d) {
        return x * pw[d] % MOD;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Seg seg(n);
    seg.build(a);

    HashSeg hs(n);
    hs.build(a);

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r;
            cin >> l >> r;

            vector<int> over;

            while (true) {
                int p = seg.find(l, r, LIM);
                if (p == -1) break;

                over.push_back(p);

                seg.setv(p, -1);
            }

            seg.add(l, r, 1);
            hs.add(l, r, 1);

            for (int p : over) {
                hs.add(p, p, -FULL);
            }
        } else {
            int x, y, len;
            cin >> x >> y >> len;

            ll h1 = hs.ask(x, x + len - 1);
            ll h2 = hs.ask(y, y + len - 1);

            if (x < y) {
                h1 = hs.shift(h1, y - x);
            } else if (x > y) {
                h2 = hs.shift(h2, x - y);
            }

            cout << (h1 == h2 ? "yes\n" : "no\n");
        }
    }

    return 0;
}
