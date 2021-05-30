#include <cmath>
#include <iostream>
using namespace std;
int main()
{
 int v;
 cout << "Enter the number of vertices: ";
 cin >> v;
 int matrixin[v][v],matrixout[v][v];
 for (int i = 0; i < v; i++)
 for (int j = 0; j < v; j++)
 matrixin[i][j] = 0,matrixout[i][j]=0;
 for (int i = 0, e; i < v; i++)
 {
 cout << "Enter the number of edges incoming to vertex "
 << i + 1 << ": ";
 cin >> e;
 for (int j = 0, f; j < e; j++)
 {
 cout << "Enter vertex from which the incoming edge to vertex "
 << i + 1 << " is emerging from: ";
 cin >> f;
 matrixin[i][f - 1] = -1;
 }
 cout << "Enter the number of edges outgoing from vertex "
 << i + 1 << ": ";
 cin >> e;
 for (int j = 0, f; j < e; j++)

 {
 cout << "Enter vertex from which the outgoing edge from vertex "
 << i + 1 << " is ending at: ";
 cin >> f;
 matrixout[i][f - 1] = 1;
 }
 }
 for (int i = 0; i < v; i++)
 {
 int inDegree = 0, outDegree = 0;
 for (int j = 0; j < v; j++)
 {
 if (matrixin[i][j] == -1)
 inDegree += matrixin[i][j];
 if (matrixout[i][j] == 1)
 outDegree += matrixout[i][j];
 }
 cout << "\nOutdegree of vertex " << i + 1 << ": " << outDegree
 << "\tIndegree of vertex " << i + 1 << ": " << abs(inDegree)
 << endl;
 }
 return 0;
}

