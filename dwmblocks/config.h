static unsigned int delimLen = 5;
static char delim[] = " "; // NULL character ('\0') means no delimiter

static const Block blocks[] = {
	/*Icon*/  /*Command*/		/*Upd Interval*/	/*Upd Signal*/
	{"",      "sb-disk /home",	10,		        0		},
	{"",      "sb-volume",		0,		        10              },
	{"",      "sb-clock",	        5,		        0               },
};
