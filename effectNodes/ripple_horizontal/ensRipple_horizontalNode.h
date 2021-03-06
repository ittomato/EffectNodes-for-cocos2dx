//
//  ensRipple_horizontalNode.h
//  HelloCpp
//
//  Created by yang chao (wantnon) on 13-12-16.
//
//

#ifndef __HelloCpp__ensRipple_horizontalNode__
#define __HelloCpp__ensRipple_horizontalNode__

#include <iostream>
#include <vector>
using namespace std;
#include "cocos2d.h"
using namespace cocos2d;
#include "common/ensCommon.h"
namespace_ens_begin
class Cripple_horizontalNode:public CCSprite{
public:
    Cripple_horizontalNode(){
        m_dx=10;
        m_mesh=NULL;
        m_indexVBO=NULL;
        m_isDrawDebug=false;
    }
    virtual~Cripple_horizontalNode(){
        if(m_mesh)m_mesh->release();
        if(m_indexVBO)m_indexVBO->release();
    }
    void init(const string&texFileName);
    void pressAtX(float x,float h_press,float r_press=80);
    void draw();
    void drawWire();
    void update(float dt);
    bool getIsDrawDebug()const {return m_isDrawDebug;}
    void setIsDrawDebug(bool value){m_isDrawDebug=value;}
protected:
    void initMesh();
    void updateMesh();
    void updateRipple();
protected:
    vector<CCPoint> m_surfacePointList;//in local space
    vector<CCPoint> m_surfacePointList_back;//back up buffer
    float m_dx;
    Cmesh*m_mesh;
    CindexVBO*m_indexVBO;
    bool m_isDrawDebug;

};

namespace_ens_end
#endif /* defined(__HelloCpp__ensRipple_horizontalNode__) */
