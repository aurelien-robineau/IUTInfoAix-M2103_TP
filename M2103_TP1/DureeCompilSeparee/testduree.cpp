/*
 * Je n'ai pas réussi à régler les dernières erreurs.
 */

#include "duree.h"

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using namespace nsUtil;

void testDureeDeBase ()
{
    vector <Duree *> desDurees;

    unsigned sec;
    while (!cin.fail())
    {
        cout << "Entrez une duree en secondes : ";
        cin >> sec;
        cout << endl;

        Duree D (sec);
        desDurees.push_back(D);
    }

    for (Duree *duree : desDurees)
    {
        cout << "Nbre sec. " << setw (6) << duree->getDuree ()
             << ", soit : ";
        duree->display ();
        cout << '\n';
    }
} // testDureeDeBase
