#include <bit>
#include <iostream>
#include <cstddef>
#include <cstdint>
#include <vector>
using i64 = std::int64_t;
struct problem {
    char verdict;
    int submissions{-1};
    int frozen_submissions{-1};
    int ac{-1};
    int ac_time{-1};
    int penalty{-1};
    friend std::ostream& operator<<(std::ostream& os, const problem& prob) {
        os << prob.verdict;
        switch (prob.verdict) {
        case '+':
            os << ' ' << prob.ac << '/' << prob.ac_time << '\n';
            break;
        case '-':
            os << ' ' << prob.submissions << '\n';
            break;
        case '.':
        default:
            os << '\n';
            break;
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, problem& prob) {
        char verdict{};
        is >> verdict;
        prob = problem(verdict);
        switch (verdict) {
        case '+':
            is >> prob.ac;
            is.ignore();
            is >> prob.ac_time;
            prob.penalty = prob.ac_time + 20 * (prob.ac - 1);
            break;
        case '?':
            is >> prob.frozen_submissions >> prob.submissions;
            break;
        case '-':
            is >> prob.submissions;
            break;
        case '.':
        default:
            break;
        }
        return is;
    }
};
void process(int m) {
    int a{}, b{};
    std::cin >> a >> b;
    std::vector<problem> problems(m);
    std::vector<int> pending_id{};
    int penalty_sum = 0;
    int solved = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> problems[i];
        if (problems[i].verdict == '?') pending_id.push_back(i);
        if (problems[i].verdict == '+') {
            ++solved;
            penalty_sum += problems[i].penalty;
        }
    }
    if (solved > a || solved + (int)pending_id.size() < a) {
        std::cout << "No" << '\n';
        return;
    }
    int p = (int)pending_id.size();
    int p_ac = a - solved, p_penalty = b - penalty_sum;
    if (p_penalty < 0) {
        std::cout << "No" << '\n';
        return;
    }
    bool found = false;
    for (unsigned mask = 0; mask < (1u << p); ++mask) {
        if (std::popcount(mask) != p_ac) continue;
        int min_pen_sum = 0;
        int max_pen_sum = 0;
        for (int i = 0; i < p; ++i) {
            if ((mask >> i) & 1) {
                int id = pending_id[i];
                int s = problems[id].submissions;
                int fs = problems[id].frozen_submissions;
                min_pen_sum += 240 + 20 * (s - fs);
                max_pen_sum += 299 + 20 * (s - 1);
            }
        }
        if (p_penalty >= min_pen_sum && p_penalty <= max_pen_sum) {
            found = true;
            int p_extra = p_penalty - min_pen_sum;
            for (int i = 0; i < p; ++i) {
                int id = pending_id[i];
                if ((mask >> i) & 1) {
                    problems[id].verdict = '+';
                    int s = problems[id].submissions;
                    int fs = problems[id].frozen_submissions;
                    int fails = std::min(p_extra / 20, fs - 1);
                    p_extra -= fails * 20;
                    problems[id].ac = (s - fs + 1) + fails;
                } else {
                    problems[id].verdict = '-';
                }
            }
            for (int i = 0; i < p; ++i) {
                int id = pending_id[i];
                if ((mask >> i) & 1) {
                    int take_mins = std::min(p_extra, 59);
                    p_extra -= take_mins;
                    problems[id].ac_time = 240 + take_mins;
                }
            }
            break;
        }
    }
    if (found) {
        std::cout << "Yes" << '\n';
        for (int i = 0; i < m; ++i) {
            std::cout << problems[i];
        }
    } else {
        std::cout << "No" << '\n';
    }
}
void solve() {
    int n{}, m{};
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        process(m);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}

