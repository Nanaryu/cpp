#include <iostream>
#include <windows.h>

using namespace std;


void memory_address(HWND hwnd)
{
    HWND* p = NULL;
    for (int i = 0; i < 1000; i++)
    {
        cout << &hwnd[i] << " -> ";
        cout << p << endl;
    }
    delete[] p;
}

int main()
{
    wstring appname;
    cout << "Process name -> ";
    wcin >> appname;
    HWND hwnd;
    LPCWSTR ws;
    ws = appname.c_str();
    hwnd = FindWindow(NULL, ws);
    cout << hwnd << endl;
    HRESULT GetWindowHandle(HWND * hwnd);
    memory_address(hwnd);
    system("pause");
}