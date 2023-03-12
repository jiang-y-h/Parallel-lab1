#include <iostream>
#include <windows.h>
#include<stdlib.h>
using namespace std;
int main() {
    for (int b = 16; b < 10000000; b *= 2) {
        int n = b;
        int* a = new int[n];
        for (int i = 0; i < n; i++)a[i] = i;
        int sum = 0, sum1 = 0;

        long long head, tail, freq; // timers
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&head);

        for (int i = 0; i < n; i += 2) { sum += a[i]; sum1 += a[i + 1]; }
        QueryPerformanceCounter((LARGE_INTEGER*)&tail);
        cout << "n=" << n << ":  " << (tail - head) * 1000.0 / freq << "ms" << endl;
    }
    return 0;
}