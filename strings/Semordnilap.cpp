// O(n * m) time / O(n * m) space
std::vector<std::vector<std::string>> semordnilap(std::vector<string> words)
{
  std::unordered_set<std::string> lookup;
  std::vector<std::vector<std::string>> result;
  
  for (auto& word: words) {
    std::string reversed_word = word;
    std::reverse(begin(reversed_word), end(reversed_word));

    auto it = lookup.find(reversed_word);
    if (it != end(lookup))
      result.push_back({ word, reversed_word });
    else
      lookup.insert(word);
  }
  
  return result;
}
