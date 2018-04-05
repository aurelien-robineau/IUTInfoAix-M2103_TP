#include "exception.h"

#include <iostream>

using namespace std;

namespace {
    void testException()
    {
        string Libelle;
        int CodErr;

        while (!cin.eof())
        {
            cout << "Saisir libelle de l'exeption : ";
            cin >> Libelle;

            cout << "Saisir code erreur de l'exception : ";
            cin >> CodErr;

            nsUtil::Exception E (Libelle, CodErr);

            E.display();
            cout << endl << endl;
        }
    } // testException
} // namespace
