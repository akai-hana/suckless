***
my custom dwm build.
***

### patches used:
+ [pertag](https://dwm.suckless.org/patches/pertag/)
+ [actual fullscreen](https://dwm.suckless.org/patches/actualfullscreen/)
+ [status bar font](https://dwm.suckless.org/patches/statusbarfont/)
+ [better swallow](https://dwm.suckless.org/patches/betterswallow/)
+ [backlight](https://dwm.suckless.org/patches/backlight/)
+ [amixer integration](https://dwm.suckless.org/patches/amixer-integration/)

## other patches:
+ i manually patched the source code to use byte instead of int datatype wherever possible


### dependencies
+ **firacode nerd fonts** for bar and dmenu
+ **noto sans cjk** for the workspace icons
+ **xres** for the better swallow patch
+ **xdotool** for the sigstop/sigcont bind functionality
+ **slstatus** for the clock and date
+ for any binds, my *~/scripts* dir with the scripts i use, for certain program launch binds, can be found in [my other dotfiles repo](https://github.com/akai-hana/dotfiles).

### theme
> custom one based on milk outside a bag of milk.
***

#### TO-DO
+ *fix <Super+M> crash (togglewin patch)*
+ *figure out brightness & volume patches*
