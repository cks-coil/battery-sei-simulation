/*
  \file    kmc_surface.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>

  面心立方格子を表面に成長させる

  横から見たイメージとしては下のような感じになる(数字がsite:nに対応する,実際には周期境界あり)
  1_2_3_4_5_..._N_
  _1_2_3_4_5_..._N
  1_2_3_4_5_..._N_
  上のようになっている場合、site:1~Nは全て、三層になっていると言える
  例えば二層目の"2"の下には一層目の"2"と"3"が、上には三層目の"2"と"3"が存在している

  プログラム内では、n*mの配列を持ち、そこに高さ(何層目まで粒子があるか)を持っている
*/

#include "kmc_surface.hpp"
#include <algorithm>
using namespace std;

KMCSurface::KMCSurface(void){
    p = NULL;
    s = NULL;
    SEIThicknessAve = 0;
}

void KMCSurface::setParam(Param *param){
    p = param;
    surface.reserve(p->getKMCSurfaceSizeX()*p->getKMCSurfaceSizeY());
    for(int i=0; i<p->getKMCSurfaceSizeX()*p->getKMCSurfaceSizeY(); i++) surface[i] = 1;
}
void KMCSurface::setState(State *state){
    s = state;
}

void KMCSurface::updateState(void){
    calcSEIThicknessAve();
}

bool KMCSurface::isValid(int n){
    if( n>=0 && n<getNumSite() ) return true;
    else return false;
}

bool KMCSurface::isTop(int n){
    diaDir listDiaDir[4] = {RIGHT_FRONT, RIGHT_BACK, LEFT_FRONT, LEFT_BACK};
    int nSide;
    if( !isValid(n) ) return false; // \cks err msg
    for(int i=0; i<( (int)sizeof(listDiaDir)/(int)sizeof(listDiaDir[0]) ); i++){
        nSide = getUpDownSideN(n, surface[n], listDiaDir[i]);
        if( surface[nSide] > surface[n] ) return false;
    }
    return true;
}
bool KMCSurface::isFlat(int n){
    diaDir listDiaDir[4] = {RIGHT_FRONT, RIGHT_BACK, LEFT_FRONT, LEFT_BACK};
    int nSide;
    if( !isValid(n) ) return false; // \cks err msg
    for(int i=0; i<( (int)sizeof(listDiaDir)/(int)sizeof(listDiaDir[0]) ); i++){
        nSide = getUpDownSideN(n, surface[n]+1, listDiaDir[i]);
        if( surface[nSide] < surface[n] ) return false;
    }
    return true;
}

int KMCSurface::getNumSite(void){
    return p->getKMCSurfaceSizeX() * p->getKMCSurfaceSizeY();
}

int KMCSurface::getNumSide(int n){
    orthDir listOrthDir[4] = {RIGHT, LEFT, FRONT, BACK};
    int nSide;
    int num=0;
    if( !isValid(n) ) return 0; // \cks err msg
    for(int i=0; i<( (int)sizeof(listOrthDir)/(int)sizeof(listOrthDir[0]) ); i++){
        nSide  = getSideN(n, listOrthDir[i]);
        if( surface[nSide] >= surface[n]) num++;
    }
    return num;
}

int KMCSurface::getNumSideUp(int n){
    orthDir listOrthDir[4] = {RIGHT, LEFT, FRONT, BACK};
    int nSide;
    int num=0;
    if( !isValid(n) ) return 0; // \cks err msg
    for(int i=0; i<( (int)sizeof(listOrthDir)/(int)sizeof(listOrthDir[0]) ); i++){
        nSide  = getSideN(n, listOrthDir[i]);
        if( surface[nSide] > surface[n]) num++;
    }
    return num;
}

double KMCSurface::getSurfaceArea(void){
    return p->getKMCSurfaceSizeX() * p->getKMCSurfaceSizeY() * p->getSEIUnitArea();
}

double KMCSurface::getSEIThicknessPoint(int n){
    if( !isValid(n) ) return 0; // \cks err msg
    return (double)surface[n] * p->getSEIUnitThickness();
}
double KMCSurface::getSEIThicknessAve(void){
    return SEIThicknessAve;
}

void KMCSurface::adsorb(int n){
    if( !isValid(n) || !isFlat(n) ) return; // \cks err msg
    surface[n]++;
}
void KMCSurface::desorb(int n){
    if( !isValid(n) || !isTop(n) ) return; // \cks err msg
    surface[n]--;
}
void KMCSurface::output(std::ostream &out){
    for(int i=0;i<getNumSite();i++) out << surface[i] << " ";
    return;
}

void KMCSurface::analyze(std::ostream &out){
    unsigned int numFlat = 0;
    for(int i=0;i<getNumSite();i++) if(isFlat(i)) numFlat++;
    out << numFlat <<  " #NumFlat " << getNumSite() - numFlat << " #NumNotFlat ";

    unsigned int numWithSideUp = 0;
    for(int i=0;i<getNumSite();i++) if(isFlat(i)) if(getNumSideUp(i)) numWithSideUp++;
    out << numWithSideUp << " #NumWithSideUp " << numFlat - numWithSideUp << " #NumWithoutSideUp ";
}

void KMCSurface::calcSEIThicknessAve(void){
    int sum=0;
    for(int i=0; i<getNumSite(); i++) sum += surface[i];
    SEIThicknessAve = double(sum) * p->getSEIUnitThickness() / double(getNumSite());
    s->setSEIThickness( SEIThicknessAve );
}

void KMCSurface::changeXYtoN(int x, int y, int *n){
    boundaryXY(&x, &y);
    *n = y*p->getKMCSurfaceSizeX() + x;
}

void KMCSurface::changeNtoXY(int n, int *x, int *y){
    if( !isValid(n) ){
        // \cks err msg
        *x = *y = 0;
        return;
    }
    *x = n%p->getKMCSurfaceSizeX();
    *y = n/p->getKMCSurfaceSizeX();
}

void KMCSurface::boundaryXY(int *x, int *y){
    // Periodic boundary condition
    while(*x<0) *x += p->getKMCSurfaceSizeX();
    while(*y<0) *y += p->getKMCSurfaceSizeY();
    *x %= p->getKMCSurfaceSizeX();
    *y %= p->getKMCSurfaceSizeY();
}

int KMCSurface::getSideN(int n, orthDir dir){
    int x,y;
    int nSide;
    if( !isValid(n) ) return 0; // \cks err msg

    changeNtoXY(n, &x, &y);
    switch(dir){
    case RIGHT: x++; break;
    case LEFT: x--; break;
    case FRONT: y++; break;
    case BACK: y--; break;
    default: break;
    }
    changeXYtoN(x, y, &nSide);

    return nSide;
}

int KMCSurface::getUpDownSideN(int n, int z, diaDir dir){
    int x,y;
    int nSide;
    if( !isValid(n) ) return 0; // \cks err msg

    changeNtoXY(n, &x, &y);
    // zが奇数としてまずは処理
    // 奇数の場合、RIGHT_FRONTが同じx,yとなる
    switch(dir){
    case RIGHT_FRONT: break;
    case RIGHT_BACK: y--; break;
    case LEFT_FRONT: x--; break;
    case LEFT_BACK: y--; x--; break;
    default: break;
    }
    // zが偶数の場合の補正
    // 偶数の場合、LEFT_BACKが同じx,yとなる
    if( z%2 == 0 ){
        x++;
        y++;
    }
    changeXYtoN(x, y, &nSide);

    return nSide;
}

ostream &operator<<(ostream &out, KMCSurface &tgt){
    tgt.output(out);
    return out;
}
