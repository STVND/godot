/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "general_resource.h"
#include "lazy_state.h"

void initialize_simple_extension_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
	ClassDB::register_class<General_Resource>();
	ClassDB::register_class<Lazy_State>();
}

void uninitialize_simple_extension_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
   // Nothing to do here in this example.
}