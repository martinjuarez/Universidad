t=input("Dame la expresion; [ejemplo -2xy = -2*x*y] : ", "s");
format short;
f=inline(t);
n=input("Dame n(numero de partes): ");
v=ones(2,n+1);
x=input("Dame el valor a aproximar(xf): ");
v(1,1)=input("Dame el valor de x0: ");
v(2,1)=input("Dame el valor de y0: ");
h=(x-v(1))/n;
n=n+1;
i=2;
while ( i <= n)
  v(1,i)=v(1,i-1)+h;
  i++;
endwhile
i=1;
while (i <= n-1)
  k1=f(v(1,i),v(2,i))
  k2=f(v(1,i)+(h/2),v(2,i)+(h/2)*k1)
  k3=f(v(1,i)+(h/2),v(2,i)+(h/2)*k2)
  k4=f(v(1,i)+h,v(2,i)+h*k3)
  k5=v(2,i)+(h/6)*(k1+2*k2+2*k3+k4)
  v(2,i+1)=k5;
  i++;
endwhile
disp('Tabla de iteraciones')
v