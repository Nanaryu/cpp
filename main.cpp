#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int randint(int from, int to)
{
	return ((to - from) * double(rand()) / RAND_MAX) + from;
}

string strm(int amount, string str)
{
    string r_str = str;
    for (int i=0; i < amount; i++)
    {
        r_str += str;
    }
    return r_str;
}

void menu_construct()
{
    cout << strm(3, "\n");
    cout << strm(47, " ") << strm(20, "=") << endl;
	cout << strm(48, " ") << "[1]. Add Element" << endl;
	cout << strm(48, " ") << "[2]. Delete Element" << endl;
	cout << strm(48, " ") << "[3]. Insert Element" << endl;
	cout << strm(48, " ") << "[4]. Show Array" << endl;
	cout << strm(48, " ") << "[5]. Write to file" << endl;
	cout << strm(48, " ") << "[6]. Read from file" << endl;
	cout << strm(48, " ") << "[0]. Exit Program" << endl;
	cout << strm(47, " ") << strm(20, "=") << endl;
	cout << strm(48, " ") << "[X]. Choice: ";
}


void showarr(int *pointer, int n)
{
    cout << "\n " << strm(48, " ");
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

    cout << strm(3, "\n");
	cout << strm(48, " ") <<"Array Initial Length: ";
	cin >> size;
	system("cls");

	p = new int[size];

	for (int i = 0; i < size; i++)
	{
		p[i] = randint(0, 10);
	}

	while (true) {
		int n = NULL;
		menu_construct();
		cin >> n;
		switch (n) {
        case 0:
			return 0; // exit
		case 1:
			{
				int* new_pointer = NULL;
				new_pointer = new int[size + 1];
				for (int i = 0; i < size; i++) {new_pointer[i] = p[i];}
				int e = 0;
				cout << "\n" <<strm(48, " ") << "Value: ";
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
				cout << "\n" <<strm(48, " ") << "Value: ";
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
                cout << "\n" <<strm(48, " ") << "Value: ";
                cin >> e;
                cout << "\n" <<strm(48, " ") << "Place: ";
                cin >> place;
		        int* new_pointer = NULL;
                new_pointer = new int[size + 1];
                for (int i = 0; i < size; i++)
                {
                    if (i==place && !triggered) {
                        new_pointer[i] = e;
                        triggered = true;
                    }

                    if (triggered) {new_pointer[i + 1] = p[i];}
                    else {new_pointer[i] = p[i];}
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
            {
                fstream file;
                fstream bak;
                file.open("C:\\users\\student\\desktop\\test.txt", ios::out | ios::trunc);
                if (file.is_open())
                {
                    for(int i = 0; i < size; i++)
                    {
                        if(i != size - 1)
                        {
                            file << p[i] << endl;
                        }
                        else
                        {
                            file << p[i];
                        }
                    }
                    file.close();
                }
            }
            break;
        case 6:
            {
                fstream file;
                file.open("C:\\users\\student\\desktop\\test.txt", ios::in);
                if(file.is_open())
                {
                    string str;
                    int indicator = 0;

                    while(!file.eof())
                    {
                        getline(file, str);
                        indicator++;
                    }

                    int* new_pointer = NULL;
                    new_pointer = new int[indicator];
                    size = indicator;
                    indicator = 0;
                    file.clear();
                    file.seekg(0);

                    while(!file.eof())
                    {
                        getline(file, str);
                        new_pointer[indicator] = atoi(str.c_str());
                        indicator++;
                    }
                    delete[] p;
                    p = new_pointer;
                }
                file.close();
            }
            break;
		default:
			cout << "\n" <<strm(48, " ") << "Option not available." << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}
