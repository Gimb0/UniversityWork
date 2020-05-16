mtype = {red, yellow, green};
active proctype P(mtype light) {
do
::
if
   :: light == red -> light = green
   :: light == yellow -> light = red
   :: light == green -> light = yellow
   fi
printf ("The light is now %e\n", light)
break
od}

init { run P(red) }
