#include "huffman.h"
#include <iostream>
#include <fstream>

using namespace std;

unordered_map<char, int> buildFreqTable(const string& text){
    unordered_map<char, int> freq;
    for(char c: text){
        freq[c]++;
    }

    return freq;
}