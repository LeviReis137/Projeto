#include "putsphere.h"
#include <math.h>

PutSphere::PutSphere(int xae, int yae, int zae, int centroxe, int centroye, int centroze, int raioe, int re, int ge, int be, float alphae){
    xa=xae;
    ya=yae;
    za=zae;
    centroX = centroxe;
    centroY = centroye;
    centroZ = centroze;
    raio = raioe;
    r = re;
    g = ge;
    b = be;
    alpha = alphae;

}
PutSphere::~PutSphere(){

}
void PutSphere::draw(Sculptor &d){
    double rd = raio/1.0, distancia;

    d.SetColor(r, g, b, alpha);
    for(int i=0; i < xa; i++)
        for(int j=0; j < ya; j++)
            for(int k=0; k< za; k++){
                distancia = (i - centroX/1.0)*(i - centroX/1.0)/(rd*rd)+(j - centroY/1.0)*( j- centroY/1.0)/(rd*rd)+
                        (k - centroZ/1.0)*(k - centroZ/1.0)/(rd*rd);
                if(distancia <= 1.0){
                    d.PutVoxel(i,j,k);
                }
            }
}
