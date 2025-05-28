# Data Structures & Algorithms Showcase

Welcome to my DSA Showcase! This repository highlights my skills in solving complex algorithmic problems and building interactive applications using advanced data structures and algorithms. Each project includes visualizations powered by the **Malena framework** (developed by Professor Dave Smith) and **SFML**, illustrating the internal workings of each solution.

## 📌 Projects Overview

---

### 1. **Minesweeper Backtracking Solver**
**Objective:** Solve an *n × n* Minesweeper grid using backtracking based on numeric clues.

**Key Highlights:**
- Designed a `Node` class to represent grid values and determine valid bomb placements.
- Built a **recursive backtracking engine** to explore and undo configurations based on validity.
- Visualized the **step-by-step bomb placement** process using **Malena** and **SFML**.
- Focused on **recursive search**, **state management**, and **iterator patterns**.

**Challenge:**  
Managing the **exponential complexity** of placement combinations while maintaining a smooth and informative visual trace.

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
