#include <iostream>
#include <vector>
#include <string>
using namespace std;
class KMP
{
public:
    string pat = "ababc"; //ģ�崮,��ҪѰ�ҵ��ַ���
    string txt;           //�ܴ�
    long N, M;
    vector<vector<int>> dp; //״̬ת��,next����
    vector<int> next;
    // next �����ֵ�ĺ��壺����ǰ�ַ�֮ǰ���ַ����У��ж�󳤶ȵ���ͬǰ׺��׺
    // j ֮ǰ���ַ���������󳤶�Ϊ k ����ͬǰ׺��׺��
    KMP(string &a, string &b) //���캯��
    {
        txt = a;
        pat = b;
        N = txt.size();
        M = pat.size();
        next.resize(M + 1, 0); // pat��M���ַ�
        NEXT();
    }
    void NEXT() //��ֵnext����
    {
        // ʧ��ʱ��ģʽ��P������ı���S�����ƶ���j - next [j] λ�� 
        long k = -1, j = 0; // k��ʾ��ǰ״̬,j��ʾ��ǰ�ַ�λ��,-1<=k<M
        next[0] = -1;       // next+1��ʾǰ׺�ͺ�׺��ͬ�ĳ���
        // next��ʾӦ���˵�״̬
        //-1��ʾδƥ�����ַ�,0��ʾƥ����һ���ַ�
        while (j <= M)
        {
            if (k == -1 || pat[j] == pat[k])
            {
                ++k;
                ++j;
                next[j] = k;
            }
            else
                k = next[k]; //���˺��״̬����ٴ�ʧ�ܻ��˵�����
        }
        // for (int i : next)
        // {
        //     cout << i << " ";
        // }
    }
    long kmpsearch()
    {
        int j = 0; //��ʾƥ���˼����ַ�
        for (int i = 0; i < N; i++)
        {
            if (txt[i] == pat[j])
            {
                j++;
                i++;
            }
            else
            {
                j = next[j];
            }
            if (j == M)
            {
                return i - M + 1; //ƥ�䵽���ַ�����ͷ������,�����0��ʼ
            }
        }
        return N;
    }
    void dpout(int &i)
    {
        for (int j = 'A'; j <= 'Z'; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    void Dp() //����dp����
    {
        // dp[j][c] = next
        // 0 <= j < M������ǰ��״̬
        // 0 <= c < 256�������������ַ���ASCII �룩
        // 0 <= next <= M��������һ��״̬
        // dp[4]['A'] = 3 ��ʾ��
        // ��ǰ��״̬ 4����������ַ� A��
        // pat Ӧ��ת�Ƶ�״̬ 3
        vector<int> temp;
        next.resize(pat.size() + 1);
        int M = pat.length();
        temp.resize(257, 0);
        dp.resize(pat.size() + 1, temp); // 0~pat.size()��״̬,��ʾ�Ѿ�ƥ������j���ַ�
        dp[0][(int)pat[0]] = 1;          //��һ���ַ�Ϊ1,��ʼ״̬
        int x = 0;                       // x����:ǰ׺�ͺ�׺��ͬ���ַ���
        for (int i = 1; i < M; i++)      // M��,�Ѿ�ƥ����i���ַ�
        {
            for (int j = 0; j < 256; j++) // 256��ASCII���ַ�
            {
                if (j == (int)pat[i]) //״̬ǰ��
                    dp[i][j] = i + 1;
                else
                    dp[i][j] = dp[x][j]; // i�ַ�ƥ��ʧ��,��[1~i-1]�Ӵ���patƥ��
                //��һ���ַ�ʼ���ǻ��˵�0״̬,��dp[0]�����ʼΪ0
                // x��¼��[1~i-1]�Ӵ���patƥ��ɹ��ĸ���,i-1��pat[0]ƥ��
                // i-1->1 1���Ѿ�0~i,0~i-1�Ѿ��жϹ�,i-1����Ϊ1~i-1δ�жϹ�
                // 0->pat.size()
            }
            dpout(i);
			//X ��ʾ��ǰ״̬��ƥ��ʧ��Ҫ��ת����״̬
            x = dp[x][(int)pat[i]]; //����Ӱ��,x����ƥ��һλ,�õ�����ǰ�Ľ���Ƴ���һ��״̬�ķ���ֵ
            // x�õ�����һ���Ӵ������i-1,�������,�͸������,����i-1��ǰƥ����ͬ��
            //  ��ǰ��״̬ X�������ַ� pat[i]
            //  Ӱ��״̬������ǰ�ַ��Ƿ����ǰ��,������о�ת��
            next[i] = x; //ÿ�ε�x��next[i]��ֵ
        }
    }
    long dpsearch()
    {
        int M = pat.length();
        int N = txt.length();
        int j = 0; //��ʾƥ���˼����ַ�
        for (int i = 0; i < N; i++)
        {
            j = dp[j][(int)txt[i]];
            if (j == M)
            {
                return i - M + 1; //ƥ�䵽���ַ�����ͷ������,�����0��ʼ
            }
        }
        return N;
    }
};
int main()
{
    freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    string a, b;
    cin >> a >> b;
    KMP x(a, b);
    return 0;
}
