
#include "cutsphere.h"


CutSphere::CutSphere(int xae,int yae,int zae,int centroxe,int centroye,int centroze,int raioe){

    xa=xae;
    ya=yae;
    za=zae;
    centroX = centroxe;
    centroY = centroye;
    centroZ = centroze;
    raio = raioe;
}
CutSphere::~CutSphere(){

}
void CutSphere::draw(Sculptor &d){

    double rd = raio/1.0, distancia;

    for(int i=0; i < xa; i++)
        for(int j=0; j < ya; j++)
            for(int k=0; k < za; k++){
                distancia = (i - centroX/1.0)*(i - centroX/1.0)/(rd*rd)+(j - centroY/1.0)*(j - centroY/1.0)/(rd*rd)+
                (k - centroZ/1.0)*( k- centroZ/1.0)/(rd*rd);
                if(distancia <= 1.0)
                    d.CutVoxel(i, j, k);
            }
}
