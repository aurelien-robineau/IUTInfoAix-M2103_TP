/**
 *
 * \file     TestDureeRelops.cpp
 *
 * \authors  M. Laporte, D. Mathieu
 *
 * \date     01/02/2008
 *
 * \version  V1.0
 *
 * \brief    Test des operateurs de comparaison
 *
 **/
#include <iostream>
#include <iomanip>         // boolalpha
#include <utility>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;
using namespace rel_ops;

#include "duree.h"

using namespace nsUtil;

#define classdef typedef

namespace
{
    void testDuree (void)
    {
        const unsigned KDureeMax = 31536000;

        typedef vector <Duree> CVDuree;
        typedef CVDuree::const_iterator Iter_t;

        CVDuree lesDurees;
        unsigned nbDurees;

        /*Choix nb de durées*/
        cout << "Choisissez le nombre de durees a generer : ";
        cin >> nbDurees;

        /*Génération des durées*/
        srand(time(NULL));
        for (unsigned i = 0; i < nbDurees; i++)
        {
            unsigned nbAlea = rand () % KDureeMax;
            Duree D(nbAlea);
            lesDurees.push_back(D);
        }

        /*Affichage des durées*/
        cout << "Durees :" << endl;
        for (Iter_t Iter (lesDurees.begin()); Iter < lesDurees.end(); ++Iter)
        {
            Iter->display();
            cout << " = " << Iter->getDuree() << endl;
        }

        //Tri des durées
        sort (lesDurees.begin(), lesDurees.end());
        reverse(lesDurees.begin(), lesDurees.end());

        /*Reaffichage des durées*/
        cout << endl << "Durees triees :" << endl;
        for (Iter_t Iter (lesDurees.begin()); Iter < lesDurees.end(); ++Iter)
        {
            Iter->display();
            cout << " = " << Iter->getDuree() << endl;
        }
        cout << endl;

        unsigned dureeATrouver;
        while(true)
        {
            cout << "Duree a trouver : ";
            cin >> dureeATrouver;
            if (dureeATrouver == 0) break;

            if (find(lesDurees.begin(), lesDurees.end(), dureeATrouver) != lesDurees.end())
                cout << "Duree trouvee !";
            else cout << "Duree introuvable...";

            cout << endl;
        }
    } // testDuree()

} // namespace anonyme
