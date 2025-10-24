//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <queue>
#include <vector>
using namespace std;



struct MinHeap {
    int data[64]; //Array that stores the items into the heap, the items represent the index not their concrete values. Can connect this to WeightArr to achieve the actaul data.
    int size; //Size of the heap


    MinHeap() : size(0) {}
        int parent(int i) {
            return (i-1) / 2; //Represents Parent Node
         }
        int left(int i) {
            return (2*i)+1; //Represents left node of the heap.
        }
        int right(int i) {
            return (2*i)+2; //Represents the right node of the heap
        }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[++size] = idx;
        //upheap(node/pos, wieghtArr)
    }

    int pop(int weightArr[]) {
        //Remove root, left right compared smaller value becomes root. perform upheap at root
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            return 0;
        }
        int minIdx = data[1];
        size--;
        data[1] = data[size];
        //downheap(1,weightArr);

        return minIdx; // placeholder
    }

    void upheap(int pos, int weightArr[]) { //Resorts heap upwards
        // TODO: swap child upward while smaller than parent
        //Implement the parent and Left/right methods to achieve the logic and function.
    }

    void downheap(int pos, int weightArr[]) { //Resorts heap downwards
        // TODO: swap parent downward while larger than any child
        //Implement the parent and Left/right methods to achieve the logic and function.
    }
};

#endif