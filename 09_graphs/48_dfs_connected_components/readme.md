# Connected Components / Flood-Fill Pattern Map

Core idea underneath everything: **Connected Components in a Grid (DFS/BFS flood-fill)**

```text
Grid / Graph -> Traverse neighbors -> Mark visited
```

Interviewers rotate this one concept into 5 disguises. Recognize the disguise, apply the same template.

---

## 1. Counting Components ("How many groups?")

Count connected regions instead of being told "islands" directly.

**Trick wording:** "How many groups are there?", "How many connected regions exist?"

**Approach:** Each unvisited node -> DFS/BFS -> `count++`

| Problem | Difficulty | Link |
|---|---|---|
| Number of Islands | Medium | https://leetcode.com/problems/number-of-islands/ |
| Number of Provinces | Medium | https://leetcode.com/problems/number-of-provinces/ |
| Max Area of Island | Medium | https://leetcode.com/problems/max-area-of-island/ |
| Count Sub Islands | Medium | https://leetcode.com/problems/count-sub-islands/ |
| Number of Closed Islands | Medium | https://leetcode.com/problems/number-of-closed-islands/ |

---

## 2. Spread / Infection / Rotting (Multi-source BFS)

Something spreads outward each time unit. You track **levels (time)**, not counts.

**Trick wording:** "Each minute, infection spreads to adjacent cells", "How long until everything is reached?"

**Approach:** Multi-source BFS. Push ALL starting points into the queue first, then process level by level.

| Problem | Difficulty | Link |
|---|---|---|
| Rotting Oranges | Medium | https://leetcode.com/problems/rotting-oranges/ |
| Walls and Gates | Medium | https://leetcode.com/problems/walls-and-gates/ |
| 01 Matrix | Medium | https://leetcode.com/problems/01-matrix/ |
| Map of Highest Peak | Medium | https://leetcode.com/problems/map-of-highest-peak/ |

---

## 3. Flood Fill / Recolor / Transform Region

You are not counting. You **modify a connected region** in place.

**Trick wording:** "Replace all connected X with Y", "Capture surrounded regions"

**Approach:** DFS/BFS the region -> change values instead of counting.

| Problem | Difficulty | Link |
|---|---|---|
| Flood Fill | Easy | https://leetcode.com/problems/flood-fill/ |
| Surrounded Regions | Medium | https://leetcode.com/problems/surrounded-regions/ |
| Island Perimeter | Easy | https://leetcode.com/problems/island-perimeter/ |
| Pacific Atlantic Water Flow | Medium | https://leetcode.com/problems/pacific-atlantic-water-flow/ |

---

## 4. Blocked / Walls / Constraints Added

Same traversal, but some cells are invalid. Skip them.

**Trick wording:** "You can only move through open cells", "Find if a path exists"

**Approach:** Standard DFS/BFS with an extra validity check:

```cpp
if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == BLOCKED) return;
```

| Problem | Difficulty | Link |
|---|---|---|
| The Maze | Medium | https://leetcode.com/problems/the-maze/ |
| The Maze II | Medium | https://leetcode.com/problems/the-maze-ii/ |
| Path With Maximum Gold | Medium | https://leetcode.com/problems/path-with-maximum-gold/ |
| Unique Paths III | Hard | https://leetcode.com/problems/unique-paths-iii/ |

---

## 5. Shortest Path Disguised as Islands

Distance matters, not just reachability. **BFS becomes mandatory** (BFS guarantees shortest path in unweighted graphs).

**Trick wording:** "Minimum steps to reach target"

**Approach:** BFS with level tracking (either store distance in queue or process level-by-level).

| Problem | Difficulty | Link |
|---|---|---|
| Shortest Path in Binary Matrix | Medium | https://leetcode.com/problems/shortest-path-in-binary-matrix/ |
| Word Ladder | Hard | https://leetcode.com/problems/word-ladder/ |
| Open the Lock | Medium | https://leetcode.com/problems/open-the-lock/ |
| Nearest Exit from Entrance in Maze | Medium | https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/ |

---

## Skill Map

| Variant | Skill tested |
|---|---|
| Counting | DFS/BFS + visited tracking |
| Spread | Multi-source BFS |
| Region transform | DFS modification in place |
| Obstacle handling | Conditional traversal |
| Shortest path | BFS levels / distance |

---

## Trigger Words (instant recognition)

If the problem says any of these, think **graph traversal (DFS or BFS)** immediately:

- "connected"
- "adjacent"
- "region"
- "group"
- "spread"
- "minimum steps"
- "fill"
- "capture"

Mental shortcut: *"Am I walking on a grid where each cell connects to neighbors?"* If yes, it is flood-fill disguised.

---

## Decision Rule: DFS or BFS?

| Question asked | Use |
|---|---|
| How many components? | DFS or BFS (either) |
| Modify a region? | DFS (cleanest) |
| Time to spread everywhere? | Multi-source BFS |
| Shortest path / min steps? | BFS (mandatory) |
| Path exists at all? | DFS or BFS (either) |