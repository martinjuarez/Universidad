function w=mincuat(x,y)

	n=input("Ingrese el grado del polinomio, n=");

	for i=(n+1):-1:1
		A(:,n+2-i)=[t.^(i-1)]';
	endfor

	B=A';

	M=B*A;

	MI=inv(M);

	x0=MI*B*y';

	ec=fopen("yy.m","w");

	fprintf(ec,"yy=");
	printf("p(x)=");

	for i=1:(n+1)
		printf("%+fx^%i",x0(i),n+1-i);
		fprintf(ec,"%+f.*x.^%i",x0(i),n+1-i);
	endfor
	printf("\n");
	fprintf(ec,";");
	fclose(ec);

	x=linspace(min(t)-2,max(t)+2,1000);
	yy

	plot(x,yy,t,y,"*r");
endfunction