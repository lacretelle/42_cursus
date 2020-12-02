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
        ~Fixed(void);

        int     getRawBits(void) const;
        void    setRawBits(int const);
        float   toFloat(void) const;
        int     toInt(void) const;

        Fixed & operator=(Fixed const & src);
        bool    operator>(Fixed const & src);
        bool    operator<(Fixed const & src);
        bool    operator>=(Fixed const & src);
        bool    operator<=(Fixed const & src);
        bool    operator==(Fixed const & src);
        bool    operator!=(Fixed const & src);

        Fixed   operator+(Fixed const & src);
        Fixed   operator-(Fixed const & src);
        Fixed   operator/(Fixed const & src);
        Fixed   operator*(Fixed const & src);
        
        Fixed   operator++(void);
        Fixed   operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);

        static Fixed const &min(Fixed const &rhs1, Fixed const &rhs2);
		static Fixed &min(Fixed &rhs1, Fixed &rhs2);
		static Fixed const &max(Fixed const &rhs1, Fixed const &rhs2);
		static Fixed &max(Fixed &rhs1, Fixed &rhs2);

    private:
        int                 _raw;
        static int const    _nbBits;
};

std::ostream &  operator<<( std::ostream & o, Fixed const & rhs);

#endif