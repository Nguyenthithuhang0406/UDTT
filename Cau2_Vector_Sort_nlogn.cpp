#include<bits/stdc++.h>
using namespace std;

void init (vector<int>& a){
	int n; cin >> n;
	for(int i = 0; i< n; i++){
		int x; cin >> x;
		a.push_back(x);
	}
}

void display(vector<int>& a) {
	for(int x: a){
		cout << x << " ";
	}
}

int sum(vector<int>& a){
	int s = 0;
	for(int x : a){
		s +=  x;
	}
	return s;
}

int max(vector<int>& a){
	int m = INT_MIN;
	for(int x : a){
		m = x > m ? x : m;
	}
	return m;
}

int min(vector<int>& a){
	int m = INT_MAX;
	for(int x : a){
		m = x < m ? x : m;
	}
	return m;
}

// Hàm h?p nh?t (merge) hai m?ng con dã du?c s?p x?p
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    // Copy du lieu vào các mang con
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Hop nhat các mang con lai
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy cac phan con lai leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy cac phan con lai cua rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Hàm MergeSort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

//Dung ham sort
void sort(vector<int>& a){
	sort(a.begin(), a.end());
}
int main(){
	vector<int> a;
	init(a);
	cout << "sum: " << sum(a) << "\n";
	cout << "max: " << max(a) << "\n";
	cout << "min: " << min(a) << "\n";
	mergeSort(a, 0, a.size() - 1);
	cout << "Sau khi sort: ";
	display(a); 
	return 0;
}
