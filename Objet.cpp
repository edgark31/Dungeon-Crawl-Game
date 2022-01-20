/**
* Classe qui représente un objet avec ses getters.
* \file   Objet.cpp
* \author Edgar Kappauf
* \date   21 décembre 2021
* Créé le 21 décembre 2021
*/
#pragma once
#include <iostream>
#include <string>

#include "Objet.h"
using namespace std;

Objet::Objet(const string& nom, const string& description, const string& utiliser, shared_ptr<Objet> objetCache) : nom_(nom), description_(description), utiliser_(utiliser), objetCache_(objetCache) {}

const string& Objet::getNom() const { return nom_; }
const string& Objet::getDescription() const { return description_; }
const string& Objet::getUtiliser() const { return utiliser_; }
shared_ptr<Objet> Objet::getObjetCache() { return objetCache_; }

void Objet::setObjetCache(shared_ptr<Objet> objetCache) { objetCache_ = objetCache; }