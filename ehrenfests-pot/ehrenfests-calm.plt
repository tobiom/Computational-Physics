set terminal png enhanced

f(x)=a*x+b
fit f(x) "zeropoint-data-from-100000-to-1000.dat" using 1:2 via a,b

set title "zeropoint data".sprintf(" (y=%f*x+%f)",a,b)
set xlabel "N"
set ylabel "{/symbol t}_{relax}"
set output "relax-from-100000-to-1000.png"
plot "zeropoint-data-from-100000-to-1000.dat" with points pt 1 ps 0.7 title "simulation data", f(x) title "fitting"