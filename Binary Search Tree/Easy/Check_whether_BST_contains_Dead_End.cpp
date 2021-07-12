// Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

// Examples:

// Input :
//                8
//              /   \ 
//            5      9
//          /  \     
//         2    7
//        /
//       1

// Output : Yes
// Explanation : Node "1" is the dead End because after that
//               we cant insert any element.

// Input :
//               8
//             /   \ 
//            7     10
//          /      /   \
//         2      9     13

// Output : Yes
// Explanation : We can't insert any element at
//               node 9.

// Input:
// The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the no of nodes of the BST . Second line of each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.

// Output:
// The output for each test case will be 1 if the BST contains a dead end else 0.

// Constraints:
// 1<=T<=100
// 1<=N<=200

// Example(To be used only for expected output):
// Input:
// 2
// 6
// 8 5 9 7 2 1
// 6
// 8 7 10 9 13 2
// Output:
// 1
// 1

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

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int getCountOfNode(Node *root, int l, int h)
{

    if (!root)
        return 0;

    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
               getCountOfNode(root->right, l, h);

    else if (root->data < l)
        return getCountOfNode(root->right, l, h);

    else
        return getCountOfNode(root->left, l, h);
}

bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root;
        Node *tmp;
        //int i;

        root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            insert(&root, k);
        }

        cout << isDeadEnd(root);
        cout << endl;
    }
}

// } Driver Code Ends

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

void checkDeadEnd(Node *root, int min, int max, bool &deadEnd)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        if (min == root->data && max - root->data == 1)
            deadEnd = true;
        else if (root->data - min == 1 && max == root->data)
            deadEnd = true;
        else if (root->data - min == 1 && max - root->data == 1)
            deadEnd = true;

        return;
    }

    checkDeadEnd(root->left, min, root->data, deadEnd);
    checkDeadEnd(root->right, root->data, max, deadEnd);
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    //Your code here
    bool deadEnd = false;
    checkDeadEnd(root, 1, 200, deadEnd);

    return deadEnd;

    //GFG
    //return deadEnd(root , 1 , 200);
}

//GFG Solution

// bool deadEnd(Node* root, int min, int max)
// {
//     // if the root is null or the recursion moves
//     // after leaf node it will return false
//     // i.e no dead end.
//     if (!root)
//         return false;

//     // if this occurs means dead end is present.
//     if (min == max)
//         return true;

//     // heart of the recursion lies here.
//     return deadEnd(root->left, min, root->data - 1) ||
//           deadEnd(root->right, root->data + 1, max);
// }
