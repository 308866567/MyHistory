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
	//���캯��
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;
class Solution
{
public:
	map<int, int> r; //�ڵ��Ӧ�������������±�
	TreeNode* root = nullptr;
	void m(vector<int>& inorder)//������ϣ��
	{
		int len = inorder.size();
		for (int i = 0; i < len; i++)
		{
			r[inorder[i]] = i;//�ڵ�����-����λ��
		}
		return;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)//��ʼ����
	{
		m(inorder);
		root = build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
		//			pf(root);
		//			cout << "\n";
		//			pf2(root);
		//			cout << "\n";
		//			pf4(root);		
		return root;
	}
	//��ǰ��������������й��������
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int p1, int p2, int i1, int i2)
	{
		if (p1 > p2)//��������Ϊ�ռ�ʱ����,Ҳ������i1>i2
			return nullptr;
		TreeNode *root = new TreeNode(preorder[p1]);//�������ڵ�
		cout << preorder[p1] << "\n";
		int index = r[preorder[p1]]; //���������,���ڵ��λ��
		int leftnum = index - i1; //�������Ľڵ����
		//�������ӵ�����,����Ϊ���ڵ�,λ�ü�p1+1
		root->left = build(preorder, inorder, p1 + 1, p1 + leftnum, i1, index - 1);
		//�����Һ��ӵ�����,�к���Ϊ���ڵ�,λ�ü�
		root->right = build(preorder, inorder, p1 + leftnum  + 1, p2, index + 1, i2);
		return root;
	}
	void pf(TreeNode* root)//ǰ��
	{
		if (root == nullptr) return;
		cout << root->val << ' ';
		pf(root->left);
		pf(root->right);
		return;
	}
	void pf2(TreeNode* root)//����
	{
		if (root == nullptr) return;
		pf2(root->left);
		cout << root->val << ' ';
		pf2(root->right);
		return;
	}
	void pf3(TreeNode* root)//����
	{
		if (root == nullptr) return;
		pf3(root->left);
		pf3(root->right);
		cout << root->val << ' ';
		return;
	}
	void pf4(TreeNode* now)//�������
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
	vector<int> p = {3, 9, 20, 15, 7};
	vector<int> i = {9, 3, 15, 20, 7};
	a.buildTree(p, i);
	return 0;
}
