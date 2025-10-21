//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int weight = 0;
    Node* left  = nullptr;
    Node* right = nullptr;
    // Optional: index if you’re mapping leaves to symbols
    int index = -1;
};

struct MinHeap {
    int data[64];
    int size;
    Node* root;      // head of the tree
    Node* current;   // where you're attaching children
    std::vector<Node> nodes;

    MinHeap() : size(0), root(nullptr), current(nullptr) {}

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
            if (size == 0) { //pushes to root if heap is empty
                root = &nodes[idx];
                current = root;
                data[++size] = idx; //increments size and tracks the index
                return;
            } if (current->left == nullptr){ //USED to push to left node
                current->left = &nodes[idx];
                data[++size] = idx;
                return;
            }else if (current->right == nullptr) {//USED to push to right
                current->right = &nodes[idx];
                data[size++] = idx;
                return;
                //Unsure if works for heaps >3 logic looks right for <= 3
            }
    }

    int pop(int weightArr[]) { //Remove root, left right compared smaller value becomes root. perform upheap at root
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) { //Resorts heap
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) { //Resorts heap
        // TODO: swap parent downward while larger than any child
    }
};

#endif