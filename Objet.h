#pragma once
#include <iostream>
#include <string>


using namespace std;

class Objet {
public:
	Objet() = default;
	Objet(const string& nom, const string& description, const string& utiliser, shared_ptr<Objet> objetCache = nullptr);
	~Objet() = default;

	const string& getNom() const;
	const string& getDescription() const;
	const string& getUtiliser() const;
	shared_ptr<Objet> getObjetCache();

	void setObjetCache(shared_ptr<Objet> objetCache);

private:
	string nom_;
	string description_;
	string utiliser_;
	shared_ptr<Objet> objetCache_;
	friend class Jeu;
};