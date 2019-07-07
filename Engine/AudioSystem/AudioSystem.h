#pragma once

#include "../Header.h"

class AudioSystem
{
public:
	static AudioSystem& Instance()
	{
		static AudioSystem* instance_ = new AudioSystem();
		return *instance_;
	}

	void Play_Sound(std::string s);
	void PlayMusic(std::string s);
	void StopMusic();

private:
	AudioSystem() {};

	sf::SoundBuffer sound_buffer;
	sf::Music music;
	sf::Sound sound;
};