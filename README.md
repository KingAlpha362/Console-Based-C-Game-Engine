![NeoVerse City Simulation — project cover](https://raw.githubusercontent.com/KingAlpha362/KingAlpha362/main/assets/covers/programming.png)

# NeoVerse City Simulation

A console-based C++ city simulation using object-oriented components, STL containers, and event processing.

## ✨ Highlights

- City subsystems model power, transport, health, and security.
- Sensor readings and historical logs use different container types.
- Queues and stacks support ordinary events and emergency overrides.

## 🚀 Getting started

With a C++ compiler installed:

```sh
g++ -std=c++11 main.cpp Engineer.cpp CityData.cpp EventSystem.cpp CityComponent.cpp SystemSimulation.cpp -o neoverse
./neoverse
```

On Windows, use `-o neoverse.exe` and launch `.\neoverse.exe`.

## 🗂️ Repository guide

- [CityComponent.cpp](CityComponent.cpp)
- [CityComponent.h](CityComponent.h)
- [CityData.cpp](CityData.cpp)
- [CityData.h](CityData.h)
- [Engineer.cpp](Engineer.cpp)
- [Engineer.h](Engineer.h)
- [EventSystem.cpp](EventSystem.cpp)
- [EventSystem.h](EventSystem.h)

## 📝 Project notes

An educational simulation. Included engineer credentials and data files are for local practice.

<details>
<summary>Original container analysis and project references</summary>

# NeoVerse AI City Survival System

## Overview
This is a console-based C++ simulation system that manages city data, events, and agents using STL containers, algorithms, and object-oriented programming principles.

## How to Run the Simulation
1. Compile the source code using a C++ compiler (e.g., g++):
   ```bash
   g++ -std=c++11 main.cpp Engineer.cpp CityData.cpp EventSystem.cpp CityComponent.cpp SystemSimulation.cpp -o neoverse
   ```
2. Run the executable:
   ```bash
   ./neoverse
   ```
   (On Windows: `neoverse.exe`)

## Local demo accounts

The simulation creates demonstration accounts when its engineer data file is absent. Inspect the local setup code before testing and use disposable lab data.

## Explanation of Containers Used
### 1. Vector for Daily Sensor Readings
A `std::vector` is suitable for fast access because it stores elements in contiguous memory locations. This allows for constant time O(1) random access using indices, which is ideal when we need to quickly retrieve or update specific readings or when applying algorithms that benefit from random access iterators (like `std::sort`).

### 2. Linked List for Historical City Logs
A `std::list` (doubly-linked list) is suitable for unbounded logs because it does not require contiguous memory and does not suffer from reallocation overhead when growing indefinitely. Nodes can be allocated anywhere in memory, allowing infinite expansion (until memory runs out) with constant time O(1) insertions at the end.

### 3. Queue for Event Processing (FIFO)
A `std::queue` implements a First-In-First-Out (FIFO) strategy. This ensures that normal city events (like weather alerts or network overloads) are processed fairly and sequentially in the exact order they were received.

### 4. Stack for Emergency Overrides (LIFO)
A `std::stack` implements a Last-In-First-Out (LIFO) strategy. This is appropriate because emergency situations require immediate attention. The most recent, and often most critical, emergency must be resolved first, putting normal queue events on hold.

## Big-O Analysis Decisions

### Login Search Complexity (Linear vs Binary Search)
- **Linear Search (std::find_if)**: Checks each element one by one. Time complexity: O(N). Slower for large datasets.
- **Binary Search (std::lower_bound)**: Halves the search space at each step but requires a sorted container. Time complexity: O(log N). 
*Decision*: I used `std::sort` to sort the vector of engineers upon loading, and then implemented binary search (using `std::lower_bound`) for authentication. This significantly optimizes lookup times (O(log N)) in large systems.

### Insertion and Traversal Complexities (City Data)
- **Vector (Sensor Readings)**:
  - **Insertion**: O(1) amortized at the back, but O(N) if reallocation occurs or if inserting at the front/middle.
  - **Traversal**: O(N) but highly cache-efficient due to contiguous memory, making it very fast in practice.
- **Linked List (Historical Logs)**:
  - **Insertion**: O(1) to insert a new log node (no shifting or reallocation needed).
  - **Traversal**: O(N), but slower in practice than a vector due to poor cache locality (nodes scattered in memory).

### Algorithm Time Complexity & Justification
- **std::sort (Sensor Data)**
  - *Time Complexity*: O(N log N)
  - *Justification*: Required to efficiently organize data by value for analytics and fast retrieval of percentiles.
- **std::find / std::find_if (Search Event)**
  - *Time Complexity*: O(N)
  - *Justification*: We needed to search for an event/reading meeting specific criteria that isn't naturally sorted. It efficiently iterates until the first match is found.
- **std::min_element & std::max_element (Highest/Lowest Values)**
  - *Time Complexity*: O(N)
  - *Justification*: Traverses the data once to find the minimum/maximum. More efficient than sorting (O(N log N)) when we only need the extremes.
- **std::count_if (Critical Alerts)**
  - *Time Complexity*: O(N)
  - *Justification*: Evaluates a predicate (e.g., value > threshold) against every element to count occurrences. Requires a full traversal, which O(N) guarantees.

# References 

# https://www.w3schools.com/cpp/
# https://www.geeksforgeeks.org/cpp/c-plus-plus/

</details>

---

[← Portfolio](https://github.com/KingAlpha362/KingAlpha362) · [Browse all projects](https://github.com/KingAlpha362/KingAlpha362/blob/main/PORTFOLIO.md)
