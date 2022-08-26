bool is_valid_part(const std::string& part)
{
  if (part.size() > 1u && part[0] == '0')
    return false;

  const int number = atoi(part.c_str());
  return number < 256;
}

// O(1) time / O(1) space
std::vector<std::string> validIPAddresses(std::string string)
{
  std::vector<std::string> result;
  std::vector<std::string> current_ip_address;
  std::function<void(size_t, size_t)> backtracking;
  backtracking = [&backtracking, &string, &current_ip_address, &result] (size_t index, size_t count_groups)
  {
    if (count_groups == 4u) {
      if (index == string.size())
        result.push_back(
          current_ip_address[0] + '.' +
          current_ip_address[1] + '.' +
          current_ip_address[2] + '.' +
          current_ip_address[3]
        );
      return;
    }

    for (size_t i = index; i < index + 3 && i < string.size(); ++i) {
      std::string part{ begin(string) + index, begin(string) + i + 1 };
      if (!is_valid_part(part)) {
        return;
      }

      current_ip_address.push_back(part);
      backtracking(i + 1, count_groups + 1);
      current_ip_address.pop_back();
    }
  };

  backtracking(0u, 0u);
  return result;
}