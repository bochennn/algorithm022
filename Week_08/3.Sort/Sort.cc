#include <gtest/gtest.h>
using namespace std;


// 1.选择排序
void selectionSort(vector<int>& array) {
  int min_indx;
  for (int i = 0; i < array.size() - 1; i++) {
    min_indx = i;
    // 找最小值, 放到左边队列
    for (int j = i + 1; j < array.size(); j++) {
      if (array[j] < array[min_indx]) {
        min_indx = j;
      }
    }
    swap(array[i], array[min_indx]);
  }
}

// 2.插入排序
void insertSort(vector<int>& array) {
  int pre_idx = 0, cur_num;

  for (int i = 0; i < array.size(); i++) {
    pre_idx = i - 1;
    cur_num = array[i];
    while (pre_idx >= 0 && array[pre_idx] > cur_num) {
      array[pre_idx + 1] = array[pre_idx]; // 比cur大的要右移
      pre_idx--;
    }
    array[pre_idx] = cur_num;
  }
}

// 3.冒泡排序
void bubbleSort(vector<int>& array) {
  for (int i = 0; i < array.size() - 1; i++) {
    for (int j = 0; j < array.size() - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
      }
    }
  }
}

// 4.希尔排序
void shellSort(vector<int>& array) {
  for(int gap = array.size() >> 1; gap > 0; gap >>= 1) {
    // 注意：这里和动图演示的不一样，动图是分组执行，实际操作是多个分组交替执行
    for(int i = gap; i < array.size(); i++) {
      int j = i;
      int current = array[i];
      while(j - gap >= 0 && current < array[j - gap]) {
        array[j] = array[j - gap];
        j = j - gap;
      }
      array[j] = current;
    }
  }
}

// 5.归并排序
void merge(vector<int>& array, int left, int mid, int right) {
  vector<int> tmp(right - left + 1);
  int i = left, j = mid + 1, k = 0;
  
  while (i <= mid && j <= right) {
    tmp[k++] = array[i] < array[j] ? array[i++] : array[j++];
  }
  while (i <= mid) {
    tmp[k++] = array[i++];
  }
  while (j <= right) {
    tmp[k++] = array[j++];
  }
  for (i = left, k = 0; i <= right;) {
    array[i++] = tmp[k++];
  }
}

void mergeSort(vector<int>& array, int left, int right) {
  if (left >= right) {
    return;
  }
  
  int mid = left + (right - left) >> 2;
  mergeSort(array, left, mid);
  mergeSort(array, mid + 1, right);
  merge(array, left, mid, right);
}

// 6.快排
int randomPartition(vector<int>& array, int l, int r) {
  int random_pivot = rand() % (r - l + 1) + l;  //随机选择pivot
  int pivot = array[random_pivot];
  swap(array[random_pivot], array[r]);
  int i = l - 1;
  for (int j = l; j < r; j++) {
    if (array[j] < pivot) {
      swap(array[++i], array[j]);
    }
  }
  int pivot_index = i + 1;
  swap(array[pivot_index], array[r]);
  return pivot_index;
}
void randomQuickSort(vector<int>& array, int l, int r) {
  if (l < r) {
    int pivot_index = randomPartition(array, l, r);
    randomQuickSort(array, l, pivot_index - 1);
    randomQuickSort(array, pivot_index + 1, r);
  }
}

//7. 堆排序
void heapify(vector<int> &array, int length, int i) {
  int left = i << 1 + 1, right = i << 1 + 2;
  int largest = i;
  
  if (left < length && array[left] > array[largest]) {
    largest = left;
  }
  if (right < length && array[right] > array[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(array[i], array[largest]);
    heapify(array, length, largest);
  }
  return;
}
void heapSort(vector<int> &array) {
  if (array.size() == 0) {
    return;
  }
  int length = array.size();
  for (int i = length >> 1 - 1; i >= 0; i--)
    heapify(array, length, i);
  
  for (int i = length - 1; i >= 0; i--) {
    swap(array[i], array[0]);
    heapify(array, i, 0);
  }
  return;
}

// 8.计数排序
// 9.桶排序
// 10.基数排序

