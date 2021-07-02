// Given a Binary Search Tree and a node value X, find if node with value X is present in the BST or not.

// Example 1:

// Input:
//          2
//           \
//           81
//         /    \
//       42      87
//     /   \       \
//    45   66      90
// x = 87
// Output: 1
// Explanation: As 87 is present in the
// given nodes , so the output will be
// 1.
// Example 2:

// Input:
//       6
//        \
//         7
//        / \
//       8   9
// x = 11
// Output: 0
// Explanation: As 11 is not present in
// he given nodes , so the output will
// be 0.

// Your Task:
// You don't need to read input or print anything. Complete the function search() which returns true if the node with value x is present in the BST else returns false.

// Expected Time Complexity: O(Height of the BST)
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= Number of nodes <= 10^5

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node *root, int x);

Node *insert(Node *tree, int val)
{
    Node *temp = NULL;
    if (tree == NULL)
        return new Node(val);

    if (val < tree->data)
    {
        tree->left = insert(tree->left, val);
    }
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << search(root, s);
        cout << endl;
    }
}

// } Driver Code Ends

//Function to search a node in BST.
bool search(Node *root, int x)
{
    //Your code here
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (root->data > x)
        return search(root->left, x);

    return search(root->right, x);
}
