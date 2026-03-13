set terminal svg size 800,600 enhanced 
set output 'quicksort_times.svg'
set title "Quick Sort Time Complexity"
set xlabel "Input Size"
set ylabel "Time (ms)"
set grid
plot 'data.txt' using "Size":"Best-Case" with linespoints title 'Best Case', \
             '' using "Size":"Average-Case" with linespoints title 'Average Case', \
             '' using "Size":"Worst-Case" with linespoints title 'Worst Case'
