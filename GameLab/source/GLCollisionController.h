//
//  GLCollisionController.h
//  Programming Lab
//
//  Unless you are making a point-and-click adventure game, every single
//  game is going to need some sort of collision detection.  In a later
//  lab, we will see how to do this with a physics engine. For now, we use
//  custom physics.
//
//  You might ask why we need this file when we have Box2d. That is because
//  we are trying to make this code as close to that of 3152 as possible. At
//  this point in the semester of 3152, we had not covered Box2d.
//
//  However, you will notice that this is NOT A CLASS.  The collision
//  controller in 3152 did not have any state to speak of (it had some cache
//  objects that are completely unnecessary in C++.  So we can just do this
//  as a collection of functions.  But if you do that, we recommend that
//  you put the functions together in a namespace, like we have done here.
//
//  Author: Walker M. White
//  Based on original GameX Ship Demo by Rama C. Hoetzlein, 2002
//  Version: 2/21/21
//
#ifndef __GL_COLLISION_CONTROLLER_H__
#define __GL_COLLISION_CONTROLLER_H__
#include <cugl/cugl.h>
#include "GLShip.h"
#include "GLPhotonQueue.h"

/**
 * Namespace of functions implementing simple game physics.
 *
 * This is the simplest of physics engines. In reality, you will
 * probably use Box2d just like you did in 3152.
 */
namespace collisions {
/**
 *  Handles collisions between ships, causing them to bounce off one another.
 *
 *  This method updates the velocities of both ships: the collider and the
 *  collidee. Therefore, you should only call this method for one of the
 *  ships, not both. Otherwise, you are processing the same collisions twice.
 *
 *  @param ship1    First ship in candidate collision
 *  @param ship2    Second ship in candidate collision
 */
void checkForCollision(const std::shared_ptr<Ship>& ship1, const std::shared_ptr<Ship>& ship2);

/**
 *  Handles collisions between a ship and a photon.
 *
 *  A collision bounces the hit ship back and destroys the photon (e.g. age
 *  is set to the maximum).
 *
 *  @param ship     The ship in the candidate collision
 *  @param photons  The photons in the candidate collision
 */
void checkForCollision(const std::shared_ptr<Ship>& ship, const std::shared_ptr<PhotonQueue>& photons);

/**
 * Nudge the ship to ensure it does not do out of view.
 *
 * This code bounces the ship off walls.  You will replace it as part of
 * the lab.
 *
 * @param ship      They player's ship which may have collided
 * @param bounds    The rectangular bounds of the playing field
 */
void checkInBounds(const std::shared_ptr<Ship>& ship, const cugl::Rect bounds);

/**
 * Nudge the photons to ensure they do not do out of view.
 *
 * This code bounces the photons off walls.  You will replace it as part of
 * the lab.
 *
 * @param photons   They photon queue
 * @param bounds    The rectangular bounds of the playing field
 */
void checkInBounds(const std::shared_ptr<PhotonQueue>& photons, const cugl::Rect bounds);
}

#endif /* __GL_COLLISION_CONTROLLER_H__ */
