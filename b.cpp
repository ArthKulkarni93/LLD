#include<bits/stdc++.h>
using namespace std;

void print (vector<int>&v) {
    for (auto &it: v)
        cout << it << " ";
    cout << "\n";
}

void selection_sort (vector<int>&v) {
    int mini, miniIdx;
    for (int i = 0; i < v.size(); i++) {
        mini = INT_MAX, miniIdx = i;

        for (int j = i; j < v.size(); j++) {
            if (v[j] < mini) {
                mini = v[j];
                miniIdx = j;
            }
        }

        swap (v[i], v[miniIdx]);
    }
}

void bubble_sort (vector<int>&v) {
    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1])
                swap (v[j], v[j + 1]);
        }
    }
}

void insertion_sort (vector<int>&v) {
    for (int i = 1; i < v.size(); i++) {
        int j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            swap (v[j], v[j - 1]);
            j--;
        }
    }
}

void merge (vector<int>&v, int start, int mid, int end) {
    vector<int>temp;
    int left = start, right = mid + 1;

    while (left <= mid && right <= end) {
        if (v[left] <= v[right]) {
            temp.push_back (v[left]);
            left++;
        } else {
            temp.push_back (v[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back (v[left]);
        left++;
    }
    while (right <= end) {
        temp.push_back (v[right]);
        right++;
    }

    for (int i = 0; i < temp.size(); i++) 
        v[i + start] = temp[i];
}

void merge_sort (vector<int>&v, int start, int end) {
    if (start >= end)
        return;
    
    int mid = (start + end ) / 2;
    merge_sort (v, start, mid);
    merge_sort (v, mid + 1, end);
    merge (v, start, mid, end);
}

int get_pivot (vector<int>&v, int start, int end){
    int left = start, right = end, pivot = v[start];

    while (left < right) {
        while (left <= end && v[left] <= pivot)
            left++;
        while (right >= start && v[right] > pivot)
            right--;
        if (left < right)
            swap (v[left], v[right]);
    }

    swap (v[right], v[start]);
    return right;
}

void quick_sort (vector<int>&v, int start, int end) {
    if (start >= end)
        return;

    int pivot = get_pivot (v, start, end);
    quick_sort (v, start, pivot - 1);
    quick_sort (v, pivot + 1, end);
}

void sieve (int n) {
    if (n < 2)
        return;
    vector<int>v (n + 1, 1);
    v[0] = 0;
    v[1] = 0;

    for (int i = 2; i * i <= v.size(); i++) {
        if (v[i])  {
            for (int j = i + i; j < v.size(); j += i)
                v[j] = 0;
        }
    }

    for (int i = 0; i < v.size(); i++) 
        if (v[i])
            cout << i << " ";
}

int main() {
    vector<int>v{5,23235,235,567,678,789,344,12,4,67,8,96,32};



    // sieve (100);
    // vector<int>a = v;
    // selection_sort (a);
    // print (a);

    // vector<int>b = v;
    // bubble_sort (b);
    // print (b);

    // vector<int>c = v;
    // insertion_sort (c);
    // print (c);

    // vector<int>d = v;
    // merge_sort (d, 0, d.size() - 1);
    // print (d);

    // vector<int>e = v;
    // quick_sort (e, 0, d.size() - 1);
    // print (e);

}