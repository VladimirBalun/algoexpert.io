class BST {
public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
};

// O(n) time / O(n) space
void inOrderTraverse(BST* tree, std::vector<int>& array)
{
  if (tree) {
    inOrderTraverse(tree->left, array);
    array.push_back(tree->value);
    inOrderTraverse(tree->right, array);
  }
}

// O(n) time / O(n) space
void preOrderTraverse(BST *tree, std::vector<int>& array)
{
  if (tree) {
    array.push_back(tree->value);
    preOrderTraverse(tree->left, array); 
    preOrderTraverse(tree->right, array);
  }
}

// O(n) time / O(n) space
void postOrderTraverse(BST* tree, std::vector<int>& array)
{
  if (tree) {
    postOrderTraverse(tree->left, array);  
    postOrderTraverse(tree->right, array);
    array.push_back(tree->value);
  }
}