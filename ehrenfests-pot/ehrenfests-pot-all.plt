list = system("ls *.dat")

set terminal png enhanced

do for [i=1:words(list)] {
	set title remext(word(list, i))
	set xlabel "Times"
	set ylabel "Difference"
	set output remext(word(list, i))."png"
	plot word(list, i) with points pt 1 ps 0.1 title ""
}