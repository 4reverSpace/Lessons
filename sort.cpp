#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
void CheckSort(const string& sort,const vector<int>& array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        if (array[i] > array[i + 1]) {
            cout << sort << " isn't working";
            break;
        }
    }
}

void GenerateNumbers(vector<int> &array, int size) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> num(INT32_MIN, INT32_MAX);
    for (int i = 0; i < size; ++i) {
        array[i] = num(rng);
    }
}

void Merge(vector<int> &array, int lhs, int rhs) {
    vector<int> sorted(rhs - lhs + 1);
    int i = lhs, j = (rhs + lhs) / 2 + 1;
    for (int k = 0; k < sorted.size(); ++k) {
        if (i <= (rhs + lhs) / 2 && (j > rhs || array[i] <= array[j]))
            sorted[k] = array[i++];
        else
            sorted[k] = array[j++];
    }
    for (int k = 0; k < sorted.size(); ++k)
        array[k + lhs] = sorted[k];
}

void MergeSort(vector<int> &array, int lhs, int rhs) {
    if (lhs == rhs)
        return;
    MergeSort(array, lhs, (rhs + lhs) / 2);
    MergeSort(array, (rhs + lhs) / 2 + 1, rhs);
    Merge(array, lhs, rhs);
}

void ByteRadix(vector<int> &array) {
    for (int i = 0; i < 3; ++i) {
        int count[256] = {0};
        for (int j = 0; j < array.size(); ++j) {
            ++count[(array[j] >> (8 * i)) & 255];
        }
        for (int j = 1; j < 256; ++j)
            count[j] += count[j - 1];
        vector<int> ans_array(array.size(), 0);
        for (int j = array.size() - 1; j >= 0; --j) {
            ans_array[--count[(array[j] >> (8 * i)) & 255]] = array[j];
        }
        array = ans_array;
    }
    
    int count[256] = {0};
    for (int j = 0; j < array.size(); ++j) {
        ++count[(array[j] >> 24) & 255 ^ 128];
    }
    for (int j = 1; j < 256; ++j)
        count[j] += count[j - 1];
    vector<int> ans_array(array.size(), 0);
    for (int j = array.size() - 1; j >= 0; --j) {
        ans_array[--count[(array[j] >> 24) & 255 ^ 128]] = array[j];
    }
    array = ans_array;
}

int main() {
    ofstream fout;
    fout.open("text.txt");
    for(int n = 500; n <= 40000; n += 500) {
        vector<int> ar_radix(n);
        GenerateNumbers(ar_radix, n);
        vector<int> ar_merge = ar_radix;
        vector<int> ar_std = ar_radix;
        auto t1_radix = std::chrono::high_resolution_clock::now();
        ByteRadix(ar_radix);
        auto t2_radix = std::chrono::high_resolution_clock::now();
        CheckSort("Radix", ar_radix);
        auto duration_radix = std::chrono::duration_cast<std::chrono::microseconds>(t2_radix - t1_radix);

        auto t1_merge = std::chrono::high_resolution_clock::now();
        MergeSort(ar_merge, 0, n - 1);
        auto t2_merge = std::chrono::high_resolution_clock::now();
        CheckSort("Merge", ar_merge);
        auto duration_merge = std::chrono::duration_cast<std::chrono::microseconds>(t2_merge - t1_merge);

        auto t1_std = std::chrono::high_resolution_clock::now();
        sort(ar_std.begin(), ar_std.end());
        auto t2_std = std::chrono::high_resolution_clock::now();
        auto duration_std = std::chrono::duration_cast<std::chrono::microseconds>(t2_std - t1_std);

        fout << n << " " << duration_radix.count() << " " << duration_merge.count() << " " << duration_std.count() << "\n";
    }
    return 0;
}
