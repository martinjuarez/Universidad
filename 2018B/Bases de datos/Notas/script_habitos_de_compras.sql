//Creacion de la base de datos habitos de compras
create database habitos_de_compras;
---------------------------------------------------
//creacion de la cliente
create table cliente(rfc_cliente char(13) primary key, nombre varchar(20) not null,edad_cliente varchar(3) not null,sexo char(1) not null,domicilio varchar(50) not null, estado_civil varchar(20) not null,grado_estudios varchar(20) not null, profesion varchar(20) not null, hobbie1 varchar(20) not null,hobbie2 varchar(20) not null,hobbie3 varchar(20) not null,departamento_preferencial varchar(20) not null);
----------------------------------------------------------------
//creacion tabla centro_comercial
create table centro_comercial(rfc_centro char(13) primary key, nombre_centro varchar(20) not null, direccion varchar(50) not null);
-----------------------------------------------------------------
//Creacion tabla compania
create table compania(producto varchar(20) primary key, nombre_compania varchar(20) unique not null, porcentaje_descuento varchar(20) not null);
----------------------------------------------------------------
//creacion tabla chat
create table chat(nombre varchar(20) primary key,rfc_cliente_c char(13) not null,foreign key(rfc_cliente_c) references cliente(rfc_cliente), nombre_tienda varchar(20) not null, producto_c varchar(20) not null,foreign key(producto_c) references compania(producto), monto integer not null, grado_satisfaccion varchar(20) not null, n_comemtarios varchar(9) not null,puntos integer not null);
-------------------------------------------------------------------------
//insercion cliente
insert into cliente(rfc_cliente, nombre, edad_cliente, sexo, domicilio, estado_civil, grado_estudios, profesion, hobbie1, hobbie2, hobbie3, departamento_preferencial)values('LAGF459828279','Mario','25','M','estaño #300 san jose','Soltero','Licencitura','Doctor','Natacion','Videojuegos','Comer','Frutas y verduras');
insert into cliente(rfc_cliente, nombre, edad_cliente, sexo, domicilio, estado_civil, grado_estudios, profesion, hobbie1, hobbie2, hobbie3, departamento_preferencial)values('POSV929381229','Carlos','23','M','oro #340 san jose','Soltero','Licencitura','Deportes','Natacion','Futbol','Box','Deportes');
insert into cliente(rfc_cliente, nombre, edad_cliente, sexo, domicilio, estado_civil, grado_estudios, profesion, hobbie1, hobbie2, hobbie3, departamento_preferencial)values('GKJH847280998','Javier','19','M','plata #160 san jose','Soltero','Bachillerato','Cerillo','Estudiar','Idiomas','Matematicas','Libreria');
insert into cliente(rfc_cliente, nombre, edad_cliente, sexo, domicilio, estado_civil, grado_estudios, profesion, hobbie1, hobbie2, hobbie3, departamento_preferencial)values('MNBV123589715','Claudia','24','F','Manzano #500 san judas','Casada','Bachillerato','Ama de casa','Cocinar','Ver TV','Comer','Comida');
insert into cliente(rfc_cliente, nombre, edad_cliente, sexo, domicilio, estado_civil, grado_estudios, profesion, hobbie1, hobbie2, hobbie3, departamento_preferencial)values('CGYU678554312','Sofia','24','F','Cobre #170 san jose','Soltero','Bachillerato','Estudiante','Estudiar','Idiomas','Matematicas','Ropa');
-----------------------------------------------------------------
//insercocion centro comercial
insert into centro_comercial(rfc_centro, nombre_centro, direccion) values ('SAFF123987671','Terraza', 'cruz # 600 industrial');
//insercion compania
insert into compania(producto, nombre_compania, porcentaje_descuento)values('Pesas','FITNESS','50');
insert into compania(producto, nombre_compania, porcentaje_descuento)values('Trilogia fantasia','Editorial MEG','90');
insert into compania(producto, nombre_compania, porcentaje_descuento)values('PC gamer','Electronicss','30');
insert into compania(producto, nombre_compania, porcentaje_descuento)values('Chilorio','Le cocine','40');
insert into compania(producto, nombre_compania, porcentaje_descuento)values('Audifonos slim','Eletronicss','60');
//Insercion chat
insert into chat(nombre,rfc_cliente_c, nombre_tienda, producto_c, monto, grado_satisfaccion, n_comemtarios,puntos)values('Mario','LAGF459828279','Explosiones','Pesas',200,'Muy bueno','3',50);
insert into chat(nombre,rfc_cliente_c, nombre_tienda, producto_c, monto, grado_satisfaccion, n_comemtarios,puntos)values('Carlos','POSV929381229','Explosiones','Pesas',200,'Muy bueno','4',50);
insert into chat(nombre,rfc_cliente_c, nombre_tienda, producto_c, monto, grado_satisfaccion, n_comemtarios,puntos)values('Sofia','CGYU678554312','MI PC','Audifonos slim',200,'Exelente','3',10);

Tienda comercial
Consultar puntos acumulados por un consumidor específico
select puntos from chat where nombre = 'Mario';