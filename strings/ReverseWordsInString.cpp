bool is_not_equal_parts(char lhs, char rhs)
{
  return std::isspace(lhs) ^ std::isspace(rhs);
}

std::vector<std::string> split(const std::string& str)
{
  size_t part_begin = 0u;
  size_t part_finish = 1u;
  std::vector<std::string> result;
  while (part_finish < str.size()) {
    if (is_not_equal_parts(str[part_begin], str[part_finish])) {
      result.emplace_back(begin(str) + part_begin, begin(str) + part_finish);
      part_begin = part_finish++;
    } else {
      ++part_finish;
    }  
  }

  result.emplace_back(begin(str) + part_begin, begin(str) + part_finish);
  return result;
}

void reverse_string(std::string& str, size_t left, size_t right)
{
  std::cout << std::string(begin(str) + left, begin(str) + right) << std::endl;
  while (left < right) {
    std::swap(str[left], str[right]);
    ++left;
    --right;
  }
}

// O(n) time / O(n) space
std::string reverseWordsInString(std::string str)
{
  if (str.empty())
    return "";
  
  std::string result;
  const auto parts = split(str);
  for (auto it = rbegin(parts); it != rend(parts); ++it)
    result += *it;
  
  return result;
}

// O(n) time / O(1) space
std::string reverseWordsInString(std::string str)
{
  if (str.empty())
    return "";

  reverse_string(str, 0u, str.size() - 1u);

  size_t word_begin = 0u;
  size_t word_finish = 1u;
  while (word_finish < str.size()) {
    if (std::isspace(str[word_finish])) {
      reverse_string(str, word_begin, word_finish - 1u);
      while (std::isspace(str[word_finish])) 
        ++word_finish;

      word_begin = word_finish;
    } else {
      ++word_finish;
    }    
  }

  reverse_string(str, word_begin, word_finish - 1u);
  return str;
}