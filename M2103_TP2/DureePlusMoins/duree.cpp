#include "duree.h"

#include <iostream>
#include <iomanip>

using namespace std;
using namespace nsUtil;

Duree Duree::operator +(const Duree & duree)
{
    return Duree(getDuree() + duree.getDuree());
}// +

Duree Duree::operator -(const Duree & duree)
{
    if (getDuree() >= duree.getDuree())
        return Duree(getDuree() - duree.getDuree());
    else
        return Duree(0);
}// -

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

Duree::~Duree () noexcept
{
}// ~Duree

unsigned Duree::getDuree() const noexcept
{
    return myDuree;
} // getDuree

void Duree::display() const
{
    cout << "["
         << setw (4) << myDays << ':'
         << setfill('0')
         << setw (2) << myHours << ':'
         << setw (2) << myMinutes << ':'
         << setw (2) << mySeconds << ':'
         << "]" << setfill(' ');
} // display

void Duree::inc(const unsigned &delta /*= 3600*/) noexcept
{
    myDuree += delta;

    normaliser();
} // inc

void Duree::dec(const unsigned &delta /*= 3600*/) noexcept
{
    if (myDuree >= delta)
        myDuree -= delta;

    normaliser();
} // dec
