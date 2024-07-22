// O(n*log(n)) time / O(n) space
std::vector<int> sortedSquaredArray(std::vector<int> array)
{
  std::vector<int> sorted_array(array.size());
  for (int i = 0; i < array.size(); ++i)
    sorted_array[i] = array[i] * array[i];

  std::sort(begin(sorted_array), end(sorted_array));
  return sorted_array;
}

// O(n) time / O(n) space
std::vector<int> sortedSquaredArray(std::vector<int> array)
{
  int smaller_value_idx = 0;
  int larger_value_idx = array.size() - 1;

  std::vector<int> sorted_array(array.size());  
  for (int idx = array.size() - 1; idx >= 0; --idx) {
    const int smaller_value = array[smaller_value_idx];
    const int larger_value = array[larger_value_idx];
    if (std::abs(smaller_value) > std::abs(larger_value)) {
      sorted_array[idx] = smaller_value * smaller_value;
      ++smaller_value_idx;
    } else {
      sorted_array[idx] = larger_value * larger_value;
      --larger_value_idx;    
    }
  }

  return sorted_array;
}