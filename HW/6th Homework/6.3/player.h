#pragma once

using namespace std;

#include <iostream>
#include <vector>
#include "audio.h"
#include "video.h"

class Player
{
	vector<Audio*> Audiolist;
	vector<Video*> Videolist;

public:
	void add(Audio *aud)
	{
		Audiolist.push_back(aud);
	}

	void add(Video *vid)
	{
		Videolist.push_back(vid);
	}

	void play()
	{
		if (Audiolist.empty())
			cout << "audio: Nothing to play" << endl;

		else
		{
			for (Audio* i : Audiolist)
			{
				i->play();
			}
		}

		if (Videolist.empty())
			cout << "video: Nothing to play" << endl;

		else
		{
			for (Video* i : Videolist)
			{
				i->playVideo();
			}
		}
	}

	void pause()
	{
		if (Audiolist.empty())
			cout << "audio: Nothing to pause" << endl;

		else
		{
			for (Audio* i : Audiolist)
			{
				i->pause();
			}
		}

		if (Videolist.empty())
			cout << "video: Nothing to pause" << endl;

		else
		{
			for (Video* i : Videolist)
			{
				i->pauseVideo();
			}
		}
	}

	void doubleSpeed()
	{
		if (!Audiolist.empty())
		{
			for (Audio *i : Audiolist)
			{
				cout << "audio cannot be double speed" << endl;
			}
		}

		if (!Videolist.empty())
		{
			for (Video *i : Videolist)
				i->doubleSpeed();
		}
	}
};