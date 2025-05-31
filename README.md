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
![minesweeper gif](https://github.com/user-attachments/assets/b06797a9-8a60-45ed-b103-31926100a6bb/minesweeper.gif)


---

### 2. **Sliding Puzzle Solver (8-Puzzle / 15-Puzzle)**
**Objective:** Use the **A\*** search algorithm to solve classic sliding puzzles efficiently.

**Key Highlights:**
- Implemented **A\*** with cost function `f(n) = g(n) + h(n)` to find the shortest solution.
- Integrated heuristics such as **Manhattan Distance** and **Linear Conflict**.
- Used **priority queues** for the frontier and **hash sets** to track explored states.
- Collected performance metrics: **move count**, **search space size**, and **heuristic admissibility**.

**Challenge:**  
Optimizing **heuristic design** to balance **accuracy** and **computational overhead**.
![slidingpuzzle gif](https://github.com/user-attachments/assets/473873e1-1670-4a0f-a592-41edd33c28a1/slidingpuzzle.gif)

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
![autocorrect gif](https://github.com/user-attachments/assets/4ec5022d-6b64-467d-99d4-b8b8d44b89bb/autocorrect.gif)

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
![statemachine gif](https://github.com/user-attachments/assets/558af77b-8626-401e-9cab-5e13c275e2d9/statemachine.gif)
