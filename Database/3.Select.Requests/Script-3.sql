select назв_альб, год_вып from АЛЬБОМ where год_вып = 2018;
select назв_трэка, время_трэка  from ТРЭК order  by  время_трэка desc limit 1;
select назв_трэка  from ТРЭК where время_трэка  >= '00:03:30';
select назв_сбор from СБОРНИК с  where год_сбор  between 2018 and  2020;
select исполн from ИСПОЛНИТЕЛЬ where исполн not like '% %';
select назв_трэка from ТРЭК where  назв_трэка  ilike '%мой%';

