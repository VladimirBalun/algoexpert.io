void countingSort(std::vector<int>& array, int digit)
{
  std::array<int, 10> count_array{ 0 };
  std::vector<int> sorted_array(array.size());

  const auto digit_column = std::pow(10, digit);
  for (auto value: array) {
    const auto count_index = int(value / digit_column) % 10;
    ++count_array[count_index];
  }

  for (size_t i = 1; i < 10; ++i)
    count_array[i] += count_array[i - 1];

  for (int i = array.size() - 1; i >= 0; --i) {
    const auto count_index = int(array[i] / digit_column) % 10;
    --count_array[count_index];
    
    const auto sorted_index = count_array[count_index];
    sorted_array[sorted_index] = array[i];
  }

  array = std::move(sorted_array);
}

// O(d * (n + b)) time / O(n + b) space
std::vector<int> radixSort(std::vector<int> array)
{
  if (array.empty())
    return array;

  int digit = 0;
  const auto max_number = *std::max_element(begin(array), end(array));
  while (max_number / std::pow(10, digit) > 0) {
    countingSort(array, digit);
    ++digit;
  }
  
  return array;
}