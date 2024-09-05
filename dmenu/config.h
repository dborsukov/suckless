/* Default settings; can be overriden by command line. */

static int topbar = 1;
static int fuzzy  = 1;
static unsigned int lines = 0;

static const char *fonts[] = {
	"Ubuntu Mono:size=14",
	"monospace:size=14"
};
static const char *prompt      = NULL;
static const char *colors[SchemeLast][2] = {
	/*			    fg         bg       */
	[SchemeNorm]		= { "#d4be98", "#282828" },
	[SchemeNormHighlight]	= { "#d8a657", "#282828" },
	[SchemeSel]		= { "#ddc7a1", "#333e34" },
	[SchemeSelHighlight]	= { "#d8a657", "#333e34" },
	[SchemeOut]		= { "#141617", "#a9b665" },
};

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
