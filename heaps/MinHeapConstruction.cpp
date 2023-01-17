class MinHeap
{
public:
  std::vector<int> heap;

  explicit MinHeap(std::vector<int> vector)
    : heap(buildHeap(vector)) {}

  // O(n) time / O(1) space
  std::vector<int> buildHeap(std::vector<int>& vector)
  {
    const int firstParentIdx = parentIndex(vector.size() - 1);
    for (int currentIdx = firstParentIdx; currentIdx >= 0; --currentIdx)
      siftDown(currentIdx, vector.size() - 1, vector);

    return vector;
  }

  // O(log(n)) time / O(1) space
  void siftDown(int currentIdx, int endIdx, std::vector<int>& heap)
  {
    int leftChildIdx = leftChildIndex(currentIdx);
    while (leftChildIdx <= endIdx) {
      int idxToSwap = 0;
      int rightChildIdx = rightChildIndex(currentIdx);
      if (rightChildIdx <= endIdx && heap[rightChildIdx] < heap[leftChildIdx])
        idxToSwap = rightChildIdx;
      else
        idxToSwap = leftChildIdx;

      if (heap[idxToSwap] < heap[currentIdx]) {
        std::swap(heap[idxToSwap], heap[currentIdx]);
        currentIdx = idxToSwap;
        leftChildIdx = leftChildIndex(currentIdx);
      } else {
        break;
      }
    }
  }

  // O(log(n)) time / O(1) space
  void siftUp(int currentIdx, std::vector<int>& heap)
  {
    int parentIdx = parentIndex(currentIdx);
    while (currentIdx > 0 && heap[currentIdx] < heap[parentIdx]) {
      std::swap(heap[currentIdx], heap[parentIdx]);
      currentIdx = parentIdx;
      parentIdx = parentIndex(currentIdx);
    }
  }

  // O(1) time / O(1) space
  int peek()
  {
    return heap.front();
  }

  // O(log(n)) time / O(1) space
  int remove()
  {
    int result = heap.front();
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    
    siftDown(0, heap.size() - 1, heap);
    return result;
  }

  // O(log(n)) time / O(1) space
  void insert(int value)
  {
    heap.push_back(value);
    siftUp(heap.size() - 1, heap);
  }

private:
  int leftChildIndex(int index)
  {
    return index * 2 + 1;
  }

  int rightChildIndex(int index)
  {
    return index * 2 + 2;
  }

  int parentIndex(int index)
  {
    return (index - 1) / 2;
  }
};