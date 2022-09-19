class BST {
public:
  int value;
  BST* left;
  BST* right;

  BST(int val)
  {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  // O(n) time / O(1) space
  BST& insert(int val)
  {
    BST* current = this;
    while (true) {
      if (val < current->value) {
        if (!current->left) {
          current->left = new BST(val);
          break;
        } else {
          current = current->left;
        }
      } else {
        if (!current->right) {
          current->right = new BST(val);
          break;
        } else {
          current = current->right;
        }        
      }
    }
    
    return *this;
  }

  // O(n) time / O(1) space
  bool contains(int val) const
  {
    const BST* current = this;
    while (current) {
      if (val < current->value) {
        current = current->left;
      } else if (val > current->value) {
        current = current->right;
      } else {
        return true;
      }
    }

    return false;
  }

  // O(n) time / O(1) space
  BST& remove(int val)
  {
    BST* root = this;
    BST* current = root;
    BST* parent = nullptr;
    
    while (current) {
      if (val < current->value) {
        parent = current;
        current = current->left;
      } else if (val > current->value) {
        parent = current;
        current = current->right;  
      } else {
        break;
      }
    }

    if (!current)
      return *this;

    if (!current->right) {
      if (parent) {
        if (current == parent->left)
          parent->left = current->left;
        else
          parent->right = current->left;
      } else {
        if (current->left) {
          root->value = current->left->value;
          root->left = current->left->left;          
        } else {
          root = current->left;
        }
      }
    } else {
      BST* parent = current;
      BST* min = current->right;
      
      while (min->left) {
        parent = min;
        min = min->left;
      }

      current->value = min->value;
      if (min == parent->left)
        parent->left = min->right;
      else
        parent->right = min->right;
    }
    
    return *this;
  }
};
