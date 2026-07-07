#include <array>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstddef>
#include <cstdint>
using i64 = std::int64_t;
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> e(n);
    for (int i = 0; i < m; ++i) {
        int u{}, v{}, w{};
        std::cin >> u >> v >> w;
        --u, --v; // 0-idx
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    i64 ans = 0;
    bool ok = true;
    for (int k = 0; k < 30; ++k) {
        std::vector<char> vis(n, false);
        std::vector<int> color(n, 0);
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            std::array<int, 2> cnt{};
            auto dfs = [&](this auto&& self, int u, int c) -> void {
                if (!ok) return;
                vis[u] = true;
                color[u] = c;
                ++cnt[c];
                for (auto [v, w] : e[u]) {
                    int bit = (w >> k) & 1;
                    int nc = c ^ bit;
                    if (!vis[v]) {
                        self(v, nc);
                    } else if (color[v] != nc) {
                        ok = false;
                        return;
                    }
                }
            };
            dfs(i, 0);
            if (!ok) break;
            ans += (i64)std::min(cnt[0], cnt[1]) * ((i64)1 << k);
        }
        if (!ok) break;
    }
    if (ok) {
        std::cout << ans << '\n';
    } else {
        std::cout << -1 << '\n';
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}

