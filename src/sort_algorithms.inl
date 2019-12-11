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


template <typename T>
void SortAlg::timSort(std::vector<T>& vec1) {
	int minrun = GetMinrun(vec1.size());
	int curIdx = 0;
	std::vector <SortAlg::Range> minrunStack;
	//divide
	while (curIdx < vec1.size() - 1) {
		int curRunIdx = curIdx;
		int nextIdx = curRunIdx + 1;
		if (vec1[curRunIdx] > vec1[nextIdx]) {
			std::swap(vec1[curRunIdx], vec1[nextIdx]);
		}

		bool next = true;
		while (next) {
			if (vec1[curRunIdx] > vec1[nextIdx]) {
				next = false;
			}
			if (!(next) && (curRunIdx - curIdx) < minrun) {
				next = true;
			}
			if (curRunIdx == vec1.size() - 1) {
				next = false;
			}
			if (next) {
				++curRunIdx;
				++nextIdx;
			}
		}
		insertionSortVec(vec1, curIdx, curRunIdx+1);
		SortAlg::Range r;
		r.start = curIdx;
		r.length = curRunIdx - curIdx;

		minrunStack.push_back(r);
		curIdx = curRunIdx;
	}

	//merge
	while (minrunStack.size() > 1) {
		Range x = minrunStack.at(0);
		minrunStack.erase(minrunStack.begin());
		Range y = minrunStack.at(0);
		minrunStack.erase(minrunStack.begin());
		if (x.start > y.start) {
			std::swap(x.start, y.start);
			std::swap(x.length, y.length);
		}
		if (y.start != x.start + x.length) {
			minrunStack.push_back(y);
			minrunStack.push_back(x);
			continue;
		}
		mergeVec(vec1, x.start, x.length, y.start, y.length);
		x.length = x.length + y.length;
		minrunStack.push_back(x);
	}
}


template <typename T>
void SortAlg::mergeVec(std::vector<T>& vec1, std::size_t fStart, std::size_t fLength, std::size_t sStart, std::size_t sLength){
	std::vector<int> vec2(fLength);
	for (std::size_t j = 0; j < fLength; j++) {
		vec2[j] = vec1[j];
	}
	std::size_t fIndex = 0;
	std::size_t sIndex = sStart;
	std::size_t i = fStart;

	while (i < sStart+sLength-1) {
		if (vec1[sIndex] > vec2[fIndex]) {
			vec1[i] = vec2[fIndex];
			++fIndex;
			fIndex = std::min(fIndex, fLength);
		}
		else if (vec1[sIndex] <= vec2[fIndex]) {
			vec1[i] = vec1[sIndex];
			++sIndex;
			sIndex = std::min(sIndex, sStart + sLength);
		}
		if (sIndex == sStart + sLength) {
			if (fIndex != sLength) {
				for (std::size_t j = 0; j < fLength - fIndex; j++) {
					vec1[i+1+j] = vec2[fIndex+j];
				}
				i = sStart + sLength;
			}
		}
		if (fIndex == fLength) {
			i = sStart + sLength;
		}
		++i;
	}
}


template <typename T>
void SortAlg::insertionSortVec(std::vector<T>& vec1, std::size_t start, std::size_t end) {
	for (std::size_t i = start + 1; i < end; ++i) {
		T current = vec1[i];
		std::size_t j = i - 1;
		while ((j >= start) && (current < vec1[j]))
		{
			std::swap(vec1[j], vec1[j + 1]);
			--j;
		}
	}
}


int SortAlg::GetMinrun(int n) {
	int r = 0;
	while (n >= 64) {
		r |= n & 1;
		n >>= 1;
	}
	return n + r;
}
