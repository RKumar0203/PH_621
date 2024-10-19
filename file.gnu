
set xlabel "x"
set ylabel "Wavefunction"
set title  "Solution of Simple Harmonic Oscillator in Ground State"
set zeroaxis
set key right 

plot "QHO.dat" using 1:2 w lp lc 4 pt 1 lw 3, "QHO.dat" using 1:3  w lp pt 2 lc 11 lw 3

