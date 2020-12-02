#include "fillit.h"

char	*ft_algo(char *map, int sqr, char **tetri);
char	*ft_resolve(int nbTetri, char **tetri);

int	main()
{
	int nbTetri;
	char *tetri[4];

	tetri[0] = "A...A...A...A...";
	tetri[1] = "BB..BB..........";
	tetri[2] = "CC..CC..........";
	tetri[3] = 0;
	nbTetri = 3;
	printf("solution finale :%s \n", ft_resolve(nbTetri, tetri));
	return (0);
}
