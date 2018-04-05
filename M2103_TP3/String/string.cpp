#include "string.h"

#include <ctype.h>

using namespace std;

namespace nsUtil {

    String::String () : string () {}
    String::String (const char * NTCTS): string (NTCTS) {}
    String::String (const char * NTCTS, size_type size) : string (NTCTS, size) {}
    String::String (const std::string & S, size_type pos, size_type size) : string (S, pos, size) {}
    String::String (size_type size, char c) : string (size, c) {}

    String String::tolower()
    {
        String newString;

        for (char &c : (*this))
        {
            char cLow = std::tolower(c);
            newString.push_back(cLow);
        }
        return newString;
    } // tolower

    String String::toupper()
    {
        String newString;

        for (char &c : (*this))
        {
            char cUp= std::toupper(c);
            newString.push_back(cUp);
        }
        return newString;
    } // toupper

    bool String::isalpha()
    {
        for (char &c : (*this))
            if (!std::isalpha(c)) return false;

        return true;
    } // isalpha

    bool String::isdigit()
    {
        for (char &c : (*this))
            if (!std::isdigit(c)) return false;

        return true;
    } // isdigit

    bool String::isalnum()
    {
        for (char &c : (*this))
            if (!std::isalnum(c)) return false;

        return true;
    } // isalnum

    bool String::isxdigit()
    {
        for (char &c : (*this))
            if (!std::isxdigit(c)) return false;

        return true;
    } // isxdigit

    bool String::islower()
    {
        for (char &c : (*this))
            if (!std::islower(c)) return false;

        return true;
    } // islower

    bool String::isupper()
    {
        for (char &c : (*this))
            if (!std::isupper(c)) return false;

        return true;
    } // isupper

    bool String::isspace()
    {
        for (char &c : (*this))
            if (!std::isspace(c)) return false;

        return true;
    } // isspace
} // namespace
