// O(n*log(n)) time / O(log(n)) space
std::vector<int> quickSort(std::vector<int> array)
{
  std::function<void(int, int)> impl;
  impl = [&impl, &array] (int start_index, int end_index)
  {
    int left = start_index;
    int right = end_index;
    int pivot = array[(left + right) / 2];
    while (left <= right) {
      while (array[left] < pivot)
        ++left;
      while (array[right] > pivot)
        --right;

      if (left <= right)
        std::swap(array[left++], array[right--]);
    }

    if (right > start_index)
      impl(start_index, right);
    if (left < end_index)
      impl(left, end_index);
  };
  
  impl(0, array.size() - 1);
  return array;
}
