// O(n*log(n)) time / O(n * log(n)) space
std::vector<int> mergeSort(std::vector<int> array)
{
  if (array.size() < 2)
    return array;
  
  const int middle = array.size() / 2;
  const auto left = mergeSort({ std::begin(array), std::begin(array) + middle });
  const auto right = mergeSort({ std::begin(array) + middle, std::end(array) });

  int l = 0;
  int r = 0;
  
  std::vector<int> result;
  result.reserve(left.size() + right.size());
  while (l < left.size() && r < right.size()) {
    if (left[l] <= right[r])
      result.push_back(left[l++]);
    else
      result.push_back(right[r++]);
  }

  while (l < left.size())
    result.push_back(left[l++]);

  while (r < right.size())
    result.push_back(right[r++]);
  
  return result;
}

void doMerge(std::vector<int>& main, std::vector<int>& auxiliary, int left, int right)
{
  if (right - left < 2)
    return;

  const int middle = (left + right) / 2;
  doMerge(auxiliary, main, left, middle);
  doMerge(auxiliary, main, middle, right);

  int l = left;
  int r = middle;
  int index = left;
  while (l < middle && r < right) {
    if (auxiliary[l] <= auxiliary[r])
      main[index++] = auxiliary[l++];
    else
      main[index++] = auxiliary[r++];
  }

  while (l < middle)
    main[index++] = auxiliary[l++];

  while (r < right)
    main[index++] = auxiliary[r++];
}

// O(n*log(n)) time / O(n) space
std::vector<int> mergeSort(std::vector<int> array)
{
  std::vector<int> auxiliary(array);
  doMerge(array, auxiliary, 0, array.size());
  return array;
}