select Ж.назв_жанра, count(И.исполн)from ЖАНР as Ж
left join ЖАНР_ИСПОЛН  as Ж_И on Ж.id = Ж_И.id_жанра 
left join ИСПОЛНИТЕЛЬ as И on Ж_И.id_исполн  = И.id
group by Ж.назв_жанра
order by count(И.id) desc;

select Т.назв_трэка, А.год_вып from АЛЬБОМ as А
left join ТРЭК as Т on Т.id_альбом  = А.id
where (А.год_вып  >= 2019) and (А.год_вып  <= 2020);

select А.назв_альб, AVG(Т.время_трэка) from АЛЬБОМ as А
left join ТРЭК as Т on Т.id_альбом = А.id
group by А.назв_альб
order by AVG(Т.время_трэка);

select distinct И.исполн from ИСПОЛНИТЕЛЬ as И
where И.исполн not in (
    select distinct И.исполн
    from ИСПОЛНИТЕЛЬ as И
    left join ИСПОЛН_АЛЬБ as И_А on И.id = И_А.id_исполн
    left join АЛЬБОМ as А on А.id = И_А.id_альб 
    where А.год_вып = 2020
)
order by И.исполн;

select distinct С.назв_сбор from СБОРНИК as С
left join ТРЭК_СБОР  as Т_С on С.id = Т_С.id_сбор
left join ТРЭК as Т on Т.id = Т_С.id_трэк
left join АЛЬБОМ as А on А.id = Т.id_альбом
left join ИСПОЛН_АЛЬБ as И_А on И_А.id_альб = А.id
left join ИСПОЛНИТЕЛЬ as И on И.id = И_А.id_исполн
where И.исполн like '%%Жуки%%'
order by С.назв_сбор;

select А.назв_альб from АЛЬБОМ as А
left join ИСПОЛН_АЛЬБ as И_А on А.id = И_А.id_альб
left join ИСПОЛНИТЕЛЬ as И on И.id = И_А.id_исполн
left join ЖАНР_ИСПОЛН  as Ж_И on И.id = Ж_И.id_исполн
left join ЖАНР as Ж on Ж.id = Ж_И.id_жанра 
group by А.назв_альб
having count(distinct Ж.назв_жанра) > 1
order by А.назв_альб;

select Т.назв_трэка from ТРЭК as Т --нет таких треков
left join ТРЭК_СБОР  as Т_С on Т.id = Т_С.id_трэк
where Т_С.id_трэк is null;


select И.исполн, Т.время_трэка from ТРЭК as Т
left join АЛЬБОМ as А on А.id = Т.id_альбом
left join ИСПОЛН_АЛЬБ as И_А on И_А.id_альб = А.id
left join ИСПОЛНИТЕЛЬ as И on И.id = И_А.id_исполн
group by И.исполн, Т.время_трэка
having Т.время_трэка = (select min(время_трэка) from ТРЭК)
order by И.исполн;

select distinct А.назв_альб from АЛЬБОМ as А
left join ТРЭК as Т on Т.id_альбом = А.id
where Т.id_альбом in (
    select id_альбом
    from ТРЭК
    group by id_альбом
    having count(id) = (
        select count(id)
        from ТРЭК
        group by id_альбом
        order by count
        limit 1
    )
)
order by А.назв_альб