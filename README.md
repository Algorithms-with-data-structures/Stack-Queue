# Stack and Circular Queue Implementation in C++

## Overview
This C++ program implements two fundamental data structures: **Stack** and **Circular Queue**, each with basic operations. It provides a menu-driven interface to:

- Perform **stack operations** (push, pop, and display stack contents).
- Perform **circular queue operations** (insert, read, and display queue contents).

The program also incorporates error handling for cases like stack overflow/underflow and queue full/empty conditions.

## About Stacks
A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. The last element added to the stack is the first one to be removed.

### Operations:
- **Push**: Adds an element to the top of the stack.
- **Pop**: Removes and displays the top element of the stack.
- **Print**: Displays all elements currently in the stack.

## About Circular Queues
A **circular queue** is a linear data structure that uses a single, fixed-size buffer as if it were connected end-to-end. It follows the **First In, First Out (FIFO)** principle, where the first element added is the first one to be removed.

### Operations:
- **Insert**: Adds an element to the end of the queue.
- **Read**: Removes and displays the front element of the queue.
- **Print**: Displays all elements currently in the queue.

## How to Use the Program
### 1. Compile the Program
Use a C++ compiler like `g++` to compile the program:
```bash
 g++ -o stack_queue stack_queue.cpp
```

### 2. Run the Program
Execute the compiled file:
```bash
 ./stack_queue
```

### 3. Interact with the Menu
Upon running, you will be prompted to:
1. Enter the size of the stack and queue.
2. Choose from the following menu options:

```
Stack - choices:
1) Add to stack
2) Read from stack
3) Print stack

Circular queue - choices:
4) Insert to queue
5) Read from queue
6) Print queue

7) End

Choice:
```
### 4. Example Usage
#### For Stack:
- Select **1** to push elements into the stack.
- Select **2** to pop the top element.
- Select **3** to view the current stack contents.

#### For Circular Queue:
- Select **4** to insert elements into the queue.
- Select **5** to read the front element.
- Select **6** to view the current queue contents.

### 5. Exit the Program
Select **7** to terminate the program.

## Code Highlights
### Stack Functions
1. **Push**:
   ```cpp
   void push(int* stack, int& top, int max);
   ```
   Adds an element to the stack. Displays an error if the stack is full.

2. **Pop**:
   ```cpp
   void pop(int* stack, int& top);
   ```
   Removes the top element of the stack. Displays an error if the stack is empty.

3. **Print**:
   ```cpp
   void print_stack(int* stack, int top);
   ```
   Displays all elements in the stack.

### Circular Queue Functions
1. **Insert**:
   ```cpp
   void insert_in_queue(int* queue, int& tail, int head, int maxi);
   ```
   Adds an element to the queue. Displays an error if the queue is full.

2. **Read**:
   ```cpp
   void read_queue(int* queue, int tail, int& head, int maxi);
   ```
   Removes and displays the front element of the queue. Displays an error if the queue is empty.

3. **Print**:
   ```cpp
   void print_queue(int* queue, int tail, int& head, int maxi);
   ```
   Displays all elements in the queue in correct order.

### Example Program Flow
1. Input stack and queue sizes.
2. Use the menu to:
   - Add, read, or display stack contents.
   - Insert, read, or display queue contents.
3. Handle errors (e.g., stack overflow/underflow, queue full/empty).
4. Exit the program by selecting the appropriate option.

## Theory and Applications
### Stack Applications
- Function call management (e.g., recursion).
- Expression evaluation and syntax parsing.
- Undo operations in text editors.

### Circular Queue Applications
- CPU scheduling algorithms.
- Buffer management in operating systems.
- Managing resource pools in multi-threaded systems.

## Limitations
- Fixed sizes for the stack and queue, as determined by user input.
- Limited error handling (e.g., numeric input validation).

