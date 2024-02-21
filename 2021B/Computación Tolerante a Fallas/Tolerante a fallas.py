n = 7
m = 0
exp = 20 *.9
act = 0.0
print("Exposicion",exp)
exa1 = 20 *.9
print("Examen1",exa1)
exa2 = 0
prac = 0
act100 = 20 / n
print("Act100",act100)
act90 = act100 * .9
print("Act90",act90)
while m < n :
    if m < 6:
        act = act + act100
    if m > 5:
        act = act + act90
    m = m+1

print("Actividades",act)
total = exp + act + prac + exa1 + exa2
print("Total",total)
input()
