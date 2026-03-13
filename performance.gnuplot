set datafile separator ","
set terminal pngcairo size 800,600
set output 'performance.png'
set title "Algorithm Performance"
set xlabel "Input Size (n)"
set ylabel "Time (seconds)"
set grid
plot 'data.txt' using 1:2 title "Best Case" with linespoints lt 1 lw 2, \
     'data.txt' using 1:3 title "Average Case" with linespoints lt 2 lw 2, \
     'data.txt' using 1:4 title "Worst Case" with linespoints lt 3 lw 2
unset output