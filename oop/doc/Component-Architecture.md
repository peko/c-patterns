Mojoc combines Component-Based, State-Machine, Message-Driven in one structure, which is [Component](https://github.com/scottcgi/Mojoc/blob/master/Engine/Application/Component.h).

* [Component-Based](#component-based)
* [State-Machine](#state-machine)
* [Message-Driven](#message-driven)
* [Mojoc Component](#mojoc-component)

## Component-Based
Here, there is no Entity to manage Components. The Entity function is merged into the Component. So all components build a recursive tree structure. A Component is a minimal reusable structure, and can manage a group of child Components.

```c
struct Component
{
    int                            order;
    Component*                     parent;
    ArrayIntMap(order, Component*) childMap[1];
};


struct AComponent
{
    void  (*AddChild)          (Component* parent, Component* child, int order);
    void  (*AppendChild)       (Component* parent, Component* child);
    void  (*RemoveChild)       (Component* parent, Component* child);
    void  (*RemoveAllChildren) (Component* parent);
    void  (*ReorderAllChildren)(Component* parent);
};
```

* Component through childMap control child components.
* Parallel child components are sorted by order.

## State-Machine
A Component has one or more states, and must be in a state. This means the Component has own State-Machine. Why Component has a State-Machine? 

Because everything has a state, this is an abstract mapping. The Component as a minimal reusable structure, usually has data and behavior, the state is the presentation of different behaviors under the different data.

```c
struct ComponentState
{
    int  id;
    void (*Update)     (Component* component, float deltaSeconds);
    void (*UpdateAfter)(Component* component, float deltaSeconds);
    bool (*OnMessage)  (Component* component, void* sender, int subject, void* extraData);
};


struct Component
{
    ComponentState*                       curState;
    ComponentState*                       preState;
    ComponentState*                       defaultState;
    ArrayIntMap(stateId, ComponentState*) stateMap[1];
};


struct AComponent
{
    void            (*SetState)(Component* component, int stateId);
    ComponentState* (*AddState)(Component* component, int stateId, ComponentStateOnMessage onMessage, ComponentStateUpdate update);
};
```

* Each state can receive and handle message.
* Components can build a hierarchical state machine system.

## Message-Driven
Component can be either a message publisher or a message subscriber. It‘s like a minimal interactive structure, Component implement control and feedback.

```c
struct Component
{
    ArrayIntSet(Component*) observerSet[1];
};


struct AComponent
{
    void (*AddObserver)   (Component* sender,    Component* observer);
    void (*RemoveObserver)(Component* sender,    Component* observer);
    bool (*SendMessage)   (Component* component, void*      sender,  int   subject, void* extraData);
    void (*Notify)        (Component* sender,    int        subject, void* extraData);
};
```

* SendMessage and Notify, both use OnMessage receive message notification.
* SendMessage for all child components.
* Notify for subscription components.

## Mojoc Component
It's a minimal reusable, interactive, stateful, composable structure.