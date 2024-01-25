-- ������������ �������
-- ������ ������������ ��������� �������
SELECT MAX(rental_rate) FROM film;

-- ��������� ������� ����������������� ������
SELECT AVG(length) FROM film;

-- ������� ���������� ���� �������?
SELECT COUNT(DISTINCT first_name) FROM actor

-- ��������� ����� � ������� ������� �� ����������� ��������
SELECT SUM(amount), AVG(amount) FROM payment
WHERE staff_id = 1;


-- ��������� �������
-- ������ ��� ������ � ������������������ ���� ��������
-- ��� �������� �� �����
SELECT title, length  FROM film
WHERE length >= AVG(length);
-- ����� ��� ���
SELECT title, length FROM film
WHERE length >= (SELECT AVG(length) FROM film);

-- ������ �������� �������, ��������� ������� ������� �� ������������
SELECT title, rental_rate FROM film
WHERE rental_rate < (SELECT MAX(rental_rate) FROM film)
ORDER BY rental_rate DESC;


-- �����������
-- ��������� ���������� ������� � ������� ������� (������ �������������)
SELECT last_name, COUNT(*) FROM actor
GROUP BY last_name
ORDER BY COUNT(*) DESC;

-- ��������� ���������� ������� � ������� ��������� (������������� ���������)
SELECT rating, COUNT(title) FROM film
GROUP BY rating
ORDER BY COUNT(title) DESC;

-- ������ ������������ ������� � ������� ���������
SELECT staff_id, MAX(amount) FROM payment
GROUP BY staff_id;

-- ������ ������� ������� ������� �������� ������� ����������
SELECT staff_id, customer_id, AVG(amount) FROM payment
GROUP BY staff_id, customer_id
ORDER BY AVG(amount) DESC;

-- ������ ������� ����������������� ������ � ������� ��������� � 2006 ����
SELECT rating, AVG(length) FROM film
WHERE release_year = 2006
GROUP BY rating;


-- �������� HAVING
-- ������� ������ ������� �������, ������� �� �����������
SELECT last_name, COUNT(*) FROM actor
GROUP BY last_name
HAVING COUNT(*) = 1;

-- ������� � ��������� ������ ������� �������, ������� �����������
SELECT last_name, COUNT(*) FROM actor
GROUP BY last_name
HAVING COUNT(*) > 1
ORDER BY COUNT(*) DESC;

-- ������ ������, � ������� ���� Super � �������� 
-- � ��� ��������� � ������ �������� �����, ��� �� 5 ����
SELECT title, SUM(rental_duration) FROM film
WHERE title LIKE '%Super%'
GROUP BY title
HAVING SUM(rental_duration) > 5;


-- ALIAS
-- ���������� ������ � ������������
SELECT title AS t, SUM(rental_duration) AS sum_t FROM film AS f
WHERE title LIKE '%Super%'
GROUP BY t
HAVING SUM(rental_duration) > 5;

-- �������� ����� AS ����� �� ������
SELECT title t, SUM(rental_duration) sum_t FROM film f
WHERE title LIKE '%Super%'
GROUP BY t
HAVING SUM(rental_duration) > 5;


-- ����������� ������
-- ������� �����, ������� � ������ ���� �����������
SELECT first_name, last_name, address FROM staff s
LEFT JOIN address a ON s.address_id = a.address_id;

-- ��������� ���������� ������ ������� ��������
SELECT s.last_name, COUNT(amount) FROM payment p
LEFT JOIN staff s ON p.staff_id = s.staff_id
GROUP BY s.last_name;

-- ���������, ������� ������� ������ � ������ ������
SELECT title, COUNT(actor_id) actor_q FROM film f
JOIN film_actor a ON f.film_id = a.film_id
GROUP BY f.title
ORDER BY actor_q DESC;

-- ������� ����� ������� �� ������ Super � �������� ���� � �������
SELECT title, COUNT(inventory_id) FROM film f
JOIN inventory i ON f.film_id = i.film_id
WHERE title LIKE '%Super%'
GROUP BY title;

-- ������� ������ ����������� � ����������� �� ������� � ������� ��������
SELECT c.last_name n, COUNT(p.amount) amount FROM customer c
LEFT JOIN payment p ON c.customer_id = p.customer_id
GROUP BY n
ORDER BY amount DESC;

-- ������� ����� � �������� ������ ���� ����������� �� ������
SELECT c.last_name, c.first_name, c.email FROM customer c
JOIN address a ON c.address_id = a.address_id
JOIN city ON a.city_id = city.city_id
JOIN country co ON city.country_id = co.country_id
WHERE country = 'Russian Federation';

-- ������, ������� ����� � ������ ���� �����
SELECT f.title, COUNT(r.inventory_id) count FROM film f
JOIN inventory i ON f.film_id = i.film_id
JOIN rental r ON i.inventory_id = r.inventory_id
GROUP BY f.title
ORDER BY count DESC;

-- ��������� ������ ���������
SELECT s.store_id, SUM(p.amount) sales FROM store s 
JOIN staff st ON s.store_id = st.store_id
JOIN payment p ON st.staff_id = p.staff_id
GROUP BY s.store_id;

-- ������ ������ � ������ ������� ��������
SELECT store_id, city, country FROM store s 
JOIN address a ON s.address_id = a.address_id
JOIN city ON a.city_id = city.city_id
JOIN country c ON city.country_id = c.country_id;

-- ������� ���-5 ������ �� ������
SELECT c.name, SUM(p.amount) revenue FROM category c 
JOIN film_category fc ON c.category_id = fc.category_id
JOIN inventory i ON fc.film_id = i.film_id
JOIN rental r ON i.inventory_id = r.inventory_id
JOIN payment p ON r.rental_id = p.rental_id
GROUP BY c.name
ORDER BY revenue DESC 
LIMIT 5;