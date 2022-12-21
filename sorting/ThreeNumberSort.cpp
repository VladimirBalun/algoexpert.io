// O(n) time / O(1) space
std::vector<int> threeNumberSort(std::vector<int> array, std::vector<int> order)
{
  std::array<int, 3> counts{ 0 };
  for (auto value : array) {
    for (size_t i = 0; i < order.size(); ++i) {
      if (order[i] == value) {
        ++counts[i];
        break;
      }
    }
  }

  size_t index = 0;
  for (size_t i = 0; i < order.size(); ++i) {
    const auto value = order[i];
    const auto count = counts[i];
    for (int j = 0; j < count; ++j) {
      array[index++] = value;
    } 
  }
  
  return array;
}

// O(n) time / O(1) space
std::vector<int> threeNumberSort(std::vector<int> array, std::vector<int> order)
{
  const auto first_value = order[0];
  const auto third_value = order[2];

  int first_index = 0;
  for (int i = 0; i < array.size(); ++i)
    if (array[i] == first_value)
      std::swap(array[i], array[first_index++]);

  int third_index = array.size() - 1;
  for (int i = array.size() - 1; i >= 0; --i)
    if (array[i] == third_value)
      std::swap(array[i], array[third_index--]);
  
  return array;
}

// O(n) time / O(1) space
std::vector<int> threeNumberSort(std::vector<int> array, std::vector<int> order)
{
  const auto first_value = order[0];
  const auto third_value = order[2];
  
  int first_index = 0;
  int second_index = 0;
  int third_index = array.size() - 1;
  
  while (second_index <= third_index) {
    if (array[second_index] == first_value) {
      std::swap(array[second_index++], array[first_index++]);
    } else if (array[second_index] == third_value) {
      std::swap(array[second_index], array[third_index--]);
    } else {
      ++second_index;
    }    
  }
  
  return array;
}