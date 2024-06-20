#include "Zombie.hpp"

int	main(void)
{
	Zombie*	zombie = newZombie("Zombie Heap");
	zombie->announce();
	delete zombie;

	randomChump("Zombie Stack");
	// system("leaks zombie");
}
