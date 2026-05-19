#include "huffman.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string inputPath, outputPath;

    cout << "Enter input file path:";
    cin >> inputPath;
    
    cout << "Enter output file path:";
    cin >> outputPath;

    //build frequency table and tree
    ifstream inputFile(inputPath);
    string text((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    unordered_map<char, int> freq = buildFreqTable(text);
    HuffmanNode* root = buildTree(freq);

    //compress
    compress(inputPath, outputPath + ".huf");

    //decompress
    decompress(outputPath + ".huf", outputPath + "_recovered.txt", root);

    return 0;
}