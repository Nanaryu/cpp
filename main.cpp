#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int randint(int from, int to)
{
	return ((to - from) * double(rand()) / RAND_MAX) + from;
}

void menu_construct()
{
	cout << "1. Add Element" << endl;
	cout << "2. Delete Element" << endl;
	cout << "3. Insert Element" << endl;
	cout << "4. Show Array" << endl;
	cout << "5. Exit Program" << endl;
	cout << "" << endl;
	cout << "Choice: ";
}

void showarr(int *pointer, int n)
{
	cout << "[";
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1) {
			cout << pointer[i] << ", ";
		}
		else
		{
			cout << pointer[i] << "]" << endl;
		}
	}
}

int main()
{
	srand(time(NULL));

	int* p = NULL;
	int size = 10;

	cout << "Array Initial Length: ";
	cin >> size;
	system("cls");

	p = new int[size];

	for (int i = 0; i < size; i++)
	{
		p[i] = randint(0, 10);
	}

	bool active = true;
	while (active) {
		int n = NULL;
		menu_construct();
		cin >> n;
		switch (n) {
		case 1:
			{
				int* new_pointer = NULL;
				new_pointer = new int[size + 1];
				for (int i = 0; i < size; i++)
				{
					new_pointer[i] = p[i];
				}
				int e = 0;
				cout << "Value: ";
				cin >> e;
				new_pointer[size] = e;
				delete[] p;
				p = new_pointer;
				size++;
			}
			break;
		case 2:
			{
				int* new_pointer = NULL;
				int* new_new_pointer = NULL;
				new_pointer = new int[size];
				int e = 0;
				cout << "Value: ";
				cin >> e;
				bool triggered = false;
				bool one_instance = false;
				for (int i = 0; i < size; i++)
				{
					if (p[i] == e)
					{
						if (!triggered && !one_instance) {
							triggered = true;
							one_instance = true;
							continue;
						}
						else
						{
						    new_pointer[i-1] = p[i];
							break;
						}
					}
					else
					{
						if (!triggered) {
                                if (!one_instance) {
                                    new_pointer[i] = p[i];
                                }
                                else
                                {
                                    new_pointer[i-1] = p[i];
                                }
						}
						else
						{
							new_pointer[i-1] = p[i];
						}
					}
				}
				if (triggered) {
					size--;
				}
				new_new_pointer = new int[size];
				for (int i = 0; i < size; i++)
				{
					new_new_pointer[i] = new_pointer[i];
				}
				delete[] p;
				p = new_new_pointer;
			}
			break;
		case 3:
		    {
		        int e = 0;
		        int place = 0;
		        bool triggered = false;
                cout << "Value: ";
                cin >> e;
                cout << "Place: ";
                cin >> place;
		        int* new_pointer = NULL;
                new_pointer = new int[size + 1];
                for (int i = 0; i < size; i++)
                {
                    if (i==place && !triggered) {
                        new_pointer[i] = e;
                        triggered = true;
                    }
                    if (triggered)
                    {
                        new_pointer[i+1] = p[i];
                    }
                    else
                    {
                        new_pointer[i] = p[i];
                    }
                }

                delete[] p;
                p = new_pointer;
                size++;
		    }
			break;
		case 4:
			showarr(p, size);
			break;
		case 5:
			active = false;
			break;
		default:
			cout << "Option not available.";
			break;
		}
		system("pause");
		system("cls");
	}
}
