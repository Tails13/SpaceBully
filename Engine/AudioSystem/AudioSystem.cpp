#include "AudioSystem.h"

void AudioSystem::Play_Sound(std::string s)
{
	sound_buffer.loadFromFile("Resources/Sounds/" + s);
	sound.setBuffer(sound_buffer);
	sound.play();
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