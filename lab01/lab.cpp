#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include <time.h>

double avg(int N, long long int (&arr)[]) {
    double sum = 0;
    for(int i =0; i < N; ++i) {
        sum += arr[i];
        std::cout << arr[i] << std::endl;
    }
    return sum/N;
}

void make(int* ptr,long long int N) {
    for(long long int i = 0; i < N; ++i) {
        ptr[i] =  rand();
    }
}

void make_sort(int* ptr, long long int N) {
    int a = RAND_MAX;
    ptr[0] = rand()/N;
    for (int i = 0; i < N - 1; i++) {
    ptr[i+1] = rand() % (RAND_MAX - ptr[i] - N + i + 2) + ptr[i] + 1;    
    }
}

int search(long long int N, int* ptr, int f) {
    for(long long int i = 0; i < N; ++i) {
        if(ptr[i] == f) {
            return i;
        }
    }
    return 0;
}

int binsearch(long long int N, int* ptr, int f, int l, int r) {
    if(ptr[(l+r)/2] == f) {
        return (l+r)/2;
    }
    else if(ptr[(l+r)/2] > f){
        l = (l+r)/2 - 1 ;
        binsearch(N, ptr, f, l, r);
    }
    else if(ptr[(l+r)/2] < f) {
        r = (l+r)/2 - 1;
        binsearch(N, ptr, f, l, r);
    }
    else if(l == r) {
        return(l);
    }
}

int main() {
    double time = 0;
    for(long long int i = 1; i <= 1000; i++ ) {
        int* ptr = new int[i*1000];
        auto start = clock();
        for(int j = 0; j<10; j++) {
            make_sort(ptr, i*1000);
            binsearch(1000*i, ptr, rand(), 0, i*1000-1);
        }
        auto end = clock();
        time = end - start;
        std::cout << i << ',' << time/10 << std::endl;
        delete ptr;
        ptr = nullptr;
    }

}