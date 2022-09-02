// O(n) time / O(c) space
std::string longestSubstringWithoutDuplication(std::string str)
{
  size_t left = 0u, right = 0u;
  size_t max_left = 0u, max_right = 0u;
  std::unordered_map<char, size_t> frequency;
  while (right < str.size()) {
    if (frequency.count(str[right]) != 0)
      left = std::max(left, frequency[str[right]] + 1);

    frequency[str[right]] = right;
    ++right;
    
    if (right - left > max_right - max_left) {
      max_right = right;
      max_left = left;
    }
  }

  return std::string(begin(str) + max_left, begin(str) + max_right);
}