#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int medianOfThree(int a, int b, int c){
    if (a <= b && b <= c){
        return b;
    }
    else if (b <= a && a <= c){
        return a;
    }
    else{
        return c;
    }
}

void insertSort(vector <int> &arr,int l, int r){
    for(int i=l + 1;i<r;i++){
        for(int j=i; j>l && arr[j-1]>arr[j];j--){
            int tmp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=tmp;
        }
    }
}


void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


void introSortReal (vector <int> &arr, int b, int e, int deep)
{
    int l = b, r = e;
    if (deep == 0){
        heapSort(arr, arr.size());
        return;
    }
    if (e - b < 16){
        insertSort(arr, b, e);
        return;
    }
    int piv = medianOfThree(arr[l], arr[(l + r) / 2], arr[r]); // Опорным элементом для примера возьмём средний
    while (l <= r)
    {
        while (arr[l] < piv)
            l++;
        while (arr[r] > piv)
            r--;
        if (l <= r)
            swap (arr[l++], arr[r--]);
    }
    if (b < r)
        introSortReal (arr, b, r, deep - 1);
    if (e > l)
        introSortReal (arr, l, e, deep - 1);
}

void introSort(vector <int> &arr){
    long deep = 2 * log(arr.size());
    introSortReal(arr, 0, arr.size(), deep);
}
int main(){
    vector<int> arr = {12, 123, 45, 23, 2, -21, 567, 12};
    int n = arr.size();
    introSort(arr);
    for (auto x:arr){
        cout << x << " ";
    }
}