#include "huffman.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string inputPath, outputPath;

    cout << "Enter input file path: ";
    cin >> inputPath;
    
    cout << "Enter output file path: ";
    cin >> outputPath;

    // Build frequency table and tree
    ifstream inputFile(inputPath, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    string text((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    if (text.empty()) {
        cerr << "Error: Input file is empty." << endl;
        return 1;
    }

    unordered_map<char, int> freq = buildFreqTable(text);
    HuffmanNode* root = buildTree(freq);

    if (!root) {
        cerr << "Error: Huffman tree could not be built." << endl;
        return 1;
    }

    // Compress
    compress(inputPath, outputPath + ".huf");

    // Decompress
    decompress(outputPath + ".huf", outputPath + "_recovered.txt", root);

    cout << "Compression and decompression finished successfully." << endl;
    return 0;
}
