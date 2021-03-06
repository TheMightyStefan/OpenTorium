/**
 * @file particle.h
 *
 * @brief This module provides the interface of a Particle.
 */

#pragma once

/** @brief The minimum size of a particle. **/
constexpr int MIN_PARTICLE_SIZE = 1;
/** @brief The maximum size of a particle. **/
constexpr int MAX_PARTICLE_SIZE = 1000;

#include "ofMain.h"

/** @brief Defines the existing Particle types. */
enum ParticleType { 
    /** @brief The type of CircleParticle. */
    Circle 
};

/**
 * @class Particle
 *
 * @brief This class encapsulates the properties and the behaviour of a small
 * object, usually used to create bigger ones.
 *
 * The Particle has a known @b position and @b velocity, used to create a motion pattern.
 *
 * The object also has a maximum @b lifeTime. When its @b time of living equals the maximum @b lifeTime,
 * the Particle is said to be @b dead (until then being @b alive).
 *
 * When a Particle is @b dead, it can't pe updated and drawn.
 *
 * The Particle can be @b updated every frame, its @b position being modified using the @b velocity 
 * and the <b>time between frames</b>. When the object is updated, its time of living is updated.
 * If the new time exceeds the maximum lifeTime, the Particle is marked as @b dead.
 *
 * The Particle also has a color and a size.
 */
class Particle {
    protected:
        /** @brief The relativeative size of the Particle. **/
        const float relativeSize;

        /** @brief The size of the Particle. **/
        float size;

        /** @brief The color of the Particle. **/
        ofColor color;

        /** @brief The position of the Particle. **/
        ofPoint position;
        /** @brief The velocity of the Particle. **/
        ofVec2f velocity;

        /** @brief The acceleration of the Particle. **/
        ofVec2f acceleration;

        /** @brief The time passed since the Particle was created. **/
        float age;

        /** @brief The time at which the Particle is marked as @b dead. **/
        const float lifeTime;

        /** @brief The mass of the Particle. **/
        const float mass;

        /** @brief The alive / dead marker. **/
        bool live;

    public:
        /** 
         * @brief Constructs the Particle, using several properties.
         *
         * @param relativeSize -> The relativeative size of the Particle.
         *
         * @param mass -> The mass of the Particle.
         *
         * @param color -> The color of the Particle.
         *
         * @param position -> The position of the Particle.
         *
         * @param velocity -> The velocity of the Particle.
         *
         * @param lifeTime -> The maximum lifeTime of the Particle.
         */
        Particle(float relativeSize, const ofColor &color, const ofPoint &position, 
                 const ofVec2f &velocity, float lifeTime, float mass = 1.0);

        /** @brief Updates the Particle.
         *
         * The @b position is updated using the @b velocity of the Particle and @p deltaTime.
         *
         * The @b living time of the Particle is updated. The Particle is marked as @b dead
         * if the living time exceeds the maximum @b lifeTime.
         *
         * @param deltaTime -> The time passed since the last update.
         */
        void update(float deltaTime);

        /** @brief Draws the Particle. **/
        virtual void draw() const = 0;

        /** 
         * @brief Checks if the Particle is @b alive.
         *
         * @return @b true if the Paticle is @b alive, false otherwise.
         */
        bool isAlive() const;

        /**
         * @brief Returns the position of the Particle.
         */
        ofPoint getPosition() const;

        /**
         * @brief Returns the color of the Particle.
         */
        ofColor getColor() const;

        /**
         * @brief Assigns a new color to the Particle.
         *
         * @param color -> The new color.
         */
        void setColor(const ofColor &color);

        /**
         * @brief Applies a force on the Particle (modifies its acceleration).
         *
         * @param force The force to be applied.
         */
        void applyForce(const ofPoint &force);

        /**
         * @brief Adjusts the velocity and position of the Particle after window resize.
         */
        void scale(const ofVec2f &screenChangeProportion);

        /**
         * @brief Kills the Particle
         *
         * It won't be updated or drawn anymore and most likely be deleted.
         */
        void kill();
};

/**
 * @class CircleParticle
 *
 * @brief This class represents a circle-shaped Particle.
 */
class CircleParticle : public Particle {
    public:
        /** 
         * @brief Constructs the CircleParticle, using several properties.
         *
         * @param relativeSize -> The relativeative size of the Particle.
         *
         * @param color -> The color of the Particle.
         *
         * @param mass -> The mass of the Particle.
         *
         * @param position -> The position of the Particle.
         *
         * @param velocity -> The velocity of the Particle.
         *
         * @param lifeTime -> The maximum lifeTime of the Particle.
         */
        CircleParticle(float relativeSize, const ofColor& color, const ofPoint &position, 
                       const ofVec2f &velocity, int lifeTime, float mass = 1.0);

        /**
         * @brief Draws the CircleParticle.
         *
         * The Particle is drawn as a circle, using the size, color and position of the CircleParticle.
         */
        void draw() const;
};

/** 
 * @brief Creates a Particle and returns a std::unique_ptr to it.
 *
 * If a new type of Particle is used, a new entry must be added in 
 * the ParticleType enum.
 *
 * @param type -> The type of the Particle.
 *
 * @param relativeSize -> The relativeative size of the Particle.
 *
 * @param color -> The color of the Particle.
 *
 * @param mass -> The mass of the Particle.
 *
 * @param position -> The position of the Particle.
 *
 * @param velocity -> The velocity of the Particle.
 *
 * @param lifeTime -> The maximum lifeTime of the Particle.
*/
std::unique_ptr<Particle> getParticle(const enum ParticleType &type,
                                      float relativeSize, 
                                      const ofColor &color,
                                      const ofPoint &position,
                                      const ofVec2f &velocity,
                                      float lifeTime);
