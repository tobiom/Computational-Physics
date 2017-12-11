list = system("ls *.dat")

set terminal png enhanced

do for [DATA in list] {
	set title remext(DATA)
	set xlabel "Times"
	set ylabel "Difference"
	set output DATA.".png"
	plot DATA with points pt 1 ps 0.1 title ""
}