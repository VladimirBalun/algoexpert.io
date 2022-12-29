// O(n + m) time / O(n + m) space
bool oneEdit(std::string string_one, std::string string_two)
{
  const int length_one = string_one.size();
  const int length_two = string_two.size();
  if (abs(length_one - length_two) > 1)
    return false;

  for (int i = 0u; i < std::min(length_one, length_two); ++i) {
    if (string_one[i] != string_two[i]) {
      if (length_one > length_two) {
        return std::string(begin(string_one) + i + 1, end(string_one)) == 
          std::string(begin(string_two) + i, end(string_two));
      } else if (length_one < length_two) {
        return std::string(begin(string_one) + i, end(string_one)) == 
          std::string(begin(string_two) + i + 1, end(string_two));
      } else {
         return std::string(begin(string_one) + i + 1, end(string_one)) == 
          std::string(begin(string_two) + i + 1, end(string_two));       
      }
    }
  }

  return true;
}

// O(n) time / O(1) space
bool oneEdit(string string_one, string string_two)
{
  const int length_one = string_one.size();
  const int length_two = string_two.size();
  if (abs(length_one - length_two) > 1)
    return false;

  int index_one = 0;
  int index_two = 0;
  bool was_edit = false;
  while (index_one < length_one && index_two < length_two) {
    if (string_one[index_one] != string_two[index_two]) {
      if (was_edit)
        return false;

      was_edit = true;
      if (length_one > length_two) {
        ++index_one;
      } else if (length_one < length_two) {
        ++index_two;
      } else {
        ++index_one;
        ++index_two;
      }
    } else {
      ++index_one;
      ++index_two;      
    }
  }

  return true;
}