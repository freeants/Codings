/*
    IndicesOfArray.cc - Keep tracking original indices of an array after sorted.
    Author: freeants, All rights reserved.
*/
#include <iostream>
#include <vector>
#include <numeric>   // std::iota
#include <algorithm> // std::sort, std::stable_sort

using namespace std;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v)
{

    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    stable_sort(idx.begin(), idx.end(),
                [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });

    return idx;
}

int main(int argc, char const *argv[])
{
    vector<size_t> v = {3, 4, 7, 5, 2, 0, 4, 3, 1, 5};

    cout << "\nOriginal array: ";
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\n  Sorted array: ";
    for (auto i : sort_indexes(v))
        cout << "(" << v[i] << ", " << i << ")";

    cout << "\n";

    return 0;
}