
#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutSphere : public FiguraGeometrica
{
protected:
    int xa, ya, za;
    int centroX, centroY, centroZ, raio;
    int r, g, b;
    float alpha;
public:
    PutSphere(int xae, int yae, int zae, int centroxe, int centroye, int centroze, int raioe, int re, int ge, int be, float alphae);
    ~PutSphere();
    void draw(Sculptor &d);
};

#endif // PUTSPHERE_H
