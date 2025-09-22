#include <string>
#include <iostream>
#include <cstring>

char to_upper(char c)
{
	if (c >= 'a' || c <= 'z')
		c -= 32;
	return c;
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			if (islower(argv[i][j]))
				std::cout << to_upper(argv[i][j]);
			else
				std::cout << argv[i][j];
			j++;
		}
		i++;
	}
	std::cout << "\n";
	return 0;
}
