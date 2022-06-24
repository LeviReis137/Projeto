
#include "cutvoxel.h"

CutVoxel::CutVoxel(int xa,int ya,int za){
    xr = xa;
    yr = ya;
    zr = za;
}
CutVoxel::~CutVoxel(){

}
void CutVoxel::draw(Sculptor &d){
    d.CutVoxel(xr, yr, zr);
}
