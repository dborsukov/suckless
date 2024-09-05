/* See LICENSE file for copyright and license details. */

/* settings */
static const int topbar                  = 1;
static const int showbar                 = 1;
static const int focusonwheel            = 1;
static const unsigned int snap           = 32;
static const unsigned int borderpx       = 1;
static const int showsystray             = 1;
static const unsigned int systrayonleft  = 0;
static const unsigned int systrayspacing = 2;
static const unsigned int systraypinning = 0;
static const int systraypinningfailfirst = 1;

/* appearance */
static const char *fonts[]               = { "Ubuntu Mono:size=14", "monospace:size=14" };
static const char normbgcolor[]          = "#282828";
static const char normbordercolor[]      = "#282828";
static const char normfgcolor[]          = "#ddc7a1";
static const char selfgcolor[]           = "#ddc7a1";
static const char selbordercolor[]       = "#89b482";
static const char selbgcolor[]           = "#333e34";
static const char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact        = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },              /* Default: Master left, slaves right */
	{ "TTT",      bstack },            /* Master top, slaves bottom */

	{ "[M]",      monocle },           /* All windows on top of each other */
	{ "[D]",      deck },              /* Master left, with monocle stack on the right */

	{ "[@]",      spiral },            /* Fibonacci spiral */
	{ "[\\]",     dwindle },           /* Binary space partitioning(sort of) */

	{ "><>",      NULL },              /* No layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const Key keys[] = {
	/* modifier                     key        function        argument                      */
	// spawn
	{ MODKEY,                       XK_Return, spawn,	   SHCMD("wezterm")              },
	{ MODKEY,                       XK_p,      spawn,          SHCMD("rofi -show drun")      },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("rofi -show run")       },
	// wm
	{ MODKEY,                       XK_b,      togglebar,      {0}                           },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 }                    },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 }                    },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 }                    },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 }                    },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = +1 }                    },
	{ MODKEY|ShiftMask,             XK_o,      incnmaster,     {.i = -1 }                    },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05}                  },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05}                  },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0}                           },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0}                           },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} /* tile  */},
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[1]} /* bstack*/},
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} /* mono  */},
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[3]} /* deck  */},
	{ MODKEY,                       XK_s,      setlayout,      {.v = &layouts[4]} /* spiral*/},
	{ MODKEY|ShiftMask,             XK_s,      setlayout,      {.v = &layouts[5]} /* dwindl*/},
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[6]} /* float */},
	{ MODKEY,                       XK_f,      togglefullscr,  {0}                           },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 }                    },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 }                    },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 }                    },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 }                    },
	TAGKEYS(                        XK_1,                      0                             )
	TAGKEYS(                        XK_2,                      1                             )
	TAGKEYS(                        XK_3,                      2                             )
	TAGKEYS(                        XK_4,                      3                             )
	TAGKEYS(                        XK_5,                      4                             )
	TAGKEYS(                        XK_6,                      5                             )
	TAGKEYS(                        XK_7,                      6                             )
	TAGKEYS(                        XK_8,                      7                             )
	TAGKEYS(                        XK_9,                      8                             )
	{ MODKEY|ShiftMask,             XK_Escape, quit,           {0}                           },
	// sound
	{ MODKEY,                       XK_minus,       spawn,     SHCMD("wpctl set-volume -l 1 @DEFAULT_AUDIO_SINK@ 1%-; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,             XK_minus,       spawn,     SHCMD("wpctl set-volume -l 1 @DEFAULT_AUDIO_SINK@ 5%-; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,                       XK_equal,       spawn,     SHCMD("wpctl set-volume -l 1 @DEFAULT_AUDIO_SINK@ 1%+; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,             XK_equal,       spawn,     SHCMD("wpctl set-volume -l 1 @DEFAULT_AUDIO_SINK@ 5%+; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,                       XK_BackSpace,   spawn,     SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)")     },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument         */
	{ ClkTagBar,            0,              Button1,        view,           {0}              },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0}              },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0}              },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0}              },
};

