#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

int largestBst(Node *root);

// Function to Build Tree
Node *buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = new Node(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {

      // Create the left child for the current node
      currNode->left = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {

      // Create the right child for the current node
      currNode->right = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

int main()
{

  int t;
  string tc;
  getline(cin, tc);
  t = stoi(tc);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node *root1 = buildTree(s);

    //getline(cin, s);
    // int k = stoi(s);
    // getline(cin, s);

    cout << largestBst(root1);
    cout << endl;
    //cout<<"~"<<endl;
  }
  return 0;
} // } Driver Code Ends

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
vector<int> func(Node *root)
{
  if (!root)
    return {1, 0, INT_MAX, 0};
  vector<int> a = func(root->left);
  vector<int> b = func(root->right);
  if (a[0] == 1 && b[0] == 1 && root->data > a[3] && root->data < b[2])
  {
    return {1, a[1] + b[1] + 1, min(root->data, min(a[2], b[2])), max(root->data, max(a[3], b[3]))};
  }
  else
  {
    return {0, max(a[1], b[1]), 0, 0};
  }
}
int largestBst(Node *root)
{
  vector<int> ans = func(root);
  return ans[1];
}
