#include "lazy_state.h"

void Lazy_State::set_condition(bool p_value) {
    state_condition = p_value;
}

void Lazy_State::update_state() {
    current_state = !current_state;
}

bool Lazy_State::is_active() {
    return state_condition;
}


bool Lazy_State::state_changed() {
    if (state_condition == current_state) {
        return false;
    } else {
        return true;
    } 
}


void Lazy_State::_bind_methods() {

    ClassDB::bind_method(D_METHOD("set_condition", "value"), &Lazy_State::set_condition);
    ClassDB::bind_method(D_METHOD("update_state"), &Lazy_State::update_state);
    ClassDB::bind_method(D_METHOD("return_state"), &Lazy_State::is_active);
    ClassDB::bind_method(D_METHOD("state_changed"), &Lazy_State::state_changed);

}

Lazy_State::Lazy_State() {
    state_condition = false;
    current_state = false;


}