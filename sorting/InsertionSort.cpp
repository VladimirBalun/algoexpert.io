// O(N^2) time / O(1) space
std::vector<int> insertionSort(std::vector<int> array)
{
  for (size_t i = 1; i < array.size(); i++)
    for (size_t j = i; j > 0 && array[j] < array[j - 1]; --j)
      std::swap(array[j], array[j - 1]);

  return array;
}
