class MergeSort : public SortingStrategy {
public:
    void merge(vector<int>& arr, int first, int mid, int last) {
        int n1 = mid - first + 1;
        int n2 = last - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[first + i];

        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + i + 1];

        int i = 0, j = 0, k = first;

        /* As Assigning L[i] and R[i] is complex, we are just checking if our indexes
        passes the limit or not
        */

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        /*
        As we are ending the loop whenever i or j crosses given index, there are more
        elements that needs to be assigned
        */

        //checking and assigning for i index
        while (i < n1) {
            arr[k++] = L[i++];
        }

        //checking and assigning for j index
        while (j < n2) {
            arr[k++] = R[j++];
        }
    }

    void sort(vector<int>& arr) override {

        mergeSort(arr, 0, arr.size() - 1);

    }

private:
    void mergeSort(vector<int>& arr, int first, int last) {
        if (first < last) {
            int mid = (first + last) / 2;
            mergeSort(arr, first, mid);
            mergeSort(arr, mid + 1, last);
            merge(arr, first, mid, last);
        }
    }
};
