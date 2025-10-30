//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//Finished First Draft, Implement into Main

struct MinHeap {
    int data[64]; //Array that stores the items into the heap, the items represent the index not their concrete values. Can connect this to WeightArr to achieve the actaul data.
    int size; //Size of the heap


    MinHeap() : size(0) {}
    //I represents index
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
        upheap(idx, &weightArr[data[size]]);
    }

    int pop(int weightArr[]) {
        //Remove root, left right compared smaller value becomes root. perform upheap at root
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            return -1;
        }
        int minIdx = data[0];
        size--;
        if (size>0){
        data[0] = data[size];
        downheap(0, &weightArr[data[minIdx]]);
    }
        return minIdx; // placeholder
    }

    void upheap(int pos, int weightArr[]) { //Resorts heap upwards, pos represents the index of data to perform the reheap.
        // TODO: swap child upward while smaller than parent
        //Implement the parent and Left/right methods to achieve the logic and function.
        while (pos>0) {
            int Par = parent(pos);
            if (weightArr[pos] >= weightArr[Par]) break;
            swap(weightArr[pos],weightArr[Par]);//exchanges two values/variables of the same type.
            pos = Par;
        }//Ripped Straight out of the C++ Supplement

    }

    void downheap(int pos, int weightArr[]) { //Resorts heap downwards
        // TODO: swap parent downward while larger than any child
        //Implement the parent and Left/right methods to achieve the logic and function.
        while (left(pos) <size) {
            int left1 = left(pos);
            int right1 = right(pos);
            int smallest = pos;

            if (left1 < size && weightArr[data[left1]] < weightArr[data[smallest]]) smallest = left1;
            if (right1 < size && weightArr[data[right1]] < weightArr[data[smallest]]) smallest = right1;

            if (smallest == pos) break;

            swap(data[pos], data[smallest]);
            pos = smallest;
        }

    }
};

#endif