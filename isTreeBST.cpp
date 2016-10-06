//https://www.hackerrank.com/challenges/ctci-is-binary-search-tree


/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
   bool checkBST(Node* root) {
        //these numbers are placeholders for INT_MIN and INT_MAX respectively
        return(isBSTUtil(root, -10000000, 10000000)); 
        
   }


 /* Returns true if the given tree is a BST and its 
   values are >= min and <= max. */
bool isBSTUtil(Node * node, int min, int max) 
{ 
  /* an empty tree is BST */
  if (node==NULL) 
     return true;
       
  /* false if this node violates the min/max constraint */ 
  if (node->data < min || node->data > max) 
     return false; 
 
  /* otherwise check the subtrees recursively, 
   tightening the min or max constraint */
  return
    isBSTUtil(node->left, min, node->data-1) &&  // Allow only distinct values
    isBSTUtil(node->right, node->data+1, max);  // Allow only distinct values
} 
