#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "Objet.h"
#include "Affichable.h"
#include "POINTS_CARDINAUX.h"


using namespace std;


class Salle : public virtual Affichable {
public:
	Salle(const string& nom, const string& description);
	virtual ~Salle() = default;
	
	const string& getNom() const;
	const string& getDescription() const;
	weak_ptr<Salle> getConnexion(char direction);
	map<string, shared_ptr<Objet>> getObjets();
	
	void setConnexion(weak_ptr<Salle> nouvelleSalle, char direction);
	void setConnexions(weak_ptr<Salle> salleA, char directionA, weak_ptr<Salle> salleB, char directionB);
	void setObjet(shared_ptr<Objet> objet);

	void afficher(ostream& os) const override;
	

private:
	string nom_;
	string description_;
	map<char, weak_ptr<Salle>> connexions_;
	map<string, shared_ptr<Objet>> objets_;
};