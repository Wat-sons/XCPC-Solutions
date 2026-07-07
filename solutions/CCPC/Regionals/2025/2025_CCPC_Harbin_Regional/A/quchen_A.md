# A - A+B Problems

作者：anonymous
文件：`anonymous.cpp`

## 题意概述

读入两个整数 `a` 和 `b`，输出它们的和。

## 关键观察

这题没有额外技巧，直接按照题意实现即可。

## 算法设计

1. 读入两个整数 `a`、`b`
2. 计算 `a + b`
3. 输出结果

## 正确性说明

程序直接输出输入整数的和，结果与题意完全一致，因此正确。

## 复杂度分析

- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`

## 易错点

- 注意输入输出格式。
- 若题目要求多组数据，需要额外处理，但本示例不需要。

## 代码

见同目录下的 `anonymous_A.cpp`

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << (a + b) << '\n';
    return 0;
}
```
