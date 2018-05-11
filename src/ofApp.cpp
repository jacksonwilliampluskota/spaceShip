#include "ofApp.h"
#include <iostream>
#include <math.h>
#include "actor.h"
using namespace std;

float _startDeltaTime;
float _interval = 0.07f;
float velocity = 10.0f;
bool clicked = false;

actor *spaceship;
actor *escudo;

//--------------------------------------------------------------
void ofApp::setup()
{
    _startDeltaTime = ofGetElapsedTimef();

    spaceship = new actor(450, 350, "images/spaceship.png");
    escudo = new actor(500, 500, "images/moon.png");
    spaceship->imagem.setAnchorPercent(0.5f, 0.5f);
    escudo->getDistancia(spaceship->vetor);
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSetBackgroundColor(0, 0, 0, 255);
    if (ofGetElapsedTimef() - _startDeltaTime > _interval)
    {
        escudo->rotation();

        if (clicked)
        {
            spaceship->vetor.x += velocity * cos(spaceship->rotationClick * PI / 180);
            spaceship->vetor.y += velocity * sin(spaceship->rotationClick * PI / 180);
        }

        if ((spaceship->vetor.x > ofGetWindowWidth()) || (spaceship->vetor.x < 0))
        {
            velocity = velocity * -1;
            spaceship->rotationClick += 90;
        }
        if ((spaceship->vetor.y > ofGetWindowHeight()) || (spaceship->vetor.y < 0))
        {
            velocity = velocity * -1;
            spaceship->rotationClick += 90;
        }

        _startDeltaTime = ofGetElapsedTimef();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(spaceship->vetor.x, spaceship->vetor.y);
    ofRotateZ(90 + spaceship->rotationClick);
    spaceship->draw();
    ofPushMatrix();
    ofTranslate(escudo->vetor.x, escudo->vetor.y);
    escudo->draw();
    ofPopMatrix();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    spaceship->clickMouse(x, y);
    clicked = true;

    //--------------------------------------------------------------
    void ofApp::mouseReleased(int x, int y, int button)
    {
    }

    //--------------------------------------------------------------
    void ofApp::mouseEntered(int x, int y)
    {
    }

    //--------------------------------------------------------------
    void ofApp::mouseExited(int x, int y)
    {
    }

    //--------------------------------------------------------------
    void ofApp::windowResized(int w, int h)
    {
    }

    //--------------------------------------------------------------
    void ofApp::gotMessage(ofMessage msg)
    {
    }

    //--------------------------------------------------------------
    void ofApp::dragEvent(ofDragInfo dragInfo)
    {
    }
