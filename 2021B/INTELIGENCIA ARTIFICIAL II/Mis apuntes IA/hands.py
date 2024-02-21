advertising = [23,26,30,34,43,48,52,57,58]
sales = [651,762,856,1063,1190,1298,1421,1440,1518]
sum = [0,0,0,0]
k=0
while k < 9:
    sum[0] = sum[0] + advertising[k] * sales[k]
    k+=1
print(sum[0])  
k=0
while k < 9:
    sum[1] = sum[1] + advertising[k]
    k+=1
print(sum[1]) 
k=0
while k < 9:
    sum[2] = sum[2] + sales[k]
    k+=1
print(sum[2])     
k=0
while k < 9:
    sum[3] = sum[3] + advertising[k]**2
    k+=1
print(sum[3])
y= sum[2] / k
print(y)
x= sum[1] / k
print(x)
B1 = (k*sum[0]-sum[1]*sum[2])/(k*sum[3]-sum[1]*sum[1])
print("B1 =", B1)
B0 = y - B1 * x
print("B0 =", B0)
salesnew = [0,0,0]
salesnew[0] =  B0 + B1 * 60
salesnew[1] =  B0 + B1 * 70
salesnew[2] =  B0 + B1 * 80
print("60=", salesnew[0])
print("70=", salesnew[1])
print("80=", salesnew[2])
