bool try_swap_pattern(std::string& pattern)
{
  if (pattern[0] == 'x')
    return false;

  for (size_t i = 0u; i < pattern.length(); ++i)
    pattern[i] = pattern[i] == 'x' ? 'y' : 'x';

  return true;
}

ssize_t get_letters_count_and_first_y_position(const std::string& pattern, std::unordered_map<char, ssize_t>& letters_count)
{
  ssize_t first_y_position = -1;
  for (size_t i = 0u; i < pattern.size(); ++i) {
    ++letters_count[pattern[i]];
    if (pattern[i] == 'y' && first_y_position == -1)
      first_y_position = i;
  }

  return first_y_position;
}

std::string create_str_by_pattern(const std::string& x, const std::string& y, const std::string& pattern)
{
  std::string result;
  for (const char letter: pattern) {
    if (letter == 'x')
      result += x;
    else
      result += y;
  }

  return result;
}

// O(n^2 + m) time / O(n + m) space
std::vector<std::string> patternMatcher(std::string pattern, std::string str)
{
  if (pattern.length() > str.length())
    return {};

  std::unordered_map<char, ssize_t> letters_count;
  const bool was_swapped_pattern = try_swap_pattern(pattern);
  const ssize_t first_y_position = get_letters_count_and_first_y_position(pattern, letters_count);
  if (first_y_position != -1) {
    for (ssize_t x_length = 1; x_length < str.length(); ++x_length) {
      const ssize_t y_length = ((ssize_t)str.length() - x_length * letters_count['x']) / letters_count['y'];
      if (y_length <= 0 || y_length % 1 != 0)
        continue;

      const ssize_t y_index = first_y_position * x_length;
      const std::string x(begin(str), begin(str) + x_length);
      const std::string y(begin(str) + y_index, begin(str) + y_index + y_length);
      const std::string potential_match = create_str_by_pattern(x, y, pattern);
      std::cout << potential_match << std::endl;
      if (str == potential_match)
        return was_swapped_pattern 
          ? std::vector<std::string>{ y, x } 
          : std::vector<std::string>{ x, y };
    }
  } else {
    const ssize_t x_length = str.length() / letters_count['x'];
    if (x_length % 1 == 0) {
      const std::string x(begin(str), begin(str) + x_length);
      const std::string potential_match = create_str_by_pattern(x, "", pattern);
      if (str == potential_match)
        return was_swapped_pattern 
          ? std::vector<std::string>{ "", x } 
          : std::vector<std::string>{ x, "" };        
    }
  }

  return {};
}
