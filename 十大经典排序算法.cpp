/*
°æ Æ¥Ûæ≠µ‰≈≈–ÚÀ„∑®°ø
python µœ÷∫Õ∂ØÕº—› æ–ßπ˚£∫
https://mp.weixin.qq.com/s/QaflNoxiI_FS4Ij8jg1KrQ
*/

#include <iostream>
#include <vector>
#include <algorithm>

/*√∞≈›≈≈–Ú*/
void bubbleSort(int* arr, int len) {
	for (int i = 1; i < len; i ++) {
		for (int j = 0; j < len - 1; j ++) {
			if (arr[j] > arr[i]) {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

/*—°‘Ò≈≈–Ú*/
void selectionSort(int* arr, int len) {
	for (int i = 0; i < len - 1; i ++) {
		for (int j = i + 1; j < len; j ++) {
			if (arr[j] < arr[i]) {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

/*≤Â»Î≈≈–Ú*/
void insertionSort(int* arr, int len) {
	for (int i = 0; i < len; i ++) {
		int current = arr[i];
		int index = i - 1;
		while (index >= 0 && arr[index] > current) {
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = current;
	}
}

/*œ£∂˚≈≈–Ú*/
void shellSort(int*arr, int len) {
	int gap = 4;

	while (gap > 0) {
		for (int i = gap; i < len; i ++) {
			int tmp = arr[i];
			int j = i - gap;
			while (j >= 0 && arr[j] > tmp) {
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = tmp;
		}
		gap = gap / 2;
	}
}

/*πÈ≤¢≈≈–Ú*/
void merge(int* arr, int left, int middle, int right) {
	int* tmp = new int[right - left + 1];
	int i = 0;
	int p1 = left;
	int p2 = middle + 1;
	while (p1 <= middle && p2 <= right) {
		tmp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= middle) {
		tmp[i++] = arr[p1++];
	}
	while (p2 <= right) {
		tmp[i++] = arr[p2++];
	}
	for (int i = 0; i < (right - left + 1); i ++) {
		arr[left + i] = tmp[i];
	}
	delete[] tmp;
}

void mergeSort(int* arr, int left, int right) {
	if (left == right) {
		return;
	}
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void mergeSort(int* arr, int len) {
	if (len < 2)return;
	mergeSort(arr, 0, len - 1);
}

/*øÏÀŸ≈≈–Ú*/
void quickSort(int* arr, int left, int right) {
	if (left < right) {
		int tmp = arr[left];
		int i = left;
		int j = right;
		while (i < j) {
			while (i < j && arr[j] > tmp) {
				j--;
			}
			arr[i] = arr[j];
			while (i < j && arr[i] <= tmp) {
				i++;
			}
			arr[j] = arr[i];
		}
		arr[i] = tmp;
		quickSort(arr, left, i - 1);
		quickSort(arr, i + 1, right);
	}
}

void quickSort(int* arr, int len) {
	quickSort(arr, 0, len - 1);
}

/*∂—≈≈–Ú*/
void heapSwap(int* arr, int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void adjustHeap(int* arr, int i, int len) {
	int tmp = arr[i];
	for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {
		if (k + 1 < len && arr[k] < arr[k + 1]) {
			k++;
		}
		if (arr[k] > tmp) {
			arr[i] = arr[k];
			i = k;
		}
		else {
			break;
		}
	}
	arr[i] = tmp;
}

void heapSort(int* arr, int len) {
	for (int i = len / 2 - 1; i >= 0; i --) {
		adjustHeap(arr, i, len);
	}
	for (int i = len - 1; i > 0; i --) {
		heapSwap(arr, 0, i);
		adjustHeap(arr, 0, i);
	}
}

/*º∆ ˝≈≈–Ú*/
void countSort(int* arr, int len) {
	int max = INT_MIN;
	for (int i = 0; i < len; i ++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	int* count = new int[max + 1];
	memset(count, 0, sizeof(int) * (max + 1));
	for (int i = 0; i < len; i++) {
		count[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i < (max + 1); i ++) {
		while (count[i]> 0) {
			arr[index++] = i;
			count[i]--;
		}
	}
}

/*Õ∞≈≈–Ú*/
bool compare(int a, int b) {
	return a <= b;
}

void bucketSort(int* arr, int len) {
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < len; i ++) {
		if (min > arr[i]) {
			min = arr[i];
		}
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	float size = (max - min) /1.0 / len;
	std::vector<std::vector<int> > count_list(len + 1);
	for (int i = 0; i < len; i ++) {
		count_list[(arr[i] - min)/size].push_back(arr[i]);
	}
	int index = 0;
	for (int i = 0; i < count_list.size(); i ++) {
		std::sort(count_list[i].begin(), count_list[i].end());
		for (int j = 0; j < count_list[i].size(); j ++) {
			arr[index++] = count_list[i][j];
		}
	}
}

/*ª˘ ˝≈≈–Ú*/
int maxbit(int* data, int n) {
	int d = 1;
	for (int i = 0; i < n; i ++) {
		int c = 1;
		int p = data[i];
		while (p / 10) {
			p /= 10;
			c++;
		}
		if (c > d) {
			d = c;
		}
	}
	return d;
}

void radixSort(int*arr, int len) {
	int d = maxbit(arr, len);
	int r = 1;
	int count[10] = {0};
	int tmp[10] = {0};

	for (int i = 0; i < d; i ++) {
		for (int j = 0; j < 10; j++) {
			count[j] = 0;
		}
		for (int j = 0; j < len; j ++) {
			int k = arr[j] / r;
			int q = k % 10;
			count[q]++;
		}
		for (int j = 1; j < 10; j ++) {
			count[j] += count[j - 1];
		}
		for (int j = len - 1; j >= 0; j --) {
			int p = arr[j] / r;
			int s = p % 10;
			tmp[count[s] - 1] = arr[j];
			count[s]--;
		}
		for (int j = 0; j < len; j ++) {
			arr[j] = tmp[j];
		}
		r *= 10;
	}
}

int main() {

	int arr[12] = {5, 6, 9, 7, 8, 7, 9, 2, 4, 0, 3, 1};

	//bubbleSort(arr, 12);
	//selectionSort(arr, 12);
	//insertionSort(arr, 12);
	//shellSort(arr, 12);
	//mergeSort(arr, 12);
	//quickSort(arr, 12);
	//heapSort(arr, 12);
	//countSort(arr, 12);
	//bucketSort(arr, 12);
	radixSort(arr, 12);

	for (int i = 0; i < 12; i ++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}