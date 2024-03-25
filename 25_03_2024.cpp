#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void arr_display(int* arr, int arr_size)
{
    cout << "[";
    for (int i = 0; i < arr_size; i++)
    {
        if (i != arr_size - 1)
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

int randint(int v_min, int v_max)
{
	return (int) (v_max - v_min) * ((double) rand() / RAND_MAX) + v_min;
}

void pick_value(int* arr, int arr_size, int index, int remaining_size)
{
    int* dupe_list = NULL;
    if (!dupe_list)
    {
        dupe_list = new int[arr_size];
        for (int i = 0; i < arr_size; i++)
        {
            dupe_list[i] = i;
        }
        int random_index = randint(0, remaining_size);
        arr[index] = dupe_list[random_index];
        remaining_size--;
        int* dupe_list2 = new int(remaining_size);

        bool passed = false;
        for(int i = 0; i < remaining_size; i++)
        {
            if (i != random_index)
            {
                dupe_list2[i] = dupe_list[i];
            }
            else
            {
                passed = true;
            }

            if (passed)
            {
                dupe_list2[i] = dupe_list[i+1];
            }
            else
            {
                dupe_list2[i] = dupe_list[i];
            }
        }
        dupe_list = dupe_list2;
        delete[] dupe_list2;
    }
    else
    {
        int random_index = randint(0, remaining_size);
        arr[index] = dupe_list[random_index];
        remaining_size--;
        int* dupe_list2 = new int(remaining_size);

        bool passed = false;
        for(int i = 0; i < remaining_size; i++)
        {
            if (i != random_index)
            {
                dupe_list2[i] = dupe_list[i];
            }
            else
            {
                passed = true;
            }

            if (passed)
            {
                dupe_list2[i] = dupe_list[i+1];
            }
            else
            {
                dupe_list2[i] = dupe_list[i];
            }
        }
        dupe_list = dupe_list2;
        delete[] dupe_list2;
    }
}

bool has(int *arr, int arr_size, int value)
{

}

int random(int* arr, int arr_size, int v_min, int v_max, bool is_duplicate, int sort_mode)
{
    if (is_duplicate)
    {
        switch(sort_mode)
        {
        case 0:
            {
                for (int i = 0; i < v_max; i++)
                {
                    arr[i] = randint(v_min, v_max);
                }
                break;
            }
        case 1:
            {
                for (int i = 0; i < v_max; i++)
                {
                    if (i > 0)
                    {
                        arr[i] = randint(arr[i-1], v_max);
                    }
                    else
                    {
                        arr[i] = randint(v_min, v_max);
                    }
                }
                break;
            }
        case 2:
            {
                for (int i = 0; i < v_max; i++)
                {
                    if (i > 0)
                    {
                        arr[i] = randint(v_min, arr[i-1]);
                    }
                    else
                    {
                        arr[i] = randint(v_min, v_max);
                    }
                }
                break;
            }
        }
    }
    else
    {
        switch(sort_mode)
        {
        case 0:
            {
                for (int i = 0; i < v_max; i++)
                {
                     pick_value(arr, arr_size, i, arr_size - i);
                }
                break;
            }
        case 1:
            {
                for (int i = 0; i < v_max; i++)
                {
                    if (i > 0)
                    {
                        arr[i] = randint(arr[i-1], v_max);
                    }
                    else
                    {
                        arr[i] = randint(v_min, v_max);
                    }
                }
                break;
            }
        case 2:
            {
                for (int i = 0; i < v_max; i++)
                {
                    if (i > 0)
                    {
                        arr[i] = randint(v_min, arr[i-1]);
                    }
                    else
                    {
                        arr[i] = randint(v_min, v_max);
                    }
                }
                break;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int* arr = NULL;
    int arr_size = 100;
    //cout << "Array size: ";
    //cin >> arr_size;
    arr = new int[arr_size];
    int v_min = 0;
    //cout << "Min value: ";
    //cin >> v_min;
    int v_max = 100;
    //cout << "Max value: ";
    //cin >> v_max;
    bool is_duplicate = false;
    int sort_mode = 0;

    random(arr, arr_size, v_min, v_max, is_duplicate, sort_mode);

    arr_display(arr, arr_size);

    if (arr) delete[] arr;
}
