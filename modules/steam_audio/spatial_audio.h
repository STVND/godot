#ifndef SPATIAL_AUDIO_H
#define SPATIAL_AUDIO_H

#include "core/object/object.h"
#include "core/object/class_db.h"
#include "steamaudio/include/phonon.h"


struct IPLContextSettings;
typedef int IPLerror;
typedef void* IPLContext;

// External functions from Steam Audio SDK
extern "C" IPLerror iplContextCreate(IPLContextSettings* settings, IPLContext* context);
extern "C" void iplContextRelease(IPLContext* context);

// Placeholder for success status from SDK
#define IPL_STATUS_SUCCESS 0

class SpatialAudio : public Object {
	GDCLASS(SpatialAudio, Object);

	IPLContext context = nullptr;

public:
	static SpatialAudio *get_singleton(); // Method to get the singleton instance

	void initialize(); // Initializes the Steam Audio SDK
	void shutdown();   // Shuts down the Steam Audio SDK

	SpatialAudio();
	~SpatialAudio();

protected:
	static void _bind_methods();
};

#endif