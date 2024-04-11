#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
*/
void printMemVec(vector<int> vec){
    printf("Vector - Each int is worth %lu bytes\n");
    for (int i = 0; i < vec.size(); i++) {
         printf("Value :%i at Memory Location: %p\n", vec[i] += i);
    }

}

/**
 * @brief increments all of the elements in v by 10
 * 
 * @param b - address to a vector of integers
*/
void incVecBy10(vector<int>& vec){
    for (int i = 0; i < vec.size(); i++) {
        vec[i] += 10;
    }
}

int main() {
    const int SIZE = 5;
    vector<int> vec(SIZE);
    for (int i = 0; i < SIZE; i++) {
        vec[i] = 100 + i;
    }

    printf("Before increment----------\n");

    printMemVec(vec);
    incVecBy10(vec);


    printf("After increment---------\n");
    printMemVec(vec);
    
    //remove last elements of vec

    
    printf("After Pop----------\n");
    //call printMemVec() on vec again to view changes


    //append 101 and 102 at the end of vec

    printf("After push----------\n");
    //call printMemVec() on vec again to view the changes

}