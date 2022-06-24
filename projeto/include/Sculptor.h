#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <cmath>
#include <iostream>
#include <cstdlib>

struct Voxel {
  float r,g,b; // Colors
  int a;
// Transparency
  bool isOn; // Included or not
};
class Sculptor {
protected:
  Voxel ***v;
  // 3D matrix
  int nLinhas,nColunas,nPlanos; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void SetColor(float rv, float gv, float bv, float alpha);
  void PutVoxel(int x, int y, int z);
  void CutVoxel(int x, int y, int z);
  void PutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void PutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void CutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
