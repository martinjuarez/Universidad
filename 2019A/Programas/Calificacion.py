calificacion = input("Dame tu calificacion: ")
calificacion2 = calificacion

redondeoD = ((calificacion * 10) %10) * .10
redondeoC = calificacion2 % 10

print "redondeoD: ",redondeoD
print "redondeoC: ",redondeoC


if redondeoC >= 6:
    calificacion2 = calificacion2 + (10 - redondeoC)
else:
    calificacion2 = calificacion2

print "Tu calificacion es: ", calificacion
print "Tu calificacion2 es: ", calificacion2