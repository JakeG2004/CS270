#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>

struct wav_header
{
    char riff[4];
    int32_t flength;
    char wave[4];
    char fmt[4];
    int32_t chunk_size;
    int16_t format_tag;
    int16_t num_chains;
    int32_t srate;
    int32_t bytes_per_sec;
    int16_t bytes_per_samp;
    int16_t bits_per_samp;
    char data[4];
    int32_t dlength;
};

struct wav_header wavh;

const float MIDDLE_C = 256.0;