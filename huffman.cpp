#include "huffman.h"
#include <iostream>
#include <fstream>
#include <bitset>

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

void buildCodes(HuffmanNode* node, string code, unordered_map<char, string>& codes){
    if(node == nullptr)return;

    if(node->isLeaf()){
        codes[node->ch] = code;
        return;
    }

    buildCodes(node->left, code + "0" , codes);
    buildCodes(node->right, code + "1", codes);
}

void compress(const string& inputPath, const string& outputPath){
    //step1: read the input file
    ifstream inputFile(inputPath);
    string text((istreambuf_iterator<char> (inputFile)),
                istreambuf_iterator<char>());
    inputFile.close();

    //step2: build frequency tabel and tree
    unordered_map<char, int> freq = buildFreqTable(text);
    HuffmanNode* root = buildTree(freq);

    //step3: generate codes
    unordered_map<char, string> codes;
    buildCodes(root, "", codes);

    //step4: encode the text into a bit string
    string bitString = "";
    for(char c : text){
        bitString += codes[c];
    }

    //step5: write encoded bits to output file
    ofstream outputFile(outputPath, ios::binary);
    int padding = 8 - bitString.size()%8;
    outputFile.put(padding);

    for (int i = 0; i < bitString.size(); i += 8) {
        bitset<8> bits(bitString.substr(i, 8));
        outputFile.put(bits.to_ulong());
    }

    outputFile.close();
    cout << "Compressed Successfully!" << endl;
           
}