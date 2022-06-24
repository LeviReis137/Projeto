
#include "putbox.h"

PutBox::PutBox(int dxa,int dxb,int dya,int dyb,int dza,int dzb,int re,int ge,int be,float alphae){
    xa = dxa;
    ya = dya;
    za = dza;
    xb = dxb;
    yb = dyb;
    zb = dzb;
    r = re;
    g = ge;
    b = be;
    alpha=alphae;
}
PutBox::~PutBox(){

}
void PutBox::draw(Sculptor &d){


    d.SetColor(r, g, b,alpha);


    for( int i=0 ; i<xb ; i++){
        for ( int j=0; j<yb ; j++){
            for ( int k=0 ; k<zb ; k++){
                    if((i>=xa && i<=xb) && (j>=ya && j<=yb) && (k>=za && k<=zb)){
                    d.PutVoxel(i,j,k);
                    }
        }
     }
  }
}
