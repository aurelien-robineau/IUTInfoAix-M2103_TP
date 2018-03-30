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
    desDurees.resize(10);

    unsigned sec;
    for (unsigned i = 0; i < desDurees.size(); i++)
    {
        cout << "Entrez une duree en secondes : ";
        cin >> sec;
        cout << endl;

        Duree *D = new Duree (sec);
        desDurees[i] = D;
    }

    for (Duree *duree : desDurees)
    {
        cout << "Nbre sec. " << setw (6) << duree->getDuree ()
             << ", soit : ";
        duree->display ();
        cout << '\n';
    }

    for (Duree *duree : desDurees)
    {
        duree->~Duree();
    }
} // testDureeDeBase
