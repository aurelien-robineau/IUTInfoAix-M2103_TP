/**
 *
 * \file     TestDuree.cpp
 *
 * \authors  M. Laporte, D. Mathieu
 *
 * \date     29/10/2007
 *
 * \version  V1.0
 *
 * \brief    Test des operateurs + et -
 *
 **/
#include <iostream>
#include <iomanip>            // setw()
#include <vector>

using namespace std;

#include "duree.h"

using namespace nsUtil;

#define classdef typedef

namespace
{
    void testDuree (void)
    {
        Duree d1 (123);
        Duree d2 (12);

        d1.display ();
        cout << " + ";
        d2.display ();
        cout << " = ";
        (d1 + d2).display ();
        cout << '\n';

        d2.display ();
        cout << " + ";
        d1.display ();
        cout << " = ";
        (d2 + d1).display ();
        cout << '\n';

        d1.display ();
        cout << " - ";
        d2.display ();
        cout << " = ";
        (d1 - d2).display ();
        cout << '\n';

        d2.display ();
        cout << " - ";
        d1.display ();
        cout << " = ";
        (d2 - d1).display ();
        cout << '\n';

    } // TestCDuree()

} // namespace anonyme
