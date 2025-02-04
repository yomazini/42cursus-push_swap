
# 🧮 Push_Swap | 42 School Project

### **Sort Like a Mechanical Turk - Fast, Efficient, and Memory-Safe** 🔄  

![Algorithm](https://img.shields.io/badge/Algorithm-Stack%20Sorting-blue)
![42 School Badge](https://img.shields.io/badge/42_School-1337-blue)  
![Language](https://img.shields.io/badge/Language-C-blue)
![Score](https://img.shields.io/badge/Score-125%2F100-brightgreen)  
![Leaks](https://img.shields.io/badge/Memory-0%20Leaks-success)  
![Memory](https://img.shields.io/badge/Memory-Leak%20Free-brightgreen)
![Norminette](https://img.shields.io/badge/Norminette-Passed-00FF00)  
![Performance](https://img.shields.io/badge/100%20Numbers-%E2%89%A4700%20Moves-success)

---

## 🧩 Project Structure  
### **Code Architecture**  
```
├── checker_linux          # Linux checker binary  
├── checker_Mac            # macOS checker binary  
├── Makefile               # Builds push_swap + checker  
├── moves/                 # Core stack operations  
│   ├── pushing.c          # pa/pb logic (push elements between stacks)  
│   ├── rotating.c         # ra/rb/rr logic (rotate stacks)  
│   ├── rrotating.c        # rra/rrb/rrr logic (reverse rotate stacks)  
│   └── swaping.c          # sa/sb/ss logic (swap top elements)  
├── parsing/               # Input handling and validation  
│   ├── libft_tools.c      # Basic string and stack utilities (e.g., ft_strlen, stack_length)  
│   ├── libft_tools1.c     # Extended string utilities (e.g., ft_strdup, ft_strlcpy)  
│   ├── split.c            # Custom ft_split implementation (split arguments into tokens)  
│   ├── validating.c       # Input validation (e.g., syntax_error, error_duplicate)  
│   └── validating2.c      # Advanced input validation (e.g., split_args, free_strs)  
├── push_swap.c            # Main program logic (entry point for push_swap)  
├── push_swap.h            # Header file (defines structs, prototypes, and macros)  
├── src_checker/           # Checker program (validates sorting instructions)  
│   ├── checker.c          # Main checker logic (reads and executes commands)  
│   ├── checker.h          # Checker header file  
│   ├── execute_commands.c # Executes commands (e.g., sa, pb, rr)  
│   ├── get_next_line.c    # Reads commands line by line from stdin  
│   ├── get_next_line_utils.c # Helper functions for get_next_line  
│   └── libft_tools_4checker.c # Custom libft tools for checker (e.g., ft_split, ft_strncmp)  
├── tools/                 # Stack utilities and helper functions  
│   ├── initialiase_a_2_b.c # Initializes nodes for moving from A to B (cost analysis)  
│   ├── initialiase_b_2_a.c # Initializes nodes for moving from B to A (cost analysis)  
│   ├── stack_helpers.c    # Basic stack utilities (e.g., stack_sorted, find_min_node)  
│   └── stack_helpers2.c   # Advanced stack utilities (e.g., append_node, set_cheapest_node)  
└── turkalgo/              # Core sorting algorithm  
    ├── three_sort.c       # Optimized sorting for 3 elements (e.g., sort_three)  
    └── turk_sort.c        # Main sorting logic (e.g., turk_sort, move_a_2_b, move_b_2_a)   
```

---

## 🎯 Project Overview

## 🌟 Overview  
Push_Swap is a **highly optimized stack-sorting algorithm** that manipulates two stacks (`A` and `B`) using only 11 operations. This project demonstrates mastery of **algorithm design**, **memory management**, and **error handling**, achieving **125/100** with full test compliance.  

### Core Objectives
- Sort integers using two stacks with minimal operations  
- Develop an efficient algorithm within specific move constraints  
- Implement robust error handling and memory management  
- Create a separate checker program for validation  

**Key Features**:  
- 🚀 **Blazing Speed**: Sorts 100 numbers in ≤700 moves, 500 numbers in ≤5500 moves.  
- 🛡️ **Robust Validation**: Handles invalid inputs, duplicates, and edge cases flawlessly. "They Go_Crazy on this believe me"  
- 🧠 **Hybrid Algorithm**: Combines chunking, cost analysis, and smart rotations.  
- 📊 **Visual Debugging**: Compatible with advanced visualizers for real-time tracking.  

---

## 🧮 Algorithm Deep Dive

### 🎭 The Mechanical Turk Algorithm
Named after the 18th-century "automaton" chess player, this algorithm mimics strategic decision-making through **cost-based optimizations** and **chunking**.  
Curious about the name? Check out this fascinating history! --> [Scam Or Not?](https://www.youtube.com/watch?v=Xosn4ManeD4) 🎪  

### Operation Set
| Operation | Description | Effect |
|-----------|-------------|--------|
| sa | Swap A | Swaps first 2 elements of stack A |
| sb | Swap B | Swaps first 2 elements of stack B |
| ss | sa + sb | Performs both swaps simultaneously |
| pa | Push A | Moves top element from B to A |
| pb | Push B | Moves top element from A to B |
| ra | Rotate A | Shifts up all elements of A by 1 |
| rb | Rotate B | Shifts up all elements of B by 1 |
| rr | ra + rb | Performs both rotations |
| rra | Reverse Rotate A | Shifts down all elements of A by 1 |
| rrb | Reverse Rotate B | Shifts down all elements of B by 1 |
| rrr | rra + rrb | Performs both reverse rotations |

### 🔥 Algorithm Breakdown

#### Phase 1: Strategic Splitting 🎯
```c
// Push first two elements to B (like sending scouts ahead! 🕵️)
pb(b, a);
pb(b, a);
```

#### Phase 2: Sort Three 🎲
```c
void sort_three(t_stack_node **a) {
    // Simple yet effective - like a perfect card trick! 🎴
    if ((*a)->value > (*a)->next->value) sa(a);
    if (last_node(*a)->value < (*a)->value) rra(a);
}
```

#### Phase 3: Cost-Based Merging 🧮
Like a chess grandmaster, we:
1. Find each element's target position  
2. Calculate optimal rotation combinations  
3. Execute moves with surgical precision  

#### Phase 4: Final Polish ✨
Rotate until the smallest element is on top - like aligning stars! ⭐  

---

## 🚀 Installation & Usage

### Building the Project
```bash
make          # Build push_swap  
make bonus    # Build checker  
```

### Basic Usage
```bash
# Sort numbers
./push_swap 4 67 3 87 23

# Validate sorting
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Count moves
./push_swap $ARG | wc -l
```

### Advanced Testing
```bash
# Generate random numbers
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")

# Test with visualization
./push_swap $ARG | ./visualizer

# Memory check
valgrind --leak-check=full ./push_swap $ARG
```

---

## 📊 Performance Metrics
| Stack Size | Min Allowed | This Project | Efficiency |  
|------------|-------------|--------------|------------|  
| 100        | 700         | 580-650      | 100% ✅     |  
| 500        | 5500        | 4900-5200    | 100% ✅     |  


---

### Memory Safety
```bash  
valgrind --leak-check=full ./push_swap 42 21  # Zero leaks guaranteed  
```

---

## 📚 Resources
- **Algorithm Inspired From**: [Medium Article by Ayogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)  
- **Visualizers**:  
  - [Video Explanation Of the Algorithm ](https://www.youtube.com/watch?v=wRvipSG4Mmk)  
  - [Interactive Push_Swap Visualizer](https://windowdong11.github.io/push_swap_visualizer/)  
  - [Visualizer](https://github.com/o-reo/push_swap_visualizer)  

---

## 👨‍💻 Author
**Youssef Mazini**  
[![42 Intra](https://img.shields.io/badge/42_Intra-ymazini-007BFF)](https://profile.intra.42.fr/users/ymazini)  
[![GitHub](https://img.shields.io/badge/GitHub-yomazini-181717)](https://github.com/yomazini)  

```c  
// "Simplicity is the ultimate sophistication." - Leonardo da Vinci  
```

*Made with 💖, ☕, and probably too many stack rotations! Remember: in Push_swap, we don't make mistakes, we have happy little sorting accidents! 🎨*  "deal with it; GL"
