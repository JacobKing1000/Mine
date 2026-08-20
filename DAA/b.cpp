#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<long long> &a, int left, int right) {
    if (left >= right) return;

    long long pivot = a[left + (right - left) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    quickSort(a, left, j);
    quickSort(a, i, right);
}

bool binarySearch(const vector<long long> &a, long long key) {
    int left = 0, right = a.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == key)
            return true;
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n - 1);

    int q;
    cin >> q;

    while (q--) {
        long long key;
        cin >> key;

        if (binarySearch(a,key))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}