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
    template <typename T>
    void mergeSort(std::vector<T> &vec, std::size_t first, std::size_t last);
    template <typename T>
    void quickSort(std::vector<T>& vec1, std::size_t l, std::size_t r);
}

#include "sort_algorithms.inl"

#endif 
