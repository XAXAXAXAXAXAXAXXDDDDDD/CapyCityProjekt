#pragma once
#include "Material.h"
class Metall :
    public Material
{
public:
    Metall() : Material(50) { };
    ~Metall() = default;
};

