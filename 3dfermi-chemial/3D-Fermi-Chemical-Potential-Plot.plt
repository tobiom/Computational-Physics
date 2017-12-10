set terminal png enhanced

set title "3D-Fermi Chemical Potential"
set xlabel "Temperature  T/T_{f}"
set ylabel "Chemical Potential {/symbol m}/(k_{B}T) [/mol]"
set terminal png
set output "3D Fermi Chemical Potential.png"
plot "3D-Fermi-Chemical-Potential.dat" with points pt 1 ps 0.4 title ""