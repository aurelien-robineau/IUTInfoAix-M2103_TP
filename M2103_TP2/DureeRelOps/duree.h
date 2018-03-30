#ifndef DUREE_H
#define DUREE_H

namespace nsUtil {

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

        // Destructor
        ~Duree () noexcept;

        // Operators
        Duree operator + (const Duree & duree);
        Duree operator - (const Duree & duree);
        bool operator < (const Duree & duree) const;
        bool operator == (const Duree & duree) const;

        // Operations

        unsigned getDuree () const noexcept;
        void display () const;
        void inc (const unsigned &delta = 3600) noexcept;
        void dec (const unsigned &delta = 3600) noexcept;

    }; // Duree

} // namespace nsUtil

#endif // DUREE_H
