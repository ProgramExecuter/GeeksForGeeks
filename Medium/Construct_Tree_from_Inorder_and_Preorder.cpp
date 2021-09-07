//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }
};

void printPostOrder(Node *root)
{
  if (root == NULL)
    return;
  printPostOrder(root->left);
  printPostOrder(root->right);
  cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
  int preIndex = 0;
  Node *buildtree(int in[], int pre[], int l, int h)
  {
    if (l > h)
      return NULL;
    Node *root = new Node(pre[preIndex++]);
    if (l == h)
      return root;
    int i;
    for (i = l; i <= h; i++)
      if (root->data == in[i])
        break;

    if (i <= h)
    {
      root->left = buildtree(in, pre, l, i - 1);
      root->right = buildtree(in, pre, i + 1, h);
    }
    return root;
  }
  Node *buildTree(int in[], int pre[], int n)
  {
    // Code here
    return buildtree(in, pre, 0, n - 1);
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int inorder[n], preorder[n];
    for (int i = 0; i < n; i++)
      cin >> inorder[i];
    for (int i = 0; i < n; i++)
      cin >> preorder[i];
    Solution obj;
    Node *root = obj.buildTree(inorder, preorder, n);
    printPostOrder(root);
    cout << endl;
  }
}
// } Driver Code Ends
