set terminal png enhanced

set title "Ehrenfests Pot Simulation N=25"
set xlabel "Times"
set ylabel "Difference"
set terminal png
set output "ehrenfests-pot-num=25.png"
plot "ehrenfests-pot-num=25.dat" with points pt 1 ps 0.1 title ""