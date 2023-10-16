//#include <iostream>
//using namespace std;
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//
//	return 0;
//}
//void Print()
//{
//	cout << _year << _month << _day;
//}
//class Date
//{
//public:
//	Date(int year=2023 , int month = 9, int day = 9)//ȫȱʡ
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout <<"ʱ�䣺"<< year << "-" << month << "-" << day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2020);  //���δ�������
//	Date d2(2021, 1);
//	Date d3(2022, 1, 1);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	cout << &a << endl;
//	a = 20;
//	cout << &a << endl;
//	const int b = 30;
//	cout << &b << endl;
//	return 0;
//}
#include <iostream>
using namespace std;
/*
void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void Sort(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n - i; j++)
        {
            if (a[j] < a[j - 1])
            {
                Swap(&a[j], &a[j - 1]);
            }
            cout << a[j] << endl;
        }
    }
}
int main() {
    int n = 0, b = 0;
    cin >> n;
    int* a = (int*)malloc(sizeof(int) * 3 * n);
    int i = 0;
    n *= 3;
    while (n--)
    {
        cin >> b;
        a[i] = b;
        ++i;
    }
    Sort(a, n);
    int left = 0;
    int right = n - 1;
    int sum = 0;
    while (left < right)
    {
        sum += right - 1;
        left++;
        right -= 2;
    }
    printf("%lld", sum);
    free(a);
    a = nullptr;
}
*/
/*
bool is_exist(char* a,char b[],int sz)
{
    for(int i=0;i<sz;i++)
    {
        if(*a==b[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char a[20];
    char b[20];
    gets(a);
    gets(b);
    int i=0;
    int sz1=sizeof(a)/sizeof(a[0]);
    int sz2=sizeof(b)/sizeof(b[0]); 
    cout<<sz1<<endl;
    cout<<sz2<<endl;
    while(a[i]!='\0')
    {
        if(is_exist(&a[i],b,sz2))
        {
        for(int j=i;j<sz1-1;j++)
        {
            a[j]=a[j+1];
        }
        }
        i++;
    }
    printf("%s",a);
    getchar();
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int Pow(int a,int n)//求a的n次方
{
    int b=1;
    if(n==0)
        return 1;
    for(int i=0;i<n;i++)
    {
        b*=a;
    }
    return b;
}
int main() {
    int num,n;
    cin>>num>>n;
    int quo=num/n;//商
    int ret=0;
    int mod=num%n;
    int i=0;
    int sign=0;
    do
    {
        ret=ret+mod*Pow(10,i);
        mod=quo%n;
        quo=quo/n;
        i++;
        sign=1;
    }while(quo);
    if(sign==1)
    {
        ret=ret+mod*Pow(10,i);
    }
    getchar();
    cout<<ret;
    getchar();
    return 0;
}
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//bool is_palin(string m)
//{
//    string n=m;
//    reverse(n.begin(),n.end());
//    if(m==n)
//        return true;
//    else
//        return false;
//}
//int main()
//{
//    string a,b,c;
//    cin>>a>>b;
//    int sz=a.size();
//    int count=0;
//    for(int i=0;i<=sz;i++)
//    {
//        string d=a;
//        d.insert(i,b);  
//        cout<<d<<endl;
//        if(is_palin(d))
//        {
//            count++;
//        }
//    }
//    getchar();
//    cout<<count;
//    getchar();
//    return 0;
//}

int main()
{
    string str1;
    str1+="hello world";
    cout<<str1<<endl;
    string str2("xxxxxxxxxx");
    str1.insert(5,str2);
    cout<<str1<<endl;
    getchar();
    return 0;
}