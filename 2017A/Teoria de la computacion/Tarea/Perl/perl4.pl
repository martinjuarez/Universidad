
print " PENSANDO UN NUMERO ....\n";
$numero = rand(100); #que hace esta linea?
print " Introduce un numero del 1 al 100:";
$entrada = <STDIN>; 
if($entrada == $numero) {print "Has acertado el numero\n";}
if($entrada > $numero) {print "El numero introducido es mayor que el pensado.\n";}
if($entrada < $numero) {print "El numero introducido es menor que el pensado.\n";}
print " EL NUMERO PENSADO ERA:",$numero;
