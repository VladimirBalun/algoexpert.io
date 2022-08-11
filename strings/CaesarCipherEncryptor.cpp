size_t index_of(const std::array<char, 26u>& alphabet, char letter)
{
  for (size_t i = 0u; i < alphabet.max_size(); ++i) {
    if (alphabet[i] == letter)
      return i;
  }

  throw std::invalid_argument("error");
}

// O(n) time / O(1) space
std::string caesarCypherEncryptor(std::string str, int key)
{
  if (key == 0)
    return str;

  key %= 26;
  for (size_t i = 0u; i < str.size(); ++i) {
    const size_t number = (str[i] - 'a' + key) % 26;
    str[i] = 'a' + number;
  }
  
  return str;
}

// O(n) time / O(1) space
std::string caesarCypherEncryptor(std::string str, int key)
{
  if (key == 0)
    return str;

  key %= 26;
  std::array<char, 26u> alphabet{
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
  };
  
  for (size_t i = 0u; i < str.size(); ++i) {
    const size_t index = index_of(alphabet, str[i]);
    str[i] = alphabet[(index + key) % 26];
  }
  
  return str;
}
