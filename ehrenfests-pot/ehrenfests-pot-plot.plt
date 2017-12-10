set terminal png enhanced

set title "Ehrenfests Pot Simulation"
set xlabel "Times"
set ylabel "Difference"
set terminal png
set output "ehrenfests-pot.png"
plot "ehrenfests-pot.dat" with points pt 1 ps 0.1 title ""