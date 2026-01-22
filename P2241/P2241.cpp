#include <bits/stdc++.h>
using namespace std;
struct rectangle
{
    int length;
    int wide;
};
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
long long cal_rectangle(int a_small, int a_big)
{
    // 找出所有可以在长方形中存在的表示小长方形的数对
    int count = 0;
    if (a_small > a_big)
        swap(&a_small, &a_big);
    vector<rectangle> rectangles;
    for (int b_small = 1; b_small <= a_small; b_small++)
    {
        for (int b_big = b_small + 1; b_big <= a_big; b_big++)
        {
            rectangle temp_rec;
            temp_rec.length = b_small;
            temp_rec.wide = b_big;
            rectangles.push_back(temp_rec);
            if (b_big <= a_small && b_small <= a_big)
            {
                rectangle temp_rec;
                temp_rec.length = b_big;
                temp_rec.wide = b_small;
                rectangles.push_back(temp_rec);
            }
        }
    }
    for(int i=0;i<rectangles.size();i++)
    {
        count+=(a_small-rectangles[i].length+1) * (a_big-rectangles[i].wide+1);
    }
    return count;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << cal_square(a, b) << ' ' << cal_rectangle(a, b);
    return 0;
}