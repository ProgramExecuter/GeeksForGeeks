#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
  if (size == 0)
    return NULL;

  int val;
  cin >> val;

  Node *head = new Node(val);
  Node *tail = head;

  for (int i = 0; i < size - 1; i++)
  {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }

  return head;
}

/* Driver program to test above function*/
int main()
{
  int T, n1, n2, n3;

  cin >> T;
  while (T--)
  {
    cin >> n1 >> n2 >> n3;

    Node *head1 = inputList(n1);
    Node *head2 = inputList(n2);
    Node *common = inputList(n3);

    Node *temp = head1;
    while (temp != NULL && temp->next != NULL)
      temp = temp->next;
    if (temp != NULL)
      temp->next = common;

    temp = head2;
    while (temp != NULL && temp->next != NULL)
      temp = temp->next;
    if (temp != NULL)
      temp->next = common;

    cout << intersectPoint(head1, head2) << endl;
  }
  return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
  // Your Code Here
  int l1 = 0, l2 = 0;

  //Finding the lenght of both lists
  Node *temp = head1;
  while (temp)
  {
    ++l1;
    temp = temp->next;
  }
  temp = head2;
  while (temp)
  {
    ++l2;
    temp = temp->next;
  }

  //Head starting the smaller list
  //so that both are equal distance from intersection
  Node *temp1 = head1;
  Node *temp2 = head2;
  if (l1 > l2)
  {
    for (int i = 0; i < (l1 - l2); ++i)
      temp1 = temp1->next;
  }
  else
  {
    for (int i = 0; i < (l2 - l1); ++i)
      temp2 = temp2->next;
  }

  //Finding the common node
  while (temp1 && temp2)
  {
    if (temp1 == temp2)
      return temp1->data;
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return -1;
}