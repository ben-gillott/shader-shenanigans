//
//  GLGameScene.h
//  Programming Lab
//
//  This is the primary class file for running the game.  You should study this file for
//  ideas on how to structure your own root class. This class is a reimagining of the
//  first game lab from 3152 in CUGL.
//
//  Author: Walker White
//  Based on original GameX Ship Demo by Rama C. Hoetzlein, 2002
//  Version: 2/21/21
//
#ifndef __SG_GAME_SCENE_H__
#define __SG_GAME_SCENE_H__
#include <cugl/cugl.h>
#include <vector>
#include "GLInputController.h"
#include "GLShip.h"
#include "GLPhotonQueue.h"


/**
 * This class is the primary gameplay constroller for the demo.
 *
 * A world has its own objects, assets, and input controller.  Thus this is
 * really a mini-GameEngine in its own right.  As in 3152, we separate it out
 * so that we can have a separate mode for the loading screen.
 */
class GameScene : public cugl::Scene2 {
protected:
    /** The asset manager for this game mode. */
    std::shared_ptr<cugl::AssetManager> _assets;

    /**
     * Activates the UI elements to make them interactive
     *
     * The elements do not actually do anything.  They just visually respond
     * to input.
     */
    void activateUI(const std::shared_ptr<cugl::scene2::SceneNode>& scene);
    
    // Attach input controllers directly to the scene (no pointers)
    /** Controller for the blue player */
    InputController _blueController;
    /** Controller for the blue player */
    InputController _redController;

    /** Location and animation information for blue ship (MODEL CLASS) */
    std::shared_ptr<Ship> _blueShip;
    /** Location and animation information for red ship (MODEL CLASS) */
    std::shared_ptr<Ship> _redShip;
    /** Shared memory pool for photons. (MODEL CLASS) */
    std::shared_ptr<PhotonQueue> _photons;
    
    /** The weapon fire sound for the blue player */
    std::shared_ptr<cugl::Sound> _blueSound;
    /** The weapon fire sound for the red player */
    std::shared_ptr<cugl::Sound> _redSound;


public:
#pragma mark -
#pragma mark Constructors
    /**
     * Creates a new game mode with the default values.
     *
     * This constructor does not allocate any objects or start the game.
     * This allows us to use the object without a heap pointer.
     */
    GameScene() : cugl::Scene2() {}
    
    /**
     * Disposes of all (non-static) resources allocated to this mode.
     *
     * This method is different from dispose() in that it ALSO shuts off any
     * static resources, like the input controller.
     */
    ~GameScene() { dispose(); }
    
    /**
     * Disposes of all (non-static) resources allocated to this mode.
     */
    void dispose() override;
    
    /**
     * Initializes the controller contents, and starts the game
     *
     * The constructor does not allocate any objects or memory.  This allows
     * us to have a non-pointer reference to this controller, reducing our
     * memory allocation.  Instead, allocation happens in this method.
     *
     * @param assets    The (loaded) assets for this game mode
     *
     * @return true if the controller is initialized properly, false otherwise.
     */
    bool init(const std::shared_ptr<cugl::AssetManager>& assets);

    
#pragma mark -
#pragma mark Gameplay Handling
    /**
     * The method called to update the game mode.
     *
     * This method contains any gameplay code that is not an OpenGL call.
     *
     * @param timestep  The amount of time (in seconds) since the last frame
     */
    void update(float timestep) override;

    /**
     * Draws all this scene to the given SpriteBatch.
     *
     * The default implementation of this method simply draws the scene graph
     * to the sprite batch.  By overriding it, you can do custom drawing
     * in its place.
     *
     * @param batch     The SpriteBatch to draw with.
     */
    void render(const std::shared_ptr<cugl::SpriteBatch>& batch) override;

    /**
     * Resets the status of the game so that we can play again.
     */
    void reset() override;

    /**
     * Fires a photon from the ship, adding it to the PhotonQueue.
     *
     * This is not inside either PhotonQueue or Ship because it is a relationship
     * between to objects.  As we will see in class, we do not want to code binary
     * relationships that way (because it increases dependencies).
     *
     * @param ship      Ship firing the photon
     * @param photons     PhotonQueue for allocation
     */
    bool firePhoton(const std::shared_ptr<Ship>& ship);
};

#endif /* __SG_GAME_SCENE_H__ */
