#include "Zombie.hpp"

int	main(void)
{
	int const	n = 10;
	Zombie*		zombie = zombieHorde(n, "Zombie Heap");

	for (int i = 0; i < n; i++)
		zombie[i].announce();

	delete[] zombie;

	// system("leaks zombieHorde");
}
