#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/*
 * Creates a new node from a given value, allocating heap memory for it.
 */
node_t* make_tree(int val) {
  node_t* new_tree = malloc(sizeof(node_t));
  new_tree->val = val;
  new_tree->left = NULL;
  new_tree->right = NULL;
  return new_tree;
}

/*
 * Inserts a new value into a given binary search tree, allocating heap memory
 * for it.
 */
node_t* insert(int val, node_t* cur_root) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    
    node_t* tmp_root = cur_root;
    
    while (tmp_root)
    {
        if (val < tmp_root->val && tmp_root->left)
        {
            tmp_root = tmp_root->left;
        }
        else if (val < tmp_root->val)
        {
            tmp_root->left = new_node;
        }
        
        if (val >= tmp_root->val && tmp_root->right)
        {
            tmp_root = tmp_root->right;
        }
        else if (val >= tmp_root->val)
        {
            tmp_root->right = new_node;
        }
    }
    
    return cur_root;
}

bool find_val(int val, node_t* root) {
    while (root)
    {
      if (val < root->val)
      {
          root = root->left;
      }
      else if (val > root->val)
      {
          root = root->right;
      }
      else
      {
          return true;
      }
    }
    return false;
}

/*
 * Given a pointer to the root, frees the memory associated with an entire tree.
 */
void delete_bst(node_t* root) {
    int multiplier = 0;
    int NUM_ROOTS = 100;
    node_t* roots = (node_t*)malloc((++multiplier) * NUM_ROOTS * sizeof(node_t*));
    roots[0] = root;
    int head = 0;
    node_t* cur_node;
    
    while (head >= 0)
    {
        cur_node = roots[head--];
        if (cur_node->right && head < multiplier * NUM_ROOTS)
            roots[head++] = cur_node->right;
        else (cur_node->right)
        {
            node_t* new_roots = (node_t*)realloc(roots, (++multiplier) * NUM_ROOTS * sizeof(node_t*));
            if (new_roots)
                roots = new_roots;
            roots[head++] = cur_node->right;
        }
        if (cur_node->left && head < multiplier * NUM_ROOTS)
            roots[head++] = cur_node->left;
        else (cur_node->left)
        {
            node_t* new_roots = (node_t*)realloc(roots, (++multiplier) * NUM_ROOTS * sizeof(node_t*));
            if (new_roots)
                roots = new_roots;
            roots[head++] = cur_node->left;
        }
        
        free(cur_node);
    }
    
}

/* Given a pointer to the root, prints all of the values in a tree. */
void print_bst(node_t* root) {
  if (root != NULL) {
    printf("%d ", root->val);
    print_bst(root->left);
    print_bst(root->right);
  }
  return;
}
