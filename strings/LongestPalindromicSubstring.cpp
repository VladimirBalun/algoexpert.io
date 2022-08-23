std::pair<size_t, size_t> palindromePosition(const std::string& str, int left, int right)
{
  while (left >= 0 && right < str.size()) {
    if (str[left] != str[right])
      break;

    --left;
    ++right;
  }

  return { left + 1, right }; 
}

bool compare(const std::pair<size_t, size_t>& lhs, const std::pair<size_t, size_t>& rhs)
{
  return (lhs.second - lhs.first) < (rhs.second - rhs.first); 
}

// O(n^2) time / O(1) space
std::string longestPalindromicSubstring(std::string str) {
  std::pair<size_t, size_t> longest_position{ 0u, 1u };
  for (size_t i = 1u; i < str.size(); ++i) {
    const auto odd = palindromePosition(str, i - 1, i + 1);
    const auto even = palindromePosition(str, i - 1, i);
    const auto position = std::max(odd, even, compare);
    longest_position = std::max(position, longest_position, compare);
  }
  
  return std::string(
    begin(str) + longest_position.first,
    begin(str) + longest_position.second
  );
}
