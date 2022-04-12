#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;

void Merge(vector<int>& array, int lhs, int rhs) {
    vector<int> sorted(array.size());
    int i = lhs, j = (rhs + lhs) / 2 + 1;
    for(int k = 0; k < array.size(); ++k) {
        if (i <= (rhs + lhs) / 2 && (j > rhs || array[i] <= array[j]))
            sorted[k] = array[i++];
        else
            sorted[k] = array[j++];
    }
    for(int k = 0; k < sorted.size(); ++k)
        array[k + lhs] = sorted[k];
}
void MergeSort(vector<int>& array, int lhs, int rhs) {
    if (lhs == rhs)
        return;
    MergeSort(array, lhs, (rhs + lhs) / 2);
    MergeSort(array, (rhs + lhs) / 2 + 1, rhs);
    Merge(array, lhs, rhs);
}
void ByteRadix(vector<int>& array) {
    for(int i = 0; i < 3; ++i) {
        int count[256] = {0};
        for(int j = 0; j < array.size(); ++j) {
            ++count[(array[j] >> (8 * i)) & 255];
        }
        for(int j = 1; j < 256; ++j)
            count[j] += count[j - 1];
        vector<int> ans_array(array.size(), 0);
        for(int j = array.size() - 1; j >= 0; --j) {
            ans_array[--count[(array[j] >> (8 * i)) & 255]] = array[j];
        }
        array = ans_array;
    }
        int count[256] = {0};
        for(int j = 0; j < array.size(); ++j) {
            ++count[(array[j] >> 24) & 255 ^ 128];
        }
        for(int j = 1; j < 256; ++j)
            count[j] += count[j - 1];
        vector<int> ans_array(array.size(), 0);
        for(int j = array.size() - 1; j >= 0; --j) {
            ans_array[--count[(array[j] >> 24) & 255 ^ 128]] = array[j];
        }
        array = ans_array;
}

int main() {
    int n; cin >> n;
    vector<int> ar(n);
    for(int& i : ar)
        cin >> i;
    ByteRadix(ar);
    for(int i : ar)
        cout << i << " ";
    return 0;
}
