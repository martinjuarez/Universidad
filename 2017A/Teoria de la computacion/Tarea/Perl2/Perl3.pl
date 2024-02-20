use Data::Dumper;

%cadena=("dni","2356915","asignatura","Tecnologia Web","3","otro mas");

@llaves=keys (%cadena);
print Dumper(\@llaves);

@valores=values(%cadena);
print Dumper(\@valores);

print Dumper(\%cadena);
delete $cadena{"asignatura"};
print Dumper(\%cadena);
