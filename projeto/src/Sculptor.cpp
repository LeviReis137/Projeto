#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nLinhas = _nx;
    nColunas = _ny;
    nPlanos = _nz;

    if(nLinhas<=0 || nColunas<=0 || nPlanos<=0){
        nLinhas = 0;
        nColunas = 0;
        nPlanos = 0;
    }

    v = new Voxel**[nLinhas];

    if(v==nullptr){
        cout<<"Não foi possível alocar"<<endl;
        exit(0);
    }

    v[0] = new Voxel*[nLinhas*nColunas];

    if(v[0]==nullptr){
        cout<<"Não foi possível alocar"<<endl;
        exit(0);
    }

    v[0][0] = new Voxel[nLinhas*nColunas*nPlanos];

    if(v[0][0] == nullptr){
        cout<<"Não foi possível alocar"<<endl;
        exit(0);
    }

    for(int i=0; i< nLinhas; i++){
        if (i<(nLinhas-1))
            v[i+1] = v[i]+nColunas;
        for(int j=1; j< nColunas; j++){
            v[i][j] = v[i][j-1] + nPlanos;
            if(j==nColunas-1 && i!=(nLinhas-1))
                v[i+1][0] = v[i][j] + nPlanos;
        }
    }
    for(int i = 0; i < nLinhas; i++)
        for(int j = 0; j < nColunas; j++)
            for(int k = 0; k < nPlanos; k++)
                v[i][j][k].isOn = false;
}

Sculptor::~Sculptor(){
    if(nLinhas==0 || nColunas==0 || nPlanos==0)
        return;

    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}


  void Sculptor::SetColor(float rv, float gv, float bv, float alpha){
      r=rv;
      g=gv;
      b=bv;
      a=alpha;
  };
  void Sculptor::PutVoxel(int x, int y, int z){

    v[x][y][z].r=r;
    v[x][y][z].b=b;
    v[x][y][z].g=g;
    v[x][y][z].a=a;
    v[x][y][z].isOn=true;
  };
  void Sculptor::CutVoxel(int x, int y, int z){

    v[x][y][z].isOn=false;
  };
  void Sculptor::PutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for( int i=0 ; i<nLinhas ; i++){
        for ( int j=0; j<nColunas ; j++){
            for ( int k=0 ; k<nPlanos ; k++){
                    if((i>=x0 && i<=x1) && (j>=y0 && j<=y1) && (k>=z0 && k<=z1)){
                    v[i][j][k].r=r;
                    v[i][j][k].b=b;
                    v[i][j][k].g=g;
                    v[i][j][k].a=a;
                    v[i][j][k].isOn=true;
                    }
        }
     }
  }
};
  void Sculptor::CutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for( int i=0 ; i<nLinhas ; i++){
        for ( int j=0; j<nColunas ; j++){
            for ( int k=0 ; k<nPlanos ; k++){
                    if((i>=x0 && i<=x1) && (j>=y0 && j<=y1) && (k>=z0 && k<=z1))
                v[i][j][k].isOn=false;
        }
     }
  }
};
  void Sculptor::PutSphere(int xcenter, int ycenter, int zcenter, int radius){
      float dist;
    for( int i= -radius ; i<radius ; i++){
        for ( int j=0; j<nColunas ; j++){
            for ( int k=0 ; k<nPlanos ; k++){
                dist = (i - xcenter/1.0)*(i - xcenter/1.0)/(radius*radius)+(j - ycenter/1.0)*( j- ycenter/1.0)/(radius*radius)+
                        (k - zcenter/1.0)*(k - zcenter/1.0)/(radius*radius);
                if(dist <= 1.0){
    v[i][j][k].r=r;
    v[i][j][k].b=b;
    v[i][j][k].g=g;
    v[i][j][k].a=a;
    v[i][j][k].isOn=true;
         }
       }
     }
   }
};
  void Sculptor::CutSphere(int xcenter, int ycenter, int zcenter, int radius){
      float dist;
    for( int i= -radius ; i<radius ; i++){
        for ( int j=0; j<nColunas ; j++){
            for ( int k=0 ; k<nPlanos ; k++){
                dist = (i - xcenter/1.0)*(i - xcenter/1.0)/(radius*radius)+(j - ycenter/1.0)*( j- ycenter/1.0)/(radius*radius)+
                        (k - zcenter/1.0)*(k - zcenter/1.0)/(radius*radius);
                if(dist <= 1.0){
    v[nLinhas][nColunas][nPlanos].isOn=false;
         }
       }
     }
   }
  };
  void Sculptor::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

  };
  void Sculptor::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

  };
  void Sculptor::writeOFF(const char* filename){
  int ver=0, fac=0, cont=0;

  std::ofstream ofs;

  ofs.open ("projeto.off", std::ofstream::out | std::ofstream::app);

  ofs << "OFF"<<endl;

    for(int i=0; i<nLinhas; i++){
        for(int j=0; j<nLinhas; j++){
            for(int k=0; k<nColunas; k++)
                if(v[i][j][k].isOn){
                    ver = ver+8;
                    fac = fac+6;
                }
            }
        }

    ofs << ver << " " << fac << " " << 0 <<endl;
    for(int i=0; i<nLinhas; i++){
        for(int j=0; j<nColunas; j++){
            for(int k=0; k<nPlanos; k++)
                if(v[i][j][k].isOn){
                        ofs<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        ofs<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        ofs<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        ofs<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        ofs<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                        ofs<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        ofs<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        ofs<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }
        }

    for(int i=0; i<nLinhas; i++){
        for(int j=0; j<nColunas; j++){
            for(int k=0; k<nPlanos; k++)
                if(v[i][j][k].isOn){
                    ofs<<4<<" "<<cont+0<<" "<<cont+3<<" "<<cont+2<<" "<<cont+1<<" "<<v[i][j][k].r<<".000"<<" "
                    <<v[i][j][k].g<<".000"<<" "<<v[i][j][k].b<<".000"<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont+4<<" "<<cont+5<<" "<<cont+6<<" "<<cont+7<<" "<<v[i][j][k].r<<".000"<<" "
                    <<v[i][j][k].g<<".000"<<" "<<v[i][j][k].b<<".000"<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont+0<<" "<<cont+1<<" "<<cont+5<<" "<<cont+4<<" "<<v[i][j][k].r<<".000"<<" "
                    <<v[i][j][k].g<<".000"<<" "<<v[i][j][k].b<<".000"<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont<<" "<<cont+4<<" "<<cont+7<<" "<<cont+3<<" "<<v[i][j][k].r<<".000"<<" "
                    <<v[i][j][k].g<<".000"<<" "<<v[i][j][k].b<<".000"<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont+3<<" "<<cont+7<<" "<<cont+6<<" "<<cont+2<<" "<<v[i][j][k].r<<".000"<<" "
                    <<v[i][j][k].g<<".000"<<" "<<v[i][j][k].b<<".000"<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont+1<<" "<<cont+2<<" "<<cont+6<<" "<<cont+5<<" "<<v[i][j][k].r<<".000"<<" "
                    <<v[i][j][k].g<<".000"<<" "<<v[i][j][k].b<<".000"<<" "<<v[i][j][k].a<<endl;

                    cont = cont + 8;
                }
            }
        }

  ofs.close();
  };

