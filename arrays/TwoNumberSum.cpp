// O(n^2) time / O(1) space
std::vector<int> twoNumberSum(std::vector<int> array, int target_num)
{
  for (int i = 0; i < array.size(); ++i) {
    const int first_number = array[i];
    for (int j = i + 1; j < array.size(); ++j) {
      const int second_number = array[j];
      if (first_number + second_number == target_num)
        return { second_number, first_number };
    }
  }

  return {};
}

// O(n) time / O(n) space
std::vector<int> twoNumberSum(std::vector<int> array, int target)
{
  std::unordered_set<int> lookup;
  for (const int value: array) {
    const int diff = target - value;
    const auto& it = lookup.find(diff);
    if (it != end(lookup))
      return { value, diff };

    lookup.emplace(value);
  }
  
  return {};
}

// O(n*log(n)) time / O(1) space
std::vector<int> twoNumberSum(std::vector<int> array, int target_num)
{
  std::sort(begin(array), end(array));

  int left = 0;
  int right = array.size() - 1;
  while (left < right) {
    const int first_num = array[left];
    const int second_num = array[right];
    const int sum = first_num + second_num;
    
    if (sum > target_num)
      --right;
    else if (sum < target_num)
      ++left;
    else
      return { second_num, first_num };
  }
  
  return {};
}