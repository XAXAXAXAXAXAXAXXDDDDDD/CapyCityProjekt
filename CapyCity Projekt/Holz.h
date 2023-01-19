#pragma once
#include "Material.h"
class Holz :
    public Material
{
public:
    Holz() : Material(10) { };
    ~Holz() = default;

    void ausgeben() override {
        cout << "Holz";
    }
};

