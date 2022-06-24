#ifndef PUTBOX_H
#define PUTBOX_H


#include "figurageometrica.h"
#include "sculptor.h"

class PutBox : public FiguraGeometrica{
protected:
    int xa, ya, za, xb, yb, zb;
    int r, g, b;
    float alpha;
public:
    PutBox(int dxa,int dxb,int dya,int dyb,int dza,int dzb,int re,int ge,int be,float alphae);
    ~PutBox();
    void draw(Sculptor &d);
};
#endif // PUTBOX_H
