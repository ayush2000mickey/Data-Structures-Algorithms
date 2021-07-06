// Given a binary tree. Check whether it is a BST or not.
// Note: We are considering that BSTs can not contain duplicate Nodes.

// Example 1:

// Input:
//     2
//  /    \
// 1      3
// Output: 1
// Explanation:
// The left subtree of root node contains node
// with key lesser than the root node’s key and
// the right subtree of root node contains node
// with key greater than the root node’s key.
// Hence, the tree is a BST.
// Example 2:

// Input:
//   2
//    \
//     7
//      \
//       6
//        \
//         5
//          \
//           9
//            \
//             2
//              \
//               6
// Output: 0
// Explanation:
// Since the node with value 7 has right subtree
// nodes with keys less than 7, this is not a BST.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 0 <= Number of edges <= 100000

// { Driver Code Starts
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

// } Driver Code Ends

class Solution
{
public:
    bool checkBST(Node *root, int rangeMin, int rangeMax)
    {
        if (root == NULL)
            return true;

        if (root->data <= rangeMin || root->data >= rangeMax)
            return false;

        bool l = checkBST(root->left, rangeMin, root->data);
        if (!l)
            return false;

        bool r = checkBST(root->right, root->data, rangeMax);
        if (!r)
            return false;

        return true;
    }

    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        // Your code here
        int rangeMin = INT_MIN;
        int rangeMax = INT_MAX;

        return checkBST(root, rangeMin, rangeMax);
    }
};

// { Driver Code Starts.

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

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
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
        Node *root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "1\n";

        else
            cout << "0\n";
    }
    return 0;
}

//Position this line where user code will be pasted
// } Driver Code Ends