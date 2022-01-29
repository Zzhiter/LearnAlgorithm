#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 50010;

int n;
string a[N], b[N], c[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        b[i] = c[i] = a[i];
        sort(b[i].begin(), b[i].end(), greater<char>()); //对每个字符串进行排序，按照逆字典序
        sort(c[i].begin(), c[i].end());
    }

    sort(b + 1, b + n + 1); //b是存放的字典序最大的情况
    sort(c+1, c+n+1); //c存放字典序最小的情况

    for(int i=1; i<=n; i++)
    {
        sort(a[i].begin(), a[i].end());  //先让a[i]的字典序最小
        int l=1, r=n;
        // 先升序处理，利用二分在降序数组里查找第一个字典序大于等于升序处理后的s的位置
        // 此时的位置就是s可能的最前位置。
        while(l<r) //先找字典序最小的位置，那就是前边的那些串的字典序都是最大
        {
            // 找到>=a[i]最小的位置
            int mid = l+r>>1;
            if(b[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }

        cout << l <<' ';
        reverse(a[i].begin(), a[i].end()); //再让a[i]的字典序最大
        l = 1, r = n;
        while(l<r) //找字典序最大的位置，那就是其他的字符串字典序最小
        {
            //找到<=a[i]最大的位置
            int mid = l + r + 1 >> 1;
            if (c[mid] <= a[i]) l = mid;
            else r = mid - 1;
        }
        cout << r << endl;
    }
    return 0;
}
原题链接：https://www.acwing.com/problem/content/description/1998/
作者：sailor
题解链接：https://www.acwing.com/solution/content/88269/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。