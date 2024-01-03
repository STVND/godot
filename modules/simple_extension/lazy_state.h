#ifndef LAZY_STATE_H
#define LAZY_STATE_H

#include "core/object/ref_counted.h"

class Lazy_State: public RefCounted {
    GDCLASS(Lazy_State, RefCounted);

    bool state_condition;
    bool current_state;

protected:
    static void _bind_methods();

public:
    void set_condition(bool p_value);
    void update_state();
    bool state_changed();
    bool is_active();

    Lazy_State();

};

#endif