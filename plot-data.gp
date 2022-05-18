# =================================
# Define title and axis for the plot
# ---------------------------------
set title "Sorting Algorithms Runtime" font ", 32"
set title offset 0,-0.95
set xlabel "Array size (number of elements)" font "helvetica, 24"
set xlabel offset 0,-1.8
set ylabel "Running time (in miliseconds)" font "helvetica, 24"
set ylabel offset +1.8,0

# =================================
# Line style definition
# ---------------------------------
set style line 1 lt 4 lw 3 dt 2
set style line 2 lt 3 lw 2
set style line 3 lc rgb 'red' dt 2 lt 1 lw 2
set style line 4 lc rgb 'black' dt 1 lt 1 lw 2
set style line 5 lc rgb 'blue' dt 2 lt 1 lw 2
set style line 6 lc rgb 'yellow' dt 2 lt 1 lw 2
set style line 7 lc rgb 'green' dt 2 lt 1 lw 2

# =================================
# Choose where the output should be sent to.
# In this case, we send it to a PNG image.
# ---------------------------------
set terminal png size 1920,1080
set o 'runntime_in.png'

# =================================
# Plot curves and outher stuff
# ---------------------------------
set grid                 # Do we want a grid?
set key top left         # Location of the keys
#set logscale y           # Use this if the curves are in different scale
set xrange [0:100000]    # Define range of X values to consider.
set yrange [10:5000]        # Define range of Y values to consider

# Finally, this is the plot command
plot 'output.txt' u 1:2 title 'Quick' w lp ls 5
	#'output.txt' u 1:2 title 'Selection' w lp ls 1, \
     #'output.txt' u 1:3 title 'Bubble' w lp ls 2, \
	#'output.txt' u 1:4 title 'Inserction' w lp ls 3, \
	#'output.txt' u 1:5 title 'Merge' w lp ls 4, \
	#'output.txt' u 1:6 title 'Quick' w lp ls 5, \
	#'output.txt' u 1:7 title 'Radix' w lp ls 6, \
	#'output.txt' u 1:8 title 'Shell' w lp ls 7


# Go back to interactive terminal
set out