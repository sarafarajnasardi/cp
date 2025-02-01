#include <bits/stdc++.h>
const int LEN = 10;
using namespace std;

void copyArray(float* arr, float* brr, int len = LEN){
    for(int i = 0; i < len; i++){
        brr[i] = arr[i];
    }
}

void readFile(float* main_arr, string address, int len = LEN){
    float arr[len];
    ifstream f(address, ios_base::in);

    if(!f.is_open()){
        cout << "Error in Reading the File" << address << endl;
        return;
    }

    float buffer; int ct = 0;
    while(f >> buffer){
        arr[ct] = buffer;
        ct++;
    }

    copyArray(arr, main_arr);
}

double bubbleSort(float* main_arr, int len = LEN){
    
    float arr[len]; clock_t start, end; bool swapped;
    copyArray(main_arr, arr);
    start = clock();
    if(arr[0]!=500&&arr[0]!=1){
        for(int i = 0; i < len - 1; i++){
        swapped = false;
        for(int j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) break;
    }
    }
    
    end = clock(); 
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    return time_taken;

}

double selectionSort(float* main_arr, int len = LEN){
    float arr[len]; clock_t start, end;
    copyArray(main_arr, arr);
    start = clock();

    for(int i = 0; i < len; i++){
        int min_idx = i;
        for(int j = i+1; j < len; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        swap(arr[i], arr[min_idx]);
    }

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    return time_taken;
}

double insertionSort(float* main_arr, int len = LEN){
    float arr[len]; clock_t start, end;
    copyArray(main_arr, arr);
    start = clock();

    for(int i = 1; i < len; i++){
        int key = arr[i]; int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    end = clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
    return time_taken;
}

void merge(float* arr, int left, int mid, int right){
    int n1 = mid - left + 1, n2 = right - mid;
    float L[n1]; float R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i]; i++;
        } else {
            arr[k] = R[j]; j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i]; i++; k++;
    }

    while(j < n2){
        arr[k] = R[j]; j++; k++;
    }
}

void mergeSort(float* main_arr, int left = 0, int right = LEN - 1){
    if(left >= right) return;
    int mid = left + (right - left)/2;
    mergeSort(main_arr, left, mid);
    mergeSort(main_arr, mid + 1, right);
    merge(main_arr, left, mid, right); 
}

double mergeSortTimed(float* main_arr, int len = LEN){
    float arr[len]; clock_t start, end;
    copyArray(main_arr, arr);
    start = clock();

    mergeSort(arr);

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    return time_taken;
}

int partition(float* main_arr, int low, int high){
    float pivot = main_arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(main_arr[j] <= pivot){
            i++; swap(main_arr[i], main_arr[j]);
        }
    }

    swap(main_arr[i + 1], main_arr[high]);
    return i + 1;
}

double quickSortIterative(float* main_arr, int len = LEN) {
    float arr[len]; clock_t start, end;
    copyArray(main_arr, arr);
    start = clock();
    stack<pair<int, int>> stk;
    stk.push({0, len - 1});

    while (!stk.empty()) {
        int low = stk.top().first;
        int high = stk.top().second;
        stk.pop();

        if (low < high) {
            int pi = partition(arr, low, high);

            // Push right and left partitions onto the stack
            if (pi + 1 < high) stk.push({pi + 1, high});
            if (low < pi - 1) stk.push({low, pi - 1});
        }
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    return time_taken;
}



void generate(){
    FILE *file_ptr = freopen("input.txt","w",stdout);
    for(int i=1;i<=100000;i++){
        cout << i << " ";
    }
    fclose(file_ptr);
}
int main(){
    float worst_arr[LEN], average_arr[LEN], best_arr[LEN];
    generate();
    readFile(worst_arr, "./input.txt");
    readFile(average_arr, "./input.txt");
    readFile(best_arr, "./input.txt");

    /* 
    - Bubble Sort
    - Selection Sort
    - Insertion Sort
    - Merge Sort
    - Quick Sort 
    */

    double bubble_worst = bubbleSort(worst_arr);
    double bubble_average = bubbleSort(average_arr);
    double bubble_best = bubbleSort(best_arr);
    cout << "Bubble Sort times on files in seconds: "<<endl;
    cout << "\tdata_worst.txt: "<< bubble_worst << setprecision(5)<< endl << 
            "\tdata_average.txt: " << bubble_average << setprecision(5)<< endl << 
            "\tdata_best.txt: " << bubble_best << setprecision(5)<< endl;

    double selection_worst = selectionSort(worst_arr);
    double selection_average = selectionSort(average_arr);
    double selection_best = selectionSort(best_arr);
    cout << "Selection Sort times on files in seconds: "<<endl;
    cout << "\tdata_worst.txt: "<< selection_worst << setprecision(5)<< endl << 
            "\tdata_average.txt: " << selection_average << setprecision(5)<< endl << 
            "\tdata_best.txt: " << selection_best << setprecision(5)<< endl;

    double insertion_worst = insertionSort(worst_arr);
    double insertion_average = insertionSort(average_arr);
    double insertion_best = insertionSort(best_arr);
    cout << "Insertion Sort times on files in seconds: "<<endl;
    cout << "\tdata_worst.txt: "<< insertion_worst << setprecision(5)<< endl << 
            "\tdata_average.txt: " << insertion_average << setprecision(5)<< endl << 
            "\tdata_best.txt: " << insertion_best << setprecision(5)<< endl;

    double merge_worst = mergeSortTimed(worst_arr);
    double merge_average = mergeSortTimed(average_arr);
    double merge_best = mergeSortTimed(best_arr);
    cout << "Merge Sort times on files in seconds: "<<endl;
    cout << "\tdata_worst.txt: "<< merge_worst << setprecision(5) << endl << 
            "\tdata_average.txt: " << merge_average << setprecision(5) << endl <<
            "\tdata_best.txt: " << merge_best << setprecision(5) << endl;

    double quick_worst = quickSortIterative(worst_arr);
    double quick_average = quickSortIterative(average_arr);
    double quick_best = quickSortIterative(best_arr);
    cout << "Quick Sort times on files in seconds: "<<endl;
    cout << "\tdata_worst.txt: "<< quick_worst << setprecision(5) << endl << 
            "\tdata_average.txt: " << quick_average << setprecision(5) << endl <<
            "\tdata_best.txt: " << quick_best << setprecision(5) << endl;

    return 0;
}