#include <iostream>
#include <algorithm>
using namespace std;
class Time // 时刻
{
public:
    int h;
    int m;
    Time()
    {
        h = -1;
        m = 0;
    }
    void clear()
    {
        h = -1;
        m = 0;
    }
    int over(string t, int &size) // 计算借书时间
    {
        if (h == -1)
            return 0;
        size++;
        int th = (t[0] - '0') * 10 + t[1] - '0';
        int tm = (t[3] - '0') * 10 + t[4] - '0';
        if (th == 0 && tm == 0)
            th = 24;
        clear();
        return ((th - h) * 60 + tm - m);
    }
    void set(string t)
    {
        h = (t[0] - '0') * 10 + t[1] - '0';
        m = (t[3] - '0') * 10 + t[4] - '0';
    }
    void set(int a, int b)
    {
        h = a;
        m = b;
    }
    Time(int a, int b)
    {
        set(a, b);
    }
    Time operator-(const Time &a) const // 返回两段时间的差距
    {
        return Time((h - a.h + 24) % 24, (m - a.m + 60) % 60);
    }
};
int day = 1;
int ans[11] = {}; // 每天的平均借书时间
Time book[1001] = {};
double ceil(double x)
{
    // cout<<"\nx="<<x<<"\n";
    if (x - (long)x >= 0.5)
        return (long)x + 1;
    return x;
}
int main()
{
    // freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
    int n;
    cin >> n;
    int a;
    char b;
    string c;
    int st = 0, size = 0; // 当天借书时间,次数
    // for (int i = 0; i < n; i++)
    while (day <= n)
    {
        cin >> a >> b >> c;
        if (a == 0) // 一天结束
        {
            // 处理当天数据
            if (size == 0)
                cout << 0 << ' ' << 0 << '\n';
            else
            {
                ans[day] = ceil(1.0 * st / size);
                cout << size << " " << ans[day] << "\n";
            }
            // 进入下一天
            day++;
            for (int j = 0; j < 1001; j++)
            {
                book[j].clear();
            }
            size = 0;
            st = 0;
        }
        else if (b == 'S') // 入栈一个借书开始的时间
        {
            book[a].set(c);
        }
        else if (b == 'E')
        {
            st += book[a].over(c, size);
        }
    }
    //   int h1 = (t[0] - '0') * 10 + t[1] - '0';
    //     int h2 = (a.t[0] - '0') * 10 + a.t[1] - '0';
    //     int m1 = (t[3] - '0') * 10 + t[4] - '0';
    //     int m2 = (a.t[3] - '0') * 10 + a.t[4] - '0';
    //     h1=(h1-h2+24)%24;
    return 0;
}