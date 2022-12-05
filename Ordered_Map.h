#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#ifndef PROJECT3_ORDERED_MAP_H
#define PROJECT3_ORDERED_MAP_H

//creating a tree backed ordered map. Each node will have a key which is name, and value which is set of string
class Ordered_Map {
private:
    class TreeNode {
    public:
        string name;
        set<string> values;
        int height = 1;
        TreeNode *left;
        TreeNode *right;
        TreeNode(string y) : values(), name(y), height(1), left(nullptr), right(nullptr) {}
    };

    TreeNode* root = nullptr;
    //aids in destructor
    void destruct(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* grandparent);
    TreeNode* rotateRight(TreeNode* grandparent);
    Ordered_Map::TreeNode* helperInsert(TreeNode* helpRoot, const string& name);
    set<string>* searchName(Ordered_Map::TreeNode *helpRoot, const string& name);
    int bf(TreeNode* node);
    int findHeight(TreeNode* node);
    bool helperIsValid(TreeNode* helpRoot, const string& name);

//commands accessed by main!!
public:
    ~Ordered_Map();
    set<string>& operator[](const string& name);
    bool isValid(const string& name);
};


#endif //PROJECT3_ORDERED_MAP_H
