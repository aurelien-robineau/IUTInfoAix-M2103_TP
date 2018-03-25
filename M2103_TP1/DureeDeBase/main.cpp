#include <iostream>
#include <iomanip>

using namespace std;

namespace {

    class Duree {
    private:

        // Attributes
        unsigned myDuree;
        unsigned mySeconds;
        unsigned myMinutes;
        unsigned myHours;
        unsigned myDays;

        // Operations
        void normaliser () noexcept;

    public:
        // Constructor
        Duree (const unsigned &duree = 0) noexcept;

        // Operations
        unsigned getDuree () const noexcept;
        void display () const;
        void inc (const unsigned &delta) noexcept;
        void dec (const unsigned &delta) noexcept;

    }; // Duree

    void Duree::normaliser () noexcept
    {
        myDays = myDuree / (60*60*24);
        myHours = (myDuree - myDays*(60*60*24)) / (60*60);
        myMinutes = (myDuree - myDays*(60*60*24) - myHours*(60*60)) / 60;
        mySeconds = (myDuree - myDays*(60*60*24) - myHours*(60*60) - myMinutes*(60));
    } // Normaliser

    Duree::Duree (const unsigned &myDuree_) noexcept :
        myDuree (myDuree_)
    {
        normaliser();
    } // Duree

    unsigned Duree::getDuree() const noexcept
    {
        return myDuree;
    } // getDuree

    void Duree::display() const
    {
        cout << setw (4) << myDays    << " jour(s) "
             << setw (4) << myHours   << " heure(s) "
             << setw (4) << myMinutes << " minute(s) "
             << setw (4) << mySeconds << " seconde(s) ";
    } // display

    void Duree::inc(const unsigned &delta) noexcept
    {
        myDuree += delta;

        normaliser();
    } // inc

    void Duree::dec(const unsigned &delta) noexcept
    {
        if (myDuree >= delta)
            myDuree -= delta;

        normaliser();
    } // dec

} // namespace

void testDureeDeBase ()
{
    Duree D1 (0);
    D1.inc (1);
    cout << "Nbre sec. " << setw (6) << D1.getDuree ()
         << ", soit : ";
    D1.display ();
    cout << '\n';

    D1.dec (1);
    cout << "Nbre sec. " << setw (6) << D1.getDuree ()
         << ", soit : ";
    D1.display ();
    cout << '\n';

    D1.inc (3662);
    cout << "Nbre sec. " << setw (6) << D1.getDuree ()
         << ", soit : ";
    D1.display ();
    cout << '\n';

    D1.dec (10000);
    cout << "Nbre sec. " << setw (6) << D1.getDuree ()
         << ", soit : ";
    D1.display ();
    cout << '\n';
} // testDureeDeBase

int main()
{
    testDureeDeBase();

    return 0;
} // main
