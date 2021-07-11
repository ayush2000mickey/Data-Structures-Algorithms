// Given a Binary Search Tree of size N, find the Median of its Node values.

// Example 1:

// Input:
//        6
//      /   \
//    3      8
//  /  \    /  \
// 1    4  7    9
// Output: 6
// Explanation: Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8, 9. So, here median will 6.

// Example 2:

// Input:
//        6
//      /   \
//    3      8
//  /   \    /
// 1    4   7
// Output: 5
// Explanation:Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8. So, here median will
// (4 + 6)/2 = 10/2 = 5.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
// Median of the BST is:

// If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
// If number of nodes are odd : then median = (N+1)/2th node.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

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

float findMedian(struct Node *node);

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
    //cout << t << endl;
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        // getline(cin, s);

        cout << findMedian(root) << endl;

        // cout<<"~"<<endl;
    }
    return 0;
} // } Driver Code Ends

/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
void inOrderTraversal(Node *root, vector<int> &inOrdElements)
{
    if (root)
    {
        inOrderTraversal(root->left, inOrdElements);
        inOrdElements.push_back(root->data);
        inOrderTraversal(root->right, inOrdElements);
    }
}

// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node *root)
{
    //Code here
    vector<int> inOrdElements;

    inOrderTraversal(root, inOrdElements);

    if (inOrdElements.size() % 2 == 0)
        return (((inOrdElements[(inOrdElements.size() / 2) - 1]) +
                 (inOrdElements[(inOrdElements.size() / 2)])) /
                2.0);

    return (inOrdElements[(inOrdElements.size() + 1) / 2 - 1]);
}

//GFG Editorial
//Space Optimised Solution

// int countNodes(Node* n)
// {
//     // this function returns number of nodes in tree
//     if(!n) return 0;
//     return 1 + countNodes(n->left) + countNodes(n->right);
// }

// int find(Node* n, int serialNo, int target, int& value)
// {
//     // this function keeps track of serial number while doing
//     // inorder traveresal and finds the target node

//     if(!n) return serialNo;
//     serialNo = find(n->left, serialNo, target, value);

//     serialNo++;
//     // current value of serialNo variable is the rank of
//     // current Node
//     if(serialNo==target) value = n->data;

//     serialNo = find(n->right, serialNo, target, value);
//     return serialNo;
// }

// float findMedian(struct Node* root)
// {
//     int n = countNodes(root);

//     if(n%2)
//     {
//         // odd number of nodes in tree:
//         // 1+n/2 is the rank of mid node

//         int mid = 0;
//         find( root, 0, 1+n/2, mid );
//         return mid;
//     }
//     else
//     {
//         // even number of nodes in tree:
//         // n/2 and 1+n/2 are the ranks of mid nodes

//         int mid1 = 0, mid2 = 0;
//         find( root, 0, n/2, mid1 );
//         find( root, 0, 1+n/2, mid2 );
//         return ((float)(mid1+mid2))/2.0;
//     }
// }
