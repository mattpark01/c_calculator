# Calculator Shell

## Overview
The Calculator Shell is a simple command-line interface application designed to perform basic arithmetic operations such as addition, subtraction, multiplication, and division. This project demonstrates the use of Unix system calls (`fork()`, `wait()`, `execvp()`, and `exit()`) to create a process for each arithmetic operation requested by the user.

## Features
- Perform addition (`A`), subtraction (`S`), multiplication (`M`), and division (`D`) operations.
- Accepts multiple arguments for addition and multiplication.
- Accepts exactly two arguments for subtraction and division.
- Utilizes child processes to execute each arithmetic operation.
- Simple error handling for invalid commands and incorrect argument counts.

## Requirements
- GCC (GNU Compiler Collection) for compiling the source code.
- A Unix-like operating system (Linux, macOS) to utilize the necessary system calls.

## Compilation
To compile the calculator shell and arithmetic operation programs, use the following commands in your terminal:

```bash
gcc calculator_shell.c -o calculator_shell
gcc add.c -o add
gcc subtract.c -o subtract
gcc multiply.c -o multiply
gcc divide.c -o divide
# c_calculator
