// Given a BST and a value k, the task is to delete the nodes having values greater than or equal to x.

// Example 1:

// Input:
//     4
//    / \  
//   1   9
// k = 2
// Output:
// 1
// Your Task:
// The task is to complete the function deleteNode() which takes root, k as the argument, and returns the root of tree after deleting values greater than or equal to x. The driver code will print the inorder traversal of the updated tree in output itself.

// Expected Time Complexity: O(Size of tree)
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 103
// 1 <= A[] <= 103
// 1 <= x <= N

// { Driver Code Starts
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

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

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

// } Driver Code Ends
/*The node structure
struct Node {
int data;
Node * right, * left;
};*/

class Solution
{
public:
    /*The function should return the root of the modified tree*/
    Node *deleteNode(Node *root, int k)
    {
        //Your code here
        if (root == NULL)
            return NULL;

        if (root->data >= k)
            return deleteNode(root->left, k);

        root->right = deleteNode(root->right, k);

        return root;
    }

    //GFG solution
    //Better in terms of space as it also deletes the space acquired
    //by that node greater than k
    // Node* deleteNode(Node* root, int k)
    // {
    // 	// base case
    // 	if (root == NULL) return NULL;

    //     root->right = deleteNode(root->right,k);

    // 	root->left = deleteNode(root->left,k);

    // 	if(root->data>=k)
    // 	{
    // 	    Node *temp =root->left;
    // 	    delete(root);
    // 	    return temp;
    // 	}

    // 	return root;

    // }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    getchar();
    while (T--)
    {
        Node *root;
        Node *tmp;
        //int i;
        root = NULL;
        string s;
        getline(cin, s);

        root = buildTree(s);
        int k;
        cin >> k;
        getchar();
        Solution obj;
        Node *R = obj.deleteNode(root, k);
        inorder(R);
        cout << endl;
    }
}

// } Driver Code Ends