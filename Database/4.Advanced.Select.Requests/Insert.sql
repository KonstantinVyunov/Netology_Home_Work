insert into ЖАНР (назв_жанра) values ('Поп');
insert into ЖАНР (назв_жанра) values ('Рок');
insert into ЖАНР (назв_жанра) values ('Рэп');
insert into ЖАНР (назв_жанра) values ('Джаз');
insert into ЖАНР (назв_жанра) values ('Шансон');



insert into ИСПОЛНИТЕЛЬ (исполн) values ('RASA');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Жуки');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Дабро');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Король и шут');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Ария');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Баста');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Нурминский');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Sandra Amina');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Алексей Батычинко');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Дмитрий Тювелев');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Михаил Круг');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Сергей Трофимов');
insert into ИСПОЛНИТЕЛЬ (исполн) values ('Инна Вальтер');



insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (1,1,1);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (2,1,2);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (3,2,2);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (4,1,3);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (5,2,4);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (6,2,5);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (7,1,6);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (8,3,6);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (9,3,7);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (10,4,8);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (11,4,9);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (12,4,10);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (13,1,11);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (14,5,11);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (15,5,12);
insert into ЖАНР_ИСПОЛН (id, id_жанра, id_исполн) values (16,5,13);



insert into АЛЬБОМ (назв_альб, год_вып) values ('А_RASA',2018);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Жуки',2000);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Дабро',2019);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_К и Ш',2002);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Ария',1998);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Баста',2010);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Нурмин',2021);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Sandra',2022);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Алекс Бат',2001);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Дмит Тюв',2005);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Круг',2000);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Трофим',2009);
insert into АЛЬБОМ (назв_альб, год_вып) values ('А_Инна',2017);



insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (1,1,1);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (2,2,2);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (3,3,3);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (4,4,4);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (5,5,5);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (6,6,6);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (7,7,7);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (8,8,8);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (9,9,9);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (10,10,10);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (11,11,11);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (12,12,12);
insert into "ИСПОЛН_АЛЬБ"  (id, id_исполн , id_альб) values (13,13,13);


insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (1,'Пчеловод','00:02:50');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (2,'Батарейка','00:03:47');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (3,'Юность','00:03:39');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (4,'Лесник','00:03:11');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (5,'Штиль','00:05:44');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (2,'Танкист','00:02:54');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (6,'Моя игра','00:04:30');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (6,'Мама','00:03:56');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (7,'Суета','00:02:56');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (8,'Say','00:03:07');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (9,'7 Days','00:06:15');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (10,'Юность','00:02:23');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (11,'Фраер','00:02:56');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (12,'Снегири','00:02:59');
insert into ТРЭК (id_альбом, назв_трэка, время_трэка) values (13,'Мой бандит','00:03:33');


insert into СБОРНИК (назв_сбор, год_сбор) values ('СБ_1',2015);
insert into СБОРНИК (назв_сбор, год_сбор) values ('СБ_2',2016);
insert into СБОРНИК (назв_сбор, год_сбор) values ('СБ_3',2017);
insert into СБОРНИК (назв_сбор, год_сбор) values ('СБ_4',2018);
insert into СБОРНИК (назв_сбор, год_сбор) values ('СБ_5',2019);
insert into СБОРНИК (назв_сбор, год_сбор) values ('СБ_6',2020);
insert into СБОРНИК (назв_сбор, год_сбор) values ('СБ_7',2021);
insert into СБОРНИК (назв_сбор, год_сбор) values ('СБ_8',2022);



insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (1,1,2);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (2,1,5);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (3,1,7);

insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (4,2,6);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (5,2,4);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (6,2,8);

insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (7,3,11);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (8,3,12);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (9,3,13);

insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (10,4,1);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (11,4,14);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (12,4,15);

insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (13,5,3);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (14,5,4);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (15,5,13);

insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (16,6,15);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (17,6,1);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (18,6,6);

insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (19,7,9);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (20,7,8);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (21,7,12);

insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (22,8,10);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (23,8,3);
insert into "ТРЭК_СБОР"  (id, id_сбор , id_трэк) values (24,8,1);