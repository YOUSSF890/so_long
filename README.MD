### **Push Swap – Project Overview**  

**Push Swap** is a **42 Network** project where you need to **sort a stack of numbers** using a limited set of operations, while keeping the number of moves as low as possible. It’s a mix of **algorithm optimization** and **stack manipulation**, making it a challenging but fun project.

---

## 🔹 **Project Goals**
- Take a list of integers as input.
- Sort the numbers using **two stacks (`a` and `b`)**.
- Use a limited set of stack operations.
- Optimize the sorting process to use as few moves as possible.

---

## 🔹 **Allowed Operations**
These are the basic operations you can use:

| **Operation** | **Description** |
|--------------|----------------|
| `sa` | Swap the first two elements of stack `a`. |
| `sb` | Swap the first two elements of stack `b`. |
| `ss` | Swap the first two elements of both stacks. |
| `pa` | Push the top element of stack `b` onto stack `a`. |
| `pb` | Push the top element of stack `a` onto stack `b`. |
| `ra` | Rotate stack `a` (shift up, first element goes to the end). |
| `rb` | Rotate stack `b` (shift up, first element goes to the end). |
| `rr` | Rotate both stacks (`a` and `b`). |
| `rra` | Reverse rotate stack `a` (shift down, last element moves to the top). |
| `rrb` | Reverse rotate stack `b`. |
| `rrr` | Reverse rotate both stacks. |

---

## 🔹 **Implementation Steps**
### **1️⃣ Parsing Input**
- Read the numbers and check for errors (**duplicates, non-numeric values**).
- Store the numbers in **stack `a`**.

### **2️⃣ Choosing a Sorting Algorithm**
Since sorting must be optimized, we use different strategies:
- **Small sets (3–5 numbers):** Use simple logic to sort in a few moves.
- **Larger sets:** Use advanced sorting like **QuickSort or Radix Sort**, adapted for stack operations.

### **3️⃣ Implementing Stack Operations**
- Create functions for each stack operation (`sa`, `pb`, `ra`, etc.).
- Ensure **each move modifies the stacks correctly**.

### **4️⃣ Optimizing the Sorting Process**
- The goal is to **minimize the number of moves**.
- Use strategies like **finding the best element to push** or **rotating stacks efficiently**.

---

## 🔹 **Example Execution**
```sh
./push_swap 5 2 8 1 3
```
Expected output (sequence of operations to sort the numbers):
```sh
pb
pb
ra
sa
pa
pa
```

---

## 🔹 **Bonus: Checker Program**
You also need to write a `checker` program that:
1. Reads the sequence of operations.
2. Applies them to the stack.
3. Checks if the numbers are sorted.

```sh
ARG="5 2 8 1 3"; ./push_swap $ARG | ./checker $ARG
```
If sorted correctly, it prints:  
✅ `OK`  
If incorrect, it prints:  
❌ `KO`  

---

### **🔹 Final Thoughts**
- Push Swap is a **data structure and algorithm optimization challenge**.
- The key is **choosing the right sorting strategy** and **minimizing operations**.
- Understanding **stacks and rotations** is crucial for success.
