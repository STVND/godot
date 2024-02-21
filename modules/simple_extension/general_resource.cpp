/* general_resource.cpp */

#include "general_resource.h"
#include "math.h"


void General_Resource::add_max_res(int p_value) {
    max_resource += abs(p_value);
}

void General_Resource::sub_max_res(int p_value) {
    if (max_resource - abs(p_value) > 0) {
        max_resource -= abs(p_value);
    } else {
        max_resource = 0;
    }
}

void General_Resource::sub_res_clamped(int p_value) {
    if(current_resource - abs(p_value) > 0) {
        current_resource -= abs(p_value);
    } else {
        current_resource = 0;
    }
} 

void General_Resource::add_res_clamped(int p_value) {
    if(current_resource + abs(p_value) < max_resource) {
        current_resource += abs(p_value);
    } else {
        current_resource = max_resource;
    }
}

void General_Resource::sub_res(int p_value) {
    current_resource -= abs(p_value);

} 

void General_Resource::add_res(int p_value) {
    current_resource += abs(p_value);

}

int General_Resource::get_res() {
    return current_resource;
}

int General_Resource::get_max_res() {
    return max_resource;
}

void General_Resource::set_max_res(int p_value) {
    max_resource = p_value;
}

void General_Resource::set_res(int p_value) {
    current_resource = p_value;
}






void General_Resource::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add_max_res", "value"), &General_Resource::add_max_res);
    ClassDB::bind_method(D_METHOD("sub_max_res", "value"), &General_Resource::sub_max_res);
    ClassDB::bind_method(D_METHOD("sub_res_clamped", "value"), &General_Resource::sub_res_clamped);
    ClassDB::bind_method(D_METHOD("add_res_clamped", "value"), &General_Resource::add_res_clamped);
    ClassDB::bind_method(D_METHOD("sub_res", "value"), &General_Resource::sub_res);
    ClassDB::bind_method(D_METHOD("add_res", "value"), &General_Resource::add_res);
    ClassDB::bind_method(D_METHOD("get_res"), &General_Resource::get_res);
    ClassDB::bind_method(D_METHOD("get_max_res"), &General_Resource::get_max_res);
    ClassDB::bind_method(D_METHOD("set_max_res", "value"), &General_Resource::set_max_res);
    ClassDB::bind_method(D_METHOD("set_res", "value"), &General_Resource::set_res);
}

General_Resource::General_Resource() {
    max_resource = 0;
    current_resource = 0;
}
