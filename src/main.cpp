#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include "sort_algorithms.h"

template <typename T>
auto timer(void(*sorting)(std::vector<int>&), std::vector<T> &vec) {
    auto begin = std::chrono::steady_clock::now();
    sorting(vec); 
    auto end = std::chrono::steady_clock::now();
    
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return elapsed_ms.count();
}

template <typename T>
auto timer(void(*sorting)(std::vector<int>&, std::size_t, std::size_t), std::vector<T> &vec, std::size_t l, std::size_t r) {
    auto begin = std::chrono::steady_clock::now();
    sorting(vec, l, r); 
    auto end = std::chrono::steady_clock::now();
    
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return elapsed_ms.count();
}

int main() {
    std::vector<int> vec = {3,2,4,3,1};
    for(auto i : vec)
        std::cout << i << " ";
    std::cout<<std::endl;

    int index = SortAlg::linearSearch(vec, 4);
    std::cout << "The selectionSort: " << timer(SortAlg::selectionSort, vec) << " ms\n";
    std::cout << "The insertionSort: " << timer(SortAlg::insertionSort, vec) << " ms\n";
    std::cout << "The countingSort: " << timer(SortAlg::countingSort, vec) << " ms\n";
    std::cout << "The mergeSort: " << timer(SortAlg::mergeSort, vec, 0, vec.size()-1) << " ms\n";
    std::cout << "The quickSort: " << timer(SortAlg::quickSort, vec, 0, vec.size()-1) << " ms\n";
    std::cout << "The timSort: " << timer(SortAlg::timSort, vec) << " ms\n";
    std::cout<<index<<std::endl;

    for(auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}
