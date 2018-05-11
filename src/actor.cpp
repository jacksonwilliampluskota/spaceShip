#include "actor.h"

actor::actor(int x, int y, string pathString)
{
  vetor.set(x, y);
  imagem.load(pathString);

  angle = toRadians(rotacao);
}

void actor::draw()
{
  imagem.draw(0, 0);
}

void actor::rotation()
{
  sen = sin(angle);
  coss = cos(angle);

  newX = distanciaEntre.x * coss - distanciaEntre.y * sen;
  newY = distanciaEntre.x * sen + distanciaEntre.y * coss;
  newPosition.set(newX, newY);
  angle += 1;

  vetor = newPosition;
}

ofVec2f actor::getDistancia(ofVec2f other)
{

  return distanciaEntre = vetor - other;
}

void actor::clickMouse(int x, int y)
{
  mouseposition.set(x, y);
  ofVec2f newVec = mouseposition - vetor;
  rotationClick = vecToAngle(newVec);
  clicked = true;
}

float actor::vecToAngle(ofVec2f vec)
{
  return toDegree(atan2(vec.y, vec.x));
}

float actor::toDegree(float angle)
{
  return angle * 180 / PI;
}

float actor::toRadians(float angle)
{
  return angle * PI / 180;
}

actor::~actor()
{
}