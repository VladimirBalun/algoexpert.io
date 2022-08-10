// O(n) time / O(n) space
bool isPalindrome(std::string str)
{
  const std::string reversed_str(rbegin(str), rend(str));
  return reversed_str == str;
}

// O(n) time / O(n) space
bool isPalindrome(std::string str, size_t left = 0u)
{
  const size_t right = str.length() - left - 1u;
  if (left >= right)
    return true;

  if (str[left] != str[right])
    return false;

  return isPalindrome(str, left + 1u);
}

// O(n) time / O(1) space
bool isPalindrome(std::string str)
{
  size_t left = 0u;
  size_t right = str.length() - 1u;
  while (left < right) {
    if (str[left] != str[right])
      return false;

    ++left;
    --right;
  }

  return true;
}