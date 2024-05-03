//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    //���캯��
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//���Ѿ�����
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root) //������ڵ�,����������
    {
        if (root == nullptr)
            return 0;
        invertTree(root->left);
        //����λ��,������������,��������������
        if (root->left != nullptr || root->right != nullptr) //��һ����Ϊ��
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