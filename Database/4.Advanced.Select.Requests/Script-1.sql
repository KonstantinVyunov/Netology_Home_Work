create table if not exists ЖАНР(
	id serial PRIMARY KEY,
	назв_жанра varchar(10) not null
);

create table if not exists ИСПОЛНИТЕЛЬ(
	id serial PRIMARY KEY,
	исполн varchar(30) not null
);

create table if not exists ЖАНР_ИСПОЛН(
	id serial,
	id_жанра int references ЖАНР (id) not null,
	id_исполн int references ИСПОЛНИТЕЛЬ (id) not null
);



create table if not exists АЛЬБОМ(
	id serial PRIMARY KEY,
	назв_альб varchar(30) not null,
	год_вып int not null
);

create table if not exists ИСПОЛН_АЛЬБ(
	id serial,	
	id_исполн int references ИСПОЛНИТЕЛЬ (id) not null,
	id_альб int references АЛЬБОМ (id) not null
);

create table if not exists ТРЭК(
	id serial PRIMARY KEY,
	id_альбом int references АЛЬБОМ (id) not null,
	назв_трэка varchar(30) not null,
	время_трэка time not null
);

create table if not exists СБОРНИК(
	id serial PRIMARY KEY,
	назв_сбор varchar(30) not null,
	год_сбор int not null
);

create table if not exists ТРЭК_СБОР (
	id serial,	
	id_сбор int references СБОРНИК (id) not null,
	id_трэк int references ТРЭК (id) not null
);
