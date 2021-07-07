// Given a Binary Search Tree and a range. Find all the numbers in the BST that lie in the given range.
// Note: Element greater than or equal to root go to the right side.

// Example 1:

// Input:
//        17
//      /    \
//     4     18
//   /   \
//  2     9
// l = 4, h = 24
// Output: 4 9 17 18
// Example 2:

// Input:
//        16
//      /    \
//     7     20
//   /   \
//  1    10
// l = 13, h = 23
// Output: 16 20
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function printNearNodes() which takes the root Node of the BST and the range elements low and high as inputs and returns an array that contains the BST elements in the given range low to high (inclusive) in non-decreasing order.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 <= Number of nodes <= 10^4
// 1 <= l < h < 10^5

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

vector<int> printNearNodes(Node *root, int k1, int k2);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        int k1, k2;
        string s;
        getline(cin, s);
        scanf("%d ", &k1);
        scanf("%d ", &k2);
        Node *root = buildTree(s);
        vector<int> res = printNearNodes(root, k1, k2);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 1;
} // } Driver Code Ends

void getInRangeElements(Node *root, int low, int high, vector<int> &inRangeElements)
{

    if (root == NULL)
        return;

    if (root->data > low)
        getInRangeElements(root->left, low, high, inRangeElements);

    if (root->data >= low && root->data <= high)
        inRangeElements.push_back(root->data);

    if (root->data < high)
        getInRangeElements(root->right, low, high, inRangeElements);
}

//Function to return a list of BST elements in a given range.
vector<int> printNearNodes(Node *root, int low, int high)
{
    // your code goes here
    vector<int> inRangeElements;

    if (root == NULL)
        return inRangeElements;

    getInRangeElements(root, low, high, inRangeElements);

    return inRangeElements;
}
