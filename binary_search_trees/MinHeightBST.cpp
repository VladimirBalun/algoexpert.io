class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

// O(nlog(n)) time / O(n) space
BST* minHeightBst(std::vector<int> array)
{
  std::function<BST*(BST*, ssize_t, ssize_t)> impl;
  impl = [&impl, &array] (BST* node, ssize_t left, ssize_t right) -> BST*
  {
    if (right < left)
      return nullptr;

    const ssize_t middle = (left + right) / 2;
    const int value_to_add = array[middle];
    
    if (!node)
      node = new BST(value_to_add);
    else
      node->insert(value_to_add);

    impl(node, left, middle - 1);
    impl(node, middle + 1, right);
    return node;
  };

  return impl(nullptr, 0, array.size() - 1);
}

// O(n) time / O(n) space
BST* minHeightBst(std::vector<int> array)
{
  std::function<BST*(ssize_t, ssize_t)> impl;
  impl = [&impl, &array] (ssize_t begin, ssize_t end) -> BST*
  {
    if (begin <= end) {
      const ssize_t middle = (begin + end) / 2;
      BST* node = new BST(array[middle]);
      node->left = impl(begin, middle - 1);
      node->right = impl(middle + 1, end);
      return node;
    }

    return nullptr;
  };

  return impl(0u, array.size() - 1u);
}