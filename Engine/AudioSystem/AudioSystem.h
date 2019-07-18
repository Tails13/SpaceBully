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
	void CleanPlayList();

private:
	AudioSystem();
	void StartSound();

	struct GameSoundBuffer
	{
		std::string name;
		sf::SoundBuffer sbuffer;

		GameSoundBuffer& operator=(const GameSoundBuffer& other)
		{
			this->name = other.name;
			this->sbuffer = other.sbuffer;	
			return *this;
		}
	};

	sf::SoundBuffer sound_buffer;
	sf::Music music;

	std::vector<GameSoundBuffer> sound_buffers;
	std::list<sf::Sound> play_list;
};