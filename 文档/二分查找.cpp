/*

首先，你要从题目中抽象出一个自变量 x，一个关于 x 的函数 f(x)，
以及一个目标值 target。
同时，x, f(x), target 还要满足以下条件：
1、f(x) 必须是在 x 上的单调函数（单调增单调减都可以）。
2、题目是让你计算满足约束条件 f(x) == target 时的 x 的值。

	二分答案,右侧
while(r-l>eps)//eps为精度
{
    mid=(l+r)/2;
    if(check(mid))
        l=mid;
    else
        r=mid;
}


                返回值
binary_search存在返回1,不存在返回0
lower_bound返回第一个大于等于需要查找的数的数的地址
upper_bound返回第一个大于需要查找的数的数的地址
//向左二分看做是:输出比target小的元素个数  lowe_bound(i) 返回的是键值为i的元素能够插入的位置的第一个位置(下界)。
//向右二分看做是:输出小于等于target的元素个数  upper_bound(i) 返回的是键值为i的元素能够插入的最后一个位置(上界)

                查找的数不存在时
upper_bound(i) 返回的是键值为i的元素能够插入的最后一个位置(上界)
lowe_bound(i) 返回的是键值为i的元素能够插入的位置的第一个位置(下界)。

                普通二分
while中<=意味着两端闭,r应为数组最后一个下标值
        <会漏掉索引right,打补丁
        return nums[left] == target ? left : -1;

                lower_bound
检查越界,返回比目标大的元素有几个
<左闭右开 结束是l==r
        if (left == nums.length) return -1;//防越界
        return left;
<=两端闭 结束时l=r+1
        if (left >= nums.length || nums[left] != target)  //防越界
        return -1;
        return left;

                upper_bound
<左闭右开 结束是l==r
        return left - 1;
        因为我们对 left 的更新必须是 left = mid + 1，
        就是说 while 循环结束时，
        nums[left] 一定不等于target 了，
        而 nums[left-1] 可能是 target。
<=两端闭 结束时l=r+1
        当 target 比所有元素都小时，right 会被减到 -1，所以需要在最后防止越界：
        if (right < 0 || nums[right] != target) {
        return -1;
        }
        return right;


bool cmp(const int &a,const int &b){return a>b;}
比如，要a[]数组中，从[1,n]中第一个小于s的数的下标
pos=lower_bound(a+1,a+n+1,s，cmp)-a;
*/

//向左二分看做是:输出target小的元素个数
//向左，两端闭
int left_bound(int nums[], int target, int numslength)
{
    int left = 0, right = numslength - 1;
    // 搜索区间为 [left, right]
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) // target很大时,l变成r+1
            left = mid + 1;
        else if (nums[mid] > target) // target很小时,r变成-1
            right = mid - 1;
        else if (nums[mid] == target)
            right = mid - 1;
    }
    if (left >= numslength) // 检查出界情况
        return -1;
    if (nums[left] != target) //没找到将会输出比target小的元素个数
        return -1;            //这里改为-1
    return left;
}

//向左,左闭右开
int lower(int a[], int x, int len)
{
    int l = 0, r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x) //缩右边界
            r = mid;
        else if (a[mid] > x) // target,r,l最小为0
            r = mid;
        else if (a[mid] < x) // target很大时,l=r=len
            l = mid + 1;
    }
    //跳出时始终l==r
    if (l == len) //越界,l和r最大为len
        return -1;
    if (a[l] != x) //不存在时,输出比其小的元素个数
        return -1;
    return l;
}

//向右二分看做是:输出小于等于target的元素个数
//右侧，两端闭
int right_bound(int nums[], int target, int numslength)
{
    int left = 0, right = numslength - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) //target很大时,l=r的初始值+1,r仍为初始值
            left = mid + 1;
        else if (nums[mid] > target) // target很小时,r=-1
            right = mid - 1;
        else if (nums[mid] == target) //如果找到,l将+1,但r不会
            left = mid + 1;
    }
    // l=r+1
    //l表示小于等于target的元素个数
    //r表示=target元素最右侧的下标,位置
    if (right < 0 || left>=numslength)
    {
        return -1;
    }
    return right;
}

//右侧，左闭右开
int upper(int a[], int x, int len)
{
    int l = 0, r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x) //如果找到,将返回第一个比x大的数下标
            l = mid + 1;
        else if (a[mid] > x) // r,l最小等于0
            r = mid;
        else if (a[mid] < x) // x很大时,l递加到==r
            l = mid + 1;
    }
    // l==r
    if (a[l - 1] == x) //如果找到,将返回第一个比x大的数下标
                       // 或者说是小于等于target的元素个数
        return l - 1;  //-1后即为要找的数位置
    return l;
}
