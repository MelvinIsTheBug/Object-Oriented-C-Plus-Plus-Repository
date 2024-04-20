#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

/**
 * @brief reutrns the first index of an element if it exists, otherwise returns -1
 * iterativeSearch starts at the first index and iterates sequentially to the next
 * until it either finds the element or until it reaches the end (i.e. element dne)
 * 
 * @param v: vector of elements
 * @param elem : integer to look for 
 * @return int 
*/

int iterativeSearch(vector<int>v, int elem) {
    for (int i=0; i < v.size(); i++) {
        if (v[i] == elem) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief returns the index of elem, if it exists in v. Otherwise it
 *returns -1. binarySearch is recursive(i.e. function calls itself).
 It utilizes the fact that v is increasing order (e.g. values go up
 duplicates are not allowed).

 It calculates the mid from the start and end index. It compares
 v[mid] (i.e. value at mid) with elem and decides whether to search
 the left half(lower values), or right half(upper values)

 @param v: vector of elements
 @param start : leftmost index (starting value is 0)
 @param end : rightmost index(starting value is v.size())
 @param elem : integer to look for
 @return int
*/

int binarySearch(vector<int> & v, int start, int end, int elem) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end ) / 2;

    if (v[mid] > elem) {
        end = mid -1;
    } else if (v[mid] < elem) {
        end = mid + 1;
    } else {
        return mid;
    }
    return binarySearch(v, start, end, elem);
}

/**
 * @brief updates v to contain the values from filename (leave as is)
 * 
 * It is expected that the files contain values ranging from one to 
 * one hundred million in ascending order (no duplicates).
 * 
 * @param filename: string
 * @param v: vector
*/
void vecGen(string filename, vector<int> & v) {
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num) {
        v.push_back(num);
    }
    file.close();
}



int main() {
    //populate v with 10,000 sorted numbers
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    //test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);
    

    //reads through all 10 of the test_elem values and calls iterative search
    //and records how long each search took
    for(int i = 0; i < elem_to_find.size(); i++) {
        //gets the elem to search for
        int elem = elem_to_find[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = iterativeSearch(v, elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "Time taken by iterativeSearch: " << duration.count() << " microseconds" << endl;    
    }

    for(int i = 0; i < v.size(); i++) {
        //gets the elem to search for
        int elem = v[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = binarySearch(v, 0, v.size(), elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "Time taken by binarySearch: " << duration.count() << " microseconds" << endl;    
    }


    return 0;
}