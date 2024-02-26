#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


int randint(int min, int max)
{
    return min + rand() % (max-min);
}

void showarr(int *p, int n)
{
    cout << "[";
    for (int i=0;i<n;i++)
    {
        if (i != n - 1)
        {
            cout << p[i] << ", ";
        }
        else
        {
            cout << p[i] << "]" << endl;
        }
    }
}

void genarr(int *p, int n)
{
    for (int i=0;i<n-1;i++)
    {
        p[i] = randint(0, 10);
    }
}

void sortS(int *p, int n)
{
    int i, j, m;
    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if(p[j] < p[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            int t = p[i];
            p[i] = p[m];
            p[m] = t;
        }
    }
}

void sortI(int *p, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = p[i];
        j = i - 1;

        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = key;
    }
}

void sortB(int *p, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }
}
int main()
{
    srand(time(NULL));
    int *p = NULL;

    cout << "Size: ";
    int n = 0;
    cin >> n;

    p = new int[n];

    cout << endl;

    genarr(p, n);
    showarr(p, n);
    sortS(p, n);
    showarr(p, n);

    genarr(p, n);
    showarr(p, n);
    sortI(p, n);
    showarr(p, n);

    genarr(p, n);
    showarr(p, n);
    sortB(p, n);
    showarr(p, n);
}
