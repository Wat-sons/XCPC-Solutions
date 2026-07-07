#include <string>
#include <iostream>
#include <cstddef>
#include <cstdint>
using i64 = std::int64_t;
void solve() {
    std::string s{};
    std::cin >> s;
    int ans = 0;
    for (std::size_t i = s.find("edgnb", 0); i != std::string::npos; i = s.find("edgnb", i + 1)) {
        ++ans;
    }
    std::cout << ans << '\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}

