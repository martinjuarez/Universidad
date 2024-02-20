use Data::Dumper;

open(Archivo,"< bd.txt");

while(<Archivo>){
	print $_;
	if($_ =~ /^C\d{7}\|(ENG|FRE|GER|POR|RUS|SPA)\|[A-Z]\|L\d{7}\|[A-Z]{2}\|S\d{7}\|[^\|\n\r]+\|\d\|$/){
	print "El registro contiene el formato correcto\n";
	}
	else{
		print "El registro NO contiene el formato correcto\n";
	}
	print "\n";
}

close(Archivo);