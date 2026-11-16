
/*
 * @author: Bhuvanesh
 * reconstruction of fun7 (secret phase)
 */

struct node {
  int data;
  struct node* left;
  struct node* right;
};

int fun7(struct node *root, int key) {
  
  if (!root) {
    return -1;
  } 
  int value = root->data;

  if (key < value) {
    value = fun7(root->left, key);
    value = value * 2;
  } else if (key == value) {
    value = 0;
  } else {
    value = fun7(root->right, key);
    value = (2 * value) + 1;
  }
  return value;
}


