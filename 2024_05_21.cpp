#include <iostream>
#include <stdlib.h>

#define WL 100

using namespace std;

class worker
{
protected:
    string name, sname;
    //int exp;
public:
    worker()
    {
        name = "";
        sname = "";
    }
    worker(string n, string sn)
    {
        name = n;
        sname = sn;
    }
    virtual void desc()
    {
        cout << "Worker -> " << name << " " << sname << endl;
    }
};

class tester : public worker
{
public:
    tester()
    {
        name = "";
        sname = "";
    }
    tester(string n, string sn)
    {
        name = n;
        sname = sn;
    }
    void desc()
    {
        cout << "Tester -> " << name << " " << sname << endl;
    }
};

class backend : public worker
{
public:
    backend()
    {
        name = "";
        sname = "";
    }
    backend(string n, string sn)
    {
        name = n;cout << "1 -> Add worker " << endl;
        cout << "2 -> Exit program " << endl;
        sname = sn;
    }
    void desc()
    {
        cout << "Back-End -> " << name << " " << sname << endl;
    }
};

class frontend : public worker
{
public:
    frontend()
    {
        name = "";
        sname = "";
    }
    frontend(string n, string sn)
    {
        name = n;
        sname = sn;
    }
    void desc()
    {
        cout << "Front-End -> " << name << " " << sname << endl;
    }
};

class dbmng : public worker
{
public:
    dbmng()
    {
        name = "";
        sname = "";
    }
    dbmng(string n, string sn)
    {
        name = n;
        sname = sn;
    }
    void desc()
    {
        cout << "DB Manager -> " << name << " " << sname << endl;
    }
};

int nxtfree(worker* workers[])
{
    for (int i = 0; i < WL; i++)
    {
        if (workers[i]) continue;
        else return i;
    }
}

int main()
{
    worker* workers[WL] = {};

    bool on = true;
    while (on)
    {
        cout << "1 -> Add worker " << endl;
        cout << "2 -> Exit program " << endl;
        cout << " " << endl;

        int choice;
        cout << "Input -> ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                cout << "== Choose profession == " << endl;
                cout << " 1 -> Worker " << endl;
                cout << " 2 -> Tester " << endl;
                cout << " 3 -> Back-End " << endl;
                cout << " 4 -> Front-End" << endl;
                cout << " 5 -> DB Manager " << endl;
                cout << " 6 -> Exit " << endl;
                cout << " " << endl;
                cout << "Input -> ";
                int wchoice;
                cin >> wchoice;
                switch (wchoice)
                {
                case 1:
                    {
                        string n, sn;
                        cout << "Name -> ";
                        cin >> n;
                        cout << endl << "Surname -> ";
                        cin >> sn;

                        workers[nxtfree(workers)] = new worker(n, sn);
                        system("cls");
                    }
                    break;
                case 2:
                    {
                        string n, sn;
                        cout << "Name -> ";
                        cin >> n;
                        cout << endl << "Surname -> ";
                        cin >> sn;

                        workers[nxtfree(workers)] = new tester(n, sn);
                        system("cls");
                    }
                    break;
                case 3:
                    {
                        string n, sn;
                        cout << "Name -> ";
                        cin >> n;
                        cout << endl << "Surname -> ";
                        cin >> sn;

                        workers[nxtfree(workers)] = new backend(n, sn);
                        system("cls");
                    }
                    break;
                case 4:
                    {
                        string n, sn;
                        cout << "Name -> ";
                        cin >> n;
                        cout << endl << "Surname -> ";
                        cin >> sn;

                        workers[nxtfree(workers)] = new frontend(n, sn);
                        system("cls");
                    }
                    break;
                case 5:
                    {
                        string n, sn;
                        cout << "Name -> ";
                        cin >> n;
                        cout << endl << "Surname -> ";
                        cin >> sn;

                        workers[nxtfree(workers)] = new dbmng(n, sn);
                        system("cls");
                    }
                    break;
                case 6:
                    {
                        break;
                    }
                }
            }
            break;
        case 2:
            {
                on = false;
            }
            break;
        }
    }

    for (int i = 0; i < WL; i++)
    {
        if (workers[i]) workers[i]->desc();
    }
}
