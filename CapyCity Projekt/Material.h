#pragma once
#include <iostream>

using namespace std;

class Material
{
protected:
	double preis;
public:
	Material(double p) : preis(p) { };
	~Material() = default;

	double getPreis() { return preis; };
	void setPreis(double p) { preis = p; };

	virtual void ausgeben() {
		cout << "Material";
	}
};

