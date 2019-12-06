#include "sort_algorithms.h"

template <typename T>
T SortAlg::linearSearch(std::vector<T> &vec, T a) {
	for (std::size_t i = 0; i < vec.size(); i++) {
		if (a == vec[i]) {
			return i;
		}
	}
	return -1;
}


template <typename T>
void SortAlg::selectionSort(std::vector<T> &vec) {
	for (std::size_t i = 0; i < vec.size() - 1; i++)	{
		int min = i;
		for (std::size_t j = i; j < vec.size(); j++)	{
			if (vec[j] < vec[min]) {
				min = j;
			}
		}
		if (min != i) {
			T temp = vec[i];
			vec[i] = vec[min];
			vec[min] = temp;
		}
	}
}


template <typename T>
void SortAlg::insertionSort(std::vector<T> &vec) {
	for (std::size_t i = 1; i < vec.size(); i++) {
		T temp = vec[i];
		int j = i;
		while ((j > 0) and (vec[j - 1] > temp))	{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = temp;
	}
}


template <typename T>
void SortAlg::countingSort(std::vector<T> &vec) {
	std::vector<T> count(1000);
	for (std::size_t i = 1; i < vec.size(); i++) {
		count.push_back(0);
	}
	for (std::size_t i = 0; i < vec.size(); i++) {
		count[vec[i]]++;
	}
	for (std::size_t i = 0, j = 0; i < vec.size(); i++)	{
		for (; count[i] != 0; j++) {
			vec[j] = i;
			count[i]--;
		}
	}
} 
