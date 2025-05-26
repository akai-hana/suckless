***
this is my custom dwm build.

i started off using 6.5, but now i use dwm 6.4 because i found there was no meaningful difference between 6.4 and 6.5, and 6.5 introduced changes that broke many patches that, at the moment of writing this, have no 6.5 ports *(e.g. [awesomebar](https://dwm.suckless.org/patches/awesomebar/))*.
***

### patches used:
+ [better swallow](https://dwm.suckless.org/patches/betterswallow/)
+ [backlight](https://dwm.suckless.org/patches/backlight/)
+ [amixer integration](https://dwm.suckless.org/patches/amixer-integration/)
+ [actual fullscreen](https://dwm.suckless.org/patches/actualfullscreen/)

### dependencies
+ firacode nerd *(**extra/ttf-firacode-nerd** package on arch)*
+ noto sans cjk (jp in particular) *(**world/noto-fonts-cjk** package on arch)*
+ optionally, my *~/scripts* dir with the scripts i use, for certain program launch binds (can be found in [my other dotfiles repo](https://github.com/akai-hana/dotfiles))

### other details
- it is themed after the VN "milk outside a bag of milk". i used the color hex codes from the game, which can be found at [its wiki](https://milk.wiki.gg/wiki/Milk_outside_a_bag_of_milk_outside_a_bag_of_milk#Color_Palette).

#### TO-DO
+ *detach my dwm from ~/scripts, make the config more monolithic*
+ *figure out brightness & volume patches*
+ *maybe do scratchpads?*
+ *configure and patch dmenu with inspiration from bread's video*
