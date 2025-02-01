#include<bits/stdc++.h>
using namespace std;

// Function to merge two sorted halves of an array
void merge(int *arr, int s, int e) {
   if(s >= e) {
      return; // Base case: if the array has 0 or 1 elements, it's already sorted
   }
   int mid = (s + e) / 2; // Find the middle point
   int l1 = mid - s + 1;  // Length of the left half
   int l2 = e - mid;      // Length of the right half

   // Create temporary arrays to hold the two halves
   int* left = new int[l1];
   int* right = new int[l2];

   // Copy data to temporary arrays
   int k = s;
   for (int i = 0; i < l1; i++) {
      left[i] = arr[k];
      k++;
   }
   k = mid + 1;
   for (int i = 0; i < l2; i++) {
      right[i] = arr[k];
      k++;
   }

   // Merge the two halves back into the original array
   int i = 0, j = 0, m = s;
   while (i < l1 && j < l2) {
      if (right[j] <= left[i]) {
         arr[m++] = right[j++];
      } else {
         arr[m++] = left[i++];
      }
   }

   // Copy any remaining elements of left[], if any
   while (i < l1) {
      arr[m++] = left[i++];
   }

   // Copy any remaining elements of right[], if any
   while (j < l2) {
      arr[m++] = right[j++];
   }

   // Free up the allocated memory
   delete[] left;
   delete[] right;
}

// Recursive function to perform merge sort on an array
void mergesort(int *arr, int s, int e) {
   if (s >= e) {
      return; // Base case: if the array has 0 or 1 elements, it's already sorted
   }
   
   int mid = (s + e) / 2;
   
   // Sort the left half
   mergesort(arr, s, mid);
   // Sort the right half
   mergesort(arr, mid + 1, e);

   // Merge the sorted halves
   merge(arr, s, e);
}

// Function to partition the array for quicksort
int pivotind(int arr[], int s, int e) {
   int i = s - 1;
   int j = s;
   while(j < e) {
      if(arr[j] < arr[e]) {
         i++;
         swap(arr[i], arr[j]);
      }
      j++;
   }
   
   // Place the pivot element in the correct position
   swap(arr[e], arr[i + 1]);
   
   return i + 1; // Return the pivot index
}

// Recursive function to perform quicksort on an array
void quicksort(int arr[], int s, int e) {
   if(s >= e) {
      return; // Base case: if the array has 0 or 1 elements, it's already sorted
   }
   // Partition the array and get the pivot index
   int p = pivotind(arr, s, e);

   // Recursively sort elements before and after partition
   quicksort(arr, s, p - 1);
   quicksort(arr, p + 1, e);
}

// Function to generate permutations of a string using backtracking
void permstr(string &s, int i) {
   if(i >= s.length()) {
      cout << s << endl; // Base case: if all positions are fixed, print the permutation
      return;
   }

   for (int j = i; j < s.length(); j++) {
      // Swap the current element with the element at the current position
      swap(s[j], s[i]);
      // Recur for the next position
      permstr(s, i + 1);
      // Backtrack by swapping back the elements
      swap(s[j], s[i]);
   }
}

int main() {
   // Example usage of merge sort
   // int arr[] = {7, 3, 2, 16, 24, 4, 11, 9};
   // int s = 0;
   // int e = 7;
   // mergesort(arr, s, e);
   // for (int p = 0; p < 8; p++) {
   //    cout << arr[p] << " ";
   // }

   // Example usage of quicksort
   // int arr[] = {0, 1, 3, 4, 10, 50, 40};
   // int s = 0;
   // int e = 6;
   // quicksort(arr, s, e);
   // for (int i = 0; i < e + 1; i++) {
   //    cout << arr[i] << " ";
   // }

   // Example usage of generating permutations
   // string s = "abc";
   // int i = 0;
   // permstr(s, i);

   // Placeholder for other functionalities like N-Queen or count inversions

   return 0;
}
