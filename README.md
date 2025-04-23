# Wealth Sorter

## Description
This program sorts a dataset of 100,000 randomly generated billionaires using either Merge Sort or Quick Sort. Users can sort by name, age, or net worth. The program measures how long each algorithm takes and saves the sorted data to a CSV file.

## Features
- Choose sorting algorithm: Merge Sort or Quick Sort
- Sort by: Name, Age, or Net Worth
- Time how long sorting takes using `chrono`
- Output sorted data to `sorted_output.csv`

## Dataset
The dataset has 100,000 entries. Each billionaire has:
- name (string)
- age (int)
- net worth (double)
- country (string)
- self made (bool)

The raw data is located in the `cmake-build-debug` folder.

## Tools Used
- C++
- `chrono`, `fstream`, `sstream`, `vector` (C++ standard libraries)

## Algorithms
- Merge Sort: O(n log n) worst case
- Quick Sort: O(n^2) worst case
