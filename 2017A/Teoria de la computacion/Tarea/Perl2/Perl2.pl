use Data::Dumper;

@pila=(1, 2, 3, 4);
$valor=5;
push (@pila, $valor); 
print Dumper(\@pila);

$valor=pop(@pila);
print Dumper(\@pila);
print "el valor eliminado es $valor\n";

unshift(@pila, $valor); 
print Dumper(\@pila);

$valor=shift(@pila);
print Dumper(\@pila);
print "el valor eliminado es $valor\n";

@lista1=(1,2,3,4,5,6,7,8,9);
print Dumper(\@lista1);
@lista2=reverse (@lista1);
print Dumper(\@lista2);

@nombres=sort("Javier","Pablo","Alberto");
print Dumper(\@nombres);

@numbers=sort(1,2,3,4,5,6,7,8,9,11,22);
print Dumper(\@numbers);

@numbers= sort { $a <=> $b } @numbers;
print Dumper(\@numbers);

$cadena="juana pedro y otros   nombres";
@division=split(/ +/,$cadena);
print Dumper(\@division);

print join("-",@numbers);
