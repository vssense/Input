#ifndef _EVENT_HPP_INCLUDED
#define _EVENT_HPP_INCLUDED

// Scroll event
// Study what is Text input. What is codepoints? Didn't get it.

#include <queue>

#include "window.hpp"

namespace input
{

enum EventType
{
    kNoEvent,
    kQuit,
    kKey,
    kMouseButton,
    kMouseMove,
    kMouseScroll,

    // kMouseEnter,
    // kMouseLeave,
};

enum Action
{
    kPress,
    kRelease,
    kHold
};

enum MouseButton
{
    kLeftMouseButton,
    kRightMouseButton,
    kMiddleMouseButton,
    kX1MouseButton,
    kX2MouseButton
};

struct ButtonMode
{
    bool shift_pressed : 1;
    bool ctrl_pressed  : 1;
    bool alt_pressed   : 1;
};

struct ScrollEventData
{
    int dx;
    int dy;
};

struct MouseMoveEventData         // Do we need dx and dy here?
{
    int x;
    int y;
};

struct MouseButtonEventData        // Do we need coords here?
{
    MouseButton button;
    Action action;
    ButtonMode mode;
};

struct KeyEventData
{
    int key;              // Actually ascii codes
    int scancode;
    Action action;
    ButtonMode mods;      // Check with ButtonMode
};

union EventData
{
    MouseMoveEventData   mouse;
    MouseButtonEventData button;
    KeyEventData         key;
    ScrollEventData      scroll;
};

class Event
{
  public:

    EventType& GetType()
    {
        return type_;
    }

    EventData& GetData()
    {
        return data_;
    }

  private:
    EventType type_;
    EventData data_;
};

bool PollEvent(Event* event);

class EventQueue
{
  private:
    EventQueue() {}

  public:
    static void SetWindow(Window* window);

    static void PostEvent(const Event& event);
    static bool PollEvent(Event* event);

  private:
    static void KeyCallback        (GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void MouseMoveCallback  (GLFWwindow* window, double xpos, double ypos);
    static void CloseCallback      (GLFWwindow* window);
    static void ScrollCallback     (GLFWwindow* window, double dx, double dy);

    static Window* window_;
    static std::queue<Event> queue_;
};

} // namespace event

#endif // _EVENT_HPP_INCLUDED