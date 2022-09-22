// O(n) time / O(d) space
bool validateBst(BST* tree)
{
  std::function<bool(BST*, BST*, BST*)> impl;
  impl = [&impl] (BST* current, BST* min, BST* max)
  {
    if (!current)
      return true;
    else if (min && current->value < min->value)
      return false;
    else if (max && current->value >= max->value)
      return false;
    else
      return impl(current->left, min, current) && impl(current->right, current, max);
  };

  return impl(tree->left, nullptr, tree) && impl(tree->right, tree, nullptr);
}
