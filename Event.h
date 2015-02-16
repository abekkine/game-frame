// Copyright 2015 A.Bekkine
#ifndef EVENT_H_
#define EVENT_H_

#include <SDL/SDL.h>

#include <vector>
#include <map>

#include "Vector.h"

class EventCallback {
 public:
    enum ButtonType {
        bt_NONE = 0,
        bt_LEFT,
        bt_RIGHT,
        bt_MIDDLE
    };

    // Used for both buttons and keys.
    enum StateType {
        st_NONE = 0,
        st_UP,
        st_DOWN
    };

    enum EventType {
        et_NONE = 0,
        et_BUTTON,
        et_MOTION,
        et_KEY
    };

    typedef struct {
        EventType event;
        ButtonType button;
        StateType state;
        int key;
        int x;
        int y;
    } EventInfo;

 public:
    virtual ~EventCallback() {}
    virtual void Call(const EventInfo& event) = 0;
};

class Event {
 public:
    Event();
    ~Event();
    void Update();
    void RegisterCallback(EventCallback::EventType type,
                          EventCallback* callback);
    bool QuitCondition();

 private:
    void InitVariables();
    void Poll();
    void MotionEvent();
    void ButtonEvent(EventCallback::StateType state);
    void KeyEvent(EventCallback::StateType state);
    void InvokeButtonCallbacks(EventCallback::ButtonType,
                               EventCallback::StateType state);

 private:
    SDL_Event _event;
    bool _quit_condition;
    Vector2i _mouse;
    std::vector<EventCallback *> _button_callbacks;
    std::vector<EventCallback *> _motion_callbacks;
    std::vector<EventCallback *> _key_callbacks;
};

#endif  // EVENT_H_
