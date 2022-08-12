// O(n) time / O(n) space
std::string runLengthEncoding(std::string str)
{
  std::string result;
  size_t counter = 1u;
  
  for (size_t i = 1u; i < str.length(); ++i) {
    const char current_letter = str[i];
    const char previous_letter = str[i - 1];
    if (current_letter != previous_letter || counter == 9) {
      result += std::to_string(counter) + previous_letter;
      counter = 0;
    }
    
    ++counter;
  }

  result += std::to_string(counter) + str.back();
  return result;
}