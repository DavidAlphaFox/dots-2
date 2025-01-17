/* See LICENSE file for copyright and license details. */

static const char *dmenucmd[] = {"dmenu_run", "-g", "12",    "-l",
                                 "80",        "-p", "Run: ", NULL};

// dmenu_run  -l 80 -g 12 -p 'run'
static const char *emacs[] = {"emaks", NULL};
static const char *anyywhere[] = {"/home/ghd/.emacs_anywhere/bin/run", NULL};

static const char *pctlpreviouscmd[] = {"playerctl", "previous", NULL};
static const char *pctlplaycmd[] = {"playerctl", "play-pause", NULL};
static const char *pctlpausecmd[] = {"playerctl", "pause", NULL};
static const char *pctlnextcmd[] = {"playerctl", "next", NULL};
static const char *gbrowsercmd[] = {"chromium", NULL};
static const char *ggm[] = {"keepassxc", NULL};
static const char *exp[] = {"thunar", NULL};
static const char *ranger[] = {"kitty", "-e", "ranger", NULL};
static const char *mov[] = {
    "chromium", "https://www.notion.so/Home-9061ccbeaa414fb0b7335c42f8299692",
    NULL};
static const char *scr[] = {"flameshot", "gui", NULL};
static const char *mail[] = {"mail", NULL};
static const char *pdf[] = {"zathura", NULL};
static const char *copy[] = {"rofi", "-show", "drun", "-show-icons", NULL};
static const char *copy1[] = {"rofi", "-show", "emoji", "-modi", "emoji", NULL};
static const char *lf[] = {"kitty", "-e", "lfrun", NULL};
static const char *tel[] = {"caprine", NULL};
static const char *dis[] = {"chromium", "discord.com", NULL};
static const char *ms[] = {"chromium", "m.me", NULL};
static const char *fid[] = {
    "chromium",
    "chrome-extension://mefgmmbdailogpfhfblcnnjfmnpnmdfa/reader.html", NULL};
static const char *htop[] = {"kitty", "-e ", "htop", NULL};
static const char *yakyak[] = {"yakyak", NULL};
static const char *pad[] = {"leafpad", NULL};
static const char *start[] = {"kitty", "-e ", "rsblocks", "&", "dunst", NULL};
static const char *trello[] = {"chromium", "https://www.google.com ", NULL};
//#include "fibonacci.h"
static const char *brightcmd[][4] = {
    {"light", "-A", "5", NULL},
    {"light", "-U", "5", NULL},

};

static const char *upvol[] = {"/usr/bin/pactl", "set-sink-volume",
                              "@DEFAULT_SINK@", "+5%", NULL};
static const char *downvol[] = {"/usr/bin/pactl", "set-sink-volume",
                                "@DEFAULT_SINK@", "-5%", NULL};
static const char *mutevol[] = {"/usr/bin/pactl", "set-sink-mute",
                                "@DEFAULT_SINK@", "toggle", NULL};

/* Constants */
#define TERMINAL "kitty"
#define TERMCLASS "kitty"
#define BROWSER "chromium"

/* appearance */
static unsigned int borderpx = 1; /* border pixel of windows */
static unsigned int snap = 32;    /* snap pixel */
static unsigned int gappih = 20;  /* horiz inner gap between windows */
static unsigned int gappiv = 10;  /* vert inner gap between windows */
static unsigned int gappoh =
    10; /* horiz outer gap between windows and screen edge */
static unsigned int gappov =
    30; /* vert outer gap between windows and screen edge */
static int swallowfloating =
    0; /* 1 means swallow floating windows by default */
static int smartgaps =
    0;                  /* 1 means no outer gap when there is only one window */
static int showbar = 1; /* 0 means no bar */
static int topbar = 1;  /* 0 means bottom bar */
static const char *fonts[] = {
    "Mononoki Nerd Font:size=9.5:antialias=true:autohint=true",
    "Hack:size=9.5:antialias=true:autohint=true",
    "JoyPixels:size=9.5:antialias=true:autohint=true"};

static char normbgcolor[] = "#222222";
static char normbordercolor[] = "#444444";
static char normfgcolor[] = "#bbbbbb";
static char selfgcolor[] = "#eeeeee";
static char selbordercolor[] = "#770000";
static char selbgcolor[] = "#005577";

/* static char normbgcolor[] = "#333333"; */
/* static char normbordercolor[] = "#888580"; */
/* static char normfgcolor[] = "#888580"; */
/* static char selfgcolor[] = "#F8F8F8"; */
/* static char selbordercolor[] = "#F8F8F8"; */
/* static char selbgcolor[] = "#404040"; */

/* static char *colors[][3] = { */
/*     /\*               fg           bg           border   *\/ */
/*     [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor}, */
/*     [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor}, */
/* }; */

static const char col_gray1[] = "#000000";
static const char col_gray2[] = "#888580";
static const char col_gray3[] = "#F7F8F8";
static const char col_gray4[] = "#F8F8F8";
static const char col_cyan[]  = "#1E1E1E";

static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_cyan},
};

typedef struct {
  const char *name;
  const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL};
const char *spcmd2[] = {TERMINAL, "-n",    "spcalc", "-f", "monospace:size=16",
                        "-g",     "50x20", "-e",     "bc", "-lq",
                        NULL};
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm", spcmd1},
    {"spcalc", spcmd2},
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class    instance      title       	 tags mask    isfloating
       isterminal  noswallow  monitor */
    {"Gimp", NULL, NULL, 1 << 8, 0, 0, 0, -1},
    {TERMCLASS, NULL, NULL, 0, 0, 1, 0, -1},
    {NULL, NULL, "Event Tester", 0, 0, 0, 1, -1},
    {TERMCLASS, "bg", NULL, 1 << 7, 0, 1, 0, -1},
    {TERMCLASS, "spterm", NULL, SPTAG(0), 1, 1, 0, -1},
    {TERMCLASS, "spcalc", NULL, SPTAG(1), 1, 1, 0, -1},
};

/* layout(s) */
static float mfact = 0.55;  /* factor of master area size [0.05..0.95] */
static int nmaster = 1;     /* number of clients in master area */
static int resizehints = 0; /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT                                                           \
  1 /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile},   /* Default: Master on left, slaves on right */
    {"TTT", bstack}, /* Master on top, slaves on bottom */

    {"[@]", spiral},   /* Fibonacci spiral */
    {"[\\]", dwindle}, /* Decreasing in size right and leftward */

    {"[D]", deck},    /* Master on left, slaves in monocle-like mode on right */
    {"[M]", monocle}, /* All windows on top of eachother */

    {"|M|", centeredmaster},         /* Master in middle, slaves on sides */
    {">M>", centeredfloatingmaster}, /* Same but master floats */

    {"><>", NULL}, /* no layout function means floating behavior */
    {NULL, NULL},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},
#define STACKKEYS(MOD, ACTION)                                                 \
  {MOD, XK_j, ACTION##stack, {.i = INC(+1)}},                                  \
      {MOD, XK_k, ACTION##stack, {.i = INC(-1)}},                              \
      {MOD,                                                                    \
       XK_v,                                                                   \
       ACTION##stack,                                                          \
       {.i = 0}}, /* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
                  /* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
                  /* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
                  /* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static const char *termcmd[] = {TERMINAL, NULL};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
    {"color0", STRING, &normbordercolor},
    {"color8", STRING, &selbordercolor},
    {"color0", STRING, &normbgcolor},
    {"color4", STRING, &normfgcolor},
    {"color0", STRING, &selfgcolor},
    {"color4", STRING, &selbgcolor},
    {"borderpx", INTEGER, &borderpx},
    {"snap", INTEGER, &snap},
    {"showbar", INTEGER, &showbar},
    {"topbar", INTEGER, &topbar},
    {"nmaster", INTEGER, &nmaster},
    {"resizehints", INTEGER, &resizehints},
    {"mfact", FLOAT, &mfact},
    {"gappih", INTEGER, &gappih},
    {"gappiv", INTEGER, &gappiv},
    {"gappoh", INTEGER, &gappoh},
    {"gappov", INTEGER, &gappov},
    {"swallowfloating", INTEGER, &swallowfloating},
    {"smartgaps", INTEGER, &smartgaps},
};

#include "shiftview.c"
#include <X11/XF86keysym.h>

static Key keys[] = {
    /* modifier                     key        function        argument */
    STACKKEYS(MODKEY, focus) STACKKEYS(MODKEY | ShiftMask, push)
    /* { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, */
    {MODKEY, XK_grave, spawn, {.v = (const char *[]){"dmenuunicode", NULL}}},
    /* { MODKEY|ShiftMask,		XK_grave,	togglescratch,
     * SHCMD("")
     * },
     */
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},

    {MODKEY, XK_Tab, view, {0}},
    /* { MODKEY|ShiftMask,		XK_Tab,		spawn, SHCMD("")
     * },
     */
    /*	{ MODKEY,			XK_q,		killclient,	{0} },
     */
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},             /* tile */
    {MODKEY | ShiftMask, XK_t, setlayout, {.v = &layouts[1]}}, /* bstack */
    {MODKEY, XK_y, setlayout, {.v = &layouts[2]}},             /* spiral */
    {MODKEY | ShiftMask, XK_y, setlayout, {.v = &layouts[3]}}, /* dwindle */
    {MODKEY, XK_u, setlayout, {.v = &layouts[4]}},             /* deck */

    {MODKEY, XK_f, setlayout, {.v = &layouts[5]}}, /* monocle */
    {MODKEY | ShiftMask, XK_u, togglefullscr, {0}},

    {MODKEY, XK_i, setlayout, {.v = &layouts[6]}}, /* centeredmaster */

    {MODKEY | ShiftMask, XK_c, spawn, {.v = gbrowsercmd}},

    {MODKEY | ShiftMask,
     XK_i,
     setlayout,
     {.v = &layouts[7]}}, /* centeredfloatingmaster */

    {MODKEY, XK_o, spawn, {.v = copy}},

    {MODKEY, XK_p, incnmaster, {.i = +1}},
    {MODKEY | ShiftMask, XK_p, incnmaster, {.i = -1}},

    {MODKEY, XK_backslash, view, {0}},

    {MODKEY, XK_a, togglegaps, {0}},
    {MODKEY | ShiftMask, XK_a, defaultgaps, {0}},
    {MODKEY, XK_s, togglesticky, {0}},
    /* { MODKEY|ShiftMask,		XK_s,		spawn, SHCMD("")
     * },
     */
    {MODKEY | ShiftMask,
     XK_d,
     spawn,
     {.v = (const char *[]){"passmenu", NULL}}},
    /* {MODKEY | ShiftMask, XK_f, setlayout, {.v = &layouts[8]}}, */
    {MODKEY, XK_g, shiftview, {.i = -1}},
    {MODKEY | ShiftMask, XK_g, shifttag, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    /* J and K are automatically bound above in STACKEYS */
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    /* {MODKEY, XK_semicolon, shiftview, {.i = 1}}, */
    /* {MODKEY | ShiftMask, XK_semicolon, shifttag, {.i = 1}}, */
    {MODKEY, XK_apostrophe, togglescratch, {.ui = 1}},
    /* { MODKEY|ShiftMask,		XK_apostrophe,	spawn, SHCMD("")
     * },
     */
    {MODKEY | ShiftMask, XK_apostrophe, togglesmartgaps, {0}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY | ShiftMask, XK_Return, togglescratch, {.ui = 0}},

    {MODKEY, XK_z, incrgaps, {.i = +3}},
    /* { MODKEY|ShiftMask,		XK_z,		spawn, SHCMD("")
     * },
     */
    {MODKEY, XK_x, incrgaps, {.i = -3}},
    /* { MODKEY|ShiftMask,		XK_x,		spawn, SHCMD("")
     * },
     */
    /* { MODKEY|ShiftMask,		XK_c,		spawn, SHCMD("")
     * },
     */
    /* V is automatically bound above in STACKKEYS */
    {MODKEY, XK_b, togglebar, {0}},
    /* { MODKEY|ShiftMask,		XK_b,		spawn, SHCMD("")
     * },
     */

    {MODKEY, XK_Left, focusmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_Left, tagmon, {.i = -1}},
    {MODKEY, XK_Right, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_Right, tagmon, {.i = +1}},

    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},

    {MODKEY, XK_Page_Up, shiftview, {.i = -1}},
    {MODKEY | ShiftMask, XK_Page_Up, shifttag, {.i = -1}},
    {MODKEY, XK_Page_Down, shiftview, {.i = +1}},
    {MODKEY | ShiftMask, XK_Page_Down, shifttag, {.i = +1}},

    {MODKEY, XK_space, zoom, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},

    {MODKEY, XK_d, spawn, {.v = dmenucmd}},
    {MODKEY, XK_c, killclient, {0}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY | ShiftMask, XK_s, spawn, {.v = scr}},
    {MODKEY, XK_e, spawn, {.v = lf}},
    {MODKEY | ShiftMask, XK_d, spawn, {.v = dis}},
    //{MODKEY | ShiftMask, XK_f, spawn, {.v = fid}},
    {MODKEY, XK_w, spawn, {.v = emacs}},
    {MODKEY | ShiftMask, XK_w, spawn, {.v = anyywhere}},

    {0, XF86XK_AudioPlay, spawn, {.v = pctlplaycmd}},
    {0, XF86XK_AudioPause, spawn, {.v = pctlpausecmd}},
    {0, XF86XK_AudioNext, spawn, {.v = pctlnextcmd}},
    {0, XF86XK_AudioPrev, spawn, {.v = pctlpreviouscmd}},

    {MODKEY | ShiftMask, XK_l, spawn, {.v = pad}},

    {MODKEY | ShiftMask, XK_z, spawn, {.v = pdf}},
    {MODKEY | ShiftMask, XK_e, spawn, {.v = exp}},

    {MODKEY, XK_semicolon, spawn, {.v = copy1}},

    {0, XF86XK_AudioMute, spawn, {.v = mutevol}},
    {0, XF86XK_AudioLowerVolume, spawn, {.v = downvol}},
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = upvol}},
    {0,
     XF86XK_MonBrightnessUp,
     spawn,
     {.v = brightcmd[0]}}, //                    brightness up
    {0, XF86XK_MonBrightnessDown, spawn, {.v = brightcmd[1]}},

    /* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } },
     */
    /* { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } },
     */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
     */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
     */
    /* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
     */
    /* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
     */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, */
    /* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
     */
    /* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
     */
    /* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
     */
    /* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
     */
    /* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } },
     */
    /* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } },
     */
    /* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
     */
    /* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
     */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
/* click                event mask      button          function        argument
 */
#ifndef __OpenBSD__
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button1, sigdwmblocks, {.i = 1}},
    {ClkStatusText, 0, Button2, sigdwmblocks, {.i = 2}},
    {ClkStatusText, 0, Button3, sigdwmblocks, {.i = 3}},
    {ClkStatusText, 0, Button4, sigdwmblocks, {.i = 4}},
    {ClkStatusText, 0, Button5, sigdwmblocks, {.i = 5}},
    {ClkStatusText, ShiftMask, Button1, sigdwmblocks, {.i = 6}},
#endif
    {ClkStatusText, ShiftMask, Button3, spawn,
     SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h")},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, defaultgaps, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkClientWin, MODKEY, Button4, incrgaps, {.i = +1}},
    {ClkClientWin, MODKEY, Button5, incrgaps, {.i = -1}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkTagBar, 0, Button4, shiftview, {.i = -1}},
    {ClkTagBar, 0, Button5, shiftview, {.i = 1}},
    {ClkRootWin, 0, Button2, togglebar, {0}},
};
