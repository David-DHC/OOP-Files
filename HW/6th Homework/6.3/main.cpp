#include <bits/stdc++.h>
#include "player.h"
#include "mp3.h"
#include "wav.h"
#include "mp4.h"
#include "avi.h"

using namespace std;

int main()
{

	cout << "Create a player" << endl;
	Player* player = new Player();

	MP3* mp3 = new MP3();
	WAV* wav = new WAV();
	MP4* mp4 = new MP4();
	AVI* avi = new AVI();

	player->add(mp3);
	player->add(wav);
	player->add(mp4);
	player->add(avi);

	cout << "play all" << endl;
	player->play();

	cout << "pause all" << endl;
	player->pause();

	cout << "double speed" << endl;
	player->doubleSpeed();

	delete mp3;
	delete wav;
	delete mp4;
	delete avi;
	delete player;

	return 0;
}
