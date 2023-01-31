// O(n) time / O(1) space
int indexEqualsValue(const std::vector<int>& array)
{
  for (int i = 0; i < array.size(); ++i)
    if (array[i] == i)
      return i;

  return -1;
}

int indexEqualsValueImpl(const std::vector<int>& array, int left, int right)
{
  if (left > right)
    return -1;
  
  int middle = (left + right) / 2;
  if (array[middle] < middle)
    return indexEqualsValueImpl(array, middle + 1, right);
  else if (array[middle] == middle && middle == 0)
    return middle;
  else if (array[middle] == middle && array[middle - 1] < middle - 1)
    return middle;
  else
    return indexEqualsValueImpl(array, left, middle - 1);
  
  return -1;  
}

// O(log(n)) time / O(log(n)) space
int indexEqualsValue(const std::vector<int>& array)
{
  return indexEqualsValueImpl(array, 0, array.size() - 1);
}

// O(log(n)) time / O(1) space
int indexEqualsValue(const std::vector<int>& array)
{
  int left = 0;
  int right = array.size() - 1;
  while (left <= right) {
    int middle = (left + right) / 2;
    if (array[middle] < middle)
      left = middle + 1;
    else if (array[middle] == middle && middle == 0)
      return middle;
    else if (array[middle] == middle && array[middle - 1] < middle - 1)
      return middle;
    else
      right = middle - 1;
  }
  
  return -1;
}