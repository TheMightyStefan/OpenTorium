#include "target.h"

Target::Target(const ofRectangle& zone) :
    targetZone(zone), neededParticles(50), neededFlowRate(1)  {
        lastParticleTime = ofGetElapsedTimef();

        currentParticles = 0;
}

bool Target::inside(const ofPoint& point) const {
    return targetZone.inside(point);
}

void Target::update() {
    const float timeSinceLastParticle = ofGetElapsedTimef() - lastParticleTime;

    if (currentParticles >= neededParticles)
        std::cout << "Done" << std::endl;
    else {
        if (timeSinceLastParticle > neededFlowRate)
            currentParticles--;
    }

    currentParticles = ofClamp(currentParticles, 0, neededParticles);
}

void Target::updateParticle(Particle &particle) {
    particle.kill();

    currentParticles++;

    lastParticleTime = ofGetElapsedTimef();
}

void Target::draw() const {
    ofPushStyle();

    ofNoFill();

    ofDrawRectangle(targetZone);

    ofFill();

    ofRectangle progressRender = ofRectangle(targetZone.x, targetZone.y, targetZone.width, 1);
    progressRender.scaleHeight(ofMap(currentParticles, 0, neededParticles, 1, targetZone.height));

    ofDrawRectangle(progressRender);

    ofPopStyle();
}
