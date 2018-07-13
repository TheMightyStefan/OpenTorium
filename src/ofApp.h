/**
 * @file ofApp.h
 *
 * @brief This file provides the interface of ofApp.
 */

#pragma once

#include "ofMain.h"

#include "emitter.h"
#include "field.h"

/**
 * @class ofApp
 *
 * This class encapsulates the behaviour of the program.
 *
 * An Emitter is used to create Particle instances with various
 * trajectories and speeds which are displayed on the screen.
 */
class ofApp : public ofBaseApp {
    private:
        ofPolyline shape;

        std::unique_ptr<Field> field;

        /** @brief The Emitter used to create Particle instances. **/
        std::unique_ptr<Emitter> emitter;
        /** @brief The std::list used to store the Particle instances used. **/
        std::list<std::unique_ptr<Particle>> particles;

        /** @brief The time that has passed since the beginning of the program. **/
        float timePassed;

    public:
        /** @brief Sets initial properties of the program (e.g. frame rate, background color). **/
        void setup();
        /** @brief Updates the screen / program.
         *
         * The Emitter and every Particle are updated.
         */
        void update();

        /** @brief Draws the Particle instances.
         *
         * draw() is called for every Particle.
         */
        void draw();
};
