// O(n*log(n)) time / O(1) space
bool classPhotos(std::vector<int> redShirtHeights, std::vector<int> blueShirtHeights)
{
  sort(begin(redShirtHeights), end(redShirtHeights));
  sort(begin(blueShirtHeights), end(blueShirtHeights));

  std::function<bool(int,int)> comparator = std::less<int>{};
  if (redShirtHeights.back()> blueShirtHeights.back())
    comparator = std::greater<int>{};

  for (int i = redShirtHeights.size() - 1; i >= 0; --i) {
    if (!comparator(redShirtHeights[i], blueShirtHeights[i]))
      return false;
  }  

  return true;
}
