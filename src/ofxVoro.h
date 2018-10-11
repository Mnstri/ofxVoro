//
//  ofxVoro.h
//  Funtions for wrapping Voro++ library ( http://math.lbl.gov/voro++/ )
//
//  Created by Patricio Gonzalez Vivo on 4/17/13.
//
//

#pragma once

#include "ofMain.h"

#include "voro++.hh"

//  cell (voronoicell) wrappers
//
float           getCellRadius(voro::voronoicell &_con);
glm::vec3         getCellCentroid(voro::voronoicell &_con, glm::vec3 _pos = glm::vec3(0,0,0));
vector<glm::vec3> getCellVerteces(voro::voronoicell &_con, glm::vec3 _pos = glm::vec3(0,0,0));
ofVboMesh          getCellMesh(voro::voronoicell &_con, glm::vec3 _pos = glm::vec3(0,0,0), bool bWireframe = false);
void            getCellMesh(voro::voronoicell &_c, glm::vec3 _pos, ofVboMesh& mesh, bool bWireframe = false);
void            getCellMesh(voro::voronoicell &_c, ofVboMesh& mesh, bool bWireframe = false);

//  container wrappers
//
void            addCellSeed(voro::container &_con, glm::vec3 &_pnt, int _i, bool _checkInside = false);
void            addCellSeed(voro::container &_con, glm::vec3 *_pnt, int _i, bool _checkInside = false);
void            addCellsSeeds(voro::container &_con, vector<glm::vec3> &_pnts, bool _checkInside = false);
void            addCellsSeeds(voro::container &_con, vector<glm::vec3*> &_pnts, bool _checkInside = false);
void            addCellsSeeds(voro::container &_con, glm::vec3 *_pnts, int _nSize, bool _checkInside = false);

vector<float>   getCellsRadius(voro::container &_con);
vector<ofVboMesh>  getCellsFromContainer(voro::container &_con, float _wallsThikness, bool bWireframe = false);
void            getCellsFromContainer(voro::container &_con, float _wallsThikness, vector<ofVboMesh>& cells, bool bWireframe = false);
void            getCellsFromContainer(voro::container &_con, vector<ofVboMesh>& cells, bool bWireframe = false);
void            getCellsFromContainer(voro::container &_con, vector<ofVboMesh>& cells, float _maxRadius, bool bWireframe = false);
vector<ofVboMesh>  getCellsFromContainer(voro::container &_con, float _wallsThikness, float _maxRadius, bool bWireframe);
vector<glm::vec3> getCellsPositions(voro::container &_con);
vector<glm::vec3> getCellsCentroids(voro::container &_con);
vector< ofPolyline > getCellsPolylines(voro::container &_con);
vector< vector<glm::vec3> > getCellsVertices(voro::container &_con);


bool            insideContainer(voro::container &_con, glm::vec3 _pnt);
