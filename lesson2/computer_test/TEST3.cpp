//#include<iostream>
//using namespace std;
//char X[100];
//char Y[100];
//int c[100][100] = { 0 };//用于储存X和Y的最长公共子序列的长度
//int b[100][100] = { 0 };//记录X和Y的最长公共子序列的位置
//void LCSLength(int m, int n, char X[], char Y[], int c[][100], int b[][100])
//{
//	int i, j;
//	//先把第一行和第一列的位置全部变为0
//	for (i = 1; i <= m; i++)
//		c[i][0] = 0;
//	for (i = 1; i <= n; i++)
//		c[0][i] = 0;
//	for (i = 1; i <= m; i++)
//	{
//		for (j = 1; j <= n; j++)
//		{
//			if (X[i] == Y[j])
//			{
//				c[i][j] = c[i - 1][j - 1] + 1;
//				b[i][j] = 1;//表示最后一个元素相等
//			}
//			else if (c[i - 1][j] >= c[i][j - 1])
//			{
//				c[i][j] = c[i - 1][j];
//				b[i][j] = 2;
//			}
//			else
//			{
//				c[i][j] = c[i][j - 1];
//				b[i][j] = 3;
//			}
//		}
//	}
//}
//void LCS(int i, int j, char X[], int b[][100])
//{
//	if (i == 0 || j == 0)
//		return;
//	if (b[i][j] == 1)
//	{
//		LCS(i - 1, j - 1, X, b);
//		cout << X[i];
//	}
//	else if (b[i][j] == 2)
//	{
//		LCS(i - 1, j, X, b);
//	}
//	else
//		LCS(i, j - 1, X, b);
//}
//int main(void)
//{
//	int i, j, n, m;
//	//先输入x序列的长度在输入y序列的长度
//	//cout<<"先输入x的长度在输入y的长度"<<endl;
//	cin >> m >> n;
//	for (i = 1; i <= m; i++)//输入x序列
//		cin >> X[i];
//	for (i = 1; i <= n; i++)//输入y序列
//		cin >> Y[i];
//	cout << endl;
//	LCSLength(m, n, X, Y, c, b);
//	cout << "最长子序列的长度为：" << c[m][n];
//	cout << "最长子序列为：";
//	LCS(m, n, X, b);
//	cout << endl;
//	return 0;
//}
//




//#include<iostream>
//#include <algorithm>
//using namespace std;
//
//
//int w[5] = { 2, 2, 6, 5, 4 };			//商品的体积2、3、4、5
//int v[5] = { 6, 3, 5, 4, 6 };			//商品的价值3、4、5、6
//int bagV = 10;					        //背包大小
//int dp[5][11] = { { 0 } };			        //动态规划表
//int item[5];					        //最优解情况
//
//void findMax() {					//动态规划
//	for (int i = 1; i <= 4; i++) {
//		for (int j = 1; j <= bagV; j++) {
//			if (j < w[i])
//				dp[i][j] = dp[i - 1][j];
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//		}
//	}
//}

//void findWhat(int i, int j) {				//最优解情况
//	if (i >= 0) {
//		if (dp[i][j] == dp[i - 1][j]) {
//			item[i] = 0;
//			findWhat(i - 1, j);
//		}
//		else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
//			item[i] = 1;
//			findWhat(i - 1, j - w[i]);
//		}
//	}
//}
//
//void print() {
//	for (int i = 0; i < 5; i++) {			//动态规划表输出
//		for (int j = 0; j < 11; j++) {
//			cout << dp[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	for (int i = 0; i < 5; i++)			//最优解输出
//		cout << item[i] << ' ';
//	cout << endl;
//}

//int main()
//{
//	findMax();
//
//	findWhat(4, 10);
//
//	print();
//	cout << "最大装载价值为" << dp[4][10] << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int knapsack(int* W, int* V, int* res, int n, int C)
//{
//    int value = 0;
//    int** f = new int* [n];
//    for (int i = 0; i < n; i++)
//    {
//        f[i] = new int[C + 1];
//    }
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j <= C; j++)
//            f[i][j] = 0;
//    for (int i = 0; i < n; i++)
//    {
//        f[i][0] = 0;
//    }
//    for (int i = 1; i <= C; i++)
//    {
//        f[0][i] = (i < W[0]) ? 0 : V[0];
//    }
//    for (int i = 1; i < n; i++)
//    {
//        for (int y = 1; y <= C; y++)
//        {
//            if (y >= W[i])
//            {
//                f[i][y] = (f[i - 1][y] > (f[i - 1][y - W[i]] + V[i])) ? f[i - 1][y] : (f[i - 1][y - W[i]] + V[i]);
//            }
//            else {
//                f[i][y] = f[i - 1][y];
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < C + 1; j++)
//            cout << f[i][j] << " ";
//        cout << endl;
//    }
//    value = f[n - 1][C];
//    int j = n - 1;
//    int y = C;
//    while (j)
//    {
//        if (f[j][y] == (f[j - 1][y - W[j]] + V[j]))
//        {
//            res[j] = 1;
//            y = y - W[j];
//        }
//        j--;
//    }
//    if (f[0][y])
//    {
//        res[0] = 1;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        delete f[i];
//        f[i] = 0;
//    }
//    delete[] f;
//    f = 0;
//    return value;
//}
//void test1()
//{
//    int n, C;
//    while (cin >> n >> C)
//    {
//        int* W = new int[n];
//        int* V = new int[n];
//        int* res = new int[n];
//        for (int i = 0; i < n; i++)
//        {
//            res[i] = 0;
//        }
//        int w = 0, v = 0, i = 0;
//        while (i < n)
//        {
//            cin >> w >> v;
//            W[i] = w;
//            V[i] = v;
//            i++;
//        }
//        int value = knapsack(W, V, res, n, C);
//        cout << value << endl;
//        for (int i = 0; i < n; i++)
//            cout << res[i] << " ";
//        cout << endl;
//        delete W;
//        delete V;
//        delete res;
//    }
//}
//int main()
//{
//    test1();
//    return 0;
//}
//

#include <vector>
#include <iostream>
using namespace std;
//负责放置皇后的函数
//void place(vector<vector<int>>& chess, int& count, int& number, int size, int start);
//int main()
//{
//    int n = 8;  //棋盘大小
//    vector<vector<int>> chess;
//    chess.reserve(n);
//    vector<int> temp(n, 0);
//    //初始化棋盘为全0
//    for (int i = 0; i < n; ++i)
//    {
//        chess.push_back(temp);
//    }
//    int count = 0;  //计数器
//    int number = n; //剩余需要放置的皇后数量，为零时表示成功，计数器加1
//    //开始放置
//    place(chess, count, number, n, 0);
//
//    cout << count << endl;
//
//}
////判断该位置是否可以放置
//bool isSafe(const vector<vector<int>>& chess, int i, int j);
//
////start代表下一个放置点开始的行数，为上一个放置点的下一行。避免出现计入重复的情况
//void place(vector<vector<int>>& chess, int& count, int& number, int n, int start)
//{
//
//
//    //遍历所有点
//    for (int i = start; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            //该点可以放置
//            if (chess[i][j] == 0 && isSafe(chess, i, j))
//            {
//                chess[i][j] = 1;
//
//                --number;
//                //全部放完，计数器加1，回溯状态。寻找下一种可能，因为最后一个肯定只有一种可能，所以直接return
//                if (number == 0)
//                {
//                    ++count;
//                    chess[i][j] = 0;
//                    ++number;
//
//
//                    return;
//                }
//                //放置下一个皇后
//                place(chess, count, number, n, i + 1);
//
//
//                //放置完毕，无论成功与否，回溯状态，寻找下一种可能
//                chess[i][j] = 0;
//                ++number;
//
//
//            }
//
//
//        }
//
//    }
//
//
//}
//
//bool isSafe(const vector<vector<int>>& chess, int i, int j)
//{
//    for (int k = 0; k < chess.size(); ++k)
//    {
//        if (chess[k][j])
//            return false;
//        if (chess[i][k])
//            return false;
//    }
//
//
//    int tempi = i + 1, tempj = j + 1;
//
//    while ((tempi < chess.size() && tempi >= 0) && ((tempj < chess.size() && tempj >= 0)))
//    {
//        if (chess[tempi][tempj])
//            return false;
//
//        ++tempi;
//        ++tempj;
//    }
//
//    tempi = i - 1; tempj = j - 1;
//    while ((tempi < chess.size() && tempi >= 0) && ((tempj < chess.size() && tempj >= 0)))
//    {
//        if (chess[tempi][tempj])
//            return false;
//
//        --tempi;
//        --tempj;
//    }
//
//    tempi = i - 1; tempj = j + 1;
//    while ((tempi < chess.size() && tempi >= 0) && ((tempj < chess.size() && tempj >= 0)))
//    {
//        if (chess[tempi][tempj])
//            return false;
//
//        --tempi;
//        ++tempj;
//    }
//
//    tempi = i + 1; tempj = j - 1;
//    while ((tempi < chess.size() && tempi >= 0) && ((tempj < chess.size() && tempj >= 0)))
//    {
//        if (chess[tempi][tempj])
//            return false;
//
//        ++tempi;
//        --tempj;
//    }
//
//
//    return true;
//}
//
//


//
//  optimisedMain.cpp
//  Optimised BackTrack Solution of N-Queens Problem.
//
//  Created by Kang on 2020/7/2 at NJUPT.
//  Copyright © 2020 Kang. All rights reserved.
//

//#include <iostream>
//#include <cmath>
//#include <ctime>
//using namespace std;
//
//const int maxSize = 10;      // 最大能输入的棋盘规模（皇后数量）
//int x[maxSize];              // x[k]表示：第k行选择第x[k]列
//int flag[maxSize][maxSize];  // flag[k][i]：第k行的第i列如果可选则为1，不可选则为0

/**
 Calculate the kth row's all unalternative column i, and turn flag[i] from 1 to 0.
 */
//void calcFlag(int k, int N) {
//    for (int i = 0; i < N; ++i) {
//        flag[k][i] = 1;
//    }
//
//    for (int i = 0; i < k; ++i) { // from 0th to (k-1)th row
//        flag[k][x[i]] = 0;  // 正对下方的列直接Pass
//
//        if (x[i] + abs(i - k) < N)   // 检查右下方：如果当前列号x[i] + 行差abs(i-k) < N
//            flag[k][x[i] + abs(i - k)] = 0;
//        if (x[i] - abs(i - k) > -1) // 检查左下方：如果当前列号x[i] + 行差abs(i-k) < N
//            flag[k][x[i] - abs(i - k)] = 0;
//    }
//}
//
//void Print(int N) {
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            if (x[i] != j) {
//                printf(" ");
//            }
//            else {
//                printf("*\n");
//                break;
//            }
//        }
//    }
//    printf("---------\n");
//}
//
//int Recursive_BackTrack(int k, int N) {
//    int solutionCount = 0;
//
//    if (k == N) {
//        Print(N);
//        return 1;
//    }
//
//    calcFlag(k, N);
//    for (int i = 0; i < N; ++i) {
//        if (flag[k][i]) {
//            x[k] = i;
//            solutionCount += Recursive_BackTrack(k + 1, N);
//        }
//    }
//    return solutionCount;
//}

/**
 N the scale of the problem
 return number of solution
*/
//int Iterated_BackTrack(int N) {
//    int solutionCount = 0, k = 0;       // 问题解的个数、当前层数
//
//    for (int i = 0; i < maxSize; ++i) { // 将所有层中，所选子树(列)的初始值置为-1
//        x[i] = -1;
//    }
//
//    calcFlag(0, N);
//    while (k > -1) {     // 如果已经退回第0行前面，则结束遍历
//        if (k == N) {      // 如果已经超过最后一行，则打印路径并返回上一层
//            Print(N);
//            ++solutionCount;
//            --k;
//            continue;
//        }
//
//        if (++x[k] < N) {  // 如果还有未访问的子节点，则选择这棵树的下一个子树
//            if (flag[k][x[k]] == 1) {
//                ++k;     // 如果当前列x[k]可以摆放，则k自增，进入下一行的循环。
//                calcFlag(k, N);
//            }
//            else {
//                // 如果当前位置不能摆放，则k不必动，直接进入下次循环。
//            }
//        }
//        else {         // 子树已经全部搜索，返回上一层
//            x[k--] = -1;   // 注意，返回时要将子树进行复位。
//        }
//    }
//
//    return solutionCount;
//}

//int main(int argc, const char* argv[]) {
//    int N;
//    int count;
//
//    printf("请输入皇后个数：");
//    cin >> N;
//
//    //count = Recursive_BackTrack(0, N);
//    count = Iterated_BackTrack(N);
//
//    cout << "共有" << count << "种不同的解法。" << endl;
//    return 0;
//}
//

//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#define max 10
//int num = 0;
//bool paintable(int g[max][max], int p[max], int n, int i) {
//    for (int j = 1; j <= n; j++) {
//        if (g[i][j] == 1 && p[i] == p[j])
//            return false;
//    }
//    return true;
//}
//void dfs(int g[max][max], int p[max], int n, int m, int i) {
//    if (i > n) {
//        num++;
//    }
//    else {
//        for (int j = 1; j <= m; j++) {
//            p[i] = j;
//            if (paintable(g, p, n, i))
//                dfs(g, p, n, m, i + 1);
//            p[i] = 0;
//        }
//    }
//}



//int main() {
//    int n = 5;
//    int m = 3;
//    int g[max][max];
//    int paint[max];
//    memset(paint, 0, sizeof(paint));
//    memset(g, 0, sizeof(g));
//    g[1][2] = 1; g[1][3] = 1; 
//    g[2][1] = 1; g[2][3] = 1; g[2][4] = 1; g[2][5] = 1;
//    g[3][1] = 1; g[3][2] = 1; g[3][4] = 1;
//    g[4][2] = 1; g[4][3] = 1; g[4][5] = 1;
//    g[5][2] = 1; g[5][4] = 1;
//    dfs(g, paint, n, m, 1);
//    cout << num;
//    return 0;
//}




//#include <iostream>
//using namespace std;
//int m; // 数
//int pointnum;  //点数
//int edgenum;  //边数
//int sum = 0;                                                                                        //符合条件的着色方案数量
//int Graph[100][100];  //各点之间的关系  1：两点连接 0：两点断开
//int x[100];      //存储各点的着色情况
//void InPut()
//{
//    int pos1, pos2;  //起始点
//    cout << "输入点的个数和色数：";
//    cin >> pointnum >> m;
//
//    cout << "输入边的个数: ";
//    cin >> edgenum;
//    memset(Graph, 0, sizeof(Graph));
//
//    cout << "输入边的起始点：" << endl;
//    for (int i = 1; i <= edgenum; ++i)
//    {
//        cin >> pos1 >> pos2;
//        Graph[pos1][pos2] = Graph[pos2][pos1] = 1;
//    }
//}
////判断当前点的着色是否合法合法
//bool IsOk(int i)
//{
//    for (int j = 1; j < i; ++j)
//        //两点如果相通并且与周围点的着色相同，就结束判断，表明当前的颜色选择不合法。
//        if (Graph[i][j] == 1 && x[j] == x[i])
//            return false;
//    return true;
//}
////核心代码
//void BackTrack(int i)
//{
//    if (i > pointnum)
//    {   sum += 1;
//        cout << "方案 " << sum << "  :";
//        for (int j = 1; j <= pointnum; ++j)
//        {
//            cout << x[j];
//        }
//        cout << endl;
//        return; }
//    else
//    {
//        for (int j = 1; j <= m; ++j)
//        {
//            x[i] = j;
//            if (IsOk(i))
//                BackTrack(i + 1);
//            x[i] = 0;
//        }
//    }
//}
//void OutPut()
//{
//    cout << "共有 " << sum << " 种方案" << endl;
//}
//int main()
//{
//    InPut();
//    BackTrack(1);
//    OutPut();
//}
//




//#include <iostream>
//#include <stdio.h>
//using namespace std;
//#define max 100
//int num;
//int g[max][max], x[max], bestx[max]; //best[]是用来存储最终的最短路径 
//int cl = 0;
//int best = max;
////交换函数 
//void swap(int& a, int& b)
//{
//	int tem = a;
//	a = b;
//	b = tem;
//}
//int  bound(int t)
//{
//	int min1 = max, min2 = max, temmin = 0;  //这里min与min2初始化一下 
//	for (int i = t; i <= num; i++)
//	{
//		//这里求min1 
//		if (g[x[t - 1]][x[i]] != -1 && g[x[t - 1]][x[i]] < min1)
//		{
//			min1 = g[x[t - 1]][x[i]]; //这里求要去的第t城市。选择当前到t路径最短的 
//		}
//
//		//这里求min2 
//		for (int j = 1; j <= num; j++) //贪心的思想，求剩下的路径的下界 
//		{
//			if (g[x[i]][x[j]] != -1 && g[x[i]][x[j]] != 0 && g[x[i]][x[j]] < min2)
//			{
//				min2 = g[x[i]][x[j]];
//			}
//		}
//		temmin += min2; //这里是剩下点的最短出出路径的和的累加 
//	}
//	return cl + min1 + temmin;
//}
//
////这里选择城市的方式类似于全排列问题，只不过这里加了 一个判断条件就是t与之前的城市t-1有路径，这里是有选择性的选择点（这里也叫剪枝）。 
//void prim(int t)
//{
//	//如果到叶节点，则表示所有城市都走过了，这个时候就保存一下最短路径以及相应的城市顺序 
//	if (t > num)
//	{
//		if (g[x[num]][1] != -1 && cl + g[x[num]][1] < best) //记得还有最后回到原点 
//		{
//			for (int i = 1; i <= num; i++)
//			{
//				bestx[i] = x[i];	 //将走过的顺序放入best数组中 
//			}
//			best = cl + g[x[num]][1]; //保存加上回到原点的的路径 
//		}
//	}
//	else {
//		for (int j = t; j <= num; j++)
//		{
//			if (g[x[t - 1]][x[j]] != -1 && (bound(t) < best)) //满足条件的选择要选的城市的编号 
//			{
//				swap(x[j], x[t]);
//				cl += g[x[t - 1]][x[t]]; //j改成t，因为j与t的位置数值换了。 
//				prim(t + 1);
//				cl -= g[x[t - 1]][x[t]];
//				swap(x[j], x[t]);
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	printf("输入城市数： ");
//	cin >> num;
//	for (int i = 1; i <= num; i++)
//	{
//		x[i] = i; //将城市编号放入一个数组中,初始化 
//		bestx[i] = 0;
//	}
//	for (int i = 1; i <= num; i++)
//	{
//		for (int j = 1; j <= num; j++)
//		{
//			cin>>g[i][j];
//		}
//	}
//	prim(2); //这里是从第一个城市出发，开始要寻找第二个要走的城市 
//	printf("从1号城市出发，经过所有城市回到起点顺序为： ");
//	for (int i = 1; i <= num; i++)
//	{
//		printf("%d --> ", bestx[i]);
//	}
//	if (g[x[num]][1] != -1);
//	{
//		printf("%d", bestx[1]);
//	}
//	printf("\n");
//	printf("\n最短路径为:  %d", best);
//	return 0;
//}



#include<iostream>
using namespace std;
const int MAX  = 100;
int p[MAX + 1], m[MAX][MAX], s[MAX][MAX];
int n;//矩阵个数 

void MatrixChain()
{
	for (int i = 1; i <= n; i++)//当一个矩阵相乘时，相乘次数为 0
		m[i][i] = 0;
	for (int r = 2; r <= n; r++)//矩阵个数从两个开始一次递增 
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			//拿到从 i 到 j 矩阵连乘的次数
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			//拿到矩阵连乘断开的位置
			s[i][j] = i;
			//寻找加括号不同，矩阵连乘次数的最小值，修改 m 数组，和断开的位置 s 数组
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) { m[i][j] = t; s[i][j] = k; }
			}
		}
}

void Traceback(int i, int j)
{
	if (i == j) return;
	Traceback(i, s[i][j]);
	Traceback(s[i][j] + 1, j);//递归1到s[1][j]
	cout << "Multiply A" << i << "," << s[i][j];
	cout << "and A" << (s[i][j] + 1) << "," << j << endl;
}
int main()
{
	int j;
	cout << "请输入矩阵的个数" << endl;
	cin >> n;
	cout << "请输入矩阵的行、列数" << endl;
	for (int i = 0; i <= n; i++)cin >> p[i];

	MatrixChain();
	Traceback(1, n);
	for (i = 1; i < 7; i++)
	{
		for (j = 1; j < 7; j++)
		{
			cout << setw(8) << m[i][j];
		}cout << endl;
	}
	cout << "*****************************************************" << endl;
	for (i = 1; i < 7; i++)
	{
		for (j = 1; j < 7; j++)
		{
			cout << setw(8) << s[i][j];
		}cout << endl;
	}
	//最终解值为m[1][n];
	cout << m[1][n] << endl;
	return 0;
}

