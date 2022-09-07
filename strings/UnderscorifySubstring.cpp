std::vector<std::pair<size_t, size_t>> get_locations(const std::string& str, const std::string& subStr)
{
  size_t start_index = 0u;
  std::vector<std::pair<size_t, size_t>> locations;
  while (start_index < str.length()) {
    const auto next_index = str.find(subStr, start_index);
    if (next_index == std::string::npos)
      break;
    
    locations.emplace_back(next_index, next_index + subStr.length());
    start_index = next_index + 1u;
  }

  return locations;
}

std::vector<std::pair<size_t, size_t>> collapse(const std::vector<std::pair<size_t, size_t>>& locations)
{
  if (locations.empty())
    return locations;
  
  std::vector<std::pair<size_t, size_t>> collapsed_locations;
  collapsed_locations.push_back(locations.front());

  auto previous = collapsed_locations.rbegin();
  for (size_t i = 1u; i < locations.size(); ++i) {
    auto current = locations[i];
    if (current.first <= previous->second) {
      previous->second = current.second;
    } else {
      collapsed_locations.push_back(current);
      previous = collapsed_locations.rbegin();
    }  
  }

  return collapsed_locations;
}

std::string underscorify(const std::string& str, const std::vector<std::pair<size_t, size_t>>& locations)
{
  size_t str_index = 0u;
  size_t locations_index = 0u;
  bool in_between_underscores = false;

  std::string result;
  while (str_index < str.length() && locations_index < locations.size()) {
    const size_t underscore_index = !in_between_underscores
      ? locations[locations_index].first : locations[locations_index].second;
    if (str_index == underscore_index) {
      in_between_underscores = !in_between_underscores;
      if (!in_between_underscores)
        ++locations_index;
      
      result += '_';
    }

    result += str[str_index];
    ++str_index;
  }

  
  if (locations_index < locations.size())
    result += '_';
  for (size_t i = str_index; i < str.length(); ++i)
    result += str[i];

  return result;
}

// O(n + m) time / O(n) space
std::string underscorifySubstring(std::string str, std::string subStr)
{
  auto locations = collapse(get_locations(str, subStr));
  return underscorify(str, locations);
}