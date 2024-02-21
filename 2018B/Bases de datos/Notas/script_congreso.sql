//creacion de la base de datos congreso
create database congreso;
---------------------------------------
//Creacion de la tabla Estado
create table estado(codigo_estado integer primary key,nombre varchar(20) not null unique);
------------------------------------------------------------------------------------------
//Creacion de la tabla Distrito
create table distrito(codigo_distrito integer primary key,nombre varchar(20) not null unique,region varchar(20) not null,codigo_estadoD integer not null,foreign key(codigo_estadoD) references estado(codigo_estado));
-----------------------------------------------------------------------------------------------------------------------------------------------------
//Creacion de la tabla Congresista 
create table congresista(cedula_profesional varchar(20) primary key,partido_politico varchar(20) not null,fecha_primera_eleccion date default now(),codigo_distritoC integer not null,foreign key(codigo_distritoC) references distrito(codigo_distrito));
-----------------------------------------------------------------------------------------------------------------------------------------------------
//Creacion de la tabla Proyecto de ley
create table proyecto_de_ley(codigo integer primary key,nombre varchar(20) not null unique,aprobado boolean,fecha_votacion date default now());
-----------------------------------------------------------------------------------------------------------------------------------------------
//Creacion de la tabla Voto
create table voto(cedulaV varchar(20) not null,foreign key(cedulaV) references congresista(cedula_profesional),codigoV integer not null,foreign key(codigoV) references proyecto_de_ley(codigo),fecha date default now(),voto int not null);
-----------------------------------------------------------------------------------------------------------------------------------------------------
//Insercion Estado
insert into estado(codigo_estado,nombre)values(1,'Los Angeles');
insert into estado(codigo_estado,nombre)values(2,'Alaska');
insert into estado(codigo_estado,nombre)values(3,'Arizona');
insert into estado(codigo_estado,nombre)values(4,'Arkansas');
insert into estado(codigo_estado,nombre)values(5,'California');
----------------------------------------------------------------
//Insercion Distrito
insert into distrito(codigo_distrito,nombre,region,codigo_estadoD)values(1,'Autauga','Centro',1);
insert into distrito(codigo_distrito,nombre,region,codigo_estadoD)values(49,'Montgomery','Centro',1);
insert into distrito(codigo_distrito,nombre,region,codigo_estadoD)values(7,'La Paz','oeste',3);
insert into distrito(codigo_distrito,nombre,region,codigo_estadoD)values(15,'Yuma','oeste',3);
insert into distrito(codigo_distrito,nombre,region,codigo_estadoD)values(19,'Los Angeles','sur',5);
----------------------------------------------------------------------------------------------------
//Insercion congresista
insert into congresista (cedula_profesional,partido_politico,fecha_primera_eleccion,codigo_distritoC)values('142018D','republicano','13/10/2018',1);
insert into congresista(cedula_profesional,partido_politico,fecha_primera_eleccion,codigo_distritoC)values('142934C','democrata','11/11/11',19);
insert into congresista (cedula_profesional,partido_politico,fecha_primera_eleccion,codigo_distritoC)values('771128B','republicano','14/10/2018',1);
insert into congresista(cedula_profesional,partido_politico,fecha_primera_eleccion,codigo_distritoC)values('102319S','democrata','28/10/18',7);
insert into congresista (cedula_profesional,partido_politico,fecha_primera_eleccion,codigo_distritoC)values('531017A','Libertario','20/7/2018',49);
---------------------------------------------------------------------------------------------------------------------------------------------------
//Insercion proyecto de ley
insert into proyecto_de_ley(codigo,nombre,aprobado,fecha_votacion)values(1,'Tren bala','yes','10/08/2012');
insert into proyecto_de_ley(codigo,nombre,aprobado,fecha_votacion)values(2,'Puente colgante','no','15/08/2000');
insert into proyecto_de_ley(codigo,nombre,aprobado,fecha_votacion)values(3,'Gasolina con algas','yes','01/04/2005');
insert into proyecto_de_ley(codigo,nombre,aprobado,fecha_votacion)values(4,'Ciudad universitaria','yes','12/10/2010');
insert into proyecto_de_ley(codigo,nombre,aprobado,fecha_votacion)values(5,'Metro submarino','yes','01/02/2020');
----------------------------------------------------------------------------------------------------------------------
//Insercion voto
insert into voto(cedulaV,codigoV,fecha,voto)values('142018D',1,'10/08/10',1);
insert into voto(cedulaV,codigoV,fecha,voto)values('142934C',1,'10/08/10',1);
insert into voto(cedulaV,codigoV,fecha,voto)values('771128B',2,'15/08/2000',1);
insert into voto(cedulaV,codigoV,fecha,voto)values('102319S',2,'15/08/2000',1);
insert into voto(cedulaV,codigoV,fecha,voto)values('531017A',2,'15/08/2000',0);
-----------------------------------------------------------------------------
delete from distrito;
select * from estado;

Caso Congreso
Consultar todos los proyectos con sus votos a favor y quienes lo emitieron.
select nombre, voto, cedulav from proyecto_de_ley inner join voto on codigo = codigov;