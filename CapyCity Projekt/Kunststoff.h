#pragma once
#include "Material.h"
class Kunststoff :
    public Material
{
public:
    Kunststoff() : Material(2) { };
    ~Kunststoff() = default;
};

