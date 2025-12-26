/* akai's custom config */
#define EUDAIMONIA "~/eudaimonia"
#define HOME "/home/akai"

/* APPEARANCE */

// window & bar settings
static const unsigned char borderpx = 4;   // border pixel of windows
static const unsigned char snap     = 32;  // snap pixel
static const bool showbar           = true;
static const bool topbar            = false;

// fonts
#define MAIN_FONT "FiraCode Nerd Font Ret:size=10"
#define JAP_FONT  "Noto Sans CJK JP Medium:size=10" // japanese workspace characters

static const char *fonts[] = {
	MAIN_FONT,
	JAP_FONT
};

static const char dmenufont[] = MAIN_FONT;

// color scheme
static const char col_gray1[] = "#0d0d14";
static const char col_gray2[] = "#52263e";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[]  = "#ac3232";  // focused color

static const char *colors[][3] = {
	//               fg         bg         border
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeHid]  = { col_gray4, col_gray2, col_cyan  },
};

// transparency (alpha patch)
#define OPAQUE 0xffU
static const unsigned int baralpha    = 0xb0;    // bar background alpha
static const unsigned int borderalpha = OPAQUE;  // border alpha

static const unsigned int alphas[][3] = {
	// fg          bg        border
	{ borderalpha, baralpha, OPAQUE }
};

/* WORKSPACES */

static const char *tags[] = {"贖", "罪", "へ", "の", "途", "上"};

/* WINDOW RULES */

static const Rule rules[] = {
	// class        instance  title  tags mask  isfloating  monitor

	// workspace 1: browsers
	{ "firefox",     NULL, NULL, 1 << 0, 0, -1 },
	{ "firefox-bin", NULL, NULL, 1 << 0, 0, -1 },
	{ "zen",         NULL, NULL, 1 << 0, 0, -1 },
	{ "zen-browser", NULL, NULL, 1 << 0, 0, -1 },
	{ "vivaldi",     NULL, NULL, 1 << 0, 0, -1 },
	{ "vivaldi-bin", NULL, NULL, 1 << 0, 0, -1 },

	// workspace 2: communication
	{ "discord",  NULL, NULL, 1 << 1, 0, -1 },
	{ "vesktop",  NULL, NULL, 1 << 1, 0, -1 },
	{ "equibop",  NULL, NULL, 1 << 1, 0, -1 },
	{ "electron", NULL, NULL, 1 << 1, 0, -1 },

	// workspace 3: music
	{ "youtube-music",                  NULL,                             NULL, 1 << 2, 0, -1 },
	{ NULL,                             "youtube-music",                  NULL, 1 << 2, 0, -1 },
	{ "com.github.th_ch.youtube_music", NULL,                             NULL, 1 << 2, 0, -1 },
	{ NULL,                             "com.github.th_ch.youtube_music", NULL, 1 << 2, 0, -1 },

	// workspace 4: games
	{ "osu!",          NULL, NULL, 1 << 3, 0, -1 },
	{ "DDNet",         NULL, NULL, 1 << 3, 0, -1 },
	{ "java",          NULL, NULL, 1 << 3, 0, -1 },
	{ "Hollow Knight", NULL, NULL, 1 << 3, 0, -1 },

	// workspace 5: development
	{ "emacs", NULL, NULL, 1 << 4, 0, -1 },
	{ "Emacs", NULL, NULL, 1 << 4, 0, -1 },

	// workspace 6: utilities
	{ "Prismlauncher",       NULL,     NULL, 1 << 5, 0, -1 },
	{ "corectrl",            NULL,     NULL, 1 << 5, 0, -1 },
	{ "qbittorrent",         NULL,     NULL, 1 << 5, 0, -1 },
	{ "Deluge",              NULL,     NULL, 1 << 5, 0, -1 },
	{ NULL,                  "deluge", NULL, 1 << 5, 0, -1 },
	{ "PrismLauncher",       NULL,     NULL, 1 << 5, 0, -1 },
	{ "OpenTabletDriver.UX", NULL,     NULL, 1 << 5, 0, -1 },
};

/* LAYOUTS */

static const float mfact        = 0.5;  // factor of master area size [0.05..0.95]
static const char nmaster        = 1;    // number of clients in master area
static const bool resizehints    = true;    // respect size hints in tiled resizals
static const bool lockfullscreen = false;    // force focus on fullscreen window

static const Layout layouts[] = {
	// symbol  arrange function
	{ "[]=",   tile    },  // default
	{ "><>",   NULL    },  // floating
	{ "[M]",   monocle },  // monocle
};

/* APPLICATIONS */

// system
#define SHELL     "sh"
#define TERMINAL  "ghostty"
// preloader
// #define RUNTIME "distrobox-enter artix-dinit -- " // old distrobox setup
#define RUNTIME "flatpak run " // simpler flatpaks

// programs
#define BROWSER      "firefox"
#define DISCORD      "org.equicord.equibop"
#define DISCORD_PATH "equibop"
#define MUSIC        "com.github.th_ch.youtube_music"
#define MUSIC_PATH   "youtube-music"
#define TORRENT      "deluge"

// games
#define GAME_Z      "osu-lazer"
#define GAME_Z_PATH "/home/akai/eudaimonia/scripts/osu.sh"
#define GAME_X      "DDNet"
#define GAME_X_PATH HOME       "/Games/t-client/DDNet"
#define GAME_C      "prismlauncher"
#define GAME_C_PATH "prismlauncher"

//#define GAME_C      "Hollow\\ Knight"
//#define GAME_C_PATH HOME "/Games/Hollow_Knight/start.sh"

/* HELPER MACROS */

// spawn shell commands
#define SHCMD(cmd) { .v = (const char *[]) {SHELL, "-c", cmd, NULL} }

// quickly pkill any program
#define PKILLCMD(app) SHCMD("pkill " app)
#define PKILLFIREFOX SHCMD("pkill firefox && ~/.local/bin/firefox-sync.sh xpmraevm.default-default")

// workspace key bindings
#define TAGKEYS(KEY, TAG) \
{ MODKEY,                           KEY, view,       {.ui = 1 << TAG} }, \
{ MODKEY | ControlMask,             KEY, toggleview, {.ui = 1 << TAG} }, \
{ MODKEY | ShiftMask,               KEY, tag,        {.ui = 1 << TAG} }, \
{ MODKEY | ControlMask | ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

/* DMENU */

static char dmenumon[1] = "0";  // monitor number

static const char *dmenucmd[] = {
	"dmenu_run",  // dmenu executable
	"-b",         // bottom bar
	"-m",         // monitor flag
	dmenumon,     // monitor number
	"-fn",        // font flag
	dmenufont,    // font string
	"-nb",        // normal background flag
	col_gray1,    // normal background color
	"-nf",        // normal foreground flag
	col_gray3,    // normal foreground color
	"-sb",        // selected background flag
	col_cyan,     // selected background color
	"-sf",        // selected foreground flag
	col_gray4,    // selected foreground color
	NULL          // terminator
};

/* KEYBINDINGS */

#define MODKEY Mod4Mask  // Mod3Mask = Alt; Mod4Mask = Super

// program pointers
static const char *browsercmd[] = { SHELL, "-c", "MOZ_USE_XINPUT2=1 " BROWSER, NULL };  // native xinput touchpad
static const char *termcmd[]    = { TERMINAL, NULL };
static const char *discordcmd[] = { SHELL, "-c", RUNTIME DISCORD,  NULL };
static const char *musiccmd[]   = { SHELL, "-c", RUNTIME MUSIC,    NULL };
static const char *torrentcmd[] = { TORRENT,  NULL };
static const char *gamezcmd[]   = { GAME_Z_PATH, NULL };
static const char *gamexcmd[]   = { GAME_X_PATH, NULL };
static const char *gameccmd[]   = { GAME_C_PATH, NULL };

static const Key keys[] = {
	/* WORKSPACES */

	TAGKEYS(XK_1, 0) // 贖
	TAGKEYS(XK_2, 1) // 罪
	TAGKEYS(XK_3, 2) // へ
	TAGKEYS(XK_q, 3) // の
	TAGKEYS(XK_w, 4) // 途
	TAGKEYS(XK_e, 5) // 上

	/* WINDOW MANAGER */

  //{ MODKEY | ShiftMask, XK_Return, quit,          {0} },  // quit dwm (GNU-style)
	{ MODKEY | ShiftMask, XK_Return, spawn,         SHCMD("pkill -9 Xorg") }, // quit dwm, BSD-utils style
	{ MODKEY,             XK_n,      togglebar,     {0} },
	//{ MODKEY,           XK_Tab,    view,          {0} }, // previous workspace
	{ MODKEY,             XK_Tab,    zoom,          {0} }, // swap with master
	{ MODKEY | ShiftMask, XK_Tab,    spawn,         {.v = dmenucmd} },

	// window control
	{ MODKEY,             XK_f,      togglefullscr, {0} },
	{ MODKEY | ShiftMask, XK_f,      killclient,    {0} },

	// focus & stack navigation
	{ MODKEY,             XK_j,      focusstackvis, {.i = +1} },  // next visible
	{ MODKEY,             XK_k,      focusstackvis, {.i = -1} },  // prev visible
	{ MODKEY | ShiftMask, XK_j,      focusstackhid, {.i = +1} },  // next hidden
	{ MODKEY | ShiftMask, XK_k,      focusstackhid, {.i = -1} },  // prev hidden

	// layout manipulation
	{ MODKEY,             XK_h,      setmfact,       {.f = -0.05} },  // shrink master
	{ MODKEY,             XK_l,      setmfact,       {.f = +0.05} },  // grow master
	{ MODKEY,             XK_u,      incnmaster,     {.i = +1} },     // more masters
	{ MODKEY,             XK_i,      incnmaster,     {.i = -1} },     // fewer masters
	{ MODKEY,             XK_space,  setlayout,      {0} },           // cycle layout
	{ MODKEY | ShiftMask, XK_space,  togglefloating, {0} },

	// awesomebar patch
	{ MODKEY,             XK_r,      hide,           {0} },
	{ MODKEY,             XK_t,      showall,        {0} },

	// togglewin patch
	{ MODKEY,             XK_m,      togglewin,      {0} },

	// multi-monitor
	{ MODKEY,             XK_4,      view,           {.ui = ~0} },  // view all tags
	{ MODKEY | ShiftMask, XK_4,      tag,            {.ui = ~0} },  // tag all
	{ MODKEY,             XK_comma,  focusmon,       {.i = -1} },
	{ MODKEY,             XK_period, focusmon,       {.i = +1} },
	{ MODKEY | ShiftMask, XK_comma,  tagmon,         {.i = -1} },
	{ MODKEY | ShiftMask, XK_period, tagmon,         {.i = +1} },

	/* APPLICATIONS */

	{ MODKEY,             XK_d, spawn, {.v = termcmd}       },
	{ MODKEY | ShiftMask, XK_d, spawn, PKILLCMD(TERMINAL) },

	{ MODKEY,             XK_a, spawn, {.v = browsercmd}   },
	{ MODKEY | ShiftMask, XK_a, spawn, PKILLFIREFOX },

	{ MODKEY,             XK_s, spawn, {.v = discordcmd}   },
	{ MODKEY | ShiftMask, XK_s, spawn, PKILLCMD(DISCORD_PATH) },

	{ MODKEY,             XK_b, spawn, {.v = torrentcmd}   },
	{ MODKEY | ShiftMask, XK_b, spawn, PKILLCMD(TORRENT) },

	{ MODKEY,             XK_v, spawn, {.v = musiccmd}   },
	{ MODKEY | ShiftMask, XK_v, spawn, PKILLCMD(MUSIC_PATH) },

	// games
	{ MODKEY,             XK_z, spawn, {.v = gamezcmd}    },  // osu!
	{ MODKEY | ShiftMask, XK_z, spawn, PKILLCMD(GAME_Z) },

	{ MODKEY,             XK_x, spawn, {.v = gamexcmd}    },  // ddnet
	{ MODKEY | ShiftMask, XK_x, spawn, PKILLCMD(GAME_X) },

	{ MODKEY,             XK_c, spawn, {.v = gameccmd}    },  // hollow knight
	{ MODKEY | ShiftMask, XK_c, spawn, PKILLCMD(GAME_C) },

	/* CUSTOM SCRIPTS */

	// process control (sigstop/sigcont)
	{ MODKEY | ShiftMask, XK_r, spawn, SHCMD(EUDAIMONIA "/suckless/scripts/sigstop-focused.sh") },  // pause
	{ MODKEY | ShiftMask, XK_t, spawn, SHCMD(EUDAIMONIA "/suckless/scripts/sigcont-focused.sh") },  // resume

	// webcam
	{ MODKEY,             XK_5, spawn, SHCMD(EUDAIMONIA "/scripts/webcam.sh") },
	{ MODKEY | ShiftMask, XK_5, spawn, SHCMD("pkill ffplay") },

	{ MODKEY,             XK_grave, spawn, SHCMD(EUDAIMONIA "/shader-wallpaper/shadow/scripts/shader-switch.sh") },
	// switch shader wallpaper
	{ MODKEY | ShiftMask, XK_grave, spawn, SHCMD(EUDAIMONIA "/shader-wallpaper/shadow/scripts/shader-stop.sh && pkill picom") },
};

/* MOUSE BINDINGS */

static const Button buttons[] = {
	// click          event mask  button    function        argument
	{ ClkLtSymbol,    0,          Button1,  setlayout,      {0}                },
	{ ClkLtSymbol,    0,          Button3,  setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,    0,          Button2,  zoom,           {0}                },
	{ ClkStatusText,  0,          Button2,  spawn,          {.v = termcmd}     },
	{ ClkClientWin,   MODKEY,     Button1,  movemouse,      {0}                },
	{ ClkClientWin,   MODKEY,     Button2,  togglefloating, {0}                },
	{ ClkClientWin,   MODKEY,     Button3,  resizemouse,    {0}                },
	{ ClkTagBar,      0,          Button1,  view,           {0}                },
	{ ClkTagBar,      0,          Button3,  toggleview,     {0}                },
	{ ClkTagBar,      MODKEY,     Button1,  tag,            {0}                },
	{ ClkTagBar,      MODKEY,     Button3,  toggletag,      {0}                },
};
