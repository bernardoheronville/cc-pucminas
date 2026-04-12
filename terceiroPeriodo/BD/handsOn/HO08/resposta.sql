1.
SELECT first_name, last_name
FROM actors
INTERSECT
SELECT first_name, last_name
FROM directors;

2.
SELECT first_name, last_name
FROM actors
EXCEPT
SELECT first_name, last_name
FROM directors;

3.
SELECT first_name, last_name
FROM actors
UNION
SELECT first_name, last_name
FROM directors;

4.
SELECT name
FROM movies
WHERE id NOT IN (
    SELECT movie_id
	FROM movies_directors
); 

5.
SELECT A.first_name, A.last_name
FROM roles AS R
JOIN actors AS A ON A.id = R.actor_id
GROUP BY A.first_name, A.last_name
HAVING COUNT(R.movie_id) < 2;

6.
SELECT MG.genre, M.year, COUNT(M.id) AS num_filmes
FROM movies_genres AS MG
JOIN movies AS M ON MG.movie_id = M.id
JOIN (
    SELECT R.movie_id
    FROM roles AS R
	GROUP BY R.movie_id
	HAVING COUNT(R.actor_id) < 2
) AS filmesFiltrado ON M.id = filmesFiltrado.movie_id
GROUP BY MG.genre, M.year;