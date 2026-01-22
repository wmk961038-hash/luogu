#include <bits/stdc++.h>
using namespace std;
long long a_n(long long* a,int n)
{
    long long ans=1;
    for(int i=1;i<=n/2;i++)
    {
        ans+=a[i];
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int count = 1;
    int temp_first = n;
    // 从1开始计算，保存每一个an的值，然后在最后到达终点n的时候使用
    long long a[1001];
    a[1] = 1;
    for(int i=2;i<=n;i++)
    {
        a[i]=a_n(a,i);
    }
    cout<<a[n];
    return 0;
}
