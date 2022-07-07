#pragma once
#ifndef LAB_5_CLASSES_H
#define LAB_5_CLASSES_H
#endif //LAB_5_CLASSES_H
#include <iostream>

using namespace std;
class TNode
{
public:
    int num;
    TNode* left;
    TNode* right;
    TNode(int number);
};

class BinaryTree {
private:
    int height;
    int width;
    int k;
public:
    TNode* top;
    BinaryTree(int n);
    TNode* create(int n, int a = 0);
    void printLevelOrder(TNode* r , int height);
    void printCurrentLevel(TNode* r, int level, int width, bool& flag, int i);
};