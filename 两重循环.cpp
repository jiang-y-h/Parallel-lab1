#include <iostream>
#include <windows.h>
#include<stdlib.h>
using namespace std;
int main() {
    for (int b = 16; b < 10000000; b *= 2) {
        int n = b;
        int* a = new int[n];
        for (int i = 0; i < n; i++)a[i] = i;
        int sum = 0;

        long long head, tail, freq; // timers
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);

         for (int m = n; m > 1; m /= 2){ // log(n)¸ö²½Öè
         for (int i = 0; i < m / 2; i++){a[i] = a[i * 2] + a[i*2 + 1];}}
         sum=a[0];
        
        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        cout << "n=" << n << ":  " << (tail - head) * 1000.0 / freq << "ms" << endl;
        
    }
    return 0;
}