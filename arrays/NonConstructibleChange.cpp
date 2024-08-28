// O(n*log(n)) time / O(1) space
int nonConstructibleChange(std::vector<int> coins)
{
  std::sort(begin(coins), end(coins));

  int changes = 0;
  for (const int coin: coins) {
    if (coin > changes + 1)
      return changes + 1;
    changes += coin;
  }

  return changes + 1;
}
