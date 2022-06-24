#include "putvoxel.h"

PutVoxel::PutVoxel(int xa, int ya, int za, int re, int ge, int be, float alphae){
    x = xa;
    y = ya;
    z = za;
    r = re;
    g = ge;
    b = be;
    alpha=alphae;
}
PutVoxel::~PutVoxel(){

}
void PutVoxel::draw(Sculptor &d){
    d.SetColor(r, g, b, alpha);
    d.PutVoxel(x, y, z);
}
