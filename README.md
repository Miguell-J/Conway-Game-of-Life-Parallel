# Game of Life: A Parallel Adventure 🌌

Welcome to **Game of Life: A Parallel Adventure**, an enchanting implementation of John Conway's iconic cellular automaton, brought to life with the power of C++ and OpenMP. Witness the mesmerizing dance of cells across a grid as they evolve through generations, showcasing both sequential and parallel computing prowess. This project is a celebration of life, code, and performance optimization—crafted with love and precision.

---

## 🌟 Overview

This project simulates the **Game of Life**, a zero-player game where simple rules dictate the fate of cells in a grid. Starting from a randomly initialized board, the simulation evolves over 100 generations, offering a visual feast of patterns and chaos. What makes this implementation special? It compares the elegance of sequential execution with the speed of parallel processing using OpenMP, measuring the performance boost in real-time.

- **Language**: C++  
- **Parallelism**: OpenMP  
- **Grid Size**: 500x500 (customizable)  
- **Generations**: 100  

Prepare to be captivated by the beauty of emergent behavior and the thrill of computational efficiency!

---

## ✨ Features

- **Dynamic Grid**: A 500x500 board of cells, initialized with random life (0s and 1s).  
- **Visual Output**: Watch the evolution unfold with a clean, text-based representation (`.` for dead, `O` for alive).  
- **Performance Benchmarking**: Measures execution time for both sequential and parallel runs, calculating the speedup.  
- **Memory Mastery**: Efficient allocation and cleanup of the 2D grid using dynamic memory.  
- **Parallel Magic**: Leverages OpenMP to distribute the workload across 8 threads, binding them to cores for optimal performance.  

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (e.g., `g++`)  
- OpenMP support (usually included with modern compilers like GCC)  

### Compilation
To embark on this journey, compile the code with OpenMP enabled:

```bash
g++ -fopenmp main.cpp utils.cpp -o game_of_life
```

## Running the Simulation

Launch the program and watch the magic unfold:

```
./game_of_life
```

Sit back as the console paints the evolution of life across 100 generations, followed by a detailed performance analysis.

## 🛠️ Code Structure

- **`utils.h`**: Declares the utility functions for printing and initializing the board.  
- **`utils.cpp`**: Implements the board printing (`imprimirTabuleiro`) and random initialization (`inicializarAleatorio`).  
- **`main.cpp`**: The heart of the simulation, orchestrating sequential and parallel runs with OpenMP.  
- **`gameoflifep.h`**: (Assumed to contain `atualizarTabuleiro`, the core logic for updating the grid—ensure it’s included!)  

---

## 🎨 How It Works

1. **Initialization**: A 500x500 grid is dynamically allocated and filled with random 0s and 1s.  
2. **Sequential Run**: The game evolves over 100 generations, printing each step and timing the process.  
3. **Parallel Run**: OpenMP takes the stage, splitting the workload across 8 threads for a faster evolution.  
4. **Performance Insight**: The program calculates and displays the speedup, revealing the power of parallelism.  
5. **Cleanup**: Memory is gracefully freed, leaving no trace behind.  

---

## 📊 Performance

Expect a thrilling showdown between sequential and parallel execution! On a typical system:
- **Sequential Time**: Varies based on hardware (e.g., ~X seconds).  
- **Parallel Time**: Significantly faster with 8 threads (e.g., ~Y seconds).  
- **Speedup**: Often achieves 2x–6x, depending on your CPU’s core count and workload.  

Run it yourself to see the numbers dance!

---

## 🌿 Inspiration

This project is inspired by John Conway’s **Game of Life**, a timeless demonstration of how simple rules can create complex, unpredictable beauty. By adding parallelism, we honor the spirit of exploration—pushing boundaries in both computation and creativity.

---

## 🤝 Contributing

Feel the urge to enhance this masterpiece? Fork the repo, tweak the code, and submit a pull request! Ideas to explore:
- Add colorful terminal output.  
- Implement a graphical interface (e.g., SFML or SDL).  
- Experiment with different grid sizes or rules.  

---

## 🌌 Final Thoughts

The **Game of Life: A Parallel Adventure** is more than code—it’s a window into the wonders of emergence, a testament to the power of parallelism, and a tribute to the elegance of C++. Run it, tweak it, and let it inspire you.

> *“In the Game of Life, every cell tells a story. In this code, every thread weaves a tale of efficiency.”*

Happy coding, and may your generations thrive! 🌟

---
