#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed 
{
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const & src);
        Fixed & operator=(Fixed const & raw);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
        int                _raw;
        static int const   _nbBits;
};

#endif