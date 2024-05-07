//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int search_bin(int arr[], int key, int sz)
//{
//	int left = 0; //���±�
//	int right = sz - 1;//���±�
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
//			printf("�ҵ��ˣ��±�Ϊ��%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("û�ҵ�\n");
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
////�ڲ�ʹ�õݹ�
//void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex) {
//    int midIndex;
//    if (startIndex < endIndex) {
//        midIndex = startIndex + (endIndex - startIndex) / 2;//�������int
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
const int MAXN = 1000, INF = 0x3f3f3f3f;//����һ��INF��ʾ�����
int g[MAXN][MAXN], dist[MAXN], n, m, res;
bool book[MAXN];
void prim()
{
    dist[1] = 0;                                                                                                                                                                                            //�ѵ�1���뼯��S����1�ڼ���S�У����������ϵľ����ʼ��Ϊ0
    book[1] = true;                                                                                                                                                                 //��ʾ��1�Ѿ����뵽��S������
    for (int i = 2; i <= n; i++)dist[i] = min(dist[i], g[1][i]);                                                                                                              //�õ�1ȥ����dist[]
    for (int i = 2; i <= n; i++)
    {
        int temp = INF;                                                                                                                                                                      //��ʼ������
        int t = -1;                                                                                                                                                                   //������ȥѰ���뼯��S����ĵ���뵽�����У���t��¼�������±ꡣ
        for (int j = 2; j <= n; j++)
        {
            if (!book[j] && dist[j] < temp)                                                                                                                                               //��������û�м��뼯��S����������㵽���ϵľ���С��temp�ͽ��±긳��t
            {
                temp = dist[j];                                                                                                                                         //���¼���V������S����Сֵ
                t = j;                                                                                                                                                      //�ѵ㸳��t
            }
        }
        if (t == -1) { res = INF; return; }
                                                                                                                                                                                          //���t==-1����ζ���ڼ���V�Ҳ��������򼯺�S������������ʧ�ܣ���res��ֵ�������ʾ����ʧ�ܣ���������
        book[t] = true;                                                                                                                                                                             //����ҵ�������㣬�Ͱ������뼯��S
        res += dist[t];                                                                                                                                                     //��������㵽����S�ľ���
        for (int j = 2; j <= n; j++)dist[j] = min(dist[j], g[t][j]);                                                                                                                    //���¼���ĵ����dist[]
    }
}
int main()
{
    cin >> n >> m;  //�������ͼ�ĵ���n�ͱ���m
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = INF;//��ʼ������������֮��ľ���Ϊ�������ʾ��������֮��û�бߣ�
        }
        dist[i] = INF;                                                                                                                                                                                          //��ʼ�����е㵽����S�ľ��붼��������
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;//����a��b������֮��ı�
        g[a][b] = g[b][a] = w;                                                                                                                                                                                                              //����������ߣ����Ƕ�g[a][b]��g[b][a]��Ҫ��ֵ
    }
    prim();                                                                                                                                                                                 //����prim����
    if (res == INF)//���res��ֵ���������ʾ���ܸ�ͼ����ת����һ���������orz
        cout << "orz";
    else
        cout << res;//�����������res    
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
//    //��ʼ��
//    for (i = 1; i <= n; i++)
//        for (j = 1; j <= n; j++)
//            if (i == j) e[i][j] = 0;
//            else e[i][j] = inf;
//    //�����
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
//    //Dijkstra�㷨�������
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
//	char Vexnum[MAX]; //ͼ�Ķ�����Ϣ
//	int arc[MAX][MAX];//��ά����洢����֮��ıߵ�Ȩֵ��Ϣ
//	int vexnum;//ͼ�Ķ�����
//	int edgenum;//ͼ�ı���
//};
////����ͼ
//void CreatM(Mgraph& G)
//{
//	int i, j, w;
//	cout << "������ͼ�Ķ������ͱ���" << endl;
//	cin >> G.vexnum >> G.edgenum;
//	cout << "�����붥����Ϣ" << endl;
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		cin >> G.Vexnum[i];
//	}
//	//��ʼ����ά����ıߵ�ȨֵΪINF
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			if (i == j) G.arc[i][j] = 0;
//			else G.arc[i][j] = INF;
//		}
//	}
//	//���Ķ�ά�����бߵ�ȨֵΪ���������Ȩֵ
//	for (int k = 0; k < G.edgenum; k++)
//	{
//		cin >> i >> j >> w;
//		G.arc[i][j] = w;
//	}
//}
//void MyPrint(Mgraph G) {
//	cout << "������ͼ���ڽӾ���������ʾ�� " << endl;
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			cout << G.arc[i][j] << "   ";
//		}
//		cout << endl;
//	}
//}
////��dist��������s[i] = 0,Ȩֵ��С�������±ꡣ
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
////�㷨����
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