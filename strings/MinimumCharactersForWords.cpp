// O(n*l) time / O(c) space
std::vector<char> minimumCharactersForWords(std::vector<std::string> words)
{
  std::unordered_map<char, size_t> max_frequency;
  for (const auto& word : words) {
    std::unordered_map<char, size_t> current_frequency;
    for (const char symbol : word) {
      ++current_frequency[symbol];
    }

    for (const auto& it : current_frequency) {
      max_frequency[it.first] = std::max(max_frequency[it.first], it.second);
    }
  }

  std::vector<char> result;
  for (const auto& it : max_frequency) {
    for (size_t i = 0u; i < it.second; ++i)
      result.push_back(it.first);
  }
  
  return result;
}