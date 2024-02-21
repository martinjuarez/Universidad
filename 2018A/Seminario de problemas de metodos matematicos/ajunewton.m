clc
x=[0 5 10 15 20 25 30];y=[0 1.5297 9.5120 8.7025 2.8087 1.0881 0.3537]; % entrada de datos

xa=x;ya=y;
% Formacion de las diferencias divididas
d=zeros(length(y));
d(:,1)=y';
for k=2:length(x)
    for j=1:length(x)+1-k
        d(j,k)=(d(j+1,k-1)-d(j,k-1))/(x(j+k-1)-x(j));
    end
end
% Formacion del polinomio
for w=1:length(x)
    ds=num2str(abs(d(1,w)));
    if w>1
      if x(w-1)<0
          sg1='+';
    else
          sg1='-';
       end
    end
    if d(1,w)<0
       sg2='-';
    else
       sg2='+';
    end
    if w==1
       acum=num2str(d(1,1));
    elseif w==2
       polact=['(x' sg1 num2str(abs(x(w-1))) ')' ];
       actual=[ds '*' polact];
    acum=[acum sg2 actual];
    else
       polact=[polact '.*' '(x' sg1 num2str(abs(x(w-1))) ')' ];
       actual=[ds '*' polact];
    acum=[acum sg2 actual];
    end
end
 
% Presentacion de resultados
fprintf(' \n Valores de X y Y \n ');
disp(xa);
disp(ya);
fprintf('\n Polinomio interpolaci�n Newton : %s \n',acum);
x=input(' X interp = ');
if x>max(xa)|x<min(xa)
   fprintf('\t Punto fuera de rango. El resultado puede ser equivocado \n');
end
xinterp=x;
yinterp=eval(acum);
fprintf(' Y(%g) = %g \n',x,yinterp);
% Grafica de los puntos
fprintf(' Pulse cualquier tecla para ver la grafica de los puntos \n');
pause
xg=linspace(min(xa),max(xa));
x=xg;yg=eval(acum);
plot(xg,yg,xa,ya,'.r',xinterp,yinterp,'or');
grid