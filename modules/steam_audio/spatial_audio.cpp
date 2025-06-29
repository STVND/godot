#include "spatial_audio.h"
#include "core/os/os.h"
#include "core/engine.h" // Needed for Engine::get_singleton() in get_singleton() method

void SpatialAudio::_bind_methods() {
	// No methods exposed to GDScript yet, but this is where they would go.
	// ClassDB::bind_method(D_METHOD("some_method"), &SteamAudio::some_method);
	// ClassDB::bind_method(D_METHOD("initialize"), &SteamAudio::initialize);
	// ClassDB::bind_method(D_METHOD("shutdown"), &SteamAudio::shutdown);
}

SpatialAudio *SpatialAudio::get_singleton() {
    return static_cast<SpatialAudio *>(Engine::get_singleton()->get_singleton_object("SpatialAudio"));
}

void SpatialAudio::initialize() {
	IPLContextSettings context_settings{};
	context_settings.version = STEAMAUDIO_VERSION;
	context_settings.simdlevel = IPL_SIMDLEVEL_AVX2;

	IPLerror result = iplContextCreate(&context_settings, &context);
	if (result != IPL_STATUS_SUCCESS) {
		OS::get_singleton()->print_error("Spatial Audio: Failed to create context.", __FUNCTION__, __FILE__, __LINE__);
		context = nullptr;
	}
	else {
        OS::get_singleton()->print_verbose("Spatial Audio: Context created successfully.");
    }
}

void SpatialAudio::shutdown() {
	if (context) {
		iplContextRelease(&context);
		context = nullptr;
        OS::get_singleton()->print_verbose("Spatial Audio: Context released.");
	}
}

SpatialAudio::SpatialAudio() {
}

SpatialAudio::~SpatialAudio() {
	shutdown();
}