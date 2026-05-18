#pragma once
#include <string>
#include <unordered_map>
#include <queue>
#include <memory>

struct HuffmanNode{
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    //leaf node (actual character)
    HuffmanNode(char c, int f)
        : ch(c), freq(f), left(nullptr), right(nullptr){}

    //Internal node (just a merger, no character)
    HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r)
        : ch('\0'), freq(f), left(l), right(r){}

    bool isleaf() const {
        return !left && !right;
    }
};