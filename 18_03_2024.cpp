#include <iostream>

using namespace std;

void showArr(int arr[], int n)
{
    cout << "[";
    for(int i = 0; i < n;i++)
    {
        if (i!=n-1)
        {
            cout << arr[i] << ", ";
        }
        else
        {
            cout << arr[i] << "]";
        }
    }
    cout << endl;
}

// merge sort
void sortM(int arr[], int n)
{
    if (n > 1)
    {
        int q = n/2;

        int nL, nR;

        if ((n - q) > q)
        {
            nL = n - q;
            nR = q;
        }
        else
        {
            nL = q;
            nR = q;
        }

        int* L = new int[nL];
        for (int i = 0; i < nL; i++)
        {
            L[i] = arr[i];
        }

        int* R = new int[nR];
        for (int i = 0; i < nR; i++)
        {
            R[i] = arr[i+nL];
        }

        sortM(L, nL);
        sortM(R, nR);

        int l = 0; int r = 0; int k = 0;

        while (l < nL && r < nR)
        {
            if (L[l] < R[r])
            {
                arr[k] = L[l];
                l++;
            }
            else
            {
                arr[k] = R[r];
                r++;
            }
            k++;
        }

        while (l < nL)
        {
            arr[k] = L[l];
            l++;
            k++;
        }
        while (r < nR)
        {
            arr[k] = R[r];
            r++;
            k++;
        }
        delete[] L;
        delete[] R;
    }
}

// quicksort
void sortQ(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int j = low;
        for (int i = low; i < high; i++)
        {
            if (arr[i] < pivot)
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;

                j++;
            }
        }
        int t = arr[high];
        arr[high] = arr[j];
        arr[j] = t;

        sortQ(arr, low, j-1);
        sortQ(arr, j+1, high);
    }
}

int main()
{
    int tab[5] = {1,4,3,5,2};
    cout << "Not sorted: ";
    showArr(tab, 5);
    sortM(tab, 5);
    cout << "Merge sort: ";
    showArr(tab, 5);

    int tab2[5] = {1,4,3,5,2};
    cout << "Not sorted: ";
    showArr(tab2, 5);
    sortQ(tab2, 0, 4);
    cout << "Quicksort: ";
    showArr(tab2, 5);
}
