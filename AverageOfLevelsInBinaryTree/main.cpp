/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution {
public:
    void computAverage(TreeNode *x, vector<double> &vect){
        TreeNode *fatherNode = x;
        TreeNode *sonNode;
        if(fatherNode->left != nullptr)
            sonNode = fatherNode->left;

        while(fatherNode != nullptr){
            fatherNode->left->left = fatherNode;

        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> results = {(double)root->val};
        if(root->left == nullptr and root->right == nullptr)
            computAverage(root, results);
        return results;
    }
};