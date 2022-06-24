#include <iostream>
#include "Sculptor.h"
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include "figurageometrica.h"
#include "sculptor.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"

using namespace std;

int main()
{

  // cria um escultor cuja matriz tem 10x10x10 voxels
  Sculptor trono(10,10,10);
  // para mudar a cor do voxel
  //trono.SetColor(0,0,1.0,1.0); // azul
  // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
  PutBox b1(0,9,0,9,0,9,0,0,1,1);
  CutVoxel b5(0,0,0);
  CutBox b2(1,8,1,9,1,9);
  PutSphere b3(10,10,10,6,6,6,4,0,0,1,1);
  CutSphere b4(10,10,10,3,3,3,4);
  //trono.PutBox(0,9,0,9,0,9);
  // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
  //trono.CutBox(1,8,1,9,1,9);
  // grava a escultura digital no arquivo "trono.off"
    b1.draw(trono);
    b2.draw(trono);
    b3.draw(trono);
    b4.draw(trono);
    b5.draw(trono);
  trono.writeOFF("projeto.off");

    return 0;
}
