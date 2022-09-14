class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

// O(n) time / O(n) space
int findClosestValueInBst(BST* tree, int target)
{
  std::function<long long(BST*, long long)> impl;
  impl = [&impl, target] (BST* node, long long closest)
  {
    if (!node)
      return closest;
      
    if (abs(target - closest) > std::abs(target - node->value))
      closest = node->value;

    if (node->value < target)
      return impl(node->right, closest);
    else if (node->value > target)
      return impl(node->left, closest);
    else
      return closest;
  };

  return static_cast<int>(impl(tree, std::numeric_limits<int>::max()));
}

// O(n) time / o(1) space
int findClosestValueInBst(BST* tree, int target)
{
  long long closest = std::numeric_limits<int>::max();

  while (tree) {
    if (abs(target - closest) > std::abs(target - tree->value))
      closest = tree->value;
   
    if (tree->value < target)
      tree = tree->right;
    else if (tree->value > target)
      tree = tree->left;
    else 
      return tree->value;
  }

  return closest;
}