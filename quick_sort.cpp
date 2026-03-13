#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int> &v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quick_sort(vector<int> &v, int low, int high) {
    if (low < high) {
        int p = partition(v, low, high);
        quick_sort(v, low, p - 1);
        quick_sort(v, p + 1, high);
    }
}

vector<int> generateRandomArray(int size) {
    vector<int> v(size);
    for (int i = 0; i < size; i++) {
        v[i] = rand() % 10000;
    }
    return v;
}
vector<int> bestCase(const vector<int> &v) {
    vector<int> sorted = v; 
    sort(sorted.begin(), sorted.end());
    return sorted;
}
vector<int> worstCase(const vector<int> &v) {
    vector<int> sorted = v; 
    sort(sorted.begin(), sorted.end());
    reverse(sorted.begin(), sorted.end());
    return sorted;
}

double measureTime(vector<int> v) {
    auto st = high_resolution_clock::now();
    quick_sort(v, 0, v.size() - 1);
    auto end = high_resolution_clock::now();
    duration<double> t = end - st;
    return t.count();
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    vector<int> sizes = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    cout<<"Size "<<"Best-Case "<<"Average-Case"<<"Worst-Case"<<endl;
    for (int size : sizes) {
        vector<int> randomArray = generateRandomArray(size);
        vector<int> avgArray = randomArray;
        vector<int> bestArray = bestCase(randomArray);
        vector<int> worstArray = worstCase(randomArray);

        double tavg = measureTime(avgArray);
        double tbest = measureTime(bestArray);
        double tworst = measureTime(worstArray);

        cout << size << " " << tbest << " " << tavg << " " << tworst << endl;
    }
    return 0;
}
