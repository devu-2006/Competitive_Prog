#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void countSort(vector<int>& arr) {
    int n = arr.size();
    int maxValue = *max_element(arr.begin(), arr.end());

    vector<int> count(maxValue + 1, 0);

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxValue; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

vector<int> generateBestCase(int size) {
    vector<int> arr(size, 0);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

vector<int> bestCase(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

vector<int> worstCase(vector<int> base) {
    vector<int> arr = bestCase(base);
    reverse(arr.begin(), arr.end());
    return arr;
}

vector<int> averageCase(vector<int> arr) {
    random_shuffle(arr.begin(), arr.end());
    return arr;
}

double measureTime(vector<int>& arr) {
    auto start = high_resolution_clock::now();
    countSort(arr);
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return elapsed.count();
}

int main() {
    srand(time(0));
    int sizes[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000, 550000, 600000, 650000, 700000, 750000, 800000};

    for (int i : sizes) {
        vector<int> base = generateBestCase(i);

        vector<int> arr1 = bestCase(base);
        vector<int> arr2 = worstCase(base);
        vector<int> arr3 = averageCase(base);

        double t1 = measureTime(arr1);
        double t2 = measureTime(arr2);
        double t3 = measureTime(arr3);

        cout <<i<<","<<t1<<","<<t2<<","<<t3<<endl;
    }
    return 0;
}
