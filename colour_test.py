from PIL import Image

array = [0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x8c0f,0x7bad,0x83ee,0xad33,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x9470,0x7b8c,0x6b0a,0x5aa9,0x62ea,0x7b8c,0xa4b1,0xd637,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x734b,0x5a88,0x5a88,0x5a88,0x5a88,0xd657,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb553,0x6b2b,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x8c2f,0xd678,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x5aa9,0x5a88,0x5a88,0x5a88,0x5a88,0xc5d5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x8c2f,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x83ee,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b0a,0x5a88,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0x83ce,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x7b8c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9c90,0x5a89,0x5a88,0x5a88,0x8c2f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xa4d2,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5aa9,0x9c91,0xbdb5,0xdeb9,0xce37,0xb574,0x83cd,0x5a88,0x5a88,0x734c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xde98,0xe6f9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xde98,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x6b2b,0xce16,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5f6,0x7bad,0x8c2f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0x9cb1,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce16,0xa4d1,0x7bad,0x6b2b,0x62ea,0x6b2b,0x7bad,0x944f,0xbd94,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xdeb9,0x9c90,0x83ee,0x734c,0x62ea,0x734c,0x8c0f,0xb554,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce16,0x9c91,0x8c0f,0x9470,0xad12,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0xa4f2,0x944f,0x7b8c,0x62ca,0x7b8c,0x944f,0xad12,0xce16,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0x6b0a,0x5a88,0x5a88,0x5a88,0x5a88,0x8c2f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5d5,0x7bad,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x7b6c,0xc5d5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4d1,0x5aa9,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9c90,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xa4d1,0xe6fa,0xe6fa,0xe6fa,],[0xde98,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xc5f6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x62ca,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad12,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5aa9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd657,0x7b8c,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x7b8c,0xe6fa,0xe6fa,],[0xc5d5,0x5a88,0x5a88,0x5a88,0x5a88,0x5aa9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xdeb9,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0x8bee,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xa4f2,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xad13,0xb574,0x9cb1,0x7b8d,0x5a88,0x5a89,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83ee,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0b,0x7b8d,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x9cb1,0xe6fa,],[0xb553,0x5a88,0x5a88,0x5a88,0x5a88,0x6b2b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b0b,0x62ca,0x9cb1,0xd657,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb574,0x5a88,0x5a88,0x5a88,0x5a88,0x8c2f,0xe6fa,0xe6fa,0xe6fa,0xcdf6,0x5a88,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd657,0x9c90,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbd94,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0a,0xce16,0xe6fa,0xe6fa,0xe6fa,0xa4f2,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xd657,],[0xa4d2,0x5a88,0x5a88,0x5a88,0x5a88,0x7b8d,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd698,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x7bad,0x5a88,0x5a88,0x5a88,0x7bad,0xe6fa,0xe6fa,0xe6fa,0xbd74,0x5a88,0x5a88,0x5a88,0x5a88,0xdeb8,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b2b,0x5a88,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9c90,0x5a88,0x5a88,0x5a88,0x5a88,0x9c90,],[0x9470,0x5a88,0x5a88,0x5a88,0x5a88,0x83ce,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x8c2f,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xce16,0x5a88,0x5a88,0x5a88,0x5a88,0x7b8d,0xc5d5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xdeb9,0x5a88,0x5a88,0x5a88,0x5a88,0x83cd,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd677,0x5a88,0x5a88,0x5a88,0x5a88,0x8bee,],[0xad12,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd677,0xc5f6,0xbd94,0xad12,0x9cb1,0x6b2b,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x6b0a,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xad33,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xce16,0x5a88,0x5a88,0x5a88,0x5a88,0xa4d1,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b2b,0x5a88,0x5a88,0x5a88,0x736c,],[0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0x62ea,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce37,0x9cb1,0x6b0b,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0b,0xb553,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xbd94,0x5a88,0x5a88,0x5a88,0x5a88,0xb553,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x736c,0x5a88,0x5a88,0x5a88,0x62ca,],[0xd677,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb574,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5f6,0x734b,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x83ce,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xad12,0x5a88,0x5a88,0x5a88,0x5a88,0xbd74,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x7b8c,0x5a88,0x5a88,0x5a88,0x62ca,],[0xe6fa,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad33,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb574,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x7b8d,0x9470,0xad12,0xad33,0x6b0b,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad12,0x736c,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xb553,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0xa4f2,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b0a,0x5a88,0x5a88,0x5a88,0x734c,],[0xe6fa,0x6b2b,0x5a88,0x5a88,0x5a88,0x5a88,0x6b2b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x8c2f,0x5a88,0x5a88,0x5a88,0x5a88,0xbdb5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83cd,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5d5,0x83ee,0x5a88,0x5a88,0x5a88,0x5a88,0x83cd,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xce37,0x5a88,0x5a88,0x5a88,0x5a88,0x9470,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6f9,0x5a88,0x5a88,0x5a88,0x5a88,0x83ee,],[0xe6fa,0xb553,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x9cb1,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5d5,0x9470,0xe6fa,0xe6fa,0x734b,0x5a88,0x5a88,0x5a88,0x8bee,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83ee,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x7b8c,0x5a88,0x5a88,0x5a88,0x62ea,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x5a88,0x5a88,0x5a88,0x5a88,0x62ca,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad13,0x5a88,0x5a88,0x5a88,0x5a88,0x9c90,],[0xe6fa,0xe6fa,0x7b8c,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x83ee,0xd678,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5d5,0x83ee,0x5a88,0x6b0b,0xe6fa,0xe6fa,0x6b0b,0x5a88,0x5a88,0x5a88,0x7bad,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd678,0x736c,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xd678,0xc5f6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x8c2f,0x5a88,0x5a88,0x5a88,0x734b,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x7b8c,0x5a88,0x5a88,0x5a88,0x5a88,0xa4d1,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce57,0x6b2b,0x5a88,0x5a88,0x5a88,0x5a88,0xce16,],[0xe6fa,0xe6fa,0xc5d5,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x62ca,0x7bad,0x736c,0x62ea,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0x8c0f,0x5a88,0x5a88,0x5a88,0x5a88,0xb553,0xe6d9,0xe6d9,0xbdb5,0x62ea,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xa4d1,0x5a88,0x8bee,0xbd94,0xe6d9,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0x8c2f,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5d5,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x9450,0xb553,0xbdb5,0x9cb1,0x62ca,0x5a88,0x5a88,0x5a88,0x5a88,0x9470,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0x9470,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xe6fa,0xe6fa,0xad33,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xa4f2,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xbd94,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x8c2f,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x62ca,0xe6d9,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbd94,0x6b0a,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad12,0xe6fa,0xe6fa,0xe6fa,0x83cd,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x83cd,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xb574,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad12,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9450,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x83ce,0xd677,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6b9,0x8c2f,0x6aea,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x732b,0x9cb1,0xd677,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xde98,0x9470,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x62a9,0xad12,0xe6fa,0x6b0b,0x5a88,0x5a88,0x6b0a,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4d1,0x734c,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x7bad,0xbdb5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9470,0x5a88,0x5a88,0x5a88,0x6b0a,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb574,0x62ca,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x6b2b,0xad12,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd657,0xc5d5,0xb553,0xb553,0xc5d5,0xd678,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd678,0xc5f6,0xbd94,0xbdb5,0xd678,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xde98,0xdeb9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd678,0xbdb5,0xb574,0xbd94,0xc5f6,0xd657,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd678,0xe6d9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0xce37,0xbd94,0xbd94,0xd657,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xde98,0xad33,0x8c0f,0x734b,0x62ca,0x5aa9,0x734c,0x8c0e,0xa4d1,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd678,0xa4f2,0x7b8c,0x6b0a,0x5a88,0x62ea,0x736c,0x9c91,0xce16,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5f6,0x944f,0x83ce,0x83ce,0x83ce,0x83ee,0xad12,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x9450,0x7bad,0x6b0b,0x5a88,0x6aea,0x736c,0x83ee,0xbd94,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x8c2f,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0a,0xb553,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4f2,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xb553,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x734b,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xce16,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x7b8d,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x7bad,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83cd,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xc5d5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad12,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad12,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xacf2,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xce16,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce37,0x5a89,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x7bad,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x62ea,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x734b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd677,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xc5d5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xdeb9,0x62c9,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xce16,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x736c,0x5a88,0x5a88,0x5a88,0x5a88,0x6b0b,0x944f,0x9c90,0x83cd,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xa4f2,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x62ea,0x5a88,0x5a88,0x7bad,0x9cb1,0xb553,0x9cb1,0x734c,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xce16,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4d1,0x5a88,0x5a88,0x5a88,0x5a88,0x9470,0xde98,0xe6fa,0xe6d9,0x9470,0x5a88,0x5a88,0x5a88,0x5a88,0x944f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9470,0x5a88,0x5a88,0x5a88,0x62c9,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd657,0x5a88,0x5a88,0x5a88,0x5a88,0x8c0f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb533,0x5a88,0x5a88,0x5a88,0x5a88,0x8c0e,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x736c,0x83cd,0xb574,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x7bad,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad33,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b2b,0x5a88,0x5a88,0x5a88,0x7b8c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b0b,0x5a88,0x5a88,0x5a88,0x5aa9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce37,0x5a88,0x5a88,0x5a88,0x5a88,0x83ee,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb574,0x5a88,0x5a88,0x5a88,0x5a88,0xc5f5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b2b,0x5a88,0x5a88,0x5a88,0x6b2b,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb574,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x9cb1,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0xad33,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9470,0x5a88,0x5a88,0x5a88,0x5a88,0xb574,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83ee,0x5a88,0x5a88,0x5a88,0x9450,0x83ee,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4d2,0x5a88,0x5a88,0x5a88,0x5a88,0xce16,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x736c,0x5a88,0x5a88,0x5a88,0x736c,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5d5,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad33,0xe6fa,0xe6fa,0xe6fa,0x9470,0x5a88,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbd94,0x5a88,0x5a88,0x5a88,0x5a88,0x9c90,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0x83ee,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5b5,0x5a88,0x5a88,0x5a88,0x5a88,0x9470,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce37,0x5a88,0x5a88,0x5a88,0x5a88,0x9c90,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad12,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xbdb5,0xe6fa,0xe6fa,0xe6fa,0x83ee,0x5a88,0x5a88,0x5a88,0x62c9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce16,0x5a88,0x5a88,0x5a88,0x5a88,0x9450,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x736c,0x5a88,0x5a88,0x5a88,0xb574,0xe6fa,0x8c0e,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x62c9,0x5a88,0x5a88,0x5a88,0x5a88,0xa4d2,0xe6fa,0xe6fa,0xe6d9,0x83ee,0x5a88,0x5a88,0x5a88,0x5a89,0xde98,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83cd,0x5a88,0x5a88,0x5a88,0x5a88,0x734b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x7b8c,0x5a88,0x5a88,0x5a88,0x62ea,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xde98,0x5a88,0x5a88,0x5a88,0x5a88,0x8c0f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad12,0x5a88,0x5a88,0x5a88,0x62ca,0xe6fa,0xe6fa,0x8c2f,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4d1,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x83ce,0xbdb5,0x6b0b,0x5a88,0x5a88,0x5a88,0x5a88,0xb554,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce37,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad12,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b0b,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x5a88,0x5a88,0x5a88,0x5a88,0x83ee,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x62ea,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9470,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad33,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83cd,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x5aa9,0x5a88,0x5a88,0x5a88,0x734b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x5a88,0x5a88,0x5a88,0x5a88,0x7bad,0xe6fa,0xe6fa,0xe6fa,0x9c91,0x5a88,0x5a88,0x5a88,0x83ee,0xe6fa,0xe6fa,0xe6fa,0x9450,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb553,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xbdb5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4f2,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xc5d5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x5a88,0x5a88,0x5a88,0x5a88,0x734c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x5a89,0x5a88,0x5a88,0x5a88,0x7bad,0xe6fa,0xe6fa,0xd657,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9470,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad12,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad33,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbd94,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x9c90,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x5aa9,0x5a88,0x5a88,0x5a88,0x734c,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0x5a88,0x5a88,0x5a88,0x5a88,0x8c0e,0xe6fa,0xe6fa,0x8c0f,0x5a88,0x5a88,0x5a88,0x9cb1,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9c90,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x8c0f,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x9c90,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xcdf6,0x5a89,0x5a88,0x5a88,0x5a88,0x5a88,0x8c2f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x6b0a,0x5a88,0x5a88,0x5a88,0x732b,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xdeb8,0x5a88,0x5a88,0x5a88,0x5a88,0x9450,0xe6fa,0xc5d5,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9cb1,0x5a88,0x5a88,0x5a88,0x5a88,0xcdf6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x9450,0x5a88,0x5a88,0x5a88,0x5a88,0x7bad,0xce37,0xce37,0x83ee,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xa4d1,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce37,0x62ea,0x5a88,0x5a88,0x5a88,0x5a88,0x83ee,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x734c,0x5a88,0x5a88,0x5a88,0x6aea,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce37,0x5a88,0x5a88,0x5a88,0x5a88,0x9cb1,0xe6fa,0xad12,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5aa9,0x62a9,0x62ca,0x62ea,0x6aea,0x5a88,0x5a88,0x5a88,0x5a88,0x6b2b,0x734c,0x9470,0xe6fa,0xe6fa,0xb574,0x5a88,0x5a88,0x5a88,0x5a88,0x8c2f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad12,0x5a88,0x5a88,0x5a88,0x5a88,0x5aa9,0xde98,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd657,0x6b0b,0x5a88,0x5a88,0x5a88,0x5a88,0x7bad,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x7bad,0x5a88,0x5a88,0x5a88,0x5a88,0xe6d9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0xacf2,0xe6fa,0x9cb1,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x62c9,0xe6fa,0xe6fa,0x6b0b,0x5a88,0x5a88,0x5a88,0x5aa9,0xde98,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0xb574,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xde98,0x734b,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xe6d9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x8c2f,0x5a88,0x5a88,0x5a88,0x5a88,0xc5d5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4d1,0x5a88,0x5a88,0x5a88,0x5a88,0xbdb5,0xe6fa,0xa4f2,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xe6fa,0xe6f9,0x5a88,0x5a88,0x5a88,0x5a88,0x83ce,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0x9c91,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xdeb9,0x736c,0x5a88,0x5a88,0x5a88,0x5a88,0x62ca,0xde98,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbd94,0x5a88,0x5a88,0x5a88,0x5a88,0xa4d2,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83cd,0x5a88,0x5a88,0x5a88,0x6b0b,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x736c,0xe6fa,0xde98,0x5a88,0x5a88,0x5a88,0x5a88,0x83ad,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xbdb5,0x5a88,0x5a88,0x5a88,0x5a88,0xad13,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83ce,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xd657,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x5aa9,0x5a88,0x5a88,0x5a88,0x62c9,0xd657,0xe6fa,0xe6fa,0xe6fa,0xb553,0x5a88,0x5a88,0x5a88,0x5a88,0x9cb1,0xe6fa,0xe6fa,0xe6fa,0xde98,0xde98,0xde98,0xde98,0xde98,0xde98,0xde98,0xde98,0xde98,0x9c90,0x5a88,0x5a88,0x5a88,0x5a88,0xbdb5,0xd678,0xe6fa,0xe6fa,0xe6fa,0x62ea,0x5a88,0x5a88,0x5a88,0x62ca,0xde98,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x8c2f,0x5a88,0x5a88,0x5a88,0x5a88,0xc5d5,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5d5,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a89,0x62c9,0x62ea,0x6b2b,0x6b2b,0xce37,0xe6fa,0xe6fa,0xe6fa,0x8c0f,0x5a88,0x5a88,0x5a88,0x5a88,0x734c,0x9c90,0xad33,0x944f,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xce57,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4b1,0x5a88,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0x83cd,0x5a88,0x5a88,0x5a88,0x5a88,0x732b,0xa4f2,0xc5f6,0xd657,0xbd94,0x8c0f,0x5a88,0x5a88,0x5a88,0x5a88,0x5aa9,0xdeb9,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xad33,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad33,0xe6fa,0xe6fa,0xe6fa,0xce16,0x62ea,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x9470,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4d1,0x5a88,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xc5d5,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xbd94,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb574,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xad33,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce57,0x6b2b,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x944f,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4f2,0x5a88,0x5a88,0x5a88,0x5a88,0xce37,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xa4f2,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xa4f2,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd678,0x6b0b,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0xbdb5,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd678,0x7bad,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x7b8c,0xbd94,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xb553,0x5a88,0x5a88,0x5a88,0x5a89,0xd657,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xce16,0x9450,0x5a89,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x5a88,0x9450,0xd678,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,],[0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xd677,0xbdb5,0xb574,0xb553,0xbd94,0xc5f6,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6d9,0xdeb9,0xdeb9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6f9,0xd678,0xc5f6,0xbd74,0xb574,0xc5f6,0xd677,0xe6d9,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa,0xe6fa]

width = len(array[0])
height = len(array)

# width, height
im = Image.new("RGB", (width, height))

# Loop over all the pixels and set them
for x in range(width):
    for y in range(height):
        value = array[y][x]
        # Decode colour in 16 bit RGB565 format
        # https://stackoverflow.com/questions/61816430/how-can-i-use-python-to-convert-rgb565-byte-array-to-rgb888-byte-array

        MASK5 = 0b011111
        MASK6 = 0b111111

        b = (value & MASK5) << 3
        g = ((value >> 5) & MASK6) << 2
        r = ((value >> (5 + 6)) & MASK5) << 3

        im.putpixel((x, y), (r, g, b))

# Save
im.save("colour_test.png")

def RGBto565(red, green, blue):
    # https://gist.github.com/ajfisher/2834170
    print("0x%0.4X" % ((int(red / 255 * 31) << 11) | (int(green / 255 * 63) << 5) | (int(blue / 255 * 31))))

# Print in hex format, padded to 4 digits
RGBto565(0, 255, 0)