use Data::Dumper;

open(FILE, '<', $ARGV[0]) or die "No puedo abrir el fichero '$filename' $!\n";

while(<FILE>) {
#chop;
print $_;
   }
close(FILE);
