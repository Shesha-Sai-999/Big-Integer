# BigInt Library

## Overview

The `BigInt` library is a C++ implementation for handling large integers beyond the standard data types. This library supports various arithmetic operations such as addition, subtraction, multiplication, division, modulus, exponentiation and many more operators.

## Features

- **Large Integer Support:** Handle integers larger than standard types (like `int` or `long long`).
- **Arithmetic Operations:** Supports addition, subtraction, multiplication, division, modulus, and exponentiation.
- **Comparison Operators:** Includes support for comparing two `BigInt` objects.
- **Input/Output:** Overloaded operators to easily read from input streams and output to the console.

## Files

This library consists of three main files:

1. **`BigInt.h`:** Header file containing all the prototypes of the member functions.
2. **`BigInt.cpp`:** Implementation file containing the code for all the member functions.
3. **`main.cpp`:** The main file that includes the `BigInt.h` header and contains code to demonstrate the usage of the `BigInt` library.

## Installation and Usage

**Compile the Code:**
   Navigate to the directory containing the files
   Before compiling run BigInt.cpp and then run following command in terminal
   ```bash
   g++ -o BigInt main.cpp BigInt.cpp
   .\BigInt
