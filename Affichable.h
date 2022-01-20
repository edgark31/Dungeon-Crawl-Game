#pragma once
#include <iostream>
#include <fstream>
#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"

using namespace std;


class Affichable
{
public:
	virtual ~Affichable() = default;

	virtual void afficher(ostream& os) const = 0;

};