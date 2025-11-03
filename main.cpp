//
// Created by Manju Muralidharan on 10/19/25.
//
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "heap.h"
#include <bits/stdc++.h>
using namespace std;

// Global arrays for node information
const int MAX_NODES = 64;
int weightArr[MAX_NODES];
int leftArr[MAX_NODES];
int rightArr[MAX_NODES];
char charArr[MAX_NODES];

// Function prototypes
void buildFrequencyTable(int freq[], const string& filename);
int createLeafNodes(int freq[]);
int buildEncodingTree(int nextFree);
void generateCodes(int root, string codes[]);
void encodeMessage(const string& filename, string codes[]);
inline bool isLeaf(int idx) {
    return leftArr[idx] == -1 && rightArr[idx] == -1;
}

int main() {

    int freq[26] = {0};

    // Step 1: Read file and count letter frequencies
    buildFrequencyTable(freq, "input.txt");

    // Step 2: Create leaf nodes for each character with nonzero frequency
    int nextFree = createLeafNodes(freq);

    // Step 3: Build encoding tree using your heap
    int root = buildEncodingTree(nextFree);

    // Step 4: Generate binary codes using an STL stack
    string codes[26];
    generateCodes(root, codes);

    // Step 5: Encode the message and print output
    encodeMessage("input.txt", codes);

    return 0;
}

/*------------------------------------------------------
    Function Definitions (Students will complete logic)
  ------------------------------------------------------*/

// Step 1: Read file and count frequencies
void buildFrequencyTable(int freq[], const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open " << filename << "\n";
        exit(1);
    }

    char ch;
    while (file.get(ch)) {
        // Convert uppercase to lowercase
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';

        // Count only lowercase letters
        if (ch >= 'a' && ch <= 'z')
            freq[ch - 'a']++;
    }
    file.close();

    cout << "Frequency table built successfully.\n";
}

// Step 2: Create leaf nodes for each character
int createLeafNodes(int freq[]) {
    int nextFree = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            charArr[nextFree] = 'a' + i;
            weightArr[nextFree] = freq[i];
            leftArr[nextFree] = -1;
            rightArr[nextFree] = -1;
            nextFree++;
        }
    }
    cout << "Created " << nextFree << " leaf nodes.\n";
    return nextFree;
}

// Step 3: Build the encoding tree using heap operations
int buildEncodingTree(int nextFree) {
    // TODO:
    // 1. Create a MinHeap object.
    // 2. Push all leaf node indices into the heap.
    // 3. While the heap size is greater than 1:
    //    - Pop two smallest nodes
    //    - Create a new parent node with combined weight
    //    - Set left/right pointers
    //    - Push new parent index back into the heap
    // 4. Return the index of the last remaining node (root)
    MinHeap Heap;
    for (int i = 0; i< nextFree; ++i) {
        Heap.push(i,weightArr);
    }
    while (Heap.size>1) {
        int a = Heap.pop(weightArr); //Stores top value
        int b = Heap.pop(weightArr); //stores value
        int parent = nextFree++; //increments to parent
        if (nextFree > MAX_NODES) { //Check condition for Size
            cout<<" Exceeded Max Nodes";
            break;
        }
        weightArr[parent] = weightArr[a] + weightArr[b]; //Combines the weight of smallest and next smallest Index
        leftArr[parent]  = a; //Identifies left child as A
        rightArr[parent] = b; //Identifies right child as B

        Heap.push(parent,weightArr); //Pushes new parent back int other heap
    }
    int root = Heap.pop(weightArr); //root is the top after size becomes less than 1
    return root; //returns root
}

// Step 4: Use an STL stack to generate codes
void generateCodes(int root, string codes[]) {
    // TODO:
    // Use stack<pair<int, string>> to simulate DFS traversal.
    //DFS traversal means: its a way of traversing a tree through nodes and their neighbors
    //Starts at Top then traverses down to neighbors

    stack<pair<int, string>> tempStack;


    tempStack.emplace(root, ""); //Directly adds to stack.
    while (!tempStack.empty()) {
        auto p = tempStack.top(); // Retrieves top when stack is not empty
        //To view neighboring i should A, pop it, or B, use nodes
        int node = p.first; //Stores the data of int of <int, string>
        string path = p.second; //Stores the data of string of <int, string>
        tempStack.pop();
        int L = leftArr[node];//Stores child index
        int R = rightArr[node];//Stores child index
        // Left edge adds '0', right edge adds '1'.

        //codes[node] = path; //Corrupted the array went out of bounds


        // Record code when a leaf node is reached.
        if (L == -1 && R == -1) { //checks if no children
            char ch = charArr[node]; //character stored at this leaf
            if (ch >= 'a' && ch <= 'z')
                codes[ch - 'a'] = path.empty() ? "0" : path;
            //safety check
        } else {
            if (R != -1) tempStack.emplace(R, path + '1'); //right appends 1
            if (L != -1) tempStack.emplace(L, path + '0'); //left appends 0
            // Left edge adds '0', right edge adds '1'.
        }
    }

}

// Step 5: Print table and encoded message
void encodeMessage(const string& filename, string codes[]) {
    cout << "\nCharacter : Code\n";
    for (int i = 0; i < 26; ++i) {
        if (!codes[i].empty())
            cout << char('a' + i) << " : " << codes[i] << "\n";
    }

    cout << "\nEncoded message:\n";

    ifstream file(filename);
    char ch;
    while (file.get(ch)) {
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
        if (ch >= 'a' && ch <= 'z')
            cout << codes[ch - 'a'];
    }
    cout << "\n";
    file.close();
}