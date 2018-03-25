#include "duree.h"

#include <iostream>
#include <iomanip>

using namespace std;

void nsUtil::Duree::normaliser () noexcept
{
    myDays = myDuree / (60*60*24);
    myHours = (myDuree - myDays*(60*60*24)) / (60*60);
    myMinutes = (myDuree - myDays*(60*60*24) - myHours*(60*60)) / 60;
    mySeconds = (myDuree - myDays*(60*60*24) - myHours*(60*60) - myMinutes*(60));
} // Normaliser

nsUtil::Duree::Duree (const unsigned &myDuree_) noexcept :
    myDuree (myDuree_)
{
    normaliser();
} // Duree

unsigned nsUtil::Duree::getDuree() const noexcept
{
    return myDuree;
} // getDuree

void nsUtil::Duree::display() const
{
    cout << setw (4) << myDays    << " jour(s) "
         << setw (4) << myHours   << " heure(s) "
         << setw (4) << myMinutes << " minute(s) "
         << setw (4) << mySeconds << " seconde(s) ";
} // display

void nsUtil::Duree::inc(const unsigned &delta) noexcept
{
    myDuree += delta;

    normaliser();
} // inc

void nsUtil::Duree::dec(const unsigned &delta) noexcept
{
    if (myDuree >= delta)
        myDuree -= delta;

    normaliser();
} // dec
