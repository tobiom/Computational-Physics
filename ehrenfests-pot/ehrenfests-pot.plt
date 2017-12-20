set terminal png enhanced

set title "Ehrenfests N=10000000"
set xlabel "Times"
set ylabel "Difference"
set terminal png
set output "ehrenfests-pot-num=10000000.png"
plot "ehrenfests-pot-num=10000000.dat" with points pt 1 ps 0.1 title ""