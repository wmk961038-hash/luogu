#include <bits/stdc++.h>
using namespace std;
int the_smaller_of(int a, int b)
{
    return a > b ? b : a;
}
long long cal_square(int length, int wide)
{
    int count = 0;
    for (int i = 1; i <= the_smaller_of(length, wide); i++)
    {
        count += (length - i + 1) * (wide - i + 1);
    }
    return count;
}
void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}
long long cal_every(int length, int wide)
{
    int count=0;
    for(int i=1;i<=length;i++)
    {
        for(int j=1;j<=wide;j++)
        {
            count+=(length-i+1)*(wide-j+1);
        }
    }
    return count;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << cal_square(a, b) << ' ' << cal_every(a, b)-cal_square(a, b);
    return 0;
}