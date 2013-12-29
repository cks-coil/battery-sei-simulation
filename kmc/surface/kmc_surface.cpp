/*
  \file    kmc_surface.cpp
  \author  Chikashi Shinagawa <shinagawa@tcl.t.u-tokyo.ac.jp>

  面心立方格子を表面に成長させる

  横から見たイメージとしては下のような感じになる(数字がsite:nに対応する,実際には周期境界あり)
  1 2 3 4 5 ... N
  1 2 3 4 5 ... N
  1 2 3 4 5 ... N
  上のようになっている場合、site:1~Nは全て、三層になっていると言える
  例えば二層目の"2"の下には一層目の"2"と"3"が、上には三層目の"2"と"3"が存在している

  プログラム内では、n*mの配列を持ち、そこに高さ(何層目まで粒子があるか)を持っている
*/

#include "kmc_surface.hpp"

KMCSurface::KMCSurface(int x, int y){
    xNum = x;
    yNum = y;
    deltaAve = 0;
    surface.reserve(xNum*yNum);
    for(int i=0; i<xNum*yNum; i++) surface[i] = 1;
    update();
}

void KMCSurface::setParam(KMCParam *param){
    p = param;
}

void KMCSurface::update(void){
    calcDeltaAve();
}

bool KMCSurface::isValid(int n){
    if( n>=0 && n<getNumSide() ) return true;
    else return false;
}

bool KMCSurface::isTop(int n){
    return false; // \cks
}
bool KMCSurface::isFlat(int n){
    return false; // \cks
}

int KMCSurface::getNumSite(void){
    return xNum * yNum;
}

int KMCSurface::getNumSide(int n){
    int num=0;
    int x,y;
    if( !isValid(n) ) return 0; // \cks err msg
}

double KMCSurface::getDeltaPoint(int n){
    if( !isValid(n) ) return 0; // \cks err msg
    return (double)n * p->getUnitDelta();
}
double KMCSurface::getDeltaAve(void){
    return deltaAve;
}

void KMCSurface::adsorb(int n){
    if( !isValid(n) || !isFlat(n) ) return; // \cks err msg
    surface[i]++;
}
void KMCSurface::adsorb(int n){
    if( !isValid(n) || !isTop(n) ) return; // \cks err msg
    surface[i]++;
}
void KMCSurface::output(std::ostream &out){
    // \cks
    return;
}


double KMCSurface::calcDeltaAve(void){
    int sum=0;
    for(int i=0; i<getNumSite(); i++); sum += surface[i];
    return double(sum) * p->getUnitDelta() / double(getNumSite());
}

void KMCSurface::changeXYtoN(int x, int y, int *n){
    *n = y*xNum + x;
}

void KMCSurface::changeNtoXY(int n, int *x, int *y){
    if( !isValid(n) ){
        // \cks err msg
        *x = *y = 0;
        return;
    }
    *x = n%xNum;
    *y = n/xNum;
}

void KMCSurface::boundaryXY(int *x, int *y){
    // Periodic boundary condition
    while(*x<0) *x += xNum;
    while(*y<0) *y += yNum;
    *x %= xNum;
    *y %= yNum;
}

int KMCSurface::getSideSurface(int n, orthDir dir){
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

    return surface[nSide];
}

int KMCSurface::getUpDownSideSurface(int n, diaDir dir){
    int x,y;
    int nSide;
    if( !isValid(n) ) return 0; // \cks err msg

    changeNtoXY(n, &x, &y);
    // surface[n]が奇数としてまずは処理
    // 奇数の場合、RIGHT_FRONTが同じx,yとなる
    switch(dir){
    case RIGHT_FRONT: break;
    case RIGHT_BACK: y--; break;
    case LEFT_FRONT: x--; break;
    case LEFT_BACK: y--; x--; break;
    default: break;
    }
    // surface[n]が偶数の場合の補正
    // 偶数の場合、LEFT_BACKが同じx,yとなる
    if( surface[n]%2 == 0 ){
        x++;
        y++;
    }
    changeXYtoN(x, y, &nSide);

    return surface[nSide];
}