#include <map>
#include <set>
#include <iostream>
#include <cstddef>
#include <cstdint>
using i64 = std::int64_t;
void solve() {
    int n{};
    std::cin >> n;
    std::string s{};
    s.reserve(n);
    std::cin >> s;
    std::string ans(n, 'a' - 1);
    for (int len = 1; len <= n; ++len) {
        std::set<char> set{};
        std::map<char, char> map{};
        std::string res(len, ' ');
        for (int i = len - 1; i >= 0; --i) {
            char cur = s[i];
            set.insert(cur);
            if (!map.contains(cur)) map[cur] = 'a' + (char)set.size() - 1;
            res[i] = map[cur];
        }
        //std::cerr << "# " << res << '\n';
        if (res > ans) {
            ans = res;
        }
    }
    std::cout << ans << '\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}

