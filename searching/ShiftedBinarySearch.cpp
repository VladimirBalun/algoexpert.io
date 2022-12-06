// O(log(n)) time / O(log(n)) space
int shiftedBinarySearch(std::vector<int> array, int target)
{
  std::function<int(int, int)> impl;
  impl = [&impl, &array, target](int left, int right)
  {
    if (left > right)
      return -1;
    
    const int middle = (left + right) / 2;
    if (target == array[middle]) {
      return middle;
    } else if (array[left] <= array[middle]) {
      if (target >= array[left] && target < array[middle])
        return impl(left, middle - 1);
      else
        return impl(middle + 1, right);
    } else {
      if (target > array[middle] && target <= array[right])
        return impl(middle + 1, right);
      else
        return impl(left, middle - 1);
    }
  };

  return impl(0, array.size() - 1);
}

// O(log(n)) time / O(1) space
int shiftedBinarySearch(std::vector<int> array, int target)
{
  int left = 0;
  int right = array.size() - 1;
  
  while (left <= right) {
    const int middle = (left + right) / 2;
    if (target == array[middle]) {
      return middle;
    } else if (array[left] <= array[middle]) {
      if (target < array[middle] && target >= array[left])
        right = middle - 1;
      else
        left = middle + 1;
    } else {
      if (target > array[middle] && target <= array[right])
        left = middle + 1;
      else
        right = middle - 1;
    }
  }
  
  return -1;
}