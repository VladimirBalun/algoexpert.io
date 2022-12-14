// O(log(N)) time / O(log(N)) space
int altered_binary_search(const std::vector<int>& array, int target, int left, int right, bool go_left)
{
  if (left > right)
    return -1;

  const int middle = (left + right) / 2;
  if (array[middle] < target) {
    return altered_binary_search(array, target, middle + 1, right, go_left);
  } else if (array[middle] > target) {
    return altered_binary_search(array, target, left, middle - 1, go_left);
  } else {
    if (go_left) {
      if (middle == 0 || array[middle - 1] != target)
        return middle;
      else
        return altered_binary_search(array, target, left, middle - 1, go_left);
    } else {
      if (middle == array.size() - 1 || array[middle + 1] != target)
        return middle;
      else
        return altered_binary_search(array, target, middle + 1, right, go_left);      
    }
  }
}

std::vector<int> searchForRange(const std::vector<int>& array, int target)
{
  return {
    altered_binary_search(array, target, 0, array.size() - 1, true),
    altered_binary_search(array, target, 0, array.size() - 1, false)
  };
}

// O(log(N)) time / O(1) space
int altered_binary_search(const std::vector<int>& array, int target, bool go_left)
{
  int left = 0;
  int right = array.size() - 1;
  
  while (left <= right) {
    const int middle = (left + right) / 2;
    if (array[middle] < target) {
      left = middle + 1;
    } else if (array[middle] > target) {
      right = middle - 1;
    } else {
      if (go_left) {
        if (middle == 0 || array[middle - 1] != target)
          return middle;
        else
          right = middle - 1;
      } else {
        if (middle == array.size() - 1 || array[middle + 1] != target)
          return middle;
        else
          left = middle + 1;     
      }
    }
  }

  return -1;
}

std::vector<int> searchForRange(const std::vector<int>& array, int target)
{
  return {
    altered_binary_search(array, target, true),
    altered_binary_search(array, target, false)
  };
}