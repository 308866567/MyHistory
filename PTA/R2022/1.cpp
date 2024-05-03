#include <iostream>
typedef long long ll;
const ll N = 10 + 1;
using namespace std;
int arr[N][N] = {0};
int s = 1;
int A, B, len;
//0����,1����,2����,3����
int dir[4][2] = {0, 0, 0, 1, 1, 1, 1, 0};
void out()
{
//	cout<<"\n"<<s<<"\n";
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (arr[i][j] == -1)
				printf("%4d", 0);
			else
				printf("%4d", arr[i][j]);
		}
		if (i < len)
			printf("\n");
	}
}

//����״��,����xλ��
void slove3(int lx, int ly, int x)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == x)
			continue;
		arr[ly + dir[i][0]][lx + dir[i][1]] = s;
	}
	s++;
	return ;
}

//�ж����ﲻ��
//a��b��,ly��lx��
int slove2(int lx, int ly, int len, int a, int b)
{
	if (lx < b)
	{
		if (ly < a)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (ly < a)
		{
			return 3;
		}
		else
		{
			return 0;
		}
	}
}
//ÿ���ָ����ϰ�λ��
//0->2 1->3 2->0 3->1  +2)%4,�������ⷽ���ǲ��ִ���AB
//(a,b)Ϊ�ϰ�����


//��������,Ȼ��4�ȷ�
void slove(int lx, int ly, int len, int a, int b)
{
	int tx = lx + len / 2 - 1;
	int ty = ly + len / 2 - 1;
	int x = slove2(tx, ty, len, a, b); //���Ĵ�����״
//	out();
	if (len == 2) //��ʼ��
	{
		slove3(lx, ly, x);
		return;
	}

	//�ĵȷ�
	int t[4][2];//�������ֵ��ϰ�����


	for (int i = 0; i < 4; i++)
	{
		t[i][0] = ty + dir[i][0];
		t[i][1] = tx + dir[i][1];
	}
	//��������
	slove3(tx, ty, x);
	t[x][0]=a;
	t[x][1]=b;
	//����
	slove(lx, ly, len / 2, t[0][0], t[0][1]);
	//����
	slove(lx + len / 2, ly, len / 2, t[1][0], t[1][1]);
	//����
	slove(lx + len / 2, ly + len / 2, len / 2, t[2][0], t[2][1]);
	//����
	slove(lx, ly + len / 2, len / 2, t[3][0], t[3][1]);
	return ;
}
int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//cout.tie(0);
	cin >> A >> B >> len;
	arr[A][B] = -1;
	slove(1, 1, len, A, B);
	out();
	return 0;
}
