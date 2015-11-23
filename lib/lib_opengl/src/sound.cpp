#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "SDL/SDL.h"

static Uint8	*sounddata;
static Uint32	soundlength;
static Uint32	soundpos;

void	mixaudio(void *userdata, Uint8 *stream, int len)
{
  Uint32	tocopy;

  (void)userdata;
  tocopy = (soundlength - soundpos > (unsigned int)len) ?
    (unsigned int)len : soundlength - soundpos;
  memcpy(stream, sounddata + soundpos, tocopy);
  soundpos += tocopy;
}

void	sound2(SDL_AudioCVT cvt)
{

  if (!(cvt.buf = (Uint8*)malloc(soundlength * cvt.len_mult)))
    return ;
  cvt.len = soundlength;
  memcpy(cvt.buf, sounddata, soundlength);
  if (SDL_ConvertAudio(&cvt) != 0)
    return ;
  SDL_FreeWAV(sounddata);
  if (!(sounddata = (Uint8*)malloc(cvt.len_cvt)))
    return ;
  memcpy(sounddata, cvt.buf, cvt.len_cvt);
  free(cvt.buf);
  soundlength = cvt.len_cvt;
  soundpos = 0;
  SDL_PauseAudio(0);
}

void		sound()
{
  SDL_AudioSpec	desired;
  SDL_AudioSpec	obtained;
  SDL_AudioSpec	soundfile;
  SDL_AudioCVT	cvt;

  desired.freq = 44100;
  desired.format = AUDIO_U16SYS;
  desired.channels = 1;
  desired.samples = 512;
  desired.callback = &mixaudio;
  desired.userdata = NULL;
  if (SDL_OpenAudio(&desired, &obtained) != 0)
    return ;
  if (SDL_LoadWAV("./ressources/excision.wav", &soundfile,
		  &sounddata, &soundlength) == NULL)
    return ;
  if (SDL_BuildAudioCVT(&cvt, soundfile.format, soundfile.channels,
			soundfile.freq, obtained.format,
			obtained.channels, obtained.freq) < 0)
    return ;
  sound2(cvt);
}
