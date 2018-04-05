/**
 *
 * \file     TestString.cpp
 *
 * \authors  M. Laporte, D. Mathieu
 *
 * \date     05/11/2007
 *
 * \version  V1.0
 *
 * \brief    Test de la classe String, extension de String
 *
 **/

#include <iostream>

#include "string.h"

using namespace std;
using namespace nsUtil;

namespace
{
    void testString (void)
    {
        cout << "Test des constructeurs\n\n";

        String s1;
        cout << '"' << s1 << "\"\n";
        cout << s1.append ("s1") << '\n';
        String s2 ("Coucou");
        cout << (s2 + ' ' + s1) << '\n';
        String s3 ("Coucou", 4);
        cout << s3 << '\n';
        String s4 (10, '#');
        cout << s4 << '\n';

        String s5 ("AbCdEf1234");
        cout << s5 << '\n';
        cout << s5.toupper() << '\n';
        cout << s5 << '\n';
        cout << s5.tolower() << '\n';
        cout << s5 << '\n';

        cout << "\nTest des fonctions\n\n";
        String STR ("MAJUSCULE");
        String str ("minuscule");
        String space ("  \t\t\n\n");

        cout << boolalpha;

        cout << str   << " alpha ? "  << str.isalpha   () << '\n';
        cout << str   << " alnum ? "  << str.isalnum   () << '\n';
        cout << str   << " digit ?  " << str.isdigit   () << '\n';
        cout << str   << " xdigit ? " << str.isxdigit  () << '\n';
        cout << str   << " lower ? "  << str.islower   () << '\n';
        cout << str   << " upper ? "  << str.isupper   () << '\n';
        cout << str   << " space ? "  << str.isspace   () << '\n';
        cout << STR   << " upper ? "  << STR.isupper   () << '\n';
        cout << str   << " lower ? "  << str.islower   () << '\n';
        cout << space << " space ? "  << space.isspace () << '\n';

        cout << noboolalpha;

    } // testString ()

} // namespace
