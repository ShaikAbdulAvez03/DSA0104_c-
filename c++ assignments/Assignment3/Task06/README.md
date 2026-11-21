# Task06 – Rules of Operator Overloading

**Assignment:** Assignment3 – CO3 – Constructors, Destructors and Operator Overloading  
**Student:** Shaik Abdul Avez  
**Register Number:** 192472260  

## Problem statement
Implement a dynamic Text class with copy, assignment, concatenation, comparison and self-assignment safety.

## Aim
To analyse the stated C++ concept, implement a correct solution and justify the design using test evidence.

## Design reasoning
- Keep data private when it represents an invariant; expose operations that preserve that invariant.
- Prefer named constants and strongly typed values over unexplained literals.
- Validate boundary and invalid inputs, not only the normal case.
- Select the simplest structure that satisfies the task and remains maintainable as requirements grow.

## Algorithm / pseudocode
1. Read or initialize the required values.
2. Validate inputs and preconditions.
3. Apply the task's C++ construct or class design.
4. Produce the result and report invalid cases clearly.
5. Compare observed behaviour with the expected behaviour.

## Source code
The runnable example is in [`main.cpp`](main.cpp). It is a focused implementation/example for this task; extend it with the complete task-specific evidence required by the assignment sheet.

## Compile and run
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic main.cpp -o main
./main
```

For memory checking where supported:
```bash
g++ -std=c++17 -g -fsanitize=address,undefined -fno-omit-frame-pointer main.cpp -o main
./main
```

## Input and expected output
This task's example uses fixed test data in `main.cpp`. Run it with the commands above. Record the exact terminal output below after executing it on your compiler.

```text
[Paste verified program output here]
```

## Test plan
| Case | Input / condition | Expected behaviour |
|---|---|---|
| Normal | Valid representative values | Correct result |
| Boundary | Minimum/maximum permitted value | Boundary handled correctly |
| Invalid | Invalid value or state | Rejected or safely handled |
| Repeated | Multiple calls / objects | No stale state or resource error |

## Experimental investigation
Run the normal, boundary and invalid tests. Record compiler version, command, observed output and any warnings. Do not report guessed timings or claim screenshots that have not been captured.

## Alternative concept and complexity
Compare the chosen design with a reasonable alternative (for example, procedural functions versus classes, switch versus virtual dispatch, fixed array versus vector, or exceptions versus status returns). State the assumptions. For a fixed number of operations, typical per-operation work is O(1); processing n records is commonly O(n). Include additional storage where the chosen design allocates it.

## Conclusion
The implementation demonstrates the task's central C++ concept. Final submission evidence should include your own execution output, test results and interpretation.
