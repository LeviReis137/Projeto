#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    int i, j, k;
v = new Voxel**[nx];

    for(int i=0; i< nx; i++){
        if (i<(nx-1))
            v[i+1] = v[i]+ny;
        for(int j=1; j< ny; j++){
            v[i][j] = v[i][j-1] + nz;
            if(j==ny-1 && i!=(nx-1))
                v[i+1][0] = v[i][j] + nz;
        }
    }
    for ( i = 0; i<ny; i++){
        v[0] = new Voxel*[nx*ny];
    }

    for ( i = 0; i<ny; i++){
        for (j = 0 ; j<nz; j++){
            v[0][0] = new Voxel[nx*ny*nz];
        }
    }
    for( i=0 ; i<nx ; i++){
        for ( j=0; j<ny ; j++){
            for ( k=0 ; k<nz ; k++){
                v[i][j][k].isOn=false;

        }
    }
  }
}
Sculptor::~Sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

  void Sculptor::setColor(float rv, float gv, float bv, float alpha){
      r=rv;
      g=gv;
      b=bv;
      a=alpha;
  };
  void Sculptor::putVoxel(int x, int y, int z){
      x=nx;
      y=ny;
      z=nz;
    v[x][y][z].r=r;
    v[x][y][z].b=b;
    v[x][y][z].g=g;
    v[x][y][z].a=a;
    v[x][y][z].isOn=true;
  };
  void Sculptor::cutVoxel(int x, int y, int z){
      x=nx;
      y=ny;
      z=nz;
    v[x][y][z].isOn=false;
  };
  void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for( int i=0 ; i<nx ; i++){
        for ( int j=0; j<ny ; j++){
            for ( int k=0 ; k<nz ; k++){
                    if((nx>=x0 && nx<=x1) && (ny>=x0 && ny<=x1) && (nz>=x0 && nz<=x1))
                v[i][j][k].isOn=true;
        }
     }
  }
};
  void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for( int i=0 ; i<nx ; i++){
        for ( int j=0; j<ny ; j++){
            for ( int k=0 ; k<nz ; k++){
                    if((nx>=x0 && nx<=x1) && (ny>=x0 && ny<=x1) && (nz>=x0 && nz<=x1))
                v[i][j][k].isOn=false;
        }
     }
  }
};
  void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
      float dist;
    for( int i= -radius ; i<radius ; i++){
        for ( int j=0; j<ny ; j++){
            for ( int k=0 ; k<nz ; k++){
                dist = (i - xcenter/1.0)*(i - xcenter/1.0)/(radius*radius)+(j - ycenter/1.0)*( j- ycenter/1.0)/(radius*radius)+
                        (k - zcenter/1.0)*(k - zcenter/1.0)/(radius*radius);
                if(dist <= 1.0){
    v[nx][ny][nz].r=r;
    v[nx][ny][nz].b=b;
    v[nx][ny][nz].g=g;
    v[nx][ny][nz].a=a;
    v[nx][ny][nz].isOn=true;
         }
       }
     }
   }
};
  void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
      float dist;
    for( int i= -radius ; i<radius ; i++){
        for ( int j=0; j<ny ; j++){
            for ( int k=0 ; k<nz ; k++){
                dist = (i - xcenter/1.0)*(i - xcenter/1.0)/(radius*radius)+(j - ycenter/1.0)*( j- ycenter/1.0)/(radius*radius)+
                        (k - zcenter/1.0)*(k - zcenter/1.0)/(radius*radius);
                if(dist <= 1.0){
    v[nx][ny][nz].isOn=false;
         }
       }
     }
   }
  };
  void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

  };
  void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

  };
  void Sculptor::writeOFF(const char* filename){
  int ver=0, fac=0, cont=0;

  std::ofstream ofs;

  ofs.open ("projeto.off", std::ofstream::out | std::ofstream::app);

  ofs << "OFF"<<endl;;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++)
                if(v[i][j][k].isOn){
                    ver = ver+8;
                    fac = fac+6;
                }
            }
        }

    ofs << ver << " " << fac << " " << 0 <<endl;
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++)
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

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++)
                if(v[i][j][k].isOn){
                    ofs<<4<<" "<<cont+0<<" "<<cont+3<<" "<<cont+2<<" "<<cont+1<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont+4<<" "<<cont+5<<" "<<cont+6<<" "<<cont+7<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont+0<<" "<<cont+1<<" "<<cont+5<<" "<<cont+4<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont<<" "<<cont+4<<" "<<cont+7<<" "<<cont+3<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont+3<<" "<<cont+7<<" "<<cont+6<<" "<<cont+2<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    ofs<<4<<" "<<cont+1<<" "<<cont+2<<" "<<cont+6<<" "<<cont+5<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;

                    cont = cont + 8;
                }
            }
        }

  ofs.close();
  };

