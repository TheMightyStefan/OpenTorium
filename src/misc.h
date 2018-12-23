#pragma once

#include <string>

#include "ofColor.h"
#include "ofVec2f.h"
#include "ofPoint.h"

#include "shape.h"

bool getBool(const std::string &boolString);

ofColor getColor(const std::string &colorString);
ofVec2f getVec2f(const std::string &vecString);

ofPoint scaleToScreen(const ofPoint& toScale);

PolylineShape *getPolyline(const std::string& polylineString);
