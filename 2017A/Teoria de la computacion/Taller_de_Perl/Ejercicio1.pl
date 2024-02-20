print " Introduce el registro de la base de datos: ";
$registro = <STDIN>; 

if($registro =~ /^C\d{7}\|(ENG|FRE|GER|POR|RUS|SPA)\|[A-Z]\|L\d{7}\|[A-Z]{2}\|S\d{7}\|[^\|\n\r]+\|\d\|$/){
	print "El registro contiene el formato correcto\n";
}
else{
	print "El registro NO contiene el formato correcto\n";
}