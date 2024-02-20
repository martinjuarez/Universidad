#printf
$decimal=12.1596568;
printf "Cortamos el decimal: %8.3f\n",$decimal;

#chop
$cadena="Buenos dias";
chop ($cadena);
print $cadena; 
#es útil para eliminar el salto de linea de la entrada de consola o de una linea leída de archivo
print "\nIntroduce tu nombre: \n";
$nombre=<STDIN>;
print "comienza-$nombre-termina\n";
chop($nombre);
print "comienza-$nombre-termina\n";

#s
$cadena="esta cadena contiene el numero 1 y tambien el 2";
$cadena =~ s/(\d)/-aqui habia un numero-/g;
print $cadena."\n";

#m
$cadena="esta cadena contiene el numero 1 y tambien el 2";
@ary = $cadena =~ m/\d/g;
foreach $elemento (@ary) {
	print "$elemento\n";
}
