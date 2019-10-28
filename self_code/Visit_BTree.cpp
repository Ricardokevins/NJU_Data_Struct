/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<iostream>
 #include<vector>
 using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void visit(TreeNode*root,vector<int>&a)
    {
        if(root==NULL)
            return;
        a.push_back(root->val);
        visit(root->left,a);
        visit(root->right,a);
        return;
    }
    
    vector<int> depthOrder(TreeNode *root){
        vector<int>data;
        visit(root,data);
        return data;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*>opr1;
        vector<TreeNode*>opr2;
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        opr1.push_back(root);
        int flag=2;
        while(1)
        {
            if(flag==1)
            {
                vector<int>temp2;
                if(opr2.size()==0)
                {
                    break;
                }
                for(int i(0);i<opr2.size();i++)
                {
                    temp2.push_back(opr2[i]->val);
                    if(opr2[i]->left!=NULL)
                    {
                        opr1.push_back(opr2[i]->left);
                    }
                    if(opr2[i]->right!=NULL)
                    {
                        opr1.push_back(opr2[i]->right);
                    }
                }
                if(temp2.size()!=0)
                    result.push_back(temp2);
                opr2.clear();
                flag=2;
            }
            if(flag==2)
            {
                vector<int>temp2;
                if(opr1.size()==0)
                {
                    break;
                }
                for(int i(0);i<opr1.size();i++)
                {
                    temp2.push_back(opr1[i]->val);
                    if(opr1[i]->left!=NULL)
                    {
                        
                        opr2.push_back(opr1[i]->left);
                    }
                    if(opr1[i]->right!=NULL)
                    {
                        opr2.push_back(opr1[i]->right);
                    }
                }
                if(temp2.size()!=0)
                    result.push_back(temp2);
                opr1.clear();
                flag=1;
            }
        }
        return result;
    }
};
