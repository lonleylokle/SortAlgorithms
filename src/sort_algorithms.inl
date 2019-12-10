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


template <typename T>
void SortAlg::mergeSort(std::vector<T> &vec, std::size_t first, std::size_t last) {
	if (first == last) {
		return;
	}
	std::size_t mid = (last + first) / 2;
	mergeSort(vec, first, mid);
	mergeSort(vec, mid+1, last);

	std::vector<T> rezult(10);
	std::size_t k = mid+1, j = first;
	for(std::size_t i = 0; i < last - first + 1; i++) {
		if ((k > last) || ((j <= mid) && (vec[j] < vec[k]))) {
			rezult[i] = vec[j];
			j++;
		}else {
			rezult[i] = vec[k];
			k++;
		}
	}
	for (std::size_t i = 0; i < last - first + 1; i++) {
		vec[first + i] = rezult[i];
	}
}


template <typename T>
void SortAlg::quickSort(std::vector<T>& vec1, std::size_t l, std::size_t r) {
	if (l >= r) return;
	T pivot = vec1[r];
	std::size_t i = l;
	for (std::size_t j = l; j < r; j++)	{
		if (vec1[j] <= pivot) {
			T temp = vec1[i];
			vec1[i] = vec1[j];
			vec1[j] = temp;
			i++;
		}
	}
	T temp = vec1[i];
	vec1[i] = vec1[r];
	vec1[r] = temp;

	quickSort(vec1, l, i-1);
	quickSort(vec1, i+1, r);
}
