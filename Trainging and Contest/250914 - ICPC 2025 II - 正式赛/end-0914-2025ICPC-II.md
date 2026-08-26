# 1.题目介绍
## A. Angry Birds
Aris is playing the classic game, Angry Birds!
Because Aris has been playing for too long, Yuuka confiscated Aris's game console and demanded that Aris complete today's math homework before getting it back.
However, Sensei did not assign any math homework to Aris today, so Yuuka had to come up with a problem for Aris to solve.
Consider the game field of Angry Birds as a three-dimensional Euclidean space, and the bird as a sphere with radius $ R_3 $  . Establish a spatial Cartesian coordinate system $ O-xyz $  , such that the trajectory of the bird's center lies in the horizontal plane $ z=0 $  .
It is known that the trajectory of the bird's center is a closed polyline, consisting of $ n $  segments connected end to end. The connection points are $ n $  points: $ (x_1, y_1, 0), (x_2, y_2, 0), \cdots, (x_n, y_n, 0) $  . The $ i $  \-th segment has endpoints $ (x_i, y_i, 0) $  and $ (x_{i \bmod n + 1}, y_{i \bmod n + 1}, 0) $  . However, due to sensor errors, the actual $ n $  points may deviate from $ (x_i, y_i, 0) $  by a distance not exceeding $ R_2 $  (the sensor deviation $ R_2 $  is the same for all points). That is, the actual $ i $  \-th point $ (x'_i, y'_i, 0) $  can be anywhere within the circle (which is still contained in the plane $ z=0 $  ) centered at $ (x_i, y_i, 0) $  with radius $ R_2 $  .
Let $ S $  be the set of all points that the entire bird may pass through, i.e., points in 3D space whose distance to the bird's center trajectory is at most $ R_3 $  . Yuuka requires Aris to compute the volume of the convex hull of $ S $  .
Convex hull: The convex hull of a point set $ S $  is defined as the smallest set $ T $  such that for any two points in $ S $  , all points on the line segment between them are contained in $ T $  .
**Input**
The first line contains a positive integer $ T $  $( 1 \leq T \leq 10^3 )$, indicating the number of test cases.
For each test case, the first line contains three integers $n,R_2,R_3$ $(1\leq n\leq 10^5, 0\leq R_2,R_3\leq 10^6)$, representing the number of connection points, the sensor error radius, and the bird radius, respectively.
The next $ n $  lines each contain two integers $ x_i, y_i $  $( |x_i|, |y_i| \leq 10^6 )$, representing the $ i $  \-th connection point of the trajectory.
It is guaranteed that the sum of $ n $  over all test cases in a single test point does not exceed $ 10^5 $  .
**Output**
For each test case, output a single floating-point number representing the answer. Your answer is considered correct if the relative or absolute error compared to the standard answer is at most $ 10^{-9} $  .
Let your answer be $ a $  and the standard answer be $ b $  . If $ \frac{|a - b|}{\max\{b, 1\}} \leq 10^{-9} $  , it is considered correct.

## B. Rectangular Wooden Block
Mr. Noya has a pet hamster that loves to gnaw on wood.
One day, Mr. Noya brought home a rectangular wooden block with dimensions $L \times W \times H$, meaning it has a length of $L$ units, a width of $W$ units, and a height of $H$ units, divided into $L \times W \times H$ unit cubes. Using one vertex of the block as the origin, the length direction as the $x$\-axis, the width direction as the $y$\-axis, and the height direction as the $z$\-axis, a spatial coordinate system $O-xyz$ is established. The unit cube with $x$\-coordinate in $[i-1, i)$, $y$\-coordinate in $[j-1, j)$, and $z$\-coordinate in $[k-1, k)$ is denoted as $(i, j, k)$.
Note: The block does not necessarily have length greater than width (i.e., it is not required that $W \leq L$); the terms are just used to fix the directions.
Mr. Noya does not want the wooden block to be completely gnawed away by his hamster, so he decides to reinforce it. Reinforcing the unit cube at $(i,j,k)$ has a cost $V(i,j,k)$. Additionally, there are three matrices $A,B,C$ representing constraints from the three orthogonal views (front view, side view, and top view):
-   For matrix $A = \{a_{ij}\}_{H \times L}$, if $a_{ij} = 0$, then for all $1 \leq p \leq W$, the cube at $(j, p, i)$ must not be reinforced. If $a_{ij} = 1$, at least one of these cubes must be reinforced.
-   For matrix $B = \{b_{ij}\}_{H \times W}$, if $b_{ij} = 0$, then for all $1 \leq q \leq L$, the cube at $(q, j, i)$ must not be reinforced. If $b_{ij} = 1$, at least one of these cubes must be reinforced.
-   For matrix $C = \{c_{ij}\}_{W \times L}$, if $c_{ij} = 0$, then for all $1 \leq r \leq H$, the cube at $(j, i, r)$ must not be reinforced. If $c_{ij} = 1$, any number (including zero) of these cubes may be reinforced.
Note: Mr. Noya can reinforce each unit cube at most once.
**Note: For matrix $C$, a non-zero value does not require reinforcing at least one unit cube.**
Under the above conditions, Mr. Noya wants to minimize the total cost of reinforcing the wooden block. Can you help him?
Note: You do not need to consider the issue of unit cubes being suspended in air.
**Input**
The first line contains a positive integer $T$ $(1 \leq T \leq 5 \times 10^3)$, indicating the number of test cases.
For each test case, the first line contains three positive integers $L$, $W$, $H$ $(1 \leq L \times W \times H \leq 10^3)$, representing the length, width, and height of the block.
The next line contains $L\times W\times H$ integers. The $[(i-1)\times W+j-1]\times H+k$\-th integer is $V(i,j,k)$ $(-10^9\leq V(i,j,k)\leq 10^9)$.
Then follow $H$ lines. The $i$\-th line is a binary string of length $L$, denoted $a_{i1}a_{i2}\cdots a_{iL}$, representing the $i$\-th row of matrix $A$.
Then follow $H$ lines. The $i$\-th line is a binary string of length $W$, denoted $b_{i1}b_{i2}\cdots b_{iW}$, representing the $i$\-th row of matrix $B$.
Then follow $W$ lines. The $i$\-th line is a binary string of length $L$, denoted $c_{i1}c_{i2}\cdots c_{iL}$, representing the $i$\-th row of matrix $C$.
It is guaranteed that the sum of $L \times W \times H$ over all test cases in a single test point does not exceed $5 \times 10^3$.
**Output**
For each test case, the first line contains a string $\texttt{YES}$ or $\texttt{NO}$ indicating whether Mr. Noya's conditions can be satisfied.
If the conditions can be satisfied, then output on the second line an integer representing the minimum reinforcement cost of the cuboid; on the third line a nonnegative integer representing the number $k$ of reinforced unit cubes; followed by $k$ lines, each containing three positive integers representing the coordinates of each reinforced unit cube. Note that each unit cube can be reinforced at most once.
If there are multiple valid solutions, outputting any one of them will be considered correct.

## C. Jiaxun!
There are three students training hard for ICPC. They are practicing on a problemset consisting of exactly $S$ problems. Each problem belongs to exactly one of the following seven categories, describing which subset of students can solve it:
-   $F_1$: only student $1$ can solve;
-   $F_2$: only student $2$ can solve;
-   $F_3$: students $1$ and $2$ (but not $3$) can solve;
-   $F_4$: only student $3$ can solve;
-   $F_5$: students $1$ and $3$ (but not $2$) can solve;
-   $F_6$: students $2$ and $3$ (but not $1$) can solve;
-   $F_7$: students $1$, $2$ and $3$ can all solve.
It is guaranteed that
$$
F_1 + F_2 + F_3 + F_4 + F_5 + F_6 + F_7 = S.
$$
You are going to **assign each problem to exactly one student who can solve it**. Your goal is to make the training as balanced as possible: maximize the minimum number of problems solved by any single student. Output this maximum possible value.
**Input**
The first line contains a single integer $T$ ($1 \leq T \leq 10^5$)— the number of test cases.
For each test case, the first line contains a single integer $S$ ($0 \leq S \leq 7 \times 10^8$).
The second line contains seven non-negative integers $F_1, F_2, F_3, F_4, F_5, F_6, F_7$ ($0 \le F_1, \cdots, F_7 \le 10^{8}$).
It is guaranteed that $F_1 + \cdots + F_7 = S$.
**Output**
For each test case, print a single integer — the maximum possible value of the minimum solved-count among the three students after assigning all $S$ problems.

## D.Arcane Behemoths
You have $N$ Arcane Behemoths, each with an attack value $A_i$.
You may choose any non-empty subsequence of Behemoths and sell them one by one. Whenever you sell a Behemoth, each remaining unsold Behemoth in the subsequence increases its attack value by the attack value of the Behemoth you just sold.
The value of a subsequence is the maximum attack value the last remaining Behemoth can achieve, if the other Behemoths in the subsequence are sold in an optimal order.
Your task is to compute the sum of values over all non-empty subsequences of the sequence. Print the result modulo $998244353$.
**Input**
The first line contains a single integer $T$ ($1 \leq T \leq 2 \times 10^5$) — the number of test cases.
For each test case, the first line contains an integer $N$ ($1 \leq N \leq 2 \times 10^5$) — the number of Behemoths.
The second line contains $N$ integers $A_1, A_2, \ldots, A_N$ $(0 \leq A_i \lt 998244353)$ — the initial attack values of the Behemoths.
It is guaranteed that $\sum N \leq 2\times 10^5$ over all test cases.
**Output**
For each test case, print a single integer — the sum of values over all non-empty subsequences modulo $998244353$.

## E.Zero
An integer sequence $a_1,a_2,\cdots,a_n$ is called a zero sequence if and only if it satisfies the following conditions:
-   For $i=1,2,\cdots,n-1$, $a_i \neq a_{i+1}$.
-   The binary XOR sum of $a_1,a_2,\cdots,a_n$ is $0$, i.e.,
    $$
    \bigoplus_{i=1}^{n}a_i=0
    $$
Given $n$ and $m$, find the number of zero sequences of length $n$ where each element is chosen from the set $\{0,1,2,\cdots,2^m-1\}$.
**Input**
The first line contains a positive integer $T$ $(1 \leq T \leq 10^4)$, indicating the number of test cases.
For each test case, one line contains two integers $n,m$ $(1\leq n\leq 10^9,0\leq m\leq 10^9)$, representing the length of the sequence and the binary length of the sequence elements, respectively.
**Output**
For each test case, output one integer representing the answer modulo $998244353$.

## F.Square Permutation I
Give two permutations $p$ and $q$ of length $n$. It is guaranteed that $n$ is an odd number. You must perform exactly one of the following operations for each position $i \in [1,n]$:
1.  Perform no operation at no cost.
2.  Spend a cost of $x_i$ to either modify $p_i$ to $p_i^2$ or modify $q_i$ to $q_i^2$.
3.  Spend a cost of $y_i$ to modify both $p_i$ to $p_i^2$ and $q_i$ to $q_i^2$.
Please find the minimum cost required to make the median of array $p$ equal to $A$ and the median of array $q$ equal to $B$. If it's impossible, output $-1$.
**Input**
Each test contains multiple test cases. The first line contains the number of test cases $t$ $(1 \leq t \leq 10^4)$ . The description of the test cases follows.
The first line of each test case contains three single integers $n,A,B$ $(1 \leq n \leq 10^5,1 \leq A,B \leq n^2)$.
The second line gives $n$ positive integers, representing the permutation $p$.
The third line gives $n$ positive integers, representing the permutation $q$.
The fourth line gives $n$ positive integers, representing the array $x$ .
The fifth line gives $n$ positive integers, representing the array $y$ $(1 \leq x_i \leq y_i \leq10^4)$.
It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.
**Output**
For each test case, output $-1$ if it is impossible.
Otherwise, output the minimum cost.
All outputs must be printed on separate lines.

## G.Square Permutation II
Give two permutations $p$ and $q$ of length $n$. It is guaranteed that $n$ is an odd number. You must perform exactly one of the following operations for each position $i \in [1,n]$:
1.  Perform no operation at no cost.
2.  Spend a cost of $x$ to either modify $p_i$ to $p_i^2$ or modify $q_i$ to $q_i^2$.
3.  Spend a cost of $y$ to modify both $p_i$ to $p_i^2$ and $q_i$ to $q_i^2$.
There are a total of $m$ groups of queries in this problem. For each query, values of $x$ , $y$ , $A$ and $B$ are given.Please find the minimum cost required to make the median of array $p$ equal to $A$ and the median of array $q$ equal to $B$. If it's impossible, output $-1$.
**Input**
Each test contains multiple test cases. The first line contains the number of test cases $t$ $(1 \leq t \leq 10^4)$ . The description of the test cases follows.
The first line of each test case contains two single integers $n,m$ $(1\leq n,m\leq 10^5)$.
The second line gives $n$ positive integers, representing the permutation $p$.
The third line gives $n$ positive integers, representing the permutation $q$.
The next $m$ lines each contain four positive integers $A$, $B$, $x$, and $y$ $(1 \leq A,B \leq n^2,1 \leq x \leq y \leq 10^9)$.
It is guaranteed that the sum of $n$ and $m$ over all test cases does not exceed $10^5$.
**Output**
For each set of data, output $m$ lines. The $i$\-th line contains an integer representing the answer to the $i$\-th query.

## H.Tree Shuffling
Froggy has an unrooted tree $T$ with $n$ vertices, where each vertex has an initial weight. Initially, the weight of vertex $i$ is $i$.
Froggy can perform at most 1 operation sequentially as follows:
-   Select several distinct vertices $x_1, x_2, \cdots, x_k$, such that for $i = 1, 2, \cdots, k-1$, there exists an edge in tree $T$ connecting vertex $x_i$ and vertex $x_{i+1}$.
-   From the set ${x_1, x_2, \cdots, x_k}$, choose an even number of vertices $u_1, u_2, \cdots, u_{2l}$ (vertices can be chosen repeatedly). For $i = 1, 2, \cdots, l$, sequentially swap the weights of vertex $u_{2i-1}$ and vertex $u_{2i}$.
Let $a_i$ denote the weight of vertex $i$ after all operations. How many distinct sequences $a_1, a_2, \cdots, a_n$ can Froggy obtain? Output the answer modulo $998244353$.
**Input**
The first line contains a positive integer $T$ $(1 \leq T \leq 10^3)$, indicating the number of test cases.
For each test case, the first line contains an integer $n$ $(1 \leq n \leq 3000)$, representing the number of vertices in the tree.
The next $n-1$ lines each contain two positive integers $x, y$ $(1 \leq x, y \leq n, x \neq y)$, representing the two endpoints of an edge in tree $T$.
It is guaranteed that the sum of $n$ over all test cases in a single test point does not exceed $1.5 \times 10^4$.
**Output**
For each test case, output one integer representing the answer modulo $998244353$.

## I.DAG Query
This is an interactive problem.
Given a directed acyclic graph (DAG) with $n$ vertices and $m$ edges, each edge has an associated weight.
There may be multiple paths between any pair of vertices $s$ and $t$. We define the weight of a path as the product of the weights of all edges along that path. Let $f(s,t,c)$ denote the sum of the path weights of all distinct paths from $s$ to $t$ after multiplying the weight of every edge in the graph by $c$. Since the result can be extremely large, $f(s,t,c)$ is taken modulo $998244353$.
Xiao M will inform you of the structure of the DAG in advance (excluding the edge weights).
You may provide parameters $s$, $t$, and $c$; the interactor will return the value of $f(s,t,c)$. You are allowed to make at most $999$ such queries to obtain certain information about the graph. After several query cycles, the interactor will provide a parameter $k$, and you need to determine the value of $f(1,n,k)$.
**Input**
The first line contains two positive integers $n$ and $m$ $(1 \leq n \leq 1000,1 \leq m \leq 5000)$, where $n$ represents the number of vertices in the graph and $m$ represents the number of edges.
In the following $m$ lines, each line contains two positive integers $x$ and $y$ $(1 \leq x,y \leq 1000)$, indicating that there is a directed edge from vertex $x$ to vertex $y$ in the graph. It is guaranteed that the graph is a Directed Acyclic Graph (DAG).
**Interaction**
For each query, you need to output in the format $\texttt{? s t c}$ $(1\leq s,t\leq n,0\leq c \lt 998244353)$ where $s,t,c$ are all integers, and the interactor will return the answer of $f(s,t,c)$.
When you are confident that the information you have is sufficient to answer the query, output $\texttt{!}$, and the interactor will return a integer parameter $k$ $(0\leq k \lt 998244353)$, which means you are asked for the weight of $f(1,n,k)$.
You need to output the result of $f(1,n,k)$.
After printing a query or the answer, do not forget to output the end of the line and flush the output. Otherwise, you will get the verdict Idleness Limit Exceeded. To do this, use:
$\texttt{fflush(stdout)}$ or $\texttt{cout.flush()}$ in C++; $\texttt{System.out.flush()}$ in Java; $\texttt{flush(output)}$ in Pascal; $\texttt{stdout.flush()}$ in Python; see the documentation for other languages.

## J.Reconstruct the tree
You are given a remembered collection of $\textit{diameter endpoint pairs}$ that Little Grey wrote down when he owned a tree with $N$ nodes. Now he forgot the tree itself. Your task is to reconstruct $\textbf{any}$ tree on $N$ labeled nodes whose set of unordered pairs of nodes at distance equal to the tree diameter is exactly the given collection — or report that his memory is inconsistent (i.e. no such tree exists).
A $\textit{diameter}$ of a tree is the longest simple path in the tree; its length is the maximum distance between any two vertices. A pair $(u,v)$ is a $\textit{diameter endpoint pair}$ if the distance between $u$ and $v$ equals the length of tree diameter. The given collection contains unordered pairs and may list them in any order.
**Input**
The first line contains a single integer $T$ ($1 \le T \le 2 \cdot 10^5$) — the number of test cases.
Each test case begins with a line containing three integers $N, M$ ($2 \le N \le 2\cdot 10^5,\ 1 \le M \le 2\cdot 10^5$) — the number of nodes and the number of remembered unordered pairs.
Then follow $M$ lines, each containing two integers $u$ and $v$ ($1 \le u,v \le N,\ u\ne v$), representing an unordered pair that Little Grey remembered as being at distance equal to the length of tree diameter.
$\textbf{All}\ M\ \textbf{pairs in one test case are distinct.}$
It is guaranteed that $\sum N \le 2\cdot 10^5,\sum M \le 2\cdot 10^5 $ where sums are over all test cases.
**Output**
For each test case, print:
If there exists a tree on nodes $1\ldots N$ whose set of unordered node-pairs at distance equal to the tree diameter is $\textbf{exactly}$ the given set, print a line YES and then $N-1$ lines describing any such tree as edges $(a, b)$ (one edge per line, nodes separated by a space; the tree should be connected and acyclic).
If multiple valid trees exist, you may output any of them.
Otherwise, print a single line NO.

## K.The Only Heart
Kikyou has carefully cultivated a tree. Now that the tree has grown lush with branches and leaves, Kikyou decides to prune it.
The tree currently has $n$ vertices. Kikyou plans to remove some vertices and their adjacent edges such that the remaining part is still connected. It is easy to see that the remaining part is still a tree.
As a heavy cat, Kikyou wants the remaining tree to be wholehearted, meaning it has only one heart. Here, the heart of a tree is defined as a vertex such that when it is removed, the maximum size among the remaining connected components is minimized. If multiple vertices satisfy this condition, they are all considered hearts.
Kikyou wants to know how many such remaining non-empty trees there are where the heart is unique. Output the answer modulo $998244353$. Two remaining trees are considered different if and only if their vertex sets are different.
**Input**
The first line contains a positive integer $T$ $(1 \leq T \leq 10^3)$, indicating the number of test cases.
For each test case, the first line contains an integer $n$ $(1 \leq n \leq 3000)$, representing the number of vertices in the tree.
The next $n-1$ lines each contain two positive integers $x, y$ $(1 \leq x, y \leq n, x \neq y)$, representing the two endpoints of an edge in tree $T$.
It is guaranteed that the sum of $n$ over all test cases in a single test point does not exceed $1.5 \times 10^4$.  
**Output**
For each test case, output one integer representing the answer modulo $998244353$.

## L.Xor Mirror
Long ago, in the land of Bitworld, there was a magic mirror. Whenever you looked into it, the index $i$ of an array element would be reflected as $i \oplus k$ for some magic key $k$. The wizard who owned this mirror loved to play with sequences: sometimes he mirrored parts of the sequence using XOR, and sometimes he asked for weighted sums of intervals.
Now the wizard gives you $T$ sequences and a list of operations for each sequence. Your task is to process them and report the results of his queries.
You are given an initial sequence $A_0, A_1, \dots, A_{N-1}$ of length $N$. The value $N$ is always a power of two and satisfies $N \le 2^{18}$.
There are two types of operations:
-   Operation type 1: given integers $(l,r,k)$, for every $i \in [l,r)$ set
    $$
    B_i = A_{i \oplus k}, 
    $$
     then assign $A_i = B_i$ for all $i \in [l,r)$.
-   Operation type 2: given integers $(l,r)$, output
    $$
    \sum_{i=l}^{r-1} A_i.
    $$
**Input**
The first line contains a single integer $T$ ($1 \le T \le 2\times 10^5$) — the number of test cases.
Each test case is given as:
One line with two integers $N$ ($1 \le N \le 2^{18}$, $N$ is a power of two) and $Q$ ($1 \le Q \le 2\times 10^5$) — the length of the sequence and the number of operations.
One line with $N$ integers $A_0, A_1, \dots, A_{N-1}$ ($1 \le A_i \le 1048576$) — the initial sequence.
Each of the next $Q$ lines describes one operation.
All operations are given on a left-closed, right-open interval $[l, r)$ with $0 \le l \lt r \le N$. The formats are:
1 l r k —– apply operation type 1 on the interval $[l, r)$ with parameter $k$ ($0 \le k \lt N$).
2 l r —– apply operation type 2 on the interval $[l, r)$.
It is guaranteed that $\sum N \le 2^{18}$, $\sum Q \le 2\times 10^5$ over all test cases.
**Output**
For each operation of type 2, output the result on a separate line.

# 2. 提交情况(比赛时)
## 总情况(过题数/提交数)
**A**:131/676
**B**:24/139
**C**:1396/8816
**D**:1598/3286
**E**:892/3088
**F**:0/76
**G**:10/94
**H**:611/979
**I**:417/1303
**J**:190/927
**K**:148/486
**L**:38/249
## 我的情况
[队伍排名]1757  
[学校排名]494  
[同校队伍数]1  
[校内排名]1  
[过题数]0  
[总用时]0  
## 各题目提交情况
### C.Jiaxun!
- 时间:04:50:00 结果:WA
### D.Arcane Behemoths
- 时间:04:29:00 结果:WA

# 3. 官方题解
## A
首先,记连接处点的凸包为凸多边形 $S_{0}$,半径为的圆为 $O_{2}(r)$,球为 $O_{3}(r)$,则要求体积的图形为
$V=S_{0}+O_{2}(R_{2})+O_{3}(R_{3})$,其中+是Minkowski 和。  
记 $f(z_{0})$ 为V和平面 $z=z_{0}$ 的交集的面积,则体积可以由积分 $\int_{-R}^{R}f(z)dz$,由对称性等于2 $\int_{0}^{R}f(z)dz$  
$f(z)$ 对应的图形可以认为是 $S_{0}+O_{2}(R_{2}+\sqrt{R_{3}^{2}-z^{2}})$ 的,考虑形如 $S_{0}+O_{2}(r)$ 的面积如何计算。  
考虑 $S_{0}+O_{2}(r)$ 是什么形状。对于凸多边形 $S_{0}$ 的边界,可以认为是n条线段和几个顶点,线段对应垂直往外平移r,顶点对应连接相邻线段两端点的圆弧。这样的形状可以拆成三个部分计算面积:原凸多边形So、线段平移形成的n个长方形和几个顶点对应的圆弧。不难发现n个圆弧可以拼成完整的圆,记 $S_{0}$ 的面积为A,周长为C,则 $S_{0}+O_{2}(r)$ 面积为:  $A+C\cdot r+\pi r^{2}$  
最终答案即:
$2 \int_{0}^{R_{3}}f(z)dz$  
$=2\int_{0}^{R_{3}}(A+C(R_{2}+\sqrt{R_{3}^{2}-z^{2}})+\pi(R_{2}+\sqrt{R_{3}^{2}-z^{2}})^{2})dz$  
$=2\int_{0}^{R_{3}}(A+CR_{2}+\pi(R_{2}^{2}+R_{3}^{2})+(C+2\pi R_{2})\sqrt{R_{3}^{2}-z^{2}}-\pi z^{2})dz$  
$=2AR_{3}+2CR_{2}R_{3}+2\pi R_{3}(R_{2}^{2}+R_{3}^{2})+\frac{1}{2}\pi R_{3}^{2}(C+2\pi R_{2})-\frac{2}{3}\pi R_{3}^{3}$  
时间复杂度 $O(n~log~n)$.
## B
按照高度分层,那么在每一层都是一个匹配模型,用上下界费用流模型建图即可。  
注意代价存在负权,可以用预先流满负权边再建立反向边的方式处理。
## C
考虑二分贪心判定:  
将 $F_{1},F_{2},F_{4}$ 的值都先给对应的人, $F_{7}$ 可以最后决定随意分配,所以只需要关心 $F_{3},F_{5},F_{6}$  
优先将 $F_{3}$ 分配给第一个人, $F_{6}$ 分配给第二个人, $F_{5}$ 分配给第三个人,  
这样第一个人就可以选择至多 $F_{3}$ 分配给第二个人,第二个人可以选择至多 $F_{6}$ 分配给第三个人,第三个人可以选择至多 $F_{5}$ 分配给第一个人,  
假设 $b_{i}$ 是这个人当前有的题目数,考虑在符合条件的情况下能匀出来  
$max\{min\{b_{i}-x,x-b_{(i+1)\%3},F_{2^{(i+1)\%3}}\},0\}$ 给 $b_{i+1}$    
$i\rightarrow(i+2)\%$ 3同理,可以通过类似的调整让 $\sum min(b_{i},x)$ 尽可能大,最后判定成功条件就是
$\sum min(b_{i},x)+F_{7}\ge x\times3$  
本题也可以使用Hall 定理/网络流判定 通过.
## D
考虑一个长度为n的序列第i个位置对应的系数 F是: $1,1,2,4,...,2^{n-1},$ 那么这个序列的价值应该是将排序后求出 $\sum_{i=1}^{n}a_{i}\times F_{i}.$  
先将给定的序列排序,对于所有子序列,只需要考虑第 个数作为子序列的第 个数的贡献系数,应当是 $\binom{i-1}{j-1}\times F_{j}\times2^{n-i}$  
所以第 $i$ 个数的总贡献系数是 $\sum_{j=1}^{i}\binom{i-1}{j-1}\times F_{j}\times2^{n-i}=\frac{(3^{i-1}+1)}{2}\times2^{n-i}$  
直接计算即可.
## Ε
相邻两个配对,如果奇数个把最前面那个孤立,则每一对在 $[1,2^{m})$ 内等概率随机出现。  
如果奇数个最前面那个随便调整,否则当成 $[0,2^{m})$ 容斥0的个数,容斥式子:  
$(-1)^{n}+\sum_{i=1}^{n}(-1)^{n-i}\binom{n}{i}2^{(i-1)m}$  
$=(-1)^{n}+2^{-m}(\sum_{i=0}^{n}\binom{n}{i}2^{im}(-1)^{n-i}-(-1)^{n})$  
$=(-1)^{n}+2^{-m}((2^{m}-1)^{n}-(-1)^{n})$  
时间复杂度 $O(T~log~n)$.
## F

先参考G题,剩下的部分为每个点是否平方可以产生贡献分别有一个代价,如果不可达则记作正无穷大,每个数都有
四种选择,通过枚举有多少个数 $x_{i}<A,y_{i}<B,x_{i}^{2}\ge A,y_{i}^{2}\ge B$,剩下的三类点的个数即唯一确定。剩下问题变
成了一个8个点, $O(n)$ 条边的费用流问题,通过堆模拟费用流的整个过程计算即可。
## G
首先枚举最终有多少个数恰好为A和B,只有4个位置对此会产生影响,我们对这4个位置单独枚举。  
如果对于一组 $(x_{i},y_{i})$, $x_{i}\ge p$,那么对该位置的 $x_{i}$ 进行平方操作显然无效,我们只会对那些 $x_{i}<p,x_{i}^{2}\ge p$ 的位置进行操作,y坐标同理。  
根据 $x,y$ 平方是否有意义,可以分为四类数,这四类数在以每个点以 $(x_{i},y_{i})$ 为坐标的平面直角坐标系上均为一个矩形范围,可以利用二维数点计算出每个矩形块内的个数,剩下的部分贪心即可。  
## H
首先一次操作的作用是选择一条链并随意打乱链上的点权。  
首先单独计数计数序列 $a_{i}=i_{i}$  
对于一个最终得到的点权序列 $a_{1},a_{2},\cdot\cdot\cdot,a_{n}$,其可以构造的条件为满足 $a_{i}\ne i$ 的点位于一条链上。  
从链的角度出发计数,为了保证不重复计数,我们希望对于序列 $a_{1},a_{2},\cdot\cdot\cdot,a_{n}$,只在最短的可行链处计数。  
对于一条长度为k的链,有k!种不同的打乱链的方式。假设其左右两端点分别为 $x,y$,则如果 $a_{x}=x$ 或者 $a_{y}=y$ 时,可以操作更短的链得到序列,于是我们减去这两种情况,即 $2(k-1)!$!。然而此时 $a_{x}=x$ 且 $a_{y}=y$ 的序列会被重复减,再加回去 $(k-2)$ 即可。  
注意到上述计数只与链的长度有关,于是只需要统计出每种长度的链分别有多少条即可,这个用从每个点出发遍历就可以 $O(n^{2})$。  
## I
记 $F(c)=f(1,n,c)$,整个答案是一个关于c的 $n-1$ 次多项式,通过拉格朗日插值计算答案。
## J
有解的必要条件是,给定的图可以分成若干个集合 $S_{1}...S_{k}$ 并且不同集合的点之间都存在连边,不在任何集合内的点被称为特殊点   
可能的构造如下:  
如果 $k=2$ 可以在S1,S2中间用特殊点造一条链;  
如果 $k>2$,要么直径长度为2,构造是容易的;要么直径长度为4,可以尝试构造一个特殊点点下面挂k个特殊点,每个点下面再挂上每个集合内的点,多余的特殊点都可以挂在根上,构造完不一定合法,因为当前构造可能会有多余的直径点对.  
可以大力分类讨论,也可以通过哈希或者复杂度正确的暴力判定合法避免分类讨论.  
## Κ
一棵树的重心只有一个或两个两种情况,所以答案即为连通块数减去双重心的连通块数。  
双重心的树等价于存在唯一的一条边,使得断开这条边后两个连通块大小相等。在原树上以这条边为界,这条边子树内的点权为1,子树外的点权为-1,则就是在数点权和为0的连通块数。  
那么树形 DP。设 $f_{i,j}$ 表示子树内包含的个点的连通块数; $g_{i,j}$ 表示子树内,包含i且子树以外的点权均为-1时点权和为的连通块数 $g_{i,j}$ 可以通过 $f_{i,j}$ 转移,且整个DP类似树上背包,时间复杂度 $O(\sum n^{2})$.
## L
一种简单的写法是高低位分块.  
记录一个块数组,表示每种不同的块的内部结构,在任何时刻,这个块数组的有效大小不会超过 (如果块数组中某个 $\frac{n}{B}$  块没有被序列的任何一块依赖,就可以直接删掉)  
实际上只需要对这个序列的每个块记录一个信息 $(id_{i},xor_{i})$ 描述这个块是块数组中的第几个块以及内部的形态。  
针对整块的修改,只需要将k拆成 $xB+y$ 将块的信息标注成 $(id_{i\oplus x},xor_{i\oplus x}\oplus y)$ 即可.  
针对散块,修改完只需要加进去一个新的整块即可,并将散块所在的块的信息标注成 $(id_{i},0)$.  
查询的时候是容易的,只需要查询块和,以及每个位置的数值。  
空间复杂度 $O(n)$,时间复杂度 $O(q(\frac{n}{B}+B))$ 取 $B=2^{9}$ 可以通过.  
空间开 64 MB 是防止访问大数组导致的TLE.  