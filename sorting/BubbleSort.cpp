// O(n^2) time / O(1) space
std::vector<int> bubbleSort(std::vector<int> array)
{
  size_t counter = 0;
  bool is_sorted = false;
  while (!is_sorted) {
    is_sorted = true;
    for (size_t i = 0; i < array.size() - 1 - counter; ++i) {
      if (array[i] > array[i + 1]) {
        std::swap(array[i], array[i + 1]);
        is_sorted = false;
      }
    }

    ++counter;
  }
  
  return array;
}