#ifndef VIOLET_ACTORBEHAVIOR_HPP
#define VIOLET_ACTORBEHAVIOR_HPP
/**
 * The main class that defines an actors behavior.
 * This will keep all the state for how an actor:
 *   - moves
 *   - recieves input
 *   - behaves to events
 *   Physics/Rendering/Collision may be allowed to be modified through classes using this interface.
 **/


namespace Violet {
  class Actor;
  class ActorBehavior{
    public:
      virtual ~ActorBehavior() {}
      virtual void setup(){}
      virtual void update(Actor& object){}
      /**
       * How actors are attached to player and AI input.
       * One input commander may control multiple entities,
       * but each entity may only have one commander.
       */
      //virtual void setInputHandler(InputCommander& handler){}

    protected:
      //InputHandler* handler;
  };

  class NullActorBehavior: public ActorBehavior {
 };
}

#endif // VIOLET_ACTORBEHAVIOR_HPP
