mysql> drop database if exists jugador;


mysql> create database jugador;


mysql> use jugador;


mysql> create table jug(user varchar(20) primary key not null, pasaword varc
har(30));


mysql> create table partida (id_p integer primary key not null, fecha varchar(15), duracion integer, ganador varchar(20));


mysql> create table relacion(user varchar(20), id_p integer, foreign key (user) references jug(user), foreign key (id_p) references partida (id_p));

mysql> insert into jug values('david2004','1234');

mysql> insert into jug values ('pol56','6789');


mysql> insert into partida values(1,'23/02/24.13:02',38,'david2004');

mysql> insert into partida values(4,'23/03/24.13:37',27,'pol56');

mysql> insert into relacion values('david2004',1);

mysql> insert into relacion values('pol56',4);
