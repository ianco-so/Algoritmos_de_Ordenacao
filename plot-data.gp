# ===============================
#           S1 INCREASE
# ===============================
set title "Sorting Algorithms Running Time (Increase Order) " font ", 32"
set title offset 0,-0.95
set xlabel "Array size (number of elements)" font "helvetica, 24"
set xlabel offset 0,-1.8
set ylabel "Running time (in miliseconds)" font "helvetica, 24"
set ylabel offset +1.8,0


set style line 1 lt 4 lw 3 dt 2
set style line 2 lt 3 lw 2
set style line 3 lc rgb 'red' dt 2 lt 1 lw 2
set style line 4 lc rgb 'black' dt 1 lt 1 lw 2
set style line 5 lc rgb 'blue' dt 2 lt 1 lw 2
set style line 6 lc rgb 'yellow' dt 2 lt 1 lw 2
set style line 7 lc rgb 'green' dt 2 lt 1 lw 2


set terminal png size 1920,1080
#set o 's1_increase.png'
#set datafile separator "\t\t" #Do you want specify the separator?


set grid                 # Do we want a grid?
set key top left         # Location of the keys


set o 's1_increase.png'

#set logscale y           # Use this if the curves are in different scale
set xrange [100:100000]    # Define range of X values to consider.
set yrange [0:10000]        # Define range of Y values to consider

plot 'output.txt' u 1:2 title 'Selection' w lp ls 1, \
    'output.txt' u 1:3 title 'Bubble' w lp ls 2, \
	'output.txt' u 1:4 title 'Inserction' w lp ls 3, \
	'output.txt' u 1:5 title 'Merge' w lp ls 4, \
	'output.txt' u 1:6 title 'Quick' w lp ls 5, \
	'output.txt' u 1:7 title 'Radix' w lp ls 6, \
	'output.txt' u 1:8 title 'Shell' w lp ls 7

# ===============================
#           S2 REVERSE
# ===============================

set title "Sorting Algorithms Running Time (Reverse Order) " font ", 32"
set o 's2_reverse.png'

#set logscale y
#set xrange [100:100000]
#set yrange [0:1.4] 

plot 'output.txt' u 1:9 title 'Selection' w lp ls 1, \
     'output.txt' u 1:10 title 'Bubble' w lp ls 2, \
	'output.txt' u 1:11 title 'Inserction' w lp ls 3, \
	'output.txt' u 1:12 title 'Merge' w lp ls 4, \
	'output.txt' u 1:13 title 'Quick' w lp ls 5, \
	'output.txt' u 1:14 title 'Radix' w lp ls 6, \
	'output.txt' u 1:15 title 'Shell' w lp ls 7

# ===============================
#           S3 RANDOM
# ===============================

set title "Sorting Algorithms Running Time (At Random) " font ", 32"
set o 's3_random.png'

#set logscale y
set xrange [100:100000]
set yrange [0:15000]

plot 'output.txt' u 1:16 title 'Selection' w lp ls 1, \
     'output.txt' u 1:17 title 'Bubble' w lp ls 2, \
	'output.txt' u 1:18 title 'Inserction' w lp ls 3, \
	'output.txt' u 1:19 title 'Merge' w lp ls 4, \
	'output.txt' u 1:20 title 'Quick' w lp ls 5, \
	'output.txt' u 1:21 title 'Radix' w lp ls 6, \
	'output.txt' u 1:22 title 'Shell' w lp ls 7

# ==================================
#           S4 25% RANDOM
# ==================================

set title "Sorting Algorithms Running Time (25% Random) " font ", 32"
set o 's4_25random.png'

#set logscale y
#set xrange [100:1000]
#set yrange [0:1.2]

plot 'output.txt' u 1:23 title 'Selection' w lp ls 1, \
     'output.txt' u 1:24 title 'Bubble' w lp ls 2, \
	'output.txt' u 1:25 title 'Inserction' w lp ls 3, \
	'output.txt' u 1:26 title 'Merge' w lp ls 4, \
	'output.txt' u 1:27 title 'Quick' w lp ls 5, \
	'output.txt' u 1:28 title 'Radix' w lp ls 6, \
	'output.txt' u 1:29 title 'Shell' w lp ls 7

# ==================================
#           S5 50% RANDOM
# ==================================

set title "Sorting Algorithms Running Time (50% Random) " font ", 32"
set o 's5_50random.png'

#set logscale y
#set xrange [100:1000]
#set yrange [0:1.6]

plot 'output.txt' u 1:30 title 'Selection' w lp ls 1, \
     'output.txt' u 1:31 title 'Bubble' w lp ls 2, \
	'output.txt' u 1:32 title 'Inserction' w lp ls 3, \
	'output.txt' u 1:33 title 'Merge' w lp ls 4, \
	'output.txt' u 1:34 title 'Quick' w lp ls 5, \
	'output.txt' u 1:35 title 'Radix' w lp ls 6, \
	'output.txt' u 1:36 title 'Shell' w lp ls 7

# ==================================
#           S6 75% RANDOM
# ==================================

set title "Sorting Algorithms Running Time (75% Random) " font ", 32"
set o 's6_75random.png'

#set logscale y
#set xrange [100:1000]
#set yrange [0:1.6]

plot 'output.txt' u 1:37 title 'Selection' w lp ls 1, \
     'output.txt' u 1:38 title 'Bubble' w lp ls 2, \
	'output.txt' u 1:39 title 'Inserction' w lp ls 3, \
	'output.txt' u 1:40 title 'Merge' w lp ls 4, \
	'output.txt' u 1:41 title 'Quick' w lp ls 5, \
	'output.txt' u 1:42 title 'Radix' w lp ls 6, \
	'output.txt' u 1:43 title 'Shell' w lp ls 7

set out