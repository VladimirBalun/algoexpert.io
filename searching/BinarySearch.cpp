// O(log(N)) time / O(log(n)) space
int binarySearch(vector<int> array, int target)
{
  std::function<int(int, int)> impl;
  impl = [&impl, &array, target] (int left, int right)
  {
    if (left > right)
      return -1;

    const auto middle = (left + right) / 2;
    if (array[middle] > target) {
      return impl(left, middle - 1);
    } else if (array[middle] < target) {
      return impl(middle + 1, right);
    } else {
      return middle;
    }
  };
  
  return impl(0, array.size() - 1);
}

// O(log(N)) time / O(1) space
int binarySearch(std::vector<int> array, int target)
{
  int left = 0;
  int right = array.size() - 1;
  while (left <= right) {
    const auto middle = (left + right) / 2;
    if (array[middle] > target) {
      right = middle - 1;
    } else if (array[middle] < target) {
      left = middle + 1;
    } else {
      return middle;
    }
  }
  
  return -1;
}