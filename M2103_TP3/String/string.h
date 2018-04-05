#ifndef STRING_H
#define STRING_H

#include <string>

namespace nsUtil {
    class String : public std::string
    {
    public:
        String ();
        String (const char * NTCTS);
        String (const char * NTCTS, size_type size);
        String (const std::string &amp, size_type pos = 0, size_type size = npos);
        String (size_type size, char c);

        String tolower();
        String toupper();

        bool isalpha();
        bool isdigit();
        bool isalnum();
        bool isxdigit();
        bool islower();
        bool isupper();
        bool isspace();
    };

}

#endif // STRING_H
