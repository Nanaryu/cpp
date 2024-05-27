#include <iostream>
#include <math.h>

#define glowny main
#define srednik ;
#define wypisz cout
#define obiekt <<
#define wartosc >>
#define przypisz cin
#define enter endl
#define dla for
typedef int liczba srednik
typedef float splawik srednik
typedef double podwojny srednik
typedef bool logiczny srednik
#define dlugi long
#define pustka void
#define NIC NULL
#define bedzie =
#define jest ==
#define mniejszeod <
#define wiekszeod >
#define jezeli if
#define inaczej else
#define zwroc return
#define pierwiastek sqrt
#define nowa new
#define uzywajac using
#define przestrzennazw namespace
#define prawda true
#define falsz false
#define dopoki while
#define standardowa std
#define skasuj delete

uzywajac przestrzennazw standardowa;

liczba glowny()
{
    liczba n srednik
    wypisz obiekt "Rozmiar: " srednik
    przypisz wartosc n srednik

    logiczny* A bedzie NIC srednik
    A = nowa logiczny[n] srednik

    dla (liczba i bedzie 0 srednik i mniejszeod 100 srednik i++)
    {
        A[i] bedzie prawda srednik
    }

    liczba wielokrotnosc bedzie 0 srednik

    jezeli (A)
    {
        dla (liczba i bedzie 2 srednik i mniejszeod pierwiastek(n) srednik i++)
        {
            jezeli(A[i] jest prawda)
            {
                wielokrotnosc bedzie i srednik
                dopoki (wielokrotnosc + i mniejszeod 101)
                {
                    wielokrotnosc += i srednik
                    A[wielokrotnosc] bedzie falsz srednik
                }
                wielokrotnosc bedzie 0 srednik
            }
        }

        dla (liczba i bedzie 3 srednik i mniejszeod 101 srednik i++)
        {
            jezeli (A[i])
            {
                wypisz obiekt i obiekt " " srednik
            }
        }
        skasuj[] A srednik
    }
}
