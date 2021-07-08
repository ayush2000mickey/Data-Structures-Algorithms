// There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.

// Output:
// Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.

// Constraints:
// 1<=T<=100
// 1<=n<=100
// 1<=data of node<=100
// 1<=key<=100

// Example:
// Input:
// 2
// 6
// 50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
// 65
// 6
// 50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
// 100

// Output:
// 60 70
// 80 -1

// { Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

int key = 0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key);

void insert(struct Node *root, int n1, int n2, char lr)
{
    if (root == NULL)
        return;
    if (root->key == n1)
    {
        switch (lr)
        {
        case 'L':
            root->left = new Node(n2);
            break;
        case 'R':
            root->right = new Node(n2);
            break;
        }
    }
    else
    {
        insert(root->left, n1, n2, lr);
        insert(root->right, n1, n2, lr);
    }
}
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t, k;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct Node *root = NULL;
        Node *pre = NULL;
        Node *suc = NULL;
        while (n--)
        {
            char lr;
            int n1, n2;
            cin >> n1 >> n2;
            cin >> lr;
            if (root == NULL)
            {
                root = new Node(n1);
                switch (lr)
                {
                case 'L':
                    root->left = new Node(n2);
                    break;
                case 'R':
                    root->right = new Node(n2);
                    break;
                }
            }
            else
            {
                insert(root, n1, n2, lr);
            }
        }
        // Inorder(root);
        //Node * target =ptr;
        //printkdistanceNode(root, target, k);
        //cout<<endl;
        cin >> key;
        findPreSuc(root, pre, suc, key);
        if (pre != NULL)
            cout << pre->key;
        else
            cout << "-1";

        if (suc != NULL)
            cout << " " << suc->key << endl;
        else
            cout << " "
                 << "-1" << endl;
    }
    return 0;
} // } Driver Code Ends

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

void getPredecessor(Node *curr, Node *&pre, int key)
{
    while (curr != NULL)
    {
        if (curr->key < key)
        {
            pre = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
}

void getSuccessor(Node *curr, Node *&suc, int key)
{
    while (curr != NULL)
    {
        if (curr->key <= key)
        {
            curr = curr->right;
        }
        else
        {
            suc = curr;
            curr = curr->left;
        }
    }
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // Your code goes here
    getPredecessor(root, pre, key);

    getSuccessor(root, suc, key);
}