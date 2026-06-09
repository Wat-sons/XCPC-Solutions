# 仓库结构说明

## 概述

内容分成三层：

1. **比赛层**：记录一场比赛的总览、补题入口、题单索引。
2. **题目层**：记录每个题目的 AC 代码、题解等内容。
3. **作者层**：保留不同作者的独立思路，用文件名前缀区分。

## 推荐结构

```text
solutions/
  ICPC/
    Regionals/
      ExampleRegion/
        The 2025 ICPC Example Regionals/
          The 2025 ICPC Example Regional Contest/
            editorial.md
            A/
              quchen_A.cpp
              quchen_A.md
            B/
              ...
            statement.pdf   # 可选
````

## 目录职责

### 比赛目录

比赛目录下的 `editorial.md` 负责放这些内容：

* 比赛名称、时间、赛制、队内备注
* 题目列表
* 每题的题解链接
* 补题链接
* 外部参考资料
* 可选的赛后总结

### 题目目录

每个题目目录建议放：

* `作者_题号.cpp`：该作者的 AC 代码
* `作者_题号.md`：该作者对该题的题解

例如：

* `quchen_A.cpp`
* `quchen_A.md`

## 命名规范

* 比赛目录尽量使用官方全名。
* 题目目录使用大写题号：`A/ B/ C/`
* 代码文件建议采用：`作者_题号.扩展名`
* Markdown 文件统一使用 UTF-8 编码。

## 推荐工作流

1. 先提交 AC 代码。
2. 再补题解 Markdown。
3. 最后在比赛级 `editorial.md` 中加入索引和外链。
4. 对外部链接注明来源与访问时间。

## 说明

如果某场比赛需要额外的题面、截图或补充材料，可以按比赛目录自行放置，但应优先保证目录清晰、可检索、可维护。
