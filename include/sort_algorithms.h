#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <vector>

namespace SortAlg {

    template <typename T>
    T linearSearch(std::vector<T> &vec, T a);

    // Sort
    template <typename T>
    void selectionSort(std::vector<T> &vec);
    template <typename T>
    void insertionSort(std::vector<T> &vec);
    template <typename T>
    void countingSort(std::vector<T> &vec);
}

#include "sort_algorithms.inl"

#endif 
