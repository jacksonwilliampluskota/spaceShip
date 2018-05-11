#pragma once
#include <iostream>
#include "ofImage.h"
#include "ofVec2f.h"

class actor
{
  private:
    /* data */
  public:
    ofImage imagem;

    ofVec2f vetor;
    ofVec2f distanciaEntre;
    ofVec2f newPosition;
    ofVec2f mouseposition;

    bool clicked = false;

    float angle;
    float sen;
    float coss;
    float newX;
    float newY;
    float rotationClick;
    float rotacao = 30.0f;

    actor(int x, int y, string pathString);
    void draw();
    void rotation();
    ofVec2f getDistancia(ofVec2f other);
    void clickMouse(int x, int y);

    float toDegree(float angle);
    float toRadians(float angle);
    float vecToAngle(ofVec2f vec);
    ~actor();
};
