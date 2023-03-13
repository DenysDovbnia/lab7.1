#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High); void Change(int** a, const int row1, const int row2, const int colCount);
void Print(int** a, const int rowCount, const int colCount); void Sort(int** a, const int rowCount, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);
int main()
{
    srand((unsigned)time(NULL)); int Low = 7;
    int High = 62;
    int rowCount = 7;
    int colCount = 6;
    int** Q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Q[i] = new int[colCount];
    Create(Q, rowCount, colCount, Low, High);
    Print(Q, rowCount, colCount);
    Sort(Q, rowCount, colCount);
    Print(Q, rowCount, colCount);
    int S = 0;
    int k = 0;
    Calc(Q, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Q, rowCount, colCount);
    for (int i = 0; i < rowCount; i++)
        delete[] Q[i];
    delete[] Q;
    return 0;
}
void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            Q[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}
void Print(int** Q, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << Q[i][j];
        cout << endl;
    }
    cout << endl;
}
void Sort(int** Q, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < colCount - 1; i0++)
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
            if ((Q[0][i1] < Q[0][i1 + 1])
                ||
                (Q[0][i1] == Q[0][i1 + 1] &&
                    Q[1][i1] > Q[1][i1 + 1])
                ||
                (Q[0][i1] == Q[0][i1 + 1] &&
                    Q[1][i1] == Q[1][i1 + 1] &&
                    Q[2][i1] > Q[2][i1 + 1]))
                Change(Q, i1, i1 + 1, rowCount);
}
void Change(int** Q, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = Q[i][col1];
        Q[i][col1] = Q[i][col2];
        Q[i][col2] = tmp;
    }
}
void Calc(int** Q, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (Q[i][j] % 2 == 0 && !((i + j) % 8 == 0))
            {
                S += Q[i][j];
                k++;
                Q[i][j] = 0;
            }
}
