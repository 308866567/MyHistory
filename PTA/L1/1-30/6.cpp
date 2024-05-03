#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int i = a, j = b;
    int ans = 0;
    int h = 0;
    while (i <= j)
    {
        if (h > 4&&i!=j)
        {
            h = 0;
            printf("\n");
        }
        printf("%5d", i);
        ans += i;
        h++;
        i++;
    }
    printf("\nSum = %d", ans);
    return 0;
}