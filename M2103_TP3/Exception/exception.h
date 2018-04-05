#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <exception>
#include <stdexcept>

namespace nsUtil {
    class Exception : public std::exception
    {
    private:
        std::string myLibelle;
        unsigned myCodErr;

    public:
        Exception (const std::string & Libelle, const unsigned & CodErr);
        virtual ~Exception ();

        std::string getmyLibelle();
        unsigned getmyCodErr();
        virtual const char* what() const noexcept;
        void display();
    };
}

#endif // EXCEPTION_H
