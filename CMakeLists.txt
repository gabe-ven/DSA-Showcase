cmake_minimum_required(VERSION 3.14)
project(DSAShowcase)

include(FetchContent)
FetchContent_Declare(
        malena
        GIT_REPOSITORY https://github.com/daversmith/Malena.git
        GIT_TAG v0.2.5
)

FetchContent_MakeAvailable(malena)

add_executable(${PROJECT_NAME}
    main.cpp
    Home/Home.cpp
    Home/Home.h
    Minesweeper/Minesweeper.cpp
    Minesweeper/Minesweeper.h
    Minesweeper/Node.cpp
    Minesweeper/Node.h
    Minesweeper/Model.cpp
    Minesweeper/Model.h
    Minesweeper/Backtracking.cpp
    Minesweeper/Backtracking.h
    StateMachine/StateMachine.cpp
    StateMachine/StateMachine.h
    StateMachine/DFA.cpp
    StateMachine/DFA.h
    Autocorrect/Autocorrect.cpp
    Autocorrect/Autocorrect.h
    Autocorrect/WordSort.cpp
    Autocorrect/WordSort.h
    Autocorrect/Heap.cpp
    Autocorrect/Heap.h
    Autocorrect/Word.cpp
    Autocorrect/Word.h
    Autocorrect/FileReader.cpp
    Autocorrect/FileReader.h
    SlidingPuzzle/Puzzle.cpp
    SlidingPuzzle/Puzzle.h
    SlidingPuzzle/Node.cpp
    SlidingPuzzle/Node.h
    SlidingPuzzle/PuzzleState.cpp
    SlidingPuzzle/PuzzleState.h
    SlidingPuzzle/Constants.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE Malena::Malena)