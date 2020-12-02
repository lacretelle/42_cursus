#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
    public:
        Span(unsigned int n);
        ~Span();
        Span(Span const &);
        Span & operator=(Span const &);

        unsigned int    getN() const;
        void            addNumber(unsigned int const n);
        shortestSpan();
        longestSpan();

    private:
        unsigned int    _N;
        Span(void);
};
#endif
