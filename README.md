# Binary-Search-Tree-lib

## Overview

This project is a C++ implementation of a **Binary Search Tree (BST)**, designed as a foundational library for tree-based data structures. The project is part of a university coursework and serves as a base for future expansions, including other types of trees (e.g., Interval trees, Red-Black trees, etc.).

The library consists of two main files:

- `bst.h` - Contains the class declaration and public interface.
- `bst.cpp` - Provides the implementation of all the methods declared in the header file.

## Features

The current implementation supports the following operations:

### Tree Operations:

- **Insertion**: Add new elements to the tree.
- **Deletion**: Remove elements from the tree.
- **Traversal**: Print elements in pre-order, in-order, and post-order.
- **Search**: Check if an element exists in the tree.
- **Height Calculation**: Compute the height of the tree.
- **Leaf Node Sum**: Calculate the sum of all leaf node values.
- **Minimum and Maximum Values**: Retrieve the smallest and largest values in the tree.
- **Lowest Common Ancestor**: Find the lowest common ancestor of two given values.

### Resource Management:

- **Tree Destruction**: Automatically free memory used by the tree upon program termination.

## Installation and Usage

### Requirements

- A C++17 compatible compiler (e.g., g++, clang++)
- [Visual Studio Code](https://code.visualstudio.com/) or any preferred IDE/editor

### Compilation

To compile the project, use the following command:

```bash
g++ -o bst bst.cpp main.cpp
```

Here, `main.cpp` refers to the file where you test or interact with the library.

### Example Usage

```cpp
#include "bst.h"
#include <iostream>

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    std::cout << "In-order traversal: ";
    tree.printTree();

    std::cout << "Minimum value: " << tree.min() << std::endl;
    std::cout << "Maximum value: " << tree.max() << std::endl;

    return 0;
}
```

### Running

Run the compiled binary:

```bash
./bst
```

## Project Structure

```
.
├── bst.h         # Header file with class declarations
├── bst.cpp       # Implementation of BST methods
├── main.cpp      # Example usage or testing code (to be created by user)
└── README.md     # Project documentation
```

## Future Plans

- Add support for **Interval trees** and **Red-Black Trees**.
- Implement additional traversal algorithms (e.g., level-order).
- Extend functionality to support generic data types with templates.
- Optimize the search and insertion operations.

## Contribution

Contributions are welcome! If you'd like to contribute:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Submit a pull request with a detailed description of your changes.

## License

This project is released under the MIT License. Feel free to use, modify, and distribute it as needed.

