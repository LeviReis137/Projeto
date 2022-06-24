#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"


class CutSphere : public FiguraGeometrica{
protected:
    int centroX, centroY, centroZ, raio, xa, ya, za;
public:
    CutSphere(int xae, int yae,int zae,int centroxe,int centroye,int centroze,int raioe);
    ~CutSphere();
    void draw(Sculptor &d);
};

#endif // CUTSPHERE_H
