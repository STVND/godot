#include "audio_material.h"

void AudioMaterial::_bind_methods() {
	// Preset Enum
	ClassDB::bind_method(D_METHOD("set_preset", "preset"), &AudioMaterial::set_preset);
	ClassDB::bind_method(D_METHOD("get_preset"), &AudioMaterial::get_preset);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "preset", PROPERTY_HINT_ENUM, "Generic,Brick,Concrete,Ceramic,Gravel,Carpet,Glass,Plaster,Wood,Metal,Rock,Custom"), "set_preset", "get_preset");

	// Absorption (Low, Mid, High correspond to 400Hz, 2.5kHz, 15kHz bands)
	ClassDB::bind_method(D_METHOD("set_absorption_low", "absorption_low"), &AudioMaterial::set_absorption_low);
	ClassDB::bind_method(D_METHOD("get_absorption_low"), &AudioMaterial::get_absorption_low);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "absorption/low", PROPERTY_HINT_RANGE, "0.0,1.0,0.01"), "set_absorption_low", "get_absorption_low");

	ClassDB::bind_method(D_METHOD("set_absorption_mid", "absorption_mid"), &AudioMaterial::set_absorption_mid);
	ClassDB::bind_method(D_METHOD("get_absorption_mid"), &AudioMaterial::get_absorption_mid);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "absorption/mid", PROPERTY_HINT_RANGE, "0.0,1.0,0.01"), "set_absorption_mid", "get_absorption_mid");

	ClassDB::bind_method(D_METHOD("set_absorption_high", "absorption_high"), &AudioMaterial::set_absorption_high);
	ClassDB::bind_method(D_METHOD("get_absorption_high"), &AudioMaterial::get_absorption_high);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "absorption/high", PROPERTY_HINT_RANGE, "0.0,1.0,0.01"), "set_absorption_high", "get_absorption_high");

	// Transmission
	ClassDB::bind_method(D_METHOD("set_transmission_low", "transmission_low"), &AudioMaterial::set_transmission_low);
	ClassDB::bind_method(D_METHOD("get_transmission_low"), &AudioMaterial::get_transmission_low);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "transmission/low", PROPERTY_HINT_RANGE, "0.0,1.0,0.01"), "set_transmission_low", "get_transmission_low");

	ClassDB::bind_method(D_METHOD("set_transmission_mid", "transmission_mid"), &AudioMaterial::set_transmission_mid);
	ClassDB::bind_method(D_METHOD("get_transmission_mid"), &AudioMaterial::get_transmission_mid);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "transmission/mid", PROPERTY_HINT_RANGE, "0.0,1.0,0.01"), "set_transmission_mid", "get_transmission_mid");

	ClassDB::bind_method(D_METHOD("set_transmission_high", "transmission_high"), &AudioMaterial::set_transmission_high);
	ClassDB::bind_method(D_METHOD("get_transmission_high"), &AudioMaterial::get_transmission_high);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "transmission/high", PROPERTY_HINT_RANGE, "0.0,1.0,0.01"), "set_transmission_high", "get_transmission_high");

	// Scattering
	ClassDB::bind_method(D_METHOD("set_scattering", "scattering"), &AudioMaterial::set_scattering);
	ClassDB::bind_method(D_METHOD("get_scattering"), &AudioMaterial::get_scattering);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "scattering", PROPERTY_HINT_RANGE, "0.0,1.0,0.01"), "set_scattering", "get_scattering");

	// Enum Constants
	BIND_ENUM_CONSTANT(PRESET_GENERIC);
	BIND_ENUM_CONSTANT(PRESET_BRICK);
	BIND_ENUM_CONSTANT(PRESET_CONCRETE);
	BIND_ENUM_CONSTANT(PRESET_CERAMIC);
	BIND_ENUM_CONSTANT(PRESET_GRAVEL);
	BIND_ENUM_CONSTANT(PRESET_CARPET);
	BIND_ENUM_CONSTANT(PRESET_GLASS);
	BIND_ENUM_CONSTANT(PRESET_PLASTER);
	BIND_ENUM_CONSTANT(PRESET_WOOD);
	BIND_ENUM_CONSTANT(PRESET_METAL);
	BIND_ENUM_CONSTANT(PRESET_ROCK);
	// BIND_ENUM_CONSTANT(PRESET_CUSTOM);
}

void AudioMaterial::set_preset(Preset p_preset) {
	preset = p_preset;

	switch (preset) {
		case PRESET_BRICK:
			absorption_low = 0.03f;
			absorption_mid = 0.04f;
			absorption_high = 0.07f;
			scattering = 0.05f;
			transmission_low = 0.015f;
			transmission_mid = 0.015f;
			transmission_high = 0.015f;
			break;
		case PRESET_CONCRETE:
			absorption_low = 0.05f;
			absorption_mid = 0.07f;
			absorption_high = 0.08f;
			scattering = 0.05f;
			transmission_low = 0.015f;
			transmission_mid = 0.002f;
			transmission_high = 0.001f;
			break;
		case PRESET_CERAMIC:
			absorption_low = 0.01f;
			absorption_mid = 0.02f;
			absorption_high = 0.02f;
			scattering = 0.05f;
			transmission_low = 0.060f;
			transmission_mid = 0.044f;
			transmission_high = 0.011f;
			break;
		case PRESET_GRAVEL:
			absorption_low = 0.60f;
			absorption_mid = 0.70f;
			absorption_high = 0.80f;
			scattering = 0.05f;
			transmission_low = 0.031f;
			transmission_mid = 0.012f;
			transmission_high = 0.008f;
			break;
		case PRESET_CARPET:
			absorption_low = 0.24f;
			absorption_mid = 0.69f;
			absorption_high = 0.73f;
			scattering = 0.05f;
			transmission_low = 0.020f;
			transmission_mid = 0.005f;
			transmission_high = 0.003f;
			break;
		case PRESET_GLASS:
			absorption_low = 0.06f;
			absorption_mid = 0.03f;
			absorption_high = 0.02f;
			scattering = 0.05f;
			transmission_low = 0.060f;
			transmission_mid = 0.044f;
			transmission_high = 0.011f;
			break;
		case PRESET_PLASTER:
			absorption_low = 0.12f;
			absorption_mid = 0.06f;
			absorption_high = 0.04f;
			scattering = 0.05f;
			transmission_low = 0.056f;
			transmission_mid = 0.056f;
			transmission_high = 0.004f;
			break;
		case PRESET_WOOD:
			absorption_low = 0.11f;
			absorption_mid = 0.07f;
			absorption_high = 0.06f;
			scattering = 0.05f;
			transmission_low = 0.070f;
			transmission_mid = 0.014f;
			transmission_high = 0.005f;
			break;
		case PRESET_METAL:
			absorption_low = 0.20f;
			absorption_mid = 0.07f;
			absorption_high = 0.06f;
			scattering = 0.05f;
			transmission_low = 0.200f;
			transmission_mid = 0.025f;
			transmission_high = 0.010f;
			break;
		case PRESET_ROCK:
			absorption_low = 0.13f;
			absorption_mid = 0.20f;
			absorption_high = 0.24f;
			scattering = 0.05f;
			transmission_low = 0.015f;
			transmission_mid = 0.002f;
			transmission_high = 0.001f;
			break;
		default:
			//generic preset
			absorption_low = 0.10f;
			absorption_mid = 0.20f;
			absorption_high = 0.30f;
			scattering = 0.05f;
			transmission_low = 0.100f;
			transmission_mid = 0.050f;
			transmission_high = 0.030f;
			break;
	}
	emit_changed();
}

AudioMaterial::Preset AudioMaterial::get_preset() const {
	return preset;
}

void AudioMaterial::set_absorption_low(real_t p_val) { absorption_low = p_val; preset = PRESET_CUSTOM; emit_changed(); }
void AudioMaterial::set_absorption_mid(real_t p_val) { absorption_mid = p_val; preset = PRESET_CUSTOM; emit_changed(); }
void AudioMaterial::set_absorption_high(real_t p_val) { absorption_high = p_val; preset = PRESET_CUSTOM; emit_changed(); }

void AudioMaterial::set_transmission_low(real_t p_val) { transmission_low = p_val; preset = PRESET_CUSTOM; emit_changed(); }
void AudioMaterial::set_transmission_mid(real_t p_val) { transmission_mid = p_val; preset = PRESET_CUSTOM; emit_changed(); }
void AudioMaterial::set_transmission_high(real_t p_val) { transmission_high = p_val; preset = PRESET_CUSTOM; emit_changed(); }

void AudioMaterial::set_scattering(real_t p_val) { scattering = p_val; preset = PRESET_CUSTOM; emit_changed(); }

AudioMaterial::AudioMaterial() {
	set_preset(PRESET_GENERIC);
}