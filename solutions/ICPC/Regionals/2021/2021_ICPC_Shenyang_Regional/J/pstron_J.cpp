#include <array>
#include <iostream>
#include <cstddef>
#include <cstdint>
#include <queue>
using i64 = std::int64_t;
std::array<int, 10000> steps{};
std::array<int, 4> to_array(int x) {
    return {x / 1000, (x / 100) % 10, (x / 10) % 10, x % 10};
}
int to_int(const std::array<int, 4>& arr) {
    return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
}
int add(int x, int y) {
    auto a = to_array(x), b = to_array(y);
    decltype(a) res{};
    for (int i = 0; i < 4; ++i) {
        res[i] = (10 + a[i] + b[i]) % 10;
    }
    return to_int(res);
}
void init() {
    steps[0] = 0;
    constexpr std::array moves = {
        1000, 100, 10, 1, 1100, 110, 11, 1110, 111, 1111
    };
    std::array<char, 10000> vis{};
    for (int i = 0; i < 10000; ++i) vis[i] = false;
    int c = 0;
    std::queue<int> q{};
    q.push(c);
    vis[0] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (const auto& m : moves) {
            int next1 = add(x, m), next2 = add(x, -m);
            if (!vis[next1]) {
                steps[next1] = steps[x] + 1;
                q.push(next1);
                vis[next1] = true;
            }
            if (!vis[next2]) {
                steps[next2] = steps[x] + 1;
                q.push(next2);
                vis[next2] = true;
            }
        }
    }
}
void solve() {
    int x{}, y{};
    std::cin >> x >> y;
    std::cout << steps[add(x, -y)] << '\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    std::size_t t{};
    std::cin >> t;
    for (std::size_t i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

