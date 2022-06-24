#ifndef CUTVOXEL_H
#define CUTVOXEL_H


#include "figurageometrica.h"


class CutVoxel : public FiguraGeometrica
{
protected:
    int xr, yr, zr;
public:
    CutVoxel(int xa,int ya,int za);
    ~CutVoxel();
    void draw(Sculptor &d);
};


#endif // CUTVOXEL_H
