#! /bin/bash
for f in /etc/X11/xinit/xinitrc.d/*.sh; do
  source "$f"
done
~/.dwm/screen.sh 
picom &
#--experimental-backends &
dunst &
xset r rate 200 25
setxkbmap -layout en_US,ar -option 'grp:alt_shift_toggle'
 /home/ghd/go/bin/notifier  &
feh --bg-fill ~/configs/bg.png
# pgrep -fl 'pidswallow -gl' || pidswallow -gl
flameshot &
