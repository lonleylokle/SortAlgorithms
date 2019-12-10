#include <iostream>
#include <vector>
#include "sort_algorithms.h"

int main() {
    std::vector<int> vec = {3,2,4,3,1};
    for(auto i : vec)
        std::cout << i << " ";
    std::cout<<std::endl;

    int index = SortAlg::linearSearch(vec, 4);
    SortAlg::selectionSort(vec);
    SortAlg::insertionSort(vec);
    SortAlg::countingSort(vec);
    SortAlg::mergeSort(vec, 0, vec.size()-1);
    SortAlg::quickSort(vec, 0, vec.size()-1);

    for(auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}
 
