# Huffman Compression Tool

A lossless file compression tool built in C++ using Huffman coding.

## What it does
Compresses any text file by encoding frequent characters with shorter 
bit codes and rare characters with longer ones — reducing file size 
with zero data loss.

## Results
- Achieved 50% compression on text files
- Compresses 959 bytes → 479 bytes

## How it works
1. Scans the file and counts character frequencies
2. Builds a Huffman trie using a min-heap priority queue
3. Assigns shorter codes to frequent characters
4. Encodes the file and packs bits into bytes
5. Stores the trie in the file header for decompression

## How to run

### Compile
g++ huffman.cpp main.cpp -o huffman

### Run
./huffman

Enter input file path: test.txt
Enter output file path: output

## Technologies
- Language: C++
- Data structures: Min-heap, Binary trie, Hash map
- File I/O: Binary read/write with bit packing
