//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int search_bin(int arr[], int key, int sz)
//{
//	int left = 0; //左下标
//	int right = sz - 1;//右下标
//	int mid = 0;
//	int k = key;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标为：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("没找到\n");
//		return -1;
//	}
//
//	return 0;
//}
//int main()
//{
//	int arr[8] = { 1,3,5,7,8,9,10,15 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	search_bin(arr, 7, sz);
//	search_bin(arr, 4, sz);
//	search_bin(arr, 10, sz);
//	return 0;
//}


//#include <iostream>
//#include <stdio.h>
//using namespace std;
//void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex) {
//    int i = startIndex, j = midIndex + 1, k = startIndex;
//    while (i != midIndex + 1 && j != endIndex + 1) {
//        if (sourceArr[i] > sourceArr[j])
//            tempArr[k++] = sourceArr[j++];
//        else
//            tempArr[k++] = sourceArr[i++];
//    }
//    while (i != midIndex + 1)
//        tempArr[k++] = sourceArr[i++];
//    while (j != endIndex + 1)
//        tempArr[k++] = sourceArr[j++];
//    for (i = startIndex; i <= endIndex; i++)
//        sourceArr[i] = tempArr[i];
//}
//
////内部使用递归
//void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex) {
//    int midIndex;
//    if (startIndex < endIndex) {
//        midIndex = startIndex + (endIndex - startIndex) / 2;//避免溢出int
//        MergeSort(sourceArr, tempArr, startIndex, midIndex);
//        MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
//        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
//    }
//}
//
//int main(int argc, char* argv[]) {
//    int a[10] = { 2,8,4,6,1,10,7,3,5,9};
//    int i, b[10];
//    MergeSort(a, b, 0, 9);
//    for (i = 0; i < 10; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//    return 0;
//}
#include <iostream>
using namespace std;
const int MAXN = 1000, INF = 0x3f3f3f3f;//定义一个INF表示无穷大。
int g[MAXN][MAXN], dist[MAXN], n, m, res;
bool book[MAXN];
void prim()
{
    dist[1] = 0;                                                                                                                                                                                            //把点1加入集合S，点1在集合S中，将它到集合的距离初始化为0
    book[1] = true;                                                                                                                                                                 //表示点1已经加入到了S集合中
    for (int i = 2; i <= n; i++)dist[i] = min(dist[i], g[1][i]);                                                                                                              //用点1去更新dist[]
    for (int i = 2; i <= n; i++)
    {
        int temp = INF;                                                                                                                                                                      //初始化距离
        int t = -1;                                                                                                                                                                   //接下来去寻找离集合S最近的点加入到集合中，用t记录这个点的下标。
        for (int j = 2; j <= n; j++)
        {
            if (!book[j] && dist[j] < temp)                                                                                                                                               //如果这个点没有加入集合S，而且这个点到集合的距离小于temp就将下标赋给t
            {
                temp = dist[j];                                                                                                                                         //更新集合V到集合S的最小值
                t = j;                                                                                                                                                      //把点赋给t
            }
        }
        if (t == -1) { res = INF; return; }
                                                                                                                                                                                          //如果t==-1，意味着在集合V找不到边连向集合S，生成树构建失败，将res赋值正无穷表示构建失败，结束函数
        book[t] = true;                                                                                                                                                                             //如果找到了这个点，就把它加入集合S
        res += dist[t];                                                                                                                                                     //加上这个点到集合S的距离
        for (int j = 2; j <= n; j++)dist[j] = min(dist[j], g[t][j]);                                                                                                                    //用新加入的点更新dist[]
    }
}
int main()
{
    cin >> n >> m;  //读入这个图的点数n和边数m
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = INF;//初始化任意两个点之间的距离为正无穷（表示这两个点之间没有边）
        }
        dist[i] = INF;                                                                                                                                                                                          //初始化所有点到集合S的距离都是正无穷
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;//读入a，b两个点之间的边
        g[a][b] = g[b][a] = w;                                                                                                                                                                                                              //由于是无向边，我们对g[a][b]和g[b][a]都要赋值
    }
    prim();                                                                                                                                                                                 //调用prim函数
    if (res == INF)//如果res的值是正无穷，表示不能该图不能转化成一棵树，输出orz
        cout << "orz";
    else
        cout << res;//否则就输出结果res    
    return 0;
}

//#include <stdio.h>
//#include<iostream>
//using namespace std;
//int main()
//{
//    int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
//    int inf = 99999999; 
//    cin >> n >> m;
//    //初始化
//    for (i = 1; i <= n; i++)
//        for (j = 1; j <= n; j++)
//            if (i == j) e[i][j] = 0;
//            else e[i][j] = inf;
//    //读入边
//    for (i = 1; i <= m; i++)
//    {
//        cin >> t1 >> t2 >> t3;
//        e[t1][t2] = t3;
//    }
//    for (i = 1; i <= n; i++)
//        dis[i] = e[1][i];
//    for (i = 1; i <= n; i++)
//        book[i] = 0;
//    book[1] = 1;
//    //Dijkstra算法核心语句
//    for (i = 1; i <= n - 1; i++)
//    {
//        min = inf;
//        for (j = 1; j <= n; j++)
//        {
//            if (book[j] == 0 && dis[j] < min)
//            {
//                min = dis[j];
//                u = j;
//            }
//        }
//        book[u] = 1;
//        for (v = 1; v <= n; v++)
//        {
//            if (e[u][v] < inf)
//            {
//                if (dis[v] > dis[u] + e[u][v])
//                    dis[v] = dis[u] + e[u][v];
//            }
//        }
//    }
//
//    for (i = 1; i <= n; i++)
//        printf("%d ", dis[i]);
//
//    cout << "5 11" << endl;
    //cout << "0 1 3" << endl;
    //cout << "0 2 11" << endl;
    //cout << "1 0 2" << endl;
    //cout << "1 2 5" << endl;
    //cout << "1 3 13" << endl;
    //cout << "1 4 7" << endl;
    //cout << "2 4 12" << endl;
    //cout << "3 1 8" << endl;
    //cout << "3 4 4" << endl;
    //cout << "4 2 6" << endl;
    //cout << "4 3 3" << endl;


#include<iostream>
//using namespace std;
//#define MAX 9
//#define INF 9999
//typedef struct Mgraph {
//	char Vexnum[MAX]; //图的顶点信息
//	int arc[MAX][MAX];//二维数组存储顶点之间的边的权值信息
//	int vexnum;//图的顶点数
//	int edgenum;//图的边数
//};
////创建图
//void CreatM(Mgraph& G)
//{
//	int i, j, w;
//	cout << "请输入图的顶点数和边数" << endl;
//	cin >> G.vexnum >> G.edgenum;
//	cout << "请输入顶点信息" << endl;
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		cin >> G.Vexnum[i];
//	}
//	//初始化二维数组的边的权值为INF
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			if (i == j) G.arc[i][j] = 0;
//			else G.arc[i][j] = INF;
//		}
//	}
//	//更改二维数组中边的权值为输入进来的权值
//	for (int k = 0; k < G.edgenum; k++)
//	{
//		cin >> i >> j >> w;
//		G.arc[i][j] = w;
//	}
//}
//void MyPrint(Mgraph G) {
//	cout << "创建的图的邻接矩阵如下所示： " << endl;
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			cout << G.arc[i][j] << "   ";
//		}
//		cout << endl;
//	}
//}
////在dist数组中找s[i] = 0,权值最小的数组下标。
//int FindMinDist(int* pdist, int* s, Mgraph G) {
//	int num = G.vexnum;
//	int min = INF;
//	for (int i = 0; i < num; i++)
//	{
//		if (pdist[i] < min && s[i] == 0)
//		{
//			min = i;
//		}
//	}
//	return min;
//}
////算法核心
//void Dijkstra(Mgraph G, int v) {
//	int num = 0;
//	int min = 0;
//	int s[MAX];
//	int dist[MAX];
//	int path[MAX];
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		dist[i] = G.arc[v][i];
//		if (dist[i] != INF) path[i] = v;
//		else path[i] = -1;
//	}
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		s[i] = 0;
//	}
//	s[v] = 1;
//	num = 1;
//	while (num < G.vexnum)
//	{
//		min = FindMinDist(dist, s, G);
//		s[min] = 1;
//		for (int i = 0; i < G.vexnum; i++)
//		{
//			if (s[i] == 0 && (dist[i] > dist[min] + G.arc[min][i]))
//			{
//				dist[i] = dist[min] + G.arc[min][i];
//				path[i] = min;
//			}
//
//		}
//		num++;
//	}
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		cout << dist[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		cout << path[i] << " ";
//	}
//}
//int main() {
//	Mgraph G;
//	CreatM(G);
//	//MyPrint(G);
//	Dijkstra(G, 0);
//	return 0;
//}
//int main()
//{
//
//    cout << "11" << endl;
//
//    return 0;
//}