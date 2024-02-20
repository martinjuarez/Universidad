$cadena = $ARGV[0];

if($cadena =~ /^hola$/){
	print "la cadena es la palabra hola\n";
}

if($cadena =~ /\d/){
	print "la cadena contiene un digito\n";
}

if($cadena !~ /\d/){
	print "la cadena no contiene un digito\n";
}

@ary = $cadena =~ m/a/g;
foreach $elemento (@ary) {
	print "$elemento\n";
}

$cadena =~ s/o/a/g;
print $cadena."\n";
