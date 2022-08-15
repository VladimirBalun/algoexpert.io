// O(n) time / O(1) space
int firstNonRepeatingCharacter(std::string string)
{
  if (string.length() < 2u)
    return (int)string.length() - 1;
  
  for (size_t i = 0u; i < string.length(); ++i) {
    bool found_repeating_symbol = false;
    for (size_t j = 0u; j < string.length(); ++j) {
      if (string[j] == string[i] && i != j) {
        found_repeating_symbol = true;
        break;
      }
    }

    if (!found_repeating_symbol)
      return i;
  }

  return -1;
}

// O(n) time / O(1) space
int firstNonRepeatingCharacter(std::string string)
{
  constexpr size_t ALPHABET_SIZE = 26u;
  std::array<size_t, ALPHABET_SIZE> encountered_symbols({ 0u });
  for (const char symbol: string) {
    ++encountered_symbols[symbol - 'a'];
  }

  for (size_t i = 0u; i < string.size(); ++i) {
    if (encountered_symbols[string[i] - 'a'] == 1u)
      return i;
  }

  return -1;
}