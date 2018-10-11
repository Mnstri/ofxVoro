#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    
    light.setPosition(100,500, 100);
    cam.setAutoDistance(true);
    
    makeTissue(50, ofGetHeight()*0.8, ofGetHeight()*0.8, 20);
}

void ofApp::makeTissue(int _nCells, int _width, int _height, int _deep){
    
    //  Fresh begining
    //
    cellMeshes.clear();
    cellCentroids.clear();
    cellRadius.clear();
    
    //  Define a container
    //
    voro::container con(-_width*0.5,_width*0.5,
                        -_height*0.5,_height*0.5,
                        -_deep*0.5,_deep*0.5,
                        1,1,1,
                        true,true,true,
                        8);
    
    //  Add walls (un comment one pair if you like to shape the container)
    //
    voro::wall_cylinder cyl(0,0,0,0,0,20, min(_width*0.5, _height*0.5));
    con.add_wall(cyl);
    
//    voro::wall_sphere sph(0, 0, 0, min(_width*0.5, _height*0.5) );
//    con.add_wall(sph);
    
//    voro::wall_cone cone(0,0,min(_width*0.5, _height*0.5),0,0,-1,atan(0.5));
//    con.add_wall(cone);
    
    //  Add the cell seed to the container
    //
    for(int i = 0; i < _nCells;i++){
        glm::vec3 newCell = glm::vec3(ofRandom(-_width*0.5,_width*0.5),
                                  ofRandom(-_height*0.5,_height*0.5),
                                  ofRandom(-_deep*0.25,_deep*0.25));
    
        addCellSeed(con, newCell, i, true);
    }
    
    cellMeshes = getCellsFromContainer(con,0.0);
    cellMeshWireframes = getCellsFromContainer(con,0.0,true);
    cellRadius = getCellsRadius(con);
    cellCentroids = getCellsCentroids(con);
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    ofPushMatrix();
    cam.begin();
    light.enable();
    ofEnableLighting();
    glEnable(GL_DEPTH_TEST);
    
    for (int i = 0; i < cellCentroids.size(); i++){
        ofSetColor(0);
		ofSphere(cellCentroids[i], cellRadius[i]*0.15);
    }
    
    for(int i = 0; i < cellMeshes.size(); i++){
        ofSetColor(100,30);
        cellMeshes[i].drawFaces();
        
        ofPushStyle();
        ofSetLineWidth(3);
        ofSetColor(100);
        cellMeshWireframes[i].draw();
        ofPopStyle();
    }
    
    glDisable(GL_DEPTH_TEST);
    ofDisableLighting();
    light.disable();
    cam.end();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == 'f'){
        ofToggleFullscreen();
    } else {
        makeTissue(50, ofGetWidth()*0.8, ofGetHeight()*0.8,20);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
