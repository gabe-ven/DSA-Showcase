# Data Structures & Algorithms Showcase

Welcome to my DSA Showcase! This repository highlights my skills in solving complex algorithmic problems and building interactive applications using advanced data structures and algorithms. Each project includes visualizations powered by the [Malena framework](https://github.com/daversmith/Malena) (developed by Professor Dave Smith) and **SFML**, illustrating the internal workings of each solution.

## 📌 Projects Overview

---

### 1. Minesweeper Backtracking Solver  
**Objective:** Solve an n × n Minesweeper board by placing bombs using recursive backtracking based on numeric clues.

**Key Highlights:**
- Implemented a `Node` class to represent numbers on the grid and generate valid bomb placement combinations.
- Built a `Model` class to store the board state, nodes, and every step for visualization.
- Developed a `Backtracking` class with a recursive `solve(index)` method to place bombs, validate the state, and backtrack when needed.
- Visualized the solving process using SFML and the Malena framework, highlighting placement attempts and reversals.
- Integrated iterator patterns to efficiently cycle through bomb combinations.

**Challenge:**  
Efficiently exploring exponential bomb combinations while maintaining correct state and rendering a smooth, step-by-step visual trace.

![ezgif-3ac16f87d7b6b9](https://github.com/user-attachments/assets/a8803090-dc38-4c22-bdba-e677669f17ae)


---

### 2. **Sliding Puzzle Solver (3x3)**
**Objective:** Use the **A\*** search algorithm to solve classic sliding puzzles efficiently.

**Key Highlights:**
- Implemented **A\*** with cost function `f(n) = g(n) + h(n)` to find the shortest solution.
- Integrated heuristics such as **Manhattan Distance** and **Linear Conflict**.
- Used **priority queues** for the frontier and **hash sets** to track explored states.
- Collected performance metrics: **move count**, **search space size**, and **heuristic admissibility**.

**Challenge:**  
Optimizing **heuristic design** to balance **accuracy** and **computational overhead**.

![ezgif-298a83a437a354](https://github.com/user-attachments/assets/eade75cd-e8f8-4c4f-aeae-ca3865c9fe75)

---

### 3. **Auto-Correct System Using Heaps**
**Objective:** Create an auto-correct feature that suggests words based on user input from a list of 5000 **baby girl names**.

**Key Highlights:**
- Developed a `Word` class with a custom **priority attribute**, extending **SFML's Text** class.
- Implemented a `FileReader` to load dictionary data and `WordSort` to prioritize suggestions.
- Used a **heap** for efficient **top-k suggestion retrieval** based on relevance.
- Employed **Levenshtein Distance** as the **heuristic** to measure similarity between user input and dictionary words.
- Built an **interactive interface** for **real-time input** and **dynamic suggestions**.

**Challenge:**  
Designing a **responsive**, **modular system** where multiple classes work together **seamlessly**, while optimizing **edit distance calculations** for performance.

![ezgif-2d852957ada9e3](https://github.com/user-attachments/assets/2697a0af-9140-43cf-a6cc-444ba47658d6)

---

### 4. **C++ Variable Identifier Validator (Finite State Machine)**
**Objective:** Validate C++ identifiers using a **deterministic finite automaton (DFA)**, excluding reserved keywords.

**Key Highlights:**
- Built a **DFA** with clearly defined states: `START`, `VALID`, and `INVALID`.
- Filtered out **20+ hardcoded C++ reserved keywords**.
- Provided **real-time validation feedback** via an **interactive SFML interface**.
- Demonstrated concepts in **lexical analysis** and **formal grammars**.

**Challenge:**  
Accurately modeling **DFA transitions** and integrating **keyword filtering** without lagging the user experience.

![ezgif-27e264478ef653](https://github.com/user-attachments/assets/7571f356-c008-4c94-9b23-dc1c415acfb6)
