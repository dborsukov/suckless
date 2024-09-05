static unsigned int delimLen = 5;
static char delim[] = " "; // NULL character ('\0') means no delimiter

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",            "volume",		0,		        10                       },
	{"",            "date +%Y-%m-%d",	60,		        0                        },
	{"",            "date +%H:%M",		10,		        0                        },
};
