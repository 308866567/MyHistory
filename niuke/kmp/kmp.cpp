#include <iostream>
#include <vector>
#include <string>
using namespace std;
class KMP
{
public:
    string pat = "ababc"; //模板串,需要寻找的字符串
    string txt;           //总串
    long N, M;
    vector<vector<int>> dp; //状态转移,next数组
    vector<int> next;
    // next 数组各值的含义：代表当前字符之前的字符串中，有多大长度的相同前缀后缀
    // j 之前的字符串中有最大长度为 k 的相同前缀后缀。
    KMP(string &a, string &b) //构造函数
    {
        txt = a;
        pat = b;
        N = txt.size();
        M = pat.size();
        next.resize(M + 1, 0); // pat有M个字符
        NEXT();
    }
    void NEXT() //赋值next数组
    {
        // 失配时，模式串P相对于文本串S向右移动了j - next [j] 位。 
        long k = -1, j = 0; // k表示当前状态,j表示当前字符位置,-1<=k<M
        next[0] = -1;       // next+1表示前缀和后缀相同的长度
        // next表示应回退的状态
        //-1表示未匹配上字符,0表示匹配了一个字符
        while (j <= M)
        {
            if (k == -1 || pat[j] == pat[k])
            {
                ++k;
                ++j;
                next[j] = k;
            }
            else
                k = next[k]; //回退后的状态如果再次失败回退到哪里
        }
        // for (int i : next)
        // {
        //     cout << i << " ";
        // }
    }
    long kmpsearch()
    {
        int j = 0; //表示匹配了几个字符
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
                return i - M + 1; //匹配到的字符串开头的索引,数组从0开始
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
    void Dp() //构建dp数组
    {
        // dp[j][c] = next
        // 0 <= j < M，代表当前的状态
        // 0 <= c < 256，代表遇到的字符（ASCII 码）
        // 0 <= next <= M，代表下一个状态
        // dp[4]['A'] = 3 表示：
        // 当前是状态 4，如果遇到字符 A，
        // pat 应该转移到状态 3
        vector<int> temp;
        next.resize(pat.size() + 1);
        int M = pat.length();
        temp.resize(257, 0);
        dp.resize(pat.size() + 1, temp); // 0~pat.size()个状态,表示已经匹配上了j个字符
        dp[0][(int)pat[0]] = 1;          //第一个字符为1,初始状态
        int x = 0;                       // x含义:前缀和后缀相同的字符数
        for (int i = 1; i < M; i++)      // M行,已经匹配上i个字符
        {
            for (int j = 0; j < 256; j++) // 256个ASCII码字符
            {
                if (j == (int)pat[i]) //状态前进
                    dp[i][j] = i + 1;
                else
                    dp[i][j] = dp[x][j]; // i字符匹配失败,用[1~i-1]子串与pat匹配
                //第一个字符始终是回退到0状态,而dp[0]数组初始为0
                // x记录用[1~i-1]子串与pat匹配成功的个数,i-1与pat[0]匹配
                // i-1->1 1是已经0~i,0~i-1已经判断过,i-1是因为1~i-1未判断过
                // 0->pat.size()
            }
            dpout(i);
			//X 表示当前状态下匹配失败要跳转到的状态
            x = dp[x][(int)pat[i]]; //更新影子,x往后匹配一位,用的是先前的结果推出下一个状态的返回值
            // x用的是上一个子串的起点i-1,如果不行,就更新起点,换个i-1往前匹配相同的
            //  当前是状态 X，遇到字符 pat[i]
            //  影子状态遇见当前字符是否可以前进,如果不行就转移
            next[i] = x; //每次的x是next[i]的值
        }
    }
    long dpsearch()
    {
        int M = pat.length();
        int N = txt.length();
        int j = 0; //表示匹配了几个字符
        for (int i = 0; i < N; i++)
        {
            j = dp[j][(int)txt[i]];
            if (j == M)
            {
                return i - M + 1; //匹配到的字符串开头的索引,数组从0开始
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
