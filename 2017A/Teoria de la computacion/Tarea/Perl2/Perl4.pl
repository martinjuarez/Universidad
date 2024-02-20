#@ARGV
print "el primer parametro recibido es: $ARGV[0]\n";
foreach $param (@ARGV){
	print $param,"\n";
}

#$number
$cadena="contiene el numero 3 y el correo sulema.torres\@cucei.udg.mx";
if($cadena =~ /[\w ]+ (\d) [\w ]+ ([\w-\.]+\@[\w-\.]+)/){
	print "el numero es:$1\nel correo es:$2\n";
}

$cadena =~ s/(\d)/-aqui esta el digito:$1-/g;
print $cadena,"\n";

#$#array
@lista1=(1,2,3,4,5,6,7,8,9);
print $#lista1;
