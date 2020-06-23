#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh2048()
	{
	static unsigned char dh2048_p[]={
		0xD7,0x54,0xF3,0x6E,0xEC,0x04,0x9C,0x08,0x75,0x9C,0xCA,0x7B,
		0xB2,0xF6,0x1D,0x9D,0xB5,0x6B,0x54,0x6B,0x1C,0x39,0xF2,0x6F,
		0x0C,0x1D,0x4B,0x5A,0x1F,0x52,0x98,0x4A,0x1A,0xD4,0x71,0x84,
		0x66,0xC4,0xA2,0x93,0xE3,0x5A,0xA0,0x99,0x07,0xBE,0x26,0x7F,
		0x6A,0xF0,0x43,0x13,0x1C,0x38,0xDB,0x51,0x37,0xA1,0xED,0xFC,
		0x7F,0x6B,0x44,0xE0,0xD4,0x00,0x49,0x89,0x6B,0x8F,0x26,0x5D,
		0x69,0x8F,0xEC,0xCB,0x24,0x46,0xFA,0xD9,0xED,0xDD,0xAA,0x04,
		0xA8,0xF4,0xC4,0x52,0xB3,0x7B,0x8E,0x6B,0xE3,0xA5,0x43,0xD2,
		0x23,0xC9,0x54,0xE8,0x96,0xE5,0xD6,0xFD,0x78,0x10,0xA2,0xBB,
		0xDA,0x8F,0x00,0x45,0x12,0xCB,0x99,0xF5,0x9E,0x75,0x45,0xAF,
		0x93,0xBC,0xB4,0x6B,0xBD,0xE1,0x83,0xAD,0xFC,0x6F,0xBD,0x5D,
		0xD2,0xC2,0xAF,0x4C,0xF5,0xBC,0x55,0xE8,0xF4,0xC4,0x68,0xA8,
		0xBA,0xEB,0x9D,0x8D,0xF6,0x79,0xEA,0xD1,0x25,0x2B,0xE3,0xC4,
		0xB5,0x56,0x29,0x6F,0xD5,0x52,0xF7,0x34,0xD3,0x38,0x55,0x60,
		0xE4,0x37,0x46,0xD6,0x60,0x1F,0xEC,0xF6,0x8E,0x37,0x89,0x98,
		0xD5,0x5D,0x80,0xD8,0xE8,0x87,0xA2,0x41,0x01,0x14,0x2E,0x55,
		0xB9,0xFA,0xD2,0x00,0x75,0x59,0xC5,0xAD,0xF3,0xFE,0x15,0x70,
		0x72,0xF5,0x70,0x19,0x71,0x8B,0x3E,0xA2,0xEB,0x16,0x2B,0xC8,
		0x1B,0xED,0x6C,0x71,0xD3,0xFD,0xF6,0x56,0xC0,0x85,0x38,0x30,
		0xAF,0x4B,0x1F,0x84,0x7A,0x31,0xB7,0x52,0x2F,0xFA,0x8B,0xF4,
		0x54,0x5F,0xCA,0xC0,0x1F,0x11,0x10,0x62,0xAC,0xA2,0x97,0x26,
		0xDA,0xCC,0x37,0xBB,
		};
	static unsigned char dh2048_g[]={
		0x02,
		};
	DH *dh;

	if ((dh=DH_new()) == NULL) return(NULL);
	dh->p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
	dh->g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
	if ((dh->p == NULL) || (dh->g == NULL))
		{ DH_free(dh); return(NULL); }
	return(dh);
	}
/*
-----BEGIN DH PARAMETERS-----
MIIBCAKCAQEA11TzbuwEnAh1nMp7svYdnbVrVGscOfJvDB1LWh9SmEoa1HGEZsSi
k+NaoJkHviZ/avBDExw421E3oe38f2tE4NQASYlrjyZdaY/syyRG+tnt3aoEqPTE
UrN7jmvjpUPSI8lU6Jbl1v14EKK72o8ARRLLmfWedUWvk7y0a73hg638b71d0sKv
TPW8Vej0xGiouuudjfZ56tElK+PEtVYpb9VS9zTTOFVg5DdG1mAf7PaON4mY1V2A
2OiHokEBFC5VufrSAHVZxa3z/hVwcvVwGXGLPqLrFivIG+1scdP99lbAhTgwr0sf
hHoxt1Iv+ov0VF/KwB8REGKsopcm2sw3uwIBAg==
-----END DH PARAMETERS-----
*/