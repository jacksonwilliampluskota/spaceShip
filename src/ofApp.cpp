#include "ofApp.h"
#include <iostream>
#include <math.h>
using namespace std;

ofVec2f terra;
ofVec2f lua;
ofVec2f distanciaLuaTerra;
ofVec2f newPosition;
ofVec2f mouseposition;
float rotacao = 30.0f;
ofImage planetaTerra;
ofImage planetaLua;
float _startDeltaTime;
float _interval = 0.07f;
float angle;
float sen;
float coss;
float newX;
float newY;
float rotationClick;
float velocity = 10.0f;
bool clicked = false;

//--------------------------------------------------------------
void ofApp::setup(){
    _startDeltaTime = ofGetElapsedTimef();
    angle = rotacao * PI / 180;
    terra.set(450, 350);
    lua.set(500, 500);
    distanciaLuaTerra = lua - terra;

    planetaTerra.load("images/spaceship.png");
    planetaLua.load("images/moon.png");
    planetaTerra.setAnchorPercent(0.5f, 0.5f);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetBackgroundColor(0, 0, 0, 255);
    if (ofGetElapsedTimef() - _startDeltaTime > _interval)
    {
        sen = sin(angle);
        coss = cos(angle);

        newX = distanciaLuaTerra.x * coss - distanciaLuaTerra.y * sen;
        newY = distanciaLuaTerra.x * sen + distanciaLuaTerra.y * coss;
        newPosition.set(newX, newY);

        lua = newPosition;

        angle += 1;
        if(clicked) {
            terra.x += velocity * cos(rotationClick*PI/180);
            terra.y += velocity * sin(rotationClick*PI/180);

        }

        _startDeltaTime = ofGetElapsedTimef();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(terra.x, terra.y);
    ofRotateZ(90 + rotationClick);
    planetaTerra.draw(0, 0);
    ofPushMatrix();
    ofTranslate(lua.x, lua.y);
    planetaLua.draw(0, 0);
    ofPopMatrix();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    mouseposition.set(x, y);
    ofVec2f newVec = mouseposition - terra;
    rotationClick = (atan2(newVec.y, newVec.x) * 180) / PI;
    clicked = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
