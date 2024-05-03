#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	//构造函数
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;
class Solution
{
	public:
		map<int, int> r; //节点对应中序遍历数组的下标
		TreeNode* root = nullptr;
		void m(vector<int>& inorder)//构建哈希表
		{
			int len = inorder.size();
			for (int i = 0; i < len; i++)
			{
				r[inorder[i]] = i;//节点数据-中序位置
			}
			return;
		}
		TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
		{
			m(postorder);
			root = build(preorder, postorder, 0, postorder.size() - 1, 0, postorder.size() - 1);
//						pf(root);
//						cout << "\n";
//						pf2(root);
			//			cout << "\n";
//						pf4(root);
			return root;
		}
		//从前序与后序序遍历序列构造二叉树
		TreeNode* build(vector<int>& preorder, vector<int>& postorder, int p1, int p2, int i1, int i2)
		{
			if (p1 > p2)//子树区间为空集时返回,也可以填i1>i2
				return nullptr;
			if (p1 == p2) //子树只有一个节点的情况,直接返回,防止出错
				return new TreeNode(preorder[p1]);
			TreeNode *root = new TreeNode(preorder[p1]);//创建根节点,前序开头或后序中末尾为根节点
			//		cout << postorder[p2] << "\n";
			int index = r[preorder[p1 + 1]]; //后序遍历中,以前序根节点+1为左子树根节点的位置
			int leftnum = index - i1 + 1; //左子树的节点个数,+1是因为index为左子树的根节点,没有算进去
			//构建左孩子的子树,左孩子为根节点,中序位置即p1+1
			root->left = build(preorder, postorder, p1 + 1, p1 + leftnum , i1, index );
			//构建右孩子的子树,有孩子为根节点,中序位置即
			root->right = build(preorder, postorder, p1 + leftnum+1, p2 , index + 1, i2-1);
			return root;
		}
		void pf(TreeNode* root)//前序
		{
			if (root == nullptr) return;
			cout << root->val << ' ';
			pf(root->left);
			pf(root->right);
			return;
		}
		void pf2(TreeNode* root)//中序
		{
			if (root == nullptr) return;
			pf2(root->left);
			cout << root->val << ' ';
			pf2(root->right);
			return;
		}
		void pf3(TreeNode* root)//后序
		{
			if (root == nullptr) return;
			pf3(root->left);
			pf3(root->right);
			cout << root->val << ' ';
			return;
		}
		void pf4(TreeNode* now)//层序遍历
		{
			queue<TreeNode*> q;
			TreeNode*temp = now;
			q.push(now);
			while (!q.empty())
			{
				temp = q.front();
				cout << temp->val << ' ';
				q.pop();
				if (temp->left != NULL)
					q.push(temp->left);
				if (temp->right != NULL)
					q.push(temp->right);
			}
		}
};
int main()
{
	// freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	Solution a;
	vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
	vector<int> post = {4, 5, 2, 6, 7, 3, 1};
	a.constructFromPrePost(pre, post);
	return 0;
}
