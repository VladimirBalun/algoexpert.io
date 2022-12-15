// O(N^2) time / O(1) space
std::vector<int> selectionSort(std::vector<int> array)
{
  for (size_t i = 0; i < array.size() - 1; ++i) {
    size_t min_index = i;
    for (size_t j = i + 1; j < array.size(); ++j) {
      if (array[j] < array[min_index])
        min_index = j;
    }

    std::swap(array[i], array[min_index]);
  }
  return array;
}
