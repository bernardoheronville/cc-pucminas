1. 
SELECT first_name, last_name
FROM actors
WHERE gender = 'F';

2. 
SELECT name
FROM movies
WHERE year > 1999;

3.
SELECT A.name, B.first_name, B.last_name
FROM movies_directors AS MD
JOIN movies AS A ON MD.movie_id = A.id
JOIN directors AS B ON MD.director_id = B.id;

4.
SELECT M.name, A.first_name, A.last_name, R.role
FROM roles AS R
JOIN movies AS M ON R.movie_id = M.id
JOIN actors AS A ON R.actor_id = A.id
WHERE M.rank > 6;

5.
SELECT D.first_name, D.last_name, COUNT(MD.movie_id) AS num_movies
FROM movies_directors AS MD
JOIN directors AS D ON MD.director_id = D.id
GROUP BY D.first_name, D.last_name;

6.
SELECT MG.genre, COUNT(MG.movie_id) AS num_genres
FROM movies_genres AS MG
GROUP BY MG.genre;

7. 
SELECT MG.genre, AVG(M.rank) AS med_rank, MIN(M.rank) AS min_rank, MAX(M.rank) AS max_rank
FROM movies_genres AS MG
JOIN movies AS M ON MG.movie_id = M.id
GROUP BY MG.genre;