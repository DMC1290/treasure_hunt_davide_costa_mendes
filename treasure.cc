#include "treasure.h"
#include <random>


int random_number()
{
	srand(time(NULL));

	static bool seeded = false;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = true;
	}

	return rand() % 25;
}