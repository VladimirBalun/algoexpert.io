void siftDown(std::vector<int>& array, int begin, int end)
{
  int leftIdx = begin * 2 + 1;
  while (leftIdx <= end) {
    int idxToSwap = 0;
    int rightIdx = begin * 2 + 2;
    if (rightIdx <= end && array[rightIdx] > array[leftIdx])
      idxToSwap = rightIdx;
    else
      idxToSwap = leftIdx;

    if (array[idxToSwap] > array[begin]) {
      std::swap(array[idxToSwap], array[begin]);
      begin = idxToSwap;
      leftIdx = begin * 2 + 1;
    } else {
      break;
    }
  }
}

void buildMaxHeap(std::vector<int>& array)
{
  int firstParent = (array.size() - 2) / 2;
  for (int idx = firstParent; idx >= 0; --idx)
    siftDown(array, idx, array.size() - 1);
}

// O(n*log(n)) time / O(1) space
std::vector<int> heapSort(std::vector<int> array)
{
  buildMaxHeap(array);
  for (int i = array.size() - 1; i >= 1; --i) {
    std::swap(array[0], array[i]);
    siftDown(array, 0, i - 1);
  }

  return array;
}