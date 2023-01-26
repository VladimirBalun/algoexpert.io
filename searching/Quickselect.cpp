int quickselectImpl(std::vector<int> array, int l, int r, int k)
{
  int left = l;
  int right = r;
  int pivotIdx = left++;
  int pivot = array[pivotIdx];
  
  while (left <= right) {
    while (left <= right && array[left] <= pivot)
      ++left;
    while (left <= right && array[right] > pivot)
      --right;

    if (left <= right)
      std::swap(array[left], array[right]);
  }

  std::swap(array[pivotIdx], array[right]);
  
  if (right > k)
    return quickselectImpl(array, l, right - 1, k);
  else if (right < k)
    return quickselectImpl(array, right + 1, r, k);
  else
    return array[right];
}

// O(n) time / O(1) space
int quickselect(std::vector<int> array, int k)
{
  return quickselectImpl(array, 0, array.size() - 1, k - 1);
}