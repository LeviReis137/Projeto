#include "CutBox.h"

CutBox::CutBox(int dxa,int dxb,int dya,int dyb,int dza,int dzb){
    xa = dxa;
    ya = dya;
    za = dza;
    xb = dxb;
    yb = dyb;
    zb = dzb;
}
CutBox::~CutBox(){

}
void CutBox::draw(Sculptor &d){


    for( int i=0 ; i<xb ; i++){
        for ( int j=0; j<yb ; j++){
            for ( int k=0 ; k<zb ; k++){
                    if((i>=xa && i<=xb) && (j>=ya && j<=yb) && (k>=za && k<=zb)){
                    d.CutVoxel(i,j,k);
                    }
        }
     }
  }
}
