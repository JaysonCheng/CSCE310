/**
 * Name: Jayson Cheng
 * NUID: 28638995
 * Assignment 4
 */

#ifndef CSCE310HOMEWORK04PART01_H
#define CSCE310HOMEWORK04PART01_H
#include <vector>
#include <cstdint>
using namespace std;

struct blockData
{
    int weight;
    int capacity;
    int remCapacity;
};

// Comaprator function to sort capacity in struct in ascending order
int tallestTower( vector<int> , vector<int> );

// Main function to return the greatest number of blocks that can be stacked on top of each other
bool compareCap(const blockData &x, const blockData &y);

#endif

