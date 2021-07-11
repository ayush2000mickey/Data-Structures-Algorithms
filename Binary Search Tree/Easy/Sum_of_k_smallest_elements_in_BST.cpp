// Given a Binary Search Tree. Find sum of all elements smaller than and equal to Kth smallest element.

// Example 1:

// Input:
//           20
//         /    \
//        8     22
//      /    \
//     4     12
//          /    \
//         10    14   , K=3

// Output: 22
// Explanation:
// Sum of 3 smallest elements are:
// 4 + 8 + 10 = 22
// Example 2:
// Input:
//      10
//     /  \
//    5    11
//   / \ 
//  4   7
//       \
//        8 , K=2

// Output: 9
// Explanation:
// The sum of two smallest elements
// is 4+5=9.

// Your task:
// You don't need to read input or print anything. Your task is to complete the function sum() which takes the root node and an integer K as input parameters and returns the sum of all elements smaller than and equal to kth smallest element.

// Expected Time Complexity: O(K)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=Number of nodes in BST<=100
// 1<=K<=N

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
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
    Node *root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int sum(Node *root, int k);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin >> ws, s);
        int k;
        cin >> k;
        Node *root = buildTree(s);
        cout << sum(root, k) << endl;
    }
    return 1;
}

// } Driver Code Ends

//User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

void getKElementsSum(Node *root, int &kElementsSum, int &k)
{
    if (root)
    {
        getKElementsSum(root->left, kElementsSum, k);
        if (k > 0)
        {
            kElementsSum += root->data;
            k--;
            getKElementsSum(root->right, kElementsSum, k);
        }
    }
}

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
int sum(Node *root, int k)
{

    // Your code here
    int kElementsSum = 0;

    getKElementsSum(root, kElementsSum, k);

    return kElementsSum;
}