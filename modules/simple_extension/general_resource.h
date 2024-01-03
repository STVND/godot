/* general_resource.h */


#ifndef GENERAL_RESOURCE_H
#define GENERAL_RESOURCE_H

#include "core/object/ref_counted.h"

class General_Resource: public RefCounted {
    GDCLASS(General_Resource, RefCounted);

    int max_resource;
    int min_resource;
    int current_resource;

protected:
    static void _bind_methods();

public:
    void add_max_res(int p_value);
    void sub_max_res(int p_value);
    void add_min_res(int p_value);
    void sub_min_res(int p_value);
    void set_max_res(int p_value);
    void set_min_res(int p_value);
    void set_res(int p_value);
    void sub_res(int p_value);
    void add_res(int p_value);
    int get_res();
    int get_max_res();
    int get_min_res();

    General_Resource();

};

#endif // GENERAL_RESOURCE_H