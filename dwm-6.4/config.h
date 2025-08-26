/* akai's custom config */

/* APPEARANCE */
// windows
static const unsigned int borderpx = 4;  // border pixel of windows
static const unsigned int snap     = 32; // snap pixel
static const int showbar           = 1;  // 0 means no bar
static const int topbar            = 0;  // 0 means bottom bar

// font
static const char *fonts[] = {
    "FiraCode Nerd Font Propo Ret:size=10",
    "Noto Sans CJK JP Medium:size=10"
};

static const char dmenufont[] = {
    "FiraCode Nerd Font Mono Ret:style=Regular:size=10"
};

// alpha patch
#define OPAQUE 0xffU
static const unsigned int baralpha    = 0xd0;   // bar background alpha (0x00..0xff)
static const unsigned int borderalpha = OPAQUE; // border alpha

// colorscheme
static const char col_gray1[]  = "#0d0d14";
static const char col_gray2[]  = "#52263e";
static const char col_gray3[]  = "#bbbbbb";
static const char col_gray4[]  = "#eeeeee";
static const char col_cyan[]   = "#ac3232"; /* focused color */

static const char *colors[][3] = {
    /*               fg         bg         border    */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
    [SchemeHid]  = { col_gray4, col_gray2, col_cyan  },
};
// alpha patch
/*        fg,          bg,       border */
static const unsigned int alphas[][3] = {
	{ borderalpha, baralpha, OPAQUE }
};

/* tagging */
// workspace indicators
static const char *tags[] = {"贖", "罪", "へ", "の", "途", "上"};

// workspace redirects
static const Rule rules[] = {
    /* class           instance title tags   mask isfloating monitor */
    // 1
    { "firefox",       NULL,     NULL, 1  <<  0,   0,         -1 },
    { "firefox-bin",   NULL,     NULL, 1  <<  0,   0,         -1 },
    { "zen",           NULL,     NULL, 1  <<  0,   0,         -1 },
    { "zen-browser",   NULL,     NULL, 1  <<  0,   0,         -1 },
    { "vivaldi",       NULL,     NULL, 1  <<  0,   0,         -1 },
    { "vivaldi-bin",   NULL,     NULL, 1  <<  0,   0,         -1 },
    // 2
    { "discord",       NULL,     NULL, 1  <<  1,   0,         -1 },
    { "vesktop",       NULL,     NULL, 1  <<  1,   0,         -1 },
    { "equibop",       NULL,     NULL, 1  <<  1,   0,         -1 },
    { "electron",      NULL,     NULL, 1  <<  1,   0,         -1 },
    // 3
    { "com.github.th_ch.youtube_music", \
	               NULL,     NULL, 1  <<  2,   0,         -1 },
    { NULL,            "com.github.th_ch.youtube_music", \
	                         NULL, 1  <<  2,   0,         -1 },
    // 4
    { "java",          NULL,     NULL, 1  <<  3,   0,         -1 },
    { "PrismLauncher", NULL,     NULL, 1  <<  3,   0,         -1 },
    { "DDNet",         NULL,     NULL, 1  <<  3,   0,         -1 },
    // 5
    { "emacs",         NULL,     NULL, 1  <<  4,   0,         -1 },
    { "Emacs",         NULL,     NULL, 1  <<  4,   0,         -1 },
    // 6
    { "Prismlauncher", NULL,     NULL, 1  <<  5,   0,         -1 },
    { "corectrl",      NULL,     NULL, 1  <<  5,   0,         -1 },
    { "qbittorrent",   NULL,     NULL, 1  <<  5,   0,         -1 },
    { "Deluge",        NULL,     NULL, 1  <<  5,   0,         -1 },
    { NULL,            "deluge", NULL, 1  <<  5,   0,         -1 },
};

/* layout(s) */
static const float mfact        = 0.5; // factor of master area size [0.05..0.95]
static const int nmaster        = 1;   // number of clients in master area
static const int resizehints    = 1;   // 1 means respect size hints in tiled resizals
static const int lockfullscreen = 0;   // 1 will force focus on the fullscreen window

static const Layout layouts[] = {
    // first entry is default
    // no layout function means floating behavior

    /* symbol     arrange function */
    { "[]=",       tile },
    { "><>",       NULL },
    { "[M]",       monocle },
};

/* key definitions */
#define MODKEY Mod4Mask // Mod3Mask == Alt; Mod4Mask == Super 

// basic window manipulation
#define TAGKEYS(KEY, TAG) \
        { MODKEY,                           KEY, view,       {.ui = 1 << TAG} }, \
        { MODKEY | ControlMask,             KEY, toggleview, {.ui = 1 << TAG} }, \
        { MODKEY | ShiftMask,               KEY, tag,        {.ui = 1 << TAG} }, \
        { MODKEY | ControlMask | ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char *[]) {"/bin/dash", "-c", cmd, NULL} }

/* commands */
static char dmenumon[2] = "0"; // component of dmenucmd, manipulated in spawn()

// dmenu
static const char *dmenucmd[] = {
    "dmenu_run", "-b", "-m",       dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb", col_cyan, "-sf",    col_gray4, NULL
};

// custom placeholders
static const char *termcmd[] = {"dash", "-c", "ghostty", NULL};

/* bindkeys */
static const Key keys[] = {
    // workspaces (6)
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_q, 3) TAGKEYS(XK_w, 4) TAGKEYS(XK_e, 5)

    // important dwm stuff
    { MODKEY,             XK_Tab,    spawn,     {.v = dmenucmd} },
    { MODKEY | ShiftMask, XK_Return, quit,      {0}             },
    { MODKEY,             XK_b,      togglebar, {0}             },

    { MODKEY,             XK_f, togglefullscr, {0} },
    { MODKEY | ShiftMask, XK_f, killclient,    {0} },

    // apps
    { MODKEY,             XK_a, spawn, SHCMD("~/scripts/browser.sh") },
    { MODKEY | ShiftMask, XK_a, spawn, SHCMD("killall zen-bin")      },

    { MODKEY,             XK_s, spawn, SHCMD("vesktop")          },
    { MODKEY | ShiftMask, XK_s, spawn, SHCMD("killall electron") },

    { MODKEY,             XK_d, spawn, SHCMD("ghostty")         },
    { MODKEY | ShiftMask, XK_d, spawn, SHCMD("killall ghostty") },

    { MODKEY,             XK_z, spawn, SHCMD("prismlauncher")         },
    { MODKEY | ShiftMask, XK_z, spawn, SHCMD("killall prismlauncher") },

    { MODKEY,             XK_x, spawn, SHCMD("~/Games/t-client/DDNet") },
    { MODKEY | ShiftMask, XK_x, spawn, SHCMD("killall DDNet")          },

    { MODKEY,             XK_c, spawn, SHCMD("youtube-music")         },
    { MODKEY | ShiftMask, XK_c, spawn, SHCMD("killall youtube-music") },

    { MODKEY,             XK_v, spawn, SHCMD("deluge")         },
    { MODKEY | ShiftMask, XK_v, spawn, SHCMD("killall deluge") },

    // awesomebar patch
    { MODKEY,             XK_j, focusstackvis, {.i = +1} },
    { MODKEY,             XK_k, focusstackvis, {.i = -1} },
    { MODKEY | ShiftMask, XK_j, focusstackhid, {.i = +1} },
    { MODKEY | ShiftMask, XK_k, focusstackhid, {.i = -1} },

    // togglewin patch
    { MODKEY, XK_m, togglewin, {0} },
    
    /* remove inc/dec master: i don't use it, takes up keybinding slots */
    { MODKEY, XK_o, incnmaster, {.i = +1} },
    { MODKEY, XK_p, incnmaster, {.i = -1} },

    // window control
    { MODKEY,             XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,             XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,             XK_grave,  zoom,           {0}          },
    { MODKEY | ShiftMask, XK_Tab,    view,           {0}          },
    { MODKEY,             XK_space,  setlayout,      {0}          },
    { MODKEY | ShiftMask, XK_space,  togglefloating, {0}          },
    { MODKEY,             XK_0,      view,           {.ui = ~0}   },
    { MODKEY | ShiftMask, XK_0,      tag,            {.ui = ~0}   },
    { MODKEY,             XK_comma,  focusmon,       {.i = -1}    },
    { MODKEY,             XK_period, focusmon,       {.i = +1}    },
    { MODKEY | ShiftMask, XK_comma,  tagmon,         {.i = -1}    },
    { MODKEY | ShiftMask, XK_period, tagmon,         {.i = +1}    },

    // awesomebar patch
    { MODKEY,             XK_r, hide,    {0} },
    { MODKEY,             XK_t, showall, {0} },
    { MODKEY | ShiftMask, XK_t, show,    {0} },

    
    // layout switching
    { MODKEY, XK_4, spawn, SHCMD("~/scripts/layoutswitch.sh") }
};

/* button definitions */

// click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin

static const Button buttons[] = {
    /* click eventmask button function argument */
    { ClkLtSymbol,   0,      Button1, setlayout,      {0}                },
    { ClkLtSymbol,   0,      Button3, setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,   0,      Button2, zoom,           {0}                },
    { ClkStatusText, 0,      Button2, spawn,          {.v = termcmd}     },
    { ClkClientWin,  MODKEY, Button1, movemouse,      {0}                },
    { ClkClientWin,  MODKEY, Button2, togglefloating, {0}                },
    { ClkClientWin,  MODKEY, Button3, resizemouse,    {0}                },
    { ClkTagBar,     0,      Button1, view,           {0}                },
    { ClkTagBar,     0,      Button3, toggleview,     {0}                },
    { ClkTagBar,     MODKEY, Button1, tag,            {0}                },
    { ClkTagBar,     MODKEY, Button3, toggletag,      {0}                },
};
