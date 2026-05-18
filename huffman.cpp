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

HuffmanNode* buildTree(unordered_map<char, int>& freq){
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, NodeCmp> pq;

    // one leaf node for each character and push to queue
    for(auto& pair: freq){
        pq.push(new HuffmanNode(pair.first, pair.second));
    } 

    //merging until one node remains
    while(pq.size() > 1){
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        int mergedFreq = left->freq + right->freq;
        pq.push(new HuffmanNode(mergedFreq, left, right));
    }

    return pq.top();
}