

struct node
{
  int data;
  struct node *next;

  node(int x)
  {
    data = x;
    next = NULL;
  }
};

/* Function to print linked list */
void printList(struct node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
public:
  struct node *reverse(struct node *head, int k)
  {
    // Complete this method
    node *first, *second, *temp, *prev, *next;
    first = NULL;
    second = NULL;
    temp = head;
    prev = NULL;
    next = NULL;
    bool flag = true;
    while (temp)
    {
      second = temp;
      int i = 1;
      while (i <= k && temp)
      {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        ++i;
      }
      if (flag)
      {
        head = prev;
        flag = false;
      }
      else
      {
        first->next = prev;
      }
      second->next = NULL;
      first = second;
    }
    return head;
  }
};

// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
  int t;
  cin >> t;

  while (t--)
  {
    struct node *head = NULL;
    struct node *temp = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      int value;
      cin >> value;
      if (i == 0)
      {
        head = new node(value);
        temp = head;
      }
      else
      {
        temp->next = new node(value);
        temp = temp->next;
      }
    }

    int k;
    cin >> k;

    Solution ob;
    head = ob.reverse(head, k);
    printList(head);
  }

  return (0);
}

// } Driver Code Ends