#include <iostream>
#include <windows.h>
#include<stdlib.h>
using namespace std;
int main()
{
    for (int c = 10; c < 30000; c *= 2) {

        int n = c;
        int* a = new int[n];
        int* sum = new int[n];
        int** b = new int* [n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
            b[i] = new int[n];
            for (int j = 0; j < n; j++) {
                b[i][j] = i + j;
            }
        }
        long long head, tail, freq; // timers
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);
            for(int i = 0; i < n; i++)sum[i] = 0.0;
    for(int j = 0; j < n; j++){
    for(int i = 0; i < n-1; i+=2){
    sum[i] += b[j][i]*a[j];
    sum[i+1]+=b[j][i+1]*a[j];}}
    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
    cout << "n=" << n << ":  " << (tail - head) * 1000.0 / freq << "ms" << endl;
    delete a;
    delete[]b;
    delete sum;
    }
    return 0;

}
