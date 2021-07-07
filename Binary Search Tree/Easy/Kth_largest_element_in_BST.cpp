// Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

// Example 1:

// Input:
//       4
//     /   \
//    2     9
// k = 2
// Output: 4

// Example 2:

// Input:
//        9
//         \ 
//           10
// K = 1
// Output: 10

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

// Expected Time Complexity: O(H + K).
// Expected Auxiliary Space: O(H)

// Constraints:
// 1 <= N <= 1000
// 1 <= K <= N

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// } Driver Code Ends
/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    //For Approach 1
    // void getInOrderTraversal(Node *root ,vector<int> &inOrderVec)
    // {
    //     if(root)
    //     {
    //         getInOrderTraversal(root->left , inOrderVec);
    //         inOrderVec.push_back(root->data);
    //         getInOrderTraversal(root->right , inOrderVec);
    //     }
    // }

    //For Approach 2
    void getKthLargestEle(Node *root, int &count, int &KthLargestEle, int k)
    {
        if (root)
        {
            if (count >= k)
                return;

            getKthLargestEle(root->right, count, KthLargestEle, k);
            count++;
            if (k == count)
            {
                KthLargestEle = root->data;
                return;
            }

            getKthLargestEle(root->left, count, KthLargestEle, k);
        }
    }

    int kthLargest(Node *root, int k)
    {
        //Your code here

        //Approach 2 without using extra space
        int count = 0;
        int KthLargestEle = 0;

        getKthLargestEle(root, count, KthLargestEle, k);

        return KthLargestEle;

        //Approach 1 using Extra Space
        // vector<int> inOrderVec;

        // getInOrderTraversal(root , inOrderVec);

        // return inOrderVec[inOrderVec.size() - k];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);

        int k;
        cin >> k;
        getchar();

        Solution ob;
        cout << ob.kthLargest(head, k) << endl;
    }
    return 1;
} // } Driver Code Ends