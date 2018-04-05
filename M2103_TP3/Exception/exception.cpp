#include "exception.h"

#include <iostream>

using namespace std;

namespace nsUtil {
    Exception::Exception (const std::string & Libelle, const unsigned & CodErr)
    {
        myLibelle = Libelle;
        myCodErr = CodErr;
    } // Execption

    Exception::~Exception () {}

    string Exception::getmyLibelle()
    {
        return myLibelle;
    } // getmyLibelle

    unsigned Exception::getmyCodErr()
    {
        return myCodErr;
    } // getmyCodErr

    const char* Exception::what() const noexcept
    {
        return myLibelle.c_str();
    } // what

    void Exception::display()
    {
        cout << "Exception : " << myLibelle << endl;
        cout << "Code : " << myCodErr;
    } // display
}
