/*

���ȣ���Ҫ����Ŀ�г����һ���Ա��� x��һ������ x �ĺ��� f(x)��
�Լ�һ��Ŀ��ֵ target��
ͬʱ��x, f(x), target ��Ҫ��������������
1��f(x) �������� x �ϵĵ��������������������������ԣ���
2����Ŀ�������������Լ������ f(x) == target ʱ�� x ��ֵ��

	���ִ�,�Ҳ�
while(r-l>eps)//epsΪ����
{
    mid=(l+r)/2;
    if(check(mid))
        l=mid;
    else
        r=mid;
}


                ����ֵ
binary_search���ڷ���1,�����ڷ���0
lower_bound���ص�һ�����ڵ�����Ҫ���ҵ��������ĵ�ַ
upper_bound���ص�һ��������Ҫ���ҵ��������ĵ�ַ
//������ֿ�����:�����targetС��Ԫ�ظ���  lowe_bound(i) ���ص��Ǽ�ֵΪi��Ԫ���ܹ������λ�õĵ�һ��λ��(�½�)��
//���Ҷ��ֿ�����:���С�ڵ���target��Ԫ�ظ���  upper_bound(i) ���ص��Ǽ�ֵΪi��Ԫ���ܹ���������һ��λ��(�Ͻ�)

                ���ҵ���������ʱ
upper_bound(i) ���ص��Ǽ�ֵΪi��Ԫ���ܹ���������һ��λ��(�Ͻ�)
lowe_bound(i) ���ص��Ǽ�ֵΪi��Ԫ���ܹ������λ�õĵ�һ��λ��(�½�)��

                ��ͨ����
while��<=��ζ�����˱�,rӦΪ�������һ���±�ֵ
        <��©������right,�򲹶�
        return nums[left] == target ? left : -1;

                lower_bound
���Խ��,���ر�Ŀ����Ԫ���м���
<����ҿ� ������l==r
        if (left == nums.length) return -1;//��Խ��
        return left;
<=���˱� ����ʱl=r+1
        if (left >= nums.length || nums[left] != target)  //��Խ��
        return -1;
        return left;

                upper_bound
<����ҿ� ������l==r
        return left - 1;
        ��Ϊ���Ƕ� left �ĸ��±����� left = mid + 1��
        ����˵ while ѭ������ʱ��
        nums[left] һ��������target �ˣ�
        �� nums[left-1] ������ target��
<=���˱� ����ʱl=r+1
        �� target ������Ԫ�ض�Сʱ��right �ᱻ���� -1��������Ҫ������ֹԽ�磺
        if (right < 0 || nums[right] != target) {
        return -1;
        }
        return right;


bool cmp(const int &a,const int &b){return a>b;}
���磬Ҫa[]�����У���[1,n]�е�һ��С��s�������±�
pos=lower_bound(a+1,a+n+1,s��cmp)-a;
*/

//������ֿ�����:���targetС��Ԫ�ظ���
//�������˱�
int left_bound(int nums[], int target, int numslength)
{
    int left = 0, right = numslength - 1;
    // ��������Ϊ [left, right]
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) // target�ܴ�ʱ,l���r+1
            left = mid + 1;
        else if (nums[mid] > target) // target��Сʱ,r���-1
            right = mid - 1;
        else if (nums[mid] == target)
            right = mid - 1;
    }
    if (left >= numslength) // ���������
        return -1;
    if (nums[left] != target) //û�ҵ����������targetС��Ԫ�ظ���
        return -1;            //�����Ϊ-1
    return left;
}

//����,����ҿ�
int lower(int a[], int x, int len)
{
    int l = 0, r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x) //���ұ߽�
            r = mid;
        else if (a[mid] > x) // target,r,l��СΪ0
            r = mid;
        else if (a[mid] < x) // target�ܴ�ʱ,l=r=len
            l = mid + 1;
    }
    //����ʱʼ��l==r
    if (l == len) //Խ��,l��r���Ϊlen
        return -1;
    if (a[l] != x) //������ʱ,�������С��Ԫ�ظ���
        return -1;
    return l;
}

//���Ҷ��ֿ�����:���С�ڵ���target��Ԫ�ظ���
//�Ҳ࣬���˱�
int right_bound(int nums[], int target, int numslength)
{
    int left = 0, right = numslength - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) //target�ܴ�ʱ,l=r�ĳ�ʼֵ+1,r��Ϊ��ʼֵ
            left = mid + 1;
        else if (nums[mid] > target) // target��Сʱ,r=-1
            right = mid - 1;
        else if (nums[mid] == target) //����ҵ�,l��+1,��r����
            left = mid + 1;
    }
    // l=r+1
    //l��ʾС�ڵ���target��Ԫ�ظ���
    //r��ʾ=targetԪ�����Ҳ���±�,λ��
    if (right < 0 || left>=numslength)
    {
        return -1;
    }
    return right;
}

//�Ҳ࣬����ҿ�
int upper(int a[], int x, int len)
{
    int l = 0, r = len;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x) //����ҵ�,�����ص�һ����x������±�
            l = mid + 1;
        else if (a[mid] > x) // r,l��С����0
            r = mid;
        else if (a[mid] < x) // x�ܴ�ʱ,l�ݼӵ�==r
            l = mid + 1;
    }
    // l==r
    if (a[l - 1] == x) //����ҵ�,�����ص�һ����x������±�
                       // ����˵��С�ڵ���target��Ԫ�ظ���
        return l - 1;  //-1��ΪҪ�ҵ���λ��
    return l;
}
