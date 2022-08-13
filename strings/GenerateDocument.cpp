size_t count_symbol_frequency(char symbol, const std::string& text)
{
    return std::count(begin(text), end(text), symbol);
}

// O(n * (n + m)) time / O(1) space
bool generateDocument(string characters, string document) {
  for (const char symbol: document) {
    const size_t document_frequency = count_symbol_frequency(symbol, document);
    const size_t characters_frequency = count_symbol_frequency(symbol, characters);
    if (document_frequency > characters_frequency)
      return false;
  }
  
  return true;
}

// O(c + (n + m)) time / O(c) space
bool generateDocument(string characters, string document) {
  std::unordered_set<char> already_counted;
  for (const char symbol: document) {
    if (already_counted.count(symbol) != 0)
      continue;

    const size_t document_frequency = count_symbol_frequency(symbol, document);
    const size_t characters_frequency = count_symbol_frequency(symbol, characters);
    if (document_frequency > characters_frequency)
      return false;

    already_counted.insert(symbol);
  }
  
  return true;
}

// O(n + m) time / O(c) space
bool generateDocument(std::string characters, std::string document)
{
  std::unordered_map<char, size_t> characteres_lookup;
  for (const char character: characters) {
    ++characteres_lookup[character];
  }

  for (const char symbol: document) {
    const auto it = characteres_lookup.find(symbol);
    if (it == end(characteres_lookup) || it->second == 0)
      return false;

    --it->second;
  }

  return true;
}