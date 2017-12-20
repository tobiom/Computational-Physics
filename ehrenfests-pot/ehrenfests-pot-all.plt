list = system("ls ehrenfests-pot-num=*.dat")

set terminal png enhanced

do for [DATA in list] {
	set title DATA
	set xlabel "Times"
	set ylabel "Difference"
	set output DATA.".png"
	plot DATA with points pt 1 ps 0.2 title ""
}