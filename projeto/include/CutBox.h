#ifndef CUTBOX_H
#define CUTBOX_H


#include "figurageometrica.h"
#include "sculptor.h"

class CutBox : public FiguraGeometrica{
protected:
    int xa, ya, za, xb, yb, zb;
    int r, g, b;
    float alpha;
public:
    CutBox(int dxa,int dxb,int dya,int dyb,int dza,int dzb);
    ~CutBox();
    void draw(Sculptor &d);
};
#endif // CUTBOX_H
