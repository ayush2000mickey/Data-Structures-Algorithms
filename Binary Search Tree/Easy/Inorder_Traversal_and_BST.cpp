// Given an array arr of size N, write a program that returns 1 if array represents Inorder traversal of a BST, else returns 0.
// Note: All keys in BST must be unique.

// Example 1:

// Input:
// N = 3
// arr = {2, 4, 5}
// Output: 1
// Explaination: Given arr representing
// inorder traversal of a BST.

// Example 2:

// Input:
// N = 3
// arr = {2, 4, 1}
// Output: 0
// Explaination: Given arr is not representing
// inorder traversal of a BST.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isRepresentingBST() which takes the array arr[] and its size N as input parameters and returns 1 if array represents Inorder traversal of a BST, else returns 0.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 10^3
// 1 ≤ arr[i] ≤ 10^3

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int isRepresentingBST(int arr[], int N)
    {
        // code here
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] >= arr[i + 1])
                return 0;
        }

        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.isRepresentingBST(arr, N) << endl;
    }
    return 0;
} // } Driver Code Ends