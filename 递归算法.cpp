#include <iostream>
#include <windows.h>
#include<stdlib.h>
using namespace std;
void recursion(int n,int *a)//µÝ¹éº¯Êý
{
    if (n == 1)
     return;
else
    {for (int i = 0; i < n / 2; i++)a[i]+= a[n-i-1];
    n = n / 2;
   recursion(n,a);
 }
}

int main() {
    for (int b = 16; b < 10000000; b *= 2) {
        int n = b;
        int* a = new int[n];
        for (int i = 0; i < n; i++)a[i] = i;

        long long head, tail, freq; // timers
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);

        recursion(n, a);
        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        cout << "n=" << n << ":  " << (tail - head) * 1000.0 / freq << "ms" << endl;
    }
    return 0;
}