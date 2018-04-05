#include "rationnel.h"

#include <iostream>

using namespace std;

namespace {
    int PGCD (int a, int b)
    {
        while (true)
        {
            if (a == b) break;

            if (a < b)
                b -= a;
            else
                a -= b;
        }
        return b;
    }
} // namespace

Rationnel::Rationnel (const int &a /* = 0 */, const int &b /* = 1 */) noexcept{
    myNum = a;

    if (b != 0)
        myDenom = b;
    else
        myDenom = 1;

    simplifier();
} // default constructor

bool Rationnel::operator < (const Rationnel & R){
    //On suppose que les rationnels ont été simplifiés lors de leur construction
    if (this->getNum()*R.getNum() < this->getDenom()*R.getNum())
        return true;

    else return false;
} // <

bool Rationnel::operator ==(const Rationnel & R){
    //On suppose que les rationnels ont été simplifiés lors de leur construction
    if (this->getNum() == R.getNum() && this->getDenom() == R.getDenom())
        return true;

    else return false;
} // ==

Rationnel Rationnel::operator + (const Rationnel & R){
    int num = (this->getNum() * R.getDenom()) + (this->getDenom() * R.getNum());
    int denom = this->getDenom() * R.getDenom();

    return Rationnel (num, denom);
} // +

Rationnel Rationnel::operator - (const Rationnel & R){
    int num = (this->getNum() * R.getDenom()) - (this->getDenom() * R.getNum());
    int denom = this->getDenom() * R.getDenom();

    return Rationnel (num, denom);
} // -

Rationnel Rationnel::operator * (const Rationnel & R){
    int num = this->getNum() * R.getNum();
    int denom = this->getDenom() * R.getDenom();

    return Rationnel (num, denom);
} // *

Rationnel Rationnel::operator / (const Rationnel & R){
    int num = this->getNum() * R.getDenom();
    int denom = this->getDenom() * R.getNum();

    return Rationnel (num, denom);
} // /

void Rationnel::display(void) const
{
    cout << getNum() << '/' << getDenom();
} // display

void Rationnel::simplifier()
{
    if (this->getNum() == 0)
    {
        this->myDenom = 1;
        return;
    }

    if (this->getNum() > 0 && this->getDenom() < 0)
    {
        this->myNum = -getNum();
        this->myDenom = abs(this->getDenom());
    }

    if (this->getNum() < 0 && this->getDenom() < 0)
    {
        this->myNum = abs(getNum());
        this->myDenom = abs(getDenom());
    }

    int pgcd = PGCD(this->getNum(), this->getDenom());
    this->myNum /= pgcd;
    this->myDenom /= pgcd;
} // simplifier

int Rationnel::getNum(){
    return this->myNum;
} // getNum

int Rationnel::getDenom(){
    return this->myDenom;
} // getDenom
