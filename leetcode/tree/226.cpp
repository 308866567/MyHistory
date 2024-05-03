//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    //构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//树已经给好
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root) //给入根节点,中序遍历解决
    {
        if (root == nullptr)
            return 0;
        invertTree(root->left);
        //中序位置,遍历完左子树,即将进入右子树
        if (root->left != nullptr || root->right != nullptr) //有一个不为空
        {
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            return root;
        }
        invertTree(root->right);
        return root;
    }
};
int main()
{
    return 0;
}