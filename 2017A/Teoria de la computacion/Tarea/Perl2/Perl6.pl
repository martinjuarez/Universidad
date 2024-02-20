open (FICH, ">>bd2.txt");
@array=('a','b','c','d','e','f','g','h');
for ($c=0; $c < 8; $c++)
{
    print FICH "$array[$c]\n";
}
close (FICH);
