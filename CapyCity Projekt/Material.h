#pragma once
class Material
{
protected:
	double preis;
public:
	Material(double p) : preis(p) { };
	~Material() = default;

	double getPreis() { return preis; };
	void setPreis(double p) { preis = p; };
};

