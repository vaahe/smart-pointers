# Smart Pointers in C++

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Smart Pointer Types](#smart-pointer-types)
- [Installation](#installation)
- [Usage](#usage)

## Introduction

This project demonstrates the implementation and use of **smart pointers** in
C++. Smart pointers help manage dynamically allocated memory by automatically
handling memory deallocation, thus preventing memory leaks. This project covers
the use of different types of smart pointers and examples to illustrate their
benefits and applications.

## Features

- **Automatic memory management** using C++ standard smart pointers.
- Detailed examples of **unique_ptr**, **shared_ptr**, and **weak_ptr**.
- Explanation of **RAII (Resource Acquisition Is Initialization)** in memory
  management.
- **Examples and comments** to explain the usage of each smart pointer type.

## Smart Pointer Types

1. **std::unique_ptr** - Ensures a single owner for the dynamically allocated
   object. Useful when exclusive ownership is desired.
2. **std::shared_ptr** - Allows multiple shared ownerships of a dynamically
   allocated object. The object is deleted when the last `shared_ptr` reference
   goes out of scope.
3. **std::weak_ptr** - Works with `shared_ptr` to break circular references by
   holding a weak reference that does not affect the reference count.

## Installation

To use this project, you need a C++ compiler that supports C++11 or newer.

1. Clone the repository:
   ```bash
   git clone https://github.com/vaahe/smart-pointers.git
   ```
2. Navigate to the project directory:
   ```bash
   cd smart-pointers
   ```
3. Compile the code:

   ### On Windows

   ```bash
   ./run.bat
   ```

   ### On Linux/macOS

   ```bash
   chmod +x run.sh
   ```

   then run the following command:

   ```bash
   ./run.sh
   ```

## Usage

Run the compiled program:

```bash
./smart_pointers
```
