#ifndef AUDIO_MATERIAL_H
#define AUDIO_MATERIAL_H

#include "core/io/resource.h"

class AudioMaterial : public Resource {
	GDCLASS(AudioMaterial, Resource);
	OBJ_SAVE_TYPE(AudioMaterial);
	RES_BASE_EXTENSION("audiomat");

private:
    Preset preset;

    real_t absorption_low;
	real_t absorption_mid;
	real_t absorption_high;
	real_t transmission_low;
	real_t transmission_mid;
	real_t transmission_high;
	real_t scattering;

protected:
	static void _bind_methods();

public:
    enum Preset {
        PRESET_GENERIC,
        PRESET_BRICK,
        PRESET_CONCRETE,
        PRESET_CERAMIC,
        PRESET_GRAVEL,
		PRESET_CARPET,
		PRESET_GLASS,
        PRESET_PLASTER,
        PRESET_WOOD,
        PRESET_METAL,
        PRESET_ROCK,
		// PRESET_CUSTOM
    };

    void set_preset(Preset p_preset);
    Preset get_preset() const;

	void set_absorption_low(real_t p_val);
	_FORCE_INLINE_ real_t get_absorption_low() const { return absorption_low; }

	void set_absorption_mid(real_t p_val);
	_FORCE_INLINE_ real_t get_absorption_mid() const { return absorption_mid; }

	void set_absorption_high(real_t p_val);
	_FORCE_INLINE_ real_t get_absorption_high() const { return absorption_high; }

	void set_transmission_low(real_t p_val);
	_FORCE_INLINE_ real_t get_transmission_low() const { return transmission_low; }

	void set_transmission_mid(real_t p_val);
	_FORCE_INLINE_ real_t get_transmission_mid() const { return transmission_mid; }

	void set_transmission_high(real_t p_val);
	_FORCE_INLINE_ real_t get_transmission_high() const { return transmission_high; }

	void set_scattering(real_t p_val);
	_FORCE_INLINE_ real_t get_scattering() const { return scattering; }

	VARIANT_ENUM_CAST(AudioMaterial::Preset);
};

#endif