#include "AudioSystem.h"

AudioSystem::AudioSystem()
{

	std::vector<std::string> names = { "Shoot.ogg", "Hit.ogg"};

	for (int i = 0; i < names.size(); i++)
	{
		GameSoundBuffer temp;
		temp.name = names[i];
		temp.sbuffer.loadFromFile("Resources/Sounds/" + names[i]);

		sound_buffers.push_back(temp);
	}
}

void AudioSystem::StartSound()
{
	play_list.back().play();
}

void AudioSystem::Play_Sound(std::string s)
{
	sf::Sound test_sound;

	for (int i = 0; i < sound_buffers.size(); i++)
	{
		if (sound_buffers[i].name == s)
		{
			test_sound.setBuffer(sound_buffers[i].sbuffer);
			play_list.push_back(test_sound);
			StartSound();
		}
	}
}

void AudioSystem::CleanPlayList()
{
	std::list<sf::Sound>::iterator it;
	it = play_list.begin();

	for (it = play_list.begin(); it != play_list.end(); it++)
	{
		if ((*it).getStatus() == sf::SoundSource::Status::Stopped) 
		{
			it = play_list.erase(it);
			return;
		}
	}
}

void AudioSystem::PlayMusic(std::string s)
{
	music.openFromFile("Resources/Sounds/" + s);
	music.setLoop(true);
	music.setVolume(50.f);
	music.play();
}

void AudioSystem::StopMusic()
{
	music.stop();
}