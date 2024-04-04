#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include <time.h>
#include <fstream>

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

int search(int* ptr, long long int N, int f) {
    for(long long int i = 0; i < N; ++i) {
        if(ptr[i] == f) {
            return i;
        }
    }
    return 0;
}

bool binar_search(int* input_array, unsigned long long size, long long int needed) {
	unsigned long long int l = 0;
	unsigned long long int r = size - 1;
	unsigned long long int mid;

	while (r - l > 1) {
		mid = (l + r) / 2;

		if (input_array[mid] > needed) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	if (input_array[l] == needed) {
		return true;
	}
	else {
		return false;
	}
}

bool SumSearch(int* InputArray, long long int size, long long int sum) {
    for(long long int i = 0; i < size; ++i) {
        for(long long int j = 0; j < size; ++j) {
            if(InputArray[i]+InputArray[j] == sum) {
                return true;
            }
        }
    }
    return false;
}

bool QSumSearch(int* inputArray, long long int size, long long int sum) {
    for(int i = 0; i < size; ++i ) {
        if(binar_search(inputArray, size, sum - inputArray[i]) == true) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ofstream fout; 
    fout.open(("data_sum_rand.csv"));
    fout.clear();
    fout << 'N' << ',' << 'T' << '1' << ',' << 'T' << '2' << std::endl;
    long long int time1, time2 = 0;

    for(long long int i = 1; i <= 1000; i++ ) {
        int* ptr = new int[i*1000];
        for(int j = 0; j<10; j++) {
            make(ptr, i*1000);
            long long int r1 = rand() % i*1000;
            long long int r2 = rand() % i*1000;
            auto start1 = std::chrono::high_resolution_clock::now();
            SumSearch(ptr ,i*1000 , rand());
            auto end1 = std::chrono::high_resolution_clock::now();
            long long int d1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1).count(); 
            time1 += d1;
            //auto start2 = std::chrono::high_resolution_clock::now();
            //binar_search(ptr ,i*1000 , ptr[r]);
            //auto end2 = std::chrono::high_resolution_clock::now();
            //long long int d2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2-start2).count(); 
            //time2 += d2;
        }
        fout << i << ',' << time1/10 << ',' << time2/10 << std::endl;
        time1 = 0;
        time2 = 0;
        delete[] ptr;
        ptr = nullptr;
    }

    fout.close();

}