// O(w * n * log(n) + n * w * log(w)) time / O(wn) space
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> words)
{
  if (words.empty())
    return {};
  
  std::vector<std::string> sorted_words(words.size());
  for (size_t i = 0u; i < words.size(); ++i) {
    std::string sorted_word = words[i];
    std::sort(begin(sorted_word), end(sorted_word));
    sorted_words[i] = std::move(sorted_word);
  }

  std::vector<size_t> indices(words.size());
  for (size_t i = 0u; i < words.size(); ++i) {
    indices[i] = i;
  }

  std::sort(begin(indices), end(indices), [&sorted_words] (size_t lhs, size_t rhs)
  {
    return sorted_words[lhs] > sorted_words[rhs];
  });


  std::vector<std::vector<std::string>> result;
  std::vector<std::string> current_anagram_group;
  std::string current_anagram = sorted_words[indices.front()];
  for (const size_t index: indices) {
    const std::string& word = words[index];
    const std::string& sorted_word = sorted_words[index];
    
    if (sorted_word == current_anagram) {
      current_anagram_group.push_back(word);
      continue;
    }

    result.push_back(current_anagram_group);
    current_anagram_group = { word };
    current_anagram = sorted_word;
  }

  result.push_back(current_anagram_group);
  return result;
}

// O(w * n * log(n)) time / O(wn) space
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> words)
{
  std::unordered_map<std::string, std::vector<std::string>> lookup;
  for (const std::string& word: words) {
    std::string sorted_word = word;
    std::sort(begin(sorted_word), end(sorted_word));
    lookup[sorted_word].push_back(word);
  }

  std::vector<std::vector<std::string>> result;
  for (auto& iterator: lookup) {
    result.push_back(std::move(iterator.second));
  }

  return result;
}