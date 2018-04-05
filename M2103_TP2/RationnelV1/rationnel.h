#ifndef RATIONNEL_H
#define RATIONNEL_H


class Rationnel
{
private:
    int myNum;
    int myDenom;

    void simplifier();
public:
    Rationnel (const int &a = 0, const int &b = 1) noexcept;

    bool operator      < (const Rationnel & R);
    bool operator      ==(const Rationnel & R);
    Rationnel operator + (const Rationnel & R);
    Rationnel operator - (const Rationnel & R);
    Rationnel operator * (const Rationnel & R);
    Rationnel operator / (const Rationnel & R);

    void display(void) const;
    int getNum();
    int getDenom();
};

#endif // RATIONNEL_H
