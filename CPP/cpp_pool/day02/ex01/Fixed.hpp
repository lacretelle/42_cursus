#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed 
{
    public:
        Fixed(void);
        Fixed(int const n);
        Fixed(float const n);
        Fixed(Fixed const & src);
        Fixed & operator=(Fixed const & src);
        ~Fixed(void);

        int     getRawBits(void) const;
        void    setRawBits(int const);

        float   toFloat(void) const;
        int     toInt(void) const;

    private:
        int                 _raw;
        static int const    _nbBits;
};

std::ostream &  operator<<( std::ostream & o, Fixed const & rhs);

#endif