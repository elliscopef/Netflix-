#ifndef MERGESORT_H
#define Thanksgiving_Mergesort_h


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


class MergeSort
{
    
public:

    template<class T>
static vector<T> sort(vector<T> a) { 
    if ( a.size() == 1) 
       { return a; } 


    typename vector<T>::iterator mid = a.begin() + a.size() / 2; 
    vector<T> left(a.begin(), mid); 
    vector<T> right(mid, a.end()); 
    left = sort( left ); 
    right = sort( right ); 
    return merge( left, right); 
} 

template<class T> 
static vector<T> merge(vector<T> &left, vector<T> &right) { 
    vector<T> result; 


    int l = 0, r = 0; 
    while ( l < left.size() && r < right.size()) { 
        if ( left[l] > right[r] ) {  
            result.push_back(right[r++]); 
        } 
        else { 
            result.push_back(left[l++]); 
        } 
        
    } 
    while ( l < left.size() ) { 
        result.push_back(left[l++]); 
    } 
    while ( r < right.size() ) { 
        result.push_back(right[r++]); 
    } 
    return result; 
} 
};



#endif
