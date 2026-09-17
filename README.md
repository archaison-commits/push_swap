*This project has been created as part of the 42 curriculum by mniwinsk and brechied.*

# Push_swap: Optimized Data Sorting with Two Stacks

## Description
**Push_swap** is an algorithmic and data optimization project within the 42 core curriculum. The main goal of the project is to sort a chaotic list of unique signed integers in ascending order using two stacks (**Stack A** and **Stack B**) and a highly restricted set of instruction actions, while using the absolute lowest number of operations possible. 

Rather than relying on a static, one-size-fits-all algorithm, this implementation evaluates the layout configuration of the input stack right at runtime. The program features an internal selection engine (`strategy.c`) that measures how messy the list is by running a pair inversion check inside `compute_disorder.c`. This generates a disorder rating between `0.0` (fully sorted) and `1.0` (perfectly reversed). Based on this structural rating and the input size, the program dynamically funnels the data stream into the most appropriate sorting algorithm—switching between a minimum-position selection sort (`simple.c`), an active chunk-partitioning engine (`medium.c`), and a bitwise coordinate Radix sort (`complex.c`).

---

## Instructions

### Compilation & Installation
The project compiles directly on Unix-like environments using a standard `Makefile` that enforces strict warning variables (`-Wall -Wextra -Werror`) using the `cc` compiler. 

To build the executable binary from the source repository, navigate to your local root directory and run:
```bash
make
```

To clean and manage your workspace during development, use the standard target rules:
```bash
make clean    # Removes intermediate object configurations (.o files)
make fclean   # Performs a deep clean, removing objects and the push_swap binary
make re       # Triggers a full clean and forces a fresh recompilation cycle
```

### Execution & Operation Modes
The binary takes a formatted series of integers or space-separated quoted string literals as arguments. The first argument provided represents the absolute top element of Stack A.

```bash
./push_swap [strategy_flag] [integers...]
```

#### Runtime Strategy Selectors
* `--simple`: Forces the application to use the O(n²) minimum position sorting strategy.
* `--medium`: Forces the application to use the O(n√n) dynamic chunk-partitioning strategy.
* `--complex`: Forces the application to use the O(n log n) bitwise Radix sort strategy.
* `--adaptive`: Tells the choice switchboard to evaluate the disorder metric and choose the best strategy automatically (default behavior if no flag is provided).

#### Benchmark Performance Mode
By adding the `--bench` flag, you turn on benchmark mode. This prints structured diagnostics and operational distributions straight to standard error (`stderr`), keeping standard output (`stdout`) clear for validation tools:

```bash
$> ARG="5 1 2 4 3"; ./push_swap --bench $ARG > /dev/null
[bench] Disorder: 40.00%
[bench] Strategy: Adaptive / O(n√n)
[bench] Total_ops: 6
[bench] sa: 0 sb: 0 ss: 0 pa: 1 pb: 1
[bench] ra: 2 rb: 0 rr: 0 rra: 2 rrb: 0 rrr: 0
```

#### Error Handling
If formatting violations occur—such as non-numeric characters, inputs that exceed system integer boundaries (`INT_MAX` / `INT_MIN`), or duplicate entries—the program outputs `Error` followed by a newline directly to `stderr` and safely frees all heap-allocated stack memory before closing.

---

## Strategy Selection & Complexity Analysis

The program handles data states dynamically through the execution switchboard inside `choose_strategy()`. When elements are entered, `indexing.c` replaces raw values with relative index numbers from `0` to `Size - 1`. Following this, `compute_disorder.c` runs an exhaustive inversion-counting pass over the linked list nodes. It calculates total entry errors using a pair validation scan:

**Disorder Percentage = Mistakes / Total Possible Pairs**

Based on this runtime evaluation, the collection streams into one of three dedicated algorithmic tracks:

### 1. Simple Sort Track (`simple.c`): O(n²)
* **Trigger Conditions:** Activated automatically if the calculated disorder metric falls below `0.2`.
* **Algorithmic Logic:** The function loops while elements remain in Stack A. In each iteration, `min_position()` finds the list position holding the absolute smallest value. It checks if this position is within the top half (`minpos <= size / 2`) or bottom half of the stack. It then issues targeted up-rotations (`ra`) or down-rotations (`rra`) to shift that node to the top, shifts it to Stack B (`pb`), and repeats the cycle. Once Stack A clears, a sequential wave of pushes (`pa`) moves everything back in perfect order.
* **Complexity Bounds:** Runs at an O(n²) time upper bound due to nested node pointer updates, using O(1) auxiliary space.

### 2. Medium Sort Track (`medium.c`): O(n√n)
* **Trigger Conditions:** Triggered under default adaptive runs when the stack disorder percentage lands within the `0.2` to `0.5` boundary.
* **Algorithmic Logic:** This track implements a chunk-sorting approach. It calculates a dynamic block threshold using a fast square-root estimator (`ft_sqrt`). A conditional worker (`index_position`) screens the list to find chunk matches. Nodes falling within the active block width boundaries are cleanly swept off Stack A into Stack B (`pb`). Unmatched nodes are rolled out of the way using smart `ra` or `rra` rotations. Once Stack A is empty, `pushing_swaping_rotating_b` systematically locates, rotates, and unrolls elements from Stack B back onto Stack A in descending order.
* **Complexity Bounds:** Keeps move production stable within O(n√n) boundaries, maintaining a strict O(1) space requirement.

### 3. Complex Sort Track (`complex.c`): O(n log n)
* **Trigger Conditions:** Selected when processing highly chaotic or adversarial configurations that yield a disorder metric of `≥ 0.5`.
* **Algorithmic Logic:** This track executes a bitwise Radix Sort using index positions, avoiding negative integer shifting issues. It computes the total bit-depth using a bit-shift width check (`how_many_bits`). The sort loops through each bit position. For each node, it applies a bitmask (`(index >> i) & 1`). Elements with a clear bit (`0`) are pushed straight to Stack B (`pb`), while nodes with a set bit (`1`) are bypassed using `ra`. After completing a full pass over the list, all buffered nodes in Stack B are pushed back onto Stack A (`pa`) to prepare for the next bit-plane validation.
* **Complexity Bounds:** Guarantees structural stability at a hard mathematical limit of O(n log n) moves across all edge scenarios, using O(1) auxiliary workspace memory.

---

## Resources

* **Bhargava, Aditya** - *Grokking Algorithms: An illustrated guide for programmers and other curious people*. (Visual guide used for foundational breakdown of selection sorting, array partitions, tracking indices, and conceptualizing algorithmic Big-O time complexity configurations).


### AI Usage Disclosure

* **Tasks & Scope:** AI tools were used exclusively for formatting this `README.md` documentation template to comply with evaluation guidelines, generating test edge cases, debugging.

