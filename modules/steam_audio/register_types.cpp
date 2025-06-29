#include "register_types.h"

#include "core/object/class_db.h"
#include "core/engine.h"

#include "spatial_audio.h"
#include "audio_material.h"

static SpatialAudio *spatial_audio_singleton = nullptr;

void initialize_spatial_audio_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<AudioMaterial>();
	ClassDB::register_class<SpatialAudio>();

	spatial_audio_singleton = memnew(SpatialAudio);
	Engine::get_singleton()->add_singleton(Engine::Singleton("SpatialAudio", spatial_audio_singleton));
	spatial_audio_singleton->initialize();
}

void uninitialize_spatial_audio_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	if (spatial_audio_singleton) {
		spatial_audio_singleton->shutdown();
		memdelete(spatial_audio_singleton);
		spatial_audio_singleton = nullptr;
	}
}